//-----------------------------------------------------------------------------
//
//   Stored Event
//
//-----------------------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------------------

#include "task-list--32-tasks.h"

//-----------------------------------------------------------------------------

class Evt {
//--- Properties
  protected: TaskList mWaitingTaskList ;
  protected: bool mState ;

//--- Constructor
  public: Evt (void) ;

//--- wait
//$service stored.event.wait
  public: void attendre (USER_MODE) asm ("stored.event.wait")  ;
  public: void sys_attendre (KERNEL_MODE) asm ("service.stored.event.wait") ;

//--- signal
//$service stored.event.signal
  public: void signaler (USER_MODE) asm ("stored.event.signal") ;
  public: void sys_signaler (IRQ_MODE) asm ("service.stored.event.signal") ;

//--- No copy
  private: Evt (const Evt &) = delete ;
  private: Evt & operator = (const Evt &) = delete ;
} ;

//-----------------------------------------------------------------------------
