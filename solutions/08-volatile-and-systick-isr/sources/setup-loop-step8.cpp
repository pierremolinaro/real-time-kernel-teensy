#include "all-headers.h"
#include <atomic>

//-----------------------------------------------------------------------------

static uint32_t gCount ; // Volontairement, si volatile est absent: C'EST UN BUG!

//-----------------------------------------------------------------------------

static void rtISR (SECTION_MODE_ const uint32_t inUptime) {
  gCount += 1 ;
}

//-----------------------------------------------------------------------------

MACRO_REAL_TIME_ISR (rtISR) ;

//-----------------------------------------------------------------------------

void setup (USER_MODE) {
  printString (MODE_ "Hello!") ;
  while (gCount < 3000) {
    std::atomic_thread_fence (std::memory_order_acq_rel) ;
  }
}

//-----------------------------------------------------------------------------

void loop (USER_MODE) {
  gCount += 500 ;
  gotoLineColumn (MODE_ 1, 0) ;
  printUnsigned (MODE_ gCount) ;
  busyWaitDuring (MODE_ 500) ;
}

//-----------------------------------------------------------------------------
