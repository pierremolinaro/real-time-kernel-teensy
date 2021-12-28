#include "all-headers.h"

//-----------------------------------------------------------------------------

static void configureFaultRegisters (BOOT_MODE) {
//---------- ACTLR register (reset value: 0)
// Bit 1: Disables write buffer use during default memory map accesses. This causes all bus faults to be
//   precise, but decreases the performance of the processor because stores to memory must complete before
//   the next instruction can be executed.
// Bit 0: Disables interruption of multi-cycle instructions. This increases the interrupt latency of the processor
//   because load/store and multiply/divide operations complete before interrupt stacking occurs.
//  SCB_ACTLR = (1 << 1) ;
//---------- SHCSR register
//    SHCSR |=
//      (1 << 16) | // Memory Management Fault exception enable bit, set to 1 to enable; set to 0 to disable
//      (1 << 17) | // BusFault exception enable bit, set to 1 to enable; set to 0 to disable
//      (1 << 18) ; // UsageFault exception enable bit, set to 1 to enable; set to 0 to disable
//---------- SCB_CCR register
  SCB_CCR |=
    (1 << 4) | // Enable UsageFault when the processor executes an SDIV or UDIV instruction with a divisor of 0
    (1 << 3) ; // Enable UsageFault when a memory access to unaligned addresses are performed
}

//-----------------------------------------------------------------------------

MACRO_BOOT_ROUTINE (configureFaultRegisters) ;

//-----------------------------------------------------------------------------

static void endlessLoop (FAULT_MODE) {
  pinMode (L0_LED, DigitalMode::OUTPUT) ;
  pinMode (L1_LED, DigitalMode::OUTPUT) ;
  pinMode (L2_LED, DigitalMode::OUTPUT) ;
  pinMode (L3_LED, DigitalMode::OUTPUT) ;
  pinMode (L4_LED, DigitalMode::OUTPUT) ;
  while (1) {
    digitalToggle (L0_LED) ;
    digitalToggle (L1_LED) ;
    digitalToggle (L2_LED) ;
    digitalToggle (L3_LED) ;
    digitalToggle (L4_LED) ;
    busyWaitDuring_faultMode (MODE_ 200);
  }
}

//-----------------------------------------------------------------------------

#define MMFSR (* ((volatile uint8_t *) 0xE000ED28))
#define MMFAR (* ((volatile uint32_t *) 0xE000ED34))

#define BFSR (* ((volatile uint8_t *) 0xE000ED29))
#define BFAR (* ((volatile uint32_t *) 0xE000ED38))

#define UFSR (* ((volatile uint16_t *) 0xE000ED2A))

#define AFSR (* ((volatile uint32_t *) 0xE000ED3C))

//-----------------------------------------------------------------------------

