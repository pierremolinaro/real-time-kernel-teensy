#include "all-headers.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————
//  BLOCK HEADER
//——————————————————————————————————————————————————————————————————————————————————————————————————
// The block header size should be a multiple of 8 bytes,
// ensuring all allocated blocks are aligned on a 8-byte boundary

typedef struct HeaderType {
    HeaderType * mNextFreeBlock ; // Used only when block is free
    uint16_t mFreeListIndex ;
    uint16_t mAllocatedByteSize ;
} HeaderType ;

//——————————————————————————————————————————————————————————————————————————————————————————————————
//   HEAP START and END (theses symbols are defined by linker script)
//——————————————————————————————————————————————————————————————————————————————————————————————————

extern uint32_t __heap_start ;
extern uint32_t __heap_end ;

//——————————————————————————————————————————————————————————————————————————————————————————————————
//  HELPER FUNCTIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————

static size_t gFirstFreeAddress = size_t (& __heap_start) ;

//——————————————————————————————————————————————————————————————————————————————————————————————————

size_t heapEndAddress (void) {
  return size_t (& __heap_end) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————

size_t heapStartAddress (void) {
  return size_t (& __heap_start) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————

size_t freeRAMByteCount (void) {
  return size_t (& __heap_end) - gFirstFreeAddress ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————

size_t usedRAMByteCount (void) {
  return gFirstFreeAddress - size_t (& __heap_start) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————
//   ALLOCATED OBJECT COUNT
//——————————————————————————————————————————————————————————————————————————————————————————————————

static uint32_t gCurrentlyAllocatedCount ;
static uint32_t gAllocationCount ;
static uint32_t gAllocationCountArray [kSegregatedAllocationListCount] ;

//——————————————————————————————————————————————————————————————————————————————————————————————————

uint32_t currentlyAllocatedObjectCount (void) {
  return gCurrentlyAllocatedCount ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————

uint32_t allocationCount (void) {
  return gAllocationCount ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————

uint32_t allocationCountForListIndex (const uint32_t inIndex) {
  return gAllocationCountArray [inIndex] ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————
//   FREE OBJECT LISTS
//——————————————————————————————————————————————————————————————————————————————————————————————————

typedef struct {
  HeaderType * mFreeBlockList ;
  uint32_t mFreeBlockCount ;
} tFreeBlockListDescriptor ;

//——————————————————————————————————————————————————————————————————————————————————————————————————

static tFreeBlockListDescriptor gFreeBlockDescriptorArray [kSegregatedAllocationListCount] ;

//——————————————————————————————————————————————————————————————————————————————————————————————————

uint32_t freeObjectCountForListIndex (const uint32_t inFreeListIndex) {
  return (inFreeListIndex < kSegregatedAllocationListCount)
    ? gFreeBlockDescriptorArray [inFreeListIndex].mFreeBlockCount
    : 0
  ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————
//   MEMORY ALLOC
//——————————————————————————————————————————————————————————————————————————————————————————————————

void * section_fatPointerAlloc (SECTION_MODE_ const size_t inBlockSize) {
  HeaderType * result = nullptr ;
  if (inBlockSize > 0) {
  //--- Compute smallest block with size equal to a power of two bigger of equal to required size
    uint32_t smallestPowerOfTwo = 32 - uint32_t (__builtin_clz (inBlockSize)) ;
  //--- Allocate if not too large
    if (smallestPowerOfTwo <= kMaxSizePowerOfTwo) {
      if (smallestPowerOfTwo < kMinSizePowerOfTwo) {
        smallestPowerOfTwo = kMinSizePowerOfTwo ;
      }
      const uint32_t freeListIndex = smallestPowerOfTwo - kMinSizePowerOfTwo ;
      tFreeBlockListDescriptor & descriptorPtr = gFreeBlockDescriptorArray [freeListIndex] ;
      if (descriptorPtr.mFreeBlockCount > 0) { // Allocate from free list
        descriptorPtr.mFreeBlockCount -- ;
        result = descriptorPtr.mFreeBlockList ;
        descriptorPtr.mFreeBlockList = result->mNextFreeBlock ;
        result->mAllocatedByteSize = uint32_t (1) << smallestPowerOfTwo ;
        result ++ ;
        gCurrentlyAllocatedCount += 1 ;
        gAllocationCount += 1 ;
      }else{ // Allocate from heap
        result = (HeaderType *) gFirstFreeAddress ;
        gFirstFreeAddress += (uint32_t (1) << smallestPowerOfTwo) + sizeof (HeaderType) ;
        if (gFirstFreeAddress >= size_t (& __heap_end)) {
          gFirstFreeAddress = size_t (& __heap_end) ;
          result = nullptr ;
        }else{
          result->mFreeListIndex = freeListIndex ;
          result->mAllocatedByteSize = uint32_t (1) << smallestPowerOfTwo ;
          result ++ ;
          gAllocationCountArray [freeListIndex] += 1 ;
          gCurrentlyAllocatedCount += 1 ;
          gAllocationCount += 1 ;
        }
      }
    }
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————
//   MEMORY FREE
//——————————————————————————————————————————————————————————————————————————————————————————————————

void section_fatPointerFree (SECTION_MODE_ void * inPointer) {
  if (nullptr != inPointer) {
    HeaderType * p = (HeaderType *) inPointer ;
    p -- ;
    const uint32_t idx = p->mFreeListIndex ;
  //---
    p->mNextFreeBlock = gFreeBlockDescriptorArray [idx].mFreeBlockList ;
    gFreeBlockDescriptorArray [idx].mFreeBlockList = p ;
    gFreeBlockDescriptorArray [idx].mFreeBlockCount ++ ;
    gCurrentlyAllocatedCount -= 1 ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————
//   BLOCK SIZE
//——————————————————————————————————————————————————————————————————————————————————————————————————

uint32_t fatPointerSize (const void * inPointer) {
  uint32_t byteSize = 0 ;
  if (nullptr != inPointer) {
    const HeaderType * p = (const HeaderType *) inPointer ;
    p -- ;
    const uint32_t idx = p->mFreeListIndex ;
    byteSize = uint32_t (1) << (kMinSizePowerOfTwo + idx) ;
  }
  return byteSize ;
}
//——————————————————————————————————————————————————————————————————————————————————————————————————
//   C++ new
//——————————————————————————————————————————————————————————————————————————————————————————————————

void * operator new (size_t inSize) {
  return fatPointerAlloc (inSize) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————
//   C++ new []
//——————————————————————————————————————————————————————————————————————————————————————————————————

void * operator new [] (size_t inSize) {
  return fatPointerAlloc (inSize) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————
//   C++ delete
//——————————————————————————————————————————————————————————————————————————————————————————————————

void operator delete (void * ptr) ;

void operator delete (void * ptr) {
  fatPointerFree (ptr) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————
//   C++ delete []
//——————————————————————————————————————————————————————————————————————————————————————————————————

void operator delete [] (void * ptr) ;

void operator delete [] (void * ptr) {
  fatPointerFree (ptr) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————
//   C++ delete (required by -std=c++17)
//——————————————————————————————————————————————————————————————————————————————————————————————————

void operator delete (void * ptr, unsigned int) ;

void operator delete (void * ptr, unsigned int) {
  fatPointerFree (ptr) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————
//   C++ delete [] (required by -std=c++17)
//——————————————————————————————————————————————————————————————————————————————————————————————————

void operator delete [] (void * ptr, unsigned int) ;

void operator delete [] (void * ptr, unsigned int) {
  fatPointerFree (ptr) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————
