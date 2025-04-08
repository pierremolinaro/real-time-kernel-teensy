# -*- coding: UTF-8 -*-
#-------------------------------------------------------------------------------

import sys, os, subprocess, shutil, json, platform, dev_tool_pathes

#-------------------------------------------------------------------------------

import makefile
import common_definitions

#-------------------------------------------------------------------------------
#   Run process and wait for termination
#-------------------------------------------------------------------------------

def runProcess (command) :
  string = makefile.BOLD_GREEN ()
  for s in command :
    string += " " + s
  string += makefile.ENDC ()
  print (string)
  returncode = subprocess.call (command)
  if returncode != 0 :
    print (makefile.BOLD_RED () + "Error " + str (returncode) + makefile.ENDC ())
    sys.exit (returncode)

#-------------------------------------------------------------------------------
#   Run process, get output and wait for termination
#-------------------------------------------------------------------------------

def runProcessAndGetOutput (command) :
  result = ""
  childProcess = subprocess.Popen (command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines=True)
  while True:
    out = childProcess.stdout.read(1)
    if out == '' and childProcess.poll() != None:
      break
    if out != '' :
      result += out
#--- Wait for subprocess termination
  if childProcess.poll () == None :
    childProcess.wait ()
  if childProcess.returncode != 0 :
    print (makefile.BOLD_RED () + "Error " + str (childProcess.returncode) + makefile.ENDC ())
    sys.exit (childProcess.returncode)
  return result

#-------------------------------------------------------------------------------
#   dictionaryFromJsonFile
#-------------------------------------------------------------------------------

def dictionaryFromJsonFile (file) :
  result = {}
  if not os.path.exists (os.path.abspath (file)):
    print (makefile.BOLD_RED () + "The '" + file + "' file does not exist" + makefile.ENDC ())
    sys.exit (1)
  try:
    f = open (file, "r")
    result = json.loads (f.read ())
    f.close ()
  except:
    print (makefile.BOLD_RED () + "Syntax error in " + file + makefile.ENDC ())
    sys.exit (1)
  return result


#-------------------------------------------------------------------------------
#   buildCode
#-------------------------------------------------------------------------------

def buildCode (GOAL, projectDir, maxConcurrentJobs, showCommand):
#---------------------------------------- Prepare
  os.chdir (projectDir)
  make = makefile.Make (GOAL)
#  make.mMacTextEditor = "TextWrangler"
  allGoal = []
#---------------------------------------- Get platform ?
  SYSTEM_NAME = platform.system ()
  if SYSTEM_NAME == "Darwin" :
    BASE_NAME = "arm-none-eabi"
    TOOL_DIR = dev_tool_pathes.MACOS_ARM_TOOL_CHAIN_DIR ()
    AS_TOOL = TOOL_DIR + BASE_NAME + "-as"
    AS_TOOL_OPTIONS = ["-mthumb", "-mcpu=cortex-m4"]
    COMPILER_TOOL = TOOL_DIR + BASE_NAME + "-gcc"
    COMPILER_TOOL_OPTIONS = ["-mthumb", "-mcpu=cortex-m4"]
    OBJCOPY_TOOL = TOOL_DIR + BASE_NAME + "-objcopy"
    DISPLAY_OBJ_SIZE_TOOL = TOOL_DIR + BASE_NAME + "-size"
    OBJDUMP_TOOL = TOOL_DIR + BASE_NAME + "-objdump"
    TEENSY_TOOLS_DIR = dev_tool_pathes.MACOS_TEENSY_TOOLS_DIR ()
    TEENSY_POST_COMPILE = TEENSY_TOOLS_DIR + "teensy_post_compile"
  elif SYSTEM_NAME == "Linux" :
    BASE_NAME = "arm-none-eabi"
    TOOL_DIR = dev_tool_pathes.LINUX_ARM_TOOL_CHAIN_DIR ()
    AS_TOOL = TOOL_DIR + BASE_NAME + "-as"
    AS_TOOL_OPTIONS = ["-mthumb", "-mcpu=cortex-m4"]
    COMPILER_TOOL = TOOL_DIR + BASE_NAME + "-gcc"
    COMPILER_TOOL_OPTIONS = ["-mthumb", "-mcpu=cortex-m4"]
    OBJCOPY_TOOL = TOOL_DIR + BASE_NAME + "-objcopy"
    DISPLAY_OBJ_SIZE_TOOL = TOOL_DIR + BASE_NAME + "-size"
    OBJDUMP_TOOL = TOOL_DIR + BASE_NAME + "-objdump"
    TEENSY_TOOLS_DIR = dev_tool_pathes.LINUX_TEENSY_TOOLS_DIR ()
    TEENSY_POST_COMPILE = TEENSY_TOOLS_DIR + "teensy_post_compile"
  elif SYSTEM_NAME == "Windows" :
    BASE_NAME = "arm-none-eabi"
    TOOL_DIR = dev_tool_pathes.WINDOWS_ARM_TOOL_CHAIN_DIR ()
    AS_TOOL = TOOL_DIR + BASE_NAME + "-as.exe"
    AS_TOOL_OPTIONS = ["-mthumb", "-mcpu=cortex-m4"]
    COMPILER_TOOL = TOOL_DIR + BASE_NAME + "-gcc.exe"
    COMPILER_TOOL_OPTIONS = ["-mthumb", "-mcpu=cortex-m4"]
    OBJCOPY_TOOL = TOOL_DIR + BASE_NAME + "-objcopy.exe"
    DISPLAY_OBJ_SIZE_TOOL = TOOL_DIR + BASE_NAME + "-size.exe"
    OBJDUMP_TOOL = TOOL_DIR + BASE_NAME + "-objdump.exe"
    TEENSY_TOOLS_DIR = dev_tool_pathes.WINDOWS_TEENSY_TOOLS_DIR ()
    TEENSY_POST_COMPILE = TEENSY_TOOLS_DIR + "teensy_post_compile.exe"
  else:
    print (makefile.BOLD_RED () + "Unhandled platform: '" + SYSTEM_NAME + "'" + makefile.ENDC ())
    sys.exit (1)
