#include "all-headers.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//  BLOCK HEADER
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// The block header size should be a multiple of 8 bytes, ensuring all allocated blocks are aligned on a 8-byte boundary

typedef struct HeaderType {
    uint32_t mFreeListIndex ;
    HeaderType * mNextFreeBlock ;
} HeaderType ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   HEAP START and END (theses symbols are defined by linker script)
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern uint32_t __heap_start ;
extern uint32_t __heap_end ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//  HELPER FUNCTIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static size_t gFirstFreeAddress = (size_t) & __heap_start ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

size_t heapEndAddress (void) {
  return (size_t) & __heap_end ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

size_t heapStartAddress (void) {
  return (size_t) & __heap_start ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

size_t freeRAMByteCount (void) {
  return ((size_t) & __heap_end) - gFirstFreeAddress ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

size_t usedRAMByteCount (void) {
  return gFirstFreeAddress - ((size_t) & __heap_start) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   ALLOCATED OBJECT COUNT
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static uint32_t gCurrentlyAllocatedCount ;
static uint32_t gAllocationCount ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

uint32_t currentlyAllocatedObjectCount (void) {
  return gCurrentlyAllocatedCount ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

uint32_t allocationCount (void) {
  return gAllocationCount ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   FREE OBJECT LISTS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

typedef struct {
  HeaderType * mFreeBlockList ;
  uint32_t mFreeBlockCount ;
} tFreeBlockListDescriptor ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static tFreeBlockListDescriptor gFreeBlockDescriptorArray [kSegregatedAllocationListCount] ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

uint32_t freeObjectCountForListIndex (const uint32_t inFreeListIndex) {
  return (inFreeListIndex < kSegregatedAllocationListCount)
    ? gFreeBlockDescriptorArray [inFreeListIndex].mFreeBlockCount
    : 0
  ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   MEMORY ALLOC
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void * section_memoryAlloc (SECTION_MODE_ const size_t inBlockSize) {
  HeaderType * result = nullptr ;
  if (inBlockSize > 0) {
  //--- Compute smallest block with size equal to a power of two bigger of equal to required size
    size_t smallestPowerOfTwo = 32 - (size_t) __builtin_clz (inBlockSize) ;
//     size_t v = inBlockSize - 1 ;
//     size_t smallestPowerOfTwo = 0 ;
//     while (v > 0) {
//       smallestPowerOfTwo ++ ;
//       v >>= 1 ;
//     }
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
        result ++ ;
        gCurrentlyAllocatedCount ++ ;
        gAllocationCount ++ ;
      }else{ // Allocate from heap
        result = (HeaderType *) gFirstFreeAddress ;
        const size_t size = (1U << smallestPowerOfTwo) + sizeof (HeaderType) ;
        gFirstFreeAddress += size ;
        if (gFirstFreeAddress >= (size_t) & __heap_end) { // Not enough space
          gFirstFreeAddress -= size ;
          result = nullptr ;
        }else{
          result->mFreeListIndex = freeListIndex ;
          result ++ ;
          gCurrentlyAllocatedCount ++ ;
          gAllocationCount ++ ;
        }
      }
    }
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   MEMORY FREE
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void section_memoryFree (SECTION_MODE_ void * inPointer) {
  if (nullptr != inPointer) {
    HeaderType * p = (HeaderType *) inPointer ;
    p -- ;
    const uint32_t idx = p->mFreeListIndex ;
    p->mNextFreeBlock = gFreeBlockDescriptorArray [idx].mFreeBlockList ;
    gFreeBlockDescriptorArray [idx].mFreeBlockList = p ;
    gFreeBlockDescriptorArray [idx].mFreeBlockCount ++ ;
    gCurrentlyAllocatedCount -- ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   BLOCK SIZE
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

uint32_t memoryByteSize (void * inPointer) {
  uint32_t byteSize = 0 ;
  if (nullptr != inPointer) {
    const HeaderType * p = (const HeaderType *) inPointer ;
    p -- ;
    const uint32_t idx = p->mFreeListIndex ;
    byteSize = ((size_t) 1) << (kMinSizePowerOfTwo + idx) ;
  }
  return byteSize ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   C++ new
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void * operator new (size_t inSize) {
  return memoryAlloc (inSize) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   C++ new []
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void * operator new [] (size_t inSize) {
  return memoryAlloc (inSize) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   C++ delete
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void operator delete (void * ptr) {
  memoryFree (ptr) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   C++ delete []
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void operator delete [] (void * ptr) {
  memoryFree (ptr) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   C++ delete (required by -std=c++17)
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void operator delete (void * ptr, unsigned int) {
  memoryFree (ptr) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   C++ delete [] (required by -std=c++17)
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void operator delete [] (void * ptr, unsigned int) {
  memoryFree (ptr) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   __dso_handle
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void * __dso_handle ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   __cxa_exit
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void __cxa_exit (void) ;

void __cxa_exit (void) {
  assertionFailure (0, __FILE__, __LINE__) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   __cxa_pure_virtual
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void __cxa_pure_virtual (void) ;

void __cxa_pure_virtual (void) {
  assertionFailure (0, __FILE__, __LINE__) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
