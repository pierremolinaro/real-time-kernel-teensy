#include "all-headers.h"

//-----------------------------------------------------------------------------

void setup (USER_MODE) {
//--- Programmer l'interruption sur front descendant sur le port PTD0 (CLIC de l'encodeur)
  PORTD_PCR (0) |= PORT_PCR_IRQC (10) ;
  NVIC_ENABLE_IRQ (ISRSlot::PORTD) ;
//--- Message d'accueil
  printString (MODE_ "Hello!") ;
}

//-----------------------------------------------------------------------------

static uint32_t gDownCounter = 10 ;
static volatile uint32_t gClicCount ;

//-----------------------------------------------------------------------------

void loop (USER_MODE) {
  busyWaitDuring (MODE_ 1000) ;
  gotoLineColumn (MODE_ 0, 7) ;
  printUnsigned (MODE_ gDownCounter) ;
  printSpaces (MODE_ 1) ;
  printUnsigned (MODE_ millis (MODE) / gDownCounter) ; // DIVISION PAR ZÉRO
  gDownCounter -- ;
  gotoLineColumn (MODE_ 1, 0) ;
  printUnsigned (MODE_ gClicCount) ;
}

//-----------------------------------------------------------------------------

void clicInterrupt (SECTION_MODE) {
  gClicCount += 1 ;
//--- Acquitter l'interruption
  PORTD_PCR (0) |= PORT_PCR_ISF ;
  const uint32_t x __attribute__((unused)) = PORTD_PCR (0) ;
}

//-----------------------------------------------------------------------------
