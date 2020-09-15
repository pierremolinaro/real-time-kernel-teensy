//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//
//   Semaphore2
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#pragma once

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "task-list--32-tasks.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class Semaphore2 {
//--- Properties
  protected: TaskList mWaitingTaskList ;
  protected: uint32_t mValue ;
  protected: const uint32_t mMaxValue ;

//--- Constructor
  public: Semaphore2 (const uint32_t inMaxValue) ;

//--- V
//$service Semaphore2.V
  public: void V (USER_MODE) asm ("Semaphore2.V")  ;
  public: void sys_V (IRQ_MODE) asm ("service.Semaphore2.V") ;

//--- P
//$service Semaphore2.P
  public: void P (USER_MODE) asm ("Semaphore2.P") ;
  public: void sys_P (KERNEL_MODE) asm ("service.Semaphore2.P") ;

//--- No copy
  private: Semaphore2 (const Semaphore2 &) = delete ;
  private: Semaphore2 & operator = (const Semaphore2 &) = delete ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
