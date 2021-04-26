/*--------------------------------------------------------------------------------------------------------------------*/
/*                                                                                                                    */
/*                                   Memory                                                                           */
/*                                                                                                                    */
/*--------------------------------------------------------------------------------------------------------------------*/

MEMORY {
  flash (rx) : ORIGIN = 0, LENGTH = 1024k
  sram_low  (rwx) : ORIGIN = 0x1FFF0000, LENGTH = 64k
  sram_high (rwx) : ORIGIN = 0x20000000, LENGTH = 192k
}

/*--------------------------------------------------------------------------------------------------------------------*/
/*                                                                                                                    */
/*                             Discarded sections                                                                     */
/*                                                                                                                    */
/*--------------------------------------------------------------------------------------------------------------------*/

SECTIONS {
  /DISCARD/ : {
    *(.gnu.*) ;
    *(.glue_7t);
    *(.glue_7);
    *(.ARM.*);
    *(.comment);
    *(.debug_frame);
    *(.vfp11_veneer);
    *(.v4_bx);
    *(.iplt);
    *(.rel.*);
    *(.igot.plt);
    *(rel.ARM.*);
  }
}

/*--------------------------------------------------------------------------------------------------------------------*/
/*                                                                                                                    */
/*                                Code                                                                                */
/*                                                                                                                    */
/*--------------------------------------------------------------------------------------------------------------------*/

SECTIONS {
  .text : {
  /*-------------------- Vectors */
    __vectors_start = . ;
    KEEP (*(isr.vectors)) ;
    __vectors_end = . ;
  /*-------------------- Flash magic values */
    LONG (-1) ;
    LONG (-1) ;
    LONG (-1) ;
    LONG (-2) ;
  /*-------------------- Code */
    __code_start = . ;
    . = ALIGN(4) ;
    *(.text*) ;
    *(.text) ;
    *(text) ;
  /*-------------------- Boot routine array */
    . = ALIGN (4) ;
    __boot_routine_array_start = . ;
    KEEP (*(boot.routine.array)) ;
    . = ALIGN (4) ;
    __boot_routine_array_end = . ;
  /*-------------------- Global C++ object constructor call */
    . = ALIGN (4) ;
    __constructor_array_start = . ;
    KEEP (*(.init_array)) ;
    . = ALIGN (4) ;
    __constructor_array_end = . ;
  /*-------------------- Init routine array */
    . = ALIGN (4) ;
    __init_routine_array_start = . ;
    KEEP (*(init.routine.array)) ;
    . = ALIGN (4) ;
    __init_routine_array_end = . ;
  /*-------------------- Real time interrupt routine array */
    . = ALIGN (4) ;
    __real_time_interrupt_routine_array_start = . ;
    KEEP (*(real.time.interrupt.routine.array)) ;
    . = ALIGN (4) ;
    __real_time_interrupt_routine_array_end = . ;
  /*-------------------- ROM data */
    . = ALIGN(4);
    *(.rodata*);
    . = ALIGN(4);
  /*-------------------- End */
    __code_end = . ;
  } > flash
}

/*--------------------------------------------------------------------------------------------------------------------*/
/*                                                                                                                    */
/*                          BSS (uninitialized data)                                                                  */
/*                                                                                                                    */
/*--------------------------------------------------------------------------------------------------------------------*/

SECTIONS {
  .bss : {
    . = ALIGN(4);
    __bss_start = . ;
    * (.bss*) ;
    . = ALIGN(4);
    * (COMMON) ;
    . = ALIGN(4);
    __bss_end = . ;
  } > sram_low
}

/*--------------------------------------------------------------------------------------------------------------------*/
/*                                                                                                                    */
/*                          Data (initialized data)                                                                   */
/*                                                                                                                    */
/*--------------------------------------------------------------------------------------------------------------------*/

SECTIONS {
  .data : AT (__code_end) {
    . = ALIGN (4) ;
    __data_start = . ;
    * (.data*) ;
  /*-------------------- Teensy CAN 0 receive ports */
    . = ALIGN (4) ;
    __teensy_can0_receive_ports_array_start = . ;
    * (teensy.CAN0.receive.ports.section) ;
    . = ALIGN (4) ;
    __teensy_can0_receive_ports_array_end = . ;
  /*-------------------- Teensy CAN 1 receive ports */
    . = ALIGN (4) ;
    __teensy_can1_receive_ports_array_start = . ;
    * (teensy.CAN1.receive.ports.section) ;
    . = ALIGN (4) ;
    __teensy_can1_receive_ports_array_end = . ;
    . = ALIGN (4) ;
    __data_end = . ;
  } > sram_low
}


/*--------------------------------------------------------------------------------------------------------------------*/

__data_load_start = LOADADDR (.data) ;
__data_load_end   = LOADADDR (.data) + SIZEOF (.data) ;

/*--------------------------------------------------------------------------------------------------------------------*/
/*                                                                                                                    */
/*                                System stack                                                                        */
/*                                                                                                                    */
/*--------------------------------------------------------------------------------------------------------------------*/

SECTIONS {
  .system_stack :{
    . = ALIGN (8) ;
    __system_stack_start = . ;
    . += 1024 ;
    . = ALIGN (4) ;
    __system_stack_end = . ;
  } > sram_low
}

/*--------------------------------------------------------------------------------------------------------------------*/
/*                                                                                                                    */
/*                                    Heap                                                                            */
/*                                                                                                                    */
/*--------------------------------------------------------------------------------------------------------------------*/

__heap_start = ORIGIN (sram_high) ;
__heap_end = ORIGIN(sram_high) + LENGTH(sram_high) ;

/*--------------------------------------------------------------------------------------------------------------------*/
