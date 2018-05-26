#! /usr/bin/env python
# -*- coding: UTF-8 -*-

#-----------------------------------------------------------------------------*

import subprocess, sys, os, filecmp

#-----------------------------------------------------------------------------*
#   FOR PRINTING IN COLOR                                                     *
#-----------------------------------------------------------------------------*

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

#-----------------------------------------------------------------------------*
#   runCommand                                                                *
#-----------------------------------------------------------------------------*

def runCommand (cmd) :
  str = "+"
  for s in cmd:
    str += " " + s
  print (bcolors.BOLD_BLUE + str + bcolors.ENDC)
  returncode = subprocess.call (cmd)
  if returncode != 0 :
    sys.exit (returncode)

#-----------------------------------------------------------------------------*

def udevPath ():
  return "/etc/udev/rules.d"

#-----------------------------------------------------------------------------*

def udevFileForTeensy ():
  return "49-teensy.rules"

#-----------------------------------------------------------------------------*
#   MAIN                                                                      *
#-----------------------------------------------------------------------------*

def installUDEVrulesOnLinux ():
#------------------------------------------------------------------ Machine
  (SYSTEM_NAME, MODE_NAME, RELEASE, VERSION, MACHINE) = os.uname ()
  if SYSTEM_NAME != "Linux" :
    print (bcolors.BOLD_RED + "This script is available only for Linux" + bcolors.ENDC)
    sys.exit (1)
#------------------------------------------------------------------ Get script absolute path
  scriptDir = os.path.dirname (os.path.abspath (__file__))
#------------------------------------------------------------------ Install udev file for Teensy
  if not os.path.exists (udevPath () + "/" + udevFileForTeensy ()) :
    runCommand (["sudo", "cp", scriptDir + "/" + udevFileForTeensy (), udevPath () + "/" + udevFileForTeensy ()])
    runCommand (["sudo", "udevadm", "trigger"])
  elif not filecmp.cmp (scriptDir + "/" + udevFileForTeensy (), udevPath () + "/" + udevFileForTeensy ()) :
    runCommand (["sudo", "cp", scriptDir + "/" + udevFileForTeensy (), udevPath () + "/" + udevFileForTeensy ()])
    runCommand (["sudo", "udevadm", "trigger"])
#---

#-----------------------------------------------------------------------------*
#   MAIN                                                                      *
#-----------------------------------------------------------------------------*

def uninstallUDEVrulesOnLinux ():
#------------------------------------------------------------------ Machine
  (SYSTEM_NAME, MODE_NAME, RELEASE, VERSION, MACHINE) = os.uname ()
  if SYSTEM_NAME != "Linux" :
    print (bcolors.BOLD_RED + "This script is available only for Linux" + bcolors.ENDC)
    sys.exit (1)
#------------------------------------------------------------------ Uninstall
  if os.path.exists (udevPath () + "/" + udevFileForTeensy ()) :
    runCommand (["sudo", "rm", udevPath () + "/" + udevFileForTeensy ()])
#------------------------------------------------------------------ Uninstall
  if os.path.exists (udevPath () + "/" + udevFileForOpenOCD ()) :
    runCommand (["sudo", "rm", udevPath () + "/" + udevFileForOpenOCD ()])

#-----------------------------------------------------------------------------*

