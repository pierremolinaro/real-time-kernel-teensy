#include "all-headers.h"

//-----------------------------------------------------------------------------

static uint64_t gStack1 [64] ;

//-----------------------------------------------------------------------------

static uint32_t gDisplayTime = 0 ;

static void task1 (USER_MODE) {
  while (1) {
    if (gDisplayTime <= millis (MODE)) {
      const uint32_t s = systick (MODE) ;
      gotoLineColumn (MODE_ 1, 0) ;
      printUnsigned (MODE_ s) ;
      gotoLineColumn (MODE_ 2, 0) ;
      printUnsigned (MODE_ millis (MODE)) ;
      gotoLineColumn (MODE_ 3, 0) ;
      printUnsigned64 (MODE_ micros (MODE)) ;
      gDisplayTime += 1000 ;
    }
  }
}

//-----------------------------------------------------------------------------

static void initTasks (INIT_MODE) {
  kernel_createTask (MODE_ gStack1, sizeof (gStack1), task1) ;
}

//-----------------------------------------------------------------------------

MACRO_INIT_ROUTINE (initTasks) ;

//-----------------------------------------------------------------------------