#---------------------------------------- Analyze JSON file
  print (makefile.BOLD_GREEN () + "--- Making " + projectDir + makefile.ENDC ())
  dictionaire = dictionaryFromJsonFile (projectDir + "/makefile.json")
#--- TEENSY
  linkerScript = "common-sources/teensy-3-6.ld"
  teensyName = "TEENSY36"
#--- ASSERTION_GENERATION
  ASSERTION_GENERATION = False
  if ("ASSERTION-GENERATION" in dictionaire) and dictionaire ["ASSERTION-GENERATION"] :
    ASSERTION_GENERATION = True
#--- CPU_MHZ
  CPU_MHZ = 0
  if "CPU-MHZ" in dictionaire :
    CPU_MHZ = dictionaire ["CPU-MHZ"]
#--- SOURCE_FILE_DIRECTORIES
  SOURCE_FILE_DIRECTORIES = []
  if "SOURCE-DIR" in dictionaire :
    SOURCE_FILE_DIRECTORIES = dictionaire ["SOURCE-DIR"]
#--- GROUP_SOURCES
  GROUP_SOURCES = False
  if "GROUP-SOURCES" in dictionaire :
    GROUP_SOURCES = dictionaire ["GROUP-SOURCES"]
#--- TASK_COUNT
  TASK_COUNT = "0" # Means TASK_COUNT is not defined by JSON file
  if "TASK-COUNT" in dictionaire :
    TASK_COUNT = str (dictionaire ["TASK-COUNT"])
#--- LTO
  usesLTO = False
  if ("LTO" in dictionaire) and dictionaire ["LTO"] :
    usesLTO = True
#--- SERVICE
  serviceScheme = ""
  if "SERVICE-SCHEME"  in dictionaire :
    serviceScheme = dictionaire ["SERVICE-SCHEME"]
#--- SECTION
  sectionScheme = ""
  if "SECTION-SCHEME" in dictionaire :
    sectionScheme = dictionaire ["SECTION-SCHEME"]
#---------------------------------------- Directories
  BUILD_DIR = common_definitions.buildDirectory ()
  GENERATED_SOURCE_DIR = common_definitions.generatedSourceDirectory ()
  PRODUCT_DIR = common_definitions.productDirectory ()
  ASBUILD_DIR = common_definitions.asDirectory ()
#---------------------------------------- Build source lists
  includeDirsInCompilerCommand = ["-I", GENERATED_SOURCE_DIR, "-I", projectDir]
  H_SOURCE_LIST = []
  CPP_SOURCE_LIST = []
  S_SOURCE_LIST = []
  for f in SOURCE_FILE_DIRECTORIES :
    for root, dirs, files in os.walk (f) :
      includeDirsInCompilerCommand += ["-I", root]
      for name in files:
        sourcePath = os.path.join (root, name)
        (b, extension) = os.path.splitext (sourcePath)
        if extension == ".cpp" :
          CPP_SOURCE_LIST.append (sourcePath)
        elif extension == ".h" :
          H_SOURCE_LIST.append (sourcePath)
        elif extension == ".s" :
          S_SOURCE_LIST.append (sourcePath)
        elif extension == ".ld" :
          pass # Ignored file
        elif extension != "" : # Ceci permet d'ignorer les fichés cachés (dont les noms commencent par un point)
          print (makefile.MAGENTA () + makefile.BOLD () + "Note: unhandled file " + sourcePath + makefile.ENDC ())
