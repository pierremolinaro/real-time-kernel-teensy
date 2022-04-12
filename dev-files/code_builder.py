# -*- coding: UTF-8 -*-
#---------------------------------------------------------------------------------------------------

import sys, os, subprocess, shutil, json, platform

#---------------------------------------------------------------------------------------------------

import makefile
import common_definitions

#---------------------------------------------------------------------------------------------------
#   Run process and wait for termination
#---------------------------------------------------------------------------------------------------

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

#---------------------------------------------------------------------------------------------------
#   Run process, get output and wait for termination
#---------------------------------------------------------------------------------------------------

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

#---------------------------------------------------------------------------------------------------
#   dictionaryFromJsonFile
#---------------------------------------------------------------------------------------------------

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


#---------------------------------------------------------------------------------------------------
#   buildCode
#---------------------------------------------------------------------------------------------------

def buildCode (GOAL, projectDir, maxConcurrentJobs, showCommand):
#--------------------------------------------------------------------------- Prepare
  os.chdir (projectDir)
  make = makefile.Make (GOAL)
  make.mMacTextEditor = "TextWrangler" # "Atom"
  allGoal = []
#--------------------------------------------------------------------------- Get platform ?
#  (SYSTEM_NAME, MODE_NAME, RELEASE, VERSION, MACHINE) = os.uname ()
  SYSTEM_NAME = platform.system ()
  if SYSTEM_NAME == "Darwin" :
    BASE_NAME = "arm-none-eabi"
    TOOL_DIR = "/Applications/Teensyduino.app/Contents/Java/hardware/tools/arm/bin/"
    AS_TOOL_WITH_OPTIONS = [TOOL_DIR + BASE_NAME + "-as", "-mthumb", "-mcpu=cortex-m4"]
    COMPILER_TOOL_WITH_OPTIONS = [TOOL_DIR + BASE_NAME + "-gcc", "-mthumb", "-mcpu=cortex-m4"]
    OBJCOPY_TOOL_WITH_OPTIONS = [TOOL_DIR + BASE_NAME + "-objcopy"]
    DISPLAY_OBJ_SIZE_TOOL = [TOOL_DIR + BASE_NAME + "-size"]
    OBJDUMP_TOOL = TOOL_DIR + BASE_NAME + "-objdump"
    TEENSY_POST_COMPILE = "/Applications/Teensyduino.app/Contents/Java/hardware/tools/teensy_post_compile"
    TEENSY_TOOLS_DIR = "/Applications/Teensyduino.app/Contents/Java/hardware/tools/"
  elif SYSTEM_NAME == "Windows" :
    BASE_NAME = "arm-none-eabi"
    TOOL_DIR = "c:/Program Files (x86)/Arduino/hardware/tools/arm/bin/"
    AS_TOOL_WITH_OPTIONS = [TOOL_DIR + BASE_NAME + "-as", "-mthumb", "-mcpu=cortex-m4"]
    COMPILER_TOOL_WITH_OPTIONS = [TOOL_DIR + BASE_NAME + "-gcc", "-mthumb", "-mcpu=cortex-m4"]
    OBJCOPY_TOOL_WITH_OPTIONS = [TOOL_DIR + BASE_NAME + "-objcopy"]
    DISPLAY_OBJ_SIZE_TOOL = [TOOL_DIR + BASE_NAME + "-size"]
    OBJDUMP_TOOL = TOOL_DIR + BASE_NAME + "-objdump"
    TEENSY_POST_COMPILE = "c:/Program Files (x86)/Arduino/hardware/tools/teensy_post_compile"
    TEENSY_TOOLS_DIR = "c:/Program Files (x86)/Arduino/hardware/tools/"
  else:
    print (makefile.BOLD_RED () + "Unhandled platform: '" + SYSTEM_NAME + "'" + makefile.ENDC ())
    sys.exit (1)
#--------------------------------------------------------------------------- Analyze JSON file
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
#--------------------------------------------------------------------------- Directories
  BUILD_DIR = common_definitions.buildDirectory ()
  GENERATED_SOURCE_DIR = common_definitions.generatedSourceDirectory ()
  PRODUCT_DIR = common_definitions.productDirectory ()
  ASBUILD_DIR = common_definitions.asDirectory ()
#--------------------------------------------------------------------------- Build source lists
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
#--------------------------------------------------------------------------- Build base header file
  baseHeader_file = GENERATED_SOURCE_DIR + "/base.h"
  H_SOURCE_LIST.insert (0, baseHeader_file)
  rule = makefile.Rule ([baseHeader_file], "Build base header file")
  rule.mOpenSourceOnError = False
  rule.mDependences.append ("makefile.json")
  rule.mCommand += ["python", "../../dev-files/build_base_header_file.py", baseHeader_file, str (CPU_MHZ), TASK_COUNT, teensyName, "1" if ASSERTION_GENERATION else "0"]
  rule.mPriority = -1
  make.addRule (rule)
