#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

#------------------------------------------------------------------------------

import sys, os, json

#------------------------------------------------------------------------------

#----------------------------------------------------------------- Get script absolute path
scriptDir = os.path.dirname (os.path.abspath (sys.argv [0]))
os.chdir (scriptDir)
#----------------------------------------------------------------- Get max parallel jobs as first argument
goal = "all"
if len (sys.argv) > 1 :
  goal = sys.argv [1]
#----------------------------------------------------------------- Get max parallel jobs as first argument
maxParallelJobs = 0 # 0 means use host processor count
if len (sys.argv) > 2 :
  maxParallelJobs = int (sys.argv [2])
#----------------------------------------------------------------- Build
jsonFilePath = os.path.abspath (scriptDir + "/makefile.json")
f = open (jsonFilePath, "r")
dictionary = json.loads (f.read ())
f.close ()
sys.path.append (scriptDir + "/../../dev-files")
import code_builder
code_builder.buildCode (goal, scriptDir, maxParallelJobs, maxParallelJobs == 1)

#------------------------------------------------------------------------------