#---------------------------------------- Build base header file
  baseHeader_file = GENERATED_SOURCE_DIR + "/base.h"
  H_SOURCE_LIST.insert (0, baseHeader_file)
  rule = makefile.Rule ("python3", "Build base header file", ["makefile.json"])
  rule.appendSource ("../../dev-files/build_base_header_file.py") ;
  rule.appendTarget (baseHeader_file) ;
  rule.appendOption (str (CPU_MHZ)) ;
  rule.appendOption (TASK_COUNT) ;
  rule.appendOption (teensyName) ;
  rule.appendOption ("1" if ASSERTION_GENERATION else "0") ;
  rule.mPriority = -1
  make.addRule (rule)
#---------------------------------------- Build all header file
  allHeadersSecondaryDependenceFile = BUILD_DIR + "/all-headers.d"
  allHeaders_file = GENERATED_SOURCE_DIR + "/all-headers.h"
  rule = makefile.Rule ("python3", "Build all headers file", ["makefile.json"])
  rule.appendSource ("../../dev-files/build_all_header_file.py") ;
  rule.appendTarget (allHeaders_file) ;
  rule.appendTarget (allHeadersSecondaryDependenceFile) ;
  rule.appendSourceList (H_SOURCE_LIST) ;
  rule.mPriority = -1
  make.addRule (rule)
#---------------------------------------- Build interrupt handler files
  interruptHandlerSFile = GENERATED_SOURCE_DIR + "/interrupt-handlers.s"
  interruptHandlerCppFile = GENERATED_SOURCE_DIR + "/interrupt-handler-helper.cpp"
  S_SOURCE_LIST.append (interruptHandlerSFile)
  CPP_SOURCE_LIST.append (interruptHandlerCppFile)
  rule = makefile.Rule ("python3", "Build interrupt files", ["makefile.json"])
  rule.appendSource ("../../dev-files/build_interrupt_handlers.py") ;
  rule.appendTarget (interruptHandlerCppFile) ;
  rule.appendTarget (interruptHandlerSFile) ;
  rule.appendOption (serviceScheme) ;
  rule.appendOption (sectionScheme) ;
  rule.appendSourceList (H_SOURCE_LIST) ;
  rule.mPriority = -1
  make.addRule (rule)
#---------------------------------------- Group sources ?
  if GROUP_SOURCES :
    allSourceFile = GENERATED_SOURCE_DIR + "/all-sources.cpp"
    rule = makefile.Rule ("python3", "Group all sources", ["makefile.json"])
    rule.appendSource ("../../dev-files/build_grouped_sources.py") ;
    rule.appendTarget (allSourceFile) ;
    rule.appendSourceList (CPP_SOURCE_LIST) ;
    rule.mPriority = -1
    make.addRule (rule)
    CPP_SOURCE_LIST = [allSourceFile]
#---------------------------------------- Build makefile rules
  objectFileList = []
  asObjectFileList = []
#--- CPP source files
  for sourcePath in CPP_SOURCE_LIST :
    source = os.path.basename (sourcePath)
    objectFile = BUILD_DIR + "/" + source + ".o"
    objectFileForChecking = BUILD_DIR + "/" + source + ".check.o"
    asObjectFile = BUILD_DIR + "/" + source + ".s"
  #--- Checking source
    rule = makefile.Rule (COMPILER_TOOL, "Checking " + source, ["makefile.json", allHeaders_file])
    rule.appendOptionList (COMPILER_TOOL_OPTIONS)
    rule.appendOptionList (common_definitions.checkModeOptions ())
    rule.appendOptionList (common_definitions.C_Cpp_optimizationOptions ())
    rule.appendOptionList (common_definitions.Cpp_actualOptions (False))
    rule.appendOption ("-c")
    rule.appendSource (sourcePath)
    rule.appendOption ("-o")
    rule.appendTarget (objectFileForChecking)
    rule.appendOption ("-DSTATIC=")
    rule.appendOptionList (includeDirsInCompilerCommand)
    rule.appendOptionList (["-MMD", "-MP", "-MF"])
    rule.appendSecondaryDependanceFile (objectFileForChecking + ".d", make) ;
    make.addRule (rule)
    rule.mPriority = -1
    allGoal.append (objectFileForChecking)
 #--- Compile source
    rule = makefile.Rule (COMPILER_TOOL, "Compiling " + source, ["makefile.json", allHeaders_file])
    rule.appendOptionList (COMPILER_TOOL_OPTIONS)
    rule.appendOptionList (common_definitions.C_Cpp_optimizationOptions ())
    rule.appendOptionList (common_definitions.Cpp_actualOptions (False))
