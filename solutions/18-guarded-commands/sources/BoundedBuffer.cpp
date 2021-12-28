//-----------------------------------------------------------------------------
//
//   BoundedBuffer
//
//-----------------------------------------------------------------------------

#include "all-headers.h"

//-----------------------------------------------------------------------------

BoundedBuffer::BoundedBuffer (void) :
mInput (BOUNDED_BUFFER_SIZE),
mOutput (0),
mWriteIndex (0),
mReadIndex (0),
mCount (0),
mBuffer () {
}

//-----------------------------------------------------------------------------

void BoundedBuffer::append (USER_MODE_ const uint32_t inData) {
  mInput.P (MODE) ;
  internalAppend (MODE_ inData) ;
  mOutput.V (MODE) ;
}

//-----------------------------------------------------------------------------

void BoundedBuffer::section_internalAppend (SECTION_MODE_ const uint32_t inData) {
  mBuffer [mWriteIndex] = inData ;
  mWriteIndex = (mWriteIndex + 1) % BOUNDED_BUFFER_SIZE ;
  mCount += 1 ;
}

//-----------------------------------------------------------------------------

bool BoundedBuffer::guarded_append (USER_MODE_ const uint32_t inData) {
  const bool result = mInput.guarded_P (MODE) ;
  if (result) {
    internalAppend (MODE_ inData) ;
    mOutput.V (MODE) ;
  }
  return result ;
}

//-----------------------------------------------------------------------------

uint32_t BoundedBuffer::remove (USER_MODE) {
  mOutput.P (MODE) ;
  uint32_t data = 0 ;
  internalRemove (MODE_ data) ;
  mInput.V (MODE) ;
  return data ;
}

//-----------------------------------------------------------------------------

void BoundedBuffer::section_internalRemove (SECTION_MODE_ uint32_t & outData) {
  outData = mBuffer [mReadIndex] ;
  mReadIndex = (mReadIndex + 1) % BOUNDED_BUFFER_SIZE ;
  mCount -= 1 ;
}

//-----------------------------------------------------------------------------

bool BoundedBuffer::guarded_remove (USER_MODE_ uint32_t & outData) {
  const bool result = mOutput.guarded_P (MODE) ;
  if (result) {
    internalRemove (MODE_ outData) ;
    mInput.V (MODE) ;
  }
  return result ;
}

//-----------------------------------------------------------------------------

bool BoundedBuffer::irq_append (IRQ_MODE_ const uint32_t inData) {
  const bool ok = mCount < BOUNDED_BUFFER_SIZE ;
  if (ok) {
    mBuffer [mWriteIndex] = inData ;
    mWriteIndex = (mWriteIndex + 1) % BOUNDED_BUFFER_SIZE ;
    mCount += 1 ;
    mOutput.sys_V (MODE) ;
  }
  return ok ;
}

//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
