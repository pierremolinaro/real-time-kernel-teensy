#include "all-headers.h"

//-----------------------------------------------------------------------------

#include <stddef.h>
#include <stdbool.h>

//-----------------------------------------------------------------------------

// http://esd.cs.ucr.edu/labs/interface/interface.html

//-----------------------------------------------------------------------------
//   PORT CONFIGURATION                                                                                                *
//-----------------------------------------------------------------------------
//   LCD D4 : Teensy D16
//   LCD D5 : Teensy D15
//   LCD D6 : Teensy D14
//   LCD D7 : Teensy D19
//   LCD RS : Teensy D18
//   LCD E  : Teensy D17

static const DigitalPort LCD_D4 = DigitalPort::D16 ;

static const DigitalPort LCD_D5 = DigitalPort::D15 ;

static const DigitalPort LCD_D6 = DigitalPort::D14 ;

static const DigitalPort LCD_D7 = DigitalPort::D19 ;

static const DigitalPort LCD_RS = DigitalPort::D18 ;

static const DigitalPort LCD_E  = DigitalPort::D17 ;

//-----------------------------------------------------------------------------
//   UTILITY ROUTINES — ANY MODE                                                                                                  *
//-----------------------------------------------------------------------------

static void driveHighE (void) {
  digitalWrite (LCD_E, true) ;
}

//-----------------------------------------------------------------------------

static void driveLowE (void) {
  digitalWrite (LCD_E, false) ;
}

//-----------------------------------------------------------------------------

static void driveHighRS (void) {
  digitalWrite (LCD_RS, true) ;
}

//-----------------------------------------------------------------------------

static void driveLowRS (void) {
  digitalWrite (LCD_RS, false) ;
}

//-----------------------------------------------------------------------------

static void setD4 (const bool inValue) {
  digitalWrite (LCD_D4, inValue) ;
}

//-----------------------------------------------------------------------------

static void setD5 (const bool inValue) {
  digitalWrite (LCD_D5, inValue) ;
}

//-----------------------------------------------------------------------------

static void setD6 (const bool inValue) {
  digitalWrite (LCD_D6, inValue) ;
}

//-----------------------------------------------------------------------------

static void setD7 (const bool inValue) {
  digitalWrite (LCD_D7, inValue) ;
}

//-----------------------------------------------------------------------------

static void programLcd4BitDataBusOutput (const uint8_t inValue) {
  setD4 ((inValue & 0x01) != 0) ;
  setD5 ((inValue & 0x02) != 0) ;
  setD6 ((inValue & 0x04) != 0) ;
  setD7 ((inValue & 0x08) != 0) ;
}

//-----------------------------------------------------------------------------
//   UTILITY ROUTINES — INIT_MODE
//-----------------------------------------------------------------------------

static void write4BitCommand_initMode (INIT_MODE_ const uint8_t inCommand) {
  busyWaitDuring_initMode (MODE_ 1) ;
  driveLowRS () ;
  programLcd4BitDataBusOutput (inCommand) ;
  driveHighE () ;
  busyWaitDuring_initMode (MODE_ 1) ;
  driveLowE () ;
}

//-----------------------------------------------------------------------------

static void write8bitCommand_initMode (INIT_MODE_ const uint8_t inCommand) {
  busyWaitDuring_initMode (MODE_ 1) ;
  driveLowRS () ;
  programLcd4BitDataBusOutput ((uint8_t) (inCommand >> 4)) ;
  driveHighE () ;
  busyWaitDuring_initMode (MODE_ 1) ;
  driveLowE () ;
  busyWaitDuring_initMode (MODE_ 1) ;
  programLcd4BitDataBusOutput (inCommand) ;
  driveHighE () ;
  busyWaitDuring_initMode (MODE_ 1) ;
  driveLowE () ;
}

//-----------------------------------------------------------------------------
//   LCD INIT
//-----------------------------------------------------------------------------

