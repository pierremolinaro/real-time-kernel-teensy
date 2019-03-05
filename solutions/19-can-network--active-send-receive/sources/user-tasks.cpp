#include "all-headers.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

// static void tacheTest0 (USER_MODE) {
//   uint32_t sentCount0 = 0 ;
//   uint32_t sentCount1 = 0 ;
//   uint32_t receivedCount0 = 0 ;
//   uint32_t receivedCount1 = 0 ;
//   gotoLineColumn (MODE_ 0, 5) ;
//   printString (MODE_ "Sent") ;
//   gotoLineColumn (MODE_ 0, 13) ;
//   printString (MODE_ "Rved") ;
//   gotoLineColumn (MODE_ 1, 0) ;
//   printString (MODE_ "CAN0") ;
//   gotoLineColumn (MODE_ 2, 0) ;
//   printString (MODE_ "CAN1") ;
//   while (1) {
//     waitDuring (MODE_ 1000) ;
//     CANMessage message ; // Sandard frame, identifier equal to 0, no data
//     if (ACAN::can0.tryToSend (MODE_ message)) {
//       sentCount0 += 1 ;
//       gotoLineColumn (MODE_ 1, 5) ;
//       printUnsigned (MODE_ sentCount0) ;
//     }
//     if (ACAN::can1.tryToSend (MODE_ message)) {
//       sentCount1 += 1 ;
//       gotoLineColumn (MODE_ 2, 5) ;
//       printUnsigned (MODE_ sentCount1) ;
//     }
//     if (ACAN::can0.receive (MODE_ message)) {
//       receivedCount0 += 1 ;
//       gotoLineColumn (MODE_ 1, 13) ;
//       printUnsigned (MODE_ receivedCount0) ;
//     }
//     if (ACAN::can1.receive (MODE_ message)) {
//       receivedCount1 += 1 ;
//       gotoLineColumn (MODE_ 2, 13) ;
//       printUnsigned (MODE_ receivedCount1) ;
//     }
//   }
// }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static void tacheTest1 (USER_MODE) {
  uint32_t sentCount0 = 0 ;
  uint32_t sentCount1 = 0 ;
  uint32_t receivedCount0 = 0 ;
  uint32_t receivedCount1 = 0 ;
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
    CANMessage message ; // Standard frame, identifier equal to 0, no data
    if (digitalRead (P0_PUSH_BUTTON)) {
      if (ACAN::can0.tryToSend (MODE_ message)) {
        sentCount0 += 1 ;
      }
      message.mIdentifier = 0x01 ; // Standard frame, identifier equal to 1, no data
      message.mFormat = kExtended ;
      if (ACAN::can1.tryToSend (MODE_ message)) {
        sentCount1 += 1 ;
      }
    }
    if (ACAN::can0.receive (MODE_ message)) {
      receivedCount0 += 1 ;
    }
    if (ACAN::can1.receive (MODE_ message)) {
      receivedCount1 += 1 ;
    }
    if (displayDate < millis (MODE)) {
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
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

// static uint64_t gStack0 [64] ;
static uint64_t gStack1 [64] ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static void initApplication (INIT_MODE) {
  ACANSettings settings (MODE_ 125 * 1000) ;
  //  settings.mLoopBack = true ;
  uint32_t errorCode = ACAN::can0.begin (MODE_ settings) ;
  assertion (errorCode == 0, errorCode, __FILE__, __LINE__) ;
  errorCode = ACAN::can1.begin (MODE_ settings) ;
  assertion (errorCode == 0, errorCode, __FILE__, __LINE__) ;

//   kernel_createTask (MODE_ gStack0, sizeof (gStack0), tacheTest0) ;
  kernel_createTask (MODE_ gStack1, sizeof (gStack1), tacheTest1) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

MACRO_INIT_ROUTINE (initApplication) ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

