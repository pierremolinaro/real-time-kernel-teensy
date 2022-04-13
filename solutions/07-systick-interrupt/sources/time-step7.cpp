#include "all-headers.h"

//-----------------------------------------------------------------------------
//   Configure systick
//-----------------------------------------------------------------------------

static void startSystick (BOOT_MODE) {
//------------------------------------ Configure Systick
  SYST_RVR = CPU_MHZ * 1000 - 1 ; // Underflow every ms
  SYST_CVR = 0 ;
  SYST_CSR = SYST_CSR_CLKSOURCE | SYST_CSR_ENABLE ;
}

//-----------------------------------------------------------------------------

MACRO_BOOT_ROUTINE (startSystick) ;

//-----------------------------------------------------------------------------

static void activateSystickInterrupt (INIT_MODE) {
  SYST_CSR |= SYST_CSR_TICKINT ;
}

//-----------------------------------------------------------------------------

MACRO_INIT_ROUTINE (activateSystickInterrupt) ;

//-----------------------------------------------------------------------------
//   systick — ANY MODE
//-----------------------------------------------------------------------------

uint32_t systick (ANY_MODE) {
  return SYST_CVR ;
}

//-----------------------------------------------------------------------------
//   busyWaitDuring — INIT MODE
//-----------------------------------------------------------------------------

void busyWaitDuring_initMode (INIT_MODE_ const uint32_t inDelayMS) {
  for (uint32_t i=0 ; i<inDelayMS ; i++) {
    while ((SYST_CSR & SYST_CSR_COUNTFLAG) == 0) {} // Busy wait, polling COUNTFLAG
  }
}

//-----------------------------------------------------------------------------
//   SYSTICK interrupt service routine
//-----------------------------------------------------------------------------

static volatile uint32_t gUptime ;

//-----------------------------------------------------------------------------

void systickInterruptServiceRoutine (SECTION_MODE) {
  gUptime += 1 ;
}

//-----------------------------------------------------------------------------
//   millis — ANY MODE
//-----------------------------------------------------------------------------

uint32_t millis (ANY_MODE) {
  return gUptime ;
}

//-----------------------------------------------------------------------------
//   busyWaitDuring, busyWaitUntil — USER MODE
//-----------------------------------------------------------------------------

void busyWaitDuring (USER_MODE_ const uint32_t inDelayMS) {
  busyWaitUntil (MODE_ gUptime + inDelayMS) ;
}

//-----------------------------------------------------------------------------

void busyWaitUntil (USER_MODE_ const uint32_t inDeadlineMS) {
  while (inDeadlineMS > gUptime) {}
}

//-----------------------------------------------------------------------------
