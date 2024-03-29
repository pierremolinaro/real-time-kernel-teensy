//-----------------------------------------------------------------------------
//
//   Gate
//
//-----------------------------------------------------------------------------

#include "all-headers.h"

//-----------------------------------------------------------------------------

Gate::Gate (const bool inIsOpen) :
mWaitingTaskList (),
mIsOpen (inIsOpen) {
}

//-----------------------------------------------------------------------------

void Gate::sys_wait (KERNEL_MODE) {
  if (!mIsOpen) {
    kernel_blockRunningTaskInList (MODE_ mWaitingTaskList) ;
  }
}

//-----------------------------------------------------------------------------

void Gate::sys_open (IRQ_MODE) {
  if (!mIsOpen) {
    mIsOpen = true ;
    while (irq_makeTaskReadyFromList (MODE_ mWaitingTaskList)) {}
  }
}

//-----------------------------------------------------------------------------

void Gate::sys_close (IRQ_MODE) {
  mIsOpen = false ;
}

//-----------------------------------------------------------------------------
