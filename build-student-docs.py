#! /usr/bin/env python
# -*- coding: UTF-8 -*-

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
# https://docs.python.org/2/library/subprocess.html#module-subprocess

import subprocess
import sys
import os

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
#   Run process and wait for termination                                                                               *
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def runProcess (command) :
  s = "+"
  for arg in command :
    s += " " + arg
  print (bcolors.BOLD_BLUE + s + bcolors.ENDC)
  returncode = subprocess.call (command)
  if returncode != 0 :
    sys.exit (returncode)

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def runProcessSingleCommand (command) :
  print (bcolors.BOLD_BLUE + command + bcolors.ENDC)
  returncode = subprocess.call (command, shell=True)
  if returncode != 0 :
    sys.exit (returncode)

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def compress (DIRECTORY, ARCHIVE) :
#--- Save current dir
  savedDir = os.getcwd ()
#--- Set current dir
  os.chdir (DIRECTORY)
#--- Compress
  runProcess (["tar", "cjvf", ARCHIVE + ".tar", ARCHIVE])
  runProcess (["bzip2", "--compress", ARCHIVE + ".tar"])
  runProcess (["rm", "-fR", ARCHIVE])
#--- Restore dir
  os.chdir (savedDir)

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#--- Get script absolute path
scriptDir = os.path.dirname (os.path.realpath (__file__))
os.chdir (scriptDir)
#-------------------------------------- Archive
ARCHIVE_NAME = "info-treel-steps"
#--- Remove archive
runProcess (["rm", "-fR", ARCHIVE_NAME])
runProcess (["rm", "-f", ARCHIVE_NAME + ".tar.bz2"])
#--- Create archive
runProcess (["mkdir", ARCHIVE_NAME])
#--- Copy dev files
runProcess (["mkdir", ARCHIVE_NAME + "/dev-files"])
runProcessSingleCommand ("cp dev-files/*.c " + ARCHIVE_NAME + "/dev-files")
runProcessSingleCommand ("cp dev-files/*.py " + ARCHIVE_NAME + "/dev-files")
runProcessSingleCommand ("cp dev-files/*.ld " + ARCHIVE_NAME + "/dev-files")
runProcessSingleCommand ("cp dev-files/*.rules " + ARCHIVE_NAME + "/dev-files")
#--- Copy step 01
runProcess (["mkdir", ARCHIVE_NAME + "/steps"])
runProcess (["cp", scriptDir + "/solutions/-build-all.py", ARCHIVE_NAME + "/steps"])
runProcess (["cp", scriptDir + "/solutions/-clean-all.py", ARCHIVE_NAME + "/steps"])
runProcessSingleCommand ("cp -r solutions/01-blink-led " + ARCHIVE_NAME + "/steps")
runProcess (["rm", "-fr", ARCHIVE_NAME + "/steps/01-blink-led/zBUILDS"])
runProcess (["rm", "-fr", ARCHIVE_NAME + "/steps/01-blink-led/zPRODUCTS"])
runProcess (["rm", "-fr", ARCHIVE_NAME + "/steps/01-blink-led/zSOURCES"])
#--- Create archive
compress (scriptDir, ARCHIVE_NAME)
# runProcess (["tar", "cjvf", ARCHIVE_NAME + ".tar", ARCHIVE_NAME])
# runProcess (["bzip2", "--compress", ARCHIVE_NAME + ".tar"])
# runProcess (["rm", "-fR", ARCHIVE_NAME])
#--- Move archive to desktop
runProcess (["mv", ARCHIVE_NAME + ".tar.bz2", os.path.expanduser ("~/Desktop/")])

#-------------------------------------- Documents
DOCUMENT_DIR = os.path.expanduser ("~/Desktop/info-treel-documents")
#--- Remove archive
runProcess (["rm", "-fR", DOCUMENT_DIR])
#--- Create archive
runProcess (["mkdir", DOCUMENT_DIR])
#--- Copy PDF files
runProcessSingleCommand ("cp pdf-2018-2019/*.pdf " + DOCUMENT_DIR)
#--- Step 03
runProcess (["mkdir", DOCUMENT_DIR + "/03-files"])
runProcess (["cp", "solutions/03-software-modes/sources/software-modes.h", DOCUMENT_DIR + "/03-files"])
compress (DOCUMENT_DIR, "03-files")
#--- Step 04
runProcess (["mkdir", DOCUMENT_DIR + "/04-files"])
runProcess (["cp", "solutions/04-boot-and-init-routines/sources/boot-init-macros.h", DOCUMENT_DIR + "/04-files"])
compress (DOCUMENT_DIR, "04-files")


#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
