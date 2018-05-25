#include "all-headers.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Teensy led is connected to PORTC:5 (active high)

void setup (USER_MODE) {
//--- Configure PTC5 as digital port (input or output)
  PORTC_PCR (5) = PORT_PCR_MUX (1) ;
//--- Configure PTC5 as digital output port (output level is low --> led is off)
  GPIOC_PDDR |= (1 << 5) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void loop (USER_MODE) {
//--- Drive PTC5 high --> led is on
  GPIOC_PSOR = 1 << 5 ;
//--- Wait...
  busyWaitDuring (MODE_ 250) ;
//--- Drive PTC5 low --> led is off
  GPIOC_PCOR = 1 << 5 ;
//--- Wait...
  busyWaitDuring (MODE_ 250) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
