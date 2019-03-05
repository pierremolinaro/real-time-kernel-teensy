//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//
//   Gate
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#pragma once

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "task-list--32-tasks.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class Gate {
//--- Properties
  protected: TaskList mWaitingTaskList ;
  protected: bool mIsOpen ;

//--- Constructor
  public: Gate (const bool inIsOpen) ;

//--- wait
//$service gate.wait
  public: void wait (USER_MODE) asm ("gate.wait")  ;
  public: void sys_wait (KERNEL_MODE) asm ("service.gate.wait") ;

//--- open
//$service gate.open
  public: void open (USER_MODE) asm ("gate.open") ;
  public: void sys_open (IRQ_MODE) asm ("service.gate.open") ;

//--- close
//$service gate.close
  public: void close (USER_MODE) asm ("gate.close") ;
  public: void sys_close (IRQ_MODE) asm ("service.gate.close") ;

//--- No copy
  private: Gate (const Gate &) = delete ;
  private: Gate & operator = (const Gate &) = delete ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
