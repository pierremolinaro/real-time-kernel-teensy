//-----------------------------------------------------------------------------
//
//   Semaphore
//
//-----------------------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------------------

#include "Semaphore.h"

//-----------------------------------------------------------------------------

class Port {
//--- Properties
  protected: Semaphore mEntree ;
  protected: Semaphore mSortie ;

//--- Constructor
  public: Port (void) ;

//--- Entrée
  public: void entree (USER_MODE) ;

//--- Sortie
  public: void sortie (USER_MODE) ;

//--- No copy
  private: Port (const Port &) = delete ;
  private: Port & operator = (const Port &) = delete ;
} ;

//-----------------------------------------------------------------------------