static void handleFault (FAULT_MODE_ const char * inTitle,  const uint32_t inLinkRegisterValue) {
//----------------- Init Systick (LCD display requires an 1 ms timer)
  configureSystick_faultMode (MODE) ;
//---
  pinMode (L0_LED, DigitalMode::OUTPUT) ;
  pinMode (L1_LED, DigitalMode::OUTPUT) ;
  pinMode (L2_LED, DigitalMode::OUTPUT) ;
  pinMode (L3_LED, DigitalMode::OUTPUT) ;
  pinMode (L4_LED, DigitalMode::OUTPUT) ;
  uint32_t displayedPage = 0 ;
  uint32_t displayCounter = 0 ;
  bool encoderA = false ;
  bool display = true ;
  pinMode (ENCODER_A, DigitalMode::INPUT_PULLUP) ;
  pinMode (ENCODER_B, DigitalMode::INPUT_PULLUP) ;
  while (1) {
  //--- Wait
    busyWaitDuring_faultMode (MODE_ 1);
  //--- Handle encoder
    const bool currentEncoderA = digitalRead (ENCODER_A) ;
    if (encoderA && !currentEncoderA) {
      display = true ;
      if (digitalRead (ENCODER_B)) {
        displayedPage = (displayedPage + 1) % 4 ;
      }else{
        displayedPage = (displayedPage + 3) % 4 ;
      }
    }
    encoderA = currentEncoderA ;
  //--- Display
    if (displayCounter > 0) {
      displayCounter -= 1 ;
    }else{
      displayCounter = 200 ;
      digitalToggle (L0_LED) ;
      digitalToggle (L1_LED) ;
      digitalToggle (L2_LED) ;
      digitalToggle (L3_LED) ;
      digitalToggle (L4_LED) ;
      if (display) {
        display = false ;
        initScreen_faultMode (MODE) ;
        printString_faultMode (MODE_ inTitle) ;
        gotoLineColumn_faultMode (MODE_ 0, 19) ;
        printUnsigned_faultMode (MODE_ displayedPage) ;
        gotoLineColumn_faultMode (MODE_ 1, 0) ;
        switch (displayedPage) {
        case 0 :
          printString_faultMode (MODE_ "SHCSR: 0x") ;
          printHex8_faultMode (MODE_ SCB_SHCSR) ;
          gotoLineColumn_faultMode (MODE_ 2, 0) ;
          printString_faultMode (MODE_ "MMFSR: 0x") ;
          printHex2_faultMode (MODE_ MMFSR) ;
          gotoLineColumn_faultMode (MODE_ 3, 0) ;
          printString_faultMode (MODE_ "MMFAR: 0x") ;
          printHex8_faultMode (MODE_ MMFAR) ;
          break ;
        case 1 :
          printString_faultMode (MODE_ "BFSR: 0x") ;
          printHex2_faultMode (MODE_ BFSR) ;
          gotoLineColumn_faultMode (MODE_ 2, 0) ;
          printString_faultMode (MODE_ "BFAR: 0x") ;
          printHex8_faultMode (MODE_ BFAR) ;
          gotoLineColumn_faultMode (MODE_ 3, 0) ;
          printString_faultMode (MODE_ "CCR: 0x") ;
          printHex8_faultMode (MODE_ SCB_CCR) ;
          break ;
        case 2 :
          printString_faultMode (MODE_ "AFSR: 0x") ;
          printHex8_faultMode (MODE_ AFSR) ;
          gotoLineColumn_faultMode (MODE_ 2, 0) ;
          printString_faultMode (MODE_ "UFSR: 0x") ;
          printHex4_faultMode (MODE_ UFSR) ;
          break ;
        case 3 :
          printString_faultMode (MODE_ "LR: 0x") ;
          printHex8_faultMode (MODE_ inLinkRegisterValue) ;
          gotoLineColumn_faultMode (MODE_ 2, 0) ;
          if ((inLinkRegisterValue & (1 << 2)) != 0) { // Fault occurs in user mode
            uint32_t psp ;
            asm ("mrs %[result], psp" : [result] "=r" (psp) ) ;
            printString_faultMode (MODE_ "PSP: 0x") ;
            printHex8_faultMode (MODE_ psp) ;
            uint32_t * framePtr = (uint32_t *) psp ;
            const uint32_t pc = framePtr [6] ;
            gotoLineColumn_faultMode (MODE_ 3, 0) ;
            printString_faultMode (MODE_ "PC: 0x") ;
            printHex8_faultMode (MODE_ pc) ;
          }else{ // Fault occurs in system mode
            uint32_t msp ;
            asm ("mrs %[result], msp" : [result] "=r" (msp) ) ;
            printString_faultMode (MODE_ "MSP: 0x") ;
            printHex8_faultMode (MODE_ msp) ;
            uint32_t * framePtr = (uint32_t *) msp ;
            const uint32_t pc = framePtr [6] ;
            gotoLineColumn_faultMode (MODE_ 3, 0) ;
            printString_faultMode (MODE_ "PC: 0x") ;
            printHex8_faultMode (MODE_ pc) ;
          }
          break ;
        }
      }
    }
  }
}

//-----------------------------------------------------------------------------

