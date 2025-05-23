#pragma once

//-----------------------------------------------------------------------------

#include "software-modes.h"

//-----------------------------------------------------------------------------
//   Task routine type                                                                                                 *
//-----------------------------------------------------------------------------

typedef void (* RoutineTaskType) (USER_MODE) ;

//-----------------------------------------------------------------------------
//   kernel_createTask                                                                                                *
//-----------------------------------------------------------------------------

void kernel_createTask (INIT_MODE_
                        uint64_t * inStackBufferAddress,
                        uint32_t inStackBufferSize,
                        RoutineTaskType inTaskRoutine) ;

//-----------------------------------------------------------------------------

struct TaskControlBlock ;

TaskControlBlock * descriptorPointerForTaskIndex (const uint8_t inTaskIndex) ;

uint8_t indexForDescriptorTask (const TaskControlBlock * inTaskPtr) ; // should be not nullptr

//-----------------------------------------------------------------------------
//  TASK SELF TERMINATES
//-----------------------------------------------------------------------------

//$service task.self.terminates

void taskSelfTerminates (USER_MODE) asm ("task.self.terminates") ;

void service_taskSelfTerminates (KERNEL_MODE) asm ("service.task.self.terminates") ;

//-----------------------------------------------------------------------------
