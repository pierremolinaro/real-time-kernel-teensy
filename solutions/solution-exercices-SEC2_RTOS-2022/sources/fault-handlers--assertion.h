#pragma once

//-----------------------------------------------------------------------------

#include "software-modes.h"

//-----------------------------------------------------------------------------

//$interrupt-section HardFault

void HardFault_handler (FAULT_MODE) asm ("interrupt.section.HardFault") ;

//-----------------------------------------------------------------------------

//$interrupt-section MemManage

void MemManage_handler (FAULT_MODE) asm ("interrupt.section.MemManage") ;

//-----------------------------------------------------------------------------

//$interrupt-section BusFault

void BusFault_handler (FAULT_MODE) asm ("interrupt.section.BusFault") ;

//-----------------------------------------------------------------------------

//$interrupt-section UsageFault

void UsageFault_handler (FAULT_MODE) asm ("interrupt.section.UsageFault") ;

//-----------------------------------------------------------------------------

void assertion (const bool inAssertion,
                const uint32_t inMessageValue,
                const char * inFileName,
                const int inLine) ;

//-----------------------------------------------------------------------------

void assertNonNullPointer (const void * inPointer,
                           const char * inFileName,
                           const int inLine) ;

//-----------------------------------------------------------------------------

//$section assertion.failure

void assertionFailure (const uint32_t inMessageValue,
                       const char * inFileName,
                       const int inLine) asm ("assertion.failure") ;

void section_assertionFailure (FAULT_MODE_
                               const uint32_t inMessageValue,
                               const char * inFileName,
                               const int inLine) asm ("section.assertion.failure") ;

//-----------------------------------------------------------------------------
