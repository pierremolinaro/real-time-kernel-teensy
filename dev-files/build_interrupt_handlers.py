#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
#———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

import sys, interrupt_names_teensy_3_6

#———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

def ENDC () :
  return '\033[0m'

#······················································································································*

def RED () :
  return '\033[91m'

#······················································································································*

def BOLD () :
  return '\033[1m'

#······················································································································*

def BOLD_RED () :
  return BOLD () + RED ()

#———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

def asSeparator () :
  return "@" + ("-" * 119) + "\n"

#———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

def cppSeparator () :
  return "//" + ("-" * 118) + "\n"

#———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

def generateSVChandler ():
  sFile = asSeparator ()
  sFile += "@                 S V C    H A N D L E R    ( D O U B L E    S T A C K    M O D E )\n"
  sFile += asSeparator ()
  sFile += "@\n"
  sFile += "@          PSP+32 -> |                            |\n"
  sFile += "@                    |----------------------------| \\\n"
  sFile += "@          PSP+28 -> | xPSR                       |  |\n"
  sFile += "@                    |----------------------------|  |\n"
  sFile += "@          PSP+24 -> | PC (after SVC instruction) |  |\n"
  sFile += "@                    |----------------------------|  |\n"
  sFile += "@          PSP+20 -> | LR                         |  |\n"
  sFile += "@                    |----------------------------|  |\n"
  sFile += "@          PSP+16 -> | R12                        |  |  Saved by interrupt response\n"
  sFile += "@                    |----------------------------|  |\n"
  sFile += "@          PSP+12 -> | R3                         |  |\n"
  sFile += "@                    |----------------------------|  |\n"
  sFile += "@          PSP+8  -> | R2                         |  |\n"
  sFile += "@                    |----------------------------|  |\n"
  sFile += "@          PSP+4  -> | R1                         |  |\n"
  sFile += "@                    |----------------------------|  |\n"
  sFile += "@     /--- PSP ----> | R0                         |  |\n"
  sFile += "@     |              |----------------------------| /\n"
  sFile += "@     |              |                            |\n"
  sFile += "@     |\n"
  sFile += "@     |                          ---------------------*\n"
  sFile += "@     |                                          | LR return code      | +36 [ 9]\n"
  sFile += "@     |                          ---------------------*\n"
  sFile += "@     \----------------------------------------- | R13 (PSP)           | +32 [ 8]\n"
  sFile += "@                                ---------------------*\n"
  sFile += "@                                                | R11                 | +28 [ 7]\n"
  sFile += "@                                ---------------------*\n"
  sFile += "@                                                | R10                 | +24 [ 6]\n"
  sFile += "@                                ---------------------*\n"
  sFile += "@                                                | R9                  | +20 [ 5]\n"
  sFile += "@                                ---------------------*\n"
  sFile += "@                                                | R8                  | +16 [ 4]\n"
  sFile += "@                                ---------------------*\n"
  sFile += "@                                                | R7                  | +12 [ 3]\n"
  sFile += "@                                ---------------------*\n"
  sFile += "@                                                | R6                  | + 8 [ 2]\n"
  sFile += "@                                ---------------------*\n"
  sFile += "@                                                | R5                  | + 4 [ 1]\n"
  sFile += "@  *------------------------------------*        *---------------------*\n"
  sFile += "@  | var.running.task.control.block.ptr +------> | R4                  | + 0 [ 0]\n"
  sFile += "@  *------------------------------------*        *---------------------*\n"
  sFile += "@\n"
  sFile += asSeparator () + "\n"
  sFile += "	.section	.bss.var.background.task.context, \"aw\", %nobits\n"
  sFile += "  .align	  2\n\n"
  sFile += "var.background.task.context:\n"
  sFile += "  .space  4\n\n"
  sFile += asSeparator () + "\n"
  sFile += "	.section	.text.interrupt.SVC, \"ax\", %progbits\n\n"
  sFile += "  .global interrupt.SVC\n"
  sFile += "  .type interrupt.SVC, %function\n\n"
  sFile += "interrupt.SVC:\n"
  sFile += "@----------------------------------------- Save preserved registers\n"
  sFile += "  push  {r4, lr}\n"
  sFile += "@----------------------------------------- R4 <- thread SP\n"
  sFile += "  mrs   r4, psp\n"
  sFile += "@----------------------------------------- Restore R0, R1, R2 and R3 from saved stack\n"
  sFile += "  ldmia r4!, {r0, r1, r2, r3}       @ R4 incremented by 16\n"
  sFile += "@----------------------------------------- R4 <- Address of SVC instruction\n"
  sFile += "  ldr   r4, [r4, #8]                @ 8 : 2 stacked registers before saved PC\n"
  sFile += "@----------------------------------------- R12 <- bits 0-7 of SVC instruction\n"
  sFile += "  ldrb  r12, [r4, #-2]              @ R12 is service call index\n"
  sFile += "@----------------------------------------- R4 <- address of dispatcher table\n"
  sFile += "  ldr   r4, =svc.dispatcher.table\n"
  sFile += "@----------------------------------------- R12 <- address of routine to call\n"
  sFile += "  ldr   r12, [r4, r12, lsl #2]      @ R12 = R4 + (R12 << 2)\n"
  sFile += "@----------------------------------------- R4 <- calling task context\n"
  sFile += "  ldr   r4, =var.running.task.control.block.ptr\n"
  sFile += "  ldr   r4, [r4]\n"
  sFile += "@----------------------------------------- Call service routine\n"
  sFile += "  blx   r12                         @ R4:calling task context address\n"
  sFile += "@--- Continues in sequence to handle.context.switch\n\n"
  sFile += asSeparator ()
  sFile += "@\n"
  sFile += "@                 H A N D L E    C O N T E X T    S W I T C H    ( D O U B L E    S T A C K    M O D E )\n"
  sFile += "@\n"
  sFile += "@  On entry:\n"
  sFile += "@    - R4 contains the runnning task save context address,\n"
  sFile += "@    - R4 and LR of running task have been pushed on handler stack.\n"
  sFile += "@\n"
  sFile += asSeparator () + "\n"
  sFile += "handle.context.switch:\n"
  sFile += "@----------------------------------------- Select task to run\n"
  sFile += "  bl    kernel.select.task.to.run\n"
  sFile += "@----------------------------------------- R0 <- calling task context, R1 <- new task context\n"
  sFile += "  ldr   r1, =var.running.task.control.block.ptr\n"
  sFile += "  mov   r0, r4\n"
  sFile += "  ldr   r1, [r1]\n"
  sFile += "@----------------------------------------- Restore preserved registers\n"
  sFile += "  pop   {r4, lr}\n"
  sFile += "@----------------------------------------- Running task did change ?\n"
  sFile += "  cmp   r0, r1  @ R0:calling task context, R1:new task context\n"
  sFile += "  bne   running.state.did.change\n"
  sFile += "  bx    lr  @ No change\n"
  sFile += "@----------------------------------------- Save context of preempted task\n"
  sFile += "running.state.did.change:\n"
  sFile += "  mrs   r12, psp\n"
  sFile += "  cbz   r0, save.background.task.context\n"
  sFile += "@--- Save registers r4 to r11, PSP (stored in R12), LR\n"
  sFile += "  stmia r0, {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}\n"
  sFile += "  b     perform.restore.context\n"
  sFile += "save.background.task.context:\n"
  sFile += "  ldr   r2, =var.background.task.context\n"
  sFile += "  str   r12, [r2]\n"
  sFile += "@----------------------------------------- Restore context of activated task\n"
  sFile += "perform.restore.context:\n"
  sFile += "  cbz   r1, restore.background.task.context\n"
  sFile += "  ldmia r1, {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}\n"
  sFile += "  msr   psp, r12\n"
  sFile += "  bx    lr\n"
  sFile += "@----------------------------------------- Restore background task context\n"
  sFile += "restore.background.task.context:\n"
  sFile += "  ldr   r2, =var.background.task.context\n"
  sFile += "  ldr   r2, [r2]\n"
  sFile += "  msr   psp, r2\n"
  sFile += "  bx    lr\n\n"
  return sFile

