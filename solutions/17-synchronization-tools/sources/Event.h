//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//
//   Event
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#pragma once

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "task-list--32-tasks.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class Event {
//--- Properties
  protected: TaskList mWaitingTaskList ;
  protected: bool mState ;

//--- Constructor
  public: Event (const bool inInitialState) ;

//--- wait
//$service event.wait
  public: void wait (USER_MODE) asm ("event.wait")  ;
  public: void sys_wait (KERNEL_MODE) asm ("service.event.wait") ;

//--- signal
//$service event.signal
  public: void signal (USER_MODE) asm ("event.signal") ;
  private: void sys_signal (IRQ_MODE) asm ("service.event.signal") ;

//--- No copy
  private: Event (const Event &) ;
  private: Event & operator = (const Event &) ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