#--------------------------------------------------------------------------- Build all header file
  allHeadersSecondaryDependenceFile = BUILD_DIR + "/all-headers.dep"
  allHeaders_file = GENERATED_SOURCE_DIR + "/all-headers.h"
  rule = makefile.Rule ([allHeaders_file, allHeadersSecondaryDependenceFile], "Build all headers file")
  rule.mOpenSourceOnError = False
  rule.mDependences.append ("makefile.json")
  rule.mDependences += H_SOURCE_LIST
  rule.mCommand += ["python", "../../dev-files/build_all_header_file.py", allHeaders_file, allHeadersSecondaryDependenceFile]
  rule.mCommand += H_SOURCE_LIST
  rule.enterSecondaryDependanceFile (allHeadersSecondaryDependenceFile, make)
  rule.mPriority = -1
  make.addRule (rule)
#--------------------------------------------------------------------------- Build interrupt handler files
  interruptHandlerSFile = GENERATED_SOURCE_DIR + "/interrupt-handlers.s"
  interruptHandlerCppFile = GENERATED_SOURCE_DIR + "/interrupt-handler-helper.cpp"
  S_SOURCE_LIST.append (interruptHandlerSFile)
  CPP_SOURCE_LIST.append (interruptHandlerCppFile)
  rule = makefile.Rule ([interruptHandlerSFile, interruptHandlerCppFile], "Build interrupt files")
  rule.mOpenSourceOnError = False
  rule.mDependences += H_SOURCE_LIST
  rule.mDependences.append ("makefile.json")
  rule.mDependences.append ("../../dev-files/build_interrupt_handlers.py")
  rule.mCommand += ["python", "../../dev-files/build_interrupt_handlers.py"]
  rule.mCommand += [interruptHandlerCppFile]
  rule.mCommand += [interruptHandlerSFile]
  rule.mCommand += [serviceScheme]
  rule.mCommand += [sectionScheme]
  rule.mCommand += H_SOURCE_LIST
  rule.mPriority = -1
  make.addRule (rule)
#--------------------------------------------------------------------------- Group sources ?
  if GROUP_SOURCES :
    allSourceFile = GENERATED_SOURCE_DIR + "/all-sources.cpp"
    rule = makefile.Rule ([allSourceFile], "Group all sources")
    rule.mOpenSourceOnError = False
    rule.mDependences += CPP_SOURCE_LIST
    rule.mDependences.append ("makefile.json")
    rule.mCommand += ["python", "../../dev-files/build_grouped_sources.py", allSourceFile]
    rule.mCommand += CPP_SOURCE_LIST
    rule.mPriority = -1
    make.addRule (rule)
    CPP_SOURCE_LIST = [allSourceFile]
#--------------------------------------------------------------------------- Build makefile rules
  objectFileList = []
  asObjectFileList = []