static void setupLCD (INIT_MODE) {
//--- Step 1: Configure ports
  pinMode (LCD_D4, DigitalMode::OUTPUT) ;
  pinMode (LCD_D5, DigitalMode::OUTPUT) ;
  pinMode (LCD_D6, DigitalMode::OUTPUT) ;
  pinMode (LCD_D7, DigitalMode::OUTPUT) ;
  pinMode (LCD_RS, DigitalMode::OUTPUT) ;
  pinMode (LCD_E,  DigitalMode::OUTPUT) ;
//--- Step 2: wait for 15 ms
  busyWaitDuring_initMode (MODE_ 15) ;
//--- Step 3: write command 0x30
  write4BitCommand_initMode (MODE_ 0x3) ;
//--- Step 4: wait for 4,1 ms (actually 5 ms)
  busyWaitDuring_initMode (MODE_ 5) ;
//--- Step 5: write command 0x30 again
  write4BitCommand_initMode (MODE_ 0x3) ;
//--- Step 6: wait for 100 µs (actually 1 ms)
  busyWaitDuring_initMode (MODE_ 1) ;
//--- Step 7: write command 0x30 (third)
  write4BitCommand_initMode (MODE_ 0x3) ;
//--- Step 8: write command 0x20 (4-bit mode)
  write4BitCommand_initMode (MODE_ 0x2) ;
//--- Step 9: write command 'Set Interface Length' : 0 0 1 DL N F * *
//    DL : Data interface length : 0 (4 bits)
//    N : Number of Display lines : 1 (2 lines)
//    F : Character Font : 0 (5x7)
  write8bitCommand_initMode (MODE_ 0x28) ;
//--- Step 10: write command 'Display Off'
  write8bitCommand_initMode (MODE_ 0x08) ;
//--- Step 11: write command 'Clear Display'
  write8bitCommand_initMode (MODE_ 0x01) ;
//--- Step 12: write command 'Set Cursor Move Direction' : 0 0 0 0 0 1 ID S
//    ID : Increment Cursor after Each Byte Written to Display : 1 (yes)
//    S : Shift Display When Byte Written : 0 (no)
  write8bitCommand_initMode (MODE_ 0x06) ;
//--- Step 13: write command 'Move Cursor / Shift Display' : 0 0 0 1 SC RL * *
//    SC : Display Shift On : 1 (oui)
//    RL : Direction of Shift : 1 (to right)
  write8bitCommand_initMode (MODE_ 0x1C) ;
//--- Step 14: write command 'Return Cursor and LCD to Home Position'
  write8bitCommand_initMode (MODE_ 0x02) ;
//--- Step 15: write command 'Enable Display / Cursor' : 0 0 0 0 1 D C B
//    D : Turn Display On : 1 (yes)
//    C : Turn Cursor On : 0 (no)
//    B : Cursor Blink On : 0 (no)
  write8bitCommand_initMode (MODE_ 0x0C) ;
}

//-----------------------------------------------------------------------------

MACRO_INIT_ROUTINE (setupLCD) ;

//-----------------------------------------------------------------------------
//   UTILITY ROUTINES — USER MODE
//-----------------------------------------------------------------------------

static void write8bitCommand (USER_MODE_ const uint8_t inCommand) {
  busyWaitDuring (MODE_ 1) ;
  driveLowRS () ;
  programLcd4BitDataBusOutput ((uint8_t) (inCommand >> 4)) ;
  driveHighE () ;
  busyWaitDuring (MODE_ 1) ;
  driveLowE () ;
  busyWaitDuring (MODE_ 1) ;
  programLcd4BitDataBusOutput (inCommand) ;
  driveHighE () ;
  busyWaitDuring (MODE_ 1) ;
  driveLowE () ;
}

//-----------------------------------------------------------------------------

static void writeData (USER_MODE_ const uint8_t inData) {
  busyWaitDuring (MODE_ 1) ;
  driveHighRS () ;
  programLcd4BitDataBusOutput (inData >> 4) ;
  driveHighE () ;
  busyWaitDuring (MODE_ 1) ;
  driveLowE () ;
  busyWaitDuring (MODE_ 1) ;
  programLcd4BitDataBusOutput (inData) ;
  driveHighE () ;
  busyWaitDuring (MODE_ 1) ;
  driveLowE () ;
}

