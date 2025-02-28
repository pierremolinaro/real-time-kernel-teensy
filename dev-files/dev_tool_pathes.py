# -*- coding: UTF-8 -*-
#-------------------------------------------------------------------------------

import os

#-------------------------------------------------------------------------------
# ARM TOOL DIR
#-------------------------------------------------------------------------------

def findARMToolChainDir (inRelativePath) :
  basePath = os.path.expanduser (inRelativePath)
  result = ""
  for (dirpath, dirnames, filenames) in os.walk (basePath) :
    if (result == "") and dirpath.endswith ("/arm/bin") :
      result = dirpath + "/"
  return result

#-------------------------------------------------------------------------------

def MACOS_ARM_TOOL_CHAIN_DIR () :
  return findARMToolChainDir ("~/Library/Arduino15/packages/teensy/tools/teensy-compile")

def LINUX_ARM_TOOL_CHAIN_DIR () :
  return findARMToolChainDir ("~/.arduino15/packages/teensy/tools/teensy-compile")

def WINDOWS_ARM_TOOL_CHAIN_DIR () :
  return findARMToolChainDir ("~/AppData/Local/Arduino15/packages/teensy/tools/teensy-compile")

#-------------------------------------------------------------------------------
# TEENSY POST COMPILE TOOL
#-------------------------------------------------------------------------------

def findTeensyToolDir (inRelativePath) :
  basePath = os.path.expanduser (inRelativePath)
  result = ""
  for (dirpath, dirnames, filenames) in os.walk (basePath) :
    if (result == "") and ("teensy_post_compile" in filenames) :
      result = dirpath + "/"
  return result

#-------------------------------------------------------------------------------

def MACOS_TEENSY_TOOLS_DIR () :
  return findTeensyToolDir ("~/Library/Arduino15/packages/teensy/tools/teensy-tools")

def LINUX_TEENSY_TOOLS_DIR () :
  return findTeensyToolDir ("~/.arduino15/packages/teensy/tools/teensy-tools")

def WINDOWS_TEENSY_TOOLS_DIR () :
  return findTeensyToolDir ("~/AppData/Local/Arduino15/packages/teensy/tools/teensy-tools")

#-------------------------------------------------------------------------------
# PICOTOOL
#-------------------------------------------------------------------------------

def findPicotoolPath (inRelativePath, fileName) :
  basePath = os.path.expanduser (inRelativePath)
  result = ""
  for (dirpath, dirnames, filenames) in os.walk (basePath) :
    if (result == "") and fileName in set (filenames) :
      result = dirpath + "/" + fileName
  return result

#-------------------------------------------------------------------------------

def MACOS_PICOTOOL_PATH () :
  return findPicotoolPath ("~/Library/Arduino15/packages/rp2040/tools/pqt-picotool", "picotool")

def LINUX_PICOTOOL_PATH () :
  return findPicotoolPath ("~/.arduino15/packages/rp2040/tools/pqt-picotool", "picotool")

def WINDOWS_PICOTOOL_PATH  () :
  return findPicotoolPath ("~/AppData/Local/Arduino15/packages/rp2040/tools/pqt-picotool", "picotool.exe")

#-------------------------------------------------------------------------------
