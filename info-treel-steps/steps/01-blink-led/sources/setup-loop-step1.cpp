#include "all-headers.h"

//-----------------------------------------------------------------------------
// Led L2 is connected to PORTD:7 (active high)

void setup (void) {
//--- Configure PTD7 as digital port (input or output)
  PORTD_PCR (7) = PORT_PCR_MUX (1) ;
//--- Configure PTD7 as digital output port (output level is low --> led is off)
  GPIOD_PDDR |= (1 << 7) ;
}

//-----------------------------------------------------------------------------

void loop (void) {
//--- Drive PTD7 high --> led is on
  GPIOD_PSOR = 1 << 7 ;
//--- Wait...
  for (volatile uint32_t i=0 ; i< 1 * 1000 * 1000 ; i++) {}
//--- Drive PTD7 low --> led is off
  GPIOD_PCOR = 1 << 7 ;
//--- Wait...
  for (volatile uint32_t i=0 ; i< 10 * 1000 * 1000 ; i++) {}
}

//-----------------------------------------------------------------------------