#———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

def generateBreakpointHandler () :
  sFile = asSeparator ()
  sFile += "@\n"
  sFile += "@                 B K P T    H A N D L E R    ( D O U B L E    S T A C K    M O D E )\n"
  sFile += "@\n"
  sFile += asSeparator ()
  sFile += "@\n"
  sFile += "@                    |                            |\n"
  sFile += "@          PSP+32 -> |----------------------------| \\\n"
  sFile += "@                    | xPSR                       |  |\n"
  sFile += "@          PSP+28 -> |----------------------------|  |\n"
  sFile += "@                    | PC (BKPT instruction)      |  |\n"
  sFile += "@          PSP+24 -> |----------------------------|  |\n"
  sFile += "@                    | LR                         |  |\n"
  sFile += "@          PSP+20 -> |----------------------------|  |\n"
  sFile += "@                    | R12                        |  |  Saved by interrupt response\n"
  sFile += "@          PSP+16 -> |----------------------------|  |\n"
  sFile += "@                    | R3                         |  |\n"
  sFile += "@          PSP+12 -> |----------------------------|  |\n"
  sFile += "@                    | R2                         |  |\n"
  sFile += "@          PSP+8  -> |----------------------------|  |\n"
  sFile += "@                    | R1                         |  |\n"
  sFile += "@          PSP+4  -> |----------------------------|  |\n"
  sFile += "@                    | R0                         |  |\n"
  sFile += "@          PSP    -> |----------------------------| /\n"
  sFile += "@\n"
  sFile += asSeparator () + "\n"
  sFile += "  .section  .text.interrupt.DebugMonitor, \"ax\", %progbits\n\n"
  sFile += "  .global interrupt.DebugMonitor\n"
  sFile += "  .type interrupt.DebugMonitor, %function\n\n"
  sFile += "interrupt.DebugMonitor:\n"
  sFile += "@--------------------- Save preserved registers\n"
  sFile += "  push  {r5, lr}\n"
  sFile += "@--------------------- R5 <- thread SP\n"
  sFile += "  mrs   r5, psp\n"
  sFile += "  ldmia r5, {r0, r1, r2, r3}\n"
  sFile += "@--------------------- LR <- Address of BKPT instruction\n"
  sFile += "  ldr   lr, [r5, #24]     @ 24 : 6 stacked registers before saved PC\n"
  sFile += "@--------------------- Set return address to instruction following BKPT\n"
  sFile += "@  adds  lr, #2\n"
  sFile += "@  str   lr, [r5, #24]\n"
  sFile += "@--------------------- R12 <- address of dispatcher\n"
  sFile += "  ldr   r12, =section.dispatcher.table\n"
  sFile += "@--------------------- LR <- bits 0-7 of BKPT instruction\n"
  sFile += "  ldrb  lr, [lr, #-2]            @ LR is service call index\n"
  sFile += "@--------------------- r12 <- address of routine to call\n"
  sFile += "  ldr   r12, [r12, lr, lsl #2]   @ R12 = [R12 + LR * 4]\n"
  sFile += "@--------------------- Call service routine\n"
  sFile += "  blx   r12\n"
  sFile += "@--------------------- Set return code (from R0 to R3) in stacked registers\n"
  sFile += "  stmia r5!, {r0, r1, r2, r3}\n"
  sFile += "@--------------------- Restore preserved registers, return from interrupt\n"
  sFile += "  pop   {r5, pc}\n\n"
  return sFile

