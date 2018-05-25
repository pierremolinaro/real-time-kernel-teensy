#! /usr/bin/env python
# -*- coding: UTF-8 -*-

import sys, os

#----------------------------------------------------------------------------------------------------------------------*

separator = "//" + ("—" * 118) + "\n"
#------------------------------ Arg 1 is estination file
destinationFile = sys.argv [1]
#------------------------------ Arg 2 is task count ("*" is no task)
TASK_COUNT = sys.argv [2]
#------------------------------ Arg 3 is teensy name
TEENSY_NAME = sys.argv [3]
#------------------------------ Arg 4 is assertion generation value
ASSERTION_GENERATION = sys.argv [4]
#------------------------------ Header files
s = "#pragma once\n\n"
s += separator + "\n"
s += "#include <stdint.h>\n"
s += "#include <stdlib.h>\n"
s += "#include <string.h>\n"
s += "\n"
s += separator
#------------------------------
s += "\n"
s += "static const uint32_t TASK_COUNT = " + TASK_COUNT + " ;\n"
s += "#define " + TEENSY_NAME + "\n"
s += "#define ASSERTION_GENERATION (" + ASSERTION_GENERATION + ")\n"
s += "\n"
s += separator

#------------------------------ Write destination file
f = open (destinationFile, "wt")
f.write (s)
f.close()

#----------------------------------------------------------------------------------------------------------------------*
