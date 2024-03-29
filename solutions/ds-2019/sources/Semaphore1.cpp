//-----------------------------------------------------------------------------
//
//   Semaphore1
//
//-----------------------------------------------------------------------------

#include "all-headers.h"

//-----------------------------------------------------------------------------
//
//   C O N S T R U C T O R
//
//-----------------------------------------------------------------------------

Semaphore1::Semaphore1 (const uint32_t inMaxValue) :
mWaitingTaskList (),
mValue (0),
mMaxValue (inMaxValue) {
}

//-----------------------------------------------------------------------------
//
//   P    O P E R A T I O N
//
//-----------------------------------------------------------------------------

void Semaphore1::sys_P (KERNEL_MODE) {
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

bool Semaphore1::sys_V (IRQ_MODE) {
  bool result = true ;
  const bool found = irq_makeTaskReadyFromList (MODE_ mWaitingTaskList) ;
  if (! found) {
    if (mValue < mMaxValue) {
      mValue += 1 ;
    }else{
      result = false ;
    }
  }
  return result ;
}

//-----------------------------------------------------------------------------
