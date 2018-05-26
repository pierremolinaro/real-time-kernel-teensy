#! /usr/bin/env python
# -*- coding: UTF-8 -*-

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

import os, sys

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   FOR PRINTING IN COLOR
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
#   PLATFORM
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def getPlatform () :
#--- Determine platform
  PLATFORM = ""
  (SYSTEM_NAME, MODE_NAME, RELEASE, VERSION, MACHINE) = os.uname ()
  #print "SYSTEM_NAME '" + SYSTEM_NAME + "'"
  #print "MACHINE '" + MACHINE + "'"
  if (MACHINE == "i386") & (SYSTEM_NAME == "Darwin") :
    PLATFORM = "mac"
  elif (MACHINE == "x86_64") & (SYSTEM_NAME == "Darwin") :
    PLATFORM = "mac"
  elif (MACHINE == "x86_64") & (SYSTEM_NAME == "Linux") :
    PLATFORM = "linux"
  elif (MACHINE == "i386") & (SYSTEM_NAME == "Linux") :
    PLATFORM = "linux32"
  elif (MACHINE == "i686") & (SYSTEM_NAME == "Linux") :
    PLATFORM = "linux32"
  else:
    print (bcolors.BOLD_RED + "*** Unknown platform (SYSTEM_NAME = \"" + SYSTEM_NAME + "\", MACHINE = \"" + MACHINE + "\") ***" + bcolors.ENDC)
    sys.exit (1) ;
  return PLATFORM

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

