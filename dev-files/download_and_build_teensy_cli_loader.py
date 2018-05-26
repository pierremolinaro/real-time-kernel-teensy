#! /usr/bin/env python
# -*- coding: UTF-8 -*-

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

import os, urllib, subprocess, sys

import archive_directory
import dev_platform

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   Source file name                                                                                                   *
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def fileBaseName () :
  return "teensy_loader_cli"

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   REPOSITORY URL                                                                                                     *
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def teensyCLILoaderRepositoryURL () :
 return "https://github.com/PaulStoffregen/teensy_loader_cli/blob/master/" + fileBaseName () + ".c"

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   FOR PRINTING IN COLOR                                                                                              *
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class bcolors:
    HEADER = '\033[95m'
    BLUE = '\033[94m'
    GREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'
    BOLD_BLUE = '\033[1m' + '\033[94m'
    BOLD_GREEN = '\033[1m' + '\033[92m'
    BOLD_RED = '\033[1m' + '\033[91m'

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   runCommand                                                                                                         *
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def runCommand (cmd) :
  str = "+"
  for s in cmd:
    str += " " + s
  print bcolors.BOLD_BLUE + str + bcolors.ENDC
  returncode = subprocess.call (cmd)
  if returncode != 0 :
    sys.exit (returncode)

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   ARCHIVE DOWNLOAD                                                                                                   *
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def downloadReportHook (a,b,fileSize):
  # "," at the end of the line is important!
  if fileSize < (1 << 10):
    sizeString = str (fileSize)
  else:
    if fileSize < (1 << 20):
      sizeString = str (fileSize >> 10) + "Ki"
    else:
      sizeString = str (fileSize >> 20) + "Mi"
  print "% 3.1f%% of %sB\r" % (min(100.0, float(a * b) / fileSize * 100.0), sizeString),
  sys.stdout.flush()

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def downloadArchive (archiveURL, archivePath):
  print "URL: "+ archiveURL
  print "Downloading..."
  urllib.urlretrieve (archiveURL,  archivePath, downloadReportHook)
  print ""

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#  Install Teensy CLI Loader                                                                                           *
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def installTeensyCLILoader (INSTALL_PATH) :
  print bcolors.BOLD_GREEN + "Install Teensy CLI Loader..." + bcolors.ENDC
  TEENSY_CLI_LOADER_URL = teensyCLILoaderRepositoryURL ()
  PLATFORM = dev_platform.getPlatform ()
  #------------------------------------------------------------------ Archive dir
  COMPILER_ARCHIVE_DIR = archive_directory.createAndGetArchiveDirectory ()
  if not os.path.exists (COMPILER_ARCHIVE_DIR):
    os.mkdir (COMPILER_ARCHIVE_DIR)
  #------------------------------------------------------------------ Download
  SOURCE_FILE_PATH = COMPILER_ARCHIVE_DIR + "/" + fileBaseName () + ".c"
  if not os.path.exists (SOURCE_FILE_PATH) :
    runCommand (["curl", "-L", "-o", COMPILER_ARCHIVE_DIR + "/master.zip", "https://github.com/PaulStoffregen/teensy_loader_cli/archive/master.zip"])
    savedCurrentDir = os.getcwd ()
    os.chdir (COMPILER_ARCHIVE_DIR)
    runCommand (["unzip", "master.zip"])
    runCommand (["cp", fileBaseName () + "-master/" + fileBaseName () + ".c", fileBaseName () + ".c"])
    runCommand (["rm", "master.zip"])
    runCommand (["rm", "-r", fileBaseName () + "-master"])
    os.chdir (savedCurrentDir)
  #------------------------------------------------------------------ Compile command
  COMPILE_COMMAND = [
    "gcc",
    "-O2",
    "-fomit-frame-pointer",
    COMPILER_ARCHIVE_DIR + "/" + fileBaseName () + ".c",
    "-o", INSTALL_PATH
  ]
  if PLATFORM == "mac" :
    COMPILE_COMMAND += [
      "-DUSE_APPLE_IOKIT",
      "-framework", "Foundation",
      "-framework", "IOKit",
    ]
  elif PLATFORM == "linux" :
    COMPILE_COMMAND += ["-DUSE_LIBUSB", "-lusb"]
  elif PLATFORM == "linux32" :
    COMPILE_COMMAND += ["-DUSE_LIBUSB", "-lusb"]
  #------------------------------------------------------------------ Compile
  runCommand (COMPILE_COMMAND)

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   TOOL PATH                                                                                                          *
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def downloadTeensyCLILoaderThenCompileAndGetPath (TOOL_DIR) :
  path = TOOL_DIR + "/" + fileBaseName ()
#--- Install tool ?
  if not os.path.exists (path) :
    installTeensyCLILoader (path)
#--- Return tool path
  return path

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

