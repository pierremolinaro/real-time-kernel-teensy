//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//
//   Stored Event
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#pragma once

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "task-list--32-tasks.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class StoredEvent {
//--- Properties
  protected: TaskList mWaitingTaskList ;
  protected: bool mState ;

//--- Constructor
  public: StoredEvent (const bool inInitialState) ;

//--- wait
//$service stored.event.wait
  public: void wait (USER_MODE) asm ("stored.event.wait")  ;
  public: void sys_wait (KERNEL_MODE) asm ("service.stored.event.wait") ;

//--- signal
//$service stored.event.signal
  public: void signal (USER_MODE) asm ("stored.event.signal") ;
  public: void sys_signal (IRQ_MODE) asm ("service.stored.event.signal") ;

//--- No copy
  private: StoredEvent (const StoredEvent &) ;
  private: StoredEvent & operator = (const StoredEvent &) ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
