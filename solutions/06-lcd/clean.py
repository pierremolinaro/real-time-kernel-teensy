#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

#------------------------------------------------------------------------------

import sys, os, shutil

#------------------------------------------------------------------------------

#----------------------------------------------------------------- Get script absolute path
scriptDir = os.path.dirname (os.path.abspath (sys.argv [0]))
#----------------------------------------------------------------- Import common definitions
pythonScriptDir = scriptDir + "/../../dev-files"
sys.path.append (pythonScriptDir)
import common_definitions
#-----------------------------------------------------------------
GENERATED_SOURCE_DIR = scriptDir + "/" + common_definitions.generatedSourceDirectory ()
if os.path.exists (GENERATED_SOURCE_DIR):
  shutil.rmtree (GENERATED_SOURCE_DIR)
BUILD_DIR = scriptDir + "/" + common_definitions.buildDirectory ()
if os.path.exists (BUILD_DIR):
  shutil.rmtree (BUILD_DIR)
PRODUCT_DIR = scriptDir + "/" + common_definitions.productDirectory ()
if os.path.exists (PRODUCT_DIR):
  shutil.rmtree (PRODUCT_DIR)
AS_DIR = scriptDir + "/" + common_definitions.asDirectory ()
if os.path.exists (AS_DIR):
  shutil.rmtree (AS_DIR)
#---
print ("Cleaning " + os.path.basename (scriptDir) + " done")

#------------------------------------------------------------------------------
