#include "all-headers.h"

//-----------------------------------------------------------------------------

static uint64_t gStack1 [64] ;
static uint64_t gStack2 [64] ;

//-----------------------------------------------------------------------------

static Semaphore s (0) ;

//-----------------------------------------------------------------------------

static void task1 (USER_MODE) {
  while (1) {
    digitalToggle (L0_LED) ;
    waitDuring (MODE_ 250) ;
    s.V (MODE) ;
  }
}

//-----------------------------------------------------------------------------

static void task2 (USER_MODE) {
  while (1) {
    s.P (MODE) ;
    digitalToggle (L1_LED) ;
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

