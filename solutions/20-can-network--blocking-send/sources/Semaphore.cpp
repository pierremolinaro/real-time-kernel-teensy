//-----------------------------------------------------------------------------
//
//   Semaphore
//
//-----------------------------------------------------------------------------

#include "all-headers.h"

//-----------------------------------------------------------------------------
//
//   C O N S T R U C T O R
//
//-----------------------------------------------------------------------------

Semaphore::Semaphore (const uint32_t inInitialValue) :
mWaitingTaskList (),
mGuardList (),
mValue (inInitialValue) {
}

//-----------------------------------------------------------------------------
//
//   P    O P E R A T I O N
//
//-----------------------------------------------------------------------------

void Semaphore::sys_P (KERNEL_MODE) {
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

void Semaphore::sys_V (IRQ_MODE) {
  const bool found = irq_makeTaskReadyFromList (MODE_ mWaitingTaskList) ;
  if (! found) {
    mValue += 1 ;
    guard_commandStatesDidChange (MODE_ mGuardList) ;
  }
}

//-----------------------------------------------------------------------------
//
//   P _ U N T I L     O P E R A T I O N
//
//-----------------------------------------------------------------------------

void Semaphore::sys_P_until (KERNEL_MODE_ const uint32_t inDeadline) {
  const bool userResult = mValue > 0 ;
  kernel_setUserResult (MODE_ userResult) ; // SOULD BE CALLED BEFORE TASK BLOCKING
  if (userResult) {
    mValue -= 1 ;
  }else if (inDeadline > millis (MODE)) {
    kernel_blockRunningTaskInListAndDeadline (MODE_ mWaitingTaskList, inDeadline) ;
  }
}

//-----------------------------------------------------------------------------
//
//   G U A R D E D _ P     O P E R A T I O N
//
//-----------------------------------------------------------------------------

bool Semaphore::sys_guarded_P (SECTION_MODE) {
  const bool accepted = mValue > 0 ;
  guard_handleCommand (MODE_ mGuardList, accepted) ;
  if (accepted) {
    mValue -- ;
  }
  return accepted ;
}

//-----------------------------------------------------------------------------
