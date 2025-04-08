  .syntax unified
  .cpu cortex-m4
  .thumb

@-----------------------------------------------------------------------------------------
@   RESET HANDLER (DOUBLE STACK MODE)
@-----------------------------------------------------------------------------------------

@--- This is stack for background task
   BACKGROUND.STACK.SIZE = 512

  .section  .bss.background.task.stack, "aw", %nobits
  .align    3   @ Stack should be aligned on a 8-byte boundary

background.task.stack:
  .space  BACKGROUND.STACK.SIZE

@-----------------------------------------------------------------------------------------
@ See https://developer.arm.com/docs/dui0553/latest/2-the-cortex-m4-processor/21-programmers-model/213-core-registers

  .section  ".text.reset.handler", "ax", %progbits

  .global reset.handler
  .type reset.handler, %function

reset.handler: @ Cortex M4 boots with interrupts enabled, in Thread mode
@---------------------------------- Run boot, zero bss section, copy data section
  bl    start.phase1
@---------------------------------- Set PSP: this is stack for background task
  ldr   r0,  =background.task.stack + BACKGROUND.STACK.SIZE
  msr   psp, r0
@---------------------------------- Set CONTROL register (see §B1.4.4)
@ bit 0 : 0 -> Thread mode has privileged access, 1 -> Thread mode has unprivileged access
@ bit 1 : 0 -> Use SP_main as the current stack, 1 -> In Thread mode, use SP_process as the current stack
@ bit 2 : 0 -> FP extension not active, 1 -> FP extension is active
  movs  r2, #2
  msr   CONTROL, r2
@--- Software must use an ISB barrier instruction to ensure a write to the CONTROL register
@ takes effect before the next instruction is executed.
  isb
@---------------------------------- Run init routines, interrupt disabled
  cpsid i              @ Disable interrupts
  bl    start.phase2
  cpsie i              @ Enable interrupts
@---------------------------------- Run setup, loop
  bl    setup.function
background.task:
  bl    loop.function
  b     background.task

@-----------------------------------------------------------------------------------------
