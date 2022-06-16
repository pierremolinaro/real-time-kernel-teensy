//-----------------------------------------------------------------------------
//
//   Port2
//
//-----------------------------------------------------------------------------

#include "all-headers.h"

//-----------------------------------------------------------------------------
//
//   CONSTRUCTEUR
//
//-----------------------------------------------------------------------------

Port2::Port2 (void) :
mEntreesEnAttente (),
mSortiesEnAttente () {
}

//-----------------------------------------------------------------------------
//
//   ENTRÉE
//
//-----------------------------------------------------------------------------

void Port2::sys_entree (KERNEL_MODE) {
  const bool found = irq_makeTaskReadyFromList (MODE_ mSortiesEnAttente) ;
  if (! found) {
    kernel_blockRunningTaskInList (MODE_ mEntreesEnAttente) ;
  }
}

//-----------------------------------------------------------------------------
//
//   SORTIE
//
//-----------------------------------------------------------------------------

void Port2::sys_sortie (KERNEL_MODE) {
  const bool found = irq_makeTaskReadyFromList (MODE_ mEntreesEnAttente) ;
  if (! found) {
    kernel_blockRunningTaskInList (MODE_ mSortiesEnAttente) ;
  }
}

//-----------------------------------------------------------------------------
