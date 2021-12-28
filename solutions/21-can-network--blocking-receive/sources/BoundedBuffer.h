//-----------------------------------------------------------------------------
//
//   BoundedBuffer
//
//-----------------------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------------------

#include "Semaphore.h"

//-----------------------------------------------------------------------------

static const uint32_t BOUNDED_BUFFER_SIZE = 10 ;

//-----------------------------------------------------------------------------

class BoundedBuffer {
//--- Properties
  protected: Semaphore mInput ;
  protected: Semaphore mOutput ;
  protected: uint32_t mWriteIndex ;
  protected: uint32_t mReadIndex ;
  protected: uint32_t mCount ;
  protected: uint32_t mBuffer [BOUNDED_BUFFER_SIZE] ;

//--- Constructor
  public: BoundedBuffer (void) ;

//--- Append
  public: void append (USER_MODE_ const uint32_t inData) ;

//--- Append in guard
  public: bool guarded_append (USER_MODE_ const uint32_t inData) ;

//--- Remove
  public: uint32_t remove (USER_MODE) ;

//--- Remove in guard
  public: bool guarded_remove (USER_MODE_ uint32_t & outData) ;

//--- Append data in IRQ mode (return true if buffer was not full)
  public : bool irq_append (IRQ_MODE_ const uint32_t inData) ;

//$section bounded.buffer.append
  private: void internalAppend (USER_MODE_ const uint32_t inData) asm ("bounded.buffer.append") ;
  private: void section_internalAppend (SECTION_MODE_ const uint32_t inData) asm ("section.bounded.buffer.append") ;

//$section bounded.buffer.remove
  private: void internalRemove (USER_MODE_ uint32_t & outData) asm ("bounded.buffer.remove") ;
  private: void section_internalRemove (SECTION_MODE_ uint32_t & outData) asm ("section.bounded.buffer.remove") ;

//--- No copy
  private: BoundedBuffer (const BoundedBuffer &) = delete ;
  private: BoundedBuffer & operator = (const BoundedBuffer &) = delete ;
} ;

//-----------------------------------------------------------------------------
