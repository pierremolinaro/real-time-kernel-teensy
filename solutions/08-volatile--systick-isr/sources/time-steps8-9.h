#pragma once

//-----------------------------------------------------------------------------

#include "software-modes.h"

//-----------------------------------------------------------------------------
//   INIT MODE
//-----------------------------------------------------------------------------

void busyWaitDuring_initMode (INIT_MODE_ const uint32_t inDelayMS) ;

//-----------------------------------------------------------------------------
//   USER MODE
//-----------------------------------------------------------------------------

void busyWaitDuring (USER_MODE_ const uint32_t inDelayMS) ;

void busyWaitUntil (USER_MODE_ const uint32_t inDeadlineMS) ;

//-----------------------------------------------------------------------------
//   ANY MODE
//-----------------------------------------------------------------------------

uint32_t systick (ANY_MODE) ;

uint32_t millis (ANY_MODE) ;

//-----------------------------------------------------------------------------
//   INTERRUPT ROUTINE
//-----------------------------------------------------------------------------

//$interrupt-section SysTick
void systickInterruptServiceRoutine (SECTION_MODE) asm ("interrupt.section.SysTick") ;

//-----------------------------------------------------------------------------
//
// Insert routine address into 'real.time.interrupt.routine.array' section
//
//-----------------------------------------------------------------------------

#define MACRO_REAL_TIME_ISR(ROUTINE) \
  static void (* UNIQUE_IDENTIFIER) (SECTION_MODE_ const uint32_t inUptime) \
  __attribute__ ((section ("real.time.interrupt.routine.array"))) \
  __attribute__ ((unused)) \
  __attribute__ ((used)) = ROUTINE ;


//-----------------------------------------------------------------------------
