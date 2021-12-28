#pragma once

//-----------------------------------------------------------------------------

#include "software-modes.h"

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
