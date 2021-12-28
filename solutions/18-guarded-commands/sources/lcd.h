#pragma once

//-----------------------------------------------------------------------------

#include "software-modes.h"

//-----------------------------------------------------------------------------
//    USER MODE
//-----------------------------------------------------------------------------

void clearScreen (USER_MODE) ;

void gotoLineColumn (USER_MODE_ const uint32_t inLine, const uint32_t inColumn) ;

void printString (USER_MODE_ const char * inString) ;

void printChar (USER_MODE_ const char inChar) ;

void printSpaces (USER_MODE_ const uint32_t inCount) ;

void printUnsigned (USER_MODE_ const uint32_t inValue) ;

void printUnsigned64 (USER_MODE_ const uint64_t inValue) ;

void printSigned (USER_MODE_ const int32_t inValue) ;

void printHex1 (USER_MODE_ const uint32_t inValue) ;

void printHex2 (USER_MODE_ const uint32_t inValue) ;

void printHex4 (USER_MODE_ const uint32_t inValue) ;

void printHex8 (USER_MODE_ const uint32_t inValue) ;

void printHex16 (USER_MODE_ const uint64_t inValue) ;

//-----------------------------------------------------------------------------
//    FAULT MODE
//-----------------------------------------------------------------------------

void initScreen_faultMode (FAULT_MODE) ;

void gotoLineColumn_faultMode (FAULT_MODE_ const uint32_t inLine, const uint32_t inColumn) ;

void printString_faultMode (FAULT_MODE_ const char * inString) ;

void printChar_faultMode (FAULT_MODE_ const char inChar) ;

void printUnsigned_faultMode (FAULT_MODE_ const uint32_t inValue) ;

void printHex8_faultMode (FAULT_MODE_ const uint32_t inValue) ;

void printHex4_faultMode (FAULT_MODE_ const uint32_t inValue) ;

void printHex2_faultMode (FAULT_MODE_ const uint32_t inValue) ;

//-----------------------------------------------------------------------------