#———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

def generateBreakpointSection (sectionName, idx):
  sFile  = asSeparator () + "\n"
  sFile += "  .section .text." + section + ", \"ax\", %progbits\n"
  sFile += "  .global " + section +"\n"
  sFile += "  .align 1\n"
  sFile += "  .type " + section +", %function\n\n"
  sFile += section +":\n"
  sFile += "  .fnstart\n"
  sFile += "  mrs  r12, IPSR @ r12 <- 0x??????00 in thread mode, 0x??????nn, nn ≠ 0 in handler mode\n"
  sFile += "  ands r12, #255\n"
  sFile += "  bne  section." + section + " @ in handler mode, call implementation routine directly\n"
  sFile += "  bkpt #" + str (idx) + "\n"
  sFile += "  bx   lr\n\n"
  sFile += ".Lfunc_end_" + section +":\n"
  sFile += "  .size " + section +", .Lfunc_end_" + section +" - " + section +"\n"
  sFile += "  .cantunwind\n"
  sFile += "  .fnend\n\n"
  return sFile

#———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

def generateSoftwareInterruptandler () :
  sFile = asSeparator ()
  sFile += "@\n"
  sFile += "@     SECTIONS: Software Interrupt Handler (two stack mode)\n"
  sFile += "@\n"
  sFile += asSeparator ()
  sFile += "@\n"
  sFile += "@                    |                            |\n"
  sFile += "@          PSP+32 -> |----------------------------| \\\n"
  sFile += "@                    | xPSR                       |  |\n"
  sFile += "@          PSP+28 -> |----------------------------|  |\n"
  sFile += "@                    | PC                         |  |\n"
  sFile += "@          PSP+24 -> |----------------------------|  |\n"
  sFile += "@                    | LR                         |  |\n"
  sFile += "@          PSP+20 -> |----------------------------|  |\n"
  sFile += "@                    | R12                        |  |  Saved by interrupt response\n"
  sFile += "@          PSP+16 -> |----------------------------|  |\n"
  sFile += "@                    | R3                         |  |\n"
  sFile += "@          PSP+12 -> |----------------------------|  |\n"
  sFile += "@                    | R2                         |  |\n"
  sFile += "@          PSP+8  -> |----------------------------|  |\n"
  sFile += "@                    | R1                         |  |\n"
  sFile += "@          PSP+4  -> |----------------------------|  |\n"
  sFile += "@                    | R0                         |  |\n"
  sFile += "@          PSP    -> |----------------------------| /\n"
  sFile += "@\n"
  sFile += asSeparator () + "\n"
  sFile += "  .section  .text.interrupt.SWINT, \"ax\", %progbits\n\n"
  sFile += "  .global interrupt.SWINT\n"
  sFile += "  .type interrupt.SWINT, %function\n\n"
  sFile += "interrupt.SWINT:\n"
  sFile += "@--------------------- Save preserved registers\n"
  sFile += "  push  {r5, lr}\n"
  sFile += "@--------------------- R5 <- thread SP\n"
  sFile += "  mrs   r5, psp\n"
  sFile += "@--------------------- Restore R0, R1, R2 and R3 from saved stack\n"
  sFile += "  ldmia r5, {r0, r1, r2, r3}\n"
  sFile += "@--------------------- R12 <- Address section routine\n"
  sFile += "  ldr   r12, [r5, #16]     @ 16 : 4 stacked registers before saved R12\n"
  sFile += "@--------------------- Call section routine\n"
  sFile += "  blx   r12\n"
  sFile += "@--------------------- Set return code (from R0 to R3) in stacked registers\n"
  sFile += "  stmia r5!, {r0, r1, r2, r3}    @ R5 is thread SP\n"
  sFile += "@--------------------- Set R12 stacked register to 0\n"
  sFile += "  mov   r0, #0\n"
  sFile += "  str   r0, [r5]\n"
  sFile += "@--------------------- Restore preserved registers, return from interrupt\n"
  sFile += "  pop   {r5, pc}\n\n"
  sFile += asSeparator () + "\n"
  sFile += "  .section  .text.direct.call.or.call.software.interrupt, \"ax\", %progbits\n\n"
  sFile += "  .type direct.call.or.call.software.interrupt, %function\n\n"
  sFile += "direct.call.or.call.software.interrupt: @ R12 contains the address of section implementation function\n"
  sFile += "@--------------------- Save preserved registers\n"
  sFile += "  push {r6, r7}\n"
  sFile += "  mrs  r6, IPSR          @ IPSR[8...0] ≠ 0 in handler mode, = 0 in thread mode\n"
  sFile += "  mov  r7, #511\n"
  sFile += "  tst  r6, r7\n"
  sFile += "  bne  direct.call\n"
  sFile += "@--------------------- Software interrupt\n"
  sFile += "  ldr  r6, = 0xE000EF00  @ Address of STIR control register\n"
  sFile += "  movs r7, # (80 - 16)   @ Software Interrupt has number #80\n"
  sFile += "  str  r7, [r6]          @ Generate Software Interrupt\n"
  sFile += "@--------------------- Wait for the exception is carried out\n"
  sFile += "wait.software.interrupt.done: @ R12 is reset by interrupt handler\n"
  sFile += "  cmp  r12, #0\n"
  sFile += "  bne  wait.software.interrupt.done\n"
  sFile += "@--------------------- Restore preserved registers\n"
  sFile += "  pop  {r6, r7}\n"
  sFile += "  bx   lr\n"
  sFile += "@--------------------- Direct call\n"
  sFile += "direct.call:\n"
  sFile += "  pop  {r6, r7}\n"
  sFile += "  bx   r12              @ in handler mode, call implementation routine directly\n\n"
  return sFile

