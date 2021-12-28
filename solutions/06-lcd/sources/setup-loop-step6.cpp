#include "all-headers.h"

//-----------------------------------------------------------------------------

void setup (USER_MODE) {
  printString (MODE_ "Hello!") ;
}

//-----------------------------------------------------------------------------

static uint32_t gCount ;

//-----------------------------------------------------------------------------

void loop (USER_MODE) {
  busyWaitDuring (MODE_ 500) ;
  gCount += 1 ;
  gCount %= 20 ;
  gotoLineColumn (MODE_ 1, 0) ;
  printSpaces (MODE_ 2) ;
  gotoLineColumn (MODE_ 1, 0) ;
  printUnsigned (MODE_ gCount) ;
  digitalToggle (L4_LED) ;
}

//-----------------------------------------------------------------------------
