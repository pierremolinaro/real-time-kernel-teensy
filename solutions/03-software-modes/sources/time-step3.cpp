#include "all-headers.h"

//-----------------------------------------------------------------------------
//   Configure systick
//-----------------------------------------------------------------------------

void startSystick (USER_MODE) {
//------------------------------------ Configure Systick
  SYST_RVR = CPU_MHZ * 1000 - 1 ; // Underflow every ms
  SYST_CVR = 0 ;
  SYST_CSR = SYST_CSR_CLKSOURCE | SYST_CSR_ENABLE ;
}

//-----------------------------------------------------------------------------
//   busyWaitDuring
//-----------------------------------------------------------------------------

void busyWaitDuring (USER_MODE_ const uint32_t inDelayMS) {
  for (uint32_t i=0 ; i<inDelayMS ; i++) {
    while ((SYST_CSR & SYST_CSR_COUNTFLAG) == 0) {} // Busy wait, polling COUNTFLAG
  }
}

//-----------------------------------------------------------------------------
