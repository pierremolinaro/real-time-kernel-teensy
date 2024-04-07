#include "all-headers.h"

//----------------------------------------------------------------------------------------

#define ENABLE_TASK_LIST_ASSERTIONS

//----------------------------------------------------------------------------------------

#ifdef ENABLE_TASK_LIST_ASSERTIONS
  #define TASK_LIST_ASSERT_NON_NULL_POINTER(ptr) assertNonNullPointer (ptr, __FILE__, __LINE__) ;
#else
  #define TASK_LIST_ASSERT_NON_NULL_POINTER(ptr)
#endif

//----------------------------------------------------------------------------------------

#ifdef ENABLE_TASK_LIST_ASSERTIONS
  #define TASK_LIST_ASSERT(condition,value) assertion (condition, value, __FILE__, __LINE__) ;
#else
  #define TASK_LIST_ASSERT(condition,value)
#endif

//----------------------------------------------------------------------------------------
// ENTER TASK IN LIST: inTask should be not null
//----------------------------------------------------------------------------------------

void TaskList::enterTask (SECTION_MODE_ TaskControlBlock * inTaskPtr) {
  TASK_LIST_ASSERT_NON_NULL_POINTER (inTaskPtr) ;
  const uint32_t taskIndex = indexForDescriptorTask (inTaskPtr) ;
  TASK_LIST_ASSERT (taskIndex < TASK_COUNT, taskIndex) ;
  const uint32_t mask = 1U << taskIndex ;
  mList |= mask ;
}

//----------------------------------------------------------------------------------------
//  REMOVE FIRST TASK FROM LIST: returns nullptr if list is empty
//----------------------------------------------------------------------------------------

TaskControlBlock * TaskList::removeFirstTask (IRQ_MODE) {
  TaskControlBlock * taskPtr = nullptr ;
  if (mList != 0) {
    const uint32_t taskIndex = (uint32_t) __builtin_ctz (mList) ;
    TASK_LIST_ASSERT (taskIndex < TASK_COUNT, taskIndex) ;
    const uint32_t mask = 1U << taskIndex ;
    mList &= ~ mask ;
    taskPtr = descriptorPointerForTaskIndex (taskIndex) ;
  }
  return taskPtr ;
}

//----------------------------------------------------------------------------------------
//  REMOVE A TASK FROM LIST
//----------------------------------------------------------------------------------------

void TaskList::removeTask (SECTION_MODE_ TaskControlBlock * inTaskPtr) {
  TASK_LIST_ASSERT_NON_NULL_POINTER (inTaskPtr) ;
  const uint32_t taskIndex = indexForDescriptorTask (inTaskPtr) ;
  TASK_LIST_ASSERT (taskIndex < TASK_COUNT, taskIndex) ;
  const uint32_t mask = 1U << taskIndex ;
  mList &= ~ mask ;
}

//----------------------------------------------------------------------------------------
//  REMOVE FIRST TASK FROM LIST: returns nullptr if list is empty
//----------------------------------------------------------------------------------------

TaskControlBlock * TaskList::Iterator::nextTask (IRQ_MODE) {
  TaskControlBlock * taskPtr = nullptr ;
  if (mIteratedList != 0) {
    const uint32_t taskIndex = (uint32_t) __builtin_ctz (mIteratedList) ;
    TASK_LIST_ASSERT (taskIndex < TASK_COUNT, taskIndex) ;
    const uint32_t mask = 1U << taskIndex ;
    mIteratedList &= ~ mask ;
    taskPtr = descriptorPointerForTaskIndex (taskIndex) ;
  }
  return taskPtr ;
}

//----------------------------------------------------------------------------------------
//  CONTAINS TASK
//----------------------------------------------------------------------------------------

bool TaskList::containsTask (SECTION_MODE_ TaskControlBlock * inTaskPtr) const {
  TASK_LIST_ASSERT_NON_NULL_POINTER (inTaskPtr) ;
  const uint32_t taskIndex = indexForDescriptorTask (inTaskPtr) ;
  TASK_LIST_ASSERT (taskIndex < TASK_COUNT, taskIndex) ;
  const uint32_t mask = 1U << taskIndex ;
  return (mList & mask) != 0 ;
}

//----------------------------------------------------------------------------------------
