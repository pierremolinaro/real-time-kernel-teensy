#include "all-headers.h"

//-----------------------------------------------------------------------------

static volatile uint32_t gCount1 = 0 ;
static volatile uint32_t gCount2 = 0 ;
static volatile uint32_t gCount3 = 0 ;
static volatile uint32_t gCount4 = 0 ;
static volatile bool gPerformCount = true ;

//-----------------------------------------------------------------------------

static void rtISR (SECTION_MODE_ const uint32_t inUptime) {
  if (gPerformCount) {
    gCount1 += 1 ;
    gCount2 += 1 ;
    gCount3 += 1 ;
    gCount4 += 1 ;
  }
}

//-----------------------------------------------------------------------------

MACRO_REAL_TIME_ISR (rtISR) ;

//-----------------------------------------------------------------------------

void setup (USER_MODE) {
}

//-----------------------------------------------------------------------------

void loop (USER_MODE) {
  if (gPerformCount) {
    gCount1 += 1 ;
    gCount2 += 1 ;
    gCount3 += 1 ;
    gCount4 += 1 ;
    if (5000 <= millis (MODE)) {
      gPerformCount = false ;
      gotoLineColumn (MODE_ 0, 0) ;
      printUnsigned (MODE_ gCount1) ;
      gotoLineColumn (MODE_ 1, 0) ;
      printUnsigned (MODE_ gCount2) ;
      gotoLineColumn (MODE_ 2, 0) ;
      printUnsigned (MODE_ gCount3) ;
      gotoLineColumn (MODE_ 3, 0) ;
      printUnsigned (MODE_ gCount4) ;
    }
  }
}

//-----------------------------------------------------------------------------
