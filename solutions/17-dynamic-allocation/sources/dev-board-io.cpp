#include "all-headers.h"

//----------------------------------------------------------------------------------------------------------------------

static void configurePorts (INIT_MODE) {
//--- Leds
  pinMode (L0_LED, DigitalMode::OUTPUT) ;
  pinMode (L1_LED, DigitalMode::OUTPUT) ;
  pinMode (L2_LED, DigitalMode::OUTPUT) ;
  pinMode (L3_LED, DigitalMode::OUTPUT) ;
  pinMode (L4_LED, DigitalMode::OUTPUT) ;
//--- Push buttons
  pinMode (P0_PUSH_BUTTON, DigitalMode::INPUT_PULLUP) ;
  pinMode (P1_PUSH_BUTTON, DigitalMode::INPUT_PULLUP) ;
  pinMode (P2_PUSH_BUTTON, DigitalMode::INPUT_PULLUP) ;
  pinMode (P3_PUSH_BUTTON, DigitalMode::INPUT_PULLUP) ;
  pinMode (P4_PUSH_BUTTON, DigitalMode::INPUT_PULLUP) ;
//--- Encoder
  pinMode (ENCODER_A, DigitalMode::INPUT_PULLUP) ;
  pinMode (ENCODER_B, DigitalMode::INPUT_PULLUP) ;
  pinMode (ENCODER_CLIC, DigitalMode::INPUT_PULLUP) ;
//--- Teensy Led
  pinMode (DigitalPort::D13, DigitalMode::OUTPUT) ;
  digitalWrite (DigitalPort::D13, true) ; // On
}

//----------------------------------------------------------------------------------------------------------------------

MACRO_INIT_ROUTINE (configurePorts) ;

//----------------------------------------------------------------------------------------------------------------------