#———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

def generateSoftwareInterruptSection (sectionName, idx):
  sFile  = asSeparator () + "\n"
  sFile += "  .section .text." + sectionName + ", \"ax\", %progbits\n"
  sFile += "  .global " + sectionName +"\n"
  sFile += "  .align 1\n"
  sFile += "  .type " + sectionName +", %function\n\n"
  sFile += sectionName +":\n"
  sFile += "  .fnstart\n"
  sFile += "  ldr  r12, =section." + sectionName + "\n"
  sFile += "  b    direct.call.or.call.software.interrupt\n\n"
  sFile += ".Lfunc_end_" + sectionName +":\n"
  sFile += "  .size " + sectionName +", .Lfunc_end_" + sectionName +" - " + sectionName +"\n"
  sFile += "  .cantunwind\n"
  sFile += "  .fnend\n\n"
  return sFile

#———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

def generateCppForBreakpointSection ():
  s = "#include \"all-headers.h\"\n\n"
  s += cppSeparator () + "\n"
  s += "static void enableDebugMonitorInterruption (BOOT_MODE) {\n"
  s += "//--- Enable DebugMonitor interrupt\n"
  s += "  #define DEMCR (* ((volatile uint32_t *) 0xE000EDFC))\n"
  s += "  DEMCR |= (1 << 16) ; // Set MON_EN\n"
  s += "}\n\n"
  s += cppSeparator () + "\n"
  s += "MACRO_BOOT_ROUTINE (enableDebugMonitorInterruption) ;\n\n"
  s += cppSeparator ()
  return s

