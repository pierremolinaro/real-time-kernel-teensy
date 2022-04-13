#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

#------------------------------------------------------------------------------

import sys, os, subprocess

#------------------------------------------------------------------------------

#--- Get script absolute path
scriptDir = os.path.dirname (os.path.abspath (sys.argv [0]))
os.chdir (scriptDir)
#---
returncode = subprocess.call (["python3", "1-build.py", "display-obj-size", "1"])
if returncode != 0 :
  sys.exit (returncode)

#------------------------------------------------------------------------------
