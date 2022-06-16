//-----------------------------------------------------------------------------
//
//   Semaphore
//
//-----------------------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------------------

#include "task-list--32-tasks.h"

//-----------------------------------------------------------------------------

class Port2 {
//--- Properties
  protected: TaskList mEntreesEnAttente ;
  protected: TaskList mSortiesEnAttente ;

//--- Constructor
  public: Port2 (void) ;

//--- Entrée
//$service port.entree
  public: void entree (USER_MODE) asm ("port.entree") ;
  public: void sys_entree (KERNEL_MODE) asm ("service.port.entree") ;

//--- Sortie
//$service port.sortie
  public: void sortie (USER_MODE) asm ("port.sortie") ;
  public: void sys_sortie (KERNEL_MODE) asm ("service.port.sortie") ;

//--- No copy
  private: Port2 (const Port2 &) = delete ;
  private: Port2 & operator = (const Port2 &) = delete ;
} ;

//-----------------------------------------------------------------------------
