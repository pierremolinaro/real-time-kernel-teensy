#include "all-headers.h"

//----------------------------------------------------------------------------------------------------------------------

static void configureActivityLed (INIT_MODE) {
//--- Leds
  pinMode (L0_LED, OUTPUT) ;
  pinMode (L1_LED, OUTPUT) ;
  pinMode (L2_LED, OUTPUT) ;
  pinMode (L3_LED, OUTPUT) ;
  pinMode (L4_LED, OUTPUT) ;
//--- Push buttons
  pinMode (P0_PUSH_BUTTON, INPUT_PULLUP) ;
  pinMode (P1_PUSH_BUTTON, INPUT_PULLUP) ;
  pinMode (P2_PUSH_BUTTON, INPUT_PULLUP) ;
  pinMode (P3_PUSH_BUTTON, INPUT_PULLUP) ;
  pinMode (P4_PUSH_BUTTON, INPUT_PULLUP) ;
//--- Encoder
  pinMode (ENCODER_A, INPUT_PULLUP) ;
  pinMode (ENCODER_B, INPUT_PULLUP) ;
  pinMode (ENCODER_CLIC, INPUT_PULLUP) ;
//--- Teensy Led
  pinMode (DigitalPort::D13, OUTPUT) ;
  digitalWrite (DigitalPort::D13, true) ; // On
}

//----------------------------------------------------------------------------------------------------------------------

MACRO_INIT_ROUTINE (configureActivityLed) ;

//----------------------------------------------------------------------------------------------------------------------
