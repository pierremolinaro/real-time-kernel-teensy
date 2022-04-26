#include "all-headers.h"

//-----------------------------------------------------------------------------

static const uint32_t TAILLE_BUFFER = 200 ;
static uint32_t * gBufferAllocation [TAILLE_BUFFER] ;
static volatile uint32_t gNombreDansBufferAllocation = 0 ;

//-----------------------------------------------------------------------------

static uint64_t gStack1 [128] ;
static uint64_t gStack2 [128] ;
static uint64_t gStack3 [128] ;

//-----------------------------------------------------------------------------

static void task1 (USER_MODE) {
  while (1) {
    waitDuring (MODE_ 1000) ;
    gotoLineColumn (MODE_ 0, 0) ;
    printUnsigned (MODE_ gNombreDansBufferAllocation) ;
    printString (MODE_ "  ") ;
    gotoLineColumn (MODE_ 1, 0) ;
    printUnsigned (MODE_ allocationCount ()) ;
  }
}

//-----------------------------------------------------------------------------

static void task2 (USER_MODE) {
  while (1) {
    waitDuring (MODE_ 1) ;
    uint32_t * p = nullptr ;
    if (digitalRead (P4_PUSH_BUTTON)) {
      p = new uint32_t (0) ;
    }
    waitDuring (MODE_ 1) ;
    delete p ;
  }
}

//-----------------------------------------------------------------------------

static void task3 (USER_MODE) {
  while (1) {
    const bool flag = (micros (MODE) & 1ULL) != 0 ;
    if (flag && (gNombreDansBufferAllocation < TAILLE_BUFFER) && digitalRead (P4_PUSH_BUTTON)) {
      gBufferAllocation [gNombreDansBufferAllocation] = new uint32_t (0) ;
      gNombreDansBufferAllocation += 1 ;
    }else if (gNombreDansBufferAllocation > 0) {
      const uint32_t idx = uint32_t (micros (MODE) % gNombreDansBufferAllocation) ;
      delete gBufferAllocation [idx] ;
      for (uint32_t i= idx+1 ; i < gNombreDansBufferAllocation ; i++) {
        gBufferAllocation [i-1] = gBufferAllocation [i] ;
      }
      gNombreDansBufferAllocation -= 1 ;
    }
  }
}

//-----------------------------------------------------------------------------

static void initTasks (INIT_MODE) {
  kernel_createTask (MODE_ gStack1, sizeof (gStack1), task1) ;
  kernel_createTask (MODE_ gStack2, sizeof (gStack2), task2) ;
  kernel_createTask (MODE_ gStack3, sizeof (gStack3), task3) ;
}

//-----------------------------------------------------------------------------

MACRO_INIT_ROUTINE (initTasks) ;

//-----------------------------------------------------------------------------

