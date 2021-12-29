#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
#———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

import sys, os, stat

#———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
#    ENTRY POINT
#———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#------------------------------ objdump tool
OBJDUMP_TOOL = sys.argv [1]
#------------------------------ Source file
SOURCE_NAME = sys.argv [2]
#------------------------------ Destination file
PYTHON_FILE_NAME = sys.argv [3]
#------------------------------ script dir
scriptDir = os.path.dirname (os.path.abspath (__file__))
#------------------------------ Script source
f = open (scriptDir + "/objdump.py.txt", "rt")
s = f.read ()
f.close()
#------------------------------ Perform substitutions
s = s.replace ("$OBJDUMP$", OBJDUMP_TOOL)
s = s.replace ("$SOURCE$", SOURCE_NAME)
#------------------------------ Destination file write
f = open (PYTHON_FILE_NAME, "wt")
f.write (s)
f.close()
os.chmod (PYTHON_FILE_NAME, stat.S_IRWXU | stat.S_IRWXG | stat.S_IRWXO)

#———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
