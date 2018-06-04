#pragma once

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <stdint.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral NVIC
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Interrupt Set-Enable Registers (idx = 0 ... 7)
#define NVIC_ISER(idx) (* ((const volatile uint32_t *) (0xE000E100 + 0x00 + 4 * (idx))))

//-------------------- Interrupt Clear-Enable Registers (idx = 0 ... 7)
#define NVIC_ICER(idx) (* ((const volatile uint32_t *) (0xE000E100 + 0x80 + 4 * (idx))))

//-------------------- Interrupt Set-Pending Registers (idx = 0 ... 7)
#define NVIC_ISPR(idx) (* ((const volatile uint32_t *) (0xE000E100 + 0x100 + 4 * (idx))))

//-------------------- Interrupt Clear-Pending Registers (idx = 0 ... 7)
#define NVIC_ICPR(idx) (* ((const volatile uint32_t *) (0xE000E100 + 0x180 + 4 * (idx))))

//-------------------- Interrupt Active Bit Register (idx = 0 ... 7)
#define NVIC_IABR(idx) (* ((const volatile uint32_t *) (0xE000E100 + 0x200 + 4 * (idx))))

//-------------------- Interrupt Priority Register (idx = 0 ... 59)
#define NVIC_IPR(idx) (* ((const volatile uint32_t *) (0xE000E100 + 0x300 + 4 * (idx))))

