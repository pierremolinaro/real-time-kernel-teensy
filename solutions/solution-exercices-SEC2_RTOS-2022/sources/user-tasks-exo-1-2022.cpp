#include "all-headers.h"

//-----------------------------------------------------------------------------

static uint64_t gStack1 [64] ;
static uint64_t gStack2 [64] ;
static uint64_t gStack3 [64] ;
static uint64_t gStack4 [64] ;

//-----------------------------------------------------------------------------

static Evt evenement ;

//-----------------------------------------------------------------------------

static void task1 (USER_MODE) {
  while (1) {
    digitalWrite (L0_LED, true) ;
    waitDuring (MODE_ 1000) ;
    digitalWrite (L0_LED, false) ;
    evenement.signaler (MODE) ;
    waitDuring (MODE_ 1000) ;
  }
}

//-----------------------------------------------------------------------------

static void task2 (USER_MODE) {
  while (1) {
    evenement.attendre (MODE) ;
    digitalWrite (L1_LED, true) ;
    waitDuring (MODE_ 1000) ;
    digitalWrite (L1_LED, false) ;
  }
}

//-----------------------------------------------------------------------------

static void task3 (USER_MODE) {
  while (1) {
    evenement.attendre (MODE) ;
    digitalWrite (L2_LED, true) ;
    waitDuring (MODE_ 1000) ;
    digitalWrite (L2_LED, false) ;
  }
}

//-----------------------------------------------------------------------------

static void task4 (USER_MODE) {
  while (1) {
    evenement.attendre (MODE) ;
    digitalWrite (L3_LED, true) ;
    waitDuring (MODE_ 1000) ;
    digitalWrite (L3_LED, false) ;
  }
}

//-----------------------------------------------------------------------------

static void initTasks (INIT_MODE) {
  kernel_createTask (MODE_ gStack1, sizeof (gStack1), task1) ;
  kernel_createTask (MODE_ gStack2, sizeof (gStack2), task2) ;
  kernel_createTask (MODE_ gStack3, sizeof (gStack3), task3) ;
  kernel_createTask (MODE_ gStack4, sizeof (gStack4), task4) ;
}

//-----------------------------------------------------------------------------

MACRO_INIT_ROUTINE (initTasks) ;

//-----------------------------------------------------------------------------

