//-----------------------------------------------------------------------------
//
//   Stored Event
//
//-----------------------------------------------------------------------------

#include "all-headers.h"

//-----------------------------------------------------------------------------

Evt::Evt (void) :
mWaitingTaskList (),
mState (false) {
}

//-----------------------------------------------------------------------------

void Evt::sys_attendre (KERNEL_MODE) {
  if (mState) {
    mState = false ;
  }else{
    kernel_blockRunningTaskInList (MODE_ mWaitingTaskList) ;
  }
}

//-----------------------------------------------------------------------------

void Evt::sys_signaler (IRQ_MODE) {
  const bool found = irq_makeTaskReadyFromList (MODE_ mWaitingTaskList) ;
  if (! found) {
    mState = true ;
  }else{
    while (irq_makeTaskReadyFromList (MODE_ mWaitingTaskList)) {}
  }
}

//-----------------------------------------------------------------------------
