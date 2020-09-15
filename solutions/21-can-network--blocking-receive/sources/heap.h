#pragma once

//——————————————————————————————————————————————————————————————————————————————————————————————————

#include "software-modes.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————

#include <stddef.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————
//   MEMORY ALLOC
//——————————————————————————————————————————————————————————————————————————————————————————————————

//$section fat.pointer.alloc

void * fatPointerAlloc (const size_t inBlockSize) asm ("fat.pointer.alloc") ;

void * section_fatPointerAlloc (SECTION_MODE_ const size_t inBlockSize) asm ("section.fat.pointer.alloc") ;

//——————————————————————————————————————————————————————————————————————————————————————————————————
//   MEMORY FREE
//——————————————————————————————————————————————————————————————————————————————————————————————————

//$section fat.pointer.free

void fatPointerFree (void * inPointer) asm ("fat.pointer.free") ;

void section_fatPointerFree (SECTION_MODE_ void * inPointer)  asm ("section.fat.pointer.free") ;

//——————————————————————————————————————————————————————————————————————————————————————————————————
//   ALLOCATED BLOCK SIZE
//——————————————————————————————————————————————————————————————————————————————————————————————————

uint32_t fatPointerSize (const void * inPointer) ;

//——————————————————————————————————————————————————————————————————————————————————————————————————
//   HELPER FUNCTIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————

STATIC size_t heapEndAddress (void) ;

STATIC size_t heapStartAddress (void) ;

STATIC size_t freeRAMByteCount (void) ;

STATIC size_t usedRAMByteCount (void) ;

STATIC uint32_t currentlyAllocatedObjectCount (void) ;

STATIC uint32_t allocationCount (void) ;

STATIC uint32_t freeObjectCountForListIndex (const uint32_t inFreeListIndex) ;

STATIC uint32_t allocationCountForListIndex (const uint32_t inIndex) ;

//——————————————————————————————————————————————————————————————————————————————————————————————————
//   BLOCK SIZES
//——————————————————————————————————————————————————————————————————————————————————————————————————

static const size_t kMaxSizePowerOfTwo = 10 ; // Biggest block being allocated = 2 ** kMaxSizePowerOfTwo
static const size_t kMinSizePowerOfTwo =  3 ; // Smallest block being allocated = 2 ** kMinSizePowerOfTwo
static const size_t kSegregatedAllocationListCount = kMaxSizePowerOfTwo - kMinSizePowerOfTwo + 1 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————
