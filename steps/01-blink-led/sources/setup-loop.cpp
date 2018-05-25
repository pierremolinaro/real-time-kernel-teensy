#include "all-headers.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Teensy led is connected to PORTC:5 (active high)

void setup (void) {
//--- Configure PTC5 as digital port (input or output)
  PORTC_PCR (5) = PORT_PCR_MUX (1) ;
//--- Configure PTC5 as digital output port (output level is low --> led is off)
  GPIOC_PDDR |= (1 << 5) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void loop (void) {
//--- Drive PTC5 high --> led is on
  GPIOC_PSOR = 1 << 5 ;
//--- Wait...
  for (volatile uint32_t i=0 ; i< 10 * 1000 * 1000 ; i++) {}
//--- Drive PTC5 low --> led is off
  GPIOC_PCOR = 1 << 5 ;
//--- Wait...
  for (volatile uint32_t i=0 ; i< 10 * 1000 * 1000 ; i++) {}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
