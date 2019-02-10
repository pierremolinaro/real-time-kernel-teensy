//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//
//   SilberchatzPortWithData
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#pragma once

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "SilberchatzPort.h"
#include "Semaphore.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class SilberchatzPortWithData {
//--- Properties
  protected: SilberchatzPort mPort ;
  protected: Semaphore mSemaphoreWrite ;
  protected: Semaphore mSemaphoreRead ;
  protected: volatile uint32_t mData ;

//--- Constructor
  public: SilberchatzPortWithData (void) ;

//--- Input
  public: void input (USER_MODE_ uint32_t & outData) ;

//--- Output
  public: void output (USER_MODE_ const uint32_t inData) ;

//--- No copy
  private: SilberchatzPortWithData (const SilberchatzPortWithData &) = delete ;
  private: SilberchatzPortWithData & operator = (const SilberchatzPortWithData &) = delete ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
