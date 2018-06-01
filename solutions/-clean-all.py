#! /usr/bin/env python
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
for name in os.listdir (scriptDir):
   fname = os.path.join (scriptDir, name, "clean.py")
   if os.path.isfile (fname) :
     returncode = subprocess.call ([fname])
     if returncode != 0 :
       sys.exit (returncode)

#------------------------------------------------------------------------------*
