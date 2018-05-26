#pragma once

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "logical-modes.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   MEMORY ALLOC
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//$section memory.alloc

void * memoryAlloc (const size_t inBlockSize) asm ("memory.alloc") ;

void * section_memoryAlloc (SECTION_MODE_ const size_t inBlockSize) asm ("section.memory.alloc") ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   MEMORY FREE
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//$section memory.free

void memoryFree (void * inPointer) asm ("memory.free") ;

void section_memoryFree (SECTION_MODE_ void * inPointer) asm ("section.memory.free") ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   ALLOCATED BLOCK SIZE
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

uint32_t memoryByteSize (void * inPointer) ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   HELPER FUNCTIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

size_t heapEndAddress (void) ;

size_t heapStartAddress (void) ;

size_t freeRAMByteCount (void) ;

size_t usedRAMByteCount (void) ;

uint32_t currentlyAllocatedObjectCount (void) ;

uint32_t allocationCount (void) ;

uint32_t freeObjectCountForListIndex (const uint32_t inFreeListIndex) ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   BLOCK SIZES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const size_t kMaxSizePowerOfTwo = 16 ; // Biggest block being allocated = 2 ** kMaxSizePowerOfTwo
static const size_t kMinSizePowerOfTwo =  4 ; // Smallest block being allocated = 2 ** kMinSizePowerOfTwo (SHOULD BE >= 3)
static const size_t kSegregatedAllocationListCount = kMaxSizePowerOfTwo - kMinSizePowerOfTwo + 1 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
