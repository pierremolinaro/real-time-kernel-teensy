#include "all-headers.h"

//-----------------------------------------------------------------------------
//   Configure systick
//-----------------------------------------------------------------------------

static void startSystick (BOOT_MODE) {
//------------------------------------ Configure Systick
  SYST_RVR = CPU_MHZ * 1000 - 1 ; // Underflow every ms
  SYST_CVR = 0 ;
  SYST_CSR = SYST_CSR_CLKSOURCE | SYST_CSR_ENABLE ;
//------------------------------------ Configure and chain PIT0 and PIT1 for 64-bit counting
//--- Power on PIT
  SIM_SCGC6 |= SIM_SCGC6_PIT ;
//--- Enable PIT module
  PIT_MCR = 0 ;
//--- Disable PIT0 and PIT1
  PIT_TCTRL (0) = 0 ;
  PIT_TCTRL (1) = 0 ;
//--- PIT0 and PIT1 down-count: initialize them with all 1's
  PIT_LDVAL (0) = UINT32_MAX ;
  PIT_LDVAL (1) = UINT32_MAX ;
//--- Enable PIT0 and PIT1: start counting, chain PI1 to PIT0, no interrupt
  PIT_TCTRL (1) = PIT_TCTRL_CHN | PIT_TCTRL_TEN ;
  PIT_TCTRL (0) = PIT_TCTRL_TEN ;
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
//   micros current value
//-----------------------------------------------------------------------------

uint64_t section_micros (SECTION_MODE) {
//--- To obtain the correct value, first read LTMR64H and then LTMR64L
  uint64_t result = PIT_LTMR64H ;
  result <<= 32 ;
  result |= PIT_LTMR64L ;
//--- PIT0 and PIT1 actually downcount
  result = ~ result ;
//--- Divide by the clock frequency in MHz for getting microsecond count
  return result / busMHZ () ;
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
//   Configure systick — FAULT MODE
//-----------------------------------------------------------------------------

void configureSystick_faultMode (FAULT_MODE) {
//------------------------------------ Configure Systick
  SYST_CSR = 0 ; // Stop systick
  SYST_RVR = CPU_MHZ * 1000 - 1 ; // Underflow every ms
  SYST_CVR = 0 ;
  SYST_CSR = SYST_CSR_CLKSOURCE | SYST_CSR_ENABLE ;
}

//-----------------------------------------------------------------------------
//   busyWaitDuring — FAULT MODE
//-----------------------------------------------------------------------------

void busyWaitDuring_faultMode (FAULT_MODE_ const uint32_t inDelayMS) {
  for (uint32_t i=0 ; i<inDelayMS ; i++) {
    while ((SYST_CSR & SYST_CSR_COUNTFLAG) == 0) {} // Busy wait, polling COUNTFLAG
  }
}

//-----------------------------------------------------------------------------
//   millis — ANY MODE
//-----------------------------------------------------------------------------

static volatile uint32_t gUptime ;

//-----------------------------------------------------------------------------

uint32_t millis (ANY_MODE) {
  return gUptime ;
}

//-----------------------------------------------------------------------------
//   systick — ANY MODE
//-----------------------------------------------------------------------------

uint32_t systick (ANY_MODE) {
  return SYST_CVR ;
}

//-----------------------------------------------------------------------------
//   SYSTICK interrupt service routine
//-----------------------------------------------------------------------------

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