#———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

def generateCppForSoftwareInterruptSection ():
  s = "#include \"all-headers.h\"\n\n"
  s += cppSeparator () + "\n"
  s += "static void enableSoftwareInterrupt (BOOT_MODE) {\n"
  s += "//--- Enable software interrupt\n"
  s += "  NVIC_ENABLE_IRQ (ISRSlot::SWINT) ;\n"
  s += "//--- Make STIR register accessible in unprivileged mode\n"
  s += "  #define CCR (* ((volatile uint32_t *) 0xE000ED14))\n"
  s += "  CCR |= (1 << 1) ;\n"
  s += "}\n\n"
  s += cppSeparator () + "\n"
  s += "MACRO_BOOT_ROUTINE (enableSoftwareInterrupt) ;\n\n"
  s += cppSeparator ()
  return s

#———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

def generateDisableInterruptSection (sectionName):
  sFile  = asSeparator ()
  sFile += "@   SECTION - " + sectionName + "\n"
  sFile += asSeparator () + "\n"
  sFile += "  .section .text." + sectionName + ", \"ax\", %progbits\n"
  sFile += "  .global " + sectionName +"\n"
  sFile += "  .align 1\n"
  sFile += "  .type " + sectionName +", %function\n\n"
  sFile += sectionName +":\n"
  sFile += "  .fnstart\n"
  sFile += "@--- Save preserved registers\n"
  sFile += "  push  {r6, lr}\n"
  sFile += "@--- Save interrupt enabled state\n"
  sFile += "  mrs   r6, PRIMASK\n"
  sFile += "@--- Disable interrupt\n"
  sFile += "  cpsid i\n"
  sFile += "@--- Call section, interrupts disabled\n"
  sFile += "  bl    section." + sectionName + "\n"
  sFile += "@--- Restore interrupt state\n"
  sFile += "  msr   PRIMASK, r6\n"
  sFile += "@--- Restore preserved registers and return\n"
  sFile += "  pop   {r6, pc}\n\n"
  sFile += ".Lfunc_end_" + sectionName +":\n"
  sFile += "  .size " + sectionName +", .Lfunc_end_" + sectionName +" - " + sectionName +"\n"
  sFile += "  .cantunwind\n"
  sFile += "  .fnend\n\n"
  return sFile

