//-----------------------------------------------------------------------------
//
//   Semaphore2
//
//-----------------------------------------------------------------------------

#include "all-headers.h"

static Event gOverflowEvent ;

//-----------------------------------------------------------------------------
//
//   C O N S T R U C T O R
//
//-----------------------------------------------------------------------------

Semaphore2::Semaphore2 (const uint32_t inMaxValue) :
mWaitingTaskList (),
mValue (0),
mMaxValue (inMaxValue) {
}

//-----------------------------------------------------------------------------
//
//   P    O P E R A T I O N
//
//-----------------------------------------------------------------------------

void Semaphore2::sys_P (KERNEL_MODE) {
  if (mValue == 0) {
    kernel_blockRunningTaskInList (MODE_ mWaitingTaskList) ;
  }else{
    mValue -= 1 ;
  }
}

//-----------------------------------------------------------------------------
//
//   V    O P E R A T I O N
//
//-----------------------------------------------------------------------------

void Semaphore2::sys_V (IRQ_MODE) {
  const bool found = irq_makeTaskReadyFromList (MODE_ mWaitingTaskList) ;
  if (! found) {
    if (mValue < mMaxValue) {
      mValue += 1 ;
    }else{
      gOverflowEvent.sys_signal (MODE) ;
    }
  }
}

//-----------------------------------------------------------------------------
