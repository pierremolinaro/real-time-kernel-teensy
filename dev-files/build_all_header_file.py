#! /usr/bin/env python
# -*- coding: UTF-8 -*-

import sys, os

#----------------------------------------------------------------------------------------------------------------------*

separator = "//" + ("—" * 118) + "\n"
#------------------------------ Destination file
destinationFile = sys.argv [1]
#------------------------------ Dependence file
dependenceFile = sys.argv [2]
#------------------------------ Header files
dependenceString = ""
s = "#pragma once\n\n"
s += separator + "\n"
for i in range (3, len (sys.argv)):
  s += "#include \"" + os.path.basename (sys.argv [i]) + "\"\n"
  dependenceString += " :" + sys.argv [i] + "\n\n"
s += "\n" + separator
#------------------------------ Write files
f = open (destinationFile, "wt")
f.write (s)
f.close()
f = open (dependenceFile, "wt")
f.write (dependenceString)
f.close()

#----------------------------------------------------------------------------------------------------------------------*