#———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
#    ENTRY POINT
#———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#------------------------------ Interrupt dictionary
interruptDictionary = interrupt_names_teensy_3_6.interruptNames ()
# print ("Dest " + destinationFile)
#------------------------------ Assembly destination file
destinationCppFile = sys.argv [1]
# print ("Dest " + destinationAssemblerFile)
#------------------------------ Assembly destination file
destinationAssemblerFile = sys.argv [2]
# print ("Dest " + destinationAssemblerFile)
#------------------------------ Service scheme
serviceScheme = sys.argv [3]
#------------------------------ Section scheme
sectionScheme = sys.argv [4]
#------------------------------ Header files
headerFiles = []
for i in range (5, len (sys.argv)):
  headerFiles.append (sys.argv [i])
#print headerFiles
#------------------------------ Destination file string
cppFile = ""
sFile  = "  .syntax unified\n"
sFile += "  .cpu cortex-m4\n"
sFile += "  .thumb\n\n"
#------------------------------ Explore header files
interruptServiceList = []
interruptSectionList = []
boolServiceSet = set ()
serviceList = []
sectionList = []
for header in headerFiles:
  with open (header) as f:
    for line in f:
      splitStr = line.strip ().split ("//$interrupt-section ")
      if len (splitStr) == 2 :
        interruptName = splitStr [1].strip ()
        if interruptName in interruptDictionary :
          interruptSectionList.append (interruptName)
          del interruptDictionary [interruptName]
        else:
          print (BOLD_RED () + "Error, interrupt '" + interruptName + "' does not exist, or is already assigned." + ENDC ())
          sys.exit (1)
      splitStr = line.strip ().split ("//$interrupt-service ")
      if len (splitStr) == 2 :
        interruptName = splitStr [1].strip ()
        if interruptName in interruptDictionary :
          interruptServiceList.append (interruptName)
          del interruptDictionary [interruptName]
        else:
          print (BOLD_RED () + "Error, interrupt '" + interruptName + "' does not exist, or is already assigned." + ENDC ())
          sys.exit (1)
      splitStr = line.strip ().split ("//$service ")
      if len (splitStr) == 2 :
        serviceName = splitStr [1].strip ()
        serviceList.append (serviceName)
      splitStr = line.strip ().split ("//$bool-service ")
      if len (splitStr) == 2 :
        serviceName = splitStr [1].strip ()
        serviceList.append (serviceName)
        boolServiceSet.add (serviceName)
      splitStr = line.strip ().split ("//$section ")
      if len (splitStr) == 2 :
        sectionName = splitStr [1].strip ()
        sectionList.append (sectionName)
