//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//
//   SilberchatzPort
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#pragma once

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "task-list--32-tasks.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class SilberchatzPort {
//--- Properties
  protected: TaskList mInputWaitingTaskList ;
  protected: TaskList mOutputWaitingTaskList ;

//--- Constructor
  public: SilberchatzPort (void) ;

//--- Input
//$service silberschatz.port.input
  public: void input (USER_MODE) asm ("silberschatz.port.input")  ;
  public: void sys_input (KERNEL_MODE) asm ("service.silberschatz.port.input") ;

//--- Output
//$service silberschatz.port.output
  public: void output (USER_MODE) asm ("silberschatz.port.output") ;
  public: void sys_output (KERNEL_MODE) asm ("service.silberschatz.port.output") ;

//--- No copy
  private: SilberchatzPort (const SilberchatzPort &) = delete ;
  private: SilberchatzPort & operator = (const SilberchatzPort &) = delete ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