//-----------------------------------------------------------------------------
//   PRINT ROUTINES — USER MODE
//-----------------------------------------------------------------------------

void clearScreen (USER_MODE) {
  write8bitCommand (MODE_ 0x01) ;
}

//-----------------------------------------------------------------------------
// Line 0 : 00 -> 19
// Line 1 : 64 -> 83
// Line 2 : 20 -> 39
// Line 3 : 84 -> 103

void gotoLineColumn (USER_MODE_ const uint32_t inLine, const uint32_t inColumn) {
  static const uint8_t tab [4] = {0, 64, 20, 84} ;
  if ((inLine < 4) && (inColumn < 20)) {
    write8bitCommand (MODE_ tab [inLine] + inColumn + 0x80U) ;
  }
}

//-----------------------------------------------------------------------------

void printString (USER_MODE_ const char * inString) {
  if (NULL != inString) {
    while ('\0' != *inString) {
      writeData (MODE_ *inString) ;
      inString ++ ;
    }
  }
}

//-----------------------------------------------------------------------------

void printChar (USER_MODE_ const char inChar) {
  writeData (MODE_ inChar) ;
}

//-----------------------------------------------------------------------------

void printSpaces (USER_MODE_ const uint32_t inCount) {
  uint32_t count = inCount ;
  while (count > 0) {
    printChar (MODE_ ' ') ;
    count -- ;
  }
}

//-----------------------------------------------------------------------------

void printUnsigned (USER_MODE_ const uint32_t inValue) {
  uint32_t divisor = 1000 * 1000 * 1000 ; // 10**9
  uint32_t value = inValue ;
  bool isPrinting = false ;
  while (divisor > 0) {
    if (isPrinting || (value >= divisor)) {
      printChar (MODE_ '0' + value / divisor) ;
      value %= divisor ;
      isPrinting = true ;
    }
    divisor /= 10 ;
  }
  if (!isPrinting) {
    printChar (MODE_ '0') ;
  }
}

//-----------------------------------------------------------------------------

void printUnsigned64 (USER_MODE_ const uint64_t inValue) {
  char buffer [20] ;
  buffer [19] = '\0' ;
  buffer [18] = (inValue % 10) + '0' ;
  uint32_t idx = 18 ;
  uint64_t v = inValue / 10 ;
  while (v != 0) {
    idx -- ;
    buffer [idx] = (v % 10) + '0' ;
    v /= 10 ;
  }
  printString (MODE_ & buffer [idx]) ;
}

//-----------------------------------------------------------------------------

void printSigned (USER_MODE_ const int32_t inValue) {
  if (inValue < 0) {
    printChar (MODE_ '-') ;
    printUnsigned (MODE_ (uint32_t) -inValue) ;
  }else{
    printUnsigned (MODE_ (uint32_t) inValue) ;
  }
}

//-----------------------------------------------------------------------------

void printHex1 (USER_MODE_ const uint32_t inValue) {
  const uint32_t v = inValue & 0xF ;
  if (v < 10) {
    printChar (MODE_ '0' + v) ;
  }else{
    printChar (MODE_ 'A' + v - 10) ;
  }
}

//-----------------------------------------------------------------------------

void printHex2 (USER_MODE_ const uint32_t inValue) {
  printHex1 (MODE_ inValue >> 4) ;
  printHex1 (MODE_ inValue) ;
}

//-----------------------------------------------------------------------------

void printHex4 (USER_MODE_ const uint32_t inValue) {
  printHex2 (MODE_ inValue >> 8) ;
  printHex2 (MODE_ inValue) ;
}

//-----------------------------------------------------------------------------

void printHex8 (USER_MODE_ const uint32_t inValue) {
  printHex4 (MODE_ inValue >> 16) ;
  printHex4 (MODE_ inValue) ;
}

//-----------------------------------------------------------------------------

void printHex16 (USER_MODE_ const uint64_t inValue) {
  printHex8 (MODE_ (uint32_t) (inValue >> 32)) ;
  printHex8 (MODE_ (uint32_t) inValue) ;
}

//-----------------------------------------------------------------------------
