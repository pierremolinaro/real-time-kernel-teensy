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
  print (bcolors.BOLD_BLUE + str + bcolors.ENDC)
  returncode = subprocess.call (cmd)
  if returncode != 0 :
    sys.exit (returncode)

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#  Install Teensy CLI Loader                                                                                           *
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def installTeensyCLILoader (INSTALL_PATH) :
  print (bcolors.BOLD_GREEN + "Install Teensy CLI Loader..." + bcolors.ENDC)
  CURRENT_DIR = os.path.abspath (os.path.dirname (__file__))
  PLATFORM = dev_platform.getPlatform ()
  #------------------------------------------------------------------ Compile command
  COMPILE_COMMAND = [
    "gcc",
    "-O2",
    "-fomit-frame-pointer",
    CURRENT_DIR + "/" + fileBaseName () + ".c",
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

def buildAndGetPath (TOOL_DIR) :
  path = TOOL_DIR + "/" + fileBaseName ()
#--- Install tool ?
  if not os.path.exists (path) :
    installTeensyCLILoader (path)
#--- Return tool path
  return path

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

