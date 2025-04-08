#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
# https://docs.python.org/2/library/subprocess.html#module-subprocess

import subprocess
import sys
import os

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   FOR PRINTING IN COLOR
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class bcolors:
    HEADER = '\033[35m'
    BLUE = '\033[34m'
    GREEN = '\033[32m'
    WARNING = '\033[33m'
    FAIL = '\033[31m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'
    BOLD_BLUE = '\033[1m' + '\033[34m'
    BOLD_GREEN = '\033[1m' + '\033[32m'
    BOLD_RED = '\033[1m' + '\033[31m'

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   Run process and wait for termination
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
#--- Compress zip
  runProcess (["zip", "-r", ARCHIVE + ".zip", ARCHIVE, "--exclude", "./.*"])
#--- Compress bzip2
#   runProcess (["tar", "--exclude", "./.*", "-c", "-jvf", ARCHIVE + ".tar", ARCHIVE])
#   runProcess (["bzip2", "--compress", ARCHIVE + ".tar"])
#   runProcess (["rm", "-fR", ARCHIVE])
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
runProcess (["mkdir", ARCHIVE_NAME + "/dev-files/common-sources"])
runProcessSingleCommand ("cp dev-files/*.py " + ARCHIVE_NAME + "/dev-files")
runProcessSingleCommand ("cp dev-files/*.txt " + ARCHIVE_NAME + "/dev-files")
runProcessSingleCommand ("cp dev-files/common-sources/*.cpp " + ARCHIVE_NAME + "/dev-files/common-sources")
runProcessSingleCommand ("cp dev-files/common-sources/*.h " + ARCHIVE_NAME + "/dev-files/common-sources")
runProcessSingleCommand ("cp dev-files/common-sources/*.s " + ARCHIVE_NAME + "/dev-files/common-sources")
runProcessSingleCommand ("cp dev-files/common-sources/*.ld " + ARCHIVE_NAME + "/dev-files/common-sources")
#--- Copy step 01
runProcess (["mkdir", ARCHIVE_NAME + "/steps"])
runProcess (["cp", scriptDir + "/solutions/+build-all.py", ARCHIVE_NAME + "/steps"])
runProcess (["cp", scriptDir + "/solutions/+clean-all.py", ARCHIVE_NAME + "/steps"])
runProcessSingleCommand ("cp -r solutions/01-blink-led " + ARCHIVE_NAME + "/steps")
runProcess (["rm", "-fr", ARCHIVE_NAME + "/steps/01-blink-led/zASBUILDS"])
runProcess (["rm", "-fr", ARCHIVE_NAME + "/steps/01-blink-led/zBUILDS"])
runProcess (["rm", "-fr", ARCHIVE_NAME + "/steps/01-blink-led/zPRODUCTS"])
runProcess (["rm", "-fr", ARCHIVE_NAME + "/steps/01-blink-led/zSOURCES"])
#--- Create archive
compress (scriptDir, ARCHIVE_NAME)
#--- Move archive to desktop
# runProcess (["mv", ARCHIVE_NAME + ".tar.bz2", os.path.expanduser ("~/Desktop/")])

#-------------------------------------- Documents
DOCUMENT_DIR = os.path.expanduser ("~/Desktop/info-treel-documents")
#--- Remove archive
runProcess (["rm", "-fR", DOCUMENT_DIR])
#--- Create archive
runProcess (["mkdir", DOCUMENT_DIR])
#--- Copy PDF files
for root, dirs, files in os.walk ("keynotes-2021-2022") :
  for name in files:
    keynotePath = os.path.join (root, name)
    (base, extension) = os.path.splitext (name)
    if extension == ".key" :
      pdfSourcePath = "pdf-2021-2022/" + base + ".pdf"
      if not os.path.exists (pdfSourcePath) :
        print (bcolors.BOLD_RED + "Le fichier '" + pdfSourcePath + "' n'existe pas" + bcolors.ENDC)
        sys.exit (1)
      elif os.path.getmtime (pdfSourcePath) < os.path.getmtime (keynotePath) :
        print (bcolors.BOLD_RED + "Le fichier '" + pdfSourcePath + "' n'est pas à jour" + bcolors.ENDC)
        sys.exit (1)
      else:
        runProcess (["cp", pdfSourcePath, DOCUMENT_DIR])