#    rule.appendOption ("-g")
    rule.appendOption ("-c")
    rule.appendSource (sourcePath)
    rule.appendOption ("-o")
    rule.appendTarget (objectFile)
    rule.appendOption ("-DSTATIC=static __attribute__((unused))" if GROUP_SOURCES else "-DSTATIC=")
    rule.appendOptionList (includeDirsInCompilerCommand)
    rule.appendOptionList (["-MMD", "-MP", "-MF"])
    rule.appendSecondaryDependanceFile (objectFile + ".d", make) ;
    make.addRule (rule)
    objectFileList.append (objectFile)
  #--- objdump python source
    objdumpPythonFile = BUILD_DIR + "/" + source + ".objdump.py"
    rule = makefile.Rule ("python3", "Building " + source + ".objdump.py", ["makefile.json"])
    rule.appendSource ("../../dev-files/build_objdump.py")
    rule.appendSource (OBJDUMP_TOOL)
    rule.appendSource (sourcePath)
    rule.appendTarget (objdumpPythonFile)
    rule.mPriority = -1
    make.addRule (rule)
    allGoal.append (objdumpPythonFile)
  #--- AS rule
    rule = makefile.Rule (COMPILER_TOOL, "Compiling -> s " + source, ["makefile.json", allHeaders_file])
    rule.appendOptionList (COMPILER_TOOL_OPTIONS)
    rule.appendOptionList (common_definitions.C_Cpp_optimizationOptions ())
    rule.appendOptionList (common_definitions.Cpp_actualOptions (False))
    rule.appendOption ("-S")
    rule.appendSource (sourcePath)
    rule.appendOption ("-o")
    rule.appendTarget (asObjectFile)
    rule.appendOption ("-DSTATIC=")
    rule.appendOptionList (includeDirsInCompilerCommand)
    rule.appendOptionList (["-MMD", "-MP", "-MF"])
    rule.appendSecondaryDependanceFile (asObjectFile + ".d", make) ;
    make.addRule (rule)
  #--- AS rule, getting output assembler file
    listingFile = ASBUILD_DIR + "/" + source + ".s.list"
    rule = makefile.Rule (AS_TOOL, "Assembling " + asObjectFile + " -> listing", ["makefile.json"])
    rule.appendOptionList (AS_TOOL_OPTIONS)
    rule.appendSource (asObjectFile)
    rule.appendOption ("-o")
    rule.appendTarget (listingFile + ".o")
    rule.appendOption ("-aln=" + listingFile)
    rule.enterImplicitTarget (listingFile)
    make.addRule (rule)
    asObjectFileList.append (listingFile)
#-- Add ARM S files
  for sourcePath in S_SOURCE_LIST :
    source = os.path.basename (sourcePath)
    objectFile = BUILD_DIR + "/" + source + ".o"
    objectFileForChecking = BUILD_DIR + "/" + source + ".check.o"
    asObjectFile = ASBUILD_DIR + "/" + source + ".s"
    if sourcePath != "" :
      rule = makefile.Rule (AS_TOOL, "Assembling " + source, ["makefile.json"])
      rule.appendOptionList (AS_TOOL_OPTIONS)
      rule.appendSource (sourcePath)
      rule.appendOption ("-o")
      rule.appendTarget (objectFile)
      rule.appendOptionList (includeDirsInCompilerCommand)
      rule.appendOption ("--MD")
      rule.appendSecondaryDependanceFile (objectFile + ".d", make) ;
      make.addRule (rule)
      objectFileList.append (objectFile)
    #--- Add listing file
      listingFile = ASBUILD_DIR + "/" + source + ".list"
      rule = makefile.Rule (AS_TOOL, "Assembling -> listing " + source, ["makefile.json"])
      rule.appendOptionList (AS_TOOL_OPTIONS)
      rule.appendSource (sourcePath)
      rule.appendOption ("-o")
      rule.appendTarget (listingFile + ".o")
      rule.appendOption ("-aln=" + listingFile)
      rule.enterImplicitTarget (listingFile)
      make.addRule (rule)
      asObjectFileList.append (listingFile)
