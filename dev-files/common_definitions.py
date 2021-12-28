# -*- coding: UTF-8 -*-

#------------------------------------------------------------------------------

def commonLinkerFlags (usesLTO) :
  result = []
  result.append ("-nostartfiles")
  result.append ("-Wl,--fatal-warnings")
  result.append ("-Wl,--warn-common")
  result.append ("-Wl,--no-undefined")
  if usesLTO :
    result.append ("-flto")
    result.append ("-ffat-lto-objects")
    result.append ("-fuse-linker-plugin")
  result.append ("-Wl,--cref")
  result.append ("-Wl,-static")
  result.append ("-Wl,--gc-sections")

  result.append ("-Wl,--sort-common=descending")
  result.append ("-Wl,--sort-section=alignment")
#  result.append ("-Wl,--print-memory-usage")
  result.append ("-Wl,--warn-section-align")
  result.append ("-Wl,--warn-shared-textrel")
  result.append ("-Wl,--warn-alternate-em")
  return result

#------------------------------------------------------------------------------

def checkModeOptions () :
  result = []
  result.append ("-x")
  result.append ("c++")
  result.append ("-DCHECK_SOFTWARE_MODES")
  return result

#------------------------------------------------------------------------------

def C_Cpp_optimizationOptions ():
  result = []
  result.append ("-Os")
#  result.append ("-foptimize-register-move")
  return result

#------------------------------------------------------------------------------

def C_Cpp_commonOptions (usesLTO):
  result = []
  result.append ("-Wall")
  result.append ("-Wextra")
  result.append ("-Werror")
  result.append ("-Wreturn-type")
  result.append ("-Wformat")
  result.append ("-Wshadow")
  result.append ("-Wsign-compare")
  result.append ("-Wpointer-arith")
  result.append ("-Wparentheses")
  result.append ("-Wcast-align")
  result.append ("-Wcast-qual")
  result.append ("-Wwrite-strings")
  result.append ("-Wswitch")
  result.append ("-Wswitch-enum")
  result.append ("-Wuninitialized")
  result.append ("-Wsign-conversion")

#--- Ordre de ne pas engendrer l'appel des destructeurs des variables globales C++
# et donc d'utiliser des symboles tels que __cxa_exit, __lock___atexit_recursive_mutex, …
  result.append ("-fno-use-cxa-atexit")

#--- Engendrer fonctions et variables globales dans des sections spécifiques
#    Ceci permet à l'éditeur de liens d'éliminer fonctions et variables inutilisées
  result.append ("-ffunction-sections")
  result.append ("-fdata-sections")

#   result.append ("-fno-stack-protector") # CLANG
#   result.append ("-fshort-enums") # CLANG
  if usesLTO :
    result.append ("-flto")
    result.append ("-ffat-lto-objects")
  result.append ("-Wno-unused-parameter")
  result.append ("-Wshadow")
#   result.append ("-Wduplicated-branches")
#   result.append ("-Wmisleading-indentation")
#  result.append ("-fomit-frame-pointer")
  return result

#------------------------------------------------------------------------------

def C_actualOptions (usesLTO):
  result = C_Cpp_commonOptions (usesLTO)
  result.append ("-std=c99")
  result.append ("-Wstrict-prototypes")
  result.append ("-Wbad-function-cast")
  result.append ("-Wmissing-declarations")
  result.append ("-Wimplicit-function-declaration")
  result.append ("-Wno-int-to-pointer-cast")
  result.append ("-Wno-pointer-to-int-cast")
  result.append ("-Wmissing-prototypes")
  return result

#------------------------------------------------------------------------------

def Cpp_actualOptions (usesLTO):
  result = C_Cpp_commonOptions (usesLTO)
  result.append ("-std=c++14") # c++11 For forwarding enum declarations
  result.append ("-fno-rtti")
  result.append ("-fno-exceptions")
  result.append ("-Woverloaded-virtual")
  result.append ("-Weffc++")
  result.append ("-fno-threadsafe-statics")
  result.append ("-Wmissing-declarations")
  result.append ("-Wsuggest-override")
  return result

#------------------------------------------------------------------------------

def generatedSourceDirectory () :
  return "zSOURCES"

#------------------------------------------------------------------------------

def buildDirectory () :
  return "zBUILDS"

#------------------------------------------------------------------------------

def asDirectory () :
  return "zASBUILDS"

#------------------------------------------------------------------------------

def productDirectory ():
  return "zPRODUCTS"

#------------------------------------------------------------------------------
