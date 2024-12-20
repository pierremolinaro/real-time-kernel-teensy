#include "all-headers.h"

//-----------------------------------------------------------------------------

static uint64_t gStack1 [64] ;
static uint64_t gStack2 [64] ;

//-----------------------------------------------------------------------------

static void task1 (USER_MODE) {
  for (uint32_t i=0 ; i < 10 ; i++) {
    digitalToggle (L0_LED) ;
    busyWaitDuring (MODE_ 250) ;
  }
}

//-----------------------------------------------------------------------------

static void task2 (USER_MODE) {
  for (uint32_t i=0 ; i < 10 ; i++) {
    digitalToggle (L1_LED) ;
    busyWaitDuring (MODE_ 250) ;
  }
}

//-----------------------------------------------------------------------------

static void initTasks (INIT_MODE) {
  kernel_createTask (MODE_ gStack1, sizeof (gStack1), task1) ;
  kernel_createTask (MODE_ gStack2, sizeof (gStack2), task2) ;
}

//-----------------------------------------------------------------------------

MACRO_INIT_ROUTINE (initTasks) ;

//-----------------------------------------------------------------------------