#--- CPP source files
  for sourcePath in CPP_SOURCE_LIST :
    source = os.path.basename (sourcePath)
    objectFile = BUILD_DIR + "/" + source + ".o"
    objectFileForChecking = BUILD_DIR + "/" + source + ".check.o"
    asObjectFile = BUILD_DIR + "/" + source + ".s"
  #--- Checking source
    rule = makefile.Rule ([objectFileForChecking], "Checking " + source)
    rule.mOpenSourceOnError = False
    rule.mDependences.append (allHeaders_file)
    rule.mDependences.append (sourcePath)
    rule.mDependences.append ("makefile.json")
    rule.enterSecondaryDependanceFile (objectFileForChecking + ".dep", make)
    rule.mCommand += COMPILER_TOOL_WITH_OPTIONS
    rule.mCommand += common_definitions.checkModeOptions ()
    rule.mCommand += common_definitions.C_Cpp_optimizationOptions ()
    rule.mCommand += common_definitions.Cpp_actualOptions (False)
    rule.mCommand += ["-c", sourcePath]
    rule.mCommand += ["-o", objectFileForChecking]
    rule.mCommand += ["-DSTATIC="]
    rule.mCommand += includeDirsInCompilerCommand
    rule.mCommand += ["-MMD", "-MP", "-MF", objectFileForChecking + ".dep"]
    make.addRule (rule)
    rule.mPriority = -1
    allGoal.append (objectFileForChecking)
 #--- Compile source
    rule = makefile.Rule ([objectFile], "Compiling " + source)
    rule.mOpenSourceOnError = False
    rule.mCommand += COMPILER_TOOL_WITH_OPTIONS
    rule.mCommand += common_definitions.C_Cpp_optimizationOptions ()
    rule.mCommand += common_definitions.Cpp_actualOptions (usesLTO)
    rule.mCommand += ["-g"]
    rule.mCommand += ["-c", sourcePath]
    rule.mCommand += ["-o", objectFile]
    rule.mCommand += ["-DSTATIC=static __attribute__((unused))"] if GROUP_SOURCES else ["-DSTATIC="]
    rule.mCommand += includeDirsInCompilerCommand
    rule.mCommand += ["-MMD", "-MP", "-MF", objectFile + ".dep"]
    rule.mDependences.append (allHeaders_file)
    rule.mDependences.append (sourcePath)
    rule.mDependences.append ("makefile.json")
    rule.enterSecondaryDependanceFile (objectFile + ".dep", make)
    make.addRule (rule)
    objectFileList.append (objectFile)
  #--- objdump python source
    objdumpPythonFile = BUILD_DIR + "/" + source + ".objdump.py"
    rule = makefile.Rule ([objdumpPythonFile], "Building " + source + ".objdump.py")
    rule.mDependences.append (objectFile)
    rule.mDependences.append ("makefile.json")
    rule.mCommand += ["python", "../../dev-files/build_objdump.py", OBJDUMP_TOOL, source, objdumpPythonFile]
    rule.mPriority = -1
    make.addRule (rule)
    allGoal.append (objdumpPythonFile)
  #--- AS rule
    rule = makefile.Rule ([asObjectFile], "Compiling -> s " + source)
    rule.mOpenSourceOnError = False
    rule.mCommand += COMPILER_TOOL_WITH_OPTIONS
    rule.mCommand += common_definitions.C_Cpp_optimizationOptions ()
    rule.mCommand += common_definitions.Cpp_actualOptions (usesLTO)
    rule.mCommand += ["-S", sourcePath]
    rule.mCommand += ["-o", asObjectFile]
    rule.mCommand += ["-DSTATIC="]
    rule.mCommand += includeDirsInCompilerCommand
    rule.mCommand += ["-MMD", "-MP", "-MF", asObjectFile + ".dep"]
    rule.mDependences.append (sourcePath)
    rule.mDependences.append (allHeaders_file)
    rule.mDependences.append ("makefile.json")
    rule.enterSecondaryDependanceFile (asObjectFile + ".dep", make)
    make.addRule (rule)
  #--- AS rule, getting output assembler file
    listingFile = ASBUILD_DIR + "/" + source + ".s.list"
    rule = makefile.Rule ([listingFile], "Assembling -> listing " + source)
    rule.mOpenSourceOnError = False
    rule.mCommand += AS_TOOL_WITH_OPTIONS
    rule.mCommand += [asObjectFile]
    rule.mCommand += ["-o", "/dev/null"]
    rule.mCommand += ["-aln=" + listingFile]
    rule.mDependences.append (asObjectFile)
    rule.mDependences.append (allHeaders_file)
    rule.mDependences.append ("makefile.json")
    make.addRule (rule)
    asObjectFileList.append (listingFile)
#-- Add ARM S files
  for sourcePath in S_SOURCE_LIST :
    source = os.path.basename (sourcePath)
    objectFile = BUILD_DIR + "/" + source + ".o"
    objectFileForChecking = BUILD_DIR + "/" + source + ".check.o"
    asObjectFile = ASBUILD_DIR + "/" + source + ".s"
    if sourcePath != "" :
      rule = makefile.Rule ([objectFile], "Assembling " + source)
      rule.mOpenSourceOnError = False
      rule.mCommand += AS_TOOL_WITH_OPTIONS
      rule.mCommand += [sourcePath]
      rule.mCommand += ["-o", objectFile]
      rule.mCommand += includeDirsInCompilerCommand
      rule.mCommand += ["--MD", objectFile + ".dep"]
      rule.mDependences.append (sourcePath)
      rule.mDependences.append ("makefile.json")
      rule.enterSecondaryDependanceFile (objectFile + ".dep", make)
      make.addRule (rule)
      objectFileList.append (objectFile)
    #--- Add listing file
      listingFile = ASBUILD_DIR + "/" + source + ".list"
      rule = makefile.Rule ([listingFile], "Assembling -> listing " + source)
      rule.mOpenSourceOnError = False
      rule.mCommand += AS_TOOL_WITH_OPTIONS
      rule.mCommand += [sourcePath]
      rule.mCommand += ["-o", "/dev/null"]
      rule.mCommand += ["-aln=" + listingFile]
      rule.mDependences.append (sourcePath)
      rule.mDependences.append ("makefile.json")
      make.addRule (rule)
      asObjectFileList.append (listingFile)
#--------------------------------------------------------------------------- Link for internal flash
  PRODUCT_INTERNAL_FLASH = PRODUCT_DIR + "/product"
  LINKER_SCRIPT_INTERNAL_FLASH = "../../dev-files/" + linkerScript
  allGoal.append (PRODUCT_INTERNAL_FLASH + ".elf")
