#include "all-headers.h"

//-----------------------------------------------------------------------------

static volatile uint32_t gCount ; // Volontairement, volatile est absent: C'EST UN BUG!

//-----------------------------------------------------------------------------

static void rtISR (SECTION_MODE_ const uint32_t inUptime) {
  gCount += 1 ;
}

//-----------------------------------------------------------------------------

MACRO_REAL_TIME_ISR (rtISR) ;

//-----------------------------------------------------------------------------

void setup (USER_MODE) {
  printString (MODE_ "Hello!") ;
  while (gCount < 3000) {}
}

//-----------------------------------------------------------------------------

void loop (USER_MODE) {
  gCount += 500 ;
  gotoLineColumn (MODE_ 1, 0) ;
  printUnsigned (MODE_ gCount) ;
  busyWaitDuring (MODE_ 500) ;
}

//-----------------------------------------------------------------------------
