#include "all-headers.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void setup (USER_MODE) {
  printString (MODE_ "Hello!") ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

// void loop (USER_MODE) {
//   digitalWrite (L4_LED, !digitalRead (P4_PUSH_BUTTON)) ;
//   busyWaitDuring (MODE_ 1000) ;
//   gotoLineColumn (MODE_ 1, 0) ;
//   printUnsigned (MODE_ millis ()) ;
// }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static uint32_t gDisplayTime = 0 ;

void loop (USER_MODE) {
  digitalWrite (L4_LED, !digitalRead (P4_PUSH_BUTTON)) ;
  if (gDisplayTime <= millis ()) {
    const uint32_t s = systick () ;
    gotoLineColumn (MODE_ 1, 0) ;
    printUnsigned (MODE_ s) ;
    gotoLineColumn (MODE_ 2, 0) ;
    printUnsigned (MODE_ millis ()) ;
    gotoLineColumn (MODE_ 3, 0) ;
    printUnsigned64 (MODE_ micros (MODE)) ;
    gDisplayTime += 1000 ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
