#include "all-headers.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static volatile uint32_t gNombreDonneesInserees ;
static volatile uint32_t gNombreDonneesRecues ;

static BoundedBuffer gBuffer0 ;
static BoundedBuffer gBuffer1 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static void routineInterruptionTempsReel (IRQ_MODE_ const uint32_t inUptime) {
  if (digitalRead (P0_PUSH_BUTTON) && gBuffer0.irq_append (MODE_ inUptime)) {
    gNombreDonneesInserees ++ ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

MACRO_REAL_TIME_ISR (routineInterruptionTempsReel) ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static void tacheIntermediaire (USER_MODE) {
  uint32_t data ;
  bool hasData = false ;
  while (1) {
    if (!hasData && gBuffer0.guarded_remove (MODE_ data)) {
      hasData = true ;
    }else if (hasData && gBuffer1.guarded_append (MODE_ data)) {
      hasData = false ;
    }else{
      guard_waitForChange (MODE) ;
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static void tacheReception (USER_MODE) {
  uint32_t echeance = 100 ;
  bool accepterDonnees = true ;
  uint32_t data ;
  while (1) {
    if (accepterDonnees && gBuffer1.guarded_remove (MODE_ data)) {
      gNombreDonneesRecues += 1 ;
    }else if (guard_waitUntil (MODE_ echeance)) {
      echeance += 50 ;
      accepterDonnees = digitalRead (P1_PUSH_BUTTON) ;
    }else{
      guard_waitForChange (MODE) ;
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static void tacheAffichage (USER_MODE) {
  uint32_t nombreDonneesInserees = UINT32_MAX ;
  uint32_t nombreDonneesRecues = UINT32_MAX ;
  while (1) {
    waitDuring (MODE_ 500) ;
    const uint32_t n = gNombreDonneesInserees ;
    if (nombreDonneesInserees != n) {
      nombreDonneesInserees = n ;
      gotoLineColumn (MODE_ 0, 0) ;
      printUnsigned (MODE_ nombreDonneesInserees) ;
    }
    const uint32_t m = gNombreDonneesRecues ;
    if (nombreDonneesRecues != m) {
      nombreDonneesRecues = m ;
      gotoLineColumn (MODE_ 1, 0) ;
      printUnsigned (MODE_ nombreDonneesRecues) ;
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static uint64_t gStack1 [64] ;
static uint64_t gStack2 [64] ;
static uint64_t gStack3 [64] ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static void initTasks (INIT_MODE) {
  kernel_createTask (MODE_ gStack1, sizeof (gStack1), tacheAffichage) ;
  kernel_createTask (MODE_ gStack2, sizeof (gStack2), tacheIntermediaire) ;
  kernel_createTask (MODE_ gStack3, sizeof (gStack3), tacheReception) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

MACRO_INIT_ROUTINE (initTasks) ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

