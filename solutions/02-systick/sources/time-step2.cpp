#include "all-headers.h"

//-----------------------------------------------------------------------------
//   Configure systick
//-----------------------------------------------------------------------------

void startSystick (void) {
//------------------------------------ Configure Systick
  SYST_RVR = CPU_MHZ * 1000 - 1 ; // Underflow every ms
  SYST_CVR = 0 ;
  SYST_CSR = SYST_CSR_CLKSOURCE | SYST_CSR_ENABLE ;
}

//-----------------------------------------------------------------------------
//   busyWaitDuring
//-----------------------------------------------------------------------------

void busyWaitDuring (const uint32_t inDelayMS) {
  const uint32_t COUNTFLAG_MASK = 1 << 16 ;
  for (uint32_t i=0 ; i<inDelayMS ; i++) {
    while ((SYST_CSR & COUNTFLAG_MASK) == 0) {} // Busy wait, polling COUNTFLAG
  }
}

//-----------------------------------------------------------------------------