//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "all-headers.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

CANReceivePort::CANReceivePort (const uint32_t inIdentifier,
                                const tFrameFormat inFormat,
                                const uint16_t inBufferSize) :
mMessageBuffer (),
mSemaphore (0),
mIdentifier (inIdentifier),
mBufferSize (inBufferSize),
mFormat (inFormat),
mOverflow (false) {
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CANReceivePort::init (INIT_MODE) {
  mMessageBuffer.initWithSize (MODE_ mBufferSize) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CANReceivePort::append (IRQ_MODE_ const CANMessage & inMessage) {
  const bool ok = mMessageBuffer.append (MODE_ inMessage) ;
  if (ok) {
    mSemaphore.sys_V (MODE) ;
  }else{
    mOverflow = true ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool CANReceivePort::guarded_get (USER_MODE_ CANMessage & outMessage) {
  const bool ok = mSemaphore.guarded_P (MODE) ;
  if (ok) {
    mMessageBuffer.remove (MODE_ outMessage) ;
  }
  return ok ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CANReceivePort::get (USER_MODE_ CANMessage & outMessage) {
  mSemaphore.P (MODE) ;
  mMessageBuffer.remove (MODE_ outMessage) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
