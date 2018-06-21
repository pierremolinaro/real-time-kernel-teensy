//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//
//   SilberchatzPortWithData
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "all-headers.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

SilberchatzPortWithData::SilberchatzPortWithData (void) :
mPort (),
mSemaphoreWrite (1),
mSemaphoreRead (0),
mData (0) {
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SilberchatzPortWithData::output (USER_MODE_ const uint32_t inData) {
  mPort.output (MODE) ;
//--- Transmit data
  mSemaphoreWrite.P (MODE) ;
  mData = inData ;
  mSemaphoreRead.V (MODE) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SilberchatzPortWithData::input (USER_MODE_ uint32_t & outData) {
  mPort.input (MODE) ;
//--- Get data
  mSemaphoreRead.P (MODE) ;
  outData = mData ;
  mSemaphoreWrite.V (MODE) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
