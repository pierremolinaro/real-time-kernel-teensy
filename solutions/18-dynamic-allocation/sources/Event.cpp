//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//
//   Event
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "all-headers.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

Event::Event (const bool inInitialState) :
mWaitingTaskList (),
mState (inInitialState) {
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void Event::sys_wait (KERNEL_MODE) {
  if (mState) {
    mState = false ;
  }else{
    kernel_blockRunningTaskInList (MODE_ mWaitingTaskList) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void Event::sys_signal (IRQ_MODE) {
  const bool found = irq_makeTaskReadyFromBlockingList (MODE_ mWaitingTaskList) ;
  if (! found) {
    mState = false ;
  }else{
    while (irq_makeTaskReadyFromBlockingList (MODE_ mWaitingTaskList)) {}
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
