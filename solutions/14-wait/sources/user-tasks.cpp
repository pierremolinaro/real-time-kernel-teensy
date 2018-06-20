#include "all-headers.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static uint64_t gStack1 [64] ;
static uint64_t gStack2 [64] ;
static uint64_t gStack3 [64] ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static void task1 (USER_MODE) {
  printHex8 (MODE_ Debug_DEMCR) ;
  gotoLineColumn (MODE_ 1,0) ;
  printHex8 (MODE_ Debug_DHCSR_RO) ;
  for (uint32_t i=0 ; i < 10 ; i++) {
    digitalToggle (L0_LED) ;
    waitDuring (MODE_ 250) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static void task2 (USER_MODE) {
  for (uint32_t i=0 ; i < 10 ; i++) {
    digitalToggle (L1_LED) ;
    waitDuring (MODE_ 251) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static void task3 (USER_MODE) {
  for (uint32_t i=0 ; i < 10 ; i++) {
    digitalToggle (L2_LED) ;
    waitDuring (MODE_ 249) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static void initTasks (INIT_MODE) {
  kernel_createTask (MODE_ gStack1, sizeof (gStack1), task1) ;
  kernel_createTask (MODE_ gStack2, sizeof (gStack2), task2) ;
  kernel_createTask (MODE_ gStack3, sizeof (gStack3), task3) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

MACRO_INIT_ROUTINE (initTasks) ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

