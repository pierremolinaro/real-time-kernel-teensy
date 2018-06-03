#include "all-headers.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   Configure systick
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static void startSystick (BOOT_MODE) {
//------------------------------------ Configure Systick
  SYST_RVR = CPU_MHZ * 1000 - 1 ; // Underflow every ms
  SYST_CVR = 0 ;
  SYST_CSR = SYST_CSR_CLKSOURCE | SYST_CSR_ENABLE ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

MACRO_BOOT_ROUTINE (startSystick) ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static void enableSystickInterrupt (INIT_MODE) {
//------------------------------------ Systick interrupt every ms
  SYST_CSR |= SYST_CSR_TICKINT ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

MACRO_INIT_ROUTINE (enableSystickInterrupt) ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   busyWaitDuring — INIT MODE
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void busyWaitDuring_initMode (INIT_MODE_ const uint32_t inDelayMS) {
  const uint32_t COUNTFLAG_MASK = 1 << 16 ;
  for (uint32_t i=0 ; i<inDelayMS ; i++) {
    while ((SYST_CSR & COUNTFLAG_MASK) == 0) {} // Busy wait, polling COUNTFLAG
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   millis — ANY MODE
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static volatile uint32_t gUptime ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

uint32_t millis (void) {
  return gUptime ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   systick — ANY MODE
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

uint32_t systick (void) {
  return SYST_CVR ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   SYSTICK interrupt service routine
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void systickInterruptServiceRoutine (SECTION_MODE) {
  const uint32_t newUptime = gUptime + 1 ;
  gUptime = newUptime ;
//--- Run real.time.interrupt.routine.array section routines
  extern void (* __real_time_interrupt_routine_array_start) (SECTION_MODE_ const uint32_t inUptime) ;
  extern void (* __real_time_interrupt_routine_array_end) (SECTION_MODE_ const uint32_t inUptime) ;
  void (* * ptr) (SECTION_MODE_ const uint32_t) = & __real_time_interrupt_routine_array_start ;
  while (ptr != & __real_time_interrupt_routine_array_end) {
    (* ptr) (MODE_ newUptime) ;
    ptr ++ ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   busyWaitDuring, busyWaitUntil — USER MODE
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void busyWaitDuring (USER_MODE_ const uint32_t inDelayMS) {
  busyWaitUntil (MODE_ gUptime + inDelayMS) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void busyWaitUntil (USER_MODE_ const uint32_t inDeadlineMS) {
  while (gUptime <= inDeadlineMS) {}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
