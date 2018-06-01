#! /usr/bin/env python
# -*- coding: UTF-8 -*-

import sys, os

#----------------------------------------------------------------------------------------------------------------------*

separator = "//" + ("—" * 118) + "\n"
#------------------------------ Arg 1 is destination file
destinationFile = sys.argv [1]
#------------------------------ Arg 2 is processor frequency (in MHz)
CPU_MHZ = sys.argv [2]
#------------------------------ Arg 2 is task count ("*" is no task)
TASK_COUNT = sys.argv [3]
#------------------------------ Arg 3 is teensy name
TEENSY_NAME = sys.argv [4]
#------------------------------ Header files
s = "#pragma once\n\n"
s += separator + "\n"
s += "#include <stdint.h>\n"
s += "#include <stdlib.h>\n"
s += "#include <string.h>\n"
s += "\n"
s += separator
s += "//  TASK COUNT\n"
s += separator + "\n"
s += "static const uint32_t TASK_COUNT = " + TASK_COUNT + " ;\n\n"
s += separator
s += "//  DEV BOARD\n"
s += separator + "\n"
s += "#define " + TEENSY_NAME + "\n"
s += "\n"
s += separator
s += "//  PROCESSOR FREQUENCY\n"
s += separator + "\n"
s += "#define CPU_MHZ (" + CPU_MHZ + ")\n\n"
s += separator
s += "//  FALLTHROUGH\n"
s += separator + "\n"
s += "#if __GNUC__ < 7\n"
s += "  #define FALLTHROUGH\n"
s += "#else\n"
s += "  #define FALLTHROUGH __attribute__ ((fallthrough))\n"
s += "#endif\n\n"
s += separator
s += "//   DIAGNOSTICS\n"
s += separator + "\n"
s += "#if __GNUC__ > 5\n"
s += "  #pragma GCC diagnostic error \"-Wduplicated-branches\"\n"
s += "  #pragma GCC diagnostic error \"-Wmisleading-indentation\"\n"
s += "#endif\n\n"
s += separator
#------------------------------ Write destination file
f = open (destinationFile, "wt")
f.write (s)
f.close()

#----------------------------------------------------------------------------------------------------------------------*