#------------------------------ Has service ?
if (len (serviceList) > 0) and (serviceScheme == "") :
  print (BOLD_RED ()
         + "As the project defines service(s), the makefile.json file should have a \"SERVICE-SCHEME\" "
         + "entry (asoociated value: \"svc\")"
         +  ENDC ())
  sys.exit (1)
#------------------------------ Has sections ?
if (len (sectionList) > 0) and (sectionScheme == "") :
  print (BOLD_RED ()
         + "As the project defines section(s), the makefile.json file should have a \"SECTION-SCHEME\" "
         + "entry (possible associated value: \"disableInterrupt\", \"bkpt\", \"swint\")"
         +  ENDC ())
  sys.exit (1)
#------------------------------ Services
if serviceScheme == "svc" :
  sFile += generateSVChandler ()
  del interruptDictionary ["SVC"]
  sFile += asSeparator ()
  sFile += "@   SERVICES\n"
  idx = 1
  for service in serviceList :
    sFile += asSeparator () + "\n"
    sFile += "  .section .text." + service + ", \"ax\", %progbits\n"
    sFile += "  .global " + service +"\n"
    sFile += "  .align 1\n"
    sFile += "  .type " + service +", %function\n\n"
    sFile += service +":\n"
    sFile += "  .fnstart\n"
    sFile += "  svc #" + str (idx) + "\n"
    if service in boolServiceSet :
      sFile += "  b   get.user.result\n\n"
    else:
      sFile += "  bx  lr\n\n"
    sFile += ".Lfunc_end_" + service +":\n"
    sFile += "  .size " + service +", .Lfunc_end_" + service +" - " + service +"\n"
    sFile += "  .cantunwind\n"
    sFile += "  .fnend\n\n"
    idx += 1
  sFile += asSeparator ()
  sFile += "@    SERVICE DISPATCHER TABLE\n"
  sFile += asSeparator () + "\n"
  sFile += "  .align   2\n"
  sFile += "  .global  svc.dispatcher.table\n\n"
  sFile += "svc.dispatcher.table:\n"
  sFile += "  .word start.phase2 @ 0\n"
  idx = 1
  for service in serviceList :
    sFile += "  .word service." + service + " @ " + str (idx) + "\n"
    idx += 1
  sFile += "\n"
#------------------------------ Generate section handler
if sectionScheme == "bkpt" :
  cppFile += generateCppForBreakpointSection ()
  sFile += generateBreakpointHandler ()
  del interruptDictionary ["DebugMonitor"]
  sFile += asSeparator ()
  sFile += "@   SECTIONS\n"
  idx = 0
  for section in sectionList :
    sFile += generateBreakpointSection (section, idx)
    idx += 1
  sFile += asSeparator ()
  sFile += "@    SECTION DISPATCHER TABLE\n"
  sFile += asSeparator () + "\n"
  sFile += "  .global section.dispatcher.table\n\n"
  sFile += "section.dispatcher.table:\n"
  idx = 0
  for section in sectionList :
    sFile += "  .word section." + section + " @ " + str (idx) + "\n"
    idx += 1
  sFile += "\n"
elif sectionScheme == "swint" :
  cppFile += generateCppForSoftwareInterruptSection ()
  sFile += generateSoftwareInterruptandler ()
  del interruptDictionary ["SWINT"]
  sFile += asSeparator ()
  sFile += "@   SECTIONS\n"
  idx = 0
  for section in sectionList :
    sFile += generateSoftwareInterruptSection (section, idx)
    idx += 1
elif sectionScheme == "disableInterrupt" :
  for section in sectionList :
    sFile += generateDisableInterruptSection (section)
