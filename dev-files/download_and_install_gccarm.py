#! /usr/bin/env python
# -*- coding: UTF-8 -*-

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

import os, urllib, subprocess, sys

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

import archive_directory
import tool_directory

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   RTS-SOFTWARE URL                                                                                                   *
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def compilerRepositoryURL () :
 return "https://developer.arm.com/-/media/Files/downloads/gnu-rm/7-2017q4/gcc-arm-none-eabi-7-2017-q4-major-mac.tar.bz2"
# return "https://developer.arm.com/-/media/Files/downloads/gnu-rm/6-2017q2/gcc-arm-none-eabi-6-2017-q2-update-mac.tar.bz2"

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   DISTRIBUTION GCC                                                                                                   *
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def distributionGCC () :
  return "gcc-arm-none-eabi-7-2017-q4-major"
#  return "gcc-arm-none-eabi-6-2017-q2-update"

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
  childProcess = subprocess.Popen (cmd)
  childProcess.wait ()
  if childProcess.returncode != 0 :
    sys.exit (childProcess.returncode)

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
#  Install GCC                                                                                                         *
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def install_gcc (INSTALL_DIR) :
  print bcolors.BOLD_GREEN + "Install GCC tools..." + bcolors.ENDC
  DISTRIBUTION = distributionGCC ()
  #------------------------------------------------------------------ Archive dir
  COMPILER_ARCHIVE_DIR = archive_directory.createAndGetArchiveDirectory ()
  #------------------------------------------------------------------ Download
  if not os.path.exists (COMPILER_ARCHIVE_DIR + "/" + DISTRIBUTION + ".tar.bz2"):
    url = compilerRepositoryURL ()
    runCommand (["rm", "-f", COMPILER_ARCHIVE_DIR + "/" + DISTRIBUTION + ".tar.bz2.downloading"])
    downloadArchive (url, COMPILER_ARCHIVE_DIR + "/" + DISTRIBUTION + ".tar.bz2.downloading")
    runCommand (["mv",
                 COMPILER_ARCHIVE_DIR + "/" + DISTRIBUTION + ".tar.bz2.downloading",
                 COMPILER_ARCHIVE_DIR + "/" + DISTRIBUTION + ".tar.bz2"
                ])
  #------------------------------------------------------------------ Install
  if not os.path.exists (INSTALL_DIR):
    os.mkdir (INSTALL_DIR)
  if not os.path.exists (INSTALL_DIR + "/" + DISTRIBUTION):
    runCommand (["cp", COMPILER_ARCHIVE_DIR + "/" + DISTRIBUTION + ".tar.bz2", INSTALL_DIR + "/" + DISTRIBUTION + ".tar.bz2"])
    savedCurrentDir = os.getcwd ()
    os.chdir (INSTALL_DIR)
    print bcolors.BOLD_BLUE + "+ cd " + INSTALL_DIR + bcolors.ENDC
    runCommand (["bunzip2", DISTRIBUTION + ".tar.bz2"])
    runCommand (["tar", "xf", DISTRIBUTION + ".tar"])
    runCommand (["rm", DISTRIBUTION + ".tar"])
    os.chdir (savedCurrentDir)


#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   GET GCC TOOL DIRECTORY                                                                                             *
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def installGCCARMandGetToolDirectory () :
#--- Absolute path of tool directory
  TOOL_DIRECTORY = tool_directory.toolDirectory () + "/" + distributionGCC ()
#--- Install tool ?
  if not os.path.exists (TOOL_DIRECTORY) :
    install_gcc (tool_directory.toolDirectory ())
#--- Return tool directory
  return TOOL_DIRECTORY

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

