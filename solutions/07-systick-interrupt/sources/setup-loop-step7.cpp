#include "all-headers.h"

//-----------------------------------------------------------------------------

void setup (USER_MODE) {
  printUnsigned (MODE_ millis (MODE)) ;
}

//-----------------------------------------------------------------------------

// void loop (USER_MODE) {
//   digitalToggle (L4_LED) ;
//   busyWaitDuring (MODE_ 1000) ;
//   gotoLineColumn (MODE_ 2, 0) ;
//   printUnsigned (MODE_ millis (MODE)) ;
// }

//-----------------------------------------------------------------------------

static uint32_t gDisplayTime = 0 ;

void loop (USER_MODE) {
  if (gDisplayTime <= millis (MODE)) {
    const uint32_t s = systick (MODE) ;
    digitalToggle (L4_LED) ;
    gotoLineColumn (MODE_ 1, 0) ;
    printUnsigned (MODE_ s) ;
    gotoLineColumn (MODE_ 2, 0) ;
    printUnsigned (MODE_ millis (MODE)) ;
    gDisplayTime += 1000 ;
  }
}

//-----------------------------------------------------------------------------
