#pragma once

//-----------------------------------------------------------------------------

#include "software-modes.h"

//-----------------------------------------------------------------------------
//
// Construction d'un identificateur unique par le préprocesseur
//
//   http://stackoverflow.com/questions/12697709/use-function-and-line-to-construct-identifier-name
//
//-----------------------------------------------------------------------------

#define CAT_FOR_UNIQUE_IDENTIFIER_2(a,b) a##b

#define CAT_FOR_UNIQUE_IDENTIFIER(a,b) CAT_FOR_UNIQUE_IDENTIFIER_2(a,b)

#define UNIQUE_IDENTIFIER CAT_FOR_UNIQUE_IDENTIFIER (zzUniqueIdentifier_, __COUNTER__)

//-----------------------------------------------------------------------------
//
// Inscrire l'adresse de la routine dans la section 'boot.routine.array'
// pour exécution automatique lors du démarrage
//
//-----------------------------------------------------------------------------

#define MACRO_BOOT_ROUTINE(ROUTINE) \
  static void (* UNIQUE_IDENTIFIER) (BOOT_MODE) \
  __attribute__ ((section ("boot.routine.array"))) \
  __attribute__ ((unused)) \
  __attribute__ ((used)) = ROUTINE ;

//-----------------------------------------------------------------------------
//
// Inscrire l'adresse de la routine dans la section 'init.routine.array'
// pour exécution automatique lors du démarrage
//
//-----------------------------------------------------------------------------

#define MACRO_INIT_ROUTINE(ROUTINE) \
  static void (* UNIQUE_IDENTIFIER) (INIT_MODE) \
  __attribute__ ((section ("init.routine.array"))) \
  __attribute__ ((unused)) \
  __attribute__ ((used)) = ROUTINE ;

//-----------------------------------------------------------------------------
