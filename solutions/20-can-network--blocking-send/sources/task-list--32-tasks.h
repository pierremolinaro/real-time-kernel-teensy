#pragma once

//----------------------------------------------------------------------------------------

#include "software-modes.h"

//----------------------------------------------------------------------------------------

struct TaskControlBlock ;

//----------------------------------------------------------------------------------------
//  TASK LIST
//----------------------------------------------------------------------------------------

class TaskList {
//--- Default constructor
  public: inline TaskList (void) : mList (0) {}

//--- Block a task in list
  public: void enterTask (SECTION_MODE_ TaskControlBlock * inTaskPtr) ;

//--- Remove first task (returns nullptr if list is empty)
  public: TaskControlBlock * removeFirstTask (IRQ_MODE) ;

//--- Remove a task from list
  public: void removeTask (SECTION_MODE_ TaskControlBlock * inTaskPtr) ;

//--- Contains task
  public: bool containsTask (SECTION_MODE_ TaskControlBlock * inTaskPtr) const ;

//--- Private property
  private: uint32_t mList ;

//--- No copy
  private: TaskList (const TaskList &) = delete ;
  private: TaskList & operator = (const TaskList &) = delete ;

//-------------------------------------------- Iterator
  public: class Iterator {
    public: inline Iterator (IRQ_MODE_ const TaskList & inTaskList) :
    mIteratedList (inTaskList.mList) {
    }

    public: TaskControlBlock * nextTask (IRQ_MODE) ;

  //--- Private property
    private: uint32_t mIteratedList ;

  //--- No copy
    private: Iterator (const Iterator &) = delete ;
    private: Iterator & operator = (const Iterator &) = delete ;
  } ;
} ;

//----------------------------------------------------------------------------------------
