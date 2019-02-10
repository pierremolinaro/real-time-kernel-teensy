//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//
//   Semaphore
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#pragma once

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "task-list--32-tasks.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class Semaphore {
//--- Properties
  protected: TaskList mWaitingTaskList ;
  protected: uint32_t mValue ;

//--- Constructor
  public: Semaphore (const uint32_t inInitialValue) ;

//--- V
//$service semaphore.V
  public: void V (USER_MODE) asm ("semaphore.V")  ;
  public: void sys_V (IRQ_MODE) asm ("service.semaphore.V") ;

//--- P
//$service semaphore.P
  public: void P (USER_MODE) asm ("semaphore.P") ;
  public: void sys_P (KERNEL_MODE) asm ("service.semaphore.P") ;

//--- P_until
//Bool-service semaphore.P_until
  public: bool P_until (USER_MODE_ const uint32_t inDeadline) asm ("semaphore.P_until") ;
  public: void sys_P_until (KERNEL_MODE_ const uint32_t inDeadline) asm ("service.semaphore.P_until") ;

//--- No copy
  private: Semaphore (const Semaphore &) = delete ;
  private: Semaphore & operator = (const Semaphore &) = delete ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
