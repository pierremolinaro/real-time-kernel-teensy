//-----------------------------------------------------------------------------
//
//   Stored Event
//
//-----------------------------------------------------------------------------

#include "all-headers.h"

//-----------------------------------------------------------------------------

Event::Event (void) :
mWaitingTaskList (),
mState (false) {
}

//-----------------------------------------------------------------------------

void Event::sys_wait (KERNEL_MODE) {
  if (mState) {
    mState = false ;
  }else{
    kernel_blockRunningTaskInList (MODE_ mWaitingTaskList) ;
  }
}

//-----------------------------------------------------------------------------

void Event::sys_signal (IRQ_MODE) {
  const bool found = irq_makeTaskReadyFromList (MODE_ mWaitingTaskList) ;
  if (! found) {
    mState = true ;
  }else{
    while (irq_makeTaskReadyFromList (MODE_ mWaitingTaskList)) {}
  }
}

//-----------------------------------------------------------------------------