#--- Step 03
runProcess (["mkdir", DOCUMENT_DIR + "/03-files"])
runProcess (["cp", "solutions/03-software-modes/sources/software-modes.h", DOCUMENT_DIR + "/03-files"])
# compress (DOCUMENT_DIR, "03-files")
#--- Step 04
runProcess (["mkdir", DOCUMENT_DIR + "/04-files"])
runProcess (["cp", "solutions/04-boot-and-init-routines/sources/boot-init-macros.h", DOCUMENT_DIR + "/04-files"])
# compress (DOCUMENT_DIR, "04-files")
#--- Step 05
runProcess (["mkdir", DOCUMENT_DIR + "/05-files"])
runProcess (["cp", "solutions/05-leds-pushbuttons/sources/dev-board-io.cpp", DOCUMENT_DIR + "/05-files"])
runProcess (["cp", "solutions/05-leds-pushbuttons/sources/dev-board-io.h", DOCUMENT_DIR + "/05-files"])
runProcess (["cp", "solutions/05-leds-pushbuttons/sources/teensy-3-6-digital-io.cpp", DOCUMENT_DIR + "/05-files"])
runProcess (["cp", "solutions/05-leds-pushbuttons/sources/teensy-3-6-digital-io.h", DOCUMENT_DIR + "/05-files"])
# compress (DOCUMENT_DIR, "05-files")
#--- Step 06
runProcess (["mkdir", DOCUMENT_DIR + "/06-files"])
runProcess (["cp", "solutions/06-lcd/sources/lcd-wo-fault-mode.cpp", DOCUMENT_DIR + "/06-files"])
runProcess (["cp", "solutions/06-lcd/sources/lcd-wo-fault-mode.h", DOCUMENT_DIR + "/06-files"])
# compress (DOCUMENT_DIR, "06-files")
#--- Step 08
runProcess (["mkdir", DOCUMENT_DIR + "/08-files"])
runProcess (["cp", "solutions/08-volatile-and-systick-isr/sources/setup-loop-step8.cpp", DOCUMENT_DIR + "/08-files"])
# compress (DOCUMENT_DIR, "08-files")
#--- Step 09
runProcess (["mkdir", DOCUMENT_DIR + "/09-files"])
runProcess (["cp", "solutions/09-critical-section/sources/setup-loop-step9.cpp", DOCUMENT_DIR + "/09-files"])
# compress (DOCUMENT_DIR, "09-files")
#--- Step 10
runProcess (["mkdir", DOCUMENT_DIR + "/10-files"])
runProcess (["cp", "documentation/apnt209.pdf", DOCUMENT_DIR + "/10-files"])
runProcess (["cp", "solutions/10-fault-handler-and-assertion/sources/fault-handlers--assertion.cpp", DOCUMENT_DIR + "/10-files"])
runProcess (["cp", "solutions/10-fault-handler-and-assertion/sources/fault-handlers--assertion.h", DOCUMENT_DIR + "/10-files"])
runProcess (["cp", "solutions/10-fault-handler-and-assertion/sources/time-steps10-13.cpp", DOCUMENT_DIR + "/10-files"])
runProcess (["cp", "solutions/10-fault-handler-and-assertion/sources/time-steps10-13.h", DOCUMENT_DIR + "/10-files"])
runProcess (["cp", "solutions/10-fault-handler-and-assertion/sources/lcd-steps10-13.cpp", DOCUMENT_DIR + "/10-files"])
runProcess (["cp", "solutions/10-fault-handler-and-assertion/sources/lcd.h", DOCUMENT_DIR + "/10-files"])
# compress (DOCUMENT_DIR, "10-files")
#--- Step 12
runProcess (["mkdir", DOCUMENT_DIR + "/12-files"])
runProcess (["cp", "solutions/12-first-real-time-kernel/sources/reset-handler-xtr.s", DOCUMENT_DIR + "/12-files"])
runProcess (["cp", "solutions/12-first-real-time-kernel/sources/task-list--32-tasks.h", DOCUMENT_DIR + "/12-files"])
runProcess (["cp", "solutions/12-first-real-time-kernel/sources/task-list--32-tasks.cpp", DOCUMENT_DIR + "/12-files"])
runProcess (["cp", "solutions/12-first-real-time-kernel/sources/xtr-step12.h", DOCUMENT_DIR + "/12-files"])
runProcess (["cp", "solutions/12-first-real-time-kernel/sources/xtr-step12.cpp", DOCUMENT_DIR + "/12-files"])
runProcess (["cp", "solutions/12-first-real-time-kernel/sources/user-task-step12.cpp", DOCUMENT_DIR + "/12-files"])
# compress (DOCUMENT_DIR, "12-files")
#--- Step 17
runProcess (["mkdir", DOCUMENT_DIR + "/17-files"])
runProcess (["cp", "solutions/17-dynamic-allocation/sources/heap.h", DOCUMENT_DIR + "/17-files"])
runProcess (["cp", "solutions/17-dynamic-allocation/sources/heap.cpp", DOCUMENT_DIR + "/17-files"])
# compress (DOCUMENT_DIR, "17-files")
#--- Step 18
runProcess (["mkdir", DOCUMENT_DIR + "/18-files"])
runProcess (["cp", "solutions/18-guarded-commands/sources/BoundedBuffer.h", DOCUMENT_DIR + "/18-files"])
runProcess (["cp", "solutions/18-guarded-commands/sources/BoundedBuffer.cpp", DOCUMENT_DIR + "/18-files"])
runProcess (["cp", "solutions/18-guarded-commands/sources/Semaphore.h", DOCUMENT_DIR + "/18-files"])
runProcess (["cp", "solutions/18-guarded-commands/sources/Semaphore.cpp", DOCUMENT_DIR + "/18-files"])
runProcess (["cp", "solutions/18-guarded-commands/sources/xtr.h", DOCUMENT_DIR + "/18-files"])
runProcess (["cp", "solutions/18-guarded-commands/sources/xtr.cpp", DOCUMENT_DIR + "/18-files"])
# compress (DOCUMENT_DIR, "18-files")
#--- Step 19
# runProcess (["mkdir", DOCUMENT_DIR + "/19-files"])
# runProcess (["cp", "solutions/19-can-network--active-send-receive/sources/can/can-driver.cpp", DOCUMENT_DIR + "/19-files"])
# runProcess (["cp", "solutions/19-can-network--active-send-receive/sources/can/can-driver.h", DOCUMENT_DIR + "/19-files"])
# runProcess (["cp", "solutions/19-can-network--active-send-receive/sources/can/can-settings.cpp", DOCUMENT_DIR + "/19-files"])
# runProcess (["cp", "solutions/19-can-network--active-send-receive/sources/can/can-settings.h", DOCUMENT_DIR + "/19-files"])
# runProcess (["cp", "solutions/19-can-network--active-send-receive/sources/can/CANMessage.h", DOCUMENT_DIR + "/19-files"])
# compress (DOCUMENT_DIR, "19-files")


#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
