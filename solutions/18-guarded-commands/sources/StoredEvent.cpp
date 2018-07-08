//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//
//   Stored Event
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "all-headers.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

StoredEvent::StoredEvent (const bool inInitialState) :
mWaitingTaskList (),
mState (inInitialState) {
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void StoredEvent::sys_wait (KERNEL_MODE) {
  if (mState) {
    mState = false ;
  }else{
    kernel_blockRunningTaskInList (MODE_ mWaitingTaskList) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void StoredEvent::sys_signal (IRQ_MODE) {
  const bool found = irq_makeTaskReadyFromList (MODE_ mWaitingTaskList) ;
  if (! found) {
    mState = true ;
  }else{
    while (irq_makeTaskReadyFromList (MODE_ mWaitingTaskList)) {}
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
