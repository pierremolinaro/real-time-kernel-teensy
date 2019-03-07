//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "all-headers.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

CANMessageBuffer::CANMessageBuffer (void) :
mMessageArray (nullptr),
mBufferSize (0),
mReadIndex (0),
mCount (0) {
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CANMessageBuffer::initWithSize (INIT_MODE_ const uint16_t inBufferSize) {
  mMessageArray = new CANMessage [inBufferSize] ;
  mBufferSize = inBufferSize ;
  mReadIndex = 0 ;
  mCount = 0 ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool CANMessageBuffer::append (SECTION_MODE_ const CANMessage & inMessage) {
  const bool ok = mCount < mBufferSize ;
  if (ok) {
    uint32_t writeIndex = (uint32_t) (mReadIndex + mCount) ;
    if (writeIndex >= mBufferSize) {
      writeIndex -= mBufferSize ;
    }
    mMessageArray [writeIndex] = inMessage ;
    mCount += 1 ;
  }
  return ok ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool CANMessageBuffer::section_remove (SECTION_MODE_ CANMessage & outMessage) {
  const bool ok = mCount > 0 ;
  if (ok) {
    outMessage = mMessageArray [mReadIndex] ;
    mCount -= 1 ;
    mReadIndex += 1 ;
    if (mReadIndex == mBufferSize) {
      mReadIndex = 0 ;
    }
  }
  return ok ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
