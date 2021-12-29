#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

#------------------------------------------------------------------------------*
# https://docs.python.org/2/library/subprocess.html#module-subprocess

import subprocess
import sys
import os

#------------------------------------------------------------------------------*

#--- Get script absolute path
scriptDir = os.path.dirname (os.path.abspath (sys.argv [0]))
#--- Enumerate directories
for root, dirs, files in os.walk (scriptDir):
  for filename in files:
    (b, extension) = os.path.splitext (filename)
    if extension == ".py" :
      fullPath = os.path.join (root, filename)
      print (fullPath)
      subprocess.call (["xattr", "-d", "com.apple.quarantine", fullPath])

#------------------------------------------------------------------------------*
