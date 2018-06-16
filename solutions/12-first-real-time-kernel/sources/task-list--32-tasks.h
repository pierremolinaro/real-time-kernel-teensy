#pragma once

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "software-modes.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

struct TaskControlBlock ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//  TASK LIST                                                                                                          *
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class TaskList {
//--- Default constructor
  public: inline TaskList (void) : mList (0) {}

//--- Block a task in list
  public: void enterTask (SECTION_MODE_ TaskControlBlock * inTaskPtr) ;

//--- Remove first task (returns nullptr if list is empty)
  public: TaskControlBlock * removeFirstTask (IRQ_MODE) ;

//--- Private property
  private: uint32_t mList ;

//--- No copy
  private: TaskList (const TaskList &) ;
  private: TaskList & operator = (const TaskList &) ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