//-------------------- Software Trigger Interrupt Register
#define NVIC_STIR (* ((volatile uint32_t *) (0xE000E100 + 0xE00)))

  // Field (width: 9 bits): Interrupt ID of the interrupt to trigger, in the range 0-239.
    inline uint32_t NVIC_STIR_INTID (const uint32_t inValue) { return (inValue & 511) << 0 ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral SCB
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Auxiliary Control Register
#define SCB_ACTLR (* ((volatile uint32_t *) (0xE000E000 + 0x8)))

  // Boolean field: Disables Interruption Folding
    static const uint32_t SCB_ACTLR_DISFOLD = 1U << 2 ;

  // Boolean field: Disabled FPU exception outputs
    static const uint32_t SCB_ACTLR_PFEXCODIS = 1U << 10 ;

  // Boolean field: Disables dynamic read allocate mode for Write-Back Write-Allocate memory regions:
    static const uint32_t SCB_ACTLR_DISRAMODE = 1U << 11 ;

  // Boolean field: Disables ITM and DWT ATB flush:
    static const uint32_t SCB_ACTLR_DISITMATBFLUSH = 1U << 12 ;

  // Boolean field: Disables the Branch Target Address Cache (BTAC).
    static const uint32_t SCB_ACTLR_DISBTACREAD = 1U << 13 ;

  // Boolean field: Disables the Branch Target Address Cache allocation.
    static const uint32_t SCB_ACTLR_DISBTACALLOC = 1U << 14 ;

  // Boolean field: Disables critical AXI Read-Under-Read.
    static const uint32_t SCB_ACTLR_DISCRITAXIRUR = 1U << 15 ;

  // Boolean field: Disables dual-issued direct branches.
    static const uint32_t SCB_ACTLR_DISDI_DB = 1U << 16 ;

  // Boolean field: Disables dual-issued indirect branches.
    static const uint32_t SCB_ACTLR_DISDI_IB = 1U << 17 ;

  // Boolean field: Disables dual-issued loads to PC.
    static const uint32_t SCB_ACTLR_DISDI_LPC = 1U << 18 ;

  // Boolean field: Disables integer MAC and MUL dual-issued instructions.
    static const uint32_t SCB_ACTLR_DISDI_MAC_MUL = 1U << 19 ;

  // Boolean field: Disables VFP dual-issued instruction.
    static const uint32_t SCB_ACTLR_DISDI_VFP = 1U << 20 ;

  // Boolean field: Disables direct branches instructions in channel 1.
    static const uint32_t SCB_ACTLR_DISISSCH1_DB = 1U << 21 ;

  // Boolean field: Disables indirect branches instructions in channel 1.
    static const uint32_t SCB_ACTLR_DISISSCH1_IB = 1U << 22 ;

  // Boolean field: Disables loads to PC instructions in channel 1.
    static const uint32_t SCB_ACTLR_DISISSCH1_LPC = 1U << 23 ;

  // Boolean field: Disables integer MAC and MUL instructions in channel 1.
    static const uint32_t SCB_ACTLR_DISISSCH1_MAC_MUL = 1U << 24 ;

  // Boolean field: Disables VFP instructions in channel 1
    static const uint32_t SCB_ACTLR_DISISSCH1_VFP = 1U << 25 ;

  // Boolean field: Disables dynamic allocation of ADD and SUB instructions:
    static const uint32_t SCB_ACTLR_DISDYNADD = 1U << 26 ;

//-------------------- CPUID Base Register
#define SCB_CPUID (* ((const volatile uint32_t *) (0xE000E000 + 0xD00)))

  // Field (width: 4 bits): Revision number, the p value in the rnpn product revision identifier.
    inline uint32_t SCB_CPUID_Revision (const uint32_t inValue) { return (inValue & 15) << 0 ; }

  // Field (width: 12 bits): Part number of the processor.
    inline uint32_t SCB_CPUID_PartNo (const uint32_t inValue) { return (inValue & 4095) << 4 ; }

  // Field (width: 4 bits): Reads as 0xF.
    inline uint32_t SCB_CPUID_Constant (const uint32_t inValue) { return (inValue & 15) << 16 ; }

  // Field (width: 4 bits): Variant number, the r value in the rnpn product revision identifier.
    inline uint32_t SCB_CPUID_Variant (const uint32_t inValue) { return (inValue & 15) << 20 ; }

  // Field (width: 8 bits): Implementer code.
    inline uint32_t SCB_CPUID_Implementer (const uint32_t inValue) { return (inValue & 255) << 24 ; }

//-------------------- Interrupt Control and State Register
#define SCB_ICSR (* ((volatile uint32_t *) (0xE000E000 + 0xD04)))

  // Field (width: 9 bits): Contains the active exception number.
    inline uint32_t SCB_ICSR_VECTACTIVE (const uint32_t inValue) { return (inValue & 511) << 0 ; }

  // Boolean field: Indicates whether there are preempted active exceptions.
    static const uint32_t SCB_ICSR_RETTOBASE = 1U << 11 ;

  // Field (width: 9 bits): Indicates the exception number of the highest priority pending enabled exception.
    inline uint32_t SCB_ICSR_VECTPENDING (const uint32_t inValue) { return (inValue & 511) << 12 ; }

  // Boolean field: Interrupt pending flag, excluding NMI and Faults
    static const uint32_t SCB_ICSR_ISRPENDING = 1U << 22 ;

  // Boolean field: SysTick exception clear-pending bit.
    static const uint32_t SCB_ICSR_PENDSTCLR = 1U << 25 ;

  // Boolean field: SysTick exception set-pending bit.
    static const uint32_t SCB_ICSR_PENDSTSET = 1U << 26 ;

  // Boolean field: PendSV clear-pending bit.
    static const uint32_t SCB_ICSR_PENDSVCLR = 1U << 27 ;

  // Boolean field: PendSV set-pending bit.
    static const uint32_t SCB_ICSR_PENDSVSET = 1U << 28 ;

  // Boolean field: NMI set-pending bit.
    static const uint32_t SCB_ICSR_NMIPENDSET = 1U << 31 ;

//-------------------- Vector Table Offset Register
#define SCB_VTOR (* ((volatile uint32_t *) (0xE000E000 + 0xD08)))

//-------------------- Application Interrupt and Reset Control Register
#define SCB_AIRCR (* ((volatile uint32_t *) (0xE000E000 + 0xD0C)))

  // Boolean field: System reset request bit setting is implementation defined.
    static const uint32_t SCB_AIRCR_SYSRESETREQ = 1U << 2 ;

  // Field (width: 3 bits): Interrupt priority grouping field. This field determines the split of group priority from subpriority.
    inline uint32_t SCB_AIRCR_PRIGROUP (const uint32_t inValue) { return (inValue & 7) << 8 ; }

  // Boolean field: Data endianness bit setting is implementation defined.
    static const uint32_t SCB_AIRCR_ENDIANNESS = 1U << 15 ;

  // Field (width: 16 bits): Register key. On write, write 0x5FA to VECTKEY, otherwise the write is ignored. Reads as 0xFA05
    inline uint32_t SCB_AIRCR_VECTKEY (const uint32_t inValue) { return (inValue & 65535) << 16 ; }

//-------------------- System Control Register
#define SCB_SCR (* ((volatile uint32_t *) (0xE000E000 + 0xD10)))

  // Boolean field: Indicates sleep-on-exit when returning from Handler mode to Thread mode
    static const uint32_t SCB_SCR_SLEEPONEXIT = 1U << 1 ;

  // Boolean field: Controls whether the processor uses sleep or deep sleep as its low-power mode
    static const uint32_t SCB_SCR_SLEEPDEEP = 1U << 2 ;

  // Boolean field: Send event on pending bit
    static const uint32_t SCB_SCR_SEVONPEND = 1U << 4 ;

//-------------------- Configuration and Control Register
#define SCB_CCR (* ((volatile uint32_t *) (0xE000E000 + 0xD14)))

  // Boolean field: Indicates how the processor enters Thread mode
    static const uint32_t SCB_CCR_NONBASETHREADENA = 1U << 0 ;

  // Boolean field: Enables unprivileged software access to the STIR
    static const uint32_t SCB_CCR_USERSETMPEND = 1U << 1 ;

  // Boolean field: Enables unalign access traps.
    static const uint32_t SCB_CCR_UNALIGNED_TRP = 1U << 3 ;

  // Boolean field: Enables faulting or halting when the processor executes an SDIF or UDIV instruction with a divisor of 0.
    static const uint32_t SCB_CCR_DIV0_TRP = 1U << 4 ;

  // Boolean field: Enables handlers with priority -1 or -2 to ignore data BusFaults caused by load and store instructions. This applies to the hard fault, NMI, and FAULTMASK escalated handlers.
    static const uint32_t SCB_CCR_BFHFNMIGN = 1U << 8 ;

  // Boolean field: Always reads-as-one. It indicates stack alignment on exception entry is 8-byte aligned.
    static const uint32_t SCB_CCR_STKALIGN = 1U << 9 ;

  // Boolean field: Enables L1 data cache.
    static const uint32_t SCB_CCR_DC = 1U << 16 ;

  // Boolean field: Enables L1 instruction cache.
    static const uint32_t SCB_CCR_IC = 1U << 17 ;

//-------------------- System Handler Priority Register 1
#define SCB_SHPR1 (* ((volatile uint32_t *) (0xE000E000 + 0xD18)))

  // Field (width: 8 bits): Priority of the system handler, MemManage
    inline uint32_t SCB_SHPR1_PRI_4 (const uint32_t inValue) { return (inValue & 255) << 0 ; }

  // Field (width: 8 bits): Priority of the system handler, BusFault
    inline uint32_t SCB_SHPR1_PRI_5 (const uint32_t inValue) { return (inValue & 255) << 8 ; }

  // Field (width: 8 bits): Priority of the system handler, UsageFault
    inline uint32_t SCB_SHPR1_PRI_6 (const uint32_t inValue) { return (inValue & 255) << 16 ; }

//-------------------- System Handler Priority Register 2
#define SCB_SHPR2 (* ((volatile uint32_t *) (0xE000E000 + 0xD1C)))

  // Field (width: 8 bits): Priority of the system handler, SVCall
    inline uint32_t SCB_SHPR2_PRI_11 (const uint32_t inValue) { return (inValue & 255) << 24 ; }

//-------------------- System Handler Priority Register 3
#define SCB_SHPR3 (* ((volatile uint32_t *) (0xE000E000 + 0xD20)))

  // Field (width: 8 bits): Priority of the system handler, PendSV
    inline uint32_t SCB_SHPR3_PRI_14 (const uint32_t inValue) { return (inValue & 255) << 16 ; }

  // Field (width: 8 bits): Priority of the system handler, SysTick
    inline uint32_t SCB_SHPR3_PRI_15 (const uint32_t inValue) { return (inValue & 255) << 24 ; }

//-------------------- System Handler Control and State Register
#define SCB_SHCSR (* ((volatile uint32_t *) (0xE000E000 + 0xD24)))

  // Boolean field: MemManage exception active bit, reads as 1 if exception is active.
    static const uint32_t SCB_SHCSR_MEMFAULTACT = 1U << 0 ;

  // Boolean field: BusFault exception active bit, reads as 1 if exception is active.
    static const uint32_t SCB_SHCSR_BUSFAULTACT = 1U << 1 ;

  // Boolean field: UsageFault exception active bit, reads as 1 if exception is active.
    static const uint32_t SCB_SHCSR_USGFAULTACT = 1U << 3 ;

  // Boolean field: SVCall active bit, reads as 1 if exception is active.
    static const uint32_t SCB_SHCSR_SVCALLACT = 1U << 7 ;

  // Boolean field: Debug Monitor active bit, reads as 1 if exception is active.
    static const uint32_t SCB_SHCSR_MONITORACT = 1U << 8 ;

  // Boolean field: PendSV exception active bit, reads as 1 if exception is active.
    static const uint32_t SCB_SHCSR_PENDSVACT = 1U << 10 ;

  // Boolean field: Systick exception active bit, reads as 1 if exception is active.
    static const uint32_t SCB_SHCSR_SYSTICKACT = 1U << 11 ;

  // Boolean field: UsageFault exception pending bit, reads as 1 if exception is pending
    static const uint32_t SCB_SHCSR_USGFAULTPENDED = 1U << 12 ;

  // Boolean field: MemManage exception pending bit, reads as 1 if exception is pending
    static const uint32_t SCB_SHCSR_MEMFAULTPENDED = 1U << 13 ;

  // Boolean field: BusFault exception pending bit, reads as 1 if exception is pending
    static const uint32_t SCB_SHCSR_BUSFAULTPENDED = 1U << 14 ;

  // Boolean field: SVCall pending bit, reads as 1 if exception is pending
    static const uint32_t SCB_SHCSR_SVCALLPENDED = 1U << 15 ;

  // Boolean field: MemManage enable bit, set to 1 to enable
    static const uint32_t SCB_SHCSR_MEMFAULTENA = 1U << 16 ;

  // Boolean field: BusFault enable bit, set to 1 to enable
    static const uint32_t SCB_SHCSR_BUSFAULTENA = 1U << 17 ;

  // Boolean field: UsageFault enable bit, set to 1 to enable
    static const uint32_t SCB_SHCSR_USGFAULTENA = 1U << 18 ;

//-------------------- MemManage Fault Status Register
#define SCB_CFSR (* ((volatile uint8_t *) (0xE000E000 + 0xD28)))

  // Boolean field: Instruction access violation flag
    static const uint8_t SCB_CFSR_IACCVIOL = 1U << 0 ;

  // Boolean field: Data access violation flag
    static const uint8_t SCB_CFSR_DACCVIOL = 1U << 1 ;

  // Boolean field: MemManage fault on unstacking for a return from exception
    static const uint8_t SCB_CFSR_MUNSTKERR = 1U << 3 ;

  // Boolean field: MemManage fault on stacking for exception entry
    static const uint8_t SCB_CFSR_MSTKERR = 1U << 4 ;

  // Boolean field: MemManage fault during floating-point lazy state preservation.
    static const uint8_t SCB_CFSR_MLSPERR = 1U << 5 ;

  // Boolean field: MemManage fault address register valid flag.
    static const uint8_t SCB_CFSR_MMARVALID = 1U << 7 ;

//-------------------- BusFault Status Register
#define SCB_BFSR (* ((volatile uint8_t *) (0xE000E000 + 0xD29)))

  // Boolean field: Instruction bus error
    static const uint8_t SCB_BFSR_IBUSERR = 1U << 0 ;

  // Boolean field: Precise data bus error
    static const uint8_t SCB_BFSR_PRECISERR = 1U << 1 ;

  // Boolean field: Precise data bus error
    static const uint8_t SCB_BFSR_IMPRECISERR = 1U << 2 ;

  // Boolean field: BusFault on unstacking for a return from exception.
    static const uint8_t SCB_BFSR_UNSTKERR = 1U << 3 ;

  // Boolean field: BusFault on stacking for exception entry.
    static const uint8_t SCB_BFSR_STKERR = 1U << 4 ;

  // Boolean field: BusFault on floating-point lazy state preservation.
    static const uint8_t SCB_BFSR_LSPERR = 1U << 5 ;

  // Boolean field: BusFault Address Register valid flag.
    static const uint8_t SCB_BFSR_BFARVALID = 1U << 7 ;

//-------------------- UsageFault Status Register
#define SCB_UFSR (* ((volatile uint16_t *) (0xE000E000 + 0xD2A)))

  // Boolean field: Undefined instruction UsageFault
    static const uint16_t SCB_UFSR_UNDEFINSTR = 1U << 0 ;

  // Boolean field: Invalid State UsageFault
    static const uint16_t SCB_UFSR_INVSTATE = 1U << 1 ;

  // Boolean field: Invalid PC load UsageFault, caused by an invalid PC load by EXC_RETURN
    static const uint16_t SCB_UFSR_INVPC = 1U << 2 ;

  // Boolean field: No coprocessor UsageFault
    static const uint16_t SCB_UFSR_NOCP = 1U << 3 ;

  // Boolean field: Unaligned access UsageFault
    static const uint16_t SCB_UFSR_UNALIGNED = 1U << 8 ;

  // Boolean field: Divide by zero UsageFault.
    static const uint16_t SCB_UFSR_DIVBYZERO = 1U << 9 ;

//-------------------- HardFault Status Register
#define SCB_HFSR (* ((volatile uint32_t *) (0xE000E000 + 0xD2C)))

  // Boolean field: Indicates a BusFault on a vector table read during exception processing.
    static const uint32_t SCB_HFSR_VECTTBL = 1U << 1 ;

  // Boolean field: Indicates a forced hard fault, generated by escalation of a fault with configurable priority that cannot be handled, either because of priority or because it is disabled.
    static const uint32_t SCB_HFSR_FORCED = 1U << 30 ;

  // Boolean field: Reserved for Debug use. When writing to the register, you must write 1 to this bit, otherwise behavior is UNPREDICTABLE.
    static const uint32_t SCB_HFSR_DEBUGEVT = 1U << 31 ;

//-------------------- MemManage Fault Address Register
#define SCB_MMAR (* ((volatile uint32_t *) (0xE000E000 + 0xD34)))

//-------------------- BusFault Address Register
#define SCB_BFAR (* ((volatile uint32_t *) (0xE000E000 + 0xD38)))

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral SysTick
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- SysTick Control and Status Register
#define SysTick_CSR (* ((volatile uint32_t *) (0xE000E010 + 0)))

  // Boolean field: Enable SysTick Timer
    static const uint32_t SysTick_CSR_ENABLE = 1U << 0 ;

  // Boolean field: Generate Tick Interrupt
    static const uint32_t SysTick_CSR_TICKINT = 1U << 1 ;

  // Boolean field: Source to count from
    static const uint32_t SysTick_CSR_CLKSOURCE = 1U << 2 ;

  // Boolean field: SysTick counted to zero
    static const uint32_t SysTick_CSR_COUNTFLAG = 1U << 16 ;

//-------------------- SysTick Reload Value Register
#define SysTick_RVR (* ((volatile uint32_t *) (0xE000E010 + 0x4)))

  // Field (width: 24 bits): Value to auto reload SysTick after reaching zero
    inline uint32_t SysTick_RVR_RELOAD (const uint32_t inValue) { return (inValue & 16777215) << 0 ; }

//-------------------- SysTick Current Value Register
#define SysTick_CVR (* ((volatile uint32_t *) (0xE000E010 + 0x8)))

  // Field (width: 24 bits): Current value
    inline uint32_t SysTick_CVR_CURRENT (const uint32_t inValue) { return (inValue & 16777215) << 0 ; }

//-------------------- SysTick Calibration Value Register
#define SysTick_CALIB (* ((const volatile uint32_t *) (0xE000E010 + 0xC)))

  // Field (width: 24 bits): Reload value to use for 10ms timing
    inline uint32_t SysTick_CALIB_TENMS (const uint32_t inValue) { return (inValue & 16777215) << 0 ; }

  // Boolean field: Clock Skew
    static const uint32_t SysTick_CALIB_SKEW = 1U << 30 ;

  // Boolean field: No Ref
    static const uint32_t SysTick_CALIB_NOREF = 1U << 31 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral MPU
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- MPU Type Register
#define MPU_TYPE (* ((const volatile uint32_t *) (0xE000ED90 + 0x0)))

  // Boolean field: Indicates support for unified or separate instruction and data memory maps.
    static const uint32_t MPU_TYPE_SEPARATE = 1U << 0 ;

  // Field (width: 8 bits): Indicates the number of supported MPU data regions depending on your implementation.
    inline uint32_t MPU_TYPE_DREGION (const uint32_t inValue) { return (inValue & 255) << 8 ; }

  // Field (width: 8 bits): Indicates the number of supported MPU instruction regions. Always contains 0x0: the MPU memory map is unified and is described by the DREGION field.
    inline uint32_t MPU_TYPE_IREGION (const uint32_t inValue) { return (inValue & 255) << 16 ; }

//-------------------- MPU Control Register
#define MPU_CTRL (* ((volatile uint32_t *) (0xE000ED90 + 0x4)))

  // Boolean field: Enables the optional MPU.
    static const uint32_t MPU_CTRL_ENABLE = 1U << 0 ;

  // Boolean field: Enables the operation of MPU during hard fault, NMI, and FAULTMASK handlers.
    static const uint32_t MPU_CTRL_HFNMIENA = 1U << 1 ;

  // Boolean field: Enables privileged software access to the default memory map.
    static const uint32_t MPU_CTRL_PRIVDEFENA = 1U << 2 ;

//-------------------- MPU Region Number Register
#define MPU_RNR (* ((volatile uint32_t *) (0xE000ED90 + 0x8)))

  // Field (width: 8 bits): Indicates the MPU region referenced by the MPU_RBAR and MPU_RASR registers.
    inline uint32_t MPU_RNR_REGION (const uint32_t inValue) { return (inValue & 255) << 0 ; }

//-------------------- MPU Region Base Address Register
#define MPU_RBAR (* ((volatile uint32_t *) (0xE000ED90 + 0xC)))

  // Field (width: 4 bits): On Write, see the VALID field. On read, specifies the region number.
    inline uint32_t MPU_RBAR_REGION (const uint32_t inValue) { return (inValue & 15) << 0 ; }

  // Boolean field: MPU Region number valid bit. Depending on your implementation, this has the following effect: 0 - either updates the base address for the region specified by MPU_RNR or ignores the value of the REGION field. 1 - either updates the value of the MPU_RNR to the value of the REGION field or updates the base address for the region specified in the REGION field.
    static const uint32_t MPU_RBAR_VALID = 1U << 4 ;

  // Field (width: 27 bits): The ADDR field is bits[31:N] of the MPU_RBAR.
    inline uint32_t MPU_RBAR_ADDR (const uint32_t inValue) { return (inValue & 134217727) << 5 ; }

//-------------------- MPU Region Base Attribute and Size Register
#define MPU_RASR (* ((volatile uint32_t *) (0xE000ED90 + 0x10)))

  // Boolean field: Region enable bit.
    static const uint32_t MPU_RASR_ENABLE = 1U << 0 ;

  // Field (width: 5 bits): Specifies the size of the MPU protection region. Minimum value is 4. The Region size is defined as (Region size in bytes) = 2^(SIZE+1)
    inline uint32_t MPU_RASR_SIZE (const uint32_t inValue) { return (inValue & 31) << 1 ; }

  // Boolean field: Subregion disable bits
    static const uint32_t MPU_RASR_SRD0 = 1U << 8 ;

  // Boolean field: Subregion disable bits
    static const uint32_t MPU_RASR_SRD1 = 1U << 9 ;

  // Boolean field: Subregion disable bits
    static const uint32_t MPU_RASR_SRD2 = 1U << 10 ;

  // Boolean field: Subregion disable bits
    static const uint32_t MPU_RASR_SRD3 = 1U << 11 ;

  // Boolean field: Subregion disable bits
    static const uint32_t MPU_RASR_SRD4 = 1U << 12 ;

  // Boolean field: Subregion disable bits.
    static const uint32_t MPU_RASR_SRD5 = 1U << 13 ;

  // Boolean field: Subregion disable bits.
    static const uint32_t MPU_RASR_SRD6 = 1U << 14 ;

  // Boolean field: Subregion disable bits.
    static const uint32_t MPU_RASR_SRD7 = 1U << 15 ;

  // Boolean field: Memory access attribute.
    static const uint32_t MPU_RASR_B = 1U << 16 ;

  // Boolean field: Memory access attribute.
    static const uint32_t MPU_RASR_C = 1U << 17 ;

  // Boolean field: Shareable bit. Applies to Normal memory only.
    static const uint32_t MPU_RASR_S = 1U << 18 ;

  // Field (width: 3 bits): Memory access attribute.
    inline uint32_t MPU_RASR_TEX (const uint32_t inValue) { return (inValue & 7) << 19 ; }

  // Field (width: 3 bits): Access permission field
    inline uint32_t MPU_RASR_AP (const uint32_t inValue) { return (inValue & 7) << 24 ; }

  // Boolean field: Instruction access disable bit
    static const uint32_t MPU_RASR_XN = 1U << 28 ;

//-------------------- Uses (MPU_RNR[7:2]<<2) + 1
#define MPU_RBAR_A1 (* ((volatile uint32_t *) (0xE000ED90 + 0x14)))

//-------------------- Uses (MPU_RNR[7:2]<<2) + 1
#define MPU_RASR_A1 (* ((volatile uint32_t *) (0xE000ED90 + 0x18)))

//-------------------- Uses (MPU_RNR[7:2]<<2) + 2
#define MPU_RBAR_A2 (* ((volatile uint32_t *) (0xE000ED90 + 0x1C)))

//-------------------- Uses (MPU_RNR[7:2]<<2) + 2
#define MPU_RASR_A2 (* ((volatile uint32_t *) (0xE000ED90 + 0x20)))

//-------------------- Uses (MPU_RNR[7:2]<<2) + 3
#define MPU_RBAR_A3 (* ((volatile uint32_t *) (0xE000ED90 + 0x24)))

//-------------------- Uses (MPU_RNR[7:2]<<2) + 3
#define MPU_RASR_A3 (* ((volatile uint32_t *) (0xE000ED90 + 0x28)))

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral Debug
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Debug Fault Status Register
#define Debug_DFSR (* ((volatile uint32_t *) (0xE000ED00 + 0x30)))

  // Boolean field: Halt request debug event.
    static const uint32_t Debug_DFSR_HALTED = 1U << 0 ;

  // Boolean field: BKPT instruction executed or breakpoint match in FPB.
    static const uint32_t Debug_DFSR_BKPT = 1U << 1 ;

  // Boolean field: Data Watchpoint and Trace trap. Indicates that the core halted due to at least one DWT trap event.
    static const uint32_t Debug_DFSR_DWTTRAP = 1U << 2 ;

  // Boolean field: Vector catch triggered. Corresponding FSR will contain the primary cause of the exception.
    static const uint32_t Debug_DFSR_VCATCH = 1U << 3 ;

  // Boolean field: An asynchronous exception generated due to the assertion of EDBGRQ.
    static const uint32_t Debug_DFSR_EXTERNAL = 1U << 4 ;

//-------------------- Debug Halting Control and Status Register (on read)
#define Debug_DHCSR_RO (* ((const volatile uint32_t *) (0xE000ED00 + 0xF0)))

  // Boolean field: Halting debug enable bit.
    static const uint32_t Debug_DHCSR_RO_C_DEBUGGEN = 1U << 0 ;

  // Boolean field: Processor halt bit.
    static const uint32_t Debug_DHCSR_RO_C_HALT = 1U << 1 ;

  // Boolean field: Processor step bit.
    static const uint32_t Debug_DHCSR_RO_C_STEP = 1U << 2 ;

  // Boolean field: When debug is enabled, the debugger can write to this bit to mask PendSV, SysTick and external configurable interrupts.
    static const uint32_t Debug_DHCSR_RO_C_MASKINTS = 1U << 3 ;

  // Boolean field: Allow imprecise entry to Debug state.
    static const uint32_t Debug_DHCSR_RO_C_SNAPSTALL = 1U << 5 ;

  // Boolean field: A handshake flag for transfers through the DCRDR.
    static const uint32_t Debug_DHCSR_RO_S_REGRDY = 1U << 16 ;

  // Boolean field: Indicates whether the processor is in Debug state.
    static const uint32_t Debug_DHCSR_RO_S_HALT = 1U << 17 ;

  // Boolean field: Indicates whether the processor is sleeping.
    static const uint32_t Debug_DHCSR_RO_S_SLEEP = 1U << 18 ;

  // Boolean field: Indicates whether the processor is locked up because of an unrecoverable exception.
    static const uint32_t Debug_DHCSR_RO_S_LOCKUP = 1U << 19 ;

  // Boolean field: Set to 1 every time the processor retires one or more instructions.
    static const uint32_t Debug_DHCSR_RO_S_RETIRE_ST = 1U << 24 ;

  // Boolean field: Indicates whether the processor has been reset since the last read of DHCSR.
    static const uint32_t Debug_DHCSR_RO_S_RESET_ST = 1U << 25 ;

//-------------------- Debug Halting Control and Status Register (on write)
#define Debug_DHCSR_WO (* ((volatile uint32_t *) (0xE000ED00 + 0xF0)))

  // Boolean field: Halting debug enable bit.
    static const uint32_t Debug_DHCSR_WO_C_DEBUGGEN = 1U << 0 ;

  // Boolean field: Processor halt bit.
    static const uint32_t Debug_DHCSR_WO_C_HALT = 1U << 1 ;

  // Boolean field: Processor step bit.
    static const uint32_t Debug_DHCSR_WO_C_STEP = 1U << 2 ;

  // Boolean field: When debug is enabled, the debugger can write to this bit to mask PendSV, SysTick and external configurable interrupts.
    static const uint32_t Debug_DHCSR_WO_C_MASKINTS = 1U << 3 ;

  // Boolean field: Allow imprecise entry to Debug state.
    static const uint32_t Debug_DHCSR_WO_C_SNAPSTALL = 1U << 5 ;

  // Field (width: 16 bits): Debug Key. The value 0xA05F must be written to enable write accesses to bits [15:0], otherwise the write access will be ignored.
    inline uint32_t Debug_DHCSR_WO_S_RESET_ST (const uint32_t inValue) { return (inValue & 65535) << 16 ; }

//-------------------- Debug Core Register Selector Register
#define Debug_DCRSR (* ((volatile uint32_t *) (0xE000ED00 + 0xF4)))

  // Field (width: 4 bits): Specifies the ARM core register, special-purpose register, or Floating-point extension register, to transfer.
    inline uint32_t Debug_DCRSR_REGSEL (const uint32_t inValue) { return (inValue & 15) << 0 ; }

  // Boolean field: Specifies the access type for the transfer.
    static const uint32_t Debug_DCRSR_REGWnR = 1U << 16 ;

//-------------------- Debug Core Register Data Register
#define Debug_DCRDR (* ((volatile uint32_t *) (0xE000ED00 + 0xF8)))

//-------------------- Debug Exception and Monitor Control Register
#define Debug_DEMCR (* ((volatile uint32_t *) (0xE000ED00 + 0xFC)))

  // Boolean field: Enable Reset Vector Catch. This causes a Local reset to halt a running system.
    static const uint32_t Debug_DEMCR_VC_CORERESET = 1U << 0 ;

  // Boolean field: Enable halting debug trap on a MemManage exception.
    static const uint32_t Debug_DEMCR_VC_MMERR = 1U << 4 ;

  // Boolean field: Enable halting debug trap on a UsageFault caused by an access to a Coprocessor.
    static const uint32_t Debug_DEMCR_VC_NOCPERR = 1U << 5 ;

  // Boolean field: Enable halting debug trap on a UsageFault exception caused by a checking error, for example an alignment check error.
    static const uint32_t Debug_DEMCR_VC_CHKERR = 1U << 6 ;

  // Boolean field: Enable halting debug trap on a UsageFault exception caused by a state information error, for example an Undefined instruction.
    static const uint32_t Debug_DEMCR_VC_STATERR = 1U << 7 ;

  // Boolean field: Enable halting debug trap on a BusFault exception.
    static const uint32_t Debug_DEMCR_VC_BUSERR = 1U << 8 ;

  // Boolean field: Enable halting debug trap on a fault occurring during exception entry or exception return.
    static const uint32_t Debug_DEMCR_VC_INTERR = 1U << 9 ;

  // Boolean field: Enable halting debug trap on HardFault exception.
    static const uint32_t Debug_DEMCR_VC_HARDERR = 1U << 10 ;

  // Boolean field: Enable the DebugMonitor exception.
    static const uint32_t Debug_DEMCR_MON_EN = 1U << 16 ;

  // Boolean field: Sets or clears the pending state of the DebugMonitor exception.
    static const uint32_t Debug_DEMCR_MON_PEND = 1U << 17 ;

  // Boolean field: When MON_EN is set to 0, this feature is disabled and the processor ignores MON_STEP. When MON_EN is set to 1, the meaning of MON_STEP is: 0 Do not step the processor, 1 Step the processor.
    static const uint32_t Debug_DEMCR_MON_STEP = 1U << 18 ;

  // Boolean field: DebugMonitor semaphore bit. The processor does not use this bit. The monitor software defines the meaning and use of this bit.
    static const uint32_t Debug_DEMCR_MON_REQ = 1U << 19 ;

  // Boolean field: Global enable for all DWT and ITM features.
    static const uint32_t Debug_DEMCR_TRCENA = 1U << 24 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral DWT
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Control Register
#define DWT_CTRL (* ((volatile uint32_t *) (0xE0001000 + 0)))

  // Field (width: 4 bits): Number of comparators
    inline uint32_t DWT_CTRL_NUMCOMP (const uint32_t inValue) { return (inValue & 15) << 28 ; }

  // Boolean field: No trace sampling and exception tracing
    static const uint32_t DWT_CTRL_NOTRCPKT = 1U << 27 ;

  // Boolean field: No external match signals
    static const uint32_t DWT_CTRL_NOEXTTRIG = 1U << 26 ;

  // Boolean field: No cycle counter
    static const uint32_t DWT_CTRL_NOCYCCNT = 1U << 25 ;

  // Boolean field: No profiling counters
    static const uint32_t DWT_CTRL_NOPRFCNT = 1U << 24 ;

  // Boolean field: Reserved bit 23
    static const uint32_t DWT_CTRL_Reserved_23 = 1U << 23 ;

  // Boolean field: enable Cycle count event
    static const uint32_t DWT_CTRL_CYCEVTENA = 1U << 22 ;

  // Boolean field: enable Folded instruction count event
    static const uint32_t DWT_CTRL_FOLDEVTENA = 1U << 21 ;

  // Boolean field: enable Load Store Unit (LSU) count event
    static const uint32_t DWT_CTRL_LSUEVTENA = 1U << 20 ;

  // Boolean field: enable Sleep count event
    static const uint32_t DWT_CTRL_SLEEPEVTENA = 1U << 19 ;

  // Boolean field: enable interrupt overhead event
    static const uint32_t DWT_CTRL_EXCEVTENA = 1U << 18 ;

  // Boolean field: enable CPI count event
    static const uint32_t DWT_CTRL_CPIEVTENA = 1U << 17 ;

  // Boolean field: enable interrupt event tracing
    static const uint32_t DWT_CTRL_EXCTRCENA = 1U << 16 ;

  // Field (width: 3 bits): Reserved bits 13..15
    inline uint32_t DWT_CTRL_Reserved_13_15 (const uint32_t inValue) { return (inValue & 7) << 13 ; }

  // Boolean field: enable POSTCNT as timer for PC sample packets
    static const uint32_t DWT_CTRL_PCSAMPLENA = 1U << 12 ;

  // Field (width: 2 bits): ???
    inline uint32_t DWT_CTRL_SYNCTAP (const uint32_t inValue) { return (inValue & 3) << 10 ; }

  // Boolean field: ???
    static const uint32_t DWT_CTRL_CYCTAP = 1U << 9 ;

  // Field (width: 4 bits): ???
    inline uint32_t DWT_CTRL_POSTINIT (const uint32_t inValue) { return (inValue & 15) << 5 ; }

  // Field (width: 4 bits): ???
    inline uint32_t DWT_CTRL_POSTPRESET (const uint32_t inValue) { return (inValue & 15) << 1 ; }

  // Boolean field: enable cycle counter
    static const uint32_t DWT_CTRL_CYCCNTENA = 1U << 0 ;

//-------------------- Cycle Count Register
#define DWT_CYCCNT (* ((volatile uint32_t *) (0xE0001000 + 4)))

//-------------------- CPI Count Register
#define DWT_CPICNT (* ((volatile uint32_t *) (0xE0001000 + 8)))

//-------------------- Exception Overhead Count Register
#define DWT_EXCCNT (* ((volatile uint32_t *) (0xE0001000 + 0xC)))

//-------------------- Sleep Count Register
#define DWT_SLEEPCNT (* ((volatile uint32_t *) (0xE0001000 + 0x10)))

//-------------------- LSU Count Register
#define DWT_LSUCNT (* ((volatile uint32_t *) (0xE0001000 + 0x14)))

//-------------------- Folded-instruction Count Register
#define DWT_FOLDCNT (* ((volatile uint32_t *) (0xE0001000 + 0x18)))

//-------------------- Program Counter Sample Register
#define DWT_PCSR (* ((const volatile uint32_t *) (0xE0001000 + 0x1C)))

//-------------------- Comparator Register 0
#define DWT_COMP0 (* ((volatile uint32_t *) (0xE0001000 + 0x20)))

//-------------------- Mask Register 0
#define DWT_MASK0 (* ((volatile uint32_t *) (0xE0001000 + 0x24)))

//-------------------- Function Register 0
#define DWT_FUNCTION0 (* ((volatile uint32_t *) (0xE0001000 + 0x28)))

//-------------------- Comparator Register 1
#define DWT_COMP1 (* ((volatile uint32_t *) (0xE0001000 + 0x30)))

//-------------------- Mask Register 1
#define DWT_MASK1 (* ((volatile uint32_t *) (0xE0001000 + 0x34)))

//-------------------- Function Register 1
#define DWT_FUNCTION1 (* ((volatile uint32_t *) (0xE0001000 + 0x38)))

//-------------------- Comparator Register 2
#define DWT_COMP2 (* ((volatile uint32_t *) (0xE0001000 + 0x40)))

//-------------------- Mask Register 2
#define DWT_MASK2 (* ((volatile uint32_t *) (0xE0001000 + 0x44)))

//-------------------- Function Register 2
#define DWT_FUNCTION2 (* ((volatile uint32_t *) (0xE0001000 + 0x48)))

//-------------------- Comparator Register 3
#define DWT_COMP3 (* ((volatile uint32_t *) (0xE0001000 + 0x50)))

//-------------------- Mask Register 3
#define DWT_MASK3 (* ((volatile uint32_t *) (0xE0001000 + 0x54)))

//-------------------- Function Register 3
#define DWT_FUNCTION3 (* ((volatile uint32_t *) (0xE0001000 + 0x58)))

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral SYST
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- SysTick Control and Status
#define SYST_CSR (* ((volatile uint32_t *) (0xE000E000 + 0x10)))

  // Boolean field: Enable the Counter
    static const uint32_t SYST_CSR_ENABLE = 1U << 0 ;

  // Boolean field: Enables SysTick exception request
    static const uint32_t SYST_CSR_TICKINT = 1U << 1 ;

  // Boolean field: Clock Source Selection
    static const uint32_t SYST_CSR_CLKSOURCE = 1U << 2 ;

  // Boolean field: Returns 1 if timer counted to 0 since last time this was read
    static const uint32_t SYST_CSR_COUNTFLAG = 1U << 16 ;

//-------------------- SysTick Reload Value Register
#define SYST_RVR (* ((volatile uint32_t *) (0xE000E000 + 0x14)))

//-------------------- SysTick Current Value Register
#define SYST_CVR (* ((volatile uint32_t *) (0xE000E000 + 0x18)))

//-------------------- SysTick Calibration Value Register
#define SYST_CALIB (* ((const volatile uint32_t *) (0xE000E000 + 0x1C)))

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
