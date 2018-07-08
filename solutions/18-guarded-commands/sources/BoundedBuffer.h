//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//
//   BoundedBuffer
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#pragma once

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "Semaphore.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

template <uint32_t SIZE, typename TYPE> class BoundedBuffer {
//--- Properties
  protected: Semaphore mInput ;
  protected: Semaphore mOutput ;
  protected: Semaphore mCriticalSection ;
  protected: uint32_t mWriteIndex ;
  protected: uint32_t mReadIndex ;
  protected: uint32_t mCount ;
  protected: TYPE mBuffer [SIZE] ;

//--- Constructor
  public: BoundedBuffer (void) ;

//--- Append
  public: void append (USER_MODE_ const TYPE inData) ;

//--- Append in guard
  public: bool guarded_append (USER_MODE_ const TYPE inData) ;

//--- Remove
  public: TYPE remove (USER_MODE) ;

//--- Remove in guard
  public: bool guarded_remove (USER_MODE_ TYPE & outData) ;

//--- No copy
  private: BoundedBuffer (const BoundedBuffer <SIZE, TYPE> &) ;
  private: BoundedBuffer & operator = (const BoundedBuffer <SIZE, TYPE> &) ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
