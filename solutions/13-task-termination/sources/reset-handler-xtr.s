  .syntax unified
  .cpu cortex-m4
  .thumb

@----------------------------------------------------------------------------------------------------------------------*
@                                                                                                                      *
@                 R E S E T    H A N D L E R    ( D O U B L E    S T A C K    M O D E )    F O R    X T R              *
@                                                                                                                      *
@----------------------------------------------------------------------------------------------------------------------*

@--- This is stack for background task
   BACKGROUND.STACK.SIZE = 32

  .section  .bss.background.task.stack, "aw", %nobits
  .align    3   @ Stack should be aligned on a 8-byte boundary

background.task.stack:
  .space  BACKGROUND.STACK.SIZE

@----------------------------------------------------------------------------------------------------------------------*
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
@---------------------------------- Init
  svc   #0
@---------------------------------- This is the background task: turn off activity led
@  Activity led is connected to PORTC:5 (#13)
background.task: @ Only use R0, R1, R2, R3 and R12. Other registers are not preserved
  ldr   r0, =0x400FF088  @ Address of GPIOC_PCOR control register
  movs  r1, # (1 << 5)   @ Port D13 is PORTC:5
  str   r1, [r0]         @ Turn off
  b     background.task

@----------------------------------------------------------------------------------------------------------------------*
