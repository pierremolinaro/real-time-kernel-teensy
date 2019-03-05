#include "all-headers.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static volatile uint32_t sentCount0 = 0 ;

static void can0send (USER_MODE) {
  CANMessage message ; // Standard frame, identifier equal to 0, no data
  while (1) {
    if (digitalRead (P0_PUSH_BUTTON)) {
      ACAN::can0.send (MODE_ message) ;
      sentCount0 += 1 ;
    }else{
      waitDuring (MODE_ 50) ;
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static volatile uint32_t sentCount1 = 0 ;

static void can1send (USER_MODE) {
  CANMessage message ; // Standard frame, identifier equal to 0, no data
  message.mIdentifier = 0x01 ;
  while (1) {
    if (digitalRead (P0_PUSH_BUTTON)) {
      ACAN::can1.send (MODE_ message) ;
      sentCount1 += 1 ;
    }else{
      waitDuring (MODE_ 50) ;
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static volatile uint32_t receivedCount0 = 0 ;

static void can0Receive (USER_MODE) {
  while (1) {
    CANMessage message ;
    ACAN::can0.receive (MODE_ message) ;
    receivedCount0 += 1 ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static volatile uint32_t receivedCount1 = 0 ;

static void can1Receive (USER_MODE) {
  while (1) {
    CANMessage message ;
    ACAN::can1.receive (MODE_ message) ;
    receivedCount1 += 1 ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static void display (USER_MODE) {
  uint32_t displayDate = 0 ;
  gotoLineColumn (MODE_ 0, 5) ;
  printString (MODE_ "Sent") ;
  gotoLineColumn (MODE_ 0, 13) ;
  printString (MODE_ "Rved") ;
  gotoLineColumn (MODE_ 1, 0) ;
  printString (MODE_ "CAN0") ;
  gotoLineColumn (MODE_ 2, 0) ;
  printString (MODE_ "CAN1") ;
  while (1) {
    waitUntil (MODE_ displayDate) ;
    displayDate += 1000 ;
    gotoLineColumn (MODE_ 1, 5) ;
    printUnsigned (MODE_ sentCount0) ;
    gotoLineColumn (MODE_ 2, 5) ;
    printUnsigned (MODE_ sentCount1) ;
    gotoLineColumn (MODE_ 1, 13) ;
    printUnsigned (MODE_ receivedCount0) ;
    gotoLineColumn (MODE_ 2, 13) ;
    printUnsigned (MODE_ receivedCount1) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static uint64_t gStack0 [64] ;
static uint64_t gStack1 [64] ;
static uint64_t gStack2 [64] ;
static uint64_t gStack3 [64] ;
static uint64_t gStack4 [64] ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static void initApplication (INIT_MODE) {
  ACANSettings settings (MODE_ 125 * 1000) ;
  //  settings.mLoopBack = true ;
  uint32_t errorCode = ACAN::can0.begin (MODE_ settings) ;
  assertion (errorCode == 0, errorCode, __FILE__, __LINE__) ;
  errorCode = ACAN::can1.begin (MODE_ settings) ;
  assertion (errorCode == 0, errorCode, __FILE__, __LINE__) ;

  kernel_createTask (MODE_ gStack0, sizeof (gStack0), can0send) ;
  kernel_createTask (MODE_ gStack1, sizeof (gStack1), can1send) ;
  kernel_createTask (MODE_ gStack2, sizeof (gStack2), can0Receive) ;
  kernel_createTask (MODE_ gStack3, sizeof (gStack3), can1Receive) ;
  kernel_createTask (MODE_ gStack4, sizeof (gStack4), display) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

MACRO_INIT_ROUTINE (initApplication) ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