elif len (sectionList) > 0 :
  print (BOLD_RED ()
         + "In the makefile.json file, the \"SECTION-SCHEME\" key has an invalid \"" + sectionScheme + "\" value; "
         + "(possible value: \"disableInterrupt\", \"swint\")"
         +  ENDC ())
  sys.exit (1)
#------------------------------ Interrupts as service
for interruptServiceName in interruptServiceList :
  sFile += asSeparator ()
  sFile += "@   INTERRUPT - SERVICE: " + interruptServiceName + "\n"
  sFile += asSeparator () + "\n"
  sFile += "  .section .text.interrupt." + interruptServiceName + ", \"ax\", %progbits\n\n"
  sFile += "  .align  1\n"
  sFile += "  .global interrupt." + interruptServiceName + "\n"
  sFile += "  .type interrupt." + interruptServiceName + ", %function\n\n"
  sFile += "interrupt." + interruptServiceName + ":\n"
  sFile += "@----------------------------------------- Save preserved registers\n"
  sFile += "  push  {r4, lr}\n"
  sFile += "@----------------------------------------- Activity led On\n"
  sFile += "  ldr   r0, =0x400FF084  @ Address of GPIOC_PSOR control register\n"
  sFile += "  movs  r1, # (1 << 5)   @ Port D13 is PORTC:5\n"
  sFile += "  str   r1, [r0]         @ turn on\n"
  sFile += "@----------------------------------------- R4 <- running task context\n"
  sFile += "  ldr   r4, =var.running.task.control.block.ptr\n"
  sFile += "  ldr   r4, [r4]\n"
  sFile += "@----------------------------------------- Call Interrupt handler\n"
  sFile += "  bl    interrupt.service." + interruptServiceName + "\n"
  sFile += "@----------------------------------------- Perform the context switch, if needed\n"
  sFile += "  b     handle.context.switch\n\n"
#------------------------------ Interrupts as section
for interruptSectionName in interruptSectionList :
  sFile += asSeparator ()
  sFile += "@   INTERRUPT - SECTION: " + interruptSectionName + "\n"
  sFile += asSeparator () + "\n"
  sFile += "  .section .text.interrupt." + interruptSectionName + ", \"ax\", %progbits\n\n"
  sFile += "  .align  1\n"
  sFile += "  .global interrupt." + interruptSectionName + "\n"
  sFile += "  .type interrupt." + interruptSectionName + ", %function\n\n"
  sFile += "interrupt." + interruptSectionName + ":\n"
  sFile += "@----------------------------------------- Activity led On\n"
  sFile += "  ldr   r0, =0x400FF084  @ Address of GPIOC_PSOR control register\n"
  sFile += "  movs  r1, # (1 << 5)   @ Port D13 is PORTC:5\n"
  sFile += "  str   r1, [r0]         @ turn on\n"
  sFile += "@----------------------------------------- Goto interrupt function\n"
  sFile += "  b     interrupt.section." + interruptSectionName + "\n\n"
#------------------------------ Unused interrupts
for unusedInterruptName in interruptDictionary.keys () :
  sFile += asSeparator ()
  sFile += "@   INTERRUPT - UNUSED: " + unusedInterruptName + "\n"
  sFile += asSeparator () + "\n"
  sFile += "  .section .text.interrupt." + unusedInterruptName + ", \"ax\", %progbits\n\n"
  sFile += "  .align  1\n"
  sFile += "  .type interrupt." + unusedInterruptName + ", %function\n"
  sFile += "  .global interrupt." + unusedInterruptName + "\n\n"
  sFile += "interrupt." + unusedInterruptName + ":\n"
  sFile += "  movs r0, #" + str (interruptDictionary [unusedInterruptName]) + "\n"
  sFile += "  b    unused.interrupt\n\n"
#------------------------------ Write destination file
sFile += asSeparator ()
f = open (destinationAssemblerFile, "wt")
f.write (sFile)
f.close()
f = open (destinationCppFile, "wt")
f.write (cppFile)
f.close()

#———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
