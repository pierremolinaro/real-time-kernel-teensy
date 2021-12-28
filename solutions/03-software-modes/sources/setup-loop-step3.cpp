#include "all-headers.h"

//-----------------------------------------------------------------------------
// Led L2 is connected to PORTD:7 (active high)

void setup (USER_MODE) {
//--- Configure Systick
  startSystick (MODE) ;
//--- Configure PTD7 as digital port (input or output)
  PORTD_PCR (7) = PORT_PCR_MUX (1) ;
//--- Configure PTD7 as digital output port (output level is low --> led is off)
  GPIOD_PDDR |= (1 << 7) ;
}

//-----------------------------------------------------------------------------

void loop (USER_MODE) {
//--- Drive PTD7 high --> led is on
  GPIOD_PSOR = 1 << 7 ;
//--- Wait...
  busyWaitDuring (MODE_ 250) ;
//--- Drive PTD7 low --> led is off
  GPIOD_PCOR = 1 << 7 ;
//--- Wait...
  busyWaitDuring (MODE_ 250) ;
}

//-----------------------------------------------------------------------------