#--- Add link rule
  rule = makefile.Rule ([PRODUCT_INTERNAL_FLASH + ".elf"], "Linking " + PRODUCT_INTERNAL_FLASH + ".elf")
  rule.mDependences += objectFileList
  rule.mDependences.append (LINKER_SCRIPT_INTERNAL_FLASH)
  rule.mDependences.append ("makefile.json")
  rule.mCommand += COMPILER_TOOL_WITH_OPTIONS
  rule.mCommand += objectFileList
  rule.mCommand += ["-T" + LINKER_SCRIPT_INTERNAL_FLASH]
  rule.mCommand.append ("-Wl,-Map=" + PRODUCT_INTERNAL_FLASH + ".map")
  rule.mCommand += common_definitions.commonLinkerFlags (usesLTO)
  rule.mCommand += ["-o", PRODUCT_INTERNAL_FLASH + ".elf"]
  make.addRule (rule)
#--- Add hex rule
  allGoal.append (PRODUCT_INTERNAL_FLASH + ".hex")
  rule = makefile.Rule ([PRODUCT_INTERNAL_FLASH + ".hex"], "Hexing " + PRODUCT_INTERNAL_FLASH + ".hex")
  rule.mDependences.append (PRODUCT_INTERNAL_FLASH + ".elf")
  rule.mDependences.append ("makefile.json")
  rule.mCommand += OBJCOPY_TOOL_WITH_OPTIONS
  rule.mCommand.append ("-O")
  rule.mCommand.append ("ihex")
  rule.mCommand.append (PRODUCT_INTERNAL_FLASH + ".elf")
  rule.mCommand.append (PRODUCT_INTERNAL_FLASH + ".hex")
  make.addRule (rule)
#--------------------------------------------------------------------------- Goals
  make.addGoal ("all", allGoal, "Build all")
  make.addGoal ("run", allGoal, "Building all and run")
  make.addGoal ("view-hex", allGoal, "Building all and show hex")
  make.addGoal ("display-obj-size", allGoal, "Build binaries and display object sizes")
  make.addGoal ("as", asObjectFileList, "Compile C and C++ to assembly")
#--------------------------------------------------------------------------- Run jobs
  #make.printRules ()
  #make.checkRules ()
#   make.writeRuleDependancesInDotFile ("dependances.dot")
  make.runGoal (maxConcurrentJobs, showCommand)
#--------------------------------------------------------------------------- Ok ?
  make.printErrorCountAndExitOnError ()
#---------------------------------------------------------------------------- "display-obj-size"
  if GOAL == "display-obj-size" :
    makefile.runCommand (DISPLAY_OBJ_SIZE_TOOL + objectFileList + ["-t"], "Display Object Size", False, showCommand)
#---------------------------------------------------------------------------- "All" or "run"
  if (GOAL == "all") or (GOAL == "run") or (GOAL == "view-hex") :
    s = runProcessAndGetOutput (DISPLAY_OBJ_SIZE_TOOL + ["-t"] + [PRODUCT_INTERNAL_FLASH + ".elf"])
    secondLine = s.split('\n')[1]
    numbers = [int(s) for s in secondLine.split() if s.isdigit()]
    print ("  ROM code:    " + str (numbers [0]) + " bytes")
    print ("  ROM data:    " + str (numbers [1]) + " bytes")
    print ("  RAM + STACK: " + str (numbers [2]) + " bytes")
#----------------------------------------------- Run ?
  if GOAL == "run":
    #FLASH_TEENSY = [TEENSY_POST_COMPILE, "-w", "-v", "-mmcu=TEENSY36"]
    FLASH_TEENSY = [
      TEENSY_POST_COMPILE,
      "-file=" + os.path.basename (PRODUCT_INTERNAL_FLASH),
      "-path=" + projectDir + "/" + os.path.dirname (PRODUCT_INTERNAL_FLASH),
      "-tools=" + TEENSY_TOOLS_DIR,
#      "-reboot",
      "-board=TEENSY35"
    ]
    print (makefile.BOLD_BLUE () + "Loading Teensy..." + makefile.ENDC ())
    runProcess (FLASH_TEENSY + [PRODUCT_INTERNAL_FLASH + ".hex"])
    #print (makefile.BOLD_GREEN () + "Success" + makefile.ENDC ())
  elif GOAL == "view-hex":
    print (makefile.BOLD_GREEN () + "View hex..." + makefile.ENDC ())
    scriptDir = os.path.dirname (os.path.abspath (__file__))
    runProcess (["python", scriptDir+ "/view-hex.py", PRODUCT_INTERNAL_FLASH + ".hex"])

#---------------------------------------------------------------------------------------------------
