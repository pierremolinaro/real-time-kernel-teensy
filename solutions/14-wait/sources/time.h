#pragma once

//-----------------------------------------------------------------------------

#include "software-modes.h"

//-----------------------------------------------------------------------------
//   INIT MODE
//-----------------------------------------------------------------------------

void busyWaitDuring_initMode (INIT_MODE_ const uint32_t inDelayMS) ;

//-----------------------------------------------------------------------------
//   FAULT MODE
//-----------------------------------------------------------------------------

void configureSystick_faultMode (FAULT_MODE) ;

void busyWaitDuring_faultMode (FAULT_MODE_ const uint32_t inDelayMS) ;

//-----------------------------------------------------------------------------
//   USER MODE
//-----------------------------------------------------------------------------

void waitDuring (USER_MODE_ const uint32_t inDelayMS) ;

//$service wait.until

void waitUntil (USER_MODE_ const uint32_t inDeadlineMS) asm ("wait.until") ;

void service_waitUntil (KERNEL_MODE_ const uint32_t inDeadlineMS) asm ("service.wait.until") ;

//-----------------------------------------------------------------------------
//   ANY MODE
//-----------------------------------------------------------------------------

uint32_t systick (ANY_MODE) ;

uint32_t millis (ANY_MODE) ;

//-----------------------------------------------------------------------------
//   micros current value
//-----------------------------------------------------------------------------

//$section time.micros

uint64_t micros (USER_MODE) asm ("time.micros") ;

uint64_t section_micros (SECTION_MODE) asm ("section.time.micros") ;

//-----------------------------------------------------------------------------
//   INTERRUPT ROUTINE
//-----------------------------------------------------------------------------

//$interrupt-service SysTick
void systickInterruptServiceRoutine (IRQ_MODE) asm ("interrupt.service.SysTick") ;

//-----------------------------------------------------------------------------
//
// Insert routine address into 'real.time.interrupt.routine.array' section
//
//-----------------------------------------------------------------------------

#define MACRO_REAL_TIME_ISR(ROUTINE) \
  static void (* UNIQUE_IDENTIFIER) (IRQ_MODE_ const uint32_t inUptime) \
  __attribute__ ((section ("real.time.interrupt.routine.array"))) \
  __attribute__ ((unused)) \
  __attribute__ ((used)) = ROUTINE ;

//-----------------------------------------------------------------------------