void HardFault_handler (FAULT_MODE) {
//----------------- Init display
  uint32_t linkRegisterValue ;
  asm ("mov %[result], lr" : [result] "=r" (linkRegisterValue) ) ;
  handleFault (MODE_ "HardFault", linkRegisterValue) ;
}

//-----------------------------------------------------------------------------

void MemManage_handler (FAULT_MODE) {
//----------------- Init display
  uint32_t linkRegisterValue ;
  asm ("mov %[result], lr" : [result] "=r" (linkRegisterValue) ) ;
  handleFault (MODE_ "MemManage", linkRegisterValue) ;
}

//-----------------------------------------------------------------------------

void BusFault_handler (FAULT_MODE) {
//----------------- Init display
  uint32_t linkRegisterValue ;
  asm ("mov %[result], lr" : [result] "=r" (linkRegisterValue) ) ;
  handleFault (MODE_ "BusFault", linkRegisterValue) ;
}

//-----------------------------------------------------------------------------

void UsageFault_handler (FAULT_MODE) {
//----------------- Init display
  uint32_t linkRegisterValue ;
  asm ("mov %[result], lr" : [result] "=r" (linkRegisterValue) ) ;
  handleFault (MODE_ "UsageFault", linkRegisterValue) ;
}

//-----------------------------------------------------------------------------
//    UNUSED INTERRUPT
//-----------------------------------------------------------------------------

void unusedInterrupt (FAULT_MODE_ const uint32_t inInterruptIndex) asm ("unused.interrupt") ;

void unusedInterrupt (FAULT_MODE_ const uint32_t inInterruptIndex) {
//----------------- Init Systick (LCD display requires an 1 ms timer)
  configureSystick_faultMode (MODE) ;
//----------------- Init display
  initScreen_faultMode (MODE) ;
//----------------- Title
  printString_faultMode (MODE_ "Unhandled interrupt") ;
  gotoLineColumn_faultMode (MODE_ 1, 0) ;
  printUnsigned_faultMode (MODE_ inInterruptIndex) ;
//----------------- Endless loop
  endlessLoop (MODE) ;
}

//-----------------------------------------------------------------------------
//    ASSERTION
//-----------------------------------------------------------------------------

void section_assertionFailure (FAULT_MODE_
                               const uint32_t inMessageValue,
                               const char * inFileName,
                               const int inLine) {
//----------------- Init Systick (LCD display requires an 1 ms timer)
  configureSystick_faultMode (MODE) ;
//----------------- Init display
  initScreen_faultMode (MODE) ;
//----------------- Title
  printString_faultMode (MODE_ "Assertion Failure") ;
//----------------- Associated value
  gotoLineColumn_faultMode (MODE_ 1, 0) ;
  printString_faultMode (MODE_ "Value: ") ;
  printUnsigned_faultMode (MODE_ inMessageValue) ;
//----------------- File
  int32_t idx = (int32_t) strlen (inFileName) ;
  bool loop = true ;
  while ((idx > 0) && loop) {
    idx -= 1 ;
    loop = inFileName [idx] != '/' ;
  }
  gotoLineColumn_faultMode (MODE_ 2, 0) ;
  printString_faultMode (MODE_ & inFileName [idx + 1]) ;
//----------------- Line
  gotoLineColumn_faultMode (MODE_ 3, 0) ;
  printString_faultMode (MODE_ "Line: ") ;
  printUnsigned_faultMode (MODE_ (uint32_t) inLine) ;
//----------------- Endless loop
  endlessLoop (MODE) ;
}

//-----------------------------------------------------------------------------

void assertion (const bool inAssertion,
                const uint32_t inMessageValue,
                const char * inFileName,
                const int inLine) {
  if (!inAssertion) {
    assertionFailure (inMessageValue, inFileName, inLine) ;
  }
}

//-----------------------------------------------------------------------------

void assertNonNullPointer (const void * inPointer,
                           const char * inFileName,
                           const int inLine) {
  if (nullptr == inPointer) {
    assertionFailure (0, inFileName, inLine) ;
  }
}

//-----------------------------------------------------------------------------
