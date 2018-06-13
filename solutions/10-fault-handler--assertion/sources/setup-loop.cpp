#include "all-headers.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void setup (USER_MODE) {
  printString (MODE_ "Hello!") ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static uint32_t gDisplayTime = 0 ;
static uint32_t gDownCounter = 10 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void loop (USER_MODE) {
  digitalWrite (L4_LED, !digitalRead (P4_PUSH_BUTTON)) ;
  if (gDisplayTime <= millis ()) {
    const uint32_t s = systick () ;
    gotoLineColumn (MODE_ 0, 7) ;
    printUnsigned (MODE_ millis () / gDownCounter) ; // DIVISION PAR ZÉRO APRÈS 10 s
    gDownCounter -- ;
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
