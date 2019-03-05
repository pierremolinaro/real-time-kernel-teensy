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

//--- Constructor
  public: Event (void) ;

//--- wait
//$service event.wait
  public: void wait (USER_MODE) asm ("event.wait")  ;
  public: void sys_wait (KERNEL_MODE) asm ("service.event.wait") ;

//--- signal
//$service event.signal
  public: void signal (USER_MODE) asm ("event.signal") ;
  public: void sys_signal (IRQ_MODE) asm ("service.event.signal") ;

//--- No copy
  private: Event (const Event &) = delete ;
  private: Event & operator = (const Event &) = delete ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
