//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//
//   SilberchatzPort
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "all-headers.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

SilberchatzPort::SilberchatzPort (void) :
mInputWaitingTaskList (),
mOutputWaitingTaskList () {
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SilberchatzPort::sys_input (KERNEL_MODE) {
  if (!irq_makeTaskReadyFromList (MODE_ mOutputWaitingTaskList)) {
    kernel_blockRunningTaskInList (MODE_ mInputWaitingTaskList) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SilberchatzPort::sys_output (KERNEL_MODE) {
  if (!irq_makeTaskReadyFromList (MODE_ mInputWaitingTaskList)) {
    kernel_blockRunningTaskInList (MODE_ mOutputWaitingTaskList) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
