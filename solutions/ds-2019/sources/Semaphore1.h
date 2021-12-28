//-----------------------------------------------------------------------------
//
//   Semaphore1
//
//-----------------------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------------------

#include "task-list--32-tasks.h"

//-----------------------------------------------------------------------------

class Semaphore1 {
//--- Properties
  protected: TaskList mWaitingTaskList ;
  protected: uint32_t mValue ;
  protected: const uint32_t mMaxValue ;

//--- Constructor
  public: Semaphore1 (const uint32_t inMaxValue) ;

//--- V
//$service semaphore1.V
  public: bool V (USER_MODE) asm ("semaphore1.V")  ;
  public: bool sys_V (IRQ_MODE) asm ("service.semaphore1.V") ;

//--- P
//$service semaphore1.P
  public: void P (USER_MODE) asm ("semaphore1.P") ;
  public: void sys_P (KERNEL_MODE) asm ("service.semaphore1.P") ;

//--- No copy
  private: Semaphore1 (const Semaphore1 &) = delete ;
  private: Semaphore1 & operator = (const Semaphore1 &) = delete ;
} ;

//-----------------------------------------------------------------------------