#---------------------------------------- Link for internal flash
  PRODUCT_INTERNAL_FLASH = PRODUCT_DIR + "/product"
  LINKER_SCRIPT_INTERNAL_FLASH = "../../dev-files/" + linkerScript
  allGoal.append (PRODUCT_INTERNAL_FLASH + ".elf")
#--- Add link rule
  rule = makefile.Rule (COMPILER_TOOL, "Linking " + PRODUCT_INTERNAL_FLASH + ".elf", ["makefile.json"])
  rule.appendOptionList (COMPILER_TOOL_OPTIONS)
  rule.appendSourceList (objectFileList)
  rule.appendOption ("-T")
  rule.appendSource (LINKER_SCRIPT_INTERNAL_FLASH)
  rule.appendOption ("-Wl,-Map=" + PRODUCT_INTERNAL_FLASH + ".map")
  rule.enterImplicitTarget (PRODUCT_INTERNAL_FLASH + ".map")
  rule.appendOptionList (common_definitions.commonLinkerFlags (usesLTO))
  rule.appendOption ("-o")
  rule.appendTarget (PRODUCT_INTERNAL_FLASH + ".elf")
  make.addRule (rule)
#--- Add hex rule
  allGoal.append (PRODUCT_INTERNAL_FLASH + ".hex")
  rule = makefile.Rule (OBJCOPY_TOOL, "Hexing " + PRODUCT_INTERNAL_FLASH + ".hex", ["makefile.json"])
  rule.appendOptionList (["-O", "ihex"])
  rule.appendSource (PRODUCT_INTERNAL_FLASH + ".elf")
  rule.appendTarget (PRODUCT_INTERNAL_FLASH + ".hex")
  make.addRule (rule)
#---------------------------------------- Goals
  make.addGoal ("all", allGoal, "Build all")
  make.addGoal ("run", allGoal, "Building all and run")
  make.addGoal ("view-hex", allGoal, "Building all and show hex")
  make.addGoal ("display-obj-size", allGoal, "Build binaries and display object sizes")
  make.addGoal ("as", asObjectFileList, "Compile C and C++ to assembly")
#---------------------------------------- Run jobs
#  make.printRules ()
#  make.checkRules ()
#   make.writeRuleDependancesInDotFile ("dependances.dot")
  make.runGoal (maxConcurrentJobs, showCommand)
#---------------------------------------- Ok ?
  make.printErrorCountAndExitOnError ()
#---------------------------------------- "display-obj-size"
  if GOAL == "display-obj-size" :
    makefile.runCommand ([DISPLAY_OBJ_SIZE_TOOL] + objectFileList + ["-t"], "Display Object Size", False, showCommand)
#---------------------------------------- "All" or "run"
  if (GOAL == "all") or (GOAL == "run") or (GOAL == "view-hex") :
    s = runProcessAndGetOutput ([DISPLAY_OBJ_SIZE_TOOL, "-t", PRODUCT_INTERNAL_FLASH + ".elf"])
    secondLine = s.split('\n')[1]
    numbers = [int(s) for s in secondLine.split() if s.isdigit()]
    print ("  ROM code:    " + str (numbers [0]) + " bytes")
    print ("  ROM data:    " + str (numbers [1]) + " bytes")
    print ("  RAM + STACK: " + str (numbers [2]) + " bytes")
#---------------------------------------- Run ?
  if GOAL == "run":
    #FLASH_TEENSY = [TEENSY_POST_COMPILE, "-w", "-v", "-mmcu=TEENSY36"]
    if not os.path.exists (TEENSY_POST_COMPILE) :
      print ("*** Error, path '" + TEENSY_POST_COMPILE + "' invalid")
      sys.exit (1)
    FLASH_TEENSY = [
      TEENSY_POST_COMPILE,
      "-file=" + os.path.basename (PRODUCT_INTERNAL_FLASH),
      "-path=" + projectDir + "/" + os.path.dirname (PRODUCT_INTERNAL_FLASH),
      "-tools=" + TEENSY_TOOLS_DIR,
      "-reboot",
      "-board=TEENSY36"
    ]
    print (makefile.BOLD_BLUE () + "Loading Teensy..." + makefile.ENDC ())
    runProcess (FLASH_TEENSY + [PRODUCT_INTERNAL_FLASH + ".hex"])
    #print (makefile.BOLD_GREEN () + "Success" + makefile.ENDC ())
  elif GOAL == "view-hex":
    print (makefile.BOLD_GREEN () + "View hex..." + makefile.ENDC ())
    scriptDir = os.path.dirname (os.path.abspath (__file__))
    runProcess (["python3", scriptDir+ "/view-hex.py", PRODUCT_INTERNAL_FLASH + ".hex"])

#-------------------------------------------------------------------------------
