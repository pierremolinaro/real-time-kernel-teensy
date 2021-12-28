//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//
//   BoundedBuffer
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "all-headers.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

template <uint32_t SIZE, typename TYPE> BoundedBuffer <SIZE, TYPE>::BoundedBuffer (void) :
mInput (SIZE),
mOutput (0),
mCriticalSection (1),
mWriteIndex (0),
mReadIndex (0),
mCount (0),
mBuffer () {
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

template <uint32_t SIZE, typename TYPE> void BoundedBuffer <SIZE, TYPE>::append (USER_MODE_ const TYPE inData) {
  mInput.P (MODE) ;
  mCriticalSection.P (MODE) ;
    mBuffer [mWriteIndex] = inData ;
    mWriteIndex = (mWriteIndex + 1) % SIZE ;
    mCount += 1 ;
  mCriticalSection.V (MODE) ;
  mOutput.V (MODE) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

template <uint32_t SIZE, typename TYPE> TYPE BoundedBuffer <SIZE, TYPE>::remove (USER_MODE) {
  mOutput.P (MODE) ;
  mCriticalSection.P (MODE) ;
    const TYPE data = mBuffer [mReadIndex] ;
    mReadIndex = (mReadIndex + 1) % SIZE ;
    mCount -= 1 ;
  mCriticalSection.V (MODE) ;
  mInput.V (MODE) ;
  return data ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
