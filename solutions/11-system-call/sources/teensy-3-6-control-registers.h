#pragma once

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <stdint.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral FTFE_FlashConfig
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Backdoor Comparison Key 3.
#define FTFE_FlashConfig_BACKKEY3 (* ((const volatile uint8_t *) (0x400 + 0)))

//-------------------- Backdoor Comparison Key 2.
#define FTFE_FlashConfig_BACKKEY2 (* ((const volatile uint8_t *) (0x400 + 0x1)))

//-------------------- Backdoor Comparison Key 1.
#define FTFE_FlashConfig_BACKKEY1 (* ((const volatile uint8_t *) (0x400 + 0x2)))

//-------------------- Backdoor Comparison Key 0.
#define FTFE_FlashConfig_BACKKEY0 (* ((const volatile uint8_t *) (0x400 + 0x3)))

//-------------------- Backdoor Comparison Key 7.
#define FTFE_FlashConfig_BACKKEY7 (* ((const volatile uint8_t *) (0x400 + 0x4)))

//-------------------- Backdoor Comparison Key 6.
#define FTFE_FlashConfig_BACKKEY6 (* ((const volatile uint8_t *) (0x400 + 0x5)))

//-------------------- Backdoor Comparison Key 5.
#define FTFE_FlashConfig_BACKKEY5 (* ((const volatile uint8_t *) (0x400 + 0x6)))

//-------------------- Backdoor Comparison Key 4.
#define FTFE_FlashConfig_BACKKEY4 (* ((const volatile uint8_t *) (0x400 + 0x7)))

//-------------------- Non-volatile P-Flash Protection 1 - Low Register
#define FTFE_FlashConfig_FPROT3 (* ((const volatile uint8_t *) (0x400 + 0x8)))

//-------------------- Non-volatile P-Flash Protection 1 - High Register
#define FTFE_FlashConfig_FPROT2 (* ((const volatile uint8_t *) (0x400 + 0x9)))

//-------------------- Non-volatile P-Flash Protection 0 - Low Register
#define FTFE_FlashConfig_FPROT1 (* ((const volatile uint8_t *) (0x400 + 0xA)))

//-------------------- Non-volatile P-Flash Protection 0 - High Register
#define FTFE_FlashConfig_FPROT0 (* ((const volatile uint8_t *) (0x400 + 0xB)))

//-------------------- Non-volatile Flash Security Register
#define FTFE_FlashConfig_FSEC (* ((const volatile uint8_t *) (0x400 + 0xC)))

  // Field (width: 2 bits): Flash Security
    inline uint8_t FTFE_FlashConfig_FSEC_SEC (const uint8_t inValue) { return (inValue & 3U) << 0 ; }

  // Field (width: 2 bits): Freescale Failure Analysis Access Code
    inline uint8_t FTFE_FlashConfig_FSEC_FSLACC (const uint8_t inValue) { return (inValue & 3U) << 2 ; }

  // Field (width: 2 bits): no description available
    inline uint8_t FTFE_FlashConfig_FSEC_MEEN (const uint8_t inValue) { return (inValue & 3U) << 4 ; }

  // Field (width: 2 bits): Backdoor Key Security Enable
    inline uint8_t FTFE_FlashConfig_FSEC_KEYEN (const uint8_t inValue) { return (inValue & 3U) << 6 ; }

//-------------------- Non-volatile Flash Option Register
#define FTFE_FlashConfig_FOPT (* ((const volatile uint8_t *) (0x400 + 0xD)))

  // Boolean field: no description available
    static const uint8_t FTFE_FlashConfig_FOPT_LPBOOT = 1U << 0 ;

  // Boolean field: no description available
    static const uint8_t FTFE_FlashConfig_FOPT_EZPORT_DIS = 1U << 1 ;

  // Boolean field: no description available
    static const uint8_t FTFE_FlashConfig_FOPT_NMI_DIS = 1U << 2 ;

//-------------------- Non-volatile EERAM Protection Register
#define FTFE_FlashConfig_FEPROT (* ((const volatile uint8_t *) (0x400 + 0xE)))

//-------------------- Non-volatile D-Flash Protection Register
#define FTFE_FlashConfig_FDPROT (* ((const volatile uint8_t *) (0x400 + 0xF)))

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral AXBS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Priority Registers Slave (idx = 0 ... 4)
#define AXBS_PRS(idx) (* ((volatile uint32_t *) (0x40004000 + 0 + 0x100 * (idx))))

  // Field (width: 3 bits): Master 0 Priority. Sets the arbitration priority for this port on the associated slave port.
    inline uint32_t AXBS_PRS_M0 (const uint32_t inValue) { return (inValue & 7U) << 0 ; }

  // Field (width: 3 bits): Master 1 Priority. Sets the arbitration priority for this port on the associated slave port.
    inline uint32_t AXBS_PRS_M1 (const uint32_t inValue) { return (inValue & 7U) << 4 ; }

  // Field (width: 3 bits): Master 2 Priority. Sets the arbitration priority for this port on the associated slave port.
    inline uint32_t AXBS_PRS_M2 (const uint32_t inValue) { return (inValue & 7U) << 8 ; }

  // Field (width: 3 bits): Master 3 Priority. Sets the arbitration priority for this port on the associated slave port.
    inline uint32_t AXBS_PRS_M3 (const uint32_t inValue) { return (inValue & 7U) << 12 ; }

  // Field (width: 3 bits): Master 4 Priority. Sets the arbitration priority for this port on the associated slave port.
    inline uint32_t AXBS_PRS_M4 (const uint32_t inValue) { return (inValue & 7U) << 16 ; }

  // Field (width: 3 bits): Master 5 Priority. Sets the arbitration priority for this port on the associated slave port.
    inline uint32_t AXBS_PRS_M5 (const uint32_t inValue) { return (inValue & 7U) << 20 ; }

  // Field (width: 3 bits): Master 6 Priority. Sets the arbitration priority for this port on the associated slave port.
    inline uint32_t AXBS_PRS_M6 (const uint32_t inValue) { return (inValue & 7U) << 24 ; }

//-------------------- Control Register (idx = 0 ... 4)
#define AXBS_CRS(idx) (* ((volatile uint32_t *) (0x40004000 + 0x10 + 0x100 * (idx))))

  // Field (width: 3 bits): Park
    inline uint32_t AXBS_CRS_PARK (const uint32_t inValue) { return (inValue & 7U) << 0 ; }

  // Field (width: 2 bits): Parking Control
    inline uint32_t AXBS_CRS_PCTL (const uint32_t inValue) { return (inValue & 3U) << 4 ; }

  // Field (width: 2 bits): Arbitration Mode
    inline uint32_t AXBS_CRS_ARB (const uint32_t inValue) { return (inValue & 3U) << 8 ; }

  // Boolean field: Halt Low Priority
    static const uint32_t AXBS_CRS_HLP = 1U << 30 ;

  // Boolean field: Read Only
    static const uint32_t AXBS_CRS_RO = 1U << 31 ;

//-------------------- Master General Purpose Control Register (idx = 0 ... 6)
#define AXBS_MGPCR(idx) (* ((volatile uint32_t *) (0x40004000 + 0x800 + 0x100 * (idx))))

  // Field (width: 3 bits): Arbitrates On Undefined Length Bursts
    inline uint32_t AXBS_MGPCR_AULB (const uint32_t inValue) { return (inValue & 7U) << 0 ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral DMA
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Control Register
#define DMA_CR (* ((volatile uint32_t *) (0x40008000 + 0)))

  // Boolean field: Enable Debug
    static const uint32_t DMA_CR_EDBG = 1U << 1 ;

  // Boolean field: Enable Round Robin Channel Arbitration
    static const uint32_t DMA_CR_ERCA = 1U << 2 ;

  // Boolean field: Enable Round Robin Group Arbitration
    static const uint32_t DMA_CR_ERGA = 1U << 3 ;

  // Boolean field: Halt On Error
    static const uint32_t DMA_CR_HOE = 1U << 4 ;

  // Boolean field: Halt DMA Operations
    static const uint32_t DMA_CR_HALT = 1U << 5 ;

  // Boolean field: Continuous Link Mode
    static const uint32_t DMA_CR_CLM = 1U << 6 ;

  // Boolean field: Enable Minor Loop Mapping
    static const uint32_t DMA_CR_EMLM = 1U << 7 ;

  // Boolean field: Channel Group 0 Priority
    static const uint32_t DMA_CR_GRP0PRI = 1U << 8 ;

  // Boolean field: Channel Group 1 Priority
    static const uint32_t DMA_CR_GRP1PRI = 1U << 10 ;

  // Boolean field: Error Cancel Transfer
    static const uint32_t DMA_CR_ECX = 1U << 16 ;

  // Boolean field: Cancel Transfer
    static const uint32_t DMA_CR_CX = 1U << 17 ;

//-------------------- Error Status Register
#define DMA_ES (* ((const volatile uint32_t *) (0x40008000 + 0x4)))

  // Boolean field: Destination Bus Error
    static const uint32_t DMA_ES_DBE = 1U << 0 ;

  // Boolean field: Source Bus Error
    static const uint32_t DMA_ES_SBE = 1U << 1 ;

  // Boolean field: Scatter/Gather Configuration Error
    static const uint32_t DMA_ES_SGE = 1U << 2 ;

  // Boolean field: NBYTES/CITER Configuration Error
    static const uint32_t DMA_ES_NCE = 1U << 3 ;

  // Boolean field: Destination Offset Error
    static const uint32_t DMA_ES_DOE = 1U << 4 ;

  // Boolean field: Destination Address Error
    static const uint32_t DMA_ES_DAE = 1U << 5 ;

  // Boolean field: Source Offset Error
    static const uint32_t DMA_ES_SOE = 1U << 6 ;

  // Boolean field: Source Address Error
    static const uint32_t DMA_ES_SAE = 1U << 7 ;

  // Field (width: 5 bits): Error Channel Number or Canceled Channel Number
    inline uint32_t DMA_ES_ERRCHN (const uint32_t inValue) { return (inValue & 31U) << 8 ; }

  // Boolean field: Channel Priority Error
    static const uint32_t DMA_ES_CPE = 1U << 14 ;

  // Boolean field: Group Priority Error
    static const uint32_t DMA_ES_GPE = 1U << 15 ;

  // Boolean field: Transfer Canceled
    static const uint32_t DMA_ES_ECX = 1U << 16 ;

  // Boolean field: Logical OR of all ERR status bits
    static const uint32_t DMA_ES_VLD = 1U << 31 ;

//-------------------- Enable Request Register
#define DMA_ERQ (* ((volatile uint32_t *) (0x40008000 + 0xC)))

  // Boolean field: Enable DMA Request 0
    static const uint32_t DMA_ERQ_ERQ0 = 1U << 0 ;

  // Boolean field: Enable DMA Request 1
    static const uint32_t DMA_ERQ_ERQ1 = 1U << 1 ;

  // Boolean field: Enable DMA Request 2
    static const uint32_t DMA_ERQ_ERQ2 = 1U << 2 ;

  // Boolean field: Enable DMA Request 3
    static const uint32_t DMA_ERQ_ERQ3 = 1U << 3 ;

  // Boolean field: Enable DMA Request 4
    static const uint32_t DMA_ERQ_ERQ4 = 1U << 4 ;

  // Boolean field: Enable DMA Request 5
    static const uint32_t DMA_ERQ_ERQ5 = 1U << 5 ;

  // Boolean field: Enable DMA Request 6
    static const uint32_t DMA_ERQ_ERQ6 = 1U << 6 ;

  // Boolean field: Enable DMA Request 7
    static const uint32_t DMA_ERQ_ERQ7 = 1U << 7 ;

  // Boolean field: Enable DMA Request 8
    static const uint32_t DMA_ERQ_ERQ8 = 1U << 8 ;

  // Boolean field: Enable DMA Request 9
    static const uint32_t DMA_ERQ_ERQ9 = 1U << 9 ;

  // Boolean field: Enable DMA Request 10
    static const uint32_t DMA_ERQ_ERQ10 = 1U << 10 ;

  // Boolean field: Enable DMA Request 11
    static const uint32_t DMA_ERQ_ERQ11 = 1U << 11 ;

  // Boolean field: Enable DMA Request 12
    static const uint32_t DMA_ERQ_ERQ12 = 1U << 12 ;

  // Boolean field: Enable DMA Request 13
    static const uint32_t DMA_ERQ_ERQ13 = 1U << 13 ;

  // Boolean field: Enable DMA Request 14
    static const uint32_t DMA_ERQ_ERQ14 = 1U << 14 ;

  // Boolean field: Enable DMA Request 15
    static const uint32_t DMA_ERQ_ERQ15 = 1U << 15 ;

  // Boolean field: Enable DMA Request 16
    static const uint32_t DMA_ERQ_ERQ16 = 1U << 16 ;

  // Boolean field: Enable DMA Request 17
    static const uint32_t DMA_ERQ_ERQ17 = 1U << 17 ;

  // Boolean field: Enable DMA Request 18
    static const uint32_t DMA_ERQ_ERQ18 = 1U << 18 ;

  // Boolean field: Enable DMA Request 19
    static const uint32_t DMA_ERQ_ERQ19 = 1U << 19 ;

  // Boolean field: Enable DMA Request 20
    static const uint32_t DMA_ERQ_ERQ20 = 1U << 20 ;

  // Boolean field: Enable DMA Request 21
    static const uint32_t DMA_ERQ_ERQ21 = 1U << 21 ;

  // Boolean field: Enable DMA Request 22
    static const uint32_t DMA_ERQ_ERQ22 = 1U << 22 ;

  // Boolean field: Enable DMA Request 23
    static const uint32_t DMA_ERQ_ERQ23 = 1U << 23 ;

  // Boolean field: Enable DMA Request 24
    static const uint32_t DMA_ERQ_ERQ24 = 1U << 24 ;

  // Boolean field: Enable DMA Request 25
    static const uint32_t DMA_ERQ_ERQ25 = 1U << 25 ;

  // Boolean field: Enable DMA Request 26
    static const uint32_t DMA_ERQ_ERQ26 = 1U << 26 ;

  // Boolean field: Enable DMA Request 27
    static const uint32_t DMA_ERQ_ERQ27 = 1U << 27 ;

  // Boolean field: Enable DMA Request 28
    static const uint32_t DMA_ERQ_ERQ28 = 1U << 28 ;

  // Boolean field: Enable DMA Request 29
    static const uint32_t DMA_ERQ_ERQ29 = 1U << 29 ;

  // Boolean field: Enable DMA Request 30
    static const uint32_t DMA_ERQ_ERQ30 = 1U << 30 ;

  // Boolean field: Enable DMA Request 31
    static const uint32_t DMA_ERQ_ERQ31 = 1U << 31 ;

//-------------------- Enable Error Interrupt Register
#define DMA_EEI (* ((volatile uint32_t *) (0x40008000 + 0x14)))

  // Boolean field: Enable Error Interrupt 0
    static const uint32_t DMA_EEI_EEI0 = 1U << 0 ;

  // Boolean field: Enable Error Interrupt 1
    static const uint32_t DMA_EEI_EEI1 = 1U << 1 ;

  // Boolean field: Enable Error Interrupt 2
    static const uint32_t DMA_EEI_EEI2 = 1U << 2 ;

  // Boolean field: Enable Error Interrupt 3
    static const uint32_t DMA_EEI_EEI3 = 1U << 3 ;

  // Boolean field: Enable Error Interrupt 4
    static const uint32_t DMA_EEI_EEI4 = 1U << 4 ;

  // Boolean field: Enable Error Interrupt 5
    static const uint32_t DMA_EEI_EEI5 = 1U << 5 ;

  // Boolean field: Enable Error Interrupt 6
    static const uint32_t DMA_EEI_EEI6 = 1U << 6 ;

  // Boolean field: Enable Error Interrupt 7
    static const uint32_t DMA_EEI_EEI7 = 1U << 7 ;

  // Boolean field: Enable Error Interrupt 8
    static const uint32_t DMA_EEI_EEI8 = 1U << 8 ;

  // Boolean field: Enable Error Interrupt 9
    static const uint32_t DMA_EEI_EEI9 = 1U << 9 ;

  // Boolean field: Enable Error Interrupt 10
    static const uint32_t DMA_EEI_EEI10 = 1U << 10 ;

  // Boolean field: Enable Error Interrupt 11
    static const uint32_t DMA_EEI_EEI11 = 1U << 11 ;

  // Boolean field: Enable Error Interrupt 12
    static const uint32_t DMA_EEI_EEI12 = 1U << 12 ;

  // Boolean field: Enable Error Interrupt 13
    static const uint32_t DMA_EEI_EEI13 = 1U << 13 ;

  // Boolean field: Enable Error Interrupt 14
    static const uint32_t DMA_EEI_EEI14 = 1U << 14 ;

  // Boolean field: Enable Error Interrupt 15
    static const uint32_t DMA_EEI_EEI15 = 1U << 15 ;

  // Boolean field: Enable Error Interrupt 16
    static const uint32_t DMA_EEI_EEI16 = 1U << 16 ;

  // Boolean field: Enable Error Interrupt 17
    static const uint32_t DMA_EEI_EEI17 = 1U << 17 ;

  // Boolean field: Enable Error Interrupt 18
    static const uint32_t DMA_EEI_EEI18 = 1U << 18 ;

  // Boolean field: Enable Error Interrupt 19
    static const uint32_t DMA_EEI_EEI19 = 1U << 19 ;

  // Boolean field: Enable Error Interrupt 20
    static const uint32_t DMA_EEI_EEI20 = 1U << 20 ;

  // Boolean field: Enable Error Interrupt 21
    static const uint32_t DMA_EEI_EEI21 = 1U << 21 ;

  // Boolean field: Enable Error Interrupt 22
    static const uint32_t DMA_EEI_EEI22 = 1U << 22 ;

  // Boolean field: Enable Error Interrupt 23
    static const uint32_t DMA_EEI_EEI23 = 1U << 23 ;

  // Boolean field: Enable Error Interrupt 24
    static const uint32_t DMA_EEI_EEI24 = 1U << 24 ;

  // Boolean field: Enable Error Interrupt 25
    static const uint32_t DMA_EEI_EEI25 = 1U << 25 ;

  // Boolean field: Enable Error Interrupt 26
    static const uint32_t DMA_EEI_EEI26 = 1U << 26 ;

  // Boolean field: Enable Error Interrupt 27
    static const uint32_t DMA_EEI_EEI27 = 1U << 27 ;

  // Boolean field: Enable Error Interrupt 28
    static const uint32_t DMA_EEI_EEI28 = 1U << 28 ;

  // Boolean field: Enable Error Interrupt 29
    static const uint32_t DMA_EEI_EEI29 = 1U << 29 ;

  // Boolean field: Enable Error Interrupt 30
    static const uint32_t DMA_EEI_EEI30 = 1U << 30 ;

  // Boolean field: Enable Error Interrupt 31
    static const uint32_t DMA_EEI_EEI31 = 1U << 31 ;

//-------------------- Clear Enable Error Interrupt Register
#define DMA_CEEI (* ((volatile uint8_t *) (0x40008000 + 0x18)))

  // Field (width: 5 bits): Clear Enable Error Interrupt
    inline uint8_t DMA_CEEI_CEEI (const uint8_t inValue) { return (inValue & 31U) << 0 ; }

  // Boolean field: Clear All Enable Error Interrupts
    static const uint8_t DMA_CEEI_CAEE = 1U << 6 ;

  // Boolean field: No Op enable
    static const uint8_t DMA_CEEI_NOP = 1U << 7 ;

//-------------------- Set Enable Error Interrupt Register
#define DMA_SEEI (* ((volatile uint8_t *) (0x40008000 + 0x19)))

  // Field (width: 5 bits): Set Enable Error Interrupt
    inline uint8_t DMA_SEEI_SEEI (const uint8_t inValue) { return (inValue & 31U) << 0 ; }

  // Boolean field: Sets All Enable Error Interrupts
    static const uint8_t DMA_SEEI_SAEE = 1U << 6 ;

  // Boolean field: No Op enable
    static const uint8_t DMA_SEEI_NOP = 1U << 7 ;

//-------------------- Clear Enable Request Register
#define DMA_CERQ (* ((volatile uint8_t *) (0x40008000 + 0x1A)))

  // Field (width: 5 bits): Clear Enable Request
    inline uint8_t DMA_CERQ_CERQ (const uint8_t inValue) { return (inValue & 31U) << 0 ; }

  // Boolean field: Clear All Enable Requests
    static const uint8_t DMA_CERQ_CAER = 1U << 6 ;

  // Boolean field: No Op enable
    static const uint8_t DMA_CERQ_NOP = 1U << 7 ;

//-------------------- Set Enable Request Register
#define DMA_SERQ (* ((volatile uint8_t *) (0x40008000 + 0x1B)))

  // Field (width: 5 bits): Set Enable Request
    inline uint8_t DMA_SERQ_SERQ (const uint8_t inValue) { return (inValue & 31U) << 0 ; }

  // Boolean field: Set All Enable Requests
    static const uint8_t DMA_SERQ_SAER = 1U << 6 ;

  // Boolean field: No Op enable
    static const uint8_t DMA_SERQ_NOP = 1U << 7 ;

//-------------------- Clear DONE Status Bit Register
#define DMA_CDNE (* ((volatile uint8_t *) (0x40008000 + 0x1C)))

  // Field (width: 5 bits): Clear DONE Bit
    inline uint8_t DMA_CDNE_CDNE (const uint8_t inValue) { return (inValue & 31U) << 0 ; }

  // Boolean field: Clears All DONE Bits
    static const uint8_t DMA_CDNE_CADN = 1U << 6 ;

  // Boolean field: No Op enable
    static const uint8_t DMA_CDNE_NOP = 1U << 7 ;

//-------------------- Set START Bit Register
#define DMA_SSRT (* ((volatile uint8_t *) (0x40008000 + 0x1D)))

  // Field (width: 5 bits): Set START Bit
    inline uint8_t DMA_SSRT_SSRT (const uint8_t inValue) { return (inValue & 31U) << 0 ; }

  // Boolean field: Set All START Bits (activates all channels)
    static const uint8_t DMA_SSRT_SAST = 1U << 6 ;

  // Boolean field: No Op enable
    static const uint8_t DMA_SSRT_NOP = 1U << 7 ;

//-------------------- Clear Error Register
#define DMA_CERR (* ((volatile uint8_t *) (0x40008000 + 0x1E)))

  // Field (width: 5 bits): Clear Error Indicator
    inline uint8_t DMA_CERR_CERR (const uint8_t inValue) { return (inValue & 31U) << 0 ; }

  // Boolean field: Clear All Error Indicators
    static const uint8_t DMA_CERR_CAEI = 1U << 6 ;

  // Boolean field: No Op enable
    static const uint8_t DMA_CERR_NOP = 1U << 7 ;

//-------------------- Clear Interrupt Request Register
#define DMA_CINT (* ((volatile uint8_t *) (0x40008000 + 0x1F)))

  // Field (width: 5 bits): Clear Interrupt Request
    inline uint8_t DMA_CINT_CINT (const uint8_t inValue) { return (inValue & 31U) << 0 ; }

  // Boolean field: Clear All Interrupt Requests
    static const uint8_t DMA_CINT_CAIR = 1U << 6 ;

  // Boolean field: No Op enable
    static const uint8_t DMA_CINT_NOP = 1U << 7 ;

//-------------------- Interrupt Request Register
#define DMA_INT (* ((volatile uint32_t *) (0x40008000 + 0x24)))

  // Boolean field: Interrupt Request 0
    static const uint32_t DMA_INT_INT0 = 1U << 0 ;

  // Boolean field: Interrupt Request 1
    static const uint32_t DMA_INT_INT1 = 1U << 1 ;

  // Boolean field: Interrupt Request 2
    static const uint32_t DMA_INT_INT2 = 1U << 2 ;

  // Boolean field: Interrupt Request 3
    static const uint32_t DMA_INT_INT3 = 1U << 3 ;

  // Boolean field: Interrupt Request 4
    static const uint32_t DMA_INT_INT4 = 1U << 4 ;

  // Boolean field: Interrupt Request 5
    static const uint32_t DMA_INT_INT5 = 1U << 5 ;

  // Boolean field: Interrupt Request 6
    static const uint32_t DMA_INT_INT6 = 1U << 6 ;

  // Boolean field: Interrupt Request 7
    static const uint32_t DMA_INT_INT7 = 1U << 7 ;

  // Boolean field: Interrupt Request 8
    static const uint32_t DMA_INT_INT8 = 1U << 8 ;

  // Boolean field: Interrupt Request 9
    static const uint32_t DMA_INT_INT9 = 1U << 9 ;

  // Boolean field: Interrupt Request 10
    static const uint32_t DMA_INT_INT10 = 1U << 10 ;

  // Boolean field: Interrupt Request 11
    static const uint32_t DMA_INT_INT11 = 1U << 11 ;

  // Boolean field: Interrupt Request 12
    static const uint32_t DMA_INT_INT12 = 1U << 12 ;

  // Boolean field: Interrupt Request 13
    static const uint32_t DMA_INT_INT13 = 1U << 13 ;

  // Boolean field: Interrupt Request 14
    static const uint32_t DMA_INT_INT14 = 1U << 14 ;

  // Boolean field: Interrupt Request 15
    static const uint32_t DMA_INT_INT15 = 1U << 15 ;

  // Boolean field: Interrupt Request 16
    static const uint32_t DMA_INT_INT16 = 1U << 16 ;

  // Boolean field: Interrupt Request 17
    static const uint32_t DMA_INT_INT17 = 1U << 17 ;

  // Boolean field: Interrupt Request 18
    static const uint32_t DMA_INT_INT18 = 1U << 18 ;

  // Boolean field: Interrupt Request 19
    static const uint32_t DMA_INT_INT19 = 1U << 19 ;

  // Boolean field: Interrupt Request 20
    static const uint32_t DMA_INT_INT20 = 1U << 20 ;

  // Boolean field: Interrupt Request 21
    static const uint32_t DMA_INT_INT21 = 1U << 21 ;

  // Boolean field: Interrupt Request 22
    static const uint32_t DMA_INT_INT22 = 1U << 22 ;

  // Boolean field: Interrupt Request 23
    static const uint32_t DMA_INT_INT23 = 1U << 23 ;

  // Boolean field: Interrupt Request 24
    static const uint32_t DMA_INT_INT24 = 1U << 24 ;

  // Boolean field: Interrupt Request 25
    static const uint32_t DMA_INT_INT25 = 1U << 25 ;

  // Boolean field: Interrupt Request 26
    static const uint32_t DMA_INT_INT26 = 1U << 26 ;

  // Boolean field: Interrupt Request 27
    static const uint32_t DMA_INT_INT27 = 1U << 27 ;

  // Boolean field: Interrupt Request 28
    static const uint32_t DMA_INT_INT28 = 1U << 28 ;

  // Boolean field: Interrupt Request 29
    static const uint32_t DMA_INT_INT29 = 1U << 29 ;

  // Boolean field: Interrupt Request 30
    static const uint32_t DMA_INT_INT30 = 1U << 30 ;

  // Boolean field: Interrupt Request 31
    static const uint32_t DMA_INT_INT31 = 1U << 31 ;

//-------------------- Error Register
#define DMA_ERR (* ((volatile uint32_t *) (0x40008000 + 0x2C)))

  // Boolean field: Error In Channel 0
    static const uint32_t DMA_ERR_ERR0 = 1U << 0 ;

  // Boolean field: Error In Channel 1
    static const uint32_t DMA_ERR_ERR1 = 1U << 1 ;

  // Boolean field: Error In Channel 2
    static const uint32_t DMA_ERR_ERR2 = 1U << 2 ;

  // Boolean field: Error In Channel 3
    static const uint32_t DMA_ERR_ERR3 = 1U << 3 ;

  // Boolean field: Error In Channel 4
    static const uint32_t DMA_ERR_ERR4 = 1U << 4 ;

  // Boolean field: Error In Channel 5
    static const uint32_t DMA_ERR_ERR5 = 1U << 5 ;

  // Boolean field: Error In Channel 6
    static const uint32_t DMA_ERR_ERR6 = 1U << 6 ;

  // Boolean field: Error In Channel 7
    static const uint32_t DMA_ERR_ERR7 = 1U << 7 ;

  // Boolean field: Error In Channel 8
    static const uint32_t DMA_ERR_ERR8 = 1U << 8 ;

  // Boolean field: Error In Channel 9
    static const uint32_t DMA_ERR_ERR9 = 1U << 9 ;

  // Boolean field: Error In Channel 10
    static const uint32_t DMA_ERR_ERR10 = 1U << 10 ;

  // Boolean field: Error In Channel 11
    static const uint32_t DMA_ERR_ERR11 = 1U << 11 ;

  // Boolean field: Error In Channel 12
    static const uint32_t DMA_ERR_ERR12 = 1U << 12 ;

  // Boolean field: Error In Channel 13
    static const uint32_t DMA_ERR_ERR13 = 1U << 13 ;

  // Boolean field: Error In Channel 14
    static const uint32_t DMA_ERR_ERR14 = 1U << 14 ;

  // Boolean field: Error In Channel 15
    static const uint32_t DMA_ERR_ERR15 = 1U << 15 ;

  // Boolean field: Error In Channel 16
    static const uint32_t DMA_ERR_ERR16 = 1U << 16 ;

  // Boolean field: Error In Channel 17
    static const uint32_t DMA_ERR_ERR17 = 1U << 17 ;

  // Boolean field: Error In Channel 18
    static const uint32_t DMA_ERR_ERR18 = 1U << 18 ;

  // Boolean field: Error In Channel 19
    static const uint32_t DMA_ERR_ERR19 = 1U << 19 ;

  // Boolean field: Error In Channel 20
    static const uint32_t DMA_ERR_ERR20 = 1U << 20 ;

  // Boolean field: Error In Channel 21
    static const uint32_t DMA_ERR_ERR21 = 1U << 21 ;

  // Boolean field: Error In Channel 22
    static const uint32_t DMA_ERR_ERR22 = 1U << 22 ;

  // Boolean field: Error In Channel 23
    static const uint32_t DMA_ERR_ERR23 = 1U << 23 ;

  // Boolean field: Error In Channel 24
    static const uint32_t DMA_ERR_ERR24 = 1U << 24 ;

  // Boolean field: Error In Channel 25
    static const uint32_t DMA_ERR_ERR25 = 1U << 25 ;

  // Boolean field: Error In Channel 26
    static const uint32_t DMA_ERR_ERR26 = 1U << 26 ;

  // Boolean field: Error In Channel 27
    static const uint32_t DMA_ERR_ERR27 = 1U << 27 ;

  // Boolean field: Error In Channel 28
    static const uint32_t DMA_ERR_ERR28 = 1U << 28 ;

  // Boolean field: Error In Channel 29
    static const uint32_t DMA_ERR_ERR29 = 1U << 29 ;

  // Boolean field: Error In Channel 30
    static const uint32_t DMA_ERR_ERR30 = 1U << 30 ;

  // Boolean field: Error In Channel 31
    static const uint32_t DMA_ERR_ERR31 = 1U << 31 ;

//-------------------- Hardware Request Status Register
#define DMA_HRS (* ((const volatile uint32_t *) (0x40008000 + 0x34)))

  // Boolean field: Hardware Request Status Channel 0
    static const uint32_t DMA_HRS_HRS0 = 1U << 0 ;

  // Boolean field: Hardware Request Status Channel 1
    static const uint32_t DMA_HRS_HRS1 = 1U << 1 ;

  // Boolean field: Hardware Request Status Channel 2
    static const uint32_t DMA_HRS_HRS2 = 1U << 2 ;

  // Boolean field: Hardware Request Status Channel 3
    static const uint32_t DMA_HRS_HRS3 = 1U << 3 ;

  // Boolean field: Hardware Request Status Channel 4
    static const uint32_t DMA_HRS_HRS4 = 1U << 4 ;

  // Boolean field: Hardware Request Status Channel 5
    static const uint32_t DMA_HRS_HRS5 = 1U << 5 ;

  // Boolean field: Hardware Request Status Channel 6
    static const uint32_t DMA_HRS_HRS6 = 1U << 6 ;

  // Boolean field: Hardware Request Status Channel 7
    static const uint32_t DMA_HRS_HRS7 = 1U << 7 ;

  // Boolean field: Hardware Request Status Channel 8
    static const uint32_t DMA_HRS_HRS8 = 1U << 8 ;

  // Boolean field: Hardware Request Status Channel 9
    static const uint32_t DMA_HRS_HRS9 = 1U << 9 ;

  // Boolean field: Hardware Request Status Channel 10
    static const uint32_t DMA_HRS_HRS10 = 1U << 10 ;

  // Boolean field: Hardware Request Status Channel 11
    static const uint32_t DMA_HRS_HRS11 = 1U << 11 ;

  // Boolean field: Hardware Request Status Channel 12
    static const uint32_t DMA_HRS_HRS12 = 1U << 12 ;

  // Boolean field: Hardware Request Status Channel 13
    static const uint32_t DMA_HRS_HRS13 = 1U << 13 ;

  // Boolean field: Hardware Request Status Channel 14
    static const uint32_t DMA_HRS_HRS14 = 1U << 14 ;

  // Boolean field: Hardware Request Status Channel 15
    static const uint32_t DMA_HRS_HRS15 = 1U << 15 ;

  // Boolean field: Hardware Request Status Channel 16
    static const uint32_t DMA_HRS_HRS16 = 1U << 16 ;

  // Boolean field: Hardware Request Status Channel 17
    static const uint32_t DMA_HRS_HRS17 = 1U << 17 ;

  // Boolean field: Hardware Request Status Channel 18
    static const uint32_t DMA_HRS_HRS18 = 1U << 18 ;

  // Boolean field: Hardware Request Status Channel 19
    static const uint32_t DMA_HRS_HRS19 = 1U << 19 ;

  // Boolean field: Hardware Request Status Channel 20
    static const uint32_t DMA_HRS_HRS20 = 1U << 20 ;

  // Boolean field: Hardware Request Status Channel 21
    static const uint32_t DMA_HRS_HRS21 = 1U << 21 ;

  // Boolean field: Hardware Request Status Channel 22
    static const uint32_t DMA_HRS_HRS22 = 1U << 22 ;

  // Boolean field: Hardware Request Status Channel 23
    static const uint32_t DMA_HRS_HRS23 = 1U << 23 ;

  // Boolean field: Hardware Request Status Channel 24
    static const uint32_t DMA_HRS_HRS24 = 1U << 24 ;

  // Boolean field: Hardware Request Status Channel 25
    static const uint32_t DMA_HRS_HRS25 = 1U << 25 ;

  // Boolean field: Hardware Request Status Channel 26
    static const uint32_t DMA_HRS_HRS26 = 1U << 26 ;

  // Boolean field: Hardware Request Status Channel 27
    static const uint32_t DMA_HRS_HRS27 = 1U << 27 ;

  // Boolean field: Hardware Request Status Channel 28
    static const uint32_t DMA_HRS_HRS28 = 1U << 28 ;

  // Boolean field: Hardware Request Status Channel 29
    static const uint32_t DMA_HRS_HRS29 = 1U << 29 ;

  // Boolean field: Hardware Request Status Channel 30
    static const uint32_t DMA_HRS_HRS30 = 1U << 30 ;

  // Boolean field: Hardware Request Status Channel 31
    static const uint32_t DMA_HRS_HRS31 = 1U << 31 ;

//-------------------- Enable Asynchronous Request in Stop Register
#define DMA_EARS (* ((volatile uint32_t *) (0x40008000 + 0x44)))

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 0.
    static const uint32_t DMA_EARS_EDREQ_0 = 1U << 0 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 1.
    static const uint32_t DMA_EARS_EDREQ_1 = 1U << 1 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 2.
    static const uint32_t DMA_EARS_EDREQ_2 = 1U << 2 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 3.
    static const uint32_t DMA_EARS_EDREQ_3 = 1U << 3 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 4
    static const uint32_t DMA_EARS_EDREQ_4 = 1U << 4 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 5
    static const uint32_t DMA_EARS_EDREQ_5 = 1U << 5 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 6
    static const uint32_t DMA_EARS_EDREQ_6 = 1U << 6 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 7
    static const uint32_t DMA_EARS_EDREQ_7 = 1U << 7 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 8
    static const uint32_t DMA_EARS_EDREQ_8 = 1U << 8 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 9
    static const uint32_t DMA_EARS_EDREQ_9 = 1U << 9 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 10
    static const uint32_t DMA_EARS_EDREQ_10 = 1U << 10 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 11
    static const uint32_t DMA_EARS_EDREQ_11 = 1U << 11 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 12
    static const uint32_t DMA_EARS_EDREQ_12 = 1U << 12 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 13
    static const uint32_t DMA_EARS_EDREQ_13 = 1U << 13 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 14
    static const uint32_t DMA_EARS_EDREQ_14 = 1U << 14 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 15
    static const uint32_t DMA_EARS_EDREQ_15 = 1U << 15 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 16
    static const uint32_t DMA_EARS_EDREQ_16 = 1U << 16 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 17
    static const uint32_t DMA_EARS_EDREQ_17 = 1U << 17 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 18
    static const uint32_t DMA_EARS_EDREQ_18 = 1U << 18 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 19
    static const uint32_t DMA_EARS_EDREQ_19 = 1U << 19 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 20
    static const uint32_t DMA_EARS_EDREQ_20 = 1U << 20 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 21
    static const uint32_t DMA_EARS_EDREQ_21 = 1U << 21 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 22
    static const uint32_t DMA_EARS_EDREQ_22 = 1U << 22 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 23
    static const uint32_t DMA_EARS_EDREQ_23 = 1U << 23 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 24
    static const uint32_t DMA_EARS_EDREQ_24 = 1U << 24 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 25
    static const uint32_t DMA_EARS_EDREQ_25 = 1U << 25 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 26
    static const uint32_t DMA_EARS_EDREQ_26 = 1U << 26 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 27
    static const uint32_t DMA_EARS_EDREQ_27 = 1U << 27 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 28
    static const uint32_t DMA_EARS_EDREQ_28 = 1U << 28 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 29
    static const uint32_t DMA_EARS_EDREQ_29 = 1U << 29 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 30
    static const uint32_t DMA_EARS_EDREQ_30 = 1U << 30 ;

  // Boolean field: Enable asynchronous DMA request in stop mode for channel 31
    static const uint32_t DMA_EARS_EDREQ_31 = 1U << 31 ;

//-------------------- Channel n Priority Register (idx = 0 ... 31)
#define DMA_DCHPRI(idx) (* ((volatile uint8_t *) (0x40008000 + 0x100 + 0x1 * (idx))))

  // Field (width: 4 bits): Channel n Arbitration Priority
    inline uint8_t DMA_DCHPRI_CHPRI (const uint8_t inValue) { return (inValue & 15U) << 0 ; }

  // Field (width: 2 bits): Channel n Current Group Priority
    inline uint8_t DMA_DCHPRI_GRPPRI (const uint8_t inValue) { return (inValue & 3U) << 4 ; }

  // Boolean field: Disable Preempt Ability.
    static const uint8_t DMA_DCHPRI_DPA = 1U << 6 ;

  // Boolean field: Enable Channel Preemption.
    static const uint8_t DMA_DCHPRI_ECP = 1U << 7 ;

//-------------------- TCD Source Address (idx = 0 ... 31)
#define DMA_TCD_SADDR(idx) (* ((volatile uint32_t *) (0x40008000 + 0x1000 + 0x20 * (idx))))

//-------------------- TCD Signed Source Address Offset (idx = 0 ... 31)
#define DMA_TCD_SOFF(idx) (* ((volatile uint16_t *) (0x40008000 + 0x1004 + 0x20 * (idx))))

//-------------------- TCD Transfer Attributes (idx = 0 ... 31)
#define DMA_TCD_ATTR(idx) (* ((volatile uint16_t *) (0x40008000 + 0x1006 + 0x20 * (idx))))

  // Field (width: 3 bits): Destination data transfer size
    inline uint16_t DMA_TCD_ATTR_DSIZE (const uint16_t inValue) { return (inValue & 7U) << 0 ; }

  // Field (width: 5 bits): Destination Address Modulo
    inline uint16_t DMA_TCD_ATTR_DMOD (const uint16_t inValue) { return (inValue & 31U) << 3 ; }

  // Field (width: 3 bits): Source data transfer size
    inline uint16_t DMA_TCD_ATTR_SSIZE (const uint16_t inValue) { return (inValue & 7U) << 8 ; }

  // Field (width: 5 bits): Source Address Modulo
    inline uint16_t DMA_TCD_ATTR_SMOD (const uint16_t inValue) { return (inValue & 31U) << 11 ; }

//-------------------- TCD Minor Byte Count (Minor Loop Mapping Disabled) (idx = 0 ... 31)
#define DMA_TCD_NBYTES_MLNO(idx) (* ((volatile uint32_t *) (0x40008000 + 0x1008 + 0x20 * (idx))))

//-------------------- TCD Signed Minor Loop Offset (Minor Loop Mapping Enabled and Offset Disabled) (idx = 0 ... 31)
#define DMA_TCD_NBYTES_MLOFFNO(idx) (* ((volatile uint32_t *) (0x40008000 + 0x1008 + 0x20 * (idx))))

  // Field (width: 30 bits): Minor Byte Transfer Count
    inline uint32_t DMA_TCD_NBYTES_MLOFFNO_NBYTES (const uint32_t inValue) { return (inValue & 1073741823U) << 0 ; }

  // Boolean field: Destination Minor Loop Offset enable
    static const uint32_t DMA_TCD_NBYTES_MLOFFNO_DMLOE = 1U << 30 ;

  // Boolean field: Source Minor Loop Offset Enable
    static const uint32_t DMA_TCD_NBYTES_MLOFFNO_SMLOE = 1U << 31 ;

//-------------------- TCD Signed Minor Loop Offset (Minor Loop Mapping and Offset Enabled) (idx = 0 ... 31)
#define DMA_TCD_NBYTES_MLOFFYES(idx) (* ((volatile uint32_t *) (0x40008000 + 0x1008 + 0x20 * (idx))))

  // Field (width: 10 bits): Minor Byte Transfer Count
    inline uint32_t DMA_TCD_NBYTES_MLOFFYES_NBYTES (const uint32_t inValue) { return (inValue & 1023U) << 0 ; }

  // Field (width: 20 bits): If SMLOE or DMLOE is set, this field represents a sign-extended offset applied to the source or destination address to form the next-state value after the minor loop completes.
    inline uint32_t DMA_TCD_NBYTES_MLOFFYES_MLOFF (const uint32_t inValue) { return (inValue & 1048575U) << 10 ; }

  // Boolean field: Destination Minor Loop Offset enable
    static const uint32_t DMA_TCD_NBYTES_MLOFFYES_DMLOE = 1U << 30 ;

  // Boolean field: Source Minor Loop Offset Enable
    static const uint32_t DMA_TCD_NBYTES_MLOFFYES_SMLOE = 1U << 31 ;

//-------------------- TCD Last Source Address Adjustment (idx = 0 ... 31)
#define DMA_TCD_SLAST(idx) (* ((volatile uint32_t *) (0x40008000 + 0x100C + 0x20 * (idx))))

//-------------------- TCD Destination Address (idx = 0 ... 31)
#define DMA_TCD_DADDR(idx) (* ((volatile uint32_t *) (0x40008000 + 0x1010 + 0x20 * (idx))))

//-------------------- TCD Signed Destination Address Offset (idx = 0 ... 31)
#define DMA_TCD_DOFF(idx) (* ((volatile uint16_t *) (0x40008000 + 0x1014 + 0x20 * (idx))))

//-------------------- TCD Current Minor Loop Link, Major Loop Count (Channel Linking Disabled) (idx = 0 ... 31)
#define DMA_TCD_CITER_ELINKNO(idx) (* ((volatile uint16_t *) (0x40008000 + 0x1016 + 0x20 * (idx))))

  // Field (width: 15 bits): Current Major Iteration Count
    inline uint16_t DMA_TCD_CITER_ELINKNO_CITER (const uint16_t inValue) { return (inValue & 32767U) << 0 ; }

  // Boolean field: Enable channel-to-channel linking on minor-loop complete
    static const uint16_t DMA_TCD_CITER_ELINKNO_ELINK = 1U << 15 ;

//-------------------- TCD Current Minor Loop Link, Major Loop Count (Channel Linking Enabled) (idx = 0 ... 31)
#define DMA_TCD_CITER_ELINKYES(idx) (* ((volatile uint16_t *) (0x40008000 + 0x1016 + 0x20 * (idx))))

  // Field (width: 9 bits): Current Major Iteration Count
    inline uint16_t DMA_TCD_CITER_ELINKYES_CITER (const uint16_t inValue) { return (inValue & 511U) << 0 ; }

  // Field (width: 5 bits): Minor Loop Link Channel Number
    inline uint16_t DMA_TCD_CITER_ELINKYES_LINKCH (const uint16_t inValue) { return (inValue & 31U) << 9 ; }

  // Boolean field: Enable channel-to-channel linking on minor-loop complete
    static const uint16_t DMA_TCD_CITER_ELINKYES_ELINK = 1U << 15 ;

//-------------------- TCD Last Destination Address Adjustment/Scatter Gather Address (idx = 0 ... 31)
#define DMA_TCD_DLASTSGA(idx) (* ((volatile uint32_t *) (0x40008000 + 0x1018 + 0x20 * (idx))))

//-------------------- TCD Control and Status (idx = 0 ... 31)
#define DMA_TCD_CSR(idx) (* ((volatile uint16_t *) (0x40008000 + 0x101C + 0x20 * (idx))))

  // Boolean field: Channel Start
    static const uint16_t DMA_TCD_CSR_START = 1U << 0 ;

  // Boolean field: Enable an interrupt when major iteration count completes.
    static const uint16_t DMA_TCD_CSR_INTMAJOR = 1U << 1 ;

  // Boolean field: Enable an interrupt when major counter is half complete.
    static const uint16_t DMA_TCD_CSR_INTHALF = 1U << 2 ;

  // Boolean field: Disable Request
    static const uint16_t DMA_TCD_CSR_DREQ = 1U << 3 ;

  // Boolean field: Enable Scatter/Gather Processing
    static const uint16_t DMA_TCD_CSR_ESG = 1U << 4 ;

  // Boolean field: Enable channel-to-channel linking on major loop complete
    static const uint16_t DMA_TCD_CSR_MAJORELINK = 1U << 5 ;

  // Boolean field: Channel Active
    static const uint16_t DMA_TCD_CSR_ACTIVE = 1U << 6 ;

  // Boolean field: Channel Done
    static const uint16_t DMA_TCD_CSR_DONE = 1U << 7 ;

  // Field (width: 5 bits): Major Loop Link Channel Number
    inline uint16_t DMA_TCD_CSR_MAJORLINKCH (const uint16_t inValue) { return (inValue & 31U) << 8 ; }

  // Field (width: 2 bits): Bandwidth Control
    inline uint16_t DMA_TCD_CSR_BWC (const uint16_t inValue) { return (inValue & 3U) << 14 ; }

//-------------------- TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Disabled) (idx = 0 ... 31)
#define DMA_TCD_BITER_ELINKNO(idx) (* ((volatile uint16_t *) (0x40008000 + 0x101E + 0x20 * (idx))))

  // Field (width: 15 bits): Starting Major Iteration Count
    inline uint16_t DMA_TCD_BITER_ELINKNO_BITER (const uint16_t inValue) { return (inValue & 32767U) << 0 ; }

  // Boolean field: Enables channel-to-channel linking on minor loop complete
    static const uint16_t DMA_TCD_BITER_ELINKNO_ELINK = 1U << 15 ;

//-------------------- TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Enabled) (idx = 0 ... 31)
#define DMA_TCD_BITER_ELINKYES(idx) (* ((volatile uint16_t *) (0x40008000 + 0x101E + 0x20 * (idx))))

  // Field (width: 9 bits): Starting major iteration count
    inline uint16_t DMA_TCD_BITER_ELINKYES_BITER (const uint16_t inValue) { return (inValue & 511U) << 0 ; }

  // Field (width: 5 bits): Link Channel Number
    inline uint16_t DMA_TCD_BITER_ELINKYES_LINKCH (const uint16_t inValue) { return (inValue & 31U) << 9 ; }

  // Boolean field: Enables channel-to-channel linking on minor loop complete
    static const uint16_t DMA_TCD_BITER_ELINKYES_ELINK = 1U << 15 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral FB
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Chip Select Address Register (idx = 0 ... 5)
#define FB_CSAR(idx) (* ((volatile uint32_t *) (0x4000C000 + 0 + 0xC * (idx))))

  // Field (width: 16 bits): Base Address
    inline uint32_t FB_CSAR_BA (const uint32_t inValue) { return (inValue & 65535U) << 16 ; }

//-------------------- Chip Select Mask Register (idx = 0 ... 5)
#define FB_CSMR(idx) (* ((volatile uint32_t *) (0x4000C000 + 0x4 + 0xC * (idx))))

  // Boolean field: Valid
    static const uint32_t FB_CSMR_V = 1U << 0 ;

  // Boolean field: Write Protect
    static const uint32_t FB_CSMR_WP = 1U << 8 ;

  // Field (width: 16 bits): Base Address Mask
    inline uint32_t FB_CSMR_BAM (const uint32_t inValue) { return (inValue & 65535U) << 16 ; }

//-------------------- Chip Select Control Register (idx = 0 ... 5)
#define FB_CSCR(idx) (* ((volatile uint32_t *) (0x4000C000 + 0x8 + 0xC * (idx))))

  // Boolean field: Burst-Write Enable
    static const uint32_t FB_CSCR_BSTW = 1U << 3 ;

  // Boolean field: Burst-Read Enable
    static const uint32_t FB_CSCR_BSTR = 1U << 4 ;

  // Boolean field: Byte-Enable Mode
    static const uint32_t FB_CSCR_BEM = 1U << 5 ;

  // Field (width: 2 bits): Port Size
    inline uint32_t FB_CSCR_PS (const uint32_t inValue) { return (inValue & 3U) << 6 ; }

  // Boolean field: Auto-Acknowledge Enable
    static const uint32_t FB_CSCR_AA = 1U << 8 ;

  // Boolean field: Byte-Lane Shift
    static const uint32_t FB_CSCR_BLS = 1U << 9 ;

  // Field (width: 6 bits): Wait States
    inline uint32_t FB_CSCR_WS (const uint32_t inValue) { return (inValue & 63U) << 10 ; }

  // Field (width: 2 bits): Write Address Hold or Deselect
    inline uint32_t FB_CSCR_WRAH (const uint32_t inValue) { return (inValue & 3U) << 16 ; }

  // Field (width: 2 bits): Read Address Hold or Deselect
    inline uint32_t FB_CSCR_RDAH (const uint32_t inValue) { return (inValue & 3U) << 18 ; }

  // Field (width: 2 bits): Address Setup
    inline uint32_t FB_CSCR_ASET (const uint32_t inValue) { return (inValue & 3U) << 20 ; }

  // Boolean field: Extended Transfer Start/Extended Address Latch Enable Controls how long FB_TS /FB_ALE is asserted.
    static const uint32_t FB_CSCR_EXTS = 1U << 22 ;

  // Boolean field: Secondary Wait State Enable
    static const uint32_t FB_CSCR_SWSEN = 1U << 23 ;

  // Field (width: 6 bits): Secondary Wait States
    inline uint32_t FB_CSCR_SWS (const uint32_t inValue) { return (inValue & 63U) << 26 ; }

//-------------------- Chip Select port Multiplexing Control Register
#define FB_CSPMCR (* ((volatile uint32_t *) (0x4000C000 + 0x60)))

  // Field (width: 4 bits): FlexBus Signal Group 5 Multiplex control
    inline uint32_t FB_CSPMCR_GROUP5 (const uint32_t inValue) { return (inValue & 15U) << 12 ; }

  // Field (width: 4 bits): FlexBus Signal Group 4 Multiplex control
    inline uint32_t FB_CSPMCR_GROUP4 (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 4 bits): FlexBus Signal Group 3 Multiplex control
    inline uint32_t FB_CSPMCR_GROUP3 (const uint32_t inValue) { return (inValue & 15U) << 20 ; }

  // Field (width: 4 bits): FlexBus Signal Group 2 Multiplex control
    inline uint32_t FB_CSPMCR_GROUP2 (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Field (width: 4 bits): FlexBus Signal Group 1 Multiplex control
    inline uint32_t FB_CSPMCR_GROUP1 (const uint32_t inValue) { return (inValue & 15U) << 28 ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral MPU
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Control/Error Status Register
#define MPU_CESR (* ((volatile uint32_t *) (0x4000D000 + 0)))

  // Boolean field: Valid
    static const uint32_t MPU_CESR_VLD = 1U << 0 ;

  // Field (width: 4 bits): Number Of Region Descriptors
    inline uint32_t MPU_CESR_NRGD (const uint32_t inValue) { return (inValue & 15U) << 8 ; }

  // Field (width: 4 bits): Number Of Slave Ports
    inline uint32_t MPU_CESR_NSP (const uint32_t inValue) { return (inValue & 15U) << 12 ; }

  // Field (width: 4 bits): Hardware Revision Level
    inline uint32_t MPU_CESR_HRL (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 5 bits): Slave Port n Error
    inline uint32_t MPU_CESR_SPERR (const uint32_t inValue) { return (inValue & 31U) << 27 ; }

//-------------------- Error Address Register, slave port n (idx = 0 ... 4)
#define MPU_EAR(idx) (* ((const volatile uint32_t *) (0x4000D000 + 0x10 + 0x8 * (idx))))

//-------------------- Error Detail Register, slave port n (idx = 0 ... 4)
#define MPU_EDR(idx) (* ((const volatile uint32_t *) (0x4000D000 + 0x14 + 0x8 * (idx))))

  // Boolean field: Error Read/Write
    static const uint32_t MPU_EDR_ERW = 1U << 0 ;

  // Field (width: 3 bits): Error Attributes
    inline uint32_t MPU_EDR_EATTR (const uint32_t inValue) { return (inValue & 7U) << 1 ; }

  // Field (width: 4 bits): Error Master Number
    inline uint32_t MPU_EDR_EMN (const uint32_t inValue) { return (inValue & 15U) << 4 ; }

  // Field (width: 8 bits): Error Process Identification
    inline uint32_t MPU_EDR_EPID (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 16 bits): Error Access Control Detail
    inline uint32_t MPU_EDR_EACD (const uint32_t inValue) { return (inValue & 65535U) << 16 ; }

//-------------------- Region Descriptor n, Word 0 (idx = 0 ... 11)
#define MPU_RGD_WORD0(idx) (* ((volatile uint32_t *) (0x4000D000 + 0x400 + 0x10 * (idx))))

  // Field (width: 27 bits): Start Address
    inline uint32_t MPU_RGD_WORD0_SRTADDR (const uint32_t inValue) { return (inValue & 134217727U) << 5 ; }

//-------------------- Region Descriptor n, Word 1 (idx = 0 ... 11)
#define MPU_RGD_WORD1(idx) (* ((volatile uint32_t *) (0x4000D000 + 0x404 + 0x10 * (idx))))

  // Field (width: 27 bits): End Address
    inline uint32_t MPU_RGD_WORD1_ENDADDR (const uint32_t inValue) { return (inValue & 134217727U) << 5 ; }

//-------------------- Region Descriptor n, Word 2 (idx = 0 ... 11)
#define MPU_RGD_WORD2(idx) (* ((volatile uint32_t *) (0x4000D000 + 0x408 + 0x10 * (idx))))

  // Field (width: 3 bits): Bus Master 0 User Mode Access Control
    inline uint32_t MPU_RGD_WORD2_M0UM (const uint32_t inValue) { return (inValue & 7U) << 0 ; }

  // Field (width: 2 bits): Bus Master 0 Supervisor Mode Access Control
    inline uint32_t MPU_RGD_WORD2_M0SM (const uint32_t inValue) { return (inValue & 3U) << 3 ; }

  // Boolean field: Bus Master 0 Process Identifier enable
    static const uint32_t MPU_RGD_WORD2_M0PE = 1U << 5 ;

  // Field (width: 3 bits): Bus Master 1 User Mode Access Control
    inline uint32_t MPU_RGD_WORD2_M1UM (const uint32_t inValue) { return (inValue & 7U) << 6 ; }

  // Field (width: 2 bits): Bus Master 1 Supervisor Mode Access Control
    inline uint32_t MPU_RGD_WORD2_M1SM (const uint32_t inValue) { return (inValue & 3U) << 9 ; }

  // Boolean field: Bus Master 1 Process Identifier enable
    static const uint32_t MPU_RGD_WORD2_M1PE = 1U << 11 ;

  // Field (width: 3 bits): Bus Master 2 User Mode Access control
    inline uint32_t MPU_RGD_WORD2_M2UM (const uint32_t inValue) { return (inValue & 7U) << 12 ; }

  // Field (width: 2 bits): Bus Master 2 Supervisor Mode Access Control
    inline uint32_t MPU_RGD_WORD2_M2SM (const uint32_t inValue) { return (inValue & 3U) << 15 ; }

  // Boolean field: Bus Master 2 Process Identifier Enable
    static const uint32_t MPU_RGD_WORD2_M2PE = 1U << 17 ;

  // Field (width: 3 bits): Bus Master 3 User Mode Access Control
    inline uint32_t MPU_RGD_WORD2_M3UM (const uint32_t inValue) { return (inValue & 7U) << 18 ; }

  // Field (width: 2 bits): Bus Master 3 Supervisor Mode Access Control
    inline uint32_t MPU_RGD_WORD2_M3SM (const uint32_t inValue) { return (inValue & 3U) << 21 ; }

  // Boolean field: Bus Master 3 Process Identifier Enable
    static const uint32_t MPU_RGD_WORD2_M3PE = 1U << 23 ;

  // Boolean field: Bus Master 4 Write Enable
    static const uint32_t MPU_RGD_WORD2_M4WE = 1U << 24 ;

  // Boolean field: Bus Master 4 Read Enable
    static const uint32_t MPU_RGD_WORD2_M4RE = 1U << 25 ;

  // Boolean field: Bus Master 5 Write Enable
    static const uint32_t MPU_RGD_WORD2_M5WE = 1U << 26 ;

  // Boolean field: Bus Master 5 Read Enable
    static const uint32_t MPU_RGD_WORD2_M5RE = 1U << 27 ;

  // Boolean field: Bus Master 6 Write Enable
    static const uint32_t MPU_RGD_WORD2_M6WE = 1U << 28 ;

  // Boolean field: Bus Master 6 Read Enable
    static const uint32_t MPU_RGD_WORD2_M6RE = 1U << 29 ;

  // Boolean field: Bus Master 7 Write Enable
    static const uint32_t MPU_RGD_WORD2_M7WE = 1U << 30 ;

  // Boolean field: Bus Master 7 Read Enable
    static const uint32_t MPU_RGD_WORD2_M7RE = 1U << 31 ;

//-------------------- Region Descriptor n, Word 3 (idx = 0 ... 11)
#define MPU_RGD_WORD3(idx) (* ((volatile uint32_t *) (0x4000D000 + 0x40C + 0x10 * (idx))))

  // Boolean field: Valid
    static const uint32_t MPU_RGD_WORD3_VLD = 1U << 0 ;

  // Field (width: 8 bits): Process Identifier Mask
    inline uint32_t MPU_RGD_WORD3_PIDMASK (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Process Identifier
    inline uint32_t MPU_RGD_WORD3_PID (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Region Descriptor Alternate Access Control n (idx = 0 ... 11)
#define MPU_RGDAAC(idx) (* ((volatile uint32_t *) (0x4000D000 + 0x800 + 0x4 * (idx))))

  // Field (width: 3 bits): Bus Master 0 User Mode Access Control
    inline uint32_t MPU_RGDAAC_M0UM (const uint32_t inValue) { return (inValue & 7U) << 0 ; }

  // Field (width: 2 bits): Bus Master 0 Supervisor Mode Access Control
    inline uint32_t MPU_RGDAAC_M0SM (const uint32_t inValue) { return (inValue & 3U) << 3 ; }

  // Boolean field: Bus Master 0 Process Identifier Enable
    static const uint32_t MPU_RGDAAC_M0PE = 1U << 5 ;

  // Field (width: 3 bits): Bus Master 1 User Mode Access Control
    inline uint32_t MPU_RGDAAC_M1UM (const uint32_t inValue) { return (inValue & 7U) << 6 ; }

  // Field (width: 2 bits): Bus Master 1 Supervisor Mode Access Control
    inline uint32_t MPU_RGDAAC_M1SM (const uint32_t inValue) { return (inValue & 3U) << 9 ; }

  // Boolean field: Bus Master 1 Process Identifier Enable
    static const uint32_t MPU_RGDAAC_M1PE = 1U << 11 ;

  // Field (width: 3 bits): Bus Master 2 User Mode Access Control
    inline uint32_t MPU_RGDAAC_M2UM (const uint32_t inValue) { return (inValue & 7U) << 12 ; }

  // Field (width: 2 bits): Bus Master 2 Supervisor Mode Access Control
    inline uint32_t MPU_RGDAAC_M2SM (const uint32_t inValue) { return (inValue & 3U) << 15 ; }

  // Boolean field: Bus Master 2 Process Identifier Enable
    static const uint32_t MPU_RGDAAC_M2PE = 1U << 17 ;

  // Field (width: 3 bits): Bus Master 3 User Mode Access Control
    inline uint32_t MPU_RGDAAC_M3UM (const uint32_t inValue) { return (inValue & 7U) << 18 ; }

  // Field (width: 2 bits): Bus Master 3 Supervisor Mode Access Control
    inline uint32_t MPU_RGDAAC_M3SM (const uint32_t inValue) { return (inValue & 3U) << 21 ; }

  // Boolean field: Bus Master 3 Process Identifier Enable
    static const uint32_t MPU_RGDAAC_M3PE = 1U << 23 ;

  // Boolean field: Bus Master 4 Write Enable
    static const uint32_t MPU_RGDAAC_M4WE = 1U << 24 ;

  // Boolean field: Bus Master 4 Read Enable
    static const uint32_t MPU_RGDAAC_M4RE = 1U << 25 ;

  // Boolean field: Bus Master 5 Write Enable
    static const uint32_t MPU_RGDAAC_M5WE = 1U << 26 ;

  // Boolean field: Bus Master 5 Read Enable
    static const uint32_t MPU_RGDAAC_M5RE = 1U << 27 ;

  // Boolean field: Bus Master 6 Write Enable
    static const uint32_t MPU_RGDAAC_M6WE = 1U << 28 ;

  // Boolean field: Bus Master 6 Read Enable
    static const uint32_t MPU_RGDAAC_M6RE = 1U << 29 ;

  // Boolean field: Bus Master 7 Write Enable
    static const uint32_t MPU_RGDAAC_M7WE = 1U << 30 ;

  // Boolean field: Bus Master 7 Read Enable
    static const uint32_t MPU_RGDAAC_M7RE = 1U << 31 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral SDRAM
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Control Register
#define SDRAM_CTRL (* ((volatile uint16_t *) (0x4000F000 + 0x42)))

  // Field (width: 9 bits): Refresh count
    inline uint16_t SDRAM_CTRL_RC (const uint16_t inValue) { return (inValue & 511U) << 0 ; }

  // Field (width: 2 bits): Refresh timing
    inline uint16_t SDRAM_CTRL_RTIM (const uint16_t inValue) { return (inValue & 3U) << 9 ; }

  // Boolean field: Initiate self-refresh command.
    static const uint16_t SDRAM_CTRL_IS = 1U << 11 ;

//-------------------- Address and Control Register (idx = 0 ... 1)
#define SDRAM_AC(idx) (* ((volatile uint32_t *) (0x4000F000 + 0x48 + 0x8 * (idx))))

  // Boolean field: Initiate precharge all (pall) command.
    static const uint32_t SDRAM_AC_IP = 1U << 3 ;

  // Field (width: 2 bits): Port size.
    inline uint32_t SDRAM_AC_PS (const uint32_t inValue) { return (inValue & 3U) << 4 ; }

  // Boolean field: Initiate mode register set (mrs) command.
    static const uint32_t SDRAM_AC_IMRS = 1U << 6 ;

  // Field (width: 3 bits): Command bit location
    inline uint32_t SDRAM_AC_CBM (const uint32_t inValue) { return (inValue & 7U) << 8 ; }

  // Field (width: 2 bits): CAS Latency
    inline uint32_t SDRAM_AC_CASL (const uint32_t inValue) { return (inValue & 3U) << 12 ; }

  // Boolean field: Refresh enable
    static const uint32_t SDRAM_AC_RE = 1U << 15 ;

  // Field (width: 14 bits): Base address register.
    inline uint32_t SDRAM_AC_BA (const uint32_t inValue) { return (inValue & 16383U) << 18 ; }

//-------------------- Control Mask (idx = 0 ... 1)
#define SDRAM_CM(idx) (* ((volatile uint32_t *) (0x4000F000 + 0x4C + 0x8 * (idx))))

  // Boolean field: Valid.
    static const uint32_t SDRAM_CM_V = 1U << 0 ;

  // Boolean field: Write protect.
    static const uint32_t SDRAM_CM_WP = 1U << 8 ;

  // Field (width: 14 bits): Base address mask.
    inline uint32_t SDRAM_CM_BAM (const uint32_t inValue) { return (inValue & 16383U) << 18 ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral FMC
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Flash Access Protection Register
#define FMC_PFAPR (* ((volatile uint32_t *) (0x4001F000 + 0)))

  // Field (width: 2 bits): Master 0 Access Protection
    inline uint32_t FMC_PFAPR_M0AP (const uint32_t inValue) { return (inValue & 3U) << 0 ; }

  // Field (width: 2 bits): Master 1 Access Protection
    inline uint32_t FMC_PFAPR_M1AP (const uint32_t inValue) { return (inValue & 3U) << 2 ; }

  // Field (width: 2 bits): Master 2 Access Protection
    inline uint32_t FMC_PFAPR_M2AP (const uint32_t inValue) { return (inValue & 3U) << 4 ; }

  // Field (width: 2 bits): Master 3 Access Protection
    inline uint32_t FMC_PFAPR_M3AP (const uint32_t inValue) { return (inValue & 3U) << 6 ; }

  // Field (width: 2 bits): Master 4 Access Protection
    inline uint32_t FMC_PFAPR_M4AP (const uint32_t inValue) { return (inValue & 3U) << 8 ; }

  // Field (width: 2 bits): Master 5 Access Protection
    inline uint32_t FMC_PFAPR_M5AP (const uint32_t inValue) { return (inValue & 3U) << 10 ; }

  // Field (width: 2 bits): Master 6 Access Protection
    inline uint32_t FMC_PFAPR_M6AP (const uint32_t inValue) { return (inValue & 3U) << 12 ; }

  // Field (width: 2 bits): Master 7 Access Protection
    inline uint32_t FMC_PFAPR_M7AP (const uint32_t inValue) { return (inValue & 3U) << 14 ; }

  // Boolean field: Master 0 Prefetch Disable
    static const uint32_t FMC_PFAPR_M0PFD = 1U << 16 ;

  // Boolean field: Master 1 Prefetch Disable
    static const uint32_t FMC_PFAPR_M1PFD = 1U << 17 ;

  // Boolean field: Master 2 Prefetch Disable
    static const uint32_t FMC_PFAPR_M2PFD = 1U << 18 ;

  // Boolean field: Master 3 Prefetch Disable
    static const uint32_t FMC_PFAPR_M3PFD = 1U << 19 ;

  // Boolean field: Master 4 Prefetch Disable
    static const uint32_t FMC_PFAPR_M4PFD = 1U << 20 ;

  // Boolean field: Master 5 Prefetch Disable
    static const uint32_t FMC_PFAPR_M5PFD = 1U << 21 ;

  // Boolean field: Master 6 Prefetch Disable
    static const uint32_t FMC_PFAPR_M6PFD = 1U << 22 ;

  // Boolean field: Master 7 Prefetch Disable
    static const uint32_t FMC_PFAPR_M7PFD = 1U << 23 ;

//-------------------- Flash Bank 0-1 Control Register
#define FMC_PFB01CR (* ((volatile uint32_t *) (0x4001F000 + 0x4)))

  // Boolean field: Reserved for future use
    static const uint32_t FMC_PFB01CR_RFU = 1U << 0 ;

  // Boolean field: Bank 0 Instruction Prefetch Enable
    static const uint32_t FMC_PFB01CR_B0IPE = 1U << 1 ;

  // Boolean field: Bank 0 Data Prefetch Enable
    static const uint32_t FMC_PFB01CR_B0DPE = 1U << 2 ;

  // Boolean field: Bank 0 Instruction Cache Enable
    static const uint32_t FMC_PFB01CR_B0ICE = 1U << 3 ;

  // Boolean field: Bank 0 Data Cache Enable
    static const uint32_t FMC_PFB01CR_B0DCE = 1U << 4 ;

  // Field (width: 3 bits): Cache Replacement Control
    inline uint32_t FMC_PFB01CR_CRC (const uint32_t inValue) { return (inValue & 7U) << 5 ; }

  // Field (width: 2 bits): Bank 0 Memory Width
    inline uint32_t FMC_PFB01CR_B0MW (const uint32_t inValue) { return (inValue & 3U) << 17 ; }

  // Boolean field: Invalidate Prefetch Speculation Buffer
    static const uint32_t FMC_PFB01CR_S_B_INV = 1U << 19 ;

  // Field (width: 4 bits): Cache Invalidate Way x
    inline uint32_t FMC_PFB01CR_CINV_WAY (const uint32_t inValue) { return (inValue & 15U) << 20 ; }

  // Field (width: 4 bits): Cache Lock Way x
    inline uint32_t FMC_PFB01CR_CLCK_WAY (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Field (width: 4 bits): Bank 0 Read Wait State Control
    inline uint32_t FMC_PFB01CR_B0RWSC (const uint32_t inValue) { return (inValue & 15U) << 28 ; }

//-------------------- Flash Bank 2-3 Control Register
#define FMC_PFB23CR (* ((volatile uint32_t *) (0x4001F000 + 0x8)))

  // Boolean field: Reserved for future use
    static const uint32_t FMC_PFB23CR_RFU = 1U << 0 ;

  // Boolean field: Bank 1 Instruction Prefetch Enable
    static const uint32_t FMC_PFB23CR_B1IPE = 1U << 1 ;

  // Boolean field: Bank 1 Data Prefetch Enable
    static const uint32_t FMC_PFB23CR_B1DPE = 1U << 2 ;

  // Boolean field: Bank 1 Instruction Cache Enable
    static const uint32_t FMC_PFB23CR_B1ICE = 1U << 3 ;

  // Boolean field: Bank 1 Data Cache Enable
    static const uint32_t FMC_PFB23CR_B1DCE = 1U << 4 ;

  // Field (width: 2 bits): Bank 1 Memory Width
    inline uint32_t FMC_PFB23CR_B1MW (const uint32_t inValue) { return (inValue & 3U) << 17 ; }

  // Field (width: 4 bits): Bank 1 Read Wait State Control
    inline uint32_t FMC_PFB23CR_B1RWSC (const uint32_t inValue) { return (inValue & 15U) << 28 ; }

//-------------------- Cache Tag Storage (idx = 0 ... 3)
#define FMC_TAGVDW0S(idx) (* ((volatile uint32_t *) (0x4001F000 + 0x100 + 0x4 * (idx))))

  // Boolean field: 1-bit valid for cache entry
    static const uint32_t FMC_TAGVDW0S_valid = 1U << 0 ;

  // Field (width: 16 bits): 16-bit tag for cache entry
    inline uint32_t FMC_TAGVDW0S_tag (const uint32_t inValue) { return (inValue & 65535U) << 6 ; }

//-------------------- Cache Tag Storage (idx = 0 ... 3)
#define FMC_TAGVDW1S(idx) (* ((volatile uint32_t *) (0x4001F000 + 0x110 + 0x4 * (idx))))

  // Boolean field: 1-bit valid for cache entry
    static const uint32_t FMC_TAGVDW1S_valid = 1U << 0 ;

  // Field (width: 16 bits): 16-bit tag for cache entry
    inline uint32_t FMC_TAGVDW1S_tag (const uint32_t inValue) { return (inValue & 65535U) << 6 ; }

//-------------------- Cache Tag Storage (idx = 0 ... 3)
#define FMC_TAGVDW2S(idx) (* ((volatile uint32_t *) (0x4001F000 + 0x120 + 0x4 * (idx))))

  // Boolean field: 1-bit valid for cache entry
    static const uint32_t FMC_TAGVDW2S_valid = 1U << 0 ;

  // Field (width: 16 bits): 16-bit tag for cache entry
    inline uint32_t FMC_TAGVDW2S_tag (const uint32_t inValue) { return (inValue & 65535U) << 6 ; }

//-------------------- Cache Tag Storage (idx = 0 ... 3)
#define FMC_TAGVDW3S(idx) (* ((volatile uint32_t *) (0x4001F000 + 0x130 + 0x4 * (idx))))

  // Boolean field: 1-bit valid for cache entry
    static const uint32_t FMC_TAGVDW3S_valid = 1U << 0 ;

  // Field (width: 16 bits): 16-bit tag for cache entry
    inline uint32_t FMC_TAGVDW3S_tag (const uint32_t inValue) { return (inValue & 65535U) << 6 ; }

//-------------------- Cache Data Storage (uppermost word) (idx = 0 ... 3)
#define FMC_DATAW0SUM(idx) (* ((volatile uint32_t *) (0x4001F000 + 0x200 + 0x10 * (idx))))

//-------------------- Cache Data Storage (mid-upper word) (idx = 0 ... 3)
#define FMC_DATAW0SMU(idx) (* ((volatile uint32_t *) (0x4001F000 + 0x204 + 0x10 * (idx))))

//-------------------- Cache Data Storage (mid-lower word) (idx = 0 ... 3)
#define FMC_DATAW0SML(idx) (* ((volatile uint32_t *) (0x4001F000 + 0x208 + 0x10 * (idx))))

//-------------------- Cache Data Storage (lowermost word) (idx = 0 ... 3)
#define FMC_DATAW0SLM(idx) (* ((volatile uint32_t *) (0x4001F000 + 0x20C + 0x10 * (idx))))

//-------------------- Cache Data Storage (uppermost word) (idx = 0 ... 3)
#define FMC_DATAW1SUM(idx) (* ((volatile uint32_t *) (0x4001F000 + 0x240 + 0x10 * (idx))))

//-------------------- Cache Data Storage (mid-upper word) (idx = 0 ... 3)
#define FMC_DATAW1SMU(idx) (* ((volatile uint32_t *) (0x4001F000 + 0x244 + 0x10 * (idx))))

//-------------------- Cache Data Storage (mid-lower word) (idx = 0 ... 3)
#define FMC_DATAW1SML(idx) (* ((volatile uint32_t *) (0x4001F000 + 0x248 + 0x10 * (idx))))

//-------------------- Cache Data Storage (lowermost word) (idx = 0 ... 3)
#define FMC_DATAW1SLM(idx) (* ((volatile uint32_t *) (0x4001F000 + 0x24C + 0x10 * (idx))))

//-------------------- Cache Data Storage (uppermost word) (idx = 0 ... 3)
#define FMC_DATAW2SUM(idx) (* ((volatile uint32_t *) (0x4001F000 + 0x280 + 0x10 * (idx))))

//-------------------- Cache Data Storage (mid-upper word) (idx = 0 ... 3)
#define FMC_DATAW2SMU(idx) (* ((volatile uint32_t *) (0x4001F000 + 0x284 + 0x10 * (idx))))

//-------------------- Cache Data Storage (mid-lower word) (idx = 0 ... 3)
#define FMC_DATAW2SML(idx) (* ((volatile uint32_t *) (0x4001F000 + 0x288 + 0x10 * (idx))))

//-------------------- Cache Data Storage (lowermost word) (idx = 0 ... 3)
#define FMC_DATAW2SLM(idx) (* ((volatile uint32_t *) (0x4001F000 + 0x28C + 0x10 * (idx))))

//-------------------- Cache Data Storage (uppermost word) (idx = 0 ... 3)
#define FMC_DATAW3SUM(idx) (* ((volatile uint32_t *) (0x4001F000 + 0x2C0 + 0x10 * (idx))))

//-------------------- Cache Data Storage (mid-upper word) (idx = 0 ... 3)
#define FMC_DATAW3SMU(idx) (* ((volatile uint32_t *) (0x4001F000 + 0x2C4 + 0x10 * (idx))))

//-------------------- Cache Data Storage (mid-lower word) (idx = 0 ... 3)
#define FMC_DATAW3SML(idx) (* ((volatile uint32_t *) (0x4001F000 + 0x2C8 + 0x10 * (idx))))

//-------------------- Cache Data Storage (lowermost word) (idx = 0 ... 3)
#define FMC_DATAW3SLM(idx) (* ((volatile uint32_t *) (0x4001F000 + 0x2CC + 0x10 * (idx))))

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral FTFE
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Flash Status Register
#define FTFE_FSTAT (* ((volatile uint8_t *) (0x40020000 + 0)))

  // Boolean field: Memory Controller Command Completion Status Flag
    static const uint8_t FTFE_FSTAT_MGSTAT0 = 1U << 0 ;

  // Boolean field: Flash Protection Violation Flag
    static const uint8_t FTFE_FSTAT_FPVIOL = 1U << 4 ;

  // Boolean field: Flash Access Error Flag
    static const uint8_t FTFE_FSTAT_ACCERR = 1U << 5 ;

  // Boolean field: FTFE Read Collision Error Flag
    static const uint8_t FTFE_FSTAT_RDCOLERR = 1U << 6 ;

  // Boolean field: Command Complete Interrupt Flag
    static const uint8_t FTFE_FSTAT_CCIF = 1U << 7 ;

//-------------------- Flash Configuration Register
#define FTFE_FCNFG (* ((volatile uint8_t *) (0x40020000 + 0x1)))

  // Boolean field: For devices with FlexNVM: This flag indicates if the EEPROM backup data has been copied to the FlexRAM and is therefore available for read access
    static const uint8_t FTFE_FCNFG_EEERDY = 1U << 0 ;

  // Boolean field: RAM Ready
    static const uint8_t FTFE_FCNFG_RAMRDY = 1U << 1 ;

  // Boolean field: FTFE configuration
    static const uint8_t FTFE_FCNFG_PFLSH = 1U << 2 ;

  // Boolean field: Swap
    static const uint8_t FTFE_FCNFG_SWAP = 1U << 3 ;

  // Boolean field: Erase Suspend
    static const uint8_t FTFE_FCNFG_ERSSUSP = 1U << 4 ;

  // Boolean field: Erase All Request
    static const uint8_t FTFE_FCNFG_ERSAREQ = 1U << 5 ;

  // Boolean field: Read Collision Error Interrupt Enable
    static const uint8_t FTFE_FCNFG_RDCOLLIE = 1U << 6 ;

  // Boolean field: Command Complete Interrupt Enable
    static const uint8_t FTFE_FCNFG_CCIE = 1U << 7 ;

//-------------------- Flash Security Register
#define FTFE_FSEC (* ((const volatile uint8_t *) (0x40020000 + 0x2)))

  // Field (width: 2 bits): Flash Security
    inline uint8_t FTFE_FSEC_SEC (const uint8_t inValue) { return (inValue & 3U) << 0 ; }

  // Field (width: 2 bits): Freescale Failure Analysis Access Code
    inline uint8_t FTFE_FSEC_FSLACC (const uint8_t inValue) { return (inValue & 3U) << 2 ; }

  // Field (width: 2 bits): Mass Erase Enable Bits
    inline uint8_t FTFE_FSEC_MEEN (const uint8_t inValue) { return (inValue & 3U) << 4 ; }

  // Field (width: 2 bits): Backdoor Key Security Enable
    inline uint8_t FTFE_FSEC_KEYEN (const uint8_t inValue) { return (inValue & 3U) << 6 ; }

//-------------------- Flash Option Register
#define FTFE_FOPT (* ((const volatile uint8_t *) (0x40020000 + 0x3)))

//-------------------- Flash Common Command Object Registers (0 ... 3)
#define FTFE_FCCOB_0_3 (* ((volatile uint32_t *) (0x40020000 + 0x4)))

//-------------------- Flash Common Command Object Registers (4 ... 7)
#define FTFE_FCCOB_4_7 (* ((volatile uint32_t *) (0x40020000 + 0x8)))

//-------------------- Flash Common Command Object Registers (8 ... 11)
#define FTFE_FCCOB_8_11 (* ((volatile uint32_t *) (0x40020000 + 0xC)))

//-------------------- Program Flash Protection Registers (idx = 0 ... 3)
#define FTFE_FPROT(idx) (* ((volatile uint8_t *) (0x40020000 + 0x10 + 0x1 * (idx))))

//-------------------- EEPROM Protection Register
#define FTFE_FEPROT (* ((volatile uint8_t *) (0x40020000 + 0x16)))

//-------------------- Data Flash Protection Register
#define FTFE_FDPROT (* ((volatile uint8_t *) (0x40020000 + 0x17)))

//-------------------- Execute-only Access Registers (idx = 0 ... 7)
#define FTFE_XACC(idx) (* ((const volatile uint8_t *) (0x40020000 + 0x18 + 0x1 * (idx))))

//-------------------- Supervisor-only Access Registers (idx = 0 ... 7)
#define FTFE_SACC(idx) (* ((const volatile uint8_t *) (0x40020000 + 0x20 + 0x1 * (idx))))

//-------------------- Flash Access Segment Size Register
#define FTFE_FACSS (* ((const volatile uint8_t *) (0x40020000 + 0x28)))

//-------------------- Flash Access Segment Number Register
#define FTFE_FACSN (* ((const volatile uint8_t *) (0x40020000 + 0x2B)))

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral DMAMUX
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Channel Configuration register (idx = 0 ... 31)
#define DMAMUX_CHCFG(idx) (* ((volatile uint8_t *) (0x40021000 + 0 + 0x1 * (idx))))

  // Field (width: 6 bits): DMA Channel Source (Slot)
    inline uint8_t DMAMUX_CHCFG_SOURCE (const uint8_t inValue) { return (inValue & 63U) << 0 ; }

  // Boolean field: DMA Channel Trigger Enable
    static const uint8_t DMAMUX_CHCFG_TRIG = 1U << 6 ;

  // Boolean field: DMA Channel Enable
    static const uint8_t DMAMUX_CHCFG_ENBL = 1U << 7 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral I2S0
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- SAI Transmit Control Register
#define I2S0_TCSR (* ((volatile uint32_t *) (0x4002F000 + 0)))

  // Boolean field: FIFO Request DMA Enable
    static const uint32_t I2S0_TCSR_FRDE = 1U << 0 ;

  // Boolean field: FIFO Warning DMA Enable
    static const uint32_t I2S0_TCSR_FWDE = 1U << 1 ;

  // Boolean field: FIFO Request Interrupt Enable
    static const uint32_t I2S0_TCSR_FRIE = 1U << 8 ;

  // Boolean field: FIFO Warning Interrupt Enable
    static const uint32_t I2S0_TCSR_FWIE = 1U << 9 ;

  // Boolean field: FIFO Error Interrupt Enable
    static const uint32_t I2S0_TCSR_FEIE = 1U << 10 ;

  // Boolean field: Sync Error Interrupt Enable
    static const uint32_t I2S0_TCSR_SEIE = 1U << 11 ;

  // Boolean field: Word Start Interrupt Enable
    static const uint32_t I2S0_TCSR_WSIE = 1U << 12 ;

  // Boolean field: FIFO Request Flag
    static const uint32_t I2S0_TCSR_FRF = 1U << 16 ;

  // Boolean field: FIFO Warning Flag
    static const uint32_t I2S0_TCSR_FWF = 1U << 17 ;

  // Boolean field: FIFO Error Flag
    static const uint32_t I2S0_TCSR_FEF = 1U << 18 ;

  // Boolean field: Sync Error Flag
    static const uint32_t I2S0_TCSR_SEF = 1U << 19 ;

  // Boolean field: Word Start Flag
    static const uint32_t I2S0_TCSR_WSF = 1U << 20 ;

  // Boolean field: Software Reset
    static const uint32_t I2S0_TCSR_SR = 1U << 24 ;

  // Boolean field: FIFO Reset
    static const uint32_t I2S0_TCSR_FR = 1U << 25 ;

  // Boolean field: Bit Clock Enable
    static const uint32_t I2S0_TCSR_BCE = 1U << 28 ;

  // Boolean field: Debug Enable
    static const uint32_t I2S0_TCSR_DBGE = 1U << 29 ;

  // Boolean field: Stop Enable
    static const uint32_t I2S0_TCSR_STOPE = 1U << 30 ;

  // Boolean field: Transmitter Enable
    static const uint32_t I2S0_TCSR_TE = 1U << 31 ;

//-------------------- SAI Transmit Configuration 1 Register
#define I2S0_TCR1 (* ((volatile uint32_t *) (0x4002F000 + 0x4)))

  // Field (width: 3 bits): Transmit FIFO Watermark
    inline uint32_t I2S0_TCR1_TFW (const uint32_t inValue) { return (inValue & 7U) << 0 ; }

//-------------------- SAI Transmit Configuration 2 Register
#define I2S0_TCR2 (* ((volatile uint32_t *) (0x4002F000 + 0x8)))

  // Field (width: 8 bits): Bit Clock Divide
    inline uint32_t I2S0_TCR2_DIV (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Boolean field: Bit Clock Direction
    static const uint32_t I2S0_TCR2_BCD = 1U << 24 ;

  // Boolean field: Bit Clock Polarity
    static const uint32_t I2S0_TCR2_BCP = 1U << 25 ;

  // Field (width: 2 bits): MCLK Select
    inline uint32_t I2S0_TCR2_MSEL (const uint32_t inValue) { return (inValue & 3U) << 26 ; }

  // Boolean field: Bit Clock Input
    static const uint32_t I2S0_TCR2_BCI = 1U << 28 ;

  // Boolean field: Bit Clock Swap
    static const uint32_t I2S0_TCR2_BCS = 1U << 29 ;

  // Field (width: 2 bits): Synchronous Mode
    inline uint32_t I2S0_TCR2_SYNC (const uint32_t inValue) { return (inValue & 3U) << 30 ; }

//-------------------- SAI Transmit Configuration 3 Register
#define I2S0_TCR3 (* ((volatile uint32_t *) (0x4002F000 + 0xC)))

  // Field (width: 5 bits): Word Flag Configuration
    inline uint32_t I2S0_TCR3_WDFL (const uint32_t inValue) { return (inValue & 31U) << 0 ; }

  // Field (width: 2 bits): Transmit Channel Enable
    inline uint32_t I2S0_TCR3_TCE (const uint32_t inValue) { return (inValue & 3U) << 16 ; }

  // Field (width: 2 bits): Channel FIFO Reset
    inline uint32_t I2S0_TCR3_CFR (const uint32_t inValue) { return (inValue & 3U) << 24 ; }

//-------------------- SAI Transmit Configuration 4 Register
#define I2S0_TCR4 (* ((volatile uint32_t *) (0x4002F000 + 0x10)))

  // Boolean field: Frame Sync Direction
    static const uint32_t I2S0_TCR4_FSD = 1U << 0 ;

  // Boolean field: Frame Sync Polarity
    static const uint32_t I2S0_TCR4_FSP = 1U << 1 ;

  // Boolean field: On Demand Mode
    static const uint32_t I2S0_TCR4_ONDEM = 1U << 2 ;

  // Boolean field: Frame Sync Early
    static const uint32_t I2S0_TCR4_FSE = 1U << 3 ;

  // Boolean field: MSB First
    static const uint32_t I2S0_TCR4_MF = 1U << 4 ;

  // Field (width: 5 bits): Sync Width
    inline uint32_t I2S0_TCR4_SYWD (const uint32_t inValue) { return (inValue & 31U) << 8 ; }

  // Field (width: 5 bits): Frame size
    inline uint32_t I2S0_TCR4_FRSZ (const uint32_t inValue) { return (inValue & 31U) << 16 ; }

  // Field (width: 2 bits): FIFO Packing Mode
    inline uint32_t I2S0_TCR4_FPACK (const uint32_t inValue) { return (inValue & 3U) << 24 ; }

  // Field (width: 2 bits): FIFO Combine Mode
    inline uint32_t I2S0_TCR4_FCOMB (const uint32_t inValue) { return (inValue & 3U) << 26 ; }

  // Boolean field: FIFO Continue on Error
    static const uint32_t I2S0_TCR4_FCONT = 1U << 28 ;

//-------------------- SAI Transmit Configuration 5 Register
#define I2S0_TCR5 (* ((volatile uint32_t *) (0x4002F000 + 0x14)))

  // Field (width: 5 bits): First Bit Shifted
    inline uint32_t I2S0_TCR5_FBT (const uint32_t inValue) { return (inValue & 31U) << 8 ; }

  // Field (width: 5 bits): Word 0 Width
    inline uint32_t I2S0_TCR5_W0W (const uint32_t inValue) { return (inValue & 31U) << 16 ; }

  // Field (width: 5 bits): Word N Width
    inline uint32_t I2S0_TCR5_WNW (const uint32_t inValue) { return (inValue & 31U) << 24 ; }

//-------------------- SAI Transmit Data Register (idx = 0 ... 1)
#define I2S0_TDR(idx) (* ((volatile uint32_t *) (0x4002F000 + 0x20 + 0x4 * (idx))))

//-------------------- SAI Transmit FIFO Register (idx = 0 ... 1)
#define I2S0_TFR(idx) (* ((const volatile uint32_t *) (0x4002F000 + 0x40 + 0x4 * (idx))))

  // Field (width: 4 bits): Read FIFO Pointer
    inline uint32_t I2S0_TFR_RFP (const uint32_t inValue) { return (inValue & 15U) << 0 ; }

  // Field (width: 4 bits): Write FIFO Pointer
    inline uint32_t I2S0_TFR_WFP (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Boolean field: Write Channel Pointer
    static const uint32_t I2S0_TFR_WCP = 1U << 31 ;

//-------------------- SAI Transmit Mask Register
#define I2S0_TMR (* ((volatile uint32_t *) (0x4002F000 + 0x60)))

//-------------------- SAI Receive Control Register
#define I2S0_RCSR (* ((volatile uint32_t *) (0x4002F000 + 0x80)))

  // Boolean field: FIFO Request DMA Enable
    static const uint32_t I2S0_RCSR_FRDE = 1U << 0 ;

  // Boolean field: FIFO Warning DMA Enable
    static const uint32_t I2S0_RCSR_FWDE = 1U << 1 ;

  // Boolean field: FIFO Request Interrupt Enable
    static const uint32_t I2S0_RCSR_FRIE = 1U << 8 ;

  // Boolean field: FIFO Warning Interrupt Enable
    static const uint32_t I2S0_RCSR_FWIE = 1U << 9 ;

  // Boolean field: FIFO Error Interrupt Enable
    static const uint32_t I2S0_RCSR_FEIE = 1U << 10 ;

  // Boolean field: Sync Error Interrupt Enable
    static const uint32_t I2S0_RCSR_SEIE = 1U << 11 ;

  // Boolean field: Word Start Interrupt Enable
    static const uint32_t I2S0_RCSR_WSIE = 1U << 12 ;

  // Boolean field: FIFO Request Flag
    static const uint32_t I2S0_RCSR_FRF = 1U << 16 ;

  // Boolean field: FIFO Warning Flag
    static const uint32_t I2S0_RCSR_FWF = 1U << 17 ;

  // Boolean field: FIFO Error Flag
    static const uint32_t I2S0_RCSR_FEF = 1U << 18 ;

  // Boolean field: Sync Error Flag
    static const uint32_t I2S0_RCSR_SEF = 1U << 19 ;

  // Boolean field: Word Start Flag
    static const uint32_t I2S0_RCSR_WSF = 1U << 20 ;

  // Boolean field: Software Reset
    static const uint32_t I2S0_RCSR_SR = 1U << 24 ;

  // Boolean field: FIFO Reset
    static const uint32_t I2S0_RCSR_FR = 1U << 25 ;

  // Boolean field: Bit Clock Enable
    static const uint32_t I2S0_RCSR_BCE = 1U << 28 ;

  // Boolean field: Debug Enable
    static const uint32_t I2S0_RCSR_DBGE = 1U << 29 ;

  // Boolean field: Stop Enable
    static const uint32_t I2S0_RCSR_STOPE = 1U << 30 ;

  // Boolean field: Receiver Enable
    static const uint32_t I2S0_RCSR_RE = 1U << 31 ;

//-------------------- SAI Receive Configuration 1 Register
#define I2S0_RCR1 (* ((volatile uint32_t *) (0x4002F000 + 0x84)))

  // Field (width: 3 bits): Receive FIFO Watermark
    inline uint32_t I2S0_RCR1_RFW (const uint32_t inValue) { return (inValue & 7U) << 0 ; }

//-------------------- SAI Receive Configuration 2 Register
#define I2S0_RCR2 (* ((volatile uint32_t *) (0x4002F000 + 0x88)))

  // Field (width: 8 bits): Bit Clock Divide
    inline uint32_t I2S0_RCR2_DIV (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Boolean field: Bit Clock Direction
    static const uint32_t I2S0_RCR2_BCD = 1U << 24 ;

  // Boolean field: Bit Clock Polarity
    static const uint32_t I2S0_RCR2_BCP = 1U << 25 ;

  // Field (width: 2 bits): MCLK Select
    inline uint32_t I2S0_RCR2_MSEL (const uint32_t inValue) { return (inValue & 3U) << 26 ; }

  // Boolean field: Bit Clock Input
    static const uint32_t I2S0_RCR2_BCI = 1U << 28 ;

  // Boolean field: Bit Clock Swap
    static const uint32_t I2S0_RCR2_BCS = 1U << 29 ;

  // Field (width: 2 bits): Synchronous Mode
    inline uint32_t I2S0_RCR2_SYNC (const uint32_t inValue) { return (inValue & 3U) << 30 ; }

//-------------------- SAI Receive Configuration 3 Register
#define I2S0_RCR3 (* ((volatile uint32_t *) (0x4002F000 + 0x8C)))

  // Field (width: 5 bits): Word Flag Configuration
    inline uint32_t I2S0_RCR3_WDFL (const uint32_t inValue) { return (inValue & 31U) << 0 ; }

  // Field (width: 2 bits): Receive Channel Enable
    inline uint32_t I2S0_RCR3_RCE (const uint32_t inValue) { return (inValue & 3U) << 16 ; }

  // Field (width: 2 bits): Channel FIFO Reset
    inline uint32_t I2S0_RCR3_CFR (const uint32_t inValue) { return (inValue & 3U) << 24 ; }

//-------------------- SAI Receive Configuration 4 Register
#define I2S0_RCR4 (* ((volatile uint32_t *) (0x4002F000 + 0x90)))

  // Boolean field: Frame Sync Direction
    static const uint32_t I2S0_RCR4_FSD = 1U << 0 ;

  // Boolean field: Frame Sync Polarity
    static const uint32_t I2S0_RCR4_FSP = 1U << 1 ;

  // Boolean field: On Demand Mode
    static const uint32_t I2S0_RCR4_ONDEM = 1U << 2 ;

  // Boolean field: Frame Sync Early
    static const uint32_t I2S0_RCR4_FSE = 1U << 3 ;

  // Boolean field: MSB First
    static const uint32_t I2S0_RCR4_MF = 1U << 4 ;

  // Field (width: 5 bits): Sync Width
    inline uint32_t I2S0_RCR4_SYWD (const uint32_t inValue) { return (inValue & 31U) << 8 ; }

  // Field (width: 5 bits): Frame Size
    inline uint32_t I2S0_RCR4_FRSZ (const uint32_t inValue) { return (inValue & 31U) << 16 ; }

  // Field (width: 2 bits): FIFO Packing Mode
    inline uint32_t I2S0_RCR4_FPACK (const uint32_t inValue) { return (inValue & 3U) << 24 ; }

  // Field (width: 2 bits): FIFO Combine Mode
    inline uint32_t I2S0_RCR4_FCOMB (const uint32_t inValue) { return (inValue & 3U) << 26 ; }

  // Boolean field: FIFO Continue on Error
    static const uint32_t I2S0_RCR4_FCONT = 1U << 28 ;

//-------------------- SAI Receive Configuration 5 Register
#define I2S0_RCR5 (* ((volatile uint32_t *) (0x4002F000 + 0x94)))

  // Field (width: 5 bits): First Bit Shifted
    inline uint32_t I2S0_RCR5_FBT (const uint32_t inValue) { return (inValue & 31U) << 8 ; }

  // Field (width: 5 bits): Word 0 Width
    inline uint32_t I2S0_RCR5_W0W (const uint32_t inValue) { return (inValue & 31U) << 16 ; }

  // Field (width: 5 bits): Word N Width
    inline uint32_t I2S0_RCR5_WNW (const uint32_t inValue) { return (inValue & 31U) << 24 ; }

//-------------------- SAI Receive Data Register (idx = 0 ... 1)
#define I2S0_RDR(idx) (* ((const volatile uint32_t *) (0x4002F000 + 0xA0 + 0x4 * (idx))))

//-------------------- SAI Receive FIFO Register (idx = 0 ... 1)
#define I2S0_RFR(idx) (* ((const volatile uint32_t *) (0x4002F000 + 0xC0 + 0x4 * (idx))))

  // Field (width: 4 bits): Read FIFO Pointer
    inline uint32_t I2S0_RFR_RFP (const uint32_t inValue) { return (inValue & 15U) << 0 ; }

  // Boolean field: Receive Channel Pointer
    static const uint32_t I2S0_RFR_RCP = 1U << 15 ;

  // Field (width: 4 bits): Write FIFO Pointer
    inline uint32_t I2S0_RFR_WFP (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

//-------------------- SAI Receive Mask Register
#define I2S0_RMR (* ((volatile uint32_t *) (0x4002F000 + 0xE0)))

//-------------------- SAI MCLK Control Register
#define I2S0_MCR (* ((volatile uint32_t *) (0x4002F000 + 0x100)))

  // Field (width: 2 bits): MCLK Input Clock Select
    inline uint32_t I2S0_MCR_MICS (const uint32_t inValue) { return (inValue & 3U) << 24 ; }

  // Boolean field: MCLK Output Enable
    static const uint32_t I2S0_MCR_MOE = 1U << 30 ;

  // Boolean field: Divider Update Flag
    static const uint32_t I2S0_MCR_DUF = 1U << 31 ;

//-------------------- SAI MCLK Divide Register
#define I2S0_MDR (* ((volatile uint32_t *) (0x4002F000 + 0x104)))

  // Field (width: 12 bits): MCLK Divide
    inline uint32_t I2S0_MDR_DIVIDE (const uint32_t inValue) { return (inValue & 4095U) << 0 ; }

  // Field (width: 8 bits): MCLK Fraction
    inline uint32_t I2S0_MDR_FRACT (const uint32_t inValue) { return (inValue & 255U) << 12 ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral CRC
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- CRC Data register
#define CRC_DATA (* ((volatile uint32_t *) (0x40032000 + 0)))

  // Field (width: 8 bits): CRC Low Lower Byte
    inline uint32_t CRC_DATA_LL (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): CRC Low Upper Byte
    inline uint32_t CRC_DATA_LU (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): CRC High Lower Byte
    inline uint32_t CRC_DATA_HL (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): CRC High Upper Byte
    inline uint32_t CRC_DATA_HU (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- CRC_DATAL register.
#define CRC_DATAL (* ((volatile uint16_t *) (0x40032000 + 0)))

//-------------------- CRC_DATALL register.
#define CRC_DATALL (* ((volatile uint8_t *) (0x40032000 + 0)))

//-------------------- CRC_DATALU register.
#define CRC_DATALU (* ((volatile uint8_t *) (0x40032000 + 0x1)))

//-------------------- CRC_DATAH register.
#define CRC_DATAH (* ((volatile uint16_t *) (0x40032000 + 0x2)))

//-------------------- CRC_DATAHL register.
#define CRC_DATAHL (* ((volatile uint8_t *) (0x40032000 + 0x2)))

//-------------------- CRC_DATAHU register.
#define CRC_DATAHU (* ((volatile uint8_t *) (0x40032000 + 0x3)))

//-------------------- CRC Polynomial register
#define CRC_GPOLY (* ((volatile uint32_t *) (0x40032000 + 0x4)))

  // Field (width: 16 bits): Low Polynominal Half-word
    inline uint32_t CRC_GPOLY_LOW (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Field (width: 16 bits): High Polynominal Half-word
    inline uint32_t CRC_GPOLY_HIGH (const uint32_t inValue) { return (inValue & 65535U) << 16 ; }

//-------------------- CRC_GPOLYL register.
#define CRC_GPOLYL (* ((volatile uint16_t *) (0x40032000 + 0x4)))

//-------------------- CRC_GPOLYLL register.
#define CRC_GPOLYLL (* ((volatile uint8_t *) (0x40032000 + 0x4)))

//-------------------- CRC_GPOLYLU register.
#define CRC_GPOLYLU (* ((volatile uint8_t *) (0x40032000 + 0x5)))

//-------------------- CRC_GPOLYH register.
#define CRC_GPOLYH (* ((volatile uint16_t *) (0x40032000 + 0x6)))

//-------------------- CRC_GPOLYHL register.
#define CRC_GPOLYHL (* ((volatile uint8_t *) (0x40032000 + 0x6)))

//-------------------- CRC_GPOLYHU register.
#define CRC_GPOLYHU (* ((volatile uint8_t *) (0x40032000 + 0x7)))

//-------------------- CRC Control register
#define CRC_CTRL (* ((volatile uint32_t *) (0x40032000 + 0x8)))

  // Boolean field: Width of CRC protocol.
    static const uint32_t CRC_CTRL_TCRC = 1U << 24 ;

  // Boolean field: Write CRC Data Register As Seed
    static const uint32_t CRC_CTRL_WAS = 1U << 25 ;

  // Boolean field: Complement Read Of CRC Data Register
    static const uint32_t CRC_CTRL_FXOR = 1U << 26 ;

  // Field (width: 2 bits): Type Of Transpose For Read
    inline uint32_t CRC_CTRL_TOTR (const uint32_t inValue) { return (inValue & 3U) << 28 ; }

  // Field (width: 2 bits): Type Of Transpose For Writes
    inline uint32_t CRC_CTRL_TOT (const uint32_t inValue) { return (inValue & 3U) << 30 ; }

//-------------------- CRC_CTRLHU register.
#define CRC_CTRLHU (* ((volatile uint8_t *) (0x40032000 + 0xB)))

  // Boolean field: no description available
    static const uint8_t CRC_CTRLHU_TCRC = 1U << 0 ;

  // Boolean field: no description available
    static const uint8_t CRC_CTRLHU_WAS = 1U << 1 ;

  // Boolean field: no description available
    static const uint8_t CRC_CTRLHU_FXOR = 1U << 2 ;

  // Field (width: 2 bits): no description available
    inline uint8_t CRC_CTRLHU_TOTR (const uint8_t inValue) { return (inValue & 3U) << 4 ; }

  // Field (width: 2 bits): no description available
    inline uint8_t CRC_CTRLHU_TOT (const uint8_t inValue) { return (inValue & 3U) << 6 ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral USBDCD
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Control register
#define USBDCD_CONTROL (* ((volatile uint32_t *) (0x40035000 + 0)))

  // Boolean field: Interrupt Acknowledge
    static const uint32_t USBDCD_CONTROL_IACK = 1U << 0 ;

  // Boolean field: Interrupt Flag
    static const uint32_t USBDCD_CONTROL_IF = 1U << 8 ;

  // Boolean field: Interrupt Enable
    static const uint32_t USBDCD_CONTROL_IE = 1U << 16 ;

  // Boolean field: BC1.2 compatibility. This bit cannot be changed after start detection.
    static const uint32_t USBDCD_CONTROL_BC12 = 1U << 17 ;

  // Boolean field: Start Change Detection Sequence
    static const uint32_t USBDCD_CONTROL_START = 1U << 24 ;

  // Boolean field: Software Reset
    static const uint32_t USBDCD_CONTROL_SR = 1U << 25 ;

//-------------------- Clock register
#define USBDCD_CLOCK (* ((volatile uint32_t *) (0x40035000 + 0x4)))

  // Boolean field: Unit of Measurement Encoding for Clock Speed
    static const uint32_t USBDCD_CLOCK_CLOCK_UNIT = 1U << 0 ;

  // Field (width: 10 bits): Numerical Value of Clock Speed in Binary
    inline uint32_t USBDCD_CLOCK_CLOCK_SPEED (const uint32_t inValue) { return (inValue & 1023U) << 2 ; }

//-------------------- Status register
#define USBDCD_STATUS (* ((const volatile uint32_t *) (0x40035000 + 0x8)))

  // Field (width: 2 bits): Charger Detection Sequence Results
    inline uint32_t USBDCD_STATUS_SEQ_RES (const uint32_t inValue) { return (inValue & 3U) << 16 ; }

  // Field (width: 2 bits): Charger Detection Sequence Status
    inline uint32_t USBDCD_STATUS_SEQ_STAT (const uint32_t inValue) { return (inValue & 3U) << 18 ; }

  // Boolean field: Error Flag
    static const uint32_t USBDCD_STATUS_ERR = 1U << 20 ;

  // Boolean field: Timeout Flag
    static const uint32_t USBDCD_STATUS_TO = 1U << 21 ;

  // Boolean field: Active Status Indicator
    static const uint32_t USBDCD_STATUS_ACTIVE = 1U << 22 ;

//-------------------- Signal Override Register
#define USBDCD_SIGNAL_OVERRIDE (* ((volatile uint32_t *) (0x40035000 + 0xC)))

  // Field (width: 2 bits): Phase Selection
    inline uint32_t USBDCD_SIGNAL_OVERRIDE_PS (const uint32_t inValue) { return (inValue & 3U) << 0 ; }

//-------------------- TIMER0 register
#define USBDCD_TIMER0 (* ((volatile uint32_t *) (0x40035000 + 0x10)))

  // Field (width: 12 bits): Unit Connection Timer Elapse (in ms)
    inline uint32_t USBDCD_TIMER0_TUNITCON (const uint32_t inValue) { return (inValue & 4095U) << 0 ; }

  // Field (width: 10 bits): Sequence Initiation Time
    inline uint32_t USBDCD_TIMER0_TSEQ_INIT (const uint32_t inValue) { return (inValue & 1023U) << 16 ; }

//-------------------- TIMER1 register
#define USBDCD_TIMER1 (* ((volatile uint32_t *) (0x40035000 + 0x14)))

  // Field (width: 10 bits): Time Period Comparator Enabled
    inline uint32_t USBDCD_TIMER1_TVDPSRC_ON (const uint32_t inValue) { return (inValue & 1023U) << 0 ; }

  // Field (width: 10 bits): Time Period to Debounce D+ Signal
    inline uint32_t USBDCD_TIMER1_TDCD_DBNC (const uint32_t inValue) { return (inValue & 1023U) << 16 ; }

//-------------------- TIMER2_BC11 register
#define USBDCD_TIMER2_BC11 (* ((volatile uint32_t *) (0x40035000 + 0x18)))

  // Field (width: 4 bits): Time Before Check of D- Line
    inline uint32_t USBDCD_TIMER2_BC11_CHECK_DM (const uint32_t inValue) { return (inValue & 15U) << 0 ; }

  // Field (width: 10 bits): Time Period Before Enabling D+ Pullup
    inline uint32_t USBDCD_TIMER2_BC11_TVDPSRC_CON (const uint32_t inValue) { return (inValue & 1023U) << 16 ; }

//-------------------- TIMER2_BC12 register
#define USBDCD_TIMER2_BC12 (* ((volatile uint32_t *) (0x40035000 + 0x18)))

  // Field (width: 10 bits): Sets the amount of time (in ms) that the module enables the VDM_SRC. Valid values are 0-40ms.
    inline uint32_t USBDCD_TIMER2_BC12_TVDMSRC_ON (const uint32_t inValue) { return (inValue & 1023U) << 0 ; }

  // Field (width: 10 bits): Sets the amount of time (in ms) that the module waits after primary detection before start to secondary detection
    inline uint32_t USBDCD_TIMER2_BC12_TWAIT_AFTER_PRD (const uint32_t inValue) { return (inValue & 1023U) << 16 ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral PDB0
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Status and Control register
#define PDB0_SC (* ((volatile uint32_t *) (0x40036000 + 0)))

  // Boolean field: Load OK
    static const uint32_t PDB0_SC_LDOK = 1U << 0 ;

  // Boolean field: Continuous Mode Enable
    static const uint32_t PDB0_SC_CONT = 1U << 1 ;

  // Field (width: 2 bits): Multiplication Factor Select for Prescaler
    inline uint32_t PDB0_SC_MULT (const uint32_t inValue) { return (inValue & 3U) << 2 ; }

  // Boolean field: PDB Interrupt Enable
    static const uint32_t PDB0_SC_PDBIE = 1U << 5 ;

  // Boolean field: PDB Interrupt Flag
    static const uint32_t PDB0_SC_PDBIF = 1U << 6 ;

  // Boolean field: PDB Enable
    static const uint32_t PDB0_SC_PDBEN = 1U << 7 ;

  // Field (width: 4 bits): Trigger Input Source Select
    inline uint32_t PDB0_SC_TRGSEL (const uint32_t inValue) { return (inValue & 15U) << 8 ; }

  // Field (width: 3 bits): Prescaler Divider Select
    inline uint32_t PDB0_SC_PRESCALER (const uint32_t inValue) { return (inValue & 7U) << 12 ; }

  // Boolean field: DMA Enable
    static const uint32_t PDB0_SC_DMAEN = 1U << 15 ;

  // Boolean field: Software Trigger
    static const uint32_t PDB0_SC_SWTRIG = 1U << 16 ;

  // Boolean field: PDB Sequence Error Interrupt Enable
    static const uint32_t PDB0_SC_PDBEIE = 1U << 17 ;

  // Field (width: 2 bits): Load Mode Select
    inline uint32_t PDB0_SC_LDMOD (const uint32_t inValue) { return (inValue & 3U) << 18 ; }

//-------------------- Modulus register
#define PDB0_MOD (* ((volatile uint32_t *) (0x40036000 + 0x4)))

  // Field (width: 16 bits): PDB Modulus
    inline uint32_t PDB0_MOD_MOD (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Counter register
#define PDB0_CNT (* ((const volatile uint32_t *) (0x40036000 + 0x8)))

  // Field (width: 16 bits): PDB Counter
    inline uint32_t PDB0_CNT_CNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Interrupt Delay register
#define PDB0_IDLY (* ((volatile uint32_t *) (0x40036000 + 0xC)))

  // Field (width: 16 bits): PDB Interrupt Delay
    inline uint32_t PDB0_IDLY_IDLY (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Channel n Control register 1 (idx = 0 ... 1)
#define PDB0_CHC1(idx) (* ((volatile uint32_t *) (0x40036000 + 0x10 + 0x28 * (idx))))

  // Field (width: 8 bits): PDB Channel Pre-Trigger Enable
    inline uint32_t PDB0_CHC1_EN (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): PDB Channel Pre-Trigger Output Select
    inline uint32_t PDB0_CHC1_TOS (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): PDB Channel Pre-Trigger Back-to-Back Operation Enable
    inline uint32_t PDB0_CHC1_BB (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

//-------------------- Channel n Status register (idx = 0 ... 1)
#define PDB0_CHS(idx) (* ((volatile uint32_t *) (0x40036000 + 0x14 + 0x28 * (idx))))

  // Field (width: 8 bits): PDB Channel Sequence Error Flags
    inline uint32_t PDB0_CHS_ERR (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): PDB Channel Flags
    inline uint32_t PDB0_CHS_CF (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

//-------------------- Channel n Delay 0 register (idx = 0 ... 1)
#define PDB0_CHDLY0(idx) (* ((volatile uint32_t *) (0x40036000 + 0x18 + 0x28 * (idx))))

  // Field (width: 16 bits): PDB Channel Delay
    inline uint32_t PDB0_CHDLY0_DLY (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Channel n Delay 1 register (idx = 0 ... 1)
#define PDB0_CHDLY1(idx) (* ((volatile uint32_t *) (0x40036000 + 0x1C + 0x28 * (idx))))

  // Field (width: 16 bits): PDB Channel Delay
    inline uint32_t PDB0_CHDLY1_DLY (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- DAC Interval Trigger n Control register (idx = 0 ... 1)
#define PDB0_DACINTC(idx) (* ((volatile uint32_t *) (0x40036000 + 0x150 + 0x8 * (idx))))

  // Boolean field: DAC Interval Trigger Enable
    static const uint32_t PDB0_DACINTC_TOE = 1U << 0 ;

  // Boolean field: DAC External Trigger Input Enable
    static const uint32_t PDB0_DACINTC_EXT = 1U << 1 ;

//-------------------- DAC Interval n register (idx = 0 ... 1)
#define PDB0_DACINT(idx) (* ((volatile uint32_t *) (0x40036000 + 0x154 + 0x8 * (idx))))

  // Field (width: 16 bits): DAC Interval
    inline uint32_t PDB0_DACINT_INT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Pulse-Out n Enable register
#define PDB0_POEN (* ((volatile uint32_t *) (0x40036000 + 0x190)))

  // Field (width: 8 bits): PDB Pulse-Out Enable
    inline uint32_t PDB0_POEN_POEN (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

//-------------------- Pulse-Out n Delay register (idx = 0 ... 3)
#define PDB0_PODLY(idx) (* ((volatile uint32_t *) (0x40036000 + 0x194 + 0x4 * (idx))))

  // Field (width: 16 bits): PDB Pulse-Out Delay 2
    inline uint32_t PDB0_PODLY_DLY2 (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Field (width: 16 bits): PDB Pulse-Out Delay 1
    inline uint32_t PDB0_PODLY_DLY1 (const uint32_t inValue) { return (inValue & 65535U) << 16 ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral PIT
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- PIT Module Control Register
#define PIT_MCR (* ((volatile uint32_t *) (0x40037000 + 0)))

  // Boolean field: Freeze
    static const uint32_t PIT_MCR_FRZ = 1U << 0 ;

  // Boolean field: Module Disable - (PIT section)
    static const uint32_t PIT_MCR_MDIS = 1U << 1 ;

//-------------------- PIT Upper Lifetime Timer Register
#define PIT_LTMR64H (* ((const volatile uint32_t *) (0x40037000 + 0xE0)))

//-------------------- PIT Lower Lifetime Timer Register
#define PIT_LTMR64L (* ((const volatile uint32_t *) (0x40037000 + 0xE4)))

//-------------------- Timer Load Value Register (idx = 0 ... 3)
#define PIT_LDVAL(idx) (* ((volatile uint32_t *) (0x40037000 + 0x100 + 0x10 * (idx))))

//-------------------- Current Timer Value Register (idx = 0 ... 3)
#define PIT_CVAL(idx) (* ((const volatile uint32_t *) (0x40037000 + 0x104 + 0x10 * (idx))))

//-------------------- Timer Control Register (idx = 0 ... 3)
#define PIT_TCTRL(idx) (* ((volatile uint32_t *) (0x40037000 + 0x108 + 0x10 * (idx))))

  // Boolean field: Timer Enable
    static const uint32_t PIT_TCTRL_TEN = 1U << 0 ;

  // Boolean field: Timer Interrupt Enable
    static const uint32_t PIT_TCTRL_TIE = 1U << 1 ;

  // Boolean field: Chain Mode
    static const uint32_t PIT_TCTRL_CHN = 1U << 2 ;

//-------------------- Timer Flag Register (idx = 0 ... 3)
#define PIT_TFLG(idx) (* ((volatile uint32_t *) (0x40037000 + 0x10C + 0x10 * (idx))))

  // Boolean field: Timer Interrupt Flag
    static const uint32_t PIT_TFLG_TIF = 1U << 0 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral RTC
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- RTC Time Seconds Register
#define RTC_TSR (* ((volatile uint32_t *) (0x4003D000 + 0)))

//-------------------- RTC Time Prescaler Register
#define RTC_TPR (* ((volatile uint32_t *) (0x4003D000 + 0x4)))

  // Field (width: 16 bits): Time Prescaler Register
    inline uint32_t RTC_TPR_TPR (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- RTC Time Alarm Register
#define RTC_TAR (* ((volatile uint32_t *) (0x4003D000 + 0x8)))

//-------------------- RTC Time Compensation Register
#define RTC_TCR (* ((volatile uint32_t *) (0x4003D000 + 0xC)))

  // Field (width: 8 bits): Time Compensation Register
    inline uint32_t RTC_TCR_TCR (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Compensation Interval Register
    inline uint32_t RTC_TCR_CIR (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Time Compensation Value
    inline uint32_t RTC_TCR_TCV (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Compensation Interval Counter
    inline uint32_t RTC_TCR_CIC (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- RTC Control Register
#define RTC_CR (* ((volatile uint32_t *) (0x4003D000 + 0x10)))

  // Boolean field: Software Reset
    static const uint32_t RTC_CR_SWR = 1U << 0 ;

  // Boolean field: Wakeup Pin Enable
    static const uint32_t RTC_CR_WPE = 1U << 1 ;

  // Boolean field: Supervisor Access
    static const uint32_t RTC_CR_SUP = 1U << 2 ;

  // Boolean field: Update Mode
    static const uint32_t RTC_CR_UM = 1U << 3 ;

  // Boolean field: Wakeup Pin Select
    static const uint32_t RTC_CR_WPS = 1U << 4 ;

  // Boolean field: Oscillator Enable
    static const uint32_t RTC_CR_OSCE = 1U << 8 ;

  // Boolean field: Clock Output
    static const uint32_t RTC_CR_CLKO = 1U << 9 ;

  // Boolean field: Oscillator 16pF Load Configure
    static const uint32_t RTC_CR_SC16P = 1U << 10 ;

  // Boolean field: Oscillator 8pF Load Configure
    static const uint32_t RTC_CR_SC8P = 1U << 11 ;

  // Boolean field: Oscillator 4pF Load Configure
    static const uint32_t RTC_CR_SC4P = 1U << 12 ;

  // Boolean field: Oscillator 2pF Load Configure
    static const uint32_t RTC_CR_SC2P = 1U << 13 ;

//-------------------- RTC Status Register
#define RTC_SR (* ((volatile uint32_t *) (0x4003D000 + 0x14)))

  // Boolean field: Time Invalid Flag
    static const uint32_t RTC_SR_TIF = 1U << 0 ;

  // Boolean field: Time Overflow Flag
    static const uint32_t RTC_SR_TOF = 1U << 1 ;

  // Boolean field: Time Alarm Flag
    static const uint32_t RTC_SR_TAF = 1U << 2 ;

  // Boolean field: Monotonic Overflow Flag
    static const uint32_t RTC_SR_MOF = 1U << 3 ;

  // Boolean field: Time Counter Enable
    static const uint32_t RTC_SR_TCE = 1U << 4 ;

//-------------------- RTC Lock Register
#define RTC_LR (* ((volatile uint32_t *) (0x4003D000 + 0x18)))

  // Boolean field: Time Compensation Lock
    static const uint32_t RTC_LR_TCL = 1U << 3 ;

  // Boolean field: Control Register Lock
    static const uint32_t RTC_LR_CRL = 1U << 4 ;

  // Boolean field: Status Register Lock
    static const uint32_t RTC_LR_SRL = 1U << 5 ;

  // Boolean field: Lock Register Lock
    static const uint32_t RTC_LR_LRL = 1U << 6 ;

  // Boolean field: Tamper Time Seconds Lock
    static const uint32_t RTC_LR_TTSL = 1U << 8 ;

  // Boolean field: Monotonic Enable Lock
    static const uint32_t RTC_LR_MEL = 1U << 9 ;

  // Boolean field: Monotonic Counter Low Lock
    static const uint32_t RTC_LR_MCLL = 1U << 10 ;

  // Boolean field: Monotonic Counter High Lock
    static const uint32_t RTC_LR_MCHL = 1U << 11 ;

//-------------------- RTC Interrupt Enable Register
#define RTC_IER (* ((volatile uint32_t *) (0x4003D000 + 0x1C)))

  // Boolean field: Time Invalid Interrupt Enable
    static const uint32_t RTC_IER_TIIE = 1U << 0 ;

  // Boolean field: Time Overflow Interrupt Enable
    static const uint32_t RTC_IER_TOIE = 1U << 1 ;

  // Boolean field: Time Alarm Interrupt Enable
    static const uint32_t RTC_IER_TAIE = 1U << 2 ;

  // Boolean field: Monotonic Overflow Interrupt Enable
    static const uint32_t RTC_IER_MOIE = 1U << 3 ;

  // Boolean field: Time Seconds Interrupt Enable
    static const uint32_t RTC_IER_TSIE = 1U << 4 ;

  // Boolean field: Wakeup Pin On
    static const uint32_t RTC_IER_WPON = 1U << 7 ;

//-------------------- RTC Tamper Time Seconds Register
#define RTC_TTSR (* ((const volatile uint32_t *) (0x4003D000 + 0x20)))

//-------------------- RTC Monotonic Enable Register
#define RTC_MER (* ((volatile uint32_t *) (0x4003D000 + 0x24)))

  // Boolean field: Monotonic Counter Enable
    static const uint32_t RTC_MER_MCE = 1U << 4 ;

//-------------------- RTC Monotonic Counter Low Register
#define RTC_MCLR (* ((volatile uint32_t *) (0x4003D000 + 0x28)))

//-------------------- RTC Monotonic Counter High Register
#define RTC_MCHR (* ((volatile uint32_t *) (0x4003D000 + 0x2C)))

//-------------------- RTC Write Access Register
#define RTC_WAR (* ((volatile uint32_t *) (0x4003D000 + 0x800)))

  // Boolean field: Time Seconds Register Write
    static const uint32_t RTC_WAR_TSRW = 1U << 0 ;

  // Boolean field: Time Prescaler Register Write
    static const uint32_t RTC_WAR_TPRW = 1U << 1 ;

  // Boolean field: Time Alarm Register Write
    static const uint32_t RTC_WAR_TARW = 1U << 2 ;

  // Boolean field: Time Compensation Register Write
    static const uint32_t RTC_WAR_TCRW = 1U << 3 ;

  // Boolean field: Control Register Write
    static const uint32_t RTC_WAR_CRW = 1U << 4 ;

  // Boolean field: Status Register Write
    static const uint32_t RTC_WAR_SRW = 1U << 5 ;

  // Boolean field: Lock Register Write
    static const uint32_t RTC_WAR_LRW = 1U << 6 ;

  // Boolean field: Interrupt Enable Register Write
    static const uint32_t RTC_WAR_IERW = 1U << 7 ;

  // Boolean field: Tamper Time Seconds Write
    static const uint32_t RTC_WAR_TTSW = 1U << 8 ;

  // Boolean field: Monotonic Enable Register Write
    static const uint32_t RTC_WAR_MERW = 1U << 9 ;

  // Boolean field: Monotonic Counter Low Write
    static const uint32_t RTC_WAR_MCLW = 1U << 10 ;

  // Boolean field: Monotonic Counter High Write
    static const uint32_t RTC_WAR_MCHW = 1U << 11 ;

//-------------------- RTC Read Access Register
#define RTC_RAR (* ((volatile uint32_t *) (0x4003D000 + 0x804)))

  // Boolean field: Time Seconds Register Read
    static const uint32_t RTC_RAR_TSRR = 1U << 0 ;

  // Boolean field: Time Prescaler Register Read
    static const uint32_t RTC_RAR_TPRR = 1U << 1 ;

  // Boolean field: Time Alarm Register Read
    static const uint32_t RTC_RAR_TARR = 1U << 2 ;

  // Boolean field: Time Compensation Register Read
    static const uint32_t RTC_RAR_TCRR = 1U << 3 ;

  // Boolean field: Control Register Read
    static const uint32_t RTC_RAR_CRR = 1U << 4 ;

  // Boolean field: Status Register Read
    static const uint32_t RTC_RAR_SRR = 1U << 5 ;

  // Boolean field: Lock Register Read
    static const uint32_t RTC_RAR_LRR = 1U << 6 ;

  // Boolean field: Interrupt Enable Register Read
    static const uint32_t RTC_RAR_IERR = 1U << 7 ;

  // Boolean field: Tamper Time Seconds Read
    static const uint32_t RTC_RAR_TTSR = 1U << 8 ;

  // Boolean field: Monotonic Enable Register Read
    static const uint32_t RTC_RAR_MERR = 1U << 9 ;

  // Boolean field: Monotonic Counter Low Read
    static const uint32_t RTC_RAR_MCLR = 1U << 10 ;

  // Boolean field: Monotonic Counter High Read
    static const uint32_t RTC_RAR_MCHR = 1U << 11 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral RFVBAT
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- VBAT register file register (idx = 0 ... 7)
#define RFVBAT_REG(idx) (* ((volatile uint32_t *) (0x4003E000 + 0 + 0x4 * (idx))))

  // Field (width: 8 bits): Low lower byte
    inline uint32_t RFVBAT_REG_LL (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Low higher byte
    inline uint32_t RFVBAT_REG_LH (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): High lower byte
    inline uint32_t RFVBAT_REG_HL (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): High higher byte
    inline uint32_t RFVBAT_REG_HH (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral LPTMR0
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Low Power Timer Control Status Register
#define LPTMR0_CSR (* ((volatile uint32_t *) (0x40040000 + 0)))

  // Boolean field: Timer Enable
    static const uint32_t LPTMR0_CSR_TEN = 1U << 0 ;

  // Boolean field: Timer Mode Select
    static const uint32_t LPTMR0_CSR_TMS = 1U << 1 ;

  // Boolean field: Timer Free-Running Counter
    static const uint32_t LPTMR0_CSR_TFC = 1U << 2 ;

  // Boolean field: Timer Pin Polarity
    static const uint32_t LPTMR0_CSR_TPP = 1U << 3 ;

  // Field (width: 2 bits): Timer Pin Select
    inline uint32_t LPTMR0_CSR_TPS (const uint32_t inValue) { return (inValue & 3U) << 4 ; }

  // Boolean field: Timer Interrupt Enable
    static const uint32_t LPTMR0_CSR_TIE = 1U << 6 ;

  // Boolean field: Timer Compare Flag
    static const uint32_t LPTMR0_CSR_TCF = 1U << 7 ;

//-------------------- Low Power Timer Prescale Register
#define LPTMR0_PSR (* ((volatile uint32_t *) (0x40040000 + 0x4)))

  // Field (width: 2 bits): Prescaler Clock Select
    inline uint32_t LPTMR0_PSR_PCS (const uint32_t inValue) { return (inValue & 3U) << 0 ; }

  // Boolean field: Prescaler Bypass
    static const uint32_t LPTMR0_PSR_PBYP = 1U << 2 ;

  // Field (width: 4 bits): Prescale Value
    inline uint32_t LPTMR0_PSR_PRESCALE (const uint32_t inValue) { return (inValue & 15U) << 3 ; }

//-------------------- Low Power Timer Compare Register
#define LPTMR0_CMR (* ((volatile uint32_t *) (0x40040000 + 0x8)))

  // Field (width: 16 bits): Compare Value
    inline uint32_t LPTMR0_CMR_COMPARE (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Low Power Timer Counter Register
#define LPTMR0_CNR (* ((volatile uint32_t *) (0x40040000 + 0xC)))

  // Field (width: 16 bits): Counter Value
    inline uint32_t LPTMR0_CNR_COUNTER (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral RFSYS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Register file register (idx = 0 ... 7)
#define RFSYS_REG(idx) (* ((volatile uint32_t *) (0x40041000 + 0 + 0x4 * (idx))))

  // Field (width: 8 bits): Low lower byte
    inline uint32_t RFSYS_REG_LL (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Low higher byte
    inline uint32_t RFSYS_REG_LH (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): High lower byte
    inline uint32_t RFSYS_REG_HL (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): High higher byte
    inline uint32_t RFSYS_REG_HH (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral TSI0
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- TSI General Control and Status Register
#define TSI0_GENCS (* ((volatile uint32_t *) (0x40045000 + 0)))

  // Boolean field: End-of-Scan DMA Transfer Request Enable Only
    static const uint32_t TSI0_GENCS_EOSDMEO = 1U << 0 ;

  // Boolean field: CURSW
    static const uint32_t TSI0_GENCS_CURSW = 1U << 1 ;

  // Boolean field: End of Scan Flag
    static const uint32_t TSI0_GENCS_EOSF = 1U << 2 ;

  // Boolean field: Scan In Progress Status
    static const uint32_t TSI0_GENCS_SCNIP = 1U << 3 ;

  // Boolean field: Scan Trigger Mode
    static const uint32_t TSI0_GENCS_STM = 1U << 4 ;

  // Boolean field: TSI STOP Enable
    static const uint32_t TSI0_GENCS_STPE = 1U << 5 ;

  // Boolean field: Touch Sensing Input Interrupt Enable
    static const uint32_t TSI0_GENCS_TSIIEN = 1U << 6 ;

  // Boolean field: Touch Sensing Input Module Enable
    static const uint32_t TSI0_GENCS_TSIEN = 1U << 7 ;

  // Field (width: 5 bits): NSCN
    inline uint32_t TSI0_GENCS_NSCN (const uint32_t inValue) { return (inValue & 31U) << 8 ; }

  // Field (width: 3 bits): PS
    inline uint32_t TSI0_GENCS_PS (const uint32_t inValue) { return (inValue & 7U) << 13 ; }

  // Field (width: 3 bits): EXTCHRG
    inline uint32_t TSI0_GENCS_EXTCHRG (const uint32_t inValue) { return (inValue & 7U) << 16 ; }

  // Field (width: 2 bits): DVOLT
    inline uint32_t TSI0_GENCS_DVOLT (const uint32_t inValue) { return (inValue & 3U) << 19 ; }

  // Field (width: 3 bits): REFCHRG
    inline uint32_t TSI0_GENCS_REFCHRG (const uint32_t inValue) { return (inValue & 7U) << 21 ; }

  // Field (width: 4 bits): TSI analog modes setup and status bits.
    inline uint32_t TSI0_GENCS_MODE (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Boolean field: End-of-scan or Out-of-Range Interrupt Selection
    static const uint32_t TSI0_GENCS_ESOR = 1U << 28 ;

  // Boolean field: Out of Range Flag.
    static const uint32_t TSI0_GENCS_OUTRGF = 1U << 31 ;

//-------------------- TSI DATA Register
#define TSI0_DATA (* ((volatile uint32_t *) (0x40045000 + 0x4)))

  // Field (width: 16 bits): TSI Conversion Counter Value
    inline uint32_t TSI0_DATA_TSICNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Boolean field: Software Trigger Start
    static const uint32_t TSI0_DATA_SWTS = 1U << 22 ;

  // Boolean field: DMA Transfer Enabled
    static const uint32_t TSI0_DATA_DMAEN = 1U << 23 ;

  // Field (width: 4 bits): TSICH
    inline uint32_t TSI0_DATA_TSICH (const uint32_t inValue) { return (inValue & 15U) << 28 ; }

//-------------------- TSI Threshold Register
#define TSI0_TSHD (* ((volatile uint32_t *) (0x40045000 + 0x8)))

  // Field (width: 16 bits): TSI Wakeup Channel Low-threshold
    inline uint32_t TSI0_TSHD_THRESL (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Field (width: 16 bits): TSI Wakeup Channel High-threshold
    inline uint32_t TSI0_TSHD_THRESH (const uint32_t inValue) { return (inValue & 65535U) << 16 ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral SIM
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- System Options Register 1
#define SIM_SOPT1 (* ((volatile uint32_t *) (0x40047000 + 0)))

  // Field (width: 4 bits): RAM size
    inline uint32_t SIM_SOPT1_RAMSIZE (const uint32_t inValue) { return (inValue & 15U) << 12 ; }

  // Field (width: 2 bits): 32K oscillator clock select
    inline uint32_t SIM_SOPT1_OSC32KSEL (const uint32_t inValue) { return (inValue & 3U) << 18 ; }

  // Boolean field: USB voltage regulator in standby mode during VLPR and VLPW modes
    static const uint32_t SIM_SOPT1_USBVSTBY = 1U << 29 ;

  // Boolean field: USB voltage regulator in standby mode during Stop, VLPS, LLS and VLLS modes.
    static const uint32_t SIM_SOPT1_USBSSTBY = 1U << 30 ;

  // Boolean field: USB voltage regulator enable
    static const uint32_t SIM_SOPT1_USBREGEN = 1U << 31 ;

//-------------------- SOPT1 Configuration Register
#define SIM_SOPT1CFG (* ((volatile uint32_t *) (0x40047000 + 0x4)))

  // Boolean field: USB voltage regulator enable write enable
    static const uint32_t SIM_SOPT1CFG_URWE = 1U << 24 ;

  // Boolean field: USB voltage regulator VLP standby write enable
    static const uint32_t SIM_SOPT1CFG_UVSWE = 1U << 25 ;

  // Boolean field: USB voltage regulator stop standby write enable
    static const uint32_t SIM_SOPT1CFG_USSWE = 1U << 26 ;

//-------------------- USB PHY Control Register
#define SIM_USBPHYCTL (* ((volatile uint32_t *) (0x40047000 + 0x8)))

  // Boolean field: Selects the default input voltage source to the USB Regulator in case both VREG_IN0 and VREG_IN1 are powered
    static const uint32_t SIM_USBPHYCTL_USBVREGSEL = 1U << 8 ;

  // Boolean field: Enables the pulldown on the output of the USB Regulator.
    static const uint32_t SIM_USBPHYCTL_USBVREGPD = 1U << 9 ;

  // Field (width: 3 bits): USB 3.3V Output Target
    inline uint32_t SIM_USBPHYCTL_USB3VOUTTRG (const uint32_t inValue) { return (inValue & 7U) << 20 ; }

  // Boolean field: USB Disable Inrush Current Limit
    static const uint32_t SIM_USBPHYCTL_USBDISILIM = 1U << 23 ;

//-------------------- System Options Register 2
#define SIM_SOPT2 (* ((volatile uint32_t *) (0x40047000 + 0x1004)))

  // Boolean field: USB Slow Clock Source
    static const uint32_t SIM_SOPT2_USBSLSRC = 1U << 0 ;

  // Boolean field: USB PHY PLL Regulator Enable
    static const uint32_t SIM_SOPT2_USBREGEN = 1U << 1 ;

  // Boolean field: RTC clock out select
    static const uint32_t SIM_SOPT2_RTCCLKOUTSEL = 1U << 4 ;

  // Field (width: 3 bits): CLKOUT select
    inline uint32_t SIM_SOPT2_CLKOUTSEL (const uint32_t inValue) { return (inValue & 7U) << 5 ; }

  // Field (width: 2 bits): FlexBus security level
    inline uint32_t SIM_SOPT2_FBSL (const uint32_t inValue) { return (inValue & 3U) << 8 ; }

  // Boolean field: Debug trace clock select
    static const uint32_t SIM_SOPT2_TRACECLKSEL = 1U << 12 ;

  // Field (width: 2 bits): PLL/FLL clock select
    inline uint32_t SIM_SOPT2_PLLFLLSEL (const uint32_t inValue) { return (inValue & 3U) << 16 ; }

  // Boolean field: USB clock source select
    static const uint32_t SIM_SOPT2_USBSRC = 1U << 18 ;

  // Boolean field: RMII clock source select
    static const uint32_t SIM_SOPT2_RMIISRC = 1U << 19 ;

  // Field (width: 2 bits): IEEE 1588 timestamp clock source select
    inline uint32_t SIM_SOPT2_TIMESRC (const uint32_t inValue) { return (inValue & 3U) << 20 ; }

  // Field (width: 2 bits): TPM clock source select
    inline uint32_t SIM_SOPT2_TPMSRC (const uint32_t inValue) { return (inValue & 3U) << 24 ; }

  // Field (width: 2 bits): LPUART clock source select
    inline uint32_t SIM_SOPT2_LPUARTSRC (const uint32_t inValue) { return (inValue & 3U) << 26 ; }

  // Field (width: 2 bits): SDHC clock source select
    inline uint32_t SIM_SOPT2_SDHCSRC (const uint32_t inValue) { return (inValue & 3U) << 28 ; }

//-------------------- System Options Register 4
#define SIM_SOPT4 (* ((volatile uint32_t *) (0x40047000 + 0x100C)))

  // Boolean field: FTM0 Fault 0 Select
    static const uint32_t SIM_SOPT4_FTM0FLT0 = 1U << 0 ;

  // Boolean field: FTM0 Fault 1 Select
    static const uint32_t SIM_SOPT4_FTM0FLT1 = 1U << 1 ;

  // Boolean field: FTM0 Fault 2 Select
    static const uint32_t SIM_SOPT4_FTM0FLT2 = 1U << 2 ;

  // Boolean field: FTM0 Fault 3 Select
    static const uint32_t SIM_SOPT4_FTM0FLT3 = 1U << 3 ;

  // Boolean field: FTM1 Fault 0 Select
    static const uint32_t SIM_SOPT4_FTM1FLT0 = 1U << 4 ;

  // Boolean field: FTM2 Fault 0 Select
    static const uint32_t SIM_SOPT4_FTM2FLT0 = 1U << 8 ;

  // Boolean field: FTM3 Fault 0 Select
    static const uint32_t SIM_SOPT4_FTM3FLT0 = 1U << 12 ;

  // Field (width: 2 bits): FTM1 channel 0 input capture source select
    inline uint32_t SIM_SOPT4_FTM1CH0SRC (const uint32_t inValue) { return (inValue & 3U) << 18 ; }

  // Field (width: 2 bits): FTM2 channel 0 input capture source select
    inline uint32_t SIM_SOPT4_FTM2CH0SRC (const uint32_t inValue) { return (inValue & 3U) << 20 ; }

  // Boolean field: FTM2 channel 1 input capture source select
    static const uint32_t SIM_SOPT4_FTM2CH1SRC = 1U << 22 ;

  // Boolean field: FlexTimer 0 External Clock Pin Select
    static const uint32_t SIM_SOPT4_FTM0CLKSEL = 1U << 24 ;

  // Boolean field: FTM1 External Clock Pin Select
    static const uint32_t SIM_SOPT4_FTM1CLKSEL = 1U << 25 ;

  // Boolean field: FlexTimer 2 External Clock Pin Select
    static const uint32_t SIM_SOPT4_FTM2CLKSEL = 1U << 26 ;

  // Boolean field: FlexTimer 3 External Clock Pin Select
    static const uint32_t SIM_SOPT4_FTM3CLKSEL = 1U << 27 ;

  // Boolean field: FlexTimer 0 Hardware Trigger 0 Source Select
    static const uint32_t SIM_SOPT4_FTM0TRG0SRC = 1U << 28 ;

  // Boolean field: FlexTimer 0 Hardware Trigger 1 Source Select
    static const uint32_t SIM_SOPT4_FTM0TRG1SRC = 1U << 29 ;

  // Boolean field: FlexTimer 3 Hardware Trigger 0 Source Select
    static const uint32_t SIM_SOPT4_FTM3TRG0SRC = 1U << 30 ;

  // Boolean field: FlexTimer 3 Hardware Trigger 1 Source Select
    static const uint32_t SIM_SOPT4_FTM3TRG1SRC = 1U << 31 ;

//-------------------- System Options Register 5
#define SIM_SOPT5 (* ((volatile uint32_t *) (0x40047000 + 0x1010)))

  // Field (width: 2 bits): UART 0 transmit data source select
    inline uint32_t SIM_SOPT5_UART0TXSRC (const uint32_t inValue) { return (inValue & 3U) << 0 ; }

  // Field (width: 2 bits): UART 0 receive data source select
    inline uint32_t SIM_SOPT5_UART0RXSRC (const uint32_t inValue) { return (inValue & 3U) << 2 ; }

  // Field (width: 2 bits): UART 1 transmit data source select
    inline uint32_t SIM_SOPT5_UART1TXSRC (const uint32_t inValue) { return (inValue & 3U) << 4 ; }

  // Field (width: 2 bits): UART 1 receive data source select
    inline uint32_t SIM_SOPT5_UART1RXSRC (const uint32_t inValue) { return (inValue & 3U) << 6 ; }

  // Field (width: 2 bits): LPUART0 transmit data source select
    inline uint32_t SIM_SOPT5_LPUART0TXSRC (const uint32_t inValue) { return (inValue & 3U) << 16 ; }

  // Field (width: 2 bits): LPUART0 receive data source select
    inline uint32_t SIM_SOPT5_LPUART0RXSRC (const uint32_t inValue) { return (inValue & 3U) << 18 ; }

//-------------------- System Options Register 7
#define SIM_SOPT7 (* ((volatile uint32_t *) (0x40047000 + 0x1018)))

  // Field (width: 4 bits): ADC0 trigger select
    inline uint32_t SIM_SOPT7_ADC0TRGSEL (const uint32_t inValue) { return (inValue & 15U) << 0 ; }

  // Boolean field: ADC0 pretrigger select
    static const uint32_t SIM_SOPT7_ADC0PRETRGSEL = 1U << 4 ;

  // Boolean field: ADC0 alternate trigger enable
    static const uint32_t SIM_SOPT7_ADC0ALTTRGEN = 1U << 7 ;

  // Field (width: 4 bits): ADC1 trigger select
    inline uint32_t SIM_SOPT7_ADC1TRGSEL (const uint32_t inValue) { return (inValue & 15U) << 8 ; }

  // Boolean field: ADC1 pre-trigger select
    static const uint32_t SIM_SOPT7_ADC1PRETRGSEL = 1U << 12 ;

  // Boolean field: ADC1 alternate trigger enable
    static const uint32_t SIM_SOPT7_ADC1ALTTRGEN = 1U << 15 ;

//-------------------- System Options Register 8
#define SIM_SOPT8 (* ((volatile uint32_t *) (0x40047000 + 0x101C)))

  // Boolean field: FTM0 Hardware Trigger 0 Software Synchronization
    static const uint32_t SIM_SOPT8_FTM0SYNCBIT = 1U << 0 ;

  // Boolean field: FTM1 Hardware Trigger 0 Software Synchronization
    static const uint32_t SIM_SOPT8_FTM1SYNCBIT = 1U << 1 ;

  // Boolean field: FTM2 Hardware Trigger 0 Software Synchronization
    static const uint32_t SIM_SOPT8_FTM2SYNCBIT = 1U << 2 ;

  // Boolean field: FTM3 Hardware Trigger 0 Software Synchronization
    static const uint32_t SIM_SOPT8_FTM3SYNCBIT = 1U << 3 ;

  // Boolean field: FTM0 channel 0 output source
    static const uint32_t SIM_SOPT8_FTM0OCH0SRC = 1U << 16 ;

  // Boolean field: FTM0 channel 1 output source
    static const uint32_t SIM_SOPT8_FTM0OCH1SRC = 1U << 17 ;

  // Boolean field: FTM0 channel 2 output source
    static const uint32_t SIM_SOPT8_FTM0OCH2SRC = 1U << 18 ;

  // Boolean field: FTM0 channel 3 output source
    static const uint32_t SIM_SOPT8_FTM0OCH3SRC = 1U << 19 ;

  // Boolean field: FTM0 channel 4 output source
    static const uint32_t SIM_SOPT8_FTM0OCH4SRC = 1U << 20 ;

  // Boolean field: FTM0 channel 5 output source
    static const uint32_t SIM_SOPT8_FTM0OCH5SRC = 1U << 21 ;

  // Boolean field: FTM0 channel 6 output source
    static const uint32_t SIM_SOPT8_FTM0OCH6SRC = 1U << 22 ;

  // Boolean field: FTM0 channel 7 output source
    static const uint32_t SIM_SOPT8_FTM0OCH7SRC = 1U << 23 ;

  // Boolean field: FTM3 channel 0 output source
    static const uint32_t SIM_SOPT8_FTM3OCH0SRC = 1U << 24 ;

  // Boolean field: FTM3 channel 1 output source
    static const uint32_t SIM_SOPT8_FTM3OCH1SRC = 1U << 25 ;

  // Boolean field: FTM3 channel 2 output source
    static const uint32_t SIM_SOPT8_FTM3OCH2SRC = 1U << 26 ;

  // Boolean field: FTM3 channel 3 output source
    static const uint32_t SIM_SOPT8_FTM3OCH3SRC = 1U << 27 ;

  // Boolean field: FTM3 channel 4 output source
    static const uint32_t SIM_SOPT8_FTM3OCH4SRC = 1U << 28 ;

  // Boolean field: FTM3 channel 5 output source
    static const uint32_t SIM_SOPT8_FTM3OCH5SRC = 1U << 29 ;

  // Boolean field: FTM3 channel 6 output source
    static const uint32_t SIM_SOPT8_FTM3OCH6SRC = 1U << 30 ;

  // Boolean field: FTM3 channel 7 output source
    static const uint32_t SIM_SOPT8_FTM3OCH7SRC = 1U << 31 ;

//-------------------- System Options Register 9
#define SIM_SOPT9 (* ((volatile uint32_t *) (0x40047000 + 0x1020)))

  // Field (width: 2 bits): TPM1 channel 0 input capture source select
    inline uint32_t SIM_SOPT9_TPM1CH0SRC (const uint32_t inValue) { return (inValue & 3U) << 18 ; }

  // Field (width: 2 bits): TPM2 channel 0 input capture source select
    inline uint32_t SIM_SOPT9_TPM2CH0SRC (const uint32_t inValue) { return (inValue & 3U) << 20 ; }

  // Boolean field: TPM1 External Clock Pin Select
    static const uint32_t SIM_SOPT9_TPM1CLKSEL = 1U << 25 ;

  // Boolean field: TPM2 External Clock Pin Select
    static const uint32_t SIM_SOPT9_TPM2CLKSEL = 1U << 26 ;

//-------------------- System Device Identification Register
#define SIM_SDID (* ((const volatile uint32_t *) (0x40047000 + 0x1024)))

  // Field (width: 4 bits): Pincount identification
    inline uint32_t SIM_SDID_PINID (const uint32_t inValue) { return (inValue & 15U) << 0 ; }

  // Field (width: 3 bits): Kinetis family identification
    inline uint32_t SIM_SDID_FAMID (const uint32_t inValue) { return (inValue & 7U) << 4 ; }

  // Field (width: 5 bits): Device Die ID
    inline uint32_t SIM_SDID_DIEID (const uint32_t inValue) { return (inValue & 31U) << 7 ; }

  // Field (width: 4 bits): Device revision number
    inline uint32_t SIM_SDID_REVID (const uint32_t inValue) { return (inValue & 15U) << 12 ; }

  // Field (width: 4 bits): Kinetis Series ID
    inline uint32_t SIM_SDID_SERIESID (const uint32_t inValue) { return (inValue & 15U) << 20 ; }

  // Field (width: 4 bits): Kinetis Sub-Family ID
    inline uint32_t SIM_SDID_SUBFAMID (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Field (width: 4 bits): Kinetis Family ID
    inline uint32_t SIM_SDID_FAMILYID (const uint32_t inValue) { return (inValue & 15U) << 28 ; }

//-------------------- System Clock Gating Control Register 1
#define SIM_SCGC1 (* ((volatile uint32_t *) (0x40047000 + 0x1028)))

  // Boolean field: I2C2 Clock Gate Control
    static const uint32_t SIM_SCGC1_I2C2 = 1U << 6 ;

  // Boolean field: I2C3 Clock Gate Control
    static const uint32_t SIM_SCGC1_I2C3 = 1U << 7 ;

  // Boolean field: UART4 Clock Gate Control
    static const uint32_t SIM_SCGC1_UART4 = 1U << 10 ;

//-------------------- System Clock Gating Control Register 2
#define SIM_SCGC2 (* ((volatile uint32_t *) (0x40047000 + 0x102C)))

  // Boolean field: ENET Clock Gate Control
    static const uint32_t SIM_SCGC2_ENET = 1U << 0 ;

  // Boolean field: LPUART0 Clock Gate Control
    static const uint32_t SIM_SCGC2_LPUART0 = 1U << 4 ;

  // Boolean field: TPM1 Clock Gate Control
    static const uint32_t SIM_SCGC2_TPM1 = 1U << 9 ;

  // Boolean field: TPM2 Clock Gate Control
    static const uint32_t SIM_SCGC2_TPM2 = 1U << 10 ;

  // Boolean field: DAC0 Clock Gate Control
    static const uint32_t SIM_SCGC2_DAC0 = 1U << 12 ;

  // Boolean field: DAC1 Clock Gate Control
    static const uint32_t SIM_SCGC2_DAC1 = 1U << 13 ;

//-------------------- System Clock Gating Control Register 3
#define SIM_SCGC3 (* ((volatile uint32_t *) (0x40047000 + 0x1030)))

  // Boolean field: RNGA Clock Gate Control
    static const uint32_t SIM_SCGC3_RNGA = 1U << 0 ;

  // Boolean field: USBHS Clock Gate Control
    static const uint32_t SIM_SCGC3_USBHS = 1U << 1 ;

  // Boolean field: USBHS PHY Clock Gate Control
    static const uint32_t SIM_SCGC3_USBHSPHY = 1U << 2 ;

  // Boolean field: USBHS DCD Clock Gate Control
    static const uint32_t SIM_SCGC3_USBHSDCD = 1U << 3 ;

  // Boolean field: FlexCAN1 Clock Gate Control
    static const uint32_t SIM_SCGC3_FLEXCAN1 = 1U << 4 ;

  // Boolean field: SPI2 Clock Gate Control
    static const uint32_t SIM_SCGC3_SPI2 = 1U << 12 ;

  // Boolean field: SDHC Clock Gate Control
    static const uint32_t SIM_SCGC3_SDHC = 1U << 17 ;

  // Boolean field: FTM2 Clock Gate Control
    static const uint32_t SIM_SCGC3_FTM2 = 1U << 24 ;

  // Boolean field: FTM3 Clock Gate Control
    static const uint32_t SIM_SCGC3_FTM3 = 1U << 25 ;

  // Boolean field: ADC1 Clock Gate Control
    static const uint32_t SIM_SCGC3_ADC1 = 1U << 27 ;

//-------------------- System Clock Gating Control Register 4
#define SIM_SCGC4 (* ((volatile uint32_t *) (0x40047000 + 0x1034)))

  // Boolean field: EWM Clock Gate Control
    static const uint32_t SIM_SCGC4_EWM = 1U << 1 ;

  // Boolean field: CMT Clock Gate Control
    static const uint32_t SIM_SCGC4_CMT = 1U << 2 ;

  // Boolean field: I2C0 Clock Gate Control
    static const uint32_t SIM_SCGC4_I2C0 = 1U << 6 ;

  // Boolean field: I2C1 Clock Gate Control
    static const uint32_t SIM_SCGC4_I2C1 = 1U << 7 ;

  // Boolean field: UART0 Clock Gate Control
    static const uint32_t SIM_SCGC4_UART0 = 1U << 10 ;

  // Boolean field: UART1 Clock Gate Control
    static const uint32_t SIM_SCGC4_UART1 = 1U << 11 ;

  // Boolean field: UART2 Clock Gate Control
    static const uint32_t SIM_SCGC4_UART2 = 1U << 12 ;

  // Boolean field: UART3 Clock Gate Control
    static const uint32_t SIM_SCGC4_UART3 = 1U << 13 ;

  // Boolean field: USB Clock Gate Control
    static const uint32_t SIM_SCGC4_USBOTG = 1U << 18 ;

  // Boolean field: Comparator Clock Gate Control
    static const uint32_t SIM_SCGC4_CMP = 1U << 19 ;

  // Boolean field: VREF Clock Gate Control
    static const uint32_t SIM_SCGC4_VREF = 1U << 20 ;

//-------------------- System Clock Gating Control Register 5
#define SIM_SCGC5 (* ((volatile uint32_t *) (0x40047000 + 0x1038)))

  // Boolean field: Low Power Timer Access Control
    static const uint32_t SIM_SCGC5_LPTMR = 1U << 0 ;

  // Boolean field: TSI Clock Gate Control
    static const uint32_t SIM_SCGC5_TSI = 1U << 5 ;

  // Boolean field: Port A Clock Gate Control
    static const uint32_t SIM_SCGC5_PORTA = 1U << 9 ;

  // Boolean field: Port B Clock Gate Control
    static const uint32_t SIM_SCGC5_PORTB = 1U << 10 ;

  // Boolean field: Port C Clock Gate Control
    static const uint32_t SIM_SCGC5_PORTC = 1U << 11 ;

  // Boolean field: Port D Clock Gate Control
    static const uint32_t SIM_SCGC5_PORTD = 1U << 12 ;

  // Boolean field: Port E Clock Gate Control
    static const uint32_t SIM_SCGC5_PORTE = 1U << 13 ;

//-------------------- System Clock Gating Control Register 6
#define SIM_SCGC6 (* ((volatile uint32_t *) (0x40047000 + 0x103C)))

  // Boolean field: Flash Memory Clock Gate Control
    static const uint32_t SIM_SCGC6_FTF = 1U << 0 ;

  // Boolean field: DMA Mux Clock Gate Control
    static const uint32_t SIM_SCGC6_DMAMUX = 1U << 1 ;

  // Boolean field: FlexCAN0 Clock Gate Control
    static const uint32_t SIM_SCGC6_FLEXCAN0 = 1U << 4 ;

  // Boolean field: RNGA Clock Gate Control
    static const uint32_t SIM_SCGC6_RNGA = 1U << 9 ;

  // Boolean field: SPI0 Clock Gate Control
    static const uint32_t SIM_SCGC6_SPI0 = 1U << 12 ;

  // Boolean field: SPI1 Clock Gate Control
    static const uint32_t SIM_SCGC6_SPI1 = 1U << 13 ;

  // Boolean field: I2S Clock Gate Control
    static const uint32_t SIM_SCGC6_I2S = 1U << 15 ;

  // Boolean field: CRC Clock Gate Control
    static const uint32_t SIM_SCGC6_CRC = 1U << 18 ;

  // Boolean field: USB DCD Clock Gate Control
    static const uint32_t SIM_SCGC6_USBDCD = 1U << 21 ;

  // Boolean field: PDB Clock Gate Control
    static const uint32_t SIM_SCGC6_PDB = 1U << 22 ;

  // Boolean field: PIT Clock Gate Control
    static const uint32_t SIM_SCGC6_PIT = 1U << 23 ;

  // Boolean field: FTM0 Clock Gate Control
    static const uint32_t SIM_SCGC6_FTM0 = 1U << 24 ;

  // Boolean field: FTM1 Clock Gate Control
    static const uint32_t SIM_SCGC6_FTM1 = 1U << 25 ;

  // Boolean field: FTM2 Clock Gate Control
    static const uint32_t SIM_SCGC6_FTM2 = 1U << 26 ;

  // Boolean field: ADC0 Clock Gate Control
    static const uint32_t SIM_SCGC6_ADC0 = 1U << 27 ;

  // Boolean field: RTC Access Control
    static const uint32_t SIM_SCGC6_RTC = 1U << 29 ;

  // Boolean field: DAC0 Clock Gate Control
    static const uint32_t SIM_SCGC6_DAC0 = 1U << 31 ;

//-------------------- System Clock Gating Control Register 7
#define SIM_SCGC7 (* ((volatile uint32_t *) (0x40047000 + 0x1040)))

  // Boolean field: FlexBus Clock Gate Control
    static const uint32_t SIM_SCGC7_FLEXBUS = 1U << 0 ;

  // Boolean field: DMA Clock Gate Control
    static const uint32_t SIM_SCGC7_DMA = 1U << 1 ;

  // Boolean field: MPU Clock Gate Control
    static const uint32_t SIM_SCGC7_MPU = 1U << 2 ;

  // Boolean field: SDRAMC Clock Gate Control
    static const uint32_t SIM_SCGC7_SDRAMC = 1U << 3 ;

//-------------------- System Clock Divider Register 1
#define SIM_CLKDIV1 (* ((volatile uint32_t *) (0x40047000 + 0x1044)))

  // Field (width: 4 bits): Clock 4 output divider value
    inline uint32_t SIM_CLKDIV1_OUTDIV4 (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 4 bits): Clock 3 output divider value
    inline uint32_t SIM_CLKDIV1_OUTDIV3 (const uint32_t inValue) { return (inValue & 15U) << 20 ; }

  // Field (width: 4 bits): Clock 2 output divider value
    inline uint32_t SIM_CLKDIV1_OUTDIV2 (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Field (width: 4 bits): Clock 1 output divider value
    inline uint32_t SIM_CLKDIV1_OUTDIV1 (const uint32_t inValue) { return (inValue & 15U) << 28 ; }

//-------------------- System Clock Divider Register 2
#define SIM_CLKDIV2 (* ((volatile uint32_t *) (0x40047000 + 0x1048)))

  // Boolean field: USB clock divider fraction
    static const uint32_t SIM_CLKDIV2_USBFRAC = 1U << 0 ;

  // Field (width: 3 bits): USB clock divider divisor
    inline uint32_t SIM_CLKDIV2_USBDIV (const uint32_t inValue) { return (inValue & 7U) << 1 ; }

//-------------------- Flash Configuration Register 1
#define SIM_FCFG1 (* ((volatile uint32_t *) (0x40047000 + 0x104C)))

  // Boolean field: Flash Disable
    static const uint32_t SIM_FCFG1_FLASHDIS = 1U << 0 ;

  // Boolean field: Flash Doze
    static const uint32_t SIM_FCFG1_FLASHDOZE = 1U << 1 ;

  // Field (width: 4 bits): FlexNVM partition
    inline uint32_t SIM_FCFG1_DEPART (const uint32_t inValue) { return (inValue & 15U) << 8 ; }

  // Field (width: 4 bits): EEPROM size
    inline uint32_t SIM_FCFG1_EESIZE (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 4 bits): Program flash size
    inline uint32_t SIM_FCFG1_PFSIZE (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Field (width: 4 bits): FlexNVM size
    inline uint32_t SIM_FCFG1_NVMSIZE (const uint32_t inValue) { return (inValue & 15U) << 28 ; }

//-------------------- Flash Configuration Register 2
#define SIM_FCFG2 (* ((const volatile uint32_t *) (0x40047000 + 0x1050)))

  // Field (width: 7 bits): Max address block 1
    inline uint32_t SIM_FCFG2_MAXADDR1 (const uint32_t inValue) { return (inValue & 127U) << 16 ; }

  // Boolean field: Program flash only
    static const uint32_t SIM_FCFG2_PFLSH = 1U << 23 ;

  // Field (width: 7 bits): Max address block 0
    inline uint32_t SIM_FCFG2_MAXADDR0 (const uint32_t inValue) { return (inValue & 127U) << 24 ; }

  // Boolean field: Swap program flash
    static const uint32_t SIM_FCFG2_SWAPPFLSH = 1U << 31 ;

//-------------------- Unique Identification Register High
#define SIM_UIDH (* ((const volatile uint32_t *) (0x40047000 + 0x1054)))

//-------------------- Unique Identification Register Mid-High
#define SIM_UIDMH (* ((const volatile uint32_t *) (0x40047000 + 0x1058)))

//-------------------- Unique Identification Register Mid Low
#define SIM_UIDML (* ((const volatile uint32_t *) (0x40047000 + 0x105C)))

//-------------------- Unique Identification Register Low
#define SIM_UIDL (* ((const volatile uint32_t *) (0x40047000 + 0x1060)))

//-------------------- System Clock Divider Register 3
#define SIM_CLKDIV3 (* ((volatile uint32_t *) (0x40047000 + 0x1064)))

  // Boolean field: PLLFLL clock divider fraction
    static const uint32_t SIM_CLKDIV3_PLLFLLFRAC = 1U << 0 ;

  // Field (width: 3 bits): PLLFLL clock divider divisor
    inline uint32_t SIM_CLKDIV3_PLLFLLDIV (const uint32_t inValue) { return (inValue & 7U) << 1 ; }

//-------------------- System Clock Divider Register 4
#define SIM_CLKDIV4 (* ((volatile uint32_t *) (0x40047000 + 0x1068)))

  // Boolean field: Trace clock divider fraction
    static const uint32_t SIM_CLKDIV4_TRACEFRAC = 1U << 0 ;

  // Field (width: 3 bits): Trace clock divider divisor
    inline uint32_t SIM_CLKDIV4_TRACEDIV (const uint32_t inValue) { return (inValue & 7U) << 1 ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral WDOG
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Watchdog Status and Control Register High
#define WDOG_STCTRLH (* ((volatile uint16_t *) (0x40052000 + 0)))

  // Boolean field: Enables or disables the WDOG's operation
    static const uint16_t WDOG_STCTRLH_WDOGEN = 1U << 0 ;

  // Boolean field: Selects clock source for the WDOG timer and other internal timing operations.
    static const uint16_t WDOG_STCTRLH_CLKSRC = 1U << 1 ;

  // Boolean field: Used to enable the debug breadcrumbs feature
    static const uint16_t WDOG_STCTRLH_IRQRSTEN = 1U << 2 ;

  // Boolean field: Enables Windowing mode.
    static const uint16_t WDOG_STCTRLH_WINEN = 1U << 3 ;

  // Boolean field: Enables updates to watchdog write-once registers, after the reset-triggered initial configuration window (WCT) closes, through unlock sequence
    static const uint16_t WDOG_STCTRLH_ALLOWUPDATE = 1U << 4 ;

  // Boolean field: Enables or disables WDOG in Debug mode.
    static const uint16_t WDOG_STCTRLH_DBGEN = 1U << 5 ;

  // Boolean field: Enables or disables WDOG in Stop mode.
    static const uint16_t WDOG_STCTRLH_STOPEN = 1U << 6 ;

  // Boolean field: Enables or disables WDOG in Wait mode.
    static const uint16_t WDOG_STCTRLH_WAITEN = 1U << 7 ;

  // Boolean field: Puts the watchdog in the functional test mode
    static const uint16_t WDOG_STCTRLH_TESTWDOG = 1U << 10 ;

  // Boolean field: Effective only if TESTWDOG is set. Selects the test to be run on the watchdog timer.
    static const uint16_t WDOG_STCTRLH_TESTSEL = 1U << 11 ;

  // Field (width: 2 bits): This 2-bit field selects the byte to be tested when the watchdog is in the byte test mode.
    inline uint16_t WDOG_STCTRLH_BYTESEL (const uint16_t inValue) { return (inValue & 3U) << 12 ; }

  // Boolean field: Allows the WDOG's functional test mode to be disabled permanently
    static const uint16_t WDOG_STCTRLH_DISTESTWDOG = 1U << 14 ;

//-------------------- Watchdog Status and Control Register Low
#define WDOG_STCTRLL (* ((volatile uint16_t *) (0x40052000 + 0x2)))

  // Boolean field: Interrupt flag
    static const uint16_t WDOG_STCTRLL_INTFLG = 1U << 15 ;

//-------------------- Watchdog Time-out Value Register High
#define WDOG_TOVALH (* ((volatile uint16_t *) (0x40052000 + 0x4)))

//-------------------- Watchdog Time-out Value Register Low
#define WDOG_TOVALL (* ((volatile uint16_t *) (0x40052000 + 0x6)))

//-------------------- Watchdog Window Register High
#define WDOG_WINH (* ((volatile uint16_t *) (0x40052000 + 0x8)))

//-------------------- Watchdog Window Register Low
#define WDOG_WINL (* ((volatile uint16_t *) (0x40052000 + 0xA)))

//-------------------- Watchdog Refresh register
#define WDOG_REFRESH (* ((volatile uint16_t *) (0x40052000 + 0xC)))

//-------------------- Watchdog Unlock register
#define WDOG_UNLOCK (* ((volatile uint16_t *) (0x40052000 + 0xE)))

//-------------------- Watchdog Timer Output Register High
#define WDOG_TMROUTH (* ((volatile uint16_t *) (0x40052000 + 0x10)))

//-------------------- Watchdog Timer Output Register Low
#define WDOG_TMROUTL (* ((volatile uint16_t *) (0x40052000 + 0x12)))

//-------------------- Watchdog Reset Count register
#define WDOG_RSTCNT (* ((volatile uint16_t *) (0x40052000 + 0x14)))

//-------------------- Watchdog Prescaler register
#define WDOG_PRESC (* ((volatile uint16_t *) (0x40052000 + 0x16)))

  // Field (width: 3 bits): 3-bit prescaler for the watchdog clock source
    inline uint16_t WDOG_PRESC_PRESCVAL (const uint16_t inValue) { return (inValue & 7U) << 8 ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral EWM
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Control Register
#define EWM_CTRL (* ((volatile uint8_t *) (0x40061000 + 0)))

  // Boolean field: EWM enable.
    static const uint8_t EWM_CTRL_EWMEN = 1U << 0 ;

  // Boolean field: EWM_in's Assertion State Select.
    static const uint8_t EWM_CTRL_ASSIN = 1U << 1 ;

  // Boolean field: Input Enable.
    static const uint8_t EWM_CTRL_INEN = 1U << 2 ;

  // Boolean field: Interrupt Enable.
    static const uint8_t EWM_CTRL_INTEN = 1U << 3 ;

//-------------------- Service Register
#define EWM_SERV (* ((volatile uint8_t *) (0x40061000 + 0x1)))

//-------------------- Compare Low Register
#define EWM_CMPL (* ((volatile uint8_t *) (0x40061000 + 0x2)))

//-------------------- Compare High Register
#define EWM_CMPH (* ((volatile uint8_t *) (0x40061000 + 0x3)))

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral CMT
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- CMT Carrier Generator High Data Register 1
#define CMT_CGH1 (* ((volatile uint8_t *) (0x40062000 + 0)))

//-------------------- CMT Carrier Generator Low Data Register 1
#define CMT_CGL1 (* ((volatile uint8_t *) (0x40062000 + 0x1)))

//-------------------- CMT Carrier Generator High Data Register 2
#define CMT_CGH2 (* ((volatile uint8_t *) (0x40062000 + 0x2)))

//-------------------- CMT Carrier Generator Low Data Register 2
#define CMT_CGL2 (* ((volatile uint8_t *) (0x40062000 + 0x3)))

//-------------------- CMT Output Control Register
#define CMT_OC (* ((volatile uint8_t *) (0x40062000 + 0x4)))

  // Boolean field: IRO Pin Enable
    static const uint8_t CMT_OC_IROPEN = 1U << 5 ;

  // Boolean field: CMT Output Polarity
    static const uint8_t CMT_OC_CMTPOL = 1U << 6 ;

  // Boolean field: IRO Latch Control
    static const uint8_t CMT_OC_IROL = 1U << 7 ;

//-------------------- CMT Modulator Status and Control Register
#define CMT_MSC (* ((volatile uint8_t *) (0x40062000 + 0x5)))

  // Boolean field: Modulator and Carrier Generator Enable
    static const uint8_t CMT_MSC_MCGEN = 1U << 0 ;

  // Boolean field: End of Cycle Interrupt Enable
    static const uint8_t CMT_MSC_EOCIE = 1U << 1 ;

  // Boolean field: FSK Mode Select
    static const uint8_t CMT_MSC_FSK = 1U << 2 ;

  // Boolean field: Baseband Enable
    static const uint8_t CMT_MSC_BASE = 1U << 3 ;

  // Boolean field: Extended Space Enable
    static const uint8_t CMT_MSC_EXSPC = 1U << 4 ;

  // Field (width: 2 bits): CMT Clock Divide Prescaler
    inline uint8_t CMT_MSC_CMTDIV (const uint8_t inValue) { return (inValue & 3U) << 5 ; }

  // Boolean field: End Of Cycle Status Flag
    static const uint8_t CMT_MSC_EOCF = 1U << 7 ;

//-------------------- CMT Modulator Data Register Mark High
#define CMT_CMD1 (* ((volatile uint8_t *) (0x40062000 + 0x6)))

//-------------------- CMT Modulator Data Register Mark Low
#define CMT_CMD2 (* ((volatile uint8_t *) (0x40062000 + 0x7)))

//-------------------- CMT Modulator Data Register Space High
#define CMT_CMD3 (* ((volatile uint8_t *) (0x40062000 + 0x8)))

//-------------------- CMT Modulator Data Register Space Low
#define CMT_CMD4 (* ((volatile uint8_t *) (0x40062000 + 0x9)))

//-------------------- CMT Primary Prescaler Register
#define CMT_PPS (* ((volatile uint8_t *) (0x40062000 + 0xA)))

  // Field (width: 4 bits): Primary Prescaler Divider
    inline uint8_t CMT_PPS_PPSDIV (const uint8_t inValue) { return (inValue & 15U) << 0 ; }

//-------------------- CMT Direct Memory Access Register
#define CMT_DMA (* ((volatile uint8_t *) (0x40062000 + 0xB)))

  // Boolean field: DMA Enable
    static const uint8_t CMT_DMA_DMA = 1U << 0 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral MCG
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- MCG Control 1 Register
#define MCG_C1 (* ((volatile uint8_t *) (0x40064000 + 0)))

  // Boolean field: Internal Reference Stop Enable
    static const uint8_t MCG_C1_IREFSTEN = 1U << 0 ;

  // Boolean field: Internal Reference Clock Enable
    static const uint8_t MCG_C1_IRCLKEN = 1U << 1 ;

  // Boolean field: Internal Reference Select
    static const uint8_t MCG_C1_IREFS = 1U << 2 ;

  // Field (width: 3 bits): FLL External Reference Divider
    inline uint8_t MCG_C1_FRDIV (const uint8_t inValue) { return (inValue & 7U) << 3 ; }

  // Field (width: 2 bits): Clock Source Select
    inline uint8_t MCG_C1_CLKS (const uint8_t inValue) { return (inValue & 3U) << 6 ; }

//-------------------- MCG Control 2 Register
#define MCG_C2 (* ((volatile uint8_t *) (0x40064000 + 0x1)))

  // Boolean field: Internal Reference Clock Select
    static const uint8_t MCG_C2_IRCS = 1U << 0 ;

  // Boolean field: Low Power Select
    static const uint8_t MCG_C2_LP = 1U << 1 ;

  // Boolean field: External Reference Select
    static const uint8_t MCG_C2_EREFS = 1U << 2 ;

  // Boolean field: High Gain Oscillator Select
    static const uint8_t MCG_C2_HGO = 1U << 3 ;

  // Field (width: 2 bits): Frequency Range Select
    inline uint8_t MCG_C2_RANGE (const uint8_t inValue) { return (inValue & 3U) << 4 ; }

  // Boolean field: Fast Internal Reference Clock Fine Trim
    static const uint8_t MCG_C2_FCFTRIM = 1U << 6 ;

  // Boolean field: Loss of Clock Reset Enable
    static const uint8_t MCG_C2_LOCRE0 = 1U << 7 ;

//-------------------- MCG Control 3 Register
#define MCG_C3 (* ((volatile uint8_t *) (0x40064000 + 0x2)))

//-------------------- MCG Control 4 Register
#define MCG_C4 (* ((volatile uint8_t *) (0x40064000 + 0x3)))

  // Boolean field: Slow Internal Reference Clock Fine Trim
    static const uint8_t MCG_C4_SCFTRIM = 1U << 0 ;

  // Field (width: 4 bits): Fast Internal Reference Clock Trim Setting
    inline uint8_t MCG_C4_FCTRIM (const uint8_t inValue) { return (inValue & 15U) << 1 ; }

  // Field (width: 2 bits): DCO Range Select
    inline uint8_t MCG_C4_DRST_DRS (const uint8_t inValue) { return (inValue & 3U) << 5 ; }

  // Boolean field: DCO Maximum Frequency with 32.768 kHz Reference
    static const uint8_t MCG_C4_DMX32 = 1U << 7 ;

//-------------------- MCG Control 5 Register
#define MCG_C5 (* ((volatile uint8_t *) (0x40064000 + 0x4)))

  // Field (width: 3 bits): PLL External Reference Divider
    inline uint8_t MCG_C5_PRDIV (const uint8_t inValue) { return (inValue & 7U) << 0 ; }

  // Boolean field: PLL Stop Enable
    static const uint8_t MCG_C5_PLLSTEN = 1U << 5 ;

  // Boolean field: PLL Clock Enable
    static const uint8_t MCG_C5_PLLCLKEN = 1U << 6 ;

//-------------------- MCG Control 6 Register
#define MCG_C6 (* ((volatile uint8_t *) (0x40064000 + 0x5)))

  // Field (width: 5 bits): VCO Divider
    inline uint8_t MCG_C6_VDIV (const uint8_t inValue) { return (inValue & 31U) << 0 ; }

  // Boolean field: Clock Monitor Enable
    static const uint8_t MCG_C6_CME0 = 1U << 5 ;

  // Boolean field: PLL Select
    static const uint8_t MCG_C6_PLLS = 1U << 6 ;

  // Boolean field: Loss of Lock Interrrupt Enable
    static const uint8_t MCG_C6_LOLIE0 = 1U << 7 ;

//-------------------- MCG Status Register
#define MCG_S (* ((volatile uint8_t *) (0x40064000 + 0x6)))

  // Boolean field: Internal Reference Clock Status
    static const uint8_t MCG_S_IRCST = 1U << 0 ;

  // Boolean field: OSC Initialization
    static const uint8_t MCG_S_OSCINIT0 = 1U << 1 ;

  // Field (width: 2 bits): Clock Mode Status
    inline uint8_t MCG_S_CLKST (const uint8_t inValue) { return (inValue & 3U) << 2 ; }

  // Boolean field: Internal Reference Status
    static const uint8_t MCG_S_IREFST = 1U << 4 ;

  // Boolean field: PLL Select Status
    static const uint8_t MCG_S_PLLST = 1U << 5 ;

  // Boolean field: Lock Status
    static const uint8_t MCG_S_LOCK0 = 1U << 6 ;

  // Boolean field: Loss of Lock Status
    static const uint8_t MCG_S_LOLS0 = 1U << 7 ;

//-------------------- MCG Status and Control Register
#define MCG_SC (* ((volatile uint8_t *) (0x40064000 + 0x8)))

  // Boolean field: OSC0 Loss of Clock Status
    static const uint8_t MCG_SC_LOCS0 = 1U << 0 ;

  // Field (width: 3 bits): Fast Clock Internal Reference Divider
    inline uint8_t MCG_SC_FCRDIV (const uint8_t inValue) { return (inValue & 7U) << 1 ; }

  // Boolean field: FLL Filter Preserve Enable
    static const uint8_t MCG_SC_FLTPRSRV = 1U << 4 ;

  // Boolean field: Automatic Trim Machine Fail Flag
    static const uint8_t MCG_SC_ATMF = 1U << 5 ;

  // Boolean field: Automatic Trim Machine Select
    static const uint8_t MCG_SC_ATMS = 1U << 6 ;

  // Boolean field: Automatic Trim Machine Enable
    static const uint8_t MCG_SC_ATME = 1U << 7 ;

//-------------------- MCG Auto Trim Compare Value High Register
#define MCG_ATCVH (* ((volatile uint8_t *) (0x40064000 + 0xA)))

//-------------------- MCG Auto Trim Compare Value Low Register
#define MCG_ATCVL (* ((volatile uint8_t *) (0x40064000 + 0xB)))

//-------------------- MCG Control 7 Register
#define MCG_C7 (* ((volatile uint8_t *) (0x40064000 + 0xC)))

  // Field (width: 2 bits): MCG OSC Clock Select
    inline uint8_t MCG_C7_OSCSEL (const uint8_t inValue) { return (inValue & 3U) << 0 ; }

//-------------------- MCG Control 8 Register
#define MCG_C8 (* ((volatile uint8_t *) (0x40064000 + 0xD)))

  // Boolean field: RTC Loss of Clock Status
    static const uint8_t MCG_C8_LOCS1 = 1U << 0 ;

  // Boolean field: Clock Monitor Enable1
    static const uint8_t MCG_C8_CME1 = 1U << 5 ;

  // Boolean field: PLL Loss of Lock Reset Enable
    static const uint8_t MCG_C8_LOLRE = 1U << 6 ;

  // Boolean field: Loss of Clock Reset Enable
    static const uint8_t MCG_C8_LOCRE1 = 1U << 7 ;

//-------------------- MCG Control 9 Register
#define MCG_C9 (* ((volatile uint8_t *) (0x40064000 + 0xE)))

  // Boolean field: External PLL Loss of Clock Status
    static const uint8_t MCG_C9_EXT_PLL_LOCS = 1U << 0 ;

  // Boolean field: MCG External PLL Loss of Clock Reset Enable
    static const uint8_t MCG_C9_PLL_LOCRE = 1U << 4 ;

  // Boolean field: MCG External PLL Clock Monitor Enable
    static const uint8_t MCG_C9_PLL_CME = 1U << 5 ;

//-------------------- MCG Control 11 Register
#define MCG_C11 (* ((volatile uint8_t *) (0x40064000 + 0x10)))

  // Boolean field: PLL Clock Select
    static const uint8_t MCG_C11_PLLCS = 1U << 4 ;

//-------------------- MCG Status 2 Register
#define MCG_S2 (* ((const volatile uint8_t *) (0x40064000 + 0x12)))

  // Boolean field: PLL Clock Select Status
    static const uint8_t MCG_S2_PLLCST = 1U << 4 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral OSC
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- OSC Control Register
#define OSC_CR (* ((volatile uint8_t *) (0x40065000 + 0)))

  // Boolean field: Oscillator 16 pF Capacitor Load Configure
    static const uint8_t OSC_CR_SC16P = 1U << 0 ;

  // Boolean field: Oscillator 8 pF Capacitor Load Configure
    static const uint8_t OSC_CR_SC8P = 1U << 1 ;

  // Boolean field: Oscillator 4 pF Capacitor Load Configure
    static const uint8_t OSC_CR_SC4P = 1U << 2 ;

  // Boolean field: Oscillator 2 pF Capacitor Load Configure
    static const uint8_t OSC_CR_SC2P = 1U << 3 ;

  // Boolean field: External Reference Stop Enable
    static const uint8_t OSC_CR_EREFSTEN = 1U << 5 ;

  // Boolean field: External Reference Enable
    static const uint8_t OSC_CR_ERCLKEN = 1U << 7 ;

//-------------------- OSC_DIV
#define OSC_DIV (* ((volatile uint8_t *) (0x40065000 + 0x2)))

  // Field (width: 2 bits): ERCLK prescaler
    inline uint8_t OSC_DIV_ERPS (const uint8_t inValue) { return (inValue & 3U) << 6 ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral USB0
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Peripheral ID register
#define USB0_PERID (* ((const volatile uint8_t *) (0x40072000 + 0)))

  // Field (width: 6 bits): Peripheral Identification
    inline uint8_t USB0_PERID_ID (const uint8_t inValue) { return (inValue & 63U) << 0 ; }

//-------------------- Peripheral ID Complement register
#define USB0_IDCOMP (* ((const volatile uint8_t *) (0x40072000 + 0x4)))

  // Field (width: 6 bits): Ones' complement of PERID[ID]. bits.
    inline uint8_t USB0_IDCOMP_NID (const uint8_t inValue) { return (inValue & 63U) << 0 ; }

//-------------------- Peripheral Revision register
#define USB0_REV (* ((const volatile uint8_t *) (0x40072000 + 0x8)))

//-------------------- Peripheral Additional Info register
#define USB0_ADDINFO (* ((const volatile uint8_t *) (0x40072000 + 0xC)))

  // Boolean field: This bit is set if host mode is enabled.
    static const uint8_t USB0_ADDINFO_IEHOST = 1U << 0 ;

//-------------------- OTG Interrupt Status register
#define USB0_OTGISTAT (* ((volatile uint8_t *) (0x40072000 + 0x10)))

  // Boolean field: This bit is set when a change in VBUS is detected on an A device.
    static const uint8_t USB0_OTGISTAT_AVBUSCHG = 1U << 0 ;

  // Boolean field: This bit is set when a change in VBUS is detected on a B device.
    static const uint8_t USB0_OTGISTAT_B_SESS_CHG = 1U << 2 ;

  // Boolean field: This bit is set when a change in VBUS is detected indicating a session valid or a session no longer valid
    static const uint8_t USB0_OTGISTAT_SESSVLDCHG = 1U << 3 ;

  // Boolean field: This interrupt is set when the USB line state (CTL[SE0] and CTL[JSTATE] bits) are stable without change for 1 millisecond, and the value of the line state is different from the last time when the line state was stable
    static const uint8_t USB0_OTGISTAT_LINE_STATE_CHG = 1U << 5 ;

  // Boolean field: This bit is set when the 1 millisecond timer expires
    static const uint8_t USB0_OTGISTAT_ONEMSEC = 1U << 6 ;

  // Boolean field: This bit is set when a change in the ID Signal from the USB connector is sensed.
    static const uint8_t USB0_OTGISTAT_IDCHG = 1U << 7 ;

//-------------------- OTG Interrupt Control register
#define USB0_OTGICR (* ((volatile uint8_t *) (0x40072000 + 0x14)))

  // Boolean field: A VBUS Valid Interrupt Enable
    static const uint8_t USB0_OTGICR_AVBUSEN = 1U << 0 ;

  // Boolean field: B Session END Interrupt Enable
    static const uint8_t USB0_OTGICR_BSESSEN = 1U << 2 ;

  // Boolean field: Session Valid Interrupt Enable
    static const uint8_t USB0_OTGICR_SESSVLDEN = 1U << 3 ;

  // Boolean field: Line State Change Interrupt Enable
    static const uint8_t USB0_OTGICR_LINESTATEEN = 1U << 5 ;

  // Boolean field: One Millisecond Interrupt Enable
    static const uint8_t USB0_OTGICR_ONEMSECEN = 1U << 6 ;

  // Boolean field: ID Interrupt Enable
    static const uint8_t USB0_OTGICR_IDEN = 1U << 7 ;

//-------------------- OTG Status register
#define USB0_OTGSTAT (* ((volatile uint8_t *) (0x40072000 + 0x18)))

  // Boolean field: A VBUS Valid
    static const uint8_t USB0_OTGSTAT_AVBUSVLD = 1U << 0 ;

  // Boolean field: B Session End
    static const uint8_t USB0_OTGSTAT_BSESSEND = 1U << 2 ;

  // Boolean field: Session Valid
    static const uint8_t USB0_OTGSTAT_SESS_VLD = 1U << 3 ;

  // Boolean field: Indicates that the internal signals that control the LINE_STATE_CHG field of OTGISTAT are stable for at least 1 ms
    static const uint8_t USB0_OTGSTAT_LINESTATESTABLE = 1U << 5 ;

  // Boolean field: This bit is reserved for the 1ms count, but it is not useful to software.
    static const uint8_t USB0_OTGSTAT_ONEMSECEN = 1U << 6 ;

  // Boolean field: Indicates the current state of the ID pin on the USB connector
    static const uint8_t USB0_OTGSTAT_ID = 1U << 7 ;

//-------------------- OTG Control register
#define USB0_OTGCTL (* ((volatile uint8_t *) (0x40072000 + 0x1C)))

  // Boolean field: On-The-Go pullup/pulldown resistor enable
    static const uint8_t USB0_OTGCTL_OTGEN = 1U << 2 ;

  // Boolean field: D- Data Line pull-down resistor enable
    static const uint8_t USB0_OTGCTL_DMLOW = 1U << 4 ;

  // Boolean field: D+ Data Line pull-down resistor enable
    static const uint8_t USB0_OTGCTL_DPLOW = 1U << 5 ;

  // Boolean field: D+ Data Line pullup resistor enable
    static const uint8_t USB0_OTGCTL_DPHIGH = 1U << 7 ;

//-------------------- Interrupt Status register
#define USB0_ISTAT (* ((volatile uint8_t *) (0x40072000 + 0x80)))

  // Boolean field: This bit is set when the USB Module has decoded a valid USB reset
    static const uint8_t USB0_ISTAT_USBRST = 1U << 0 ;

  // Boolean field: This bit is set when any of the error conditions within Error Interrupt Status (ERRSTAT) register occur
    static const uint8_t USB0_ISTAT_ERROR = 1U << 1 ;

  // Boolean field: This bit is set when the USB Module receives a Start Of Frame (SOF) token
    static const uint8_t USB0_ISTAT_SOFTOK = 1U << 2 ;

  // Boolean field: This bit is set when the current token being processed has completed
    static const uint8_t USB0_ISTAT_TOKDNE = 1U << 3 ;

  // Boolean field: This bit is set when the USB Module detects a constant idle on the USB bus for 3 ms
    static const uint8_t USB0_ISTAT_SLEEP = 1U << 4 ;

  // Boolean field: This bit is set when a K-state is observed on the DP/DM signals for 2
    static const uint8_t USB0_ISTAT_RESUME = 1U << 5 ;

  // Boolean field: Attach Interrupt
    static const uint8_t USB0_ISTAT_ATTACH = 1U << 6 ;

  // Boolean field: Stall Interrupt
    static const uint8_t USB0_ISTAT_STALL = 1U << 7 ;

//-------------------- Interrupt Enable register
#define USB0_INTEN (* ((volatile uint8_t *) (0x40072000 + 0x84)))

  // Boolean field: USBRST Interrupt Enable
    static const uint8_t USB0_INTEN_USBRSTEN = 1U << 0 ;

  // Boolean field: ERROR Interrupt Enable
    static const uint8_t USB0_INTEN_ERROREN = 1U << 1 ;

  // Boolean field: SOFTOK Interrupt Enable
    static const uint8_t USB0_INTEN_SOFTOKEN = 1U << 2 ;

  // Boolean field: TOKDNE Interrupt Enable
    static const uint8_t USB0_INTEN_TOKDNEEN = 1U << 3 ;

  // Boolean field: SLEEP Interrupt Enable
    static const uint8_t USB0_INTEN_SLEEPEN = 1U << 4 ;

  // Boolean field: RESUME Interrupt Enable
    static const uint8_t USB0_INTEN_RESUMEEN = 1U << 5 ;

  // Boolean field: ATTACH Interrupt Enable
    static const uint8_t USB0_INTEN_ATTACHEN = 1U << 6 ;

  // Boolean field: STALL Interrupt Enable
    static const uint8_t USB0_INTEN_STALLEN = 1U << 7 ;

//-------------------- Error Interrupt Status register
#define USB0_ERRSTAT (* ((volatile uint8_t *) (0x40072000 + 0x88)))

  // Boolean field: This bit is set when the PID check field fails.
    static const uint8_t USB0_ERRSTAT_PIDERR = 1U << 0 ;

  // Boolean field: This error interrupt has two functions
    static const uint8_t USB0_ERRSTAT_CRC5EOF = 1U << 1 ;

  // Boolean field: This bit is set when a data packet is rejected due to a CRC16 error.
    static const uint8_t USB0_ERRSTAT_CRC16 = 1U << 2 ;

  // Boolean field: This bit is set if the data field received was not 8 bits in length
    static const uint8_t USB0_ERRSTAT_DFN8 = 1U << 3 ;

  // Boolean field: This bit is set when a bus turnaround timeout error occurs
    static const uint8_t USB0_ERRSTAT_BTOERR = 1U << 4 ;

  // Boolean field: This bit is set if the USB Module has requested a DMA access to read a new BDT but has not been given the bus before it needs to receive or transmit data
    static const uint8_t USB0_ERRSTAT_DMAERR = 1U << 5 ;

  // Boolean field: This bit is set when a bit stuff error is detected
    static const uint8_t USB0_ERRSTAT_BTSERR = 1U << 7 ;

//-------------------- Error Interrupt Enable register
#define USB0_ERREN (* ((volatile uint8_t *) (0x40072000 + 0x8C)))

  // Boolean field: PIDERR Interrupt Enable
    static const uint8_t USB0_ERREN_PIDERREN = 1U << 0 ;

  // Boolean field: CRC5/EOF Interrupt Enable
    static const uint8_t USB0_ERREN_CRC5EOFEN = 1U << 1 ;

  // Boolean field: CRC16 Interrupt Enable
    static const uint8_t USB0_ERREN_CRC16EN = 1U << 2 ;

  // Boolean field: DFN8 Interrupt Enable
    static const uint8_t USB0_ERREN_DFN8EN = 1U << 3 ;

  // Boolean field: BTOERR Interrupt Enable
    static const uint8_t USB0_ERREN_BTOERREN = 1U << 4 ;

  // Boolean field: DMAERR Interrupt Enable
    static const uint8_t USB0_ERREN_DMAERREN = 1U << 5 ;

  // Boolean field: BTSERR Interrupt Enable
    static const uint8_t USB0_ERREN_BTSERREN = 1U << 7 ;

//-------------------- Status register
#define USB0_STAT (* ((const volatile uint8_t *) (0x40072000 + 0x90)))

  // Boolean field: This bit is set if the last buffer descriptor updated was in the odd bank of the BDT.
    static const uint8_t USB0_STAT_ODD = 1U << 2 ;

  // Boolean field: Transmit Indicator
    static const uint8_t USB0_STAT_TX = 1U << 3 ;

  // Field (width: 4 bits): This four-bit field encodes the endpoint address that received or transmitted the previous token
    inline uint8_t USB0_STAT_ENDP (const uint8_t inValue) { return (inValue & 15U) << 4 ; }

//-------------------- Control register
#define USB0_CTL (* ((volatile uint8_t *) (0x40072000 + 0x94)))

  // Boolean field: USB Enable
    static const uint8_t USB0_CTL_USBENSOFEN = 1U << 0 ;

  // Boolean field: Setting this bit to 1 resets all the BDT ODD ping/pong fields to 0, which then specifies the EVEN BDT bank
    static const uint8_t USB0_CTL_ODDRST = 1U << 1 ;

  // Boolean field: When set to 1 this bit enables the USB Module to execute resume signaling
    static const uint8_t USB0_CTL_RESUME = 1U << 2 ;

  // Boolean field: When set to 1, this bit enables the USB Module to operate in Host mode
    static const uint8_t USB0_CTL_HOSTMODEEN = 1U << 3 ;

  // Boolean field: Setting this bit enables the USB Module to generate USB reset signaling
    static const uint8_t USB0_CTL_RESET = 1U << 4 ;

  // Boolean field: In Host mode, TOKEN_BUSY is set when the USB module is busy executing a USB token
    static const uint8_t USB0_CTL_TXSUSPENDTOKENBUSY = 1U << 5 ;

  // Boolean field: Live USB Single Ended Zero signal
    static const uint8_t USB0_CTL_SE0 = 1U << 6 ;

  // Boolean field: Live USB differential receiver JSTATE signal
    static const uint8_t USB0_CTL_JSTATE = 1U << 7 ;

//-------------------- Address register
#define USB0_ADDR (* ((volatile uint8_t *) (0x40072000 + 0x98)))

  // Field (width: 7 bits): USB Address
    inline uint8_t USB0_ADDR_ADDR (const uint8_t inValue) { return (inValue & 127U) << 0 ; }

  // Boolean field: Low Speed Enable bit
    static const uint8_t USB0_ADDR_LSEN = 1U << 7 ;

//-------------------- BDT Page register 1
#define USB0_BDTPAGE1 (* ((volatile uint8_t *) (0x40072000 + 0x9C)))

  // Field (width: 7 bits): Provides address bits 15 through 9 of the BDT base address.
    inline uint8_t USB0_BDTPAGE1_BDTBA (const uint8_t inValue) { return (inValue & 127U) << 1 ; }

//-------------------- Frame Number register Low
#define USB0_FRMNUML (* ((volatile uint8_t *) (0x40072000 + 0xA0)))

//-------------------- Frame Number register High
#define USB0_FRMNUMH (* ((volatile uint8_t *) (0x40072000 + 0xA4)))

  // Field (width: 3 bits): This 3-bit field and the 8-bit field in the Frame Number Register Low are used to compute the address where the current Buffer Descriptor Table (BDT) resides in system memory
    inline uint8_t USB0_FRMNUMH_FRM (const uint8_t inValue) { return (inValue & 7U) << 0 ; }

//-------------------- Token register
#define USB0_TOKEN (* ((volatile uint8_t *) (0x40072000 + 0xA8)))

  // Field (width: 4 bits): Holds the Endpoint address for the token command
    inline uint8_t USB0_TOKEN_TOKENENDPT (const uint8_t inValue) { return (inValue & 15U) << 0 ; }

  // Field (width: 4 bits): Contains the token type executed by the USB module.
    inline uint8_t USB0_TOKEN_TOKENPID (const uint8_t inValue) { return (inValue & 15U) << 4 ; }

//-------------------- SOF Threshold register
#define USB0_SOFTHLD (* ((volatile uint8_t *) (0x40072000 + 0xAC)))

//-------------------- BDT Page Register 2
#define USB0_BDTPAGE2 (* ((volatile uint8_t *) (0x40072000 + 0xB0)))

//-------------------- BDT Page Register 3
#define USB0_BDTPAGE3 (* ((volatile uint8_t *) (0x40072000 + 0xB4)))

//-------------------- Endpoint Control register (idx = 0 ... 15)
#define USB0_ENDPT(idx) (* ((volatile uint8_t *) (0x40072000 + 0xC0 + 0x4 * (idx))))

  // Boolean field: When set this bit enables an endpoint to perform handshaking during a transaction to this endpoint
    static const uint8_t USB0_ENDPT_EPHSHK = 1U << 0 ;

  // Boolean field: When set this bit indicates that the endpoint is called
    static const uint8_t USB0_ENDPT_EPSTALL = 1U << 1 ;

  // Boolean field: This bit, when set, enables the endpoint for TX transfers. See
    static const uint8_t USB0_ENDPT_EPTXEN = 1U << 2 ;

  // Boolean field: This bit, when set, enables the endpoint for RX transfers. See
    static const uint8_t USB0_ENDPT_EPRXEN = 1U << 3 ;

  // Boolean field: This bit, when set, disables control (SETUP) transfers
    static const uint8_t USB0_ENDPT_EPCTLDIS = 1U << 4 ;

  // Boolean field: This is a Host mode only bit and is present in the control register for endpoint 0 (ENDPT0) only
    static const uint8_t USB0_ENDPT_RETRYDIS = 1U << 6 ;

  // Boolean field: Host without a hub This is a Host mode only field and is present in the control register for endpoint 0 (ENDPT0) only
    static const uint8_t USB0_ENDPT_HOSTWOHUB = 1U << 7 ;

//-------------------- USB Control register
#define USB0_USBCTRL (* ((volatile uint8_t *) (0x40072000 + 0x100)))

  // Boolean field: Enables the weak pulldowns on the USB transceiver.
    static const uint8_t USB0_USBCTRL_PDE = 1U << 6 ;

  // Boolean field: Places the USB transceiver into the suspend state.
    static const uint8_t USB0_USBCTRL_SUSP = 1U << 7 ;

//-------------------- USB OTG Observe register
#define USB0_OBSERVE (* ((const volatile uint8_t *) (0x40072000 + 0x104)))

  // Boolean field: Provides observability of the D- Pulldown enable at the USB transceiver.
    static const uint8_t USB0_OBSERVE_DMPD = 1U << 4 ;

  // Boolean field: Provides observability of the D+ Pulldown enable at the USB transceiver.
    static const uint8_t USB0_OBSERVE_DPPD = 1U << 6 ;

  // Boolean field: Provides observability of the D+ Pullup enable at the USB transceiver.
    static const uint8_t USB0_OBSERVE_DPPU = 1U << 7 ;

//-------------------- USB OTG Control register
#define USB0_CONTROL (* ((volatile uint8_t *) (0x40072000 + 0x108)))

  // Boolean field: Provides control of the DP Pullup in USBOTG, if USB is configured in non-OTG device mode.
    static const uint8_t USB0_CONTROL_DPPULLUPNONOTG = 1U << 4 ;

//-------------------- USB Transceiver Control register 0
#define USB0_USBTRC0 (* ((volatile uint8_t *) (0x40072000 + 0x10C)))

  // Boolean field: USB Asynchronous Interrupt
    static const uint8_t USB0_USBTRC0_USB_RESUME_INT = 1U << 0 ;

  // Boolean field: Synchronous USB Interrupt Detect
    static const uint8_t USB0_USBTRC0_SYNC_DET = 1U << 1 ;

  // Boolean field: Combined USB Clock Recovery interrupt status
    static const uint8_t USB0_USBTRC0_USB_CLK_RECOVERY_INT = 1U << 2 ;

  // Boolean field: Asynchronous Resume Interrupt Enable
    static const uint8_t USB0_USBTRC0_USBRESMEN = 1U << 5 ;

  // Boolean field: USB Reset
    static const uint8_t USB0_USBTRC0_USBRESET = 1U << 7 ;

//-------------------- Frame Adjust Register
#define USB0_USBFRMADJUST (* ((volatile uint8_t *) (0x40072000 + 0x114)))

//-------------------- USB Clock recovery control
#define USB0_CLK_RECOVER_CTRL (* ((volatile uint8_t *) (0x40072000 + 0x140)))

  // Boolean field: Restart from IFR trim value
    static const uint8_t USB0_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN = 1U << 5 ;

  // Boolean field: Reset/resume to rough phase enable
    static const uint8_t USB0_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN = 1U << 6 ;

  // Boolean field: Crystal-less USB enable
    static const uint8_t USB0_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN = 1U << 7 ;

//-------------------- IRC48M oscillator enable register
#define USB0_CLK_RECOVER_IRC_EN (* ((volatile uint8_t *) (0x40072000 + 0x144)))

  // Boolean field: IRC48M regulator enable
    static const uint8_t USB0_CLK_RECOVER_IRC_EN_REG_EN = 1U << 0 ;

  // Boolean field: IRC48M enable
    static const uint8_t USB0_CLK_RECOVER_IRC_EN_IRC_EN = 1U << 1 ;

//-------------------- Clock recovery combined interrupt enable
#define USB0_CLK_RECOVER_INT_EN (* ((volatile uint8_t *) (0x40072000 + 0x154)))

  // Boolean field: Determines whether OVF_ERROR condition signal is used in generation of USB_CLK_RECOVERY_INT.
    static const uint8_t USB0_CLK_RECOVER_INT_EN_OVF_ERROR_EN = 1U << 4 ;

//-------------------- Clock recovery separated interrupt status
#define USB0_CLK_RECOVER_INT_STATUS (* ((volatile uint8_t *) (0x40072000 + 0x15C)))

  // Boolean field: Indicates that the USB clock recovery algorithm has detected that the frequency trim adjustment needed for the IRC48M output clock is outside the available TRIM_FINE adjustment range for the IRC48M module
    static const uint8_t USB0_CLK_RECOVER_INT_STATUS_OVF_ERROR = 1U << 4 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral VREF
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- VREF Trim Register
#define VREF_TRM (* ((volatile uint8_t *) (0x40074000 + 0)))

  // Field (width: 6 bits): Trim bits
    inline uint8_t VREF_TRM_TRIM (const uint8_t inValue) { return (inValue & 63U) << 0 ; }

  // Boolean field: Chop oscillator enable. When set, internal chopping operation is enabled and the internal analog offset will be minimized.
    static const uint8_t VREF_TRM_CHOPEN = 1U << 6 ;

//-------------------- VREF Status and Control Register
#define VREF_SC (* ((volatile uint8_t *) (0x40074000 + 0x1)))

  // Field (width: 2 bits): Buffer Mode selection
    inline uint8_t VREF_SC_MODE_LV (const uint8_t inValue) { return (inValue & 3U) << 0 ; }

  // Boolean field: Internal Voltage Reference stable
    static const uint8_t VREF_SC_VREFST = 1U << 2 ;

  // Boolean field: Second order curvature compensation enable
    static const uint8_t VREF_SC_ICOMPEN = 1U << 5 ;

  // Boolean field: Regulator enable
    static const uint8_t VREF_SC_REGEN = 1U << 6 ;

  // Boolean field: Internal Voltage Reference enable
    static const uint8_t VREF_SC_VREFEN = 1U << 7 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral LLWU
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- LLWU Pin Enable 1 register
#define LLWU_PE1 (* ((volatile uint8_t *) (0x4007C000 + 0)))

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P0
    inline uint8_t LLWU_PE1_WUPE0 (const uint8_t inValue) { return (inValue & 3U) << 0 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P1
    inline uint8_t LLWU_PE1_WUPE1 (const uint8_t inValue) { return (inValue & 3U) << 2 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P2
    inline uint8_t LLWU_PE1_WUPE2 (const uint8_t inValue) { return (inValue & 3U) << 4 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P3
    inline uint8_t LLWU_PE1_WUPE3 (const uint8_t inValue) { return (inValue & 3U) << 6 ; }

//-------------------- LLWU Pin Enable 2 register
#define LLWU_PE2 (* ((volatile uint8_t *) (0x4007C000 + 0x1)))

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P4
    inline uint8_t LLWU_PE2_WUPE4 (const uint8_t inValue) { return (inValue & 3U) << 0 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P5
    inline uint8_t LLWU_PE2_WUPE5 (const uint8_t inValue) { return (inValue & 3U) << 2 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P6
    inline uint8_t LLWU_PE2_WUPE6 (const uint8_t inValue) { return (inValue & 3U) << 4 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P7
    inline uint8_t LLWU_PE2_WUPE7 (const uint8_t inValue) { return (inValue & 3U) << 6 ; }

//-------------------- LLWU Pin Enable 3 register
#define LLWU_PE3 (* ((volatile uint8_t *) (0x4007C000 + 0x2)))

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P8
    inline uint8_t LLWU_PE3_WUPE8 (const uint8_t inValue) { return (inValue & 3U) << 0 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P9
    inline uint8_t LLWU_PE3_WUPE9 (const uint8_t inValue) { return (inValue & 3U) << 2 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P10
    inline uint8_t LLWU_PE3_WUPE10 (const uint8_t inValue) { return (inValue & 3U) << 4 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P11
    inline uint8_t LLWU_PE3_WUPE11 (const uint8_t inValue) { return (inValue & 3U) << 6 ; }

//-------------------- LLWU Pin Enable 4 register
#define LLWU_PE4 (* ((volatile uint8_t *) (0x4007C000 + 0x3)))

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P12
    inline uint8_t LLWU_PE4_WUPE12 (const uint8_t inValue) { return (inValue & 3U) << 0 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P13
    inline uint8_t LLWU_PE4_WUPE13 (const uint8_t inValue) { return (inValue & 3U) << 2 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P14
    inline uint8_t LLWU_PE4_WUPE14 (const uint8_t inValue) { return (inValue & 3U) << 4 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P15
    inline uint8_t LLWU_PE4_WUPE15 (const uint8_t inValue) { return (inValue & 3U) << 6 ; }

//-------------------- LLWU Pin Enable 5 register
#define LLWU_PE5 (* ((volatile uint8_t *) (0x4007C000 + 0x4)))

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P16
    inline uint8_t LLWU_PE5_WUPE16 (const uint8_t inValue) { return (inValue & 3U) << 0 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P17
    inline uint8_t LLWU_PE5_WUPE17 (const uint8_t inValue) { return (inValue & 3U) << 2 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P18
    inline uint8_t LLWU_PE5_WUPE18 (const uint8_t inValue) { return (inValue & 3U) << 4 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P19
    inline uint8_t LLWU_PE5_WUPE19 (const uint8_t inValue) { return (inValue & 3U) << 6 ; }

//-------------------- LLWU Pin Enable 6 register
#define LLWU_PE6 (* ((volatile uint8_t *) (0x4007C000 + 0x5)))

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P20
    inline uint8_t LLWU_PE6_WUPE20 (const uint8_t inValue) { return (inValue & 3U) << 0 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P21
    inline uint8_t LLWU_PE6_WUPE21 (const uint8_t inValue) { return (inValue & 3U) << 2 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P22
    inline uint8_t LLWU_PE6_WUPE22 (const uint8_t inValue) { return (inValue & 3U) << 4 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P23
    inline uint8_t LLWU_PE6_WUPE23 (const uint8_t inValue) { return (inValue & 3U) << 6 ; }

//-------------------- LLWU Pin Enable 7 register
#define LLWU_PE7 (* ((volatile uint8_t *) (0x4007C000 + 0x6)))

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P24
    inline uint8_t LLWU_PE7_WUPE24 (const uint8_t inValue) { return (inValue & 3U) << 0 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P25
    inline uint8_t LLWU_PE7_WUPE25 (const uint8_t inValue) { return (inValue & 3U) << 2 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P26
    inline uint8_t LLWU_PE7_WUPE26 (const uint8_t inValue) { return (inValue & 3U) << 4 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P27
    inline uint8_t LLWU_PE7_WUPE27 (const uint8_t inValue) { return (inValue & 3U) << 6 ; }

//-------------------- LLWU Pin Enable 8 register
#define LLWU_PE8 (* ((volatile uint8_t *) (0x4007C000 + 0x7)))

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P28
    inline uint8_t LLWU_PE8_WUPE28 (const uint8_t inValue) { return (inValue & 3U) << 0 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P29
    inline uint8_t LLWU_PE8_WUPE29 (const uint8_t inValue) { return (inValue & 3U) << 2 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P30
    inline uint8_t LLWU_PE8_WUPE30 (const uint8_t inValue) { return (inValue & 3U) << 4 ; }

  // Field (width: 2 bits): Wakeup Pin Enable For LLWU_P31
    inline uint8_t LLWU_PE8_WUPE31 (const uint8_t inValue) { return (inValue & 3U) << 6 ; }

//-------------------- LLWU Module Enable register
#define LLWU_ME (* ((volatile uint8_t *) (0x4007C000 + 0x8)))

  // Boolean field: Wakeup Module Enable For Module 0
    static const uint8_t LLWU_ME_WUME0 = 1U << 0 ;

  // Boolean field: Wakeup Module Enable for Module 1
    static const uint8_t LLWU_ME_WUME1 = 1U << 1 ;

  // Boolean field: Wakeup Module Enable For Module 2
    static const uint8_t LLWU_ME_WUME2 = 1U << 2 ;

  // Boolean field: Wakeup Module Enable For Module 3
    static const uint8_t LLWU_ME_WUME3 = 1U << 3 ;

  // Boolean field: Wakeup Module Enable For Module 4
    static const uint8_t LLWU_ME_WUME4 = 1U << 4 ;

  // Boolean field: Wakeup Module Enable For Module 5
    static const uint8_t LLWU_ME_WUME5 = 1U << 5 ;

  // Boolean field: Wakeup Module Enable For Module 6
    static const uint8_t LLWU_ME_WUME6 = 1U << 6 ;

  // Boolean field: Wakeup Module Enable For Module 7
    static const uint8_t LLWU_ME_WUME7 = 1U << 7 ;

//-------------------- LLWU Pin Flag 1 register
#define LLWU_PF1 (* ((volatile uint8_t *) (0x4007C000 + 0x9)))

  // Boolean field: Wakeup Flag For LLWU_P0
    static const uint8_t LLWU_PF1_WUF0 = 1U << 0 ;

  // Boolean field: Wakeup Flag For LLWU_P1
    static const uint8_t LLWU_PF1_WUF1 = 1U << 1 ;

  // Boolean field: Wakeup Flag For LLWU_P2
    static const uint8_t LLWU_PF1_WUF2 = 1U << 2 ;

  // Boolean field: Wakeup Flag For LLWU_P3
    static const uint8_t LLWU_PF1_WUF3 = 1U << 3 ;

  // Boolean field: Wakeup Flag For LLWU_P4
    static const uint8_t LLWU_PF1_WUF4 = 1U << 4 ;

  // Boolean field: Wakeup Flag For LLWU_P5
    static const uint8_t LLWU_PF1_WUF5 = 1U << 5 ;

  // Boolean field: Wakeup Flag For LLWU_P6
    static const uint8_t LLWU_PF1_WUF6 = 1U << 6 ;

  // Boolean field: Wakeup Flag For LLWU_P7
    static const uint8_t LLWU_PF1_WUF7 = 1U << 7 ;

//-------------------- LLWU Pin Flag 2 register
#define LLWU_PF2 (* ((volatile uint8_t *) (0x4007C000 + 0xA)))

  // Boolean field: Wakeup Flag For LLWU_P8
    static const uint8_t LLWU_PF2_WUF8 = 1U << 0 ;

  // Boolean field: Wakeup Flag For LLWU_P9
    static const uint8_t LLWU_PF2_WUF9 = 1U << 1 ;

  // Boolean field: Wakeup Flag For LLWU_P10
    static const uint8_t LLWU_PF2_WUF10 = 1U << 2 ;

  // Boolean field: Wakeup Flag For LLWU_P11
    static const uint8_t LLWU_PF2_WUF11 = 1U << 3 ;

  // Boolean field: Wakeup Flag For LLWU_P12
    static const uint8_t LLWU_PF2_WUF12 = 1U << 4 ;

  // Boolean field: Wakeup Flag For LLWU_P13
    static const uint8_t LLWU_PF2_WUF13 = 1U << 5 ;

  // Boolean field: Wakeup Flag For LLWU_P14
    static const uint8_t LLWU_PF2_WUF14 = 1U << 6 ;

  // Boolean field: Wakeup Flag For LLWU_P15
    static const uint8_t LLWU_PF2_WUF15 = 1U << 7 ;

//-------------------- LLWU Pin Flag 3 register
#define LLWU_PF3 (* ((volatile uint8_t *) (0x4007C000 + 0xB)))

  // Boolean field: Wakeup Flag For LLWU_P16
    static const uint8_t LLWU_PF3_WUF16 = 1U << 0 ;

  // Boolean field: Wakeup Flag For LLWU_P17
    static const uint8_t LLWU_PF3_WUF17 = 1U << 1 ;

  // Boolean field: Wakeup Flag For LLWU_P18
    static const uint8_t LLWU_PF3_WUF18 = 1U << 2 ;

  // Boolean field: Wakeup Flag For LLWU_P19
    static const uint8_t LLWU_PF3_WUF19 = 1U << 3 ;

  // Boolean field: Wakeup Flag For LLWU_P20
    static const uint8_t LLWU_PF3_WUF20 = 1U << 4 ;

  // Boolean field: Wakeup Flag For LLWU_P21
    static const uint8_t LLWU_PF3_WUF21 = 1U << 5 ;

  // Boolean field: Wakeup Flag For LLWU_P22
    static const uint8_t LLWU_PF3_WUF22 = 1U << 6 ;

  // Boolean field: Wakeup Flag For LLWU_P23
    static const uint8_t LLWU_PF3_WUF23 = 1U << 7 ;

//-------------------- LLWU Pin Flag 4 register
#define LLWU_PF4 (* ((volatile uint8_t *) (0x4007C000 + 0xC)))

  // Boolean field: Wakeup Flag For LLWU_P24
    static const uint8_t LLWU_PF4_WUF24 = 1U << 0 ;

  // Boolean field: Wakeup Flag For LLWU_P25
    static const uint8_t LLWU_PF4_WUF25 = 1U << 1 ;

  // Boolean field: Wakeup Flag For LLWU_P26
    static const uint8_t LLWU_PF4_WUF26 = 1U << 2 ;

  // Boolean field: Wakeup Flag For LLWU_P27
    static const uint8_t LLWU_PF4_WUF27 = 1U << 3 ;

  // Boolean field: Wakeup Flag For LLWU_P28
    static const uint8_t LLWU_PF4_WUF28 = 1U << 4 ;

  // Boolean field: Wakeup Flag For LLWU_P29
    static const uint8_t LLWU_PF4_WUF29 = 1U << 5 ;

  // Boolean field: Wakeup Flag For LLWU_P30
    static const uint8_t LLWU_PF4_WUF30 = 1U << 6 ;

  // Boolean field: Wakeup Flag For LLWU_P31
    static const uint8_t LLWU_PF4_WUF31 = 1U << 7 ;

//-------------------- LLWU Module Flag 5 register
#define LLWU_MF5 (* ((const volatile uint8_t *) (0x4007C000 + 0xD)))

  // Boolean field: Wakeup flag For module 0
    static const uint8_t LLWU_MF5_MWUF0 = 1U << 0 ;

  // Boolean field: Wakeup flag For module 1
    static const uint8_t LLWU_MF5_MWUF1 = 1U << 1 ;

  // Boolean field: Wakeup flag For module 2
    static const uint8_t LLWU_MF5_MWUF2 = 1U << 2 ;

  // Boolean field: Wakeup flag For module 3
    static const uint8_t LLWU_MF5_MWUF3 = 1U << 3 ;

  // Boolean field: Wakeup flag For module 4
    static const uint8_t LLWU_MF5_MWUF4 = 1U << 4 ;

  // Boolean field: Wakeup flag For module 5
    static const uint8_t LLWU_MF5_MWUF5 = 1U << 5 ;

  // Boolean field: Wakeup flag For module 6
    static const uint8_t LLWU_MF5_MWUF6 = 1U << 6 ;

  // Boolean field: Wakeup flag For module 7
    static const uint8_t LLWU_MF5_MWUF7 = 1U << 7 ;

//-------------------- LLWU Pin Filter 1 register
#define LLWU_FILT1 (* ((volatile uint8_t *) (0x4007C000 + 0xE)))

  // Field (width: 5 bits): Filter Pin Select
    inline uint8_t LLWU_FILT1_FILTSEL (const uint8_t inValue) { return (inValue & 31U) << 0 ; }

  // Field (width: 2 bits): Digital Filter On External Pin
    inline uint8_t LLWU_FILT1_FILTE (const uint8_t inValue) { return (inValue & 3U) << 5 ; }

  // Boolean field: Filter Detect Flag
    static const uint8_t LLWU_FILT1_FILTF = 1U << 7 ;

//-------------------- LLWU Pin Filter 2 register
#define LLWU_FILT2 (* ((volatile uint8_t *) (0x4007C000 + 0xF)))

  // Field (width: 5 bits): Filter Pin Select
    inline uint8_t LLWU_FILT2_FILTSEL (const uint8_t inValue) { return (inValue & 31U) << 0 ; }

  // Field (width: 2 bits): Digital Filter On External Pin
    inline uint8_t LLWU_FILT2_FILTE (const uint8_t inValue) { return (inValue & 3U) << 5 ; }

  // Boolean field: Filter Detect Flag
    static const uint8_t LLWU_FILT2_FILTF = 1U << 7 ;

//-------------------- LLWU Pin Filter 3 register
#define LLWU_FILT3 (* ((volatile uint8_t *) (0x4007C000 + 0x10)))

  // Field (width: 5 bits): Filter Pin Select
    inline uint8_t LLWU_FILT3_FILTSEL (const uint8_t inValue) { return (inValue & 31U) << 0 ; }

  // Field (width: 2 bits): Digital Filter On External Pin
    inline uint8_t LLWU_FILT3_FILTE (const uint8_t inValue) { return (inValue & 3U) << 5 ; }

  // Boolean field: Filter Detect Flag
    static const uint8_t LLWU_FILT3_FILTF = 1U << 7 ;

//-------------------- LLWU Pin Filter 4 register
#define LLWU_FILT4 (* ((volatile uint8_t *) (0x4007C000 + 0x11)))

  // Field (width: 5 bits): Filter Pin Select
    inline uint8_t LLWU_FILT4_FILTSEL (const uint8_t inValue) { return (inValue & 31U) << 0 ; }

  // Field (width: 2 bits): Digital Filter On External Pin
    inline uint8_t LLWU_FILT4_FILTE (const uint8_t inValue) { return (inValue & 3U) << 5 ; }

  // Boolean field: Filter Detect Flag
    static const uint8_t LLWU_FILT4_FILTF = 1U << 7 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral PMC
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Low Voltage Detect Status And Control 1 register
#define PMC_LVDSC1 (* ((volatile uint8_t *) (0x4007D000 + 0)))

  // Field (width: 2 bits): Low-Voltage Detect Voltage Select
    inline uint8_t PMC_LVDSC1_LVDV (const uint8_t inValue) { return (inValue & 3U) << 0 ; }

  // Boolean field: Low-Voltage Detect Reset Enable
    static const uint8_t PMC_LVDSC1_LVDRE = 1U << 4 ;

  // Boolean field: Low-Voltage Detect Interrupt Enable
    static const uint8_t PMC_LVDSC1_LVDIE = 1U << 5 ;

  // Boolean field: Low-Voltage Detect Acknowledge
    static const uint8_t PMC_LVDSC1_LVDACK = 1U << 6 ;

  // Boolean field: Low-Voltage Detect Flag
    static const uint8_t PMC_LVDSC1_LVDF = 1U << 7 ;

//-------------------- Low Voltage Detect Status And Control 2 register
#define PMC_LVDSC2 (* ((volatile uint8_t *) (0x4007D000 + 0x1)))

  // Field (width: 2 bits): Low-Voltage Warning Voltage Select
    inline uint8_t PMC_LVDSC2_LVWV (const uint8_t inValue) { return (inValue & 3U) << 0 ; }

  // Boolean field: Low-Voltage Warning Interrupt Enable
    static const uint8_t PMC_LVDSC2_LVWIE = 1U << 5 ;

  // Boolean field: Low-Voltage Warning Acknowledge
    static const uint8_t PMC_LVDSC2_LVWACK = 1U << 6 ;

  // Boolean field: Low-Voltage Warning Flag
    static const uint8_t PMC_LVDSC2_LVWF = 1U << 7 ;

//-------------------- Regulator Status And Control register
#define PMC_REGSC (* ((volatile uint8_t *) (0x4007D000 + 0x2)))

  // Boolean field: Bandgap Buffer Enable
    static const uint8_t PMC_REGSC_BGBE = 1U << 0 ;

  // Boolean field: Regulator In Run Regulation Status
    static const uint8_t PMC_REGSC_REGONS = 1U << 2 ;

  // Boolean field: Acknowledge Isolation
    static const uint8_t PMC_REGSC_ACKISO = 1U << 3 ;

  // Boolean field: Bandgap Enable In VLPx Operation
    static const uint8_t PMC_REGSC_BGEN = 1U << 4 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral SMC
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Power Mode Protection register
#define SMC_PMPROT (* ((volatile uint8_t *) (0x4007E000 + 0)))

  // Boolean field: Allow Very-Low-Leakage Stop Mode
    static const uint8_t SMC_PMPROT_AVLLS = 1U << 1 ;

  // Boolean field: Allow Low-Leakage Stop Mode
    static const uint8_t SMC_PMPROT_ALLS = 1U << 3 ;

  // Boolean field: Allow Very-Low-Power Modes
    static const uint8_t SMC_PMPROT_AVLP = 1U << 5 ;

  // Boolean field: Allow High Speed Run mode
    static const uint8_t SMC_PMPROT_AHSRUN = 1U << 7 ;

//-------------------- Power Mode Control register
#define SMC_PMCTRL (* ((volatile uint8_t *) (0x4007E000 + 0x1)))

  // Field (width: 3 bits): Stop Mode Control
    inline uint8_t SMC_PMCTRL_STOPM (const uint8_t inValue) { return (inValue & 7U) << 0 ; }

  // Boolean field: Stop Aborted
    static const uint8_t SMC_PMCTRL_STOPA = 1U << 3 ;

  // Field (width: 2 bits): Run Mode Control
    inline uint8_t SMC_PMCTRL_RUNM (const uint8_t inValue) { return (inValue & 3U) << 5 ; }

//-------------------- Stop Control Register
#define SMC_STOPCTRL (* ((volatile uint8_t *) (0x4007E000 + 0x2)))

  // Field (width: 3 bits): LLS or VLLS Mode Control
    inline uint8_t SMC_STOPCTRL_LLSM (const uint8_t inValue) { return (inValue & 7U) << 0 ; }

  // Boolean field: RAM2 Power Option
    static const uint8_t SMC_STOPCTRL_RAM2PO = 1U << 4 ;

  // Boolean field: POR Power Option
    static const uint8_t SMC_STOPCTRL_PORPO = 1U << 5 ;

  // Field (width: 2 bits): Partial Stop Option
    inline uint8_t SMC_STOPCTRL_PSTOPO (const uint8_t inValue) { return (inValue & 3U) << 6 ; }

//-------------------- Power Mode Status register
#define SMC_PMSTAT (* ((const volatile uint8_t *) (0x4007E000 + 0x3)))

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral RCM
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- System Reset Status Register 0
#define RCM_SRS0 (* ((const volatile uint8_t *) (0x4007F000 + 0)))

  // Boolean field: Low Leakage Wakeup Reset
    static const uint8_t RCM_SRS0_WAKEUP = 1U << 0 ;

  // Boolean field: Low-Voltage Detect Reset
    static const uint8_t RCM_SRS0_LVD = 1U << 1 ;

  // Boolean field: Loss-of-Clock Reset
    static const uint8_t RCM_SRS0_LOC = 1U << 2 ;

  // Boolean field: Loss-of-Lock Reset
    static const uint8_t RCM_SRS0_LOL = 1U << 3 ;

  // Boolean field: Watchdog
    static const uint8_t RCM_SRS0_WDOG = 1U << 5 ;

  // Boolean field: External Reset Pin
    static const uint8_t RCM_SRS0_PIN = 1U << 6 ;

  // Boolean field: Power-On Reset
    static const uint8_t RCM_SRS0_POR = 1U << 7 ;

//-------------------- System Reset Status Register 1
#define RCM_SRS1 (* ((const volatile uint8_t *) (0x4007F000 + 0x1)))

  // Boolean field: JTAG Generated Reset
    static const uint8_t RCM_SRS1_JTAG = 1U << 0 ;

  // Boolean field: Core Lockup
    static const uint8_t RCM_SRS1_LOCKUP = 1U << 1 ;

  // Boolean field: Software
    static const uint8_t RCM_SRS1_SW = 1U << 2 ;

  // Boolean field: MDM-AP System Reset Request
    static const uint8_t RCM_SRS1_MDM_AP = 1U << 3 ;

  // Boolean field: EzPort Reset
    static const uint8_t RCM_SRS1_EZPT = 1U << 4 ;

  // Boolean field: Stop Mode Acknowledge Error Reset
    static const uint8_t RCM_SRS1_SACKERR = 1U << 5 ;

//-------------------- Reset Pin Filter Control register
#define RCM_RPFC (* ((volatile uint8_t *) (0x4007F000 + 0x4)))

  // Field (width: 2 bits): Reset Pin Filter Select in Run and Wait Modes
    inline uint8_t RCM_RPFC_RSTFLTSRW (const uint8_t inValue) { return (inValue & 3U) << 0 ; }

  // Boolean field: Reset Pin Filter Select in Stop Mode
    static const uint8_t RCM_RPFC_RSTFLTSS = 1U << 2 ;

//-------------------- Reset Pin Filter Width register
#define RCM_RPFW (* ((volatile uint8_t *) (0x4007F000 + 0x5)))

  // Field (width: 5 bits): Reset Pin Filter Bus Clock Select
    inline uint8_t RCM_RPFW_RSTFLTSEL (const uint8_t inValue) { return (inValue & 31U) << 0 ; }

//-------------------- Mode Register
#define RCM_MR (* ((const volatile uint8_t *) (0x4007F000 + 0x7)))

  // Boolean field: EZP_MS_B pin state
    static const uint8_t RCM_MR_EZP_MS = 1U << 1 ;

//-------------------- Sticky System Reset Status Register 0
#define RCM_SSRS0 (* ((volatile uint8_t *) (0x4007F000 + 0x8)))

  // Boolean field: Sticky Low Leakage Wakeup Reset
    static const uint8_t RCM_SSRS0_SWAKEUP = 1U << 0 ;

  // Boolean field: Sticky Low-Voltage Detect Reset
    static const uint8_t RCM_SSRS0_SLVD = 1U << 1 ;

  // Boolean field: Sticky Loss-of-Clock Reset
    static const uint8_t RCM_SSRS0_SLOC = 1U << 2 ;

  // Boolean field: Sticky Loss-of-Lock Reset
    static const uint8_t RCM_SSRS0_SLOL = 1U << 3 ;

  // Boolean field: Sticky Watchdog
    static const uint8_t RCM_SSRS0_SWDOG = 1U << 5 ;

  // Boolean field: Sticky External Reset Pin
    static const uint8_t RCM_SSRS0_SPIN = 1U << 6 ;

  // Boolean field: Sticky Power-On Reset
    static const uint8_t RCM_SSRS0_SPOR = 1U << 7 ;

//-------------------- Sticky System Reset Status Register 1
#define RCM_SSRS1 (* ((volatile uint8_t *) (0x4007F000 + 0x9)))

  // Boolean field: Sticky JTAG Generated Reset
    static const uint8_t RCM_SSRS1_SJTAG = 1U << 0 ;

  // Boolean field: Sticky Core Lockup
    static const uint8_t RCM_SSRS1_SLOCKUP = 1U << 1 ;

  // Boolean field: Sticky Software
    static const uint8_t RCM_SSRS1_SSW = 1U << 2 ;

  // Boolean field: Sticky MDM-AP System Reset Request
    static const uint8_t RCM_SSRS1_SMDM_AP = 1U << 3 ;

  // Boolean field: Sticky EzPort Reset
    static const uint8_t RCM_SSRS1_SEZPT = 1U << 4 ;

  // Boolean field: Sticky Stop Mode Acknowledge Error Reset
    static const uint8_t RCM_SSRS1_SSACKERR = 1U << 5 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral RNG
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- RNGA Control Register
#define RNG_CR (* ((volatile uint32_t *) (0x400A0000 + 0)))

  // Boolean field: Go
    static const uint32_t RNG_CR_GO = 1U << 0 ;

  // Boolean field: High Assurance
    static const uint32_t RNG_CR_HA = 1U << 1 ;

  // Boolean field: Interrupt Mask
    static const uint32_t RNG_CR_INTM = 1U << 2 ;

  // Boolean field: Clear Interrupt
    static const uint32_t RNG_CR_CLRI = 1U << 3 ;

  // Boolean field: Sleep
    static const uint32_t RNG_CR_SLP = 1U << 4 ;

//-------------------- RNGA Status Register
#define RNG_SR (* ((const volatile uint32_t *) (0x400A0000 + 0x4)))

  // Boolean field: Security Violation
    static const uint32_t RNG_SR_SECV = 1U << 0 ;

  // Boolean field: Last Read Status
    static const uint32_t RNG_SR_LRS = 1U << 1 ;

  // Boolean field: Output Register Underflow
    static const uint32_t RNG_SR_ORU = 1U << 2 ;

  // Boolean field: Error Interrupt
    static const uint32_t RNG_SR_ERRI = 1U << 3 ;

  // Boolean field: Sleep
    static const uint32_t RNG_SR_SLP = 1U << 4 ;

  // Field (width: 8 bits): Output Register Level
    inline uint32_t RNG_SR_OREG_LVL (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Output Register Size
    inline uint32_t RNG_SR_OREG_SIZE (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

//-------------------- RNGA Entropy Register
#define RNG_ER (* ((volatile uint32_t *) (0x400A0000 + 0x8)))

//-------------------- RNGA Output Register
#define RNG_OR (* ((const volatile uint32_t *) (0x400A0000 + 0xC)))

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral USBHS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Identification Register
#define USBHS_ID (* ((const volatile uint32_t *) (0x400A1000 + 0)))

  // Field (width: 6 bits): Configuration number
    inline uint32_t USBHS_ID_ID (const uint32_t inValue) { return (inValue & 63U) << 0 ; }

  // Field (width: 6 bits): Ones complement version of ID.
    inline uint32_t USBHS_ID_NID (const uint32_t inValue) { return (inValue & 63U) << 8 ; }

  // Field (width: 5 bits): Tag
    inline uint32_t USBHS_ID_TAG (const uint32_t inValue) { return (inValue & 31U) << 16 ; }

  // Field (width: 4 bits): Revision
    inline uint32_t USBHS_ID_REVISION (const uint32_t inValue) { return (inValue & 15U) << 21 ; }

  // Field (width: 4 bits): Version
    inline uint32_t USBHS_ID_VERSION (const uint32_t inValue) { return (inValue & 15U) << 25 ; }

  // Field (width: 3 bits): Version ID
    inline uint32_t USBHS_ID_VERSIONID (const uint32_t inValue) { return (inValue & 7U) << 29 ; }

//-------------------- General Hardware Parameters Register
#define USBHS_HWGENERAL (* ((const volatile uint32_t *) (0x400A1000 + 0x4)))

  // Field (width: 2 bits): PHY Width
    inline uint32_t USBHS_HWGENERAL_PHYW (const uint32_t inValue) { return (inValue & 3U) << 4 ; }

  // Field (width: 3 bits): PHY Mode
    inline uint32_t USBHS_HWGENERAL_PHYM (const uint32_t inValue) { return (inValue & 7U) << 6 ; }

  // Field (width: 2 bits): Serial mode
    inline uint32_t USBHS_HWGENERAL_SM (const uint32_t inValue) { return (inValue & 3U) << 9 ; }

//-------------------- Host Hardware Parameters Register
#define USBHS_HWHOST (* ((const volatile uint32_t *) (0x400A1000 + 0x8)))

  // Boolean field: Host Capable
    static const uint32_t USBHS_HWHOST_HC = 1U << 0 ;

  // Field (width: 3 bits): Number of Ports
    inline uint32_t USBHS_HWHOST_NPORT (const uint32_t inValue) { return (inValue & 7U) << 1 ; }

  // Field (width: 8 bits): Transaction translator contexts.
    inline uint32_t USBHS_HWHOST_TTASY (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Transaction translator periodic contexts.
    inline uint32_t USBHS_HWHOST_TTPER (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Device Hardware Parameters Register
#define USBHS_HWDEVICE (* ((const volatile uint32_t *) (0x400A1000 + 0xC)))

  // Boolean field: Device Capable
    static const uint32_t USBHS_HWDEVICE_DC = 1U << 0 ;

  // Field (width: 5 bits): Device endpoints.
    inline uint32_t USBHS_HWDEVICE_DEVEP (const uint32_t inValue) { return (inValue & 31U) << 1 ; }

//-------------------- Transmit Buffer Hardware Parameters Register
#define USBHS_HWTXBUF (* ((const volatile uint32_t *) (0x400A1000 + 0x10)))

  // Field (width: 8 bits): Transmit Burst.
    inline uint32_t USBHS_HWTXBUF_TXBURST (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Transmit Address.
    inline uint32_t USBHS_HWTXBUF_TXADD (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Transmit Channel Address
    inline uint32_t USBHS_HWTXBUF_TXCHANADD (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Boolean field: Transmit local Context Registers
    static const uint32_t USBHS_HWTXBUF_TXLC = 1U << 31 ;

//-------------------- Receive Buffer Hardware Parameters Register
#define USBHS_HWRXBUF (* ((const volatile uint32_t *) (0x400A1000 + 0x14)))

  // Field (width: 8 bits): Receive Burst.
    inline uint32_t USBHS_HWRXBUF_RXBURST (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Receive Address.
    inline uint32_t USBHS_HWRXBUF_RXADD (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

//-------------------- General Purpose Timer n Load Register (idx = 0 ... 1)
#define USBHS_GPTIMERLD(idx) (* ((volatile uint32_t *) (0x400A1000 + 0x80 + 0x8 * (idx))))

  // Field (width: 24 bits): Specifies the value to be loaded into the countdown timer on a reset
    inline uint32_t USBHS_GPTIMERLD_GPTLD (const uint32_t inValue) { return (inValue & 16777215U) << 0 ; }

//-------------------- General Purpose Timer n Control Register (idx = 0 ... 1)
#define USBHS_GPTIMERCTL(idx) (* ((volatile uint32_t *) (0x400A1000 + 0x84 + 0x8 * (idx))))

  // Field (width: 24 bits): Timer Count
    inline uint32_t USBHS_GPTIMERCTL_GPTCNT (const uint32_t inValue) { return (inValue & 16777215U) << 0 ; }

  // Boolean field: Timer Mode
    static const uint32_t USBHS_GPTIMERCTL_MODE = 1U << 24 ;

  // Boolean field: Timer Reset
    static const uint32_t USBHS_GPTIMERCTL_RST = 1U << 30 ;

  // Boolean field: Timer Run
    static const uint32_t USBHS_GPTIMERCTL_RUN = 1U << 31 ;

//-------------------- System Bus Interface Configuration Register
#define USBHS_USB_SBUSCFG (* ((volatile uint32_t *) (0x400A1000 + 0x90)))

  // Field (width: 3 bits): Burst mode
    inline uint32_t USBHS_USB_SBUSCFG_BURSTMODE (const uint32_t inValue) { return (inValue & 7U) << 0 ; }

//-------------------- Host Controller Interface Version and Capability Registers Length Register
#define USBHS_HCIVERSION (* ((const volatile uint32_t *) (0x400A1000 + 0x100)))

  // Field (width: 8 bits): Capability registers length
    inline uint32_t USBHS_HCIVERSION_CAPLENGTH (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 16 bits): EHCI revision number
    inline uint32_t USBHS_HCIVERSION_HCIVERSION (const uint32_t inValue) { return (inValue & 65535U) << 16 ; }

//-------------------- Host Controller Structural Parameters Register
#define USBHS_HCSPARAMS (* ((const volatile uint32_t *) (0x400A1000 + 0x104)))

  // Field (width: 4 bits): Number of Ports
    inline uint32_t USBHS_HCSPARAMS_N_PORTS (const uint32_t inValue) { return (inValue & 15U) << 0 ; }

  // Boolean field: Power Port Control
    static const uint32_t USBHS_HCSPARAMS_PPC = 1U << 4 ;

  // Field (width: 4 bits): Number Ports per CC
    inline uint32_t USBHS_HCSPARAMS_N_PCC (const uint32_t inValue) { return (inValue & 15U) << 8 ; }

  // Field (width: 4 bits): Number of Companion Controllers
    inline uint32_t USBHS_HCSPARAMS_N_CC (const uint32_t inValue) { return (inValue & 15U) << 12 ; }

  // Boolean field: Port Indicators
    static const uint32_t USBHS_HCSPARAMS_PI = 1U << 16 ;

  // Field (width: 4 bits): Ports per Transaction Translator
    inline uint32_t USBHS_HCSPARAMS_N_PTT (const uint32_t inValue) { return (inValue & 15U) << 20 ; }

  // Field (width: 4 bits): Number of Transaction Translators.
    inline uint32_t USBHS_HCSPARAMS_N_TT (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

//-------------------- Host Controller Capability Parameters Register
#define USBHS_HCCPARAMS (* ((const volatile uint32_t *) (0x400A1000 + 0x108)))

  // Boolean field: 64-bit addressing capability.
    static const uint32_t USBHS_HCCPARAMS_ADC = 1U << 0 ;

  // Boolean field: Programmable Frame List flag
    static const uint32_t USBHS_HCCPARAMS_PFL = 1U << 1 ;

  // Boolean field: Asynchronous Schedule Park capability
    static const uint32_t USBHS_HCCPARAMS_ASP = 1U << 2 ;

  // Field (width: 4 bits): Isochronous Scheduling Threshold
    inline uint32_t USBHS_HCCPARAMS_IST (const uint32_t inValue) { return (inValue & 15U) << 4 ; }

  // Field (width: 8 bits): EHCI Extended Capabilities Pointer
    inline uint32_t USBHS_HCCPARAMS_EECP (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

//-------------------- Device Controller Interface Version
#define USBHS_DCIVERSION (* ((const volatile uint16_t *) (0x400A1000 + 0x122)))

//-------------------- Device Controller Capability Parameters
#define USBHS_DCCPARAMS (* ((const volatile uint32_t *) (0x400A1000 + 0x124)))

  // Field (width: 5 bits): Device Endpoint Number
    inline uint32_t USBHS_DCCPARAMS_DEN (const uint32_t inValue) { return (inValue & 31U) << 0 ; }

  // Boolean field: Device Capable
    static const uint32_t USBHS_DCCPARAMS_DC = 1U << 7 ;

  // Boolean field: Host Capable
    static const uint32_t USBHS_DCCPARAMS_HC = 1U << 8 ;

//-------------------- USB Command Register
#define USBHS_USBCMD (* ((volatile uint32_t *) (0x400A1000 + 0x140)))

  // Boolean field: Run/Stop
    static const uint32_t USBHS_USBCMD_RS = 1U << 0 ;

  // Boolean field: Controller Reset
    static const uint32_t USBHS_USBCMD_RST = 1U << 1 ;

  // Field (width: 2 bits): Frame list Size
    inline uint32_t USBHS_USBCMD_FS (const uint32_t inValue) { return (inValue & 3U) << 2 ; }

  // Boolean field: Periodic Schedule Enable
    static const uint32_t USBHS_USBCMD_PSE = 1U << 4 ;

  // Boolean field: Asynchronous Schedule Enable
    static const uint32_t USBHS_USBCMD_ASE = 1U << 5 ;

  // Boolean field: Interrupt on Async Advance doorbell
    static const uint32_t USBHS_USBCMD_IAA = 1U << 6 ;

  // Field (width: 2 bits): Asynchronous Schedule Park mode count
    inline uint32_t USBHS_USBCMD_ASP (const uint32_t inValue) { return (inValue & 3U) << 8 ; }

  // Boolean field: Asynchronous Schedule Park mode Enable
    static const uint32_t USBHS_USBCMD_ASPE = 1U << 11 ;

  // Boolean field: Setup TripWire
    static const uint32_t USBHS_USBCMD_SUTW = 1U << 13 ;

  // Boolean field: Add dTD TripWire
    static const uint32_t USBHS_USBCMD_ATDTW = 1U << 14 ;

  // Boolean field: Frame list Size 2
    static const uint32_t USBHS_USBCMD_FS2 = 1U << 15 ;

  // Field (width: 8 bits): Interrupt Threshold Control
    inline uint32_t USBHS_USBCMD_ITC (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

//-------------------- USB Status Register
#define USBHS_USBSTS (* ((volatile uint32_t *) (0x400A1000 + 0x144)))

  // Boolean field: USB Interrupt (USBINT)
    static const uint32_t USBHS_USBSTS_UI = 1U << 0 ;

  // Boolean field: USB Error Interrupt
    static const uint32_t USBHS_USBSTS_UEI = 1U << 1 ;

  // Boolean field: Port Change detect
    static const uint32_t USBHS_USBSTS_PCI = 1U << 2 ;

  // Boolean field: Frame-list Rollover
    static const uint32_t USBHS_USBSTS_FRI = 1U << 3 ;

  // Boolean field: System Error
    static const uint32_t USBHS_USBSTS_SEI = 1U << 4 ;

  // Boolean field: Interrupt on Async Advance
    static const uint32_t USBHS_USBSTS_AAI = 1U << 5 ;

  // Boolean field: USB Reset received
    static const uint32_t USBHS_USBSTS_URI = 1U << 6 ;

  // Boolean field: SOF Received
    static const uint32_t USBHS_USBSTS_SRI = 1U << 7 ;

  // Boolean field: Device-controller suspend
    static const uint32_t USBHS_USBSTS_SLI = 1U << 8 ;

  // Boolean field: Host Controller Halted
    static const uint32_t USBHS_USBSTS_HCH = 1U << 12 ;

  // Boolean field: Reclamation
    static const uint32_t USBHS_USBSTS_RCL = 1U << 13 ;

  // Boolean field: Periodic schedule Status
    static const uint32_t USBHS_USBSTS_PS = 1U << 14 ;

  // Boolean field: Asynchronous schedule Status
    static const uint32_t USBHS_USBSTS_AS = 1U << 15 ;

  // Boolean field: NAK Interrupt
    static const uint32_t USBHS_USBSTS_NAKI = 1U << 16 ;

  // Boolean field: USB host Asynchronous Interrupt
    static const uint32_t USBHS_USBSTS_UAI = 1U << 18 ;

  // Boolean field: USB host Periodic Interrupt
    static const uint32_t USBHS_USBSTS_UPI = 1U << 19 ;

  // Boolean field: General purpose Timer 0 Interrupt
    static const uint32_t USBHS_USBSTS_TI0 = 1U << 24 ;

  // Boolean field: General purpose Timer 1 Interrupt
    static const uint32_t USBHS_USBSTS_TI1 = 1U << 25 ;

//-------------------- USB Interrupt Enable Register
#define USBHS_USBINTR (* ((volatile uint32_t *) (0x400A1000 + 0x148)))

  // Boolean field: USB interrupt Enable
    static const uint32_t USBHS_USBINTR_UE = 1U << 0 ;

  // Boolean field: USB Error interrupt Enable
    static const uint32_t USBHS_USBINTR_UEE = 1U << 1 ;

  // Boolean field: Port Change detect Enable
    static const uint32_t USBHS_USBINTR_PCE = 1U << 2 ;

  // Boolean field: Frame list Rollover Enable
    static const uint32_t USBHS_USBINTR_FRE = 1U << 3 ;

  // Boolean field: System Error Enable
    static const uint32_t USBHS_USBINTR_SEE = 1U << 4 ;

  // Boolean field: Interrupt on Async advance Enable
    static const uint32_t USBHS_USBINTR_AAE = 1U << 5 ;

  // Boolean field: USB-Reset Enable
    static const uint32_t USBHS_USBINTR_URE = 1U << 6 ;

  // Boolean field: SOF-Received Enable
    static const uint32_t USBHS_USBINTR_SRE = 1U << 7 ;

  // Boolean field: Sleep (DC suspend) Enable
    static const uint32_t USBHS_USBINTR_SLE = 1U << 8 ;

  // Boolean field: NAK Interrupt Enable
    static const uint32_t USBHS_USBINTR_NAKE = 1U << 16 ;

  // Boolean field: USB host Asynchronous Interrupt Enable
    static const uint32_t USBHS_USBINTR_UAIE = 1U << 18 ;

  // Boolean field: USB host Periodic Interrupt Enable
    static const uint32_t USBHS_USBINTR_UPIE = 1U << 19 ;

  // Boolean field: General purpose Timer 0 Interrupt Enable
    static const uint32_t USBHS_USBINTR_TIE0 = 1U << 24 ;

  // Boolean field: General purpose Timer 1 Interrupt Enable
    static const uint32_t USBHS_USBINTR_TIE1 = 1U << 25 ;

//-------------------- Frame Index Register
#define USBHS_FRINDEX (* ((volatile uint32_t *) (0x400A1000 + 0x14C)))

  // Field (width: 14 bits): Frame Index
    inline uint32_t USBHS_FRINDEX_FRINDEX (const uint32_t inValue) { return (inValue & 16383U) << 0 ; }

  // Field (width: 18 bits): Reserved
    inline uint32_t USBHS_FRINDEX_Reerved (const uint32_t inValue) { return (inValue & 262143U) << 14 ; }

//-------------------- Device Address Register
#define USBHS_DEVICEADDR (* ((volatile uint32_t *) (0x400A1000 + 0x154)))

  // Boolean field: Device Address Advance
    static const uint32_t USBHS_DEVICEADDR_USBADRA = 1U << 24 ;

  // Field (width: 7 bits): Device Address
    inline uint32_t USBHS_DEVICEADDR_USBADR (const uint32_t inValue) { return (inValue & 127U) << 25 ; }

//-------------------- Periodic Frame List Base Address Register
#define USBHS_PERIODICLISTBASE (* ((volatile uint32_t *) (0x400A1000 + 0x154)))

  // Field (width: 20 bits): Base address
    inline uint32_t USBHS_PERIODICLISTBASE_PERBASE (const uint32_t inValue) { return (inValue & 1048575U) << 12 ; }

//-------------------- Current Asynchronous List Address Register
#define USBHS_ASYNCLISTADDR (* ((volatile uint32_t *) (0x400A1000 + 0x158)))

  // Field (width: 27 bits): Link pointer low (LPL)
    inline uint32_t USBHS_ASYNCLISTADDR_ASYBASE (const uint32_t inValue) { return (inValue & 134217727U) << 5 ; }

//-------------------- Endpoint List Address Register
#define USBHS_EPLISTADDR (* ((volatile uint32_t *) (0x400A1000 + 0x158)))

  // Field (width: 21 bits): Endpoint list address
    inline uint32_t USBHS_EPLISTADDR_EPBASE (const uint32_t inValue) { return (inValue & 2097151U) << 11 ; }

//-------------------- Host TT Asynchronous Buffer Control
#define USBHS_TTCTRL (* ((const volatile uint32_t *) (0x400A1000 + 0x15C)))

  // Field (width: 7 bits): TT Hub Address
    inline uint32_t USBHS_TTCTRL_TTHA (const uint32_t inValue) { return (inValue & 127U) << 24 ; }

  // Boolean field: Reserved
    static const uint32_t USBHS_TTCTRL_Reerved = 1U << 31 ;

//-------------------- Master Interface Data Burst Size Register
#define USBHS_BURSTSIZE (* ((volatile uint32_t *) (0x400A1000 + 0x160)))

  // Field (width: 8 bits): Programable RX Burst length
    inline uint32_t USBHS_BURSTSIZE_RXPBURST (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Programable TX Burst length
    inline uint32_t USBHS_BURSTSIZE_TXPBURST (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

//-------------------- Transmit FIFO Tuning Control Register
#define USBHS_TXFILLTUNING (* ((volatile uint32_t *) (0x400A1000 + 0x164)))

  // Field (width: 7 bits): Scheduler Overhead
    inline uint32_t USBHS_TXFILLTUNING_TXSCHOH (const uint32_t inValue) { return (inValue & 127U) << 0 ; }

  // Field (width: 5 bits): Scheduler Health counter
    inline uint32_t USBHS_TXFILLTUNING_TXSCHHEALTH (const uint32_t inValue) { return (inValue & 31U) << 8 ; }

  // Field (width: 6 bits): FIFO burst Threshold
    inline uint32_t USBHS_TXFILLTUNING_TXFIFOTHRES (const uint32_t inValue) { return (inValue & 63U) << 16 ; }

//-------------------- Endpoint NAK Register
#define USBHS_ENDPTNAK (* ((volatile uint32_t *) (0x400A1000 + 0x178)))

  // Field (width: 4 bits): RX Endpoint NAK
    inline uint32_t USBHS_ENDPTNAK_EPRN (const uint32_t inValue) { return (inValue & 15U) << 0 ; }

  // Field (width: 4 bits): TX Endpoint NAK
    inline uint32_t USBHS_ENDPTNAK_EPTN (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

//-------------------- Endpoint NAK Enable Register
#define USBHS_ENDPTNAKEN (* ((volatile uint32_t *) (0x400A1000 + 0x17C)))

  // Field (width: 4 bits): RX Endpoint NAK
    inline uint32_t USBHS_ENDPTNAKEN_EPRNE (const uint32_t inValue) { return (inValue & 15U) << 0 ; }

  // Field (width: 4 bits): TX Endpoint NAK
    inline uint32_t USBHS_ENDPTNAKEN_EPTNE (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

//-------------------- Configure Flag Register
#define USBHS_CONFIGFLAG (* ((const volatile uint32_t *) (0x400A1000 + 0x180)))

//-------------------- Port Status and Control Registers
#define USBHS_PORTSC1 (* ((volatile uint32_t *) (0x400A1000 + 0x184)))

  // Boolean field: Current Connect Status
    static const uint32_t USBHS_PORTSC1_CCS = 1U << 0 ;

  // Boolean field: Connect Change Status
    static const uint32_t USBHS_PORTSC1_CSC = 1U << 1 ;

  // Boolean field: Port Enabled/disabled
    static const uint32_t USBHS_PORTSC1_PE = 1U << 2 ;

  // Boolean field: Port Enable/disable Change
    static const uint32_t USBHS_PORTSC1_PEC = 1U << 3 ;

  // Boolean field: Over-current active
    static const uint32_t USBHS_PORTSC1_OCA = 1U << 4 ;

  // Boolean field: Over-Current Change
    static const uint32_t USBHS_PORTSC1_OCC = 1U << 5 ;

  // Boolean field: Force Port Resume
    static const uint32_t USBHS_PORTSC1_FPR = 1U << 6 ;

  // Boolean field: Suspend
    static const uint32_t USBHS_PORTSC1_SUSP = 1U << 7 ;

  // Boolean field: Port Reset
    static const uint32_t USBHS_PORTSC1_PR = 1U << 8 ;

  // Boolean field: High Speed Port.
    static const uint32_t USBHS_PORTSC1_HSP = 1U << 9 ;

  // Field (width: 2 bits): Line Status
    inline uint32_t USBHS_PORTSC1_LS (const uint32_t inValue) { return (inValue & 3U) << 10 ; }

  // Boolean field: Port Power
    static const uint32_t USBHS_PORTSC1_PP = 1U << 12 ;

  // Boolean field: Port Owner
    static const uint32_t USBHS_PORTSC1_PO = 1U << 13 ;

  // Field (width: 2 bits): Port Indicator Control
    inline uint32_t USBHS_PORTSC1_PIC (const uint32_t inValue) { return (inValue & 3U) << 14 ; }

  // Field (width: 4 bits): Port Test Control
    inline uint32_t USBHS_PORTSC1_PTC (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Boolean field: Wake on Connect enable
    static const uint32_t USBHS_PORTSC1_WKCN = 1U << 20 ;

  // Boolean field: Wake on Disconnect enable
    static const uint32_t USBHS_PORTSC1_WKDS = 1U << 21 ;

  // Boolean field: Wake on Over-Current enable
    static const uint32_t USBHS_PORTSC1_WKOC = 1U << 22 ;

  // Boolean field: PHY low power suspend
    static const uint32_t USBHS_PORTSC1_PHCD = 1U << 23 ;

  // Boolean field: Port force Full-Speed Connect
    static const uint32_t USBHS_PORTSC1_PFSC = 1U << 24 ;

  // Boolean field: Port Transceiver Select [2]
    static const uint32_t USBHS_PORTSC1_PTS2 = 1U << 25 ;

  // Field (width: 2 bits): Port Speed
    inline uint32_t USBHS_PORTSC1_PSPD (const uint32_t inValue) { return (inValue & 3U) << 26 ; }

  // Field (width: 2 bits): Port Transceiver Select [1:0]
    inline uint32_t USBHS_PORTSC1_PTS (const uint32_t inValue) { return (inValue & 3U) << 30 ; }

//-------------------- On-the-Go Status and Control Register
#define USBHS_OTGSC (* ((volatile uint32_t *) (0x400A1000 + 0x1A4)))

  // Boolean field: VBUS Discharge
    static const uint32_t USBHS_OTGSC_VD = 1U << 0 ;

  // Boolean field: VBUS Charge
    static const uint32_t USBHS_OTGSC_VC = 1U << 1 ;

  // Boolean field: Hardware Assist Auto-Reset
    static const uint32_t USBHS_OTGSC_HAAR = 1U << 2 ;

  // Boolean field: OTG Termination
    static const uint32_t USBHS_OTGSC_OT = 1U << 3 ;

  // Boolean field: Data Pulsing
    static const uint32_t USBHS_OTGSC_DP = 1U << 4 ;

  // Boolean field: ID Pull-Up
    static const uint32_t USBHS_OTGSC_IDPU = 1U << 5 ;

  // Boolean field: Hardware Assist B-Disconnect to A-connect
    static const uint32_t USBHS_OTGSC_HABA = 1U << 7 ;

  // Boolean field: USB ID
    static const uint32_t USBHS_OTGSC_ID = 1U << 8 ;

  // Boolean field: A VBus Valid
    static const uint32_t USBHS_OTGSC_AVV = 1U << 9 ;

  // Boolean field: A Session Valid
    static const uint32_t USBHS_OTGSC_ASV = 1U << 10 ;

  // Boolean field: B Session Valid
    static const uint32_t USBHS_OTGSC_BSV = 1U << 11 ;

  // Boolean field: B Session End
    static const uint32_t USBHS_OTGSC_BSE = 1U << 12 ;

  // Boolean field: 1 Milli-Second timer Toggle
    static const uint32_t USBHS_OTGSC_MST = 1U << 13 ;

  // Boolean field: Data bus Pulsing Status
    static const uint32_t USBHS_OTGSC_DPS = 1U << 14 ;

  // Boolean field: USB ID Interrupt Status
    static const uint32_t USBHS_OTGSC_IDIS = 1U << 16 ;

  // Boolean field: A VBUS Valid Interrupt Status
    static const uint32_t USBHS_OTGSC_AVVIS = 1U << 17 ;

  // Boolean field: A Session Valid Interrupt Status
    static const uint32_t USBHS_OTGSC_ASVIS = 1U << 18 ;

  // Boolean field: B Session Valid Interrupt Status
    static const uint32_t USBHS_OTGSC_BSVIS = 1U << 19 ;

  // Boolean field: B Session End Interrupt Status
    static const uint32_t USBHS_OTGSC_BSEIS = 1U << 20 ;

  // Boolean field: 1 Milli-Second timer interrupt Status
    static const uint32_t USBHS_OTGSC_MSS = 1U << 21 ;

  // Boolean field: Data Pulse interrupt Status
    static const uint32_t USBHS_OTGSC_DPIS = 1U << 22 ;

  // Boolean field: USB ID Interrupt Enable
    static const uint32_t USBHS_OTGSC_IDIE = 1U << 24 ;

  // Boolean field: A VBUS Valid Interrupt Enable
    static const uint32_t USBHS_OTGSC_AVVIE = 1U << 25 ;

  // Boolean field: A Session Valid Interrupt Enable
    static const uint32_t USBHS_OTGSC_ASVIE = 1U << 26 ;

  // Boolean field: B Session Valid Interrupt Enable
    static const uint32_t USBHS_OTGSC_BSVIE = 1U << 27 ;

  // Boolean field: B Session End Interrupt Enable
    static const uint32_t USBHS_OTGSC_BSEIE = 1U << 28 ;

  // Boolean field: 1 Milli-Second timer interrupt Enable
    static const uint32_t USBHS_OTGSC_MSE = 1U << 29 ;

  // Boolean field: Data Pulse Interrupt Enable
    static const uint32_t USBHS_OTGSC_DPIE = 1U << 30 ;

//-------------------- USB Mode Register
#define USBHS_USBMODE (* ((volatile uint32_t *) (0x400A1000 + 0x1A8)))

  // Field (width: 2 bits): Controller Mode
    inline uint32_t USBHS_USBMODE_CM (const uint32_t inValue) { return (inValue & 3U) << 0 ; }

  // Boolean field: Endian Select
    static const uint32_t USBHS_USBMODE_ES = 1U << 2 ;

  // Boolean field: Setup Lock-Out Mode
    static const uint32_t USBHS_USBMODE_SLOM = 1U << 3 ;

  // Boolean field: Stream DISable
    static const uint32_t USBHS_USBMODE_SDIS = 1U << 4 ;

  // Field (width: 3 bits): Tx to Tx HS Delay
    inline uint32_t USBHS_USBMODE_TXHSD (const uint32_t inValue) { return (inValue & 7U) << 12 ; }

//-------------------- Endpoint Setup Status Register
#define USBHS_EPSETUPSR (* ((volatile uint32_t *) (0x400A1000 + 0x1AC)))

  // Field (width: 4 bits): Setup Endpoint Status
    inline uint32_t USBHS_EPSETUPSR_EPSETUPSTAT (const uint32_t inValue) { return (inValue & 15U) << 0 ; }

//-------------------- Endpoint Initialization Register
#define USBHS_EPPRIME (* ((volatile uint32_t *) (0x400A1000 + 0x1B0)))

  // Field (width: 4 bits): Prime Endpoint Receive Buffer
    inline uint32_t USBHS_EPPRIME_PERB (const uint32_t inValue) { return (inValue & 15U) << 0 ; }

  // Field (width: 4 bits): Prime Endpoint tTansmit Buffer
    inline uint32_t USBHS_EPPRIME_PETB (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

//-------------------- Endpoint Flush Register
#define USBHS_EPFLUSH (* ((volatile uint32_t *) (0x400A1000 + 0x1B4)))

  // Field (width: 4 bits): Flush Endpoint Receive Buffer
    inline uint32_t USBHS_EPFLUSH_FERB (const uint32_t inValue) { return (inValue & 15U) << 0 ; }

  // Field (width: 4 bits): Flush Endpoint Transmit Buffer
    inline uint32_t USBHS_EPFLUSH_FETB (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

//-------------------- Endpoint Status Register
#define USBHS_EPSR (* ((const volatile uint32_t *) (0x400A1000 + 0x1B8)))

  // Field (width: 4 bits): Endpoint Receive Buffer Ready
    inline uint32_t USBHS_EPSR_ERBR (const uint32_t inValue) { return (inValue & 15U) << 0 ; }

  // Field (width: 4 bits): Endpoint Transmit Buffer Ready
    inline uint32_t USBHS_EPSR_ETBR (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

//-------------------- Endpoint Complete Register
#define USBHS_EPCOMPLETE (* ((volatile uint32_t *) (0x400A1000 + 0x1BC)))

  // Field (width: 4 bits): Endpoint Receive Complete Event
    inline uint32_t USBHS_EPCOMPLETE_ERCE (const uint32_t inValue) { return (inValue & 15U) << 0 ; }

  // Field (width: 4 bits): Endpoint Transmit Complete Event
    inline uint32_t USBHS_EPCOMPLETE_ETCE (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

//-------------------- Endpoint Control Register 0
#define USBHS_EPCR0 (* ((volatile uint32_t *) (0x400A1000 + 0x1C0)))

  // Boolean field: RX endpoint Stall
    static const uint32_t USBHS_EPCR0_RXS = 1U << 0 ;

  // Field (width: 2 bits): RX endpoint Type
    inline uint32_t USBHS_EPCR0_RXT (const uint32_t inValue) { return (inValue & 3U) << 2 ; }

  // Boolean field: RX endpoint Enable
    static const uint32_t USBHS_EPCR0_RXE = 1U << 7 ;

  // Boolean field: TX Endpoint Stall
    static const uint32_t USBHS_EPCR0_TXS = 1U << 16 ;

  // Field (width: 2 bits): TX Endpoint Type
    inline uint32_t USBHS_EPCR0_TXT (const uint32_t inValue) { return (inValue & 3U) << 18 ; }

  // Boolean field: TX Endpoint Enable
    static const uint32_t USBHS_EPCR0_TXE = 1U << 23 ;

//-------------------- Endpoint Control Register n (idx = 0 ... 6)
#define USBHS_EPCR(idx) (* ((volatile uint32_t *) (0x400A1000 + 0x1C4 + 0x4 * (idx))))

  // Boolean field: RX endpoint Stall
    static const uint32_t USBHS_EPCR_RXS = 1U << 0 ;

  // Boolean field: RX endpoint Data sink
    static const uint32_t USBHS_EPCR_RXD = 1U << 1 ;

  // Field (width: 2 bits): RX endpoint Type
    inline uint32_t USBHS_EPCR_RXT (const uint32_t inValue) { return (inValue & 3U) << 2 ; }

  // Boolean field: RX data toggle Inhibit
    static const uint32_t USBHS_EPCR_RXI = 1U << 5 ;

  // Boolean field: RX data toggle Reset
    static const uint32_t USBHS_EPCR_RXR = 1U << 6 ;

  // Boolean field: RX endpoint Enable
    static const uint32_t USBHS_EPCR_RXE = 1U << 7 ;

  // Boolean field: TX endpoint Stall
    static const uint32_t USBHS_EPCR_TXS = 1U << 16 ;

  // Boolean field: TX endpoint Data source
    static const uint32_t USBHS_EPCR_TXD = 1U << 17 ;

  // Field (width: 2 bits): TX endpoint Type
    inline uint32_t USBHS_EPCR_TXT (const uint32_t inValue) { return (inValue & 3U) << 18 ; }

  // Boolean field: TX data toggle Inhibit
    static const uint32_t USBHS_EPCR_TXI = 1U << 21 ;

  // Boolean field: TX data toggle Reset
    static const uint32_t USBHS_EPCR_TXR = 1U << 22 ;

  // Boolean field: TX endpoint Enable
    static const uint32_t USBHS_EPCR_TXE = 1U << 23 ;

//-------------------- USB General Control Register
#define USBHS_USBGENCTRL (* ((volatile uint32_t *) (0x400A1000 + 0x200)))

  // Boolean field: Wakeup Interrupt Enable
    static const uint32_t USBHS_USBGENCTRL_WU_IE = 1U << 0 ;

  // Boolean field: Wakeup Interrupt Clear
    static const uint32_t USBHS_USBGENCTRL_WU_INT_CLR = 1U << 5 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral USBPHY
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- USB PHY Power-Down Register
#define USBPHY_PWD (* ((volatile uint32_t *) (0x400A2000 + 0)))

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_TXPWDFS = 1U << 10 ;

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_TXPWDIBIAS = 1U << 11 ;

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_TXPWDV2I = 1U << 12 ;

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_RXPWDENV = 1U << 17 ;

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_RXPWD1PT1 = 1U << 18 ;

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_RXPWDDIFF = 1U << 19 ;

  // Boolean field: This bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_RXPWDRX = 1U << 20 ;

//-------------------- USB PHY Power-Down Register
#define USBPHY_PWD_SET (* ((volatile uint32_t *) (0x400A2000 + 0x4)))

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_SET_TXPWDFS = 1U << 10 ;

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_SET_TXPWDIBIAS = 1U << 11 ;

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_SET_TXPWDV2I = 1U << 12 ;

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_SET_RXPWDENV = 1U << 17 ;

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_SET_RXPWD1PT1 = 1U << 18 ;

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_SET_RXPWDDIFF = 1U << 19 ;

  // Boolean field: This bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_SET_RXPWDRX = 1U << 20 ;

//-------------------- USB PHY Power-Down Register
#define USBPHY_PWD_CLR (* ((volatile uint32_t *) (0x400A2000 + 0x8)))

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_CLR_TXPWDFS = 1U << 10 ;

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_CLR_TXPWDIBIAS = 1U << 11 ;

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_CLR_TXPWDV2I = 1U << 12 ;

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_CLR_RXPWDENV = 1U << 17 ;

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_CLR_RXPWD1PT1 = 1U << 18 ;

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_CLR_RXPWDDIFF = 1U << 19 ;

  // Boolean field: This bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_CLR_RXPWDRX = 1U << 20 ;

//-------------------- USB PHY Power-Down Register
#define USBPHY_PWD_TOG (* ((volatile uint32_t *) (0x400A2000 + 0xC)))

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_TOG_TXPWDFS = 1U << 10 ;

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_TOG_TXPWDIBIAS = 1U << 11 ;

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_TOG_TXPWDV2I = 1U << 12 ;

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_TOG_RXPWDENV = 1U << 17 ;

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_TOG_RXPWD1PT1 = 1U << 18 ;

  // Boolean field: Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_TOG_RXPWDDIFF = 1U << 19 ;

  // Boolean field: This bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHY_CTRL is enabled
    static const uint32_t USBPHY_PWD_TOG_RXPWDRX = 1U << 20 ;

//-------------------- USB PHY Transmitter Control Register
#define USBPHY_TX (* ((volatile uint32_t *) (0x400A2000 + 0x10)))

  // Field (width: 4 bits): Decode to trim the nominal 17
    inline uint32_t USBPHY_TX_D_CAL (const uint32_t inValue) { return (inValue & 15U) << 0 ; }

  // Field (width: 4 bits): Decode to trim the nominal 45ohm series termination resistance to the USB_DM output pin
    inline uint32_t USBPHY_TX_TXCAL45DM (const uint32_t inValue) { return (inValue & 15U) << 8 ; }

  // Field (width: 4 bits): Decode to trim the nominal 45ohm series termination resistance to the USB_DP output pin
    inline uint32_t USBPHY_TX_TXCAL45DP (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 3 bits): Controls the edge-rate of the current sensing transistors used in HS transmit
    inline uint32_t USBPHY_TX_USBPHY_TX_EDGECTRL (const uint32_t inValue) { return (inValue & 7U) << 26 ; }

//-------------------- USB PHY Transmitter Control Register
#define USBPHY_TX_SET (* ((volatile uint32_t *) (0x400A2000 + 0x14)))

  // Field (width: 4 bits): Decode to trim the nominal 17
    inline uint32_t USBPHY_TX_SET_D_CAL (const uint32_t inValue) { return (inValue & 15U) << 0 ; }

  // Field (width: 4 bits): Decode to trim the nominal 45ohm series termination resistance to the USB_DM output pin
    inline uint32_t USBPHY_TX_SET_TXCAL45DM (const uint32_t inValue) { return (inValue & 15U) << 8 ; }

  // Field (width: 4 bits): Decode to trim the nominal 45ohm series termination resistance to the USB_DP output pin
    inline uint32_t USBPHY_TX_SET_TXCAL45DP (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 3 bits): Controls the edge-rate of the current sensing transistors used in HS transmit
    inline uint32_t USBPHY_TX_SET_USBPHY_TX_EDGECTRL (const uint32_t inValue) { return (inValue & 7U) << 26 ; }

//-------------------- USB PHY Transmitter Control Register
#define USBPHY_TX_CLR (* ((volatile uint32_t *) (0x400A2000 + 0x18)))

  // Field (width: 4 bits): Decode to trim the nominal 17
    inline uint32_t USBPHY_TX_CLR_D_CAL (const uint32_t inValue) { return (inValue & 15U) << 0 ; }

  // Field (width: 4 bits): Decode to trim the nominal 45ohm series termination resistance to the USB_DM output pin
    inline uint32_t USBPHY_TX_CLR_TXCAL45DM (const uint32_t inValue) { return (inValue & 15U) << 8 ; }

  // Field (width: 4 bits): Decode to trim the nominal 45ohm series termination resistance to the USB_DP output pin
    inline uint32_t USBPHY_TX_CLR_TXCAL45DP (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 3 bits): Controls the edge-rate of the current sensing transistors used in HS transmit
    inline uint32_t USBPHY_TX_CLR_USBPHY_TX_EDGECTRL (const uint32_t inValue) { return (inValue & 7U) << 26 ; }

//-------------------- USB PHY Transmitter Control Register
#define USBPHY_TX_TOG (* ((volatile uint32_t *) (0x400A2000 + 0x1C)))

  // Field (width: 4 bits): Decode to trim the nominal 17
    inline uint32_t USBPHY_TX_TOG_D_CAL (const uint32_t inValue) { return (inValue & 15U) << 0 ; }

  // Field (width: 4 bits): Decode to trim the nominal 45ohm series termination resistance to the USB_DM output pin
    inline uint32_t USBPHY_TX_TOG_TXCAL45DM (const uint32_t inValue) { return (inValue & 15U) << 8 ; }

  // Field (width: 4 bits): Decode to trim the nominal 45ohm series termination resistance to the USB_DP output pin
    inline uint32_t USBPHY_TX_TOG_TXCAL45DP (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 3 bits): Controls the edge-rate of the current sensing transistors used in HS transmit
    inline uint32_t USBPHY_TX_TOG_USBPHY_TX_EDGECTRL (const uint32_t inValue) { return (inValue & 7U) << 26 ; }

//-------------------- USB PHY Receiver Control Register
#define USBPHY_RX (* ((volatile uint32_t *) (0x400A2000 + 0x20)))

  // Field (width: 3 bits): The ENVADJ field adjusts the trip point for the envelope detector
    inline uint32_t USBPHY_RX_ENVADJ (const uint32_t inValue) { return (inValue & 7U) << 0 ; }

  // Field (width: 3 bits): The DISCONADJ field adjusts the trip point for the disconnect detector.
    inline uint32_t USBPHY_RX_DISCONADJ (const uint32_t inValue) { return (inValue & 7U) << 4 ; }

  // Boolean field: This test mode is intended for lab use only, replace FS differential receiver with DP single ended receiver
    static const uint32_t USBPHY_RX_RXDBYPASS = 1U << 22 ;

//-------------------- USB PHY Receiver Control Register
#define USBPHY_RX_SET (* ((volatile uint32_t *) (0x400A2000 + 0x24)))

  // Field (width: 3 bits): The ENVADJ field adjusts the trip point for the envelope detector
    inline uint32_t USBPHY_RX_SET_ENVADJ (const uint32_t inValue) { return (inValue & 7U) << 0 ; }

  // Field (width: 3 bits): The DISCONADJ field adjusts the trip point for the disconnect detector.
    inline uint32_t USBPHY_RX_SET_DISCONADJ (const uint32_t inValue) { return (inValue & 7U) << 4 ; }

  // Boolean field: This test mode is intended for lab use only, replace FS differential receiver with DP single ended receiver
    static const uint32_t USBPHY_RX_SET_RXDBYPASS = 1U << 22 ;

//-------------------- USB PHY Receiver Control Register
#define USBPHY_RX_CLR (* ((volatile uint32_t *) (0x400A2000 + 0x28)))

  // Field (width: 3 bits): The ENVADJ field adjusts the trip point for the envelope detector
    inline uint32_t USBPHY_RX_CLR_ENVADJ (const uint32_t inValue) { return (inValue & 7U) << 0 ; }

  // Field (width: 3 bits): The DISCONADJ field adjusts the trip point for the disconnect detector.
    inline uint32_t USBPHY_RX_CLR_DISCONADJ (const uint32_t inValue) { return (inValue & 7U) << 4 ; }

  // Boolean field: This test mode is intended for lab use only, replace FS differential receiver with DP single ended receiver
    static const uint32_t USBPHY_RX_CLR_RXDBYPASS = 1U << 22 ;

//-------------------- USB PHY Receiver Control Register
#define USBPHY_RX_TOG (* ((volatile uint32_t *) (0x400A2000 + 0x2C)))

  // Field (width: 3 bits): The ENVADJ field adjusts the trip point for the envelope detector
    inline uint32_t USBPHY_RX_TOG_ENVADJ (const uint32_t inValue) { return (inValue & 7U) << 0 ; }

  // Field (width: 3 bits): The DISCONADJ field adjusts the trip point for the disconnect detector.
    inline uint32_t USBPHY_RX_TOG_DISCONADJ (const uint32_t inValue) { return (inValue & 7U) << 4 ; }

  // Boolean field: This test mode is intended for lab use only, replace FS differential receiver with DP single ended receiver
    static const uint32_t USBPHY_RX_TOG_RXDBYPASS = 1U << 22 ;

//-------------------- USB PHY General Control Register
#define USBPHY_CTRL (* ((volatile uint32_t *) (0x400A2000 + 0x30)))

  // Boolean field: For host mode, enables high-speed disconnect detector
    static const uint32_t USBPHY_CTRL_ENHOSTDISCONDETECT = 1U << 1 ;

  // Boolean field: Indicates that the device has disconnected in High-Speed mode
    static const uint32_t USBPHY_CTRL_HOSTDISCONDETECT_IRQ = 1U << 3 ;

  // Boolean field: Enables non-standard resistive plugged-in detection
    static const uint32_t USBPHY_CTRL_ENDEVPLUGINDET = 1U << 4 ;

  // Boolean field: Indicates that the device is connected
    static const uint32_t USBPHY_CTRL_DEVPLUGIN_IRQ = 1U << 12 ;

  // Boolean field: Enables UTMI+ Level 2 operation for the USB HS PHY
    static const uint32_t USBPHY_CTRL_ENUTMILEVEL2 = 1U << 14 ;

  // Boolean field: Enables UTMI+ Level 3 operation for the USB HS PHY
    static const uint32_t USBPHY_CTRL_ENUTMILEVEL3 = 1U << 15 ;

  // Boolean field: Enable the auto resume feature, when set, HW will use 32KHz clock to send Resume to respond to the device remote wakeup(for host mode only)
    static const uint32_t USBPHY_CTRL_AUTORESUME_EN = 1U << 18 ;

  // Boolean field: Enables the feature to auto-clear the CLKGATE bit if there is wakeup event while USB is suspended
    static const uint32_t USBPHY_CTRL_ENAUTOCLR_CLKGATE = 1U << 19 ;

  // Boolean field: Enables the feature to auto-clear the PWD register bits in USBPHY_PWD if there is wakeup event while USB is suspended
    static const uint32_t USBPHY_CTRL_ENAUTOCLR_PHY_PWD = 1U << 20 ;

  // Boolean field: Enables the feature to reset the FSDLL lock detection logic at the end of each TX packet.
    static const uint32_t USBPHY_CTRL_FSDLL_RST_EN = 1U << 24 ;

  // Boolean field: Indicates the results of USB_ID pin while monitoring the cable plugged into the Micro- or Mini-AB receptacle
    static const uint32_t USBPHY_CTRL_OTG_ID_VALUE = 1U << 27 ;

  // Boolean field: Forces the next FS packet that is transmitted to have a EOP with low-speed timing
    static const uint32_t USBPHY_CTRL_HOST_FORCE_LS_SE0 = 1U << 28 ;

  // Boolean field: Used by the PHY to indicate a powered-down state
    static const uint32_t USBPHY_CTRL_UTMI_SUSPENDM = 1U << 29 ;

  // Boolean field: Gate UTMI Clocks
    static const uint32_t USBPHY_CTRL_CLKGATE = 1U << 30 ;

  // Boolean field: Writing a 1 to this bit will soft-reset the USBPHY_PWD, USBPHY_TX, USBPHY_RX, and USBPHY_CTRL registers
    static const uint32_t USBPHY_CTRL_SFTRST = 1U << 31 ;

//-------------------- USB PHY General Control Register
#define USBPHY_CTRL_SET (* ((volatile uint32_t *) (0x400A2000 + 0x34)))

  // Boolean field: For host mode, enables high-speed disconnect detector
    static const uint32_t USBPHY_CTRL_SET_ENHOSTDISCONDETECT = 1U << 1 ;

  // Boolean field: Indicates that the device has disconnected in High-Speed mode
    static const uint32_t USBPHY_CTRL_SET_HOSTDISCONDETECT_IRQ = 1U << 3 ;

  // Boolean field: Enables non-standard resistive plugged-in detection
    static const uint32_t USBPHY_CTRL_SET_ENDEVPLUGINDET = 1U << 4 ;

  // Boolean field: Indicates that the device is connected
    static const uint32_t USBPHY_CTRL_SET_DEVPLUGIN_IRQ = 1U << 12 ;

  // Boolean field: Enables UTMI+ Level 2 operation for the USB HS PHY
    static const uint32_t USBPHY_CTRL_SET_ENUTMILEVEL2 = 1U << 14 ;

  // Boolean field: Enables UTMI+ Level 3 operation for the USB HS PHY
    static const uint32_t USBPHY_CTRL_SET_ENUTMILEVEL3 = 1U << 15 ;

  // Boolean field: Enable the auto resume feature, when set, HW will use 32KHz clock to send Resume to respond to the device remote wakeup(for host mode only)
    static const uint32_t USBPHY_CTRL_SET_AUTORESUME_EN = 1U << 18 ;

  // Boolean field: Enables the feature to auto-clear the CLKGATE bit if there is wakeup event while USB is suspended
    static const uint32_t USBPHY_CTRL_SET_ENAUTOCLR_CLKGATE = 1U << 19 ;

  // Boolean field: Enables the feature to auto-clear the PWD register bits in USBPHY_PWD if there is wakeup event while USB is suspended
    static const uint32_t USBPHY_CTRL_SET_ENAUTOCLR_PHY_PWD = 1U << 20 ;

  // Boolean field: Enables the feature to reset the FSDLL lock detection logic at the end of each TX packet.
    static const uint32_t USBPHY_CTRL_SET_FSDLL_RST_EN = 1U << 24 ;

  // Boolean field: Indicates the results of USB_ID pin while monitoring the cable plugged into the Micro- or Mini-AB receptacle
    static const uint32_t USBPHY_CTRL_SET_OTG_ID_VALUE = 1U << 27 ;

  // Boolean field: Forces the next FS packet that is transmitted to have a EOP with low-speed timing
    static const uint32_t USBPHY_CTRL_SET_HOST_FORCE_LS_SE0 = 1U << 28 ;

  // Boolean field: Used by the PHY to indicate a powered-down state
    static const uint32_t USBPHY_CTRL_SET_UTMI_SUSPENDM = 1U << 29 ;

  // Boolean field: Gate UTMI Clocks
    static const uint32_t USBPHY_CTRL_SET_CLKGATE = 1U << 30 ;

  // Boolean field: Writing a 1 to this bit will soft-reset the USBPHY_PWD, USBPHY_TX, USBPHY_RX, and USBPHY_CTRL registers
    static const uint32_t USBPHY_CTRL_SET_SFTRST = 1U << 31 ;

//-------------------- USB PHY General Control Register
#define USBPHY_CTRL_CLR (* ((volatile uint32_t *) (0x400A2000 + 0x38)))

  // Boolean field: For host mode, enables high-speed disconnect detector
    static const uint32_t USBPHY_CTRL_CLR_ENHOSTDISCONDETECT = 1U << 1 ;

  // Boolean field: Indicates that the device has disconnected in High-Speed mode
    static const uint32_t USBPHY_CTRL_CLR_HOSTDISCONDETECT_IRQ = 1U << 3 ;

  // Boolean field: Enables non-standard resistive plugged-in detection
    static const uint32_t USBPHY_CTRL_CLR_ENDEVPLUGINDET = 1U << 4 ;

  // Boolean field: Indicates that the device is connected
    static const uint32_t USBPHY_CTRL_CLR_DEVPLUGIN_IRQ = 1U << 12 ;

  // Boolean field: Enables UTMI+ Level 2 operation for the USB HS PHY
    static const uint32_t USBPHY_CTRL_CLR_ENUTMILEVEL2 = 1U << 14 ;

  // Boolean field: Enables UTMI+ Level 3 operation for the USB HS PHY
    static const uint32_t USBPHY_CTRL_CLR_ENUTMILEVEL3 = 1U << 15 ;

  // Boolean field: Enable the auto resume feature, when set, HW will use 32KHz clock to send Resume to respond to the device remote wakeup(for host mode only)
    static const uint32_t USBPHY_CTRL_CLR_AUTORESUME_EN = 1U << 18 ;

  // Boolean field: Enables the feature to auto-clear the CLKGATE bit if there is wakeup event while USB is suspended
    static const uint32_t USBPHY_CTRL_CLR_ENAUTOCLR_CLKGATE = 1U << 19 ;

  // Boolean field: Enables the feature to auto-clear the PWD register bits in USBPHY_PWD if there is wakeup event while USB is suspended
    static const uint32_t USBPHY_CTRL_CLR_ENAUTOCLR_PHY_PWD = 1U << 20 ;

  // Boolean field: Enables the feature to reset the FSDLL lock detection logic at the end of each TX packet.
    static const uint32_t USBPHY_CTRL_CLR_FSDLL_RST_EN = 1U << 24 ;

  // Boolean field: Indicates the results of USB_ID pin while monitoring the cable plugged into the Micro- or Mini-AB receptacle
    static const uint32_t USBPHY_CTRL_CLR_OTG_ID_VALUE = 1U << 27 ;

  // Boolean field: Forces the next FS packet that is transmitted to have a EOP with low-speed timing
    static const uint32_t USBPHY_CTRL_CLR_HOST_FORCE_LS_SE0 = 1U << 28 ;

  // Boolean field: Used by the PHY to indicate a powered-down state
    static const uint32_t USBPHY_CTRL_CLR_UTMI_SUSPENDM = 1U << 29 ;

  // Boolean field: Gate UTMI Clocks
    static const uint32_t USBPHY_CTRL_CLR_CLKGATE = 1U << 30 ;

  // Boolean field: Writing a 1 to this bit will soft-reset the USBPHY_PWD, USBPHY_TX, USBPHY_RX, and USBPHY_CTRL registers
    static const uint32_t USBPHY_CTRL_CLR_SFTRST = 1U << 31 ;

//-------------------- USB PHY General Control Register
#define USBPHY_CTRL_TOG (* ((volatile uint32_t *) (0x400A2000 + 0x3C)))

  // Boolean field: For host mode, enables high-speed disconnect detector
    static const uint32_t USBPHY_CTRL_TOG_ENHOSTDISCONDETECT = 1U << 1 ;

  // Boolean field: Indicates that the device has disconnected in High-Speed mode
    static const uint32_t USBPHY_CTRL_TOG_HOSTDISCONDETECT_IRQ = 1U << 3 ;

  // Boolean field: Enables non-standard resistive plugged-in detection
    static const uint32_t USBPHY_CTRL_TOG_ENDEVPLUGINDET = 1U << 4 ;

  // Boolean field: Indicates that the device is connected
    static const uint32_t USBPHY_CTRL_TOG_DEVPLUGIN_IRQ = 1U << 12 ;

  // Boolean field: Enables UTMI+ Level 2 operation for the USB HS PHY
    static const uint32_t USBPHY_CTRL_TOG_ENUTMILEVEL2 = 1U << 14 ;

  // Boolean field: Enables UTMI+ Level 3 operation for the USB HS PHY
    static const uint32_t USBPHY_CTRL_TOG_ENUTMILEVEL3 = 1U << 15 ;

  // Boolean field: Enable the auto resume feature, when set, HW will use 32KHz clock to send Resume to respond to the device remote wakeup(for host mode only)
    static const uint32_t USBPHY_CTRL_TOG_AUTORESUME_EN = 1U << 18 ;

  // Boolean field: Enables the feature to auto-clear the CLKGATE bit if there is wakeup event while USB is suspended
    static const uint32_t USBPHY_CTRL_TOG_ENAUTOCLR_CLKGATE = 1U << 19 ;

  // Boolean field: Enables the feature to auto-clear the PWD register bits in USBPHY_PWD if there is wakeup event while USB is suspended
    static const uint32_t USBPHY_CTRL_TOG_ENAUTOCLR_PHY_PWD = 1U << 20 ;

  // Boolean field: Enables the feature to reset the FSDLL lock detection logic at the end of each TX packet.
    static const uint32_t USBPHY_CTRL_TOG_FSDLL_RST_EN = 1U << 24 ;

  // Boolean field: Indicates the results of USB_ID pin while monitoring the cable plugged into the Micro- or Mini-AB receptacle
    static const uint32_t USBPHY_CTRL_TOG_OTG_ID_VALUE = 1U << 27 ;

  // Boolean field: Forces the next FS packet that is transmitted to have a EOP with low-speed timing
    static const uint32_t USBPHY_CTRL_TOG_HOST_FORCE_LS_SE0 = 1U << 28 ;

  // Boolean field: Used by the PHY to indicate a powered-down state
    static const uint32_t USBPHY_CTRL_TOG_UTMI_SUSPENDM = 1U << 29 ;

  // Boolean field: Gate UTMI Clocks
    static const uint32_t USBPHY_CTRL_TOG_CLKGATE = 1U << 30 ;

  // Boolean field: Writing a 1 to this bit will soft-reset the USBPHY_PWD, USBPHY_TX, USBPHY_RX, and USBPHY_CTRL registers
    static const uint32_t USBPHY_CTRL_TOG_SFTRST = 1U << 31 ;

//-------------------- USB PHY Status Register
#define USBPHY_STATUS (* ((volatile uint32_t *) (0x400A2000 + 0x40)))

  // Boolean field: Indicates at the local host (downstream) port that the remote device has disconnected while in High-Speed mode
    static const uint32_t USBPHY_STATUS_HOSTDISCONDETECT_STATUS = 1U << 3 ;

  // Boolean field: Status indicator for non-standard resistive plugged-in detection
    static const uint32_t USBPHY_STATUS_DEVPLUGIN_STATUS = 1U << 6 ;

  // Boolean field: Indicates the results of USB_ID pin on the USB cable plugged into the local Micro- or Mini-AB receptacle
    static const uint32_t USBPHY_STATUS_OTGID_STATUS = 1U << 8 ;

  // Boolean field: Indicates that the host is sending a wake-up after Suspend and has triggered an interrupt.
    static const uint32_t USBPHY_STATUS_RESUME_STATUS = 1U << 10 ;

//-------------------- USB PHY Debug Register
#define USBPHY_DEBUG (* ((volatile uint32_t *) (0x400A2000 + 0x50)))

  // Boolean field: Once OTG ID from USBPHY_STATUS_OTGID_STATUS is sampled, use this to hold the value
    static const uint32_t USBPHY_DEBUG_OTGIDPIOLOCK = 1U << 0 ;

  // Boolean field: Use holding registers to assist in timing for external UTMI interface.
    static const uint32_t USBPHY_DEBUG_DEBUG_INTERFACE_HOLD = 1U << 1 ;

  // Field (width: 2 bits): This bit field selects whether to connect pulldown resistors on the USB_DP/USB_DM pins if the corresponding pulldown overdrive mode is enabled through USBPHY_DEBUG[5:4} Set bit 3 to value 1'b1 to connect the 15ohm pulldown on USB_DP line
    inline uint32_t USBPHY_DEBUG_HSTPULLDOWN (const uint32_t inValue) { return (inValue & 3U) << 2 ; }

  // Field (width: 2 bits): This bit field selects host pulldown overdrive mode
    inline uint32_t USBPHY_DEBUG_ENHSTPULLDOWN (const uint32_t inValue) { return (inValue & 3U) << 4 ; }

  // Field (width: 4 bits): Delay in between the end of transmit to the beginning of receive
    inline uint32_t USBPHY_DEBUG_TX2RXCOUNT (const uint32_t inValue) { return (inValue & 15U) << 8 ; }

  // Boolean field: Set this bit to allow a countdown to transition in between TX and RX.
    static const uint32_t USBPHY_DEBUG_ENTX2RXCOUNT = 1U << 12 ;

  // Field (width: 5 bits): Delay in between the detection of squelch to the reset of high-speed RX.
    inline uint32_t USBPHY_DEBUG_SQUELCHRESETCOUNT (const uint32_t inValue) { return (inValue & 31U) << 16 ; }

  // Boolean field: Set bit to allow squelch to reset high-speed receive.
    static const uint32_t USBPHY_DEBUG_ENSQUELCHRESET = 1U << 24 ;

  // Field (width: 4 bits): Duration of RESET in terms of the number of 480-MHz cycles.
    inline uint32_t USBPHY_DEBUG_SQUELCHRESETLENGTH (const uint32_t inValue) { return (inValue & 15U) << 25 ; }

  // Boolean field: Choose to trigger the host resume SE0 with HOST_FORCE_LS_SE0 = 0 or UTMI_SUSPEND = 1.
    static const uint32_t USBPHY_DEBUG_HOST_RESUME_DEBUG = 1U << 29 ;

  // Boolean field: Gate Test Clocks
    static const uint32_t USBPHY_DEBUG_CLKGATE = 1U << 30 ;

//-------------------- USB PHY Debug Register
#define USBPHY_DEBUG_SET (* ((volatile uint32_t *) (0x400A2000 + 0x54)))

  // Boolean field: Once OTG ID from USBPHY_STATUS_OTGID_STATUS is sampled, use this to hold the value
    static const uint32_t USBPHY_DEBUG_SET_OTGIDPIOLOCK = 1U << 0 ;

  // Boolean field: Use holding registers to assist in timing for external UTMI interface.
    static const uint32_t USBPHY_DEBUG_SET_DEBUG_INTERFACE_HOLD = 1U << 1 ;

  // Field (width: 2 bits): This bit field selects whether to connect pulldown resistors on the USB_DP/USB_DM pins if the corresponding pulldown overdrive mode is enabled through USBPHY_DEBUG[5:4} Set bit 3 to value 1'b1 to connect the 15ohm pulldown on USB_DP line
    inline uint32_t USBPHY_DEBUG_SET_HSTPULLDOWN (const uint32_t inValue) { return (inValue & 3U) << 2 ; }

  // Field (width: 2 bits): This bit field selects host pulldown overdrive mode
    inline uint32_t USBPHY_DEBUG_SET_ENHSTPULLDOWN (const uint32_t inValue) { return (inValue & 3U) << 4 ; }

  // Field (width: 4 bits): Delay in between the end of transmit to the beginning of receive
    inline uint32_t USBPHY_DEBUG_SET_TX2RXCOUNT (const uint32_t inValue) { return (inValue & 15U) << 8 ; }

  // Boolean field: Set this bit to allow a countdown to transition in between TX and RX.
    static const uint32_t USBPHY_DEBUG_SET_ENTX2RXCOUNT = 1U << 12 ;

  // Field (width: 5 bits): Delay in between the detection of squelch to the reset of high-speed RX.
    inline uint32_t USBPHY_DEBUG_SET_SQUELCHRESETCOUNT (const uint32_t inValue) { return (inValue & 31U) << 16 ; }

  // Boolean field: Set bit to allow squelch to reset high-speed receive.
    static const uint32_t USBPHY_DEBUG_SET_ENSQUELCHRESET = 1U << 24 ;

  // Field (width: 4 bits): Duration of RESET in terms of the number of 480-MHz cycles.
    inline uint32_t USBPHY_DEBUG_SET_SQUELCHRESETLENGTH (const uint32_t inValue) { return (inValue & 15U) << 25 ; }

  // Boolean field: Choose to trigger the host resume SE0 with HOST_FORCE_LS_SE0 = 0 or UTMI_SUSPEND = 1.
    static const uint32_t USBPHY_DEBUG_SET_HOST_RESUME_DEBUG = 1U << 29 ;

  // Boolean field: Gate Test Clocks
    static const uint32_t USBPHY_DEBUG_SET_CLKGATE = 1U << 30 ;

//-------------------- USB PHY Debug Register
#define USBPHY_DEBUG_CLR (* ((volatile uint32_t *) (0x400A2000 + 0x58)))

  // Boolean field: Once OTG ID from USBPHY_STATUS_OTGID_STATUS is sampled, use this to hold the value
    static const uint32_t USBPHY_DEBUG_CLR_OTGIDPIOLOCK = 1U << 0 ;

  // Boolean field: Use holding registers to assist in timing for external UTMI interface.
    static const uint32_t USBPHY_DEBUG_CLR_DEBUG_INTERFACE_HOLD = 1U << 1 ;

  // Field (width: 2 bits): This bit field selects whether to connect pulldown resistors on the USB_DP/USB_DM pins if the corresponding pulldown overdrive mode is enabled through USBPHY_DEBUG[5:4} Set bit 3 to value 1'b1 to connect the 15ohm pulldown on USB_DP line
    inline uint32_t USBPHY_DEBUG_CLR_HSTPULLDOWN (const uint32_t inValue) { return (inValue & 3U) << 2 ; }

  // Field (width: 2 bits): This bit field selects host pulldown overdrive mode
    inline uint32_t USBPHY_DEBUG_CLR_ENHSTPULLDOWN (const uint32_t inValue) { return (inValue & 3U) << 4 ; }

  // Field (width: 4 bits): Delay in between the end of transmit to the beginning of receive
    inline uint32_t USBPHY_DEBUG_CLR_TX2RXCOUNT (const uint32_t inValue) { return (inValue & 15U) << 8 ; }

  // Boolean field: Set this bit to allow a countdown to transition in between TX and RX.
    static const uint32_t USBPHY_DEBUG_CLR_ENTX2RXCOUNT = 1U << 12 ;

  // Field (width: 5 bits): Delay in between the detection of squelch to the reset of high-speed RX.
    inline uint32_t USBPHY_DEBUG_CLR_SQUELCHRESETCOUNT (const uint32_t inValue) { return (inValue & 31U) << 16 ; }

  // Boolean field: Set bit to allow squelch to reset high-speed receive.
    static const uint32_t USBPHY_DEBUG_CLR_ENSQUELCHRESET = 1U << 24 ;

  // Field (width: 4 bits): Duration of RESET in terms of the number of 480-MHz cycles.
    inline uint32_t USBPHY_DEBUG_CLR_SQUELCHRESETLENGTH (const uint32_t inValue) { return (inValue & 15U) << 25 ; }

  // Boolean field: Choose to trigger the host resume SE0 with HOST_FORCE_LS_SE0 = 0 or UTMI_SUSPEND = 1.
    static const uint32_t USBPHY_DEBUG_CLR_HOST_RESUME_DEBUG = 1U << 29 ;

  // Boolean field: Gate Test Clocks
    static const uint32_t USBPHY_DEBUG_CLR_CLKGATE = 1U << 30 ;

//-------------------- USB PHY Debug Register
#define USBPHY_DEBUG_TOG (* ((volatile uint32_t *) (0x400A2000 + 0x5C)))

  // Boolean field: Once OTG ID from USBPHY_STATUS_OTGID_STATUS is sampled, use this to hold the value
    static const uint32_t USBPHY_DEBUG_TOG_OTGIDPIOLOCK = 1U << 0 ;

  // Boolean field: Use holding registers to assist in timing for external UTMI interface.
    static const uint32_t USBPHY_DEBUG_TOG_DEBUG_INTERFACE_HOLD = 1U << 1 ;

  // Field (width: 2 bits): This bit field selects whether to connect pulldown resistors on the USB_DP/USB_DM pins if the corresponding pulldown overdrive mode is enabled through USBPHY_DEBUG[5:4} Set bit 3 to value 1'b1 to connect the 15ohm pulldown on USB_DP line
    inline uint32_t USBPHY_DEBUG_TOG_HSTPULLDOWN (const uint32_t inValue) { return (inValue & 3U) << 2 ; }

  // Field (width: 2 bits): This bit field selects host pulldown overdrive mode
    inline uint32_t USBPHY_DEBUG_TOG_ENHSTPULLDOWN (const uint32_t inValue) { return (inValue & 3U) << 4 ; }

  // Field (width: 4 bits): Delay in between the end of transmit to the beginning of receive
    inline uint32_t USBPHY_DEBUG_TOG_TX2RXCOUNT (const uint32_t inValue) { return (inValue & 15U) << 8 ; }

  // Boolean field: Set this bit to allow a countdown to transition in between TX and RX.
    static const uint32_t USBPHY_DEBUG_TOG_ENTX2RXCOUNT = 1U << 12 ;

  // Field (width: 5 bits): Delay in between the detection of squelch to the reset of high-speed RX.
    inline uint32_t USBPHY_DEBUG_TOG_SQUELCHRESETCOUNT (const uint32_t inValue) { return (inValue & 31U) << 16 ; }

  // Boolean field: Set bit to allow squelch to reset high-speed receive.
    static const uint32_t USBPHY_DEBUG_TOG_ENSQUELCHRESET = 1U << 24 ;

  // Field (width: 4 bits): Duration of RESET in terms of the number of 480-MHz cycles.
    inline uint32_t USBPHY_DEBUG_TOG_SQUELCHRESETLENGTH (const uint32_t inValue) { return (inValue & 15U) << 25 ; }

  // Boolean field: Choose to trigger the host resume SE0 with HOST_FORCE_LS_SE0 = 0 or UTMI_SUSPEND = 1.
    static const uint32_t USBPHY_DEBUG_TOG_HOST_RESUME_DEBUG = 1U << 29 ;

  // Boolean field: Gate Test Clocks
    static const uint32_t USBPHY_DEBUG_TOG_CLKGATE = 1U << 30 ;

//-------------------- UTMI Debug Status Register 0
#define USBPHY_DEBUG0_STATUS (* ((const volatile uint32_t *) (0x400A2000 + 0x60)))

  // Field (width: 16 bits): Running count of the failed pseudo-random generator loopback
    inline uint32_t USBPHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Field (width: 10 bits): Running count of the UTMI_RXERROR.
    inline uint32_t USBPHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT (const uint32_t inValue) { return (inValue & 1023U) << 16 ; }

  // Field (width: 6 bits): Running count of the squelch reset instead of normal end for HS RX.
    inline uint32_t USBPHY_DEBUG0_STATUS_SQUELCH_COUNT (const uint32_t inValue) { return (inValue & 63U) << 26 ; }

//-------------------- UTMI Debug Status Register 1
#define USBPHY_DEBUG1 (* ((volatile uint32_t *) (0x400A2000 + 0x70)))

  // Field (width: 2 bits): Delay increment of the rise of squelch:
    inline uint32_t USBPHY_DEBUG1_ENTAILADJVD (const uint32_t inValue) { return (inValue & 3U) << 13 ; }

//-------------------- UTMI Debug Status Register 1
#define USBPHY_DEBUG1_SET (* ((volatile uint32_t *) (0x400A2000 + 0x74)))

  // Field (width: 2 bits): Delay increment of the rise of squelch:
    inline uint32_t USBPHY_DEBUG1_SET_ENTAILADJVD (const uint32_t inValue) { return (inValue & 3U) << 13 ; }

//-------------------- UTMI Debug Status Register 1
#define USBPHY_DEBUG1_CLR (* ((volatile uint32_t *) (0x400A2000 + 0x78)))

  // Field (width: 2 bits): Delay increment of the rise of squelch:
    inline uint32_t USBPHY_DEBUG1_CLR_ENTAILADJVD (const uint32_t inValue) { return (inValue & 3U) << 13 ; }

//-------------------- UTMI Debug Status Register 1
#define USBPHY_DEBUG1_TOG (* ((volatile uint32_t *) (0x400A2000 + 0x7C)))

  // Field (width: 2 bits): Delay increment of the rise of squelch:
    inline uint32_t USBPHY_DEBUG1_TOG_ENTAILADJVD (const uint32_t inValue) { return (inValue & 3U) << 13 ; }

//-------------------- UTMI RTL Version
#define USBPHY_VERSION (* ((const volatile uint32_t *) (0x400A2000 + 0x80)))

  // Field (width: 16 bits): Fixed read-only value reflecting the stepping of the RTL version.
    inline uint32_t USBPHY_VERSION_STEP (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Field (width: 8 bits): Fixed read-only value reflecting the MINOR field of the RTL version.
    inline uint32_t USBPHY_VERSION_MINOR (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Fixed read-only value reflecting the MAJOR field of the RTL version.
    inline uint32_t USBPHY_VERSION_MAJOR (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- USB PHY PLL Control/Status Register
#define USBPHY_PLL_SIC (* ((volatile uint32_t *) (0x400A2000 + 0xA0)))

  // Field (width: 2 bits): This field controls the USB PLL feedback loop divider
    inline uint32_t USBPHY_PLL_SIC_PLL_DIV_SEL (const uint32_t inValue) { return (inValue & 3U) << 0 ; }

  // Boolean field: Enable the USB clock output from the USB PHY PLL.
    static const uint32_t USBPHY_PLL_SIC_PLL_EN_USB_CLKS = 1U << 6 ;

  // Boolean field: Analog debug bit
    static const uint32_t USBPHY_PLL_SIC_PLL_HOLD_RING_OFF = 1U << 11 ;

  // Boolean field: Power up the USB PLL.
    static const uint32_t USBPHY_PLL_SIC_PLL_POWER = 1U << 12 ;

  // Boolean field: Enable the clock output from the USB PLL.
    static const uint32_t USBPHY_PLL_SIC_PLL_ENABLE = 1U << 13 ;

  // Boolean field: Bypass the USB PLL.
    static const uint32_t USBPHY_PLL_SIC_PLL_BYPASS = 1U << 16 ;

  // Boolean field: USB PLL lock status indicator
    static const uint32_t USBPHY_PLL_SIC_PLL_LOCK = 1U << 31 ;

//-------------------- USB PHY PLL Control/Status Register
#define USBPHY_PLL_SIC_SET (* ((volatile uint32_t *) (0x400A2000 + 0xA4)))

  // Field (width: 2 bits): This field controls the USB PLL feedback loop divider
    inline uint32_t USBPHY_PLL_SIC_SET_PLL_DIV_SEL (const uint32_t inValue) { return (inValue & 3U) << 0 ; }

  // Boolean field: Enable the USB clock output from the USB PHY PLL.
    static const uint32_t USBPHY_PLL_SIC_SET_PLL_EN_USB_CLKS = 1U << 6 ;

  // Boolean field: Analog debug bit
    static const uint32_t USBPHY_PLL_SIC_SET_PLL_HOLD_RING_OFF = 1U << 11 ;

  // Boolean field: Power up the USB PLL.
    static const uint32_t USBPHY_PLL_SIC_SET_PLL_POWER = 1U << 12 ;

  // Boolean field: Enable the clock output from the USB PLL.
    static const uint32_t USBPHY_PLL_SIC_SET_PLL_ENABLE = 1U << 13 ;

  // Boolean field: Bypass the USB PLL.
    static const uint32_t USBPHY_PLL_SIC_SET_PLL_BYPASS = 1U << 16 ;

  // Boolean field: USB PLL lock status indicator
    static const uint32_t USBPHY_PLL_SIC_SET_PLL_LOCK = 1U << 31 ;

//-------------------- USB PHY PLL Control/Status Register
#define USBPHY_PLL_SIC_CLR (* ((volatile uint32_t *) (0x400A2000 + 0xA8)))

  // Field (width: 2 bits): This field controls the USB PLL feedback loop divider
    inline uint32_t USBPHY_PLL_SIC_CLR_PLL_DIV_SEL (const uint32_t inValue) { return (inValue & 3U) << 0 ; }

  // Boolean field: Enable the USB clock output from the USB PHY PLL.
    static const uint32_t USBPHY_PLL_SIC_CLR_PLL_EN_USB_CLKS = 1U << 6 ;

  // Boolean field: Analog debug bit
    static const uint32_t USBPHY_PLL_SIC_CLR_PLL_HOLD_RING_OFF = 1U << 11 ;

  // Boolean field: Power up the USB PLL.
    static const uint32_t USBPHY_PLL_SIC_CLR_PLL_POWER = 1U << 12 ;

  // Boolean field: Enable the clock output from the USB PLL.
    static const uint32_t USBPHY_PLL_SIC_CLR_PLL_ENABLE = 1U << 13 ;

  // Boolean field: Bypass the USB PLL.
    static const uint32_t USBPHY_PLL_SIC_CLR_PLL_BYPASS = 1U << 16 ;

  // Boolean field: USB PLL lock status indicator
    static const uint32_t USBPHY_PLL_SIC_CLR_PLL_LOCK = 1U << 31 ;

//-------------------- USB PHY PLL Control/Status Register
#define USBPHY_PLL_SIC_TOG (* ((volatile uint32_t *) (0x400A2000 + 0xAC)))

  // Field (width: 2 bits): This field controls the USB PLL feedback loop divider
    inline uint32_t USBPHY_PLL_SIC_TOG_PLL_DIV_SEL (const uint32_t inValue) { return (inValue & 3U) << 0 ; }

  // Boolean field: Enable the USB clock output from the USB PHY PLL.
    static const uint32_t USBPHY_PLL_SIC_TOG_PLL_EN_USB_CLKS = 1U << 6 ;

  // Boolean field: Analog debug bit
    static const uint32_t USBPHY_PLL_SIC_TOG_PLL_HOLD_RING_OFF = 1U << 11 ;

  // Boolean field: Power up the USB PLL.
    static const uint32_t USBPHY_PLL_SIC_TOG_PLL_POWER = 1U << 12 ;

  // Boolean field: Enable the clock output from the USB PLL.
    static const uint32_t USBPHY_PLL_SIC_TOG_PLL_ENABLE = 1U << 13 ;

  // Boolean field: Bypass the USB PLL.
    static const uint32_t USBPHY_PLL_SIC_TOG_PLL_BYPASS = 1U << 16 ;

  // Boolean field: USB PLL lock status indicator
    static const uint32_t USBPHY_PLL_SIC_TOG_PLL_LOCK = 1U << 31 ;

//-------------------- USB PHY VBUS Detect Control Register
#define USBPHY_USB1_VBUS_DETECT (* ((volatile uint32_t *) (0x400A2000 + 0xC0)))

  // Field (width: 3 bits): Sets the threshold for the VBUSVALID comparator
    inline uint32_t USBPHY_USB1_VBUS_DETECT_VBUSVALID_THRESH (const uint32_t inValue) { return (inValue & 7U) << 0 ; }

  // Boolean field: VBUS detect signal override enable
    static const uint32_t USBPHY_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN = 1U << 3 ;

  // Boolean field: Override value for SESSEND
    static const uint32_t USBPHY_USB1_VBUS_DETECT_SESSEND_OVERRIDE = 1U << 4 ;

  // Boolean field: Override value for B-Device Session Valid
    static const uint32_t USBPHY_USB1_VBUS_DETECT_BVALID_OVERRIDE = 1U << 5 ;

  // Boolean field: Override value for A-Device Session Valid
    static const uint32_t USBPHY_USB1_VBUS_DETECT_AVALID_OVERRIDE = 1U << 6 ;

  // Boolean field: Override value for VBUS_VALID signal sent to USB controller
    static const uint32_t USBPHY_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE = 1U << 7 ;

  // Boolean field: Selects the source of the VBUS_VALID signal reported to the USB controller
    static const uint32_t USBPHY_USB1_VBUS_DETECT_VBUSVALID_SEL = 1U << 8 ;

  // Field (width: 2 bits): Selects the source of the VBUS_VALID signal reported to the USB controller
    inline uint32_t USBPHY_USB1_VBUS_DETECT_VBUS_SOURCE_SEL (const uint32_t inValue) { return (inValue & 3U) << 9 ; }

  // Boolean field: Selects the comparator used for VBUS_VALID
    static const uint32_t USBPHY_USB1_VBUS_DETECT_VBUSVALID_TO_SESSVALID = 1U << 18 ;

  // Boolean field: Enables the VBUS_VALID comparator
    static const uint32_t USBPHY_USB1_VBUS_DETECT_PWRUP_CMPS = 1U << 20 ;

  // Boolean field: Controls VBUS discharge resistor
    static const uint32_t USBPHY_USB1_VBUS_DETECT_DISCHARGE_VBUS = 1U << 26 ;

  // Boolean field: Enables resistors used for an older method of resistive battery charger detection
    static const uint32_t USBPHY_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR = 1U << 31 ;

//-------------------- USB PHY VBUS Detect Control Register
#define USBPHY_USB1_VBUS_DETECT_SET (* ((volatile uint32_t *) (0x400A2000 + 0xC4)))

  // Field (width: 3 bits): Sets the threshold for the VBUSVALID comparator
    inline uint32_t USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_THRESH (const uint32_t inValue) { return (inValue & 7U) << 0 ; }

  // Boolean field: VBUS detect signal override enable
    static const uint32_t USBPHY_USB1_VBUS_DETECT_SET_VBUS_OVERRIDE_EN = 1U << 3 ;

  // Boolean field: Override value for SESSEND
    static const uint32_t USBPHY_USB1_VBUS_DETECT_SET_SESSEND_OVERRIDE = 1U << 4 ;

  // Boolean field: Override value for B-Device Session Valid
    static const uint32_t USBPHY_USB1_VBUS_DETECT_SET_BVALID_OVERRIDE = 1U << 5 ;

  // Boolean field: Override value for A-Device Session Valid
    static const uint32_t USBPHY_USB1_VBUS_DETECT_SET_AVALID_OVERRIDE = 1U << 6 ;

  // Boolean field: Override value for VBUS_VALID signal sent to USB controller
    static const uint32_t USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_OVERRIDE = 1U << 7 ;

  // Boolean field: Selects the source of the VBUS_VALID signal reported to the USB controller
    static const uint32_t USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_SEL = 1U << 8 ;

  // Field (width: 2 bits): Selects the source of the VBUS_VALID signal reported to the USB controller
    inline uint32_t USBPHY_USB1_VBUS_DETECT_SET_VBUS_SOURCE_SEL (const uint32_t inValue) { return (inValue & 3U) << 9 ; }

  // Boolean field: Selects the comparator used for VBUS_VALID
    static const uint32_t USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_TO_SESSVALID = 1U << 18 ;

  // Boolean field: Enables the VBUS_VALID comparator
    static const uint32_t USBPHY_USB1_VBUS_DETECT_SET_PWRUP_CMPS = 1U << 20 ;

  // Boolean field: Controls VBUS discharge resistor
    static const uint32_t USBPHY_USB1_VBUS_DETECT_SET_DISCHARGE_VBUS = 1U << 26 ;

  // Boolean field: Enables resistors used for an older method of resistive battery charger detection
    static const uint32_t USBPHY_USB1_VBUS_DETECT_SET_EN_CHARGER_RESISTOR = 1U << 31 ;

//-------------------- USB PHY VBUS Detect Control Register
#define USBPHY_USB1_VBUS_DETECT_CLR (* ((volatile uint32_t *) (0x400A2000 + 0xC8)))

  // Field (width: 3 bits): Sets the threshold for the VBUSVALID comparator
    inline uint32_t USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_THRESH (const uint32_t inValue) { return (inValue & 7U) << 0 ; }

  // Boolean field: VBUS detect signal override enable
    static const uint32_t USBPHY_USB1_VBUS_DETECT_CLR_VBUS_OVERRIDE_EN = 1U << 3 ;

  // Boolean field: Override value for SESSEND
    static const uint32_t USBPHY_USB1_VBUS_DETECT_CLR_SESSEND_OVERRIDE = 1U << 4 ;

  // Boolean field: Override value for B-Device Session Valid
    static const uint32_t USBPHY_USB1_VBUS_DETECT_CLR_BVALID_OVERRIDE = 1U << 5 ;

  // Boolean field: Override value for A-Device Session Valid
    static const uint32_t USBPHY_USB1_VBUS_DETECT_CLR_AVALID_OVERRIDE = 1U << 6 ;

  // Boolean field: Override value for VBUS_VALID signal sent to USB controller
    static const uint32_t USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_OVERRIDE = 1U << 7 ;

  // Boolean field: Selects the source of the VBUS_VALID signal reported to the USB controller
    static const uint32_t USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_SEL = 1U << 8 ;

  // Field (width: 2 bits): Selects the source of the VBUS_VALID signal reported to the USB controller
    inline uint32_t USBPHY_USB1_VBUS_DETECT_CLR_VBUS_SOURCE_SEL (const uint32_t inValue) { return (inValue & 3U) << 9 ; }

  // Boolean field: Selects the comparator used for VBUS_VALID
    static const uint32_t USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_TO_SESSVALID = 1U << 18 ;

  // Boolean field: Enables the VBUS_VALID comparator
    static const uint32_t USBPHY_USB1_VBUS_DETECT_CLR_PWRUP_CMPS = 1U << 20 ;

  // Boolean field: Controls VBUS discharge resistor
    static const uint32_t USBPHY_USB1_VBUS_DETECT_CLR_DISCHARGE_VBUS = 1U << 26 ;

  // Boolean field: Enables resistors used for an older method of resistive battery charger detection
    static const uint32_t USBPHY_USB1_VBUS_DETECT_CLR_EN_CHARGER_RESISTOR = 1U << 31 ;

//-------------------- USB PHY VBUS Detect Control Register
#define USBPHY_USB1_VBUS_DETECT_TOG (* ((volatile uint32_t *) (0x400A2000 + 0xCC)))

  // Field (width: 3 bits): Sets the threshold for the VBUSVALID comparator
    inline uint32_t USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_THRESH (const uint32_t inValue) { return (inValue & 7U) << 0 ; }

  // Boolean field: VBUS detect signal override enable
    static const uint32_t USBPHY_USB1_VBUS_DETECT_TOG_VBUS_OVERRIDE_EN = 1U << 3 ;

  // Boolean field: Override value for SESSEND
    static const uint32_t USBPHY_USB1_VBUS_DETECT_TOG_SESSEND_OVERRIDE = 1U << 4 ;

  // Boolean field: Override value for B-Device Session Valid
    static const uint32_t USBPHY_USB1_VBUS_DETECT_TOG_BVALID_OVERRIDE = 1U << 5 ;

  // Boolean field: Override value for A-Device Session Valid
    static const uint32_t USBPHY_USB1_VBUS_DETECT_TOG_AVALID_OVERRIDE = 1U << 6 ;

  // Boolean field: Override value for VBUS_VALID signal sent to USB controller
    static const uint32_t USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_OVERRIDE = 1U << 7 ;

  // Boolean field: Selects the source of the VBUS_VALID signal reported to the USB controller
    static const uint32_t USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_SEL = 1U << 8 ;

  // Field (width: 2 bits): Selects the source of the VBUS_VALID signal reported to the USB controller
    inline uint32_t USBPHY_USB1_VBUS_DETECT_TOG_VBUS_SOURCE_SEL (const uint32_t inValue) { return (inValue & 3U) << 9 ; }

  // Boolean field: Selects the comparator used for VBUS_VALID
    static const uint32_t USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_TO_SESSVALID = 1U << 18 ;

  // Boolean field: Enables the VBUS_VALID comparator
    static const uint32_t USBPHY_USB1_VBUS_DETECT_TOG_PWRUP_CMPS = 1U << 20 ;

  // Boolean field: Controls VBUS discharge resistor
    static const uint32_t USBPHY_USB1_VBUS_DETECT_TOG_DISCHARGE_VBUS = 1U << 26 ;

  // Boolean field: Enables resistors used for an older method of resistive battery charger detection
    static const uint32_t USBPHY_USB1_VBUS_DETECT_TOG_EN_CHARGER_RESISTOR = 1U << 31 ;

//-------------------- USB PHY VBUS Detector Status Register
#define USBPHY_USB1_VBUS_DET_STAT (* ((const volatile uint32_t *) (0x400A2000 + 0xD0)))

  // Boolean field: Session End indicator
    static const uint32_t USBPHY_USB1_VBUS_DET_STAT_SESSEND = 1U << 0 ;

  // Boolean field: B-Device Session Valid status
    static const uint32_t USBPHY_USB1_VBUS_DET_STAT_BVALID = 1U << 1 ;

  // Boolean field: A-Device Session Valid status
    static const uint32_t USBPHY_USB1_VBUS_DET_STAT_AVALID = 1U << 2 ;

  // Boolean field: VBUS voltage status
    static const uint32_t USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID = 1U << 3 ;

  // Boolean field: VBUS_VALID_3V detector status
    static const uint32_t USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_3V = 1U << 4 ;

//-------------------- USB PHY Charger Detect Status Register
#define USBPHY_USB1_CHRG_DET_STAT (* ((const volatile uint32_t *) (0x400A2000 + 0xF0)))

  // Boolean field: Battery Charging Data Contact Detection phase output
    static const uint32_t USBPHY_USB1_CHRG_DET_STAT_PLUG_CONTACT = 1U << 0 ;

  // Boolean field: Battery Charging Primary Detection phase output
    static const uint32_t USBPHY_USB1_CHRG_DET_STAT_CHRG_DETECTED = 1U << 1 ;

  // Boolean field: Single ended receiver output for the USB_DM pin, from charger detection circuits.
    static const uint32_t USBPHY_USB1_CHRG_DET_STAT_DM_STATE = 1U << 2 ;

  // Boolean field: Single ended receiver output for the USB_DP pin, from charger detection circuits.
    static const uint32_t USBPHY_USB1_CHRG_DET_STAT_DP_STATE = 1U << 3 ;

  // Boolean field: Battery Charging Secondary Detection phase output
    static const uint32_t USBPHY_USB1_CHRG_DET_STAT_SECDET_DCP = 1U << 4 ;

//-------------------- USB PHY Analog Control Register
#define USBPHY_ANACTRL (* ((volatile uint32_t *) (0x400A2000 + 0x100)))

  // Boolean field: Test clock selection to analog test
    static const uint32_t USBPHY_ANACTRL_TESTCLK_SEL = 1U << 0 ;

  // Boolean field: This bit field controls clock gating (disabling) for the PFD pfd_clk output for power savings when the PFD is not used
    static const uint32_t USBPHY_ANACTRL_PFD_CLKGATE = 1U << 1 ;

  // Field (width: 2 bits): This bit field for the PFD selects the frequency relationship between the local pfd_clk output and the exported USB1PFDCLK
    inline uint32_t USBPHY_ANACTRL_PFD_CLK_SEL (const uint32_t inValue) { return (inValue & 3U) << 2 ; }

  // Field (width: 6 bits): PFD fractional divider setting used to select the pfd_clk output frequency
    inline uint32_t USBPHY_ANACTRL_PFD_FRAC (const uint32_t inValue) { return (inValue & 63U) << 4 ; }

  // Boolean field: Setting this field to 1'b1 will enable the 15kohm pulldown resistors on both USB_DP and USB_DM pins
    static const uint32_t USBPHY_ANACTRL_DEV_PULLDOWN = 1U << 10 ;

  // Field (width: 2 bits): Controls pre-emphasis time duration for the High Speed TX drivers after each data transition when the USBPHY_ANACTRL[EMPH_EN] bit is set high to 1'b1
    inline uint32_t USBPHY_ANACTRL_EMPH_PULSE_CTRL (const uint32_t inValue) { return (inValue & 3U) << 11 ; }

  // Boolean field: Enables pre-emphasis for the High-Speed TX drivers
    static const uint32_t USBPHY_ANACTRL_EMPH_EN = 1U << 13 ;

  // Field (width: 2 bits): Controls the amount of pre-emphasis current added for the High-Speed TX drivers after each data transition when the USBPHY_ANACTRL[EMPH_EN] bit is set high to 1'b1
    inline uint32_t USBPHY_ANACTRL_EMPH_CUR_CTRL (const uint32_t inValue) { return (inValue & 3U) << 14 ; }

  // Boolean field: PFD stable signal from the Phase Fractional Divider.
    static const uint32_t USBPHY_ANACTRL_PFD_STABLE = 1U << 31 ;

//-------------------- USB PHY Analog Control Register
#define USBPHY_ANACTRL_SET (* ((volatile uint32_t *) (0x400A2000 + 0x104)))

  // Boolean field: Test clock selection to analog test
    static const uint32_t USBPHY_ANACTRL_SET_TESTCLK_SEL = 1U << 0 ;

  // Boolean field: This bit field controls clock gating (disabling) for the PFD pfd_clk output for power savings when the PFD is not used
    static const uint32_t USBPHY_ANACTRL_SET_PFD_CLKGATE = 1U << 1 ;

  // Field (width: 2 bits): This bit field for the PFD selects the frequency relationship between the local pfd_clk output and the exported USB1PFDCLK
    inline uint32_t USBPHY_ANACTRL_SET_PFD_CLK_SEL (const uint32_t inValue) { return (inValue & 3U) << 2 ; }

  // Field (width: 6 bits): PFD fractional divider setting used to select the pfd_clk output frequency
    inline uint32_t USBPHY_ANACTRL_SET_PFD_FRAC (const uint32_t inValue) { return (inValue & 63U) << 4 ; }

  // Boolean field: Setting this field to 1'b1 will enable the 15kohm pulldown resistors on both USB_DP and USB_DM pins
    static const uint32_t USBPHY_ANACTRL_SET_DEV_PULLDOWN = 1U << 10 ;

  // Field (width: 2 bits): Controls pre-emphasis time duration for the High Speed TX drivers after each data transition when the USBPHY_ANACTRL[EMPH_EN] bit is set high to 1'b1
    inline uint32_t USBPHY_ANACTRL_SET_EMPH_PULSE_CTRL (const uint32_t inValue) { return (inValue & 3U) << 11 ; }

  // Boolean field: Enables pre-emphasis for the High-Speed TX drivers
    static const uint32_t USBPHY_ANACTRL_SET_EMPH_EN = 1U << 13 ;

  // Field (width: 2 bits): Controls the amount of pre-emphasis current added for the High-Speed TX drivers after each data transition when the USBPHY_ANACTRL[EMPH_EN] bit is set high to 1'b1
    inline uint32_t USBPHY_ANACTRL_SET_EMPH_CUR_CTRL (const uint32_t inValue) { return (inValue & 3U) << 14 ; }

  // Boolean field: PFD stable signal from the Phase Fractional Divider.
    static const uint32_t USBPHY_ANACTRL_SET_PFD_STABLE = 1U << 31 ;

//-------------------- USB PHY Analog Control Register
#define USBPHY_ANACTRL_CLR (* ((volatile uint32_t *) (0x400A2000 + 0x108)))

  // Boolean field: Test clock selection to analog test
    static const uint32_t USBPHY_ANACTRL_CLR_TESTCLK_SEL = 1U << 0 ;

  // Boolean field: This bit field controls clock gating (disabling) for the PFD pfd_clk output for power savings when the PFD is not used
    static const uint32_t USBPHY_ANACTRL_CLR_PFD_CLKGATE = 1U << 1 ;

  // Field (width: 2 bits): This bit field for the PFD selects the frequency relationship between the local pfd_clk output and the exported USB1PFDCLK
    inline uint32_t USBPHY_ANACTRL_CLR_PFD_CLK_SEL (const uint32_t inValue) { return (inValue & 3U) << 2 ; }

  // Field (width: 6 bits): PFD fractional divider setting used to select the pfd_clk output frequency
    inline uint32_t USBPHY_ANACTRL_CLR_PFD_FRAC (const uint32_t inValue) { return (inValue & 63U) << 4 ; }

  // Boolean field: Setting this field to 1'b1 will enable the 15kohm pulldown resistors on both USB_DP and USB_DM pins
    static const uint32_t USBPHY_ANACTRL_CLR_DEV_PULLDOWN = 1U << 10 ;

  // Field (width: 2 bits): Controls pre-emphasis time duration for the High Speed TX drivers after each data transition when the USBPHY_ANACTRL[EMPH_EN] bit is set high to 1'b1
    inline uint32_t USBPHY_ANACTRL_CLR_EMPH_PULSE_CTRL (const uint32_t inValue) { return (inValue & 3U) << 11 ; }

  // Boolean field: Enables pre-emphasis for the High-Speed TX drivers
    static const uint32_t USBPHY_ANACTRL_CLR_EMPH_EN = 1U << 13 ;

  // Field (width: 2 bits): Controls the amount of pre-emphasis current added for the High-Speed TX drivers after each data transition when the USBPHY_ANACTRL[EMPH_EN] bit is set high to 1'b1
    inline uint32_t USBPHY_ANACTRL_CLR_EMPH_CUR_CTRL (const uint32_t inValue) { return (inValue & 3U) << 14 ; }

  // Boolean field: PFD stable signal from the Phase Fractional Divider.
    static const uint32_t USBPHY_ANACTRL_CLR_PFD_STABLE = 1U << 31 ;

//-------------------- USB PHY Analog Control Register
#define USBPHY_ANACTRL_TOG (* ((volatile uint32_t *) (0x400A2000 + 0x10C)))

  // Boolean field: Test clock selection to analog test
    static const uint32_t USBPHY_ANACTRL_TOG_TESTCLK_SEL = 1U << 0 ;

  // Boolean field: This bit field controls clock gating (disabling) for the PFD pfd_clk output for power savings when the PFD is not used
    static const uint32_t USBPHY_ANACTRL_TOG_PFD_CLKGATE = 1U << 1 ;

  // Field (width: 2 bits): This bit field for the PFD selects the frequency relationship between the local pfd_clk output and the exported USB1PFDCLK
    inline uint32_t USBPHY_ANACTRL_TOG_PFD_CLK_SEL (const uint32_t inValue) { return (inValue & 3U) << 2 ; }

  // Field (width: 6 bits): PFD fractional divider setting used to select the pfd_clk output frequency
    inline uint32_t USBPHY_ANACTRL_TOG_PFD_FRAC (const uint32_t inValue) { return (inValue & 63U) << 4 ; }

  // Boolean field: Setting this field to 1'b1 will enable the 15kohm pulldown resistors on both USB_DP and USB_DM pins
    static const uint32_t USBPHY_ANACTRL_TOG_DEV_PULLDOWN = 1U << 10 ;

  // Field (width: 2 bits): Controls pre-emphasis time duration for the High Speed TX drivers after each data transition when the USBPHY_ANACTRL[EMPH_EN] bit is set high to 1'b1
    inline uint32_t USBPHY_ANACTRL_TOG_EMPH_PULSE_CTRL (const uint32_t inValue) { return (inValue & 3U) << 11 ; }

  // Boolean field: Enables pre-emphasis for the High-Speed TX drivers
    static const uint32_t USBPHY_ANACTRL_TOG_EMPH_EN = 1U << 13 ;

  // Field (width: 2 bits): Controls the amount of pre-emphasis current added for the High-Speed TX drivers after each data transition when the USBPHY_ANACTRL[EMPH_EN] bit is set high to 1'b1
    inline uint32_t USBPHY_ANACTRL_TOG_EMPH_CUR_CTRL (const uint32_t inValue) { return (inValue & 3U) << 14 ; }

  // Boolean field: PFD stable signal from the Phase Fractional Divider.
    static const uint32_t USBPHY_ANACTRL_TOG_PFD_STABLE = 1U << 31 ;

//-------------------- USB PHY Loopback Control/Status Register
#define USBPHY_USB1_LOOPBACK (* ((volatile uint32_t *) (0x400A2000 + 0x110)))

  // Boolean field: This bit enables the USB loopback test.
    static const uint32_t USBPHY_USB1_LOOPBACK_UTMI_TESTSTART = 1U << 0 ;

  // Boolean field: Mode control for USB loopback test
    static const uint32_t USBPHY_USB1_LOOPBACK_UTMI_DIG_TST0 = 1U << 1 ;

  // Boolean field: Mode control for USB loopback test
    static const uint32_t USBPHY_USB1_LOOPBACK_UTMI_DIG_TST1 = 1U << 2 ;

  // Boolean field: Select HS or FS mode for USB loopback testing
    static const uint32_t USBPHY_USB1_LOOPBACK_TSTI_TX_HS_MODE = 1U << 3 ;

  // Boolean field: Set to value 1'b1 to choose LS for USB loopback testing, set to value 1'b0 to choose HS or FS mode which is defined by TSTI1_TX_HS
    static const uint32_t USBPHY_USB1_LOOPBACK_TSTI_TX_LS_MODE = 1U << 4 ;

  // Boolean field: Enable TX for USB loopback test.
    static const uint32_t USBPHY_USB1_LOOPBACK_TSTI_TX_EN = 1U << 5 ;

  // Boolean field: Sets TX Hi-Z for USB loopback test.
    static const uint32_t USBPHY_USB1_LOOPBACK_TSTI_TX_HIZ = 1U << 6 ;

  // Boolean field: This read-only bit is a status bit for USB loopback test results
    static const uint32_t USBPHY_USB1_LOOPBACK_UTMO_DIG_TST0 = 1U << 7 ;

  // Boolean field: This read-only bit is a status bit for USB loopback test
    static const uint32_t USBPHY_USB1_LOOPBACK_UTMO_DIG_TST1 = 1U << 8 ;

  // Boolean field: Setting this bit field to value 1'b1 will enable the loopback test to dynamically change the packet speed
    static const uint32_t USBPHY_USB1_LOOPBACK_TSTI_HSFS_MODE_EN = 1U << 15 ;

  // Field (width: 8 bits): Selects the packet data byte used for USB loopback testing in Pulse mode
    inline uint32_t USBPHY_USB1_LOOPBACK_TSTPKT (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

//-------------------- USB PHY Loopback Control/Status Register
#define USBPHY_USB1_LOOPBACK_SET (* ((volatile uint32_t *) (0x400A2000 + 0x114)))

  // Boolean field: This bit enables the USB loopback test.
    static const uint32_t USBPHY_USB1_LOOPBACK_SET_UTMI_TESTSTART = 1U << 0 ;

  // Boolean field: Mode control for USB loopback test
    static const uint32_t USBPHY_USB1_LOOPBACK_SET_UTMI_DIG_TST0 = 1U << 1 ;

  // Boolean field: Mode control for USB loopback test
    static const uint32_t USBPHY_USB1_LOOPBACK_SET_UTMI_DIG_TST1 = 1U << 2 ;

  // Boolean field: Select HS or FS mode for USB loopback testing
    static const uint32_t USBPHY_USB1_LOOPBACK_SET_TSTI_TX_HS_MODE = 1U << 3 ;

  // Boolean field: Set to value 1'b1 to choose LS for USB loopback testing, set to value 1'b0 to choose HS or FS mode which is defined by TSTI1_TX_HS
    static const uint32_t USBPHY_USB1_LOOPBACK_SET_TSTI_TX_LS_MODE = 1U << 4 ;

  // Boolean field: Enable TX for USB loopback test.
    static const uint32_t USBPHY_USB1_LOOPBACK_SET_TSTI_TX_EN = 1U << 5 ;

  // Boolean field: Sets TX Hi-Z for USB loopback test.
    static const uint32_t USBPHY_USB1_LOOPBACK_SET_TSTI_TX_HIZ = 1U << 6 ;

  // Boolean field: This read-only bit is a status bit for USB loopback test results
    static const uint32_t USBPHY_USB1_LOOPBACK_SET_UTMO_DIG_TST0 = 1U << 7 ;

  // Boolean field: This read-only bit is a status bit for USB loopback test
    static const uint32_t USBPHY_USB1_LOOPBACK_SET_UTMO_DIG_TST1 = 1U << 8 ;

  // Boolean field: Setting this bit field to value 1'b1 will enable the loopback test to dynamically change the packet speed
    static const uint32_t USBPHY_USB1_LOOPBACK_SET_TSTI_HSFS_MODE_EN = 1U << 15 ;

  // Field (width: 8 bits): Selects the packet data byte used for USB loopback testing in Pulse mode
    inline uint32_t USBPHY_USB1_LOOPBACK_SET_TSTPKT (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

//-------------------- USB PHY Loopback Control/Status Register
#define USBPHY_USB1_LOOPBACK_CLR (* ((volatile uint32_t *) (0x400A2000 + 0x118)))

  // Boolean field: This bit enables the USB loopback test.
    static const uint32_t USBPHY_USB1_LOOPBACK_CLR_UTMI_TESTSTART = 1U << 0 ;

  // Boolean field: Mode control for USB loopback test
    static const uint32_t USBPHY_USB1_LOOPBACK_CLR_UTMI_DIG_TST0 = 1U << 1 ;

  // Boolean field: Mode control for USB loopback test
    static const uint32_t USBPHY_USB1_LOOPBACK_CLR_UTMI_DIG_TST1 = 1U << 2 ;

  // Boolean field: Select HS or FS mode for USB loopback testing
    static const uint32_t USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_HS_MODE = 1U << 3 ;

  // Boolean field: Set to value 1'b1 to choose LS for USB loopback testing, set to value 1'b0 to choose HS or FS mode which is defined by TSTI1_TX_HS
    static const uint32_t USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_LS_MODE = 1U << 4 ;

  // Boolean field: Enable TX for USB loopback test.
    static const uint32_t USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_EN = 1U << 5 ;

  // Boolean field: Sets TX Hi-Z for USB loopback test.
    static const uint32_t USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_HIZ = 1U << 6 ;

  // Boolean field: This read-only bit is a status bit for USB loopback test results
    static const uint32_t USBPHY_USB1_LOOPBACK_CLR_UTMO_DIG_TST0 = 1U << 7 ;

  // Boolean field: This read-only bit is a status bit for USB loopback test
    static const uint32_t USBPHY_USB1_LOOPBACK_CLR_UTMO_DIG_TST1 = 1U << 8 ;

  // Boolean field: Setting this bit field to value 1'b1 will enable the loopback test to dynamically change the packet speed
    static const uint32_t USBPHY_USB1_LOOPBACK_CLR_TSTI_HSFS_MODE_EN = 1U << 15 ;

  // Field (width: 8 bits): Selects the packet data byte used for USB loopback testing in Pulse mode
    inline uint32_t USBPHY_USB1_LOOPBACK_CLR_TSTPKT (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

//-------------------- USB PHY Loopback Control/Status Register
#define USBPHY_USB1_LOOPBACK_TOG (* ((volatile uint32_t *) (0x400A2000 + 0x11C)))

  // Boolean field: This bit enables the USB loopback test.
    static const uint32_t USBPHY_USB1_LOOPBACK_TOG_UTMI_TESTSTART = 1U << 0 ;

  // Boolean field: Mode control for USB loopback test
    static const uint32_t USBPHY_USB1_LOOPBACK_TOG_UTMI_DIG_TST0 = 1U << 1 ;

  // Boolean field: Mode control for USB loopback test
    static const uint32_t USBPHY_USB1_LOOPBACK_TOG_UTMI_DIG_TST1 = 1U << 2 ;

  // Boolean field: Select HS or FS mode for USB loopback testing
    static const uint32_t USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_HS_MODE = 1U << 3 ;

  // Boolean field: Set to value 1'b1 to choose LS for USB loopback testing, set to value 1'b0 to choose HS or FS mode which is defined by TSTI1_TX_HS
    static const uint32_t USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_LS_MODE = 1U << 4 ;

  // Boolean field: Enable TX for USB loopback test.
    static const uint32_t USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_EN = 1U << 5 ;

  // Boolean field: Sets TX Hi-Z for USB loopback test.
    static const uint32_t USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_HIZ = 1U << 6 ;

  // Boolean field: This read-only bit is a status bit for USB loopback test results
    static const uint32_t USBPHY_USB1_LOOPBACK_TOG_UTMO_DIG_TST0 = 1U << 7 ;

  // Boolean field: This read-only bit is a status bit for USB loopback test
    static const uint32_t USBPHY_USB1_LOOPBACK_TOG_UTMO_DIG_TST1 = 1U << 8 ;

  // Boolean field: Setting this bit field to value 1'b1 will enable the loopback test to dynamically change the packet speed
    static const uint32_t USBPHY_USB1_LOOPBACK_TOG_TSTI_HSFS_MODE_EN = 1U << 15 ;

  // Field (width: 8 bits): Selects the packet data byte used for USB loopback testing in Pulse mode
    inline uint32_t USBPHY_USB1_LOOPBACK_TOG_TSTPKT (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

//-------------------- USB PHY Loopback Packet Number Select Register
#define USBPHY_USB1_LOOPBACK_HSFSCNT (* ((volatile uint32_t *) (0x400A2000 + 0x120)))

  // Field (width: 16 bits): High speed packet number, used when USBPHY_USB1_LOOPBACK[TSTI_HSFS_MODE_EN] is set to value 1'b1.
    inline uint32_t USBPHY_USB1_LOOPBACK_HSFSCNT_TSTI_HS_NUMBER (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Field (width: 16 bits): Full speed packet number, used when USBPHY_USB1_LOOPBACK[TSTI_HSFS_MODE_EN] is set to value 1'b1.
    inline uint32_t USBPHY_USB1_LOOPBACK_HSFSCNT_TSTI_FS_NUMBER (const uint32_t inValue) { return (inValue & 65535U) << 16 ; }

//-------------------- USB PHY Loopback Packet Number Select Register
#define USBPHY_USB1_LOOPBACK_HSFSCNT_SET (* ((volatile uint32_t *) (0x400A2000 + 0x124)))

  // Field (width: 16 bits): High speed packet number, used when USBPHY_USB1_LOOPBACK[TSTI_HSFS_MODE_EN] is set to value 1'b1.
    inline uint32_t USBPHY_USB1_LOOPBACK_HSFSCNT_SET_TSTI_HS_NUMBER (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Field (width: 16 bits): Full speed packet number, used when USBPHY_USB1_LOOPBACK[TSTI_HSFS_MODE_EN] is set to value 1'b1.
    inline uint32_t USBPHY_USB1_LOOPBACK_HSFSCNT_SET_TSTI_FS_NUMBER (const uint32_t inValue) { return (inValue & 65535U) << 16 ; }

//-------------------- USB PHY Loopback Packet Number Select Register
#define USBPHY_USB1_LOOPBACK_HSFSCNT_CLR (* ((volatile uint32_t *) (0x400A2000 + 0x128)))

  // Field (width: 16 bits): High speed packet number, used when USBPHY_USB1_LOOPBACK[TSTI_HSFS_MODE_EN] is set to value 1'b1.
    inline uint32_t USBPHY_USB1_LOOPBACK_HSFSCNT_CLR_TSTI_HS_NUMBER (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Field (width: 16 bits): Full speed packet number, used when USBPHY_USB1_LOOPBACK[TSTI_HSFS_MODE_EN] is set to value 1'b1.
    inline uint32_t USBPHY_USB1_LOOPBACK_HSFSCNT_CLR_TSTI_FS_NUMBER (const uint32_t inValue) { return (inValue & 65535U) << 16 ; }

//-------------------- USB PHY Loopback Packet Number Select Register
#define USBPHY_USB1_LOOPBACK_HSFSCNT_TOG (* ((volatile uint32_t *) (0x400A2000 + 0x12C)))

  // Field (width: 16 bits): High speed packet number, used when USBPHY_USB1_LOOPBACK[TSTI_HSFS_MODE_EN] is set to value 1'b1.
    inline uint32_t USBPHY_USB1_LOOPBACK_HSFSCNT_TOG_TSTI_HS_NUMBER (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Field (width: 16 bits): Full speed packet number, used when USBPHY_USB1_LOOPBACK[TSTI_HSFS_MODE_EN] is set to value 1'b1.
    inline uint32_t USBPHY_USB1_LOOPBACK_HSFSCNT_TOG_TSTI_FS_NUMBER (const uint32_t inValue) { return (inValue & 65535U) << 16 ; }

//-------------------- USB PHY Trim Override Enable Register
#define USBPHY_TRIM_OVERRIDE_EN (* ((volatile uint32_t *) (0x400A2000 + 0x130)))

  // Boolean field: Override enable for PLL_DIV_SEL, when set, the register value in USBPHY_PLL_SIC[1:0] will be used.
    static const uint32_t USBPHY_TRIM_OVERRIDE_EN_TRIM_DIV_SEL_OVERRIDE = 1U << 0 ;

  // Boolean field: Override enable for ENV_TAIL_ADJ, when set, the register value in USBPHY_DEBUG1[14:13] will be used
    static const uint32_t USBPHY_TRIM_OVERRIDE_EN_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE = 1U << 1 ;

  // Boolean field: Override enable for TX_D_CAL, when set, the register value in USBPHY_TX[3:0] will be used.
    static const uint32_t USBPHY_TRIM_OVERRIDE_EN_TRIM_TX_D_CAL_OVERRIDE = 1U << 2 ;

  // Boolean field: Override enable for TX_CAL45DP, when set, the register value in USBPHY_TX[19:16] will be used.
    static const uint32_t USBPHY_TRIM_OVERRIDE_EN_TRIM_TX_CAL45DP_OVERRIDE = 1U << 3 ;

  // Boolean field: Override enable for TX_CAL45DM, when set, the register value in USBPHY_TX[11:8] will be used.
    static const uint32_t USBPHY_TRIM_OVERRIDE_EN_TRIM_TX_CAL45DM_OVERRIDE = 1U << 4 ;

  // Field (width: 2 bits): IFR value of PLL_DIV_SEL.
    inline uint32_t USBPHY_TRIM_OVERRIDE_EN_TRIM_PLL_CTRL0_DIV_SEL (const uint32_t inValue) { return (inValue & 3U) << 16 ; }

  // Field (width: 2 bits): IFR value of ENV_TAIL_ADJ.
    inline uint32_t USBPHY_TRIM_OVERRIDE_EN_TRIM_USB_REG_ENV_TAIL_ADJ_VD (const uint32_t inValue) { return (inValue & 3U) << 18 ; }

  // Field (width: 4 bits): IFR value of TX_D_CAL.
    inline uint32_t USBPHY_TRIM_OVERRIDE_EN_TRIM_USBPHY_TX_D_CAL (const uint32_t inValue) { return (inValue & 15U) << 20 ; }

  // Field (width: 4 bits): IFR value of TX_CAL45DP.
    inline uint32_t USBPHY_TRIM_OVERRIDE_EN_TRIM_USBPHY_TX_CAL45DP (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Field (width: 4 bits): IFR value of TX_CAL45DM.
    inline uint32_t USBPHY_TRIM_OVERRIDE_EN_TRIM_USBPHY_TX_CAL45DM (const uint32_t inValue) { return (inValue & 15U) << 28 ; }

//-------------------- USB PHY Trim Override Enable Register
#define USBPHY_TRIM_OVERRIDE_EN_SET (* ((volatile uint32_t *) (0x400A2000 + 0x134)))

  // Boolean field: Override enable for PLL_DIV_SEL, when set, the register value in USBPHY_PLL_SIC[1:0] will be used.
    static const uint32_t USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_DIV_SEL_OVERRIDE = 1U << 0 ;

  // Boolean field: Override enable for ENV_TAIL_ADJ, when set, the register value in USBPHY_DEBUG1[14:13] will be used
    static const uint32_t USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE = 1U << 1 ;

  // Boolean field: Override enable for TX_D_CAL, when set, the register value in USBPHY_TX[3:0] will be used.
    static const uint32_t USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_TX_D_CAL_OVERRIDE = 1U << 2 ;

  // Boolean field: Override enable for TX_CAL45DP, when set, the register value in USBPHY_TX[19:16] will be used.
    static const uint32_t USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_TX_CAL45DP_OVERRIDE = 1U << 3 ;

  // Boolean field: Override enable for TX_CAL45DM, when set, the register value in USBPHY_TX[11:8] will be used.
    static const uint32_t USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_TX_CAL45DM_OVERRIDE = 1U << 4 ;

  // Field (width: 2 bits): IFR value of PLL_DIV_SEL.
    inline uint32_t USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_PLL_CTRL0_DIV_SEL (const uint32_t inValue) { return (inValue & 3U) << 16 ; }

  // Field (width: 2 bits): IFR value of ENV_TAIL_ADJ.
    inline uint32_t USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USB_REG_ENV_TAIL_ADJ_VD (const uint32_t inValue) { return (inValue & 3U) << 18 ; }

  // Field (width: 4 bits): IFR value of TX_D_CAL.
    inline uint32_t USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USBPHY_TX_D_CAL (const uint32_t inValue) { return (inValue & 15U) << 20 ; }

  // Field (width: 4 bits): IFR value of TX_CAL45DP.
    inline uint32_t USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USBPHY_TX_CAL45DP (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Field (width: 4 bits): IFR value of TX_CAL45DM.
    inline uint32_t USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USBPHY_TX_CAL45DM (const uint32_t inValue) { return (inValue & 15U) << 28 ; }

//-------------------- USB PHY Trim Override Enable Register
#define USBPHY_TRIM_OVERRIDE_EN_CLR (* ((volatile uint32_t *) (0x400A2000 + 0x138)))

  // Boolean field: Override enable for PLL_DIV_SEL, when set, the register value in USBPHY_PLL_SIC[1:0] will be used.
    static const uint32_t USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_DIV_SEL_OVERRIDE = 1U << 0 ;

  // Boolean field: Override enable for ENV_TAIL_ADJ, when set, the register value in USBPHY_DEBUG1[14:13] will be used
    static const uint32_t USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE = 1U << 1 ;

  // Boolean field: Override enable for TX_D_CAL, when set, the register value in USBPHY_TX[3:0] will be used.
    static const uint32_t USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_TX_D_CAL_OVERRIDE = 1U << 2 ;

  // Boolean field: Override enable for TX_CAL45DP, when set, the register value in USBPHY_TX[19:16] will be used.
    static const uint32_t USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_TX_CAL45DP_OVERRIDE = 1U << 3 ;

  // Boolean field: Override enable for TX_CAL45DM, when set, the register value in USBPHY_TX[11:8] will be used.
    static const uint32_t USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_TX_CAL45DM_OVERRIDE = 1U << 4 ;

  // Field (width: 2 bits): IFR value of PLL_DIV_SEL.
    inline uint32_t USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_PLL_CTRL0_DIV_SEL (const uint32_t inValue) { return (inValue & 3U) << 16 ; }

  // Field (width: 2 bits): IFR value of ENV_TAIL_ADJ.
    inline uint32_t USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USB_REG_ENV_TAIL_ADJ_VD (const uint32_t inValue) { return (inValue & 3U) << 18 ; }

  // Field (width: 4 bits): IFR value of TX_D_CAL.
    inline uint32_t USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USBPHY_TX_D_CAL (const uint32_t inValue) { return (inValue & 15U) << 20 ; }

  // Field (width: 4 bits): IFR value of TX_CAL45DP.
    inline uint32_t USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USBPHY_TX_CAL45DP (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Field (width: 4 bits): IFR value of TX_CAL45DM.
    inline uint32_t USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USBPHY_TX_CAL45DM (const uint32_t inValue) { return (inValue & 15U) << 28 ; }

//-------------------- USB PHY Trim Override Enable Register
#define USBPHY_TRIM_OVERRIDE_EN_TOG (* ((volatile uint32_t *) (0x400A2000 + 0x13C)))

  // Boolean field: Override enable for PLL_DIV_SEL, when set, the register value in USBPHY_PLL_SIC[1:0] will be used.
    static const uint32_t USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_DIV_SEL_OVERRIDE = 1U << 0 ;

  // Boolean field: Override enable for ENV_TAIL_ADJ, when set, the register value in USBPHY_DEBUG1[14:13] will be used
    static const uint32_t USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE = 1U << 1 ;

  // Boolean field: Override enable for TX_D_CAL, when set, the register value in USBPHY_TX[3:0] will be used.
    static const uint32_t USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_TX_D_CAL_OVERRIDE = 1U << 2 ;

  // Boolean field: Override enable for TX_CAL45DP, when set, the register value in USBPHY_TX[19:16] will be used.
    static const uint32_t USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_TX_CAL45DP_OVERRIDE = 1U << 3 ;

  // Boolean field: Override enable for TX_CAL45DM, when set, the register value in USBPHY_TX[11:8] will be used.
    static const uint32_t USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_TX_CAL45DM_OVERRIDE = 1U << 4 ;

  // Field (width: 2 bits): IFR value of PLL_DIV_SEL.
    inline uint32_t USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_PLL_CTRL0_DIV_SEL (const uint32_t inValue) { return (inValue & 3U) << 16 ; }

  // Field (width: 2 bits): IFR value of ENV_TAIL_ADJ.
    inline uint32_t USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USB_REG_ENV_TAIL_ADJ_VD (const uint32_t inValue) { return (inValue & 3U) << 18 ; }

  // Field (width: 4 bits): IFR value of TX_D_CAL.
    inline uint32_t USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USBPHY_TX_D_CAL (const uint32_t inValue) { return (inValue & 15U) << 20 ; }

  // Field (width: 4 bits): IFR value of TX_CAL45DP.
    inline uint32_t USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USBPHY_TX_CAL45DP (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Field (width: 4 bits): IFR value of TX_CAL45DM.
    inline uint32_t USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USBPHY_TX_CAL45DM (const uint32_t inValue) { return (inValue & 15U) << 28 ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral USBHSDCD
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Control register
#define USBHSDCD_CONTROL (* ((volatile uint32_t *) (0x400A3000 + 0)))

  // Boolean field: Interrupt Acknowledge
    static const uint32_t USBHSDCD_CONTROL_IACK = 1U << 0 ;

  // Boolean field: Interrupt Flag
    static const uint32_t USBHSDCD_CONTROL_IF = 1U << 8 ;

  // Boolean field: Interrupt Enable
    static const uint32_t USBHSDCD_CONTROL_IE = 1U << 16 ;

  // Boolean field: BC1.2 compatibility. This bit cannot be changed after start detection.
    static const uint32_t USBHSDCD_CONTROL_BC12 = 1U << 17 ;

  // Boolean field: Start Change Detection Sequence
    static const uint32_t USBHSDCD_CONTROL_START = 1U << 24 ;

  // Boolean field: Software Reset
    static const uint32_t USBHSDCD_CONTROL_SR = 1U << 25 ;

//-------------------- Clock register
#define USBHSDCD_CLOCK (* ((volatile uint32_t *) (0x400A3000 + 0x4)))

  // Boolean field: Unit of Measurement Encoding for Clock Speed
    static const uint32_t USBHSDCD_CLOCK_CLOCK_UNIT = 1U << 0 ;

  // Field (width: 10 bits): Numerical Value of Clock Speed in Binary
    inline uint32_t USBHSDCD_CLOCK_CLOCK_SPEED (const uint32_t inValue) { return (inValue & 1023U) << 2 ; }

//-------------------- Status register
#define USBHSDCD_STATUS (* ((const volatile uint32_t *) (0x400A3000 + 0x8)))

  // Field (width: 2 bits): Charger Detection Sequence Results
    inline uint32_t USBHSDCD_STATUS_SEQ_RES (const uint32_t inValue) { return (inValue & 3U) << 16 ; }

  // Field (width: 2 bits): Charger Detection Sequence Status
    inline uint32_t USBHSDCD_STATUS_SEQ_STAT (const uint32_t inValue) { return (inValue & 3U) << 18 ; }

  // Boolean field: Error Flag
    static const uint32_t USBHSDCD_STATUS_ERR = 1U << 20 ;

  // Boolean field: Timeout Flag
    static const uint32_t USBHSDCD_STATUS_TO = 1U << 21 ;

  // Boolean field: Active Status Indicator
    static const uint32_t USBHSDCD_STATUS_ACTIVE = 1U << 22 ;

//-------------------- Signal Override Register
#define USBHSDCD_SIGNAL_OVERRIDE (* ((volatile uint32_t *) (0x400A3000 + 0xC)))

  // Field (width: 2 bits): Phase Selection
    inline uint32_t USBHSDCD_SIGNAL_OVERRIDE_PS (const uint32_t inValue) { return (inValue & 3U) << 0 ; }

//-------------------- TIMER0 register
#define USBHSDCD_TIMER0 (* ((volatile uint32_t *) (0x400A3000 + 0x10)))

  // Field (width: 12 bits): Unit Connection Timer Elapse (in ms)
    inline uint32_t USBHSDCD_TIMER0_TUNITCON (const uint32_t inValue) { return (inValue & 4095U) << 0 ; }

  // Field (width: 10 bits): Sequence Initiation Time
    inline uint32_t USBHSDCD_TIMER0_TSEQ_INIT (const uint32_t inValue) { return (inValue & 1023U) << 16 ; }

//-------------------- TIMER1 register
#define USBHSDCD_TIMER1 (* ((volatile uint32_t *) (0x400A3000 + 0x14)))

  // Field (width: 10 bits): Time Period Comparator Enabled
    inline uint32_t USBHSDCD_TIMER1_TVDPSRC_ON (const uint32_t inValue) { return (inValue & 1023U) << 0 ; }

  // Field (width: 10 bits): Time Period to Debounce D+ Signal
    inline uint32_t USBHSDCD_TIMER1_TDCD_DBNC (const uint32_t inValue) { return (inValue & 1023U) << 16 ; }

//-------------------- TIMER2_BC11 register
#define USBHSDCD_TIMER2_BC11 (* ((volatile uint32_t *) (0x400A3000 + 0x18)))

  // Field (width: 4 bits): Time Before Check of D- Line
    inline uint32_t USBHSDCD_TIMER2_BC11_CHECK_DM (const uint32_t inValue) { return (inValue & 15U) << 0 ; }

  // Field (width: 10 bits): Time Period Before Enabling D+ Pullup
    inline uint32_t USBHSDCD_TIMER2_BC11_TVDPSRC_CON (const uint32_t inValue) { return (inValue & 1023U) << 16 ; }

//-------------------- TIMER2_BC12 register
#define USBHSDCD_TIMER2_BC12 (* ((volatile uint32_t *) (0x400A3000 + 0x18)))

  // Field (width: 10 bits): Sets the amount of time (in ms) that the module enables the VDM_SRC. Valid values are 0-40ms.
    inline uint32_t USBHSDCD_TIMER2_BC12_TVDMSRC_ON (const uint32_t inValue) { return (inValue & 1023U) << 0 ; }

  // Field (width: 10 bits): Sets the amount of time (in ms) that the module waits after primary detection before start to secondary detection
    inline uint32_t USBHSDCD_TIMER2_BC12_TWAIT_AFTER_PRD (const uint32_t inValue) { return (inValue & 1023U) << 16 ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral SDHC
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- DMA System Address register
#define SDHC_DSADDR (* ((volatile uint32_t *) (0x400B1000 + 0)))

  // Field (width: 30 bits): DMA System Address
    inline uint32_t SDHC_DSADDR_DSADDR (const uint32_t inValue) { return (inValue & 1073741823U) << 2 ; }

//-------------------- Block Attributes register
#define SDHC_BLKATTR (* ((volatile uint32_t *) (0x400B1000 + 0x4)))

  // Field (width: 13 bits): Transfer Block Size
    inline uint32_t SDHC_BLKATTR_BLKSIZE (const uint32_t inValue) { return (inValue & 8191U) << 0 ; }

  // Field (width: 16 bits): Blocks Count For Current Transfer
    inline uint32_t SDHC_BLKATTR_BLKCNT (const uint32_t inValue) { return (inValue & 65535U) << 16 ; }

//-------------------- Command Argument register
#define SDHC_CMDARG (* ((volatile uint32_t *) (0x400B1000 + 0x8)))

//-------------------- Transfer Type register
#define SDHC_XFERTYP (* ((volatile uint32_t *) (0x400B1000 + 0xC)))

  // Boolean field: DMA Enable
    static const uint32_t SDHC_XFERTYP_DMAEN = 1U << 0 ;

  // Boolean field: Block Count Enable
    static const uint32_t SDHC_XFERTYP_BCEN = 1U << 1 ;

  // Boolean field: Auto CMD12 Enable
    static const uint32_t SDHC_XFERTYP_AC12EN = 1U << 2 ;

  // Boolean field: Data Transfer Direction Select
    static const uint32_t SDHC_XFERTYP_DTDSEL = 1U << 4 ;

  // Boolean field: Multi/Single Block Select
    static const uint32_t SDHC_XFERTYP_MSBSEL = 1U << 5 ;

  // Field (width: 2 bits): Response Type Select
    inline uint32_t SDHC_XFERTYP_RSPTYP (const uint32_t inValue) { return (inValue & 3U) << 16 ; }

  // Boolean field: Command CRC Check Enable
    static const uint32_t SDHC_XFERTYP_CCCEN = 1U << 19 ;

  // Boolean field: Command Index Check Enable
    static const uint32_t SDHC_XFERTYP_CICEN = 1U << 20 ;

  // Boolean field: Data Present Select
    static const uint32_t SDHC_XFERTYP_DPSEL = 1U << 21 ;

  // Field (width: 2 bits): Command Type
    inline uint32_t SDHC_XFERTYP_CMDTYP (const uint32_t inValue) { return (inValue & 3U) << 22 ; }

  // Field (width: 6 bits): Command Index
    inline uint32_t SDHC_XFERTYP_CMDINX (const uint32_t inValue) { return (inValue & 63U) << 24 ; }

//-------------------- Command Response 0
#define SDHC_CMDRSP0 (* ((const volatile uint32_t *) (0x400B1000 + 0x10)))

//-------------------- Command Response 1
#define SDHC_CMDRSP1 (* ((const volatile uint32_t *) (0x400B1000 + 0x14)))

//-------------------- Command Response 2
#define SDHC_CMDRSP2 (* ((const volatile uint32_t *) (0x400B1000 + 0x18)))

//-------------------- Command Response 3
#define SDHC_CMDRSP3 (* ((const volatile uint32_t *) (0x400B1000 + 0x1C)))

//-------------------- Buffer Data Port register
#define SDHC_DATPORT (* ((volatile uint32_t *) (0x400B1000 + 0x20)))

//-------------------- Present State register
#define SDHC_PRSSTAT (* ((const volatile uint32_t *) (0x400B1000 + 0x24)))

  // Boolean field: Command Inhibit (CMD)
    static const uint32_t SDHC_PRSSTAT_CIHB = 1U << 0 ;

  // Boolean field: Command Inhibit (DAT)
    static const uint32_t SDHC_PRSSTAT_CDIHB = 1U << 1 ;

  // Boolean field: Data Line Active
    static const uint32_t SDHC_PRSSTAT_DLA = 1U << 2 ;

  // Boolean field: SD Clock Stable
    static const uint32_t SDHC_PRSSTAT_SDSTB = 1U << 3 ;

  // Boolean field: Bus Clock Gated Off Internally
    static const uint32_t SDHC_PRSSTAT_IPGOFF = 1U << 4 ;

  // Boolean field: System Clock Gated Off Internally
    static const uint32_t SDHC_PRSSTAT_HCKOFF = 1U << 5 ;

  // Boolean field: SDHC clock Gated Off Internally
    static const uint32_t SDHC_PRSSTAT_PEROFF = 1U << 6 ;

  // Boolean field: SD Clock Gated Off Internally
    static const uint32_t SDHC_PRSSTAT_SDOFF = 1U << 7 ;

  // Boolean field: Write Transfer Active
    static const uint32_t SDHC_PRSSTAT_WTA = 1U << 8 ;

  // Boolean field: Read Transfer Active
    static const uint32_t SDHC_PRSSTAT_RTA = 1U << 9 ;

  // Boolean field: Buffer Write Enable
    static const uint32_t SDHC_PRSSTAT_BWEN = 1U << 10 ;

  // Boolean field: Buffer Read Enable
    static const uint32_t SDHC_PRSSTAT_BREN = 1U << 11 ;

  // Boolean field: Card Inserted
    static const uint32_t SDHC_PRSSTAT_CINS = 1U << 16 ;

  // Boolean field: CMD Line Signal Level
    static const uint32_t SDHC_PRSSTAT_CLSL = 1U << 23 ;

  // Field (width: 8 bits): DAT Line Signal Level
    inline uint32_t SDHC_PRSSTAT_DLSL (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Protocol Control register
#define SDHC_PROCTL (* ((volatile uint32_t *) (0x400B1000 + 0x28)))

  // Boolean field: LED Control
    static const uint32_t SDHC_PROCTL_LCTL = 1U << 0 ;

  // Field (width: 2 bits): Data Transfer Width
    inline uint32_t SDHC_PROCTL_DTW (const uint32_t inValue) { return (inValue & 3U) << 1 ; }

  // Boolean field: DAT3 As Card Detection Pin
    static const uint32_t SDHC_PROCTL_D3CD = 1U << 3 ;

  // Field (width: 2 bits): Endian Mode
    inline uint32_t SDHC_PROCTL_EMODE (const uint32_t inValue) { return (inValue & 3U) << 4 ; }

  // Boolean field: Card Detect Test Level
    static const uint32_t SDHC_PROCTL_CDTL = 1U << 6 ;

  // Boolean field: Card Detect Signal Selection
    static const uint32_t SDHC_PROCTL_CDSS = 1U << 7 ;

  // Field (width: 2 bits): DMA Select
    inline uint32_t SDHC_PROCTL_DMAS (const uint32_t inValue) { return (inValue & 3U) << 8 ; }

  // Boolean field: Stop At Block Gap Request
    static const uint32_t SDHC_PROCTL_SABGREQ = 1U << 16 ;

  // Boolean field: Continue Request
    static const uint32_t SDHC_PROCTL_CREQ = 1U << 17 ;

  // Boolean field: Read Wait Control
    static const uint32_t SDHC_PROCTL_RWCTL = 1U << 18 ;

  // Boolean field: Interrupt At Block Gap
    static const uint32_t SDHC_PROCTL_IABG = 1U << 19 ;

  // Boolean field: Wakeup Event Enable On Card Interrupt
    static const uint32_t SDHC_PROCTL_WECINT = 1U << 24 ;

  // Boolean field: Wakeup Event Enable On SD Card Insertion
    static const uint32_t SDHC_PROCTL_WECINS = 1U << 25 ;

  // Boolean field: Wakeup Event Enable On SD Card Removal
    static const uint32_t SDHC_PROCTL_WECRM = 1U << 26 ;

//-------------------- System Control register
#define SDHC_SYSCTL (* ((volatile uint32_t *) (0x400B1000 + 0x2C)))

  // Boolean field: IPG Clock Enable
    static const uint32_t SDHC_SYSCTL_IPGEN = 1U << 0 ;

  // Boolean field: System Clock Enable
    static const uint32_t SDHC_SYSCTL_HCKEN = 1U << 1 ;

  // Boolean field: Peripheral Clock Enable
    static const uint32_t SDHC_SYSCTL_PEREN = 1U << 2 ;

  // Boolean field: SD Clock Enable
    static const uint32_t SDHC_SYSCTL_SDCLKEN = 1U << 3 ;

  // Field (width: 4 bits): Divisor
    inline uint32_t SDHC_SYSCTL_DVS (const uint32_t inValue) { return (inValue & 15U) << 4 ; }

  // Field (width: 8 bits): SDCLK Frequency Select
    inline uint32_t SDHC_SYSCTL_SDCLKFS (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 4 bits): Data Timeout Counter Value
    inline uint32_t SDHC_SYSCTL_DTOCV (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Boolean field: Software Reset For ALL
    static const uint32_t SDHC_SYSCTL_RSTA = 1U << 24 ;

  // Boolean field: Software Reset For CMD Line
    static const uint32_t SDHC_SYSCTL_RSTC = 1U << 25 ;

  // Boolean field: Software Reset For DAT Line
    static const uint32_t SDHC_SYSCTL_RSTD = 1U << 26 ;

  // Boolean field: Initialization Active
    static const uint32_t SDHC_SYSCTL_INITA = 1U << 27 ;

//-------------------- Interrupt Status register
#define SDHC_IRQSTAT (* ((volatile uint32_t *) (0x400B1000 + 0x30)))

  // Boolean field: Command Complete
    static const uint32_t SDHC_IRQSTAT_CC = 1U << 0 ;

  // Boolean field: Transfer Complete
    static const uint32_t SDHC_IRQSTAT_TC = 1U << 1 ;

  // Boolean field: Block Gap Event
    static const uint32_t SDHC_IRQSTAT_BGE = 1U << 2 ;

  // Boolean field: DMA Interrupt
    static const uint32_t SDHC_IRQSTAT_DINT = 1U << 3 ;

  // Boolean field: Buffer Write Ready
    static const uint32_t SDHC_IRQSTAT_BWR = 1U << 4 ;

  // Boolean field: Buffer Read Ready
    static const uint32_t SDHC_IRQSTAT_BRR = 1U << 5 ;

  // Boolean field: Card Insertion
    static const uint32_t SDHC_IRQSTAT_CINS = 1U << 6 ;

  // Boolean field: Card Removal
    static const uint32_t SDHC_IRQSTAT_CRM = 1U << 7 ;

  // Boolean field: Card Interrupt
    static const uint32_t SDHC_IRQSTAT_CINT = 1U << 8 ;

  // Boolean field: Command Timeout Error
    static const uint32_t SDHC_IRQSTAT_CTOE = 1U << 16 ;

  // Boolean field: Command CRC Error
    static const uint32_t SDHC_IRQSTAT_CCE = 1U << 17 ;

  // Boolean field: Command End Bit Error
    static const uint32_t SDHC_IRQSTAT_CEBE = 1U << 18 ;

  // Boolean field: Command Index Error
    static const uint32_t SDHC_IRQSTAT_CIE = 1U << 19 ;

  // Boolean field: Data Timeout Error
    static const uint32_t SDHC_IRQSTAT_DTOE = 1U << 20 ;

  // Boolean field: Data CRC Error
    static const uint32_t SDHC_IRQSTAT_DCE = 1U << 21 ;

  // Boolean field: Data End Bit Error
    static const uint32_t SDHC_IRQSTAT_DEBE = 1U << 22 ;

  // Boolean field: Auto CMD12 Error
    static const uint32_t SDHC_IRQSTAT_AC12E = 1U << 24 ;

  // Boolean field: DMA Error
    static const uint32_t SDHC_IRQSTAT_DMAE = 1U << 28 ;

//-------------------- Interrupt Status Enable register
#define SDHC_IRQSTATEN (* ((volatile uint32_t *) (0x400B1000 + 0x34)))

  // Boolean field: Command Complete Status Enable
    static const uint32_t SDHC_IRQSTATEN_CCSEN = 1U << 0 ;

  // Boolean field: Transfer Complete Status Enable
    static const uint32_t SDHC_IRQSTATEN_TCSEN = 1U << 1 ;

  // Boolean field: Block Gap Event Status Enable
    static const uint32_t SDHC_IRQSTATEN_BGESEN = 1U << 2 ;

  // Boolean field: DMA Interrupt Status Enable
    static const uint32_t SDHC_IRQSTATEN_DINTSEN = 1U << 3 ;

  // Boolean field: Buffer Write Ready Status Enable
    static const uint32_t SDHC_IRQSTATEN_BWRSEN = 1U << 4 ;

  // Boolean field: Buffer Read Ready Status Enable
    static const uint32_t SDHC_IRQSTATEN_BRRSEN = 1U << 5 ;

  // Boolean field: Card Insertion Status Enable
    static const uint32_t SDHC_IRQSTATEN_CINSEN = 1U << 6 ;

  // Boolean field: Card Removal Status Enable
    static const uint32_t SDHC_IRQSTATEN_CRMSEN = 1U << 7 ;

  // Boolean field: Card Interrupt Status Enable
    static const uint32_t SDHC_IRQSTATEN_CINTSEN = 1U << 8 ;

  // Boolean field: Command Timeout Error Status Enable
    static const uint32_t SDHC_IRQSTATEN_CTOESEN = 1U << 16 ;

  // Boolean field: Command CRC Error Status Enable
    static const uint32_t SDHC_IRQSTATEN_CCESEN = 1U << 17 ;

  // Boolean field: Command End Bit Error Status Enable
    static const uint32_t SDHC_IRQSTATEN_CEBESEN = 1U << 18 ;

  // Boolean field: Command Index Error Status Enable
    static const uint32_t SDHC_IRQSTATEN_CIESEN = 1U << 19 ;

  // Boolean field: Data Timeout Error Status Enable
    static const uint32_t SDHC_IRQSTATEN_DTOESEN = 1U << 20 ;

  // Boolean field: Data CRC Error Status Enable
    static const uint32_t SDHC_IRQSTATEN_DCESEN = 1U << 21 ;

  // Boolean field: Data End Bit Error Status Enable
    static const uint32_t SDHC_IRQSTATEN_DEBESEN = 1U << 22 ;

  // Boolean field: Auto CMD12 Error Status Enable
    static const uint32_t SDHC_IRQSTATEN_AC12ESEN = 1U << 24 ;

  // Boolean field: DMA Error Status Enable
    static const uint32_t SDHC_IRQSTATEN_DMAESEN = 1U << 28 ;

//-------------------- Interrupt Signal Enable register
#define SDHC_IRQSIGEN (* ((volatile uint32_t *) (0x400B1000 + 0x38)))

  // Boolean field: Command Complete Interrupt Enable
    static const uint32_t SDHC_IRQSIGEN_CCIEN = 1U << 0 ;

  // Boolean field: Transfer Complete Interrupt Enable
    static const uint32_t SDHC_IRQSIGEN_TCIEN = 1U << 1 ;

  // Boolean field: Block Gap Event Interrupt Enable
    static const uint32_t SDHC_IRQSIGEN_BGEIEN = 1U << 2 ;

  // Boolean field: DMA Interrupt Enable
    static const uint32_t SDHC_IRQSIGEN_DINTIEN = 1U << 3 ;

  // Boolean field: Buffer Write Ready Interrupt Enable
    static const uint32_t SDHC_IRQSIGEN_BWRIEN = 1U << 4 ;

  // Boolean field: Buffer Read Ready Interrupt Enable
    static const uint32_t SDHC_IRQSIGEN_BRRIEN = 1U << 5 ;

  // Boolean field: Card Insertion Interrupt Enable
    static const uint32_t SDHC_IRQSIGEN_CINSIEN = 1U << 6 ;

  // Boolean field: Card Removal Interrupt Enable
    static const uint32_t SDHC_IRQSIGEN_CRMIEN = 1U << 7 ;

  // Boolean field: Card Interrupt Enable
    static const uint32_t SDHC_IRQSIGEN_CINTIEN = 1U << 8 ;

  // Boolean field: Command Timeout Error Interrupt Enable
    static const uint32_t SDHC_IRQSIGEN_CTOEIEN = 1U << 16 ;

  // Boolean field: Command CRC Error Interrupt Enable
    static const uint32_t SDHC_IRQSIGEN_CCEIEN = 1U << 17 ;

  // Boolean field: Command End Bit Error Interrupt Enable
    static const uint32_t SDHC_IRQSIGEN_CEBEIEN = 1U << 18 ;

  // Boolean field: Command Index Error Interrupt Enable
    static const uint32_t SDHC_IRQSIGEN_CIEIEN = 1U << 19 ;

  // Boolean field: Data Timeout Error Interrupt Enable
    static const uint32_t SDHC_IRQSIGEN_DTOEIEN = 1U << 20 ;

  // Boolean field: Data CRC Error Interrupt Enable
    static const uint32_t SDHC_IRQSIGEN_DCEIEN = 1U << 21 ;

  // Boolean field: Data End Bit Error Interrupt Enable
    static const uint32_t SDHC_IRQSIGEN_DEBEIEN = 1U << 22 ;

  // Boolean field: Auto CMD12 Error Interrupt Enable
    static const uint32_t SDHC_IRQSIGEN_AC12EIEN = 1U << 24 ;

  // Boolean field: DMA Error Interrupt Enable
    static const uint32_t SDHC_IRQSIGEN_DMAEIEN = 1U << 28 ;

//-------------------- Auto CMD12 Error Status Register
#define SDHC_AC12ERR (* ((const volatile uint32_t *) (0x400B1000 + 0x3C)))

  // Boolean field: Auto CMD12 Not Executed
    static const uint32_t SDHC_AC12ERR_AC12NE = 1U << 0 ;

  // Boolean field: Auto CMD12 Timeout Error
    static const uint32_t SDHC_AC12ERR_AC12TOE = 1U << 1 ;

  // Boolean field: Auto CMD12 End Bit Error
    static const uint32_t SDHC_AC12ERR_AC12EBE = 1U << 2 ;

  // Boolean field: Auto CMD12 CRC Error
    static const uint32_t SDHC_AC12ERR_AC12CE = 1U << 3 ;

  // Boolean field: Auto CMD12 Index Error
    static const uint32_t SDHC_AC12ERR_AC12IE = 1U << 4 ;

  // Boolean field: Command Not Issued By Auto CMD12 Error
    static const uint32_t SDHC_AC12ERR_CNIBAC12E = 1U << 7 ;

//-------------------- Host Controller Capabilities
#define SDHC_HTCAPBLT (* ((const volatile uint32_t *) (0x400B1000 + 0x40)))

  // Field (width: 3 bits): Max Block Length
    inline uint32_t SDHC_HTCAPBLT_MBL (const uint32_t inValue) { return (inValue & 7U) << 16 ; }

  // Boolean field: ADMA Support
    static const uint32_t SDHC_HTCAPBLT_ADMAS = 1U << 20 ;

  // Boolean field: High Speed Support
    static const uint32_t SDHC_HTCAPBLT_HSS = 1U << 21 ;

  // Boolean field: DMA Support
    static const uint32_t SDHC_HTCAPBLT_DMAS = 1U << 22 ;

  // Boolean field: Suspend/Resume Support
    static const uint32_t SDHC_HTCAPBLT_SRS = 1U << 23 ;

  // Boolean field: Voltage Support 3.3 V
    static const uint32_t SDHC_HTCAPBLT_VS33 = 1U << 24 ;

//-------------------- Watermark Level Register
#define SDHC_WML (* ((volatile uint32_t *) (0x400B1000 + 0x44)))

  // Field (width: 8 bits): Read Watermark Level
    inline uint32_t SDHC_WML_RDWML (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Write Watermark Level
    inline uint32_t SDHC_WML_WRWML (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

//-------------------- Force Event register
#define SDHC_FEVT (* ((volatile uint32_t *) (0x400B1000 + 0x50)))

  // Boolean field: Force Event Auto Command 12 Not Executed
    static const uint32_t SDHC_FEVT_AC12NE = 1U << 0 ;

  // Boolean field: Force Event Auto Command 12 Time Out Error
    static const uint32_t SDHC_FEVT_AC12TOE = 1U << 1 ;

  // Boolean field: Force Event Auto Command 12 CRC Error
    static const uint32_t SDHC_FEVT_AC12CE = 1U << 2 ;

  // Boolean field: Force Event Auto Command 12 End Bit Error
    static const uint32_t SDHC_FEVT_AC12EBE = 1U << 3 ;

  // Boolean field: Force Event Auto Command 12 Index Error
    static const uint32_t SDHC_FEVT_AC12IE = 1U << 4 ;

  // Boolean field: Force Event Command Not Executed By Auto Command 12 Error
    static const uint32_t SDHC_FEVT_CNIBAC12E = 1U << 7 ;

  // Boolean field: Force Event Command Time Out Error
    static const uint32_t SDHC_FEVT_CTOE = 1U << 16 ;

  // Boolean field: Force Event Command CRC Error
    static const uint32_t SDHC_FEVT_CCE = 1U << 17 ;

  // Boolean field: Force Event Command End Bit Error
    static const uint32_t SDHC_FEVT_CEBE = 1U << 18 ;

  // Boolean field: Force Event Command Index Error
    static const uint32_t SDHC_FEVT_CIE = 1U << 19 ;

  // Boolean field: Force Event Data Time Out Error
    static const uint32_t SDHC_FEVT_DTOE = 1U << 20 ;

  // Boolean field: Force Event Data CRC Error
    static const uint32_t SDHC_FEVT_DCE = 1U << 21 ;

  // Boolean field: Force Event Data End Bit Error
    static const uint32_t SDHC_FEVT_DEBE = 1U << 22 ;

  // Boolean field: Force Event Auto Command 12 Error
    static const uint32_t SDHC_FEVT_AC12E = 1U << 24 ;

  // Boolean field: Force Event DMA Error
    static const uint32_t SDHC_FEVT_DMAE = 1U << 28 ;

  // Boolean field: Force Event Card Interrupt
    static const uint32_t SDHC_FEVT_CINT = 1U << 31 ;

//-------------------- ADMA Error Status register
#define SDHC_ADMAES (* ((const volatile uint32_t *) (0x400B1000 + 0x54)))

  // Field (width: 2 bits): ADMA Error State (When ADMA Error Is Occurred.)
    inline uint32_t SDHC_ADMAES_ADMAES (const uint32_t inValue) { return (inValue & 3U) << 0 ; }

  // Boolean field: ADMA Length Mismatch Error
    static const uint32_t SDHC_ADMAES_ADMALME = 1U << 2 ;

  // Boolean field: ADMA Descriptor Error
    static const uint32_t SDHC_ADMAES_ADMADCE = 1U << 3 ;

//-------------------- ADMA System Addressregister
#define SDHC_ADSADDR (* ((volatile uint32_t *) (0x400B1000 + 0x58)))

  // Field (width: 30 bits): ADMA System Address
    inline uint32_t SDHC_ADSADDR_ADSADDR (const uint32_t inValue) { return (inValue & 1073741823U) << 2 ; }

//-------------------- Vendor Specific register
#define SDHC_VENDOR (* ((volatile uint32_t *) (0x400B1000 + 0xC0)))

  // Boolean field: Exact Block Number Block Read Enable For SDIO CMD53
    static const uint32_t SDHC_VENDOR_EXBLKNU = 1U << 1 ;

  // Field (width: 8 bits): Internal State Value
    inline uint32_t SDHC_VENDOR_INTSTVAL (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

//-------------------- MMC Boot register
#define SDHC_MMCBOOT (* ((volatile uint32_t *) (0x400B1000 + 0xC4)))

  // Field (width: 4 bits): Boot ACK Time Out Counter Value
    inline uint32_t SDHC_MMCBOOT_DTOCVACK (const uint32_t inValue) { return (inValue & 15U) << 0 ; }

  // Boolean field: Boot Ack Mode Select
    static const uint32_t SDHC_MMCBOOT_BOOTACK = 1U << 4 ;

  // Boolean field: Boot Mode Select
    static const uint32_t SDHC_MMCBOOT_BOOTMODE = 1U << 5 ;

  // Boolean field: Boot Mode Enable
    static const uint32_t SDHC_MMCBOOT_BOOTEN = 1U << 6 ;

  // Boolean field: When boot, enable auto stop at block gap function
    static const uint32_t SDHC_MMCBOOT_AUTOSABGEN = 1U << 7 ;

  // Field (width: 16 bits): Defines the stop at block gap value of automatic mode
    inline uint32_t SDHC_MMCBOOT_BOOTBLKCNT (const uint32_t inValue) { return (inValue & 65535U) << 16 ; }

//-------------------- Host Controller Version
#define SDHC_HOSTVER (* ((const volatile uint32_t *) (0x400B1000 + 0xFC)))

  // Field (width: 8 bits): Specification Version Number
    inline uint32_t SDHC_HOSTVER_SVN (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Vendor Version Number
    inline uint32_t SDHC_HOSTVER_VVN (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral ENET
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Interrupt Event Register
#define ENET_EIR (* ((volatile uint32_t *) (0x400C0000 + 0x4)))

  // Boolean field: Timestamp Timer
    static const uint32_t ENET_EIR_TS_TIMER = 1U << 15 ;

  // Boolean field: Transmit Timestamp Available
    static const uint32_t ENET_EIR_TS_AVAIL = 1U << 16 ;

  // Boolean field: Node Wakeup Request Indication
    static const uint32_t ENET_EIR_WAKEUP = 1U << 17 ;

  // Boolean field: Payload Receive Error
    static const uint32_t ENET_EIR_PLR = 1U << 18 ;

  // Boolean field: Transmit FIFO Underrun
    static const uint32_t ENET_EIR_UN = 1U << 19 ;

  // Boolean field: Collision Retry Limit
    static const uint32_t ENET_EIR_RL = 1U << 20 ;

  // Boolean field: Late Collision
    static const uint32_t ENET_EIR_LC = 1U << 21 ;

  // Boolean field: Ethernet Bus Error
    static const uint32_t ENET_EIR_EBERR = 1U << 22 ;

  // Boolean field: MII Interrupt.
    static const uint32_t ENET_EIR_MII = 1U << 23 ;

  // Boolean field: Receive Buffer Interrupt
    static const uint32_t ENET_EIR_RXB = 1U << 24 ;

  // Boolean field: Receive Frame Interrupt
    static const uint32_t ENET_EIR_RXF = 1U << 25 ;

  // Boolean field: Transmit Buffer Interrupt
    static const uint32_t ENET_EIR_TXB = 1U << 26 ;

  // Boolean field: Transmit Frame Interrupt
    static const uint32_t ENET_EIR_TXF = 1U << 27 ;

  // Boolean field: Graceful Stop Complete
    static const uint32_t ENET_EIR_GRA = 1U << 28 ;

  // Boolean field: Babbling Transmit Error
    static const uint32_t ENET_EIR_BABT = 1U << 29 ;

  // Boolean field: Babbling Receive Error
    static const uint32_t ENET_EIR_BABR = 1U << 30 ;

//-------------------- Interrupt Mask Register
#define ENET_EIMR (* ((volatile uint32_t *) (0x400C0000 + 0x8)))

  // Boolean field: TS_TIMER Interrupt Mask
    static const uint32_t ENET_EIMR_TS_TIMER = 1U << 15 ;

  // Boolean field: TS_AVAIL Interrupt Mask
    static const uint32_t ENET_EIMR_TS_AVAIL = 1U << 16 ;

  // Boolean field: WAKEUP Interrupt Mask
    static const uint32_t ENET_EIMR_WAKEUP = 1U << 17 ;

  // Boolean field: PLR Interrupt Mask
    static const uint32_t ENET_EIMR_PLR = 1U << 18 ;

  // Boolean field: UN Interrupt Mask
    static const uint32_t ENET_EIMR_UN = 1U << 19 ;

  // Boolean field: RL Interrupt Mask
    static const uint32_t ENET_EIMR_RL = 1U << 20 ;

  // Boolean field: LC Interrupt Mask
    static const uint32_t ENET_EIMR_LC = 1U << 21 ;

  // Boolean field: EBERR Interrupt Mask
    static const uint32_t ENET_EIMR_EBERR = 1U << 22 ;

  // Boolean field: MII Interrupt Mask
    static const uint32_t ENET_EIMR_MII = 1U << 23 ;

  // Boolean field: RXB Interrupt Mask
    static const uint32_t ENET_EIMR_RXB = 1U << 24 ;

  // Boolean field: RXF Interrupt Mask
    static const uint32_t ENET_EIMR_RXF = 1U << 25 ;

  // Boolean field: TXB Interrupt Mask
    static const uint32_t ENET_EIMR_TXB = 1U << 26 ;

  // Boolean field: TXF Interrupt Mask
    static const uint32_t ENET_EIMR_TXF = 1U << 27 ;

  // Boolean field: GRA Interrupt Mask
    static const uint32_t ENET_EIMR_GRA = 1U << 28 ;

  // Boolean field: BABT Interrupt Mask
    static const uint32_t ENET_EIMR_BABT = 1U << 29 ;

  // Boolean field: BABR Interrupt Mask
    static const uint32_t ENET_EIMR_BABR = 1U << 30 ;

//-------------------- Receive Descriptor Active Register
#define ENET_RDAR (* ((volatile uint32_t *) (0x400C0000 + 0x10)))

  // Boolean field: Receive Descriptor Active
    static const uint32_t ENET_RDAR_RDAR = 1U << 24 ;

//-------------------- Transmit Descriptor Active Register
#define ENET_TDAR (* ((volatile uint32_t *) (0x400C0000 + 0x14)))

  // Boolean field: Transmit Descriptor Active
    static const uint32_t ENET_TDAR_TDAR = 1U << 24 ;

//-------------------- Ethernet Control Register
#define ENET_ECR (* ((volatile uint32_t *) (0x400C0000 + 0x24)))

  // Boolean field: Ethernet MAC Reset
    static const uint32_t ENET_ECR_RESET = 1U << 0 ;

  // Boolean field: Ethernet Enable
    static const uint32_t ENET_ECR_ETHEREN = 1U << 1 ;

  // Boolean field: Magic Packet Detection Enable
    static const uint32_t ENET_ECR_MAGICEN = 1U << 2 ;

  // Boolean field: Sleep Mode Enable
    static const uint32_t ENET_ECR_SLEEP = 1U << 3 ;

  // Boolean field: EN1588 Enable
    static const uint32_t ENET_ECR_EN1588 = 1U << 4 ;

  // Boolean field: Debug Enable
    static const uint32_t ENET_ECR_DBGEN = 1U << 6 ;

  // Boolean field: STOPEN Signal Control
    static const uint32_t ENET_ECR_STOPEN = 1U << 7 ;

  // Boolean field: Descriptor Byte Swapping Enable
    static const uint32_t ENET_ECR_DBSWP = 1U << 8 ;

//-------------------- MII Management Frame Register
#define ENET_MMFR (* ((volatile uint32_t *) (0x400C0000 + 0x40)))

  // Field (width: 16 bits): Management Frame Data
    inline uint32_t ENET_MMFR_DATA (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Field (width: 2 bits): Turn Around
    inline uint32_t ENET_MMFR_TA (const uint32_t inValue) { return (inValue & 3U) << 16 ; }

  // Field (width: 5 bits): Register Address
    inline uint32_t ENET_MMFR_RA (const uint32_t inValue) { return (inValue & 31U) << 18 ; }

  // Field (width: 5 bits): PHY Address
    inline uint32_t ENET_MMFR_PA (const uint32_t inValue) { return (inValue & 31U) << 23 ; }

  // Field (width: 2 bits): Operation Code
    inline uint32_t ENET_MMFR_OP (const uint32_t inValue) { return (inValue & 3U) << 28 ; }

  // Field (width: 2 bits): Start Of Frame Delimiter
    inline uint32_t ENET_MMFR_ST (const uint32_t inValue) { return (inValue & 3U) << 30 ; }

//-------------------- MII Speed Control Register
#define ENET_MSCR (* ((volatile uint32_t *) (0x400C0000 + 0x44)))

  // Field (width: 6 bits): MII Speed
    inline uint32_t ENET_MSCR_MII_SPEED (const uint32_t inValue) { return (inValue & 63U) << 1 ; }

  // Boolean field: Disable Preamble
    static const uint32_t ENET_MSCR_DIS_PRE = 1U << 7 ;

  // Field (width: 3 bits): Hold time On MDIO Output
    inline uint32_t ENET_MSCR_HOLDTIME (const uint32_t inValue) { return (inValue & 7U) << 8 ; }

//-------------------- MIB Control Register
#define ENET_MIBC (* ((volatile uint32_t *) (0x400C0000 + 0x64)))

  // Boolean field: MIB Clear
    static const uint32_t ENET_MIBC_MIB_CLEAR = 1U << 29 ;

  // Boolean field: MIB Idle
    static const uint32_t ENET_MIBC_MIB_IDLE = 1U << 30 ;

  // Boolean field: Disable MIB Logic
    static const uint32_t ENET_MIBC_MIB_DIS = 1U << 31 ;

//-------------------- Receive Control Register
#define ENET_RCR (* ((volatile uint32_t *) (0x400C0000 + 0x84)))

  // Boolean field: Internal Loopback
    static const uint32_t ENET_RCR_LOOP = 1U << 0 ;

  // Boolean field: Disable Receive On Transmit
    static const uint32_t ENET_RCR_DRT = 1U << 1 ;

  // Boolean field: Media Independent Interface Mode
    static const uint32_t ENET_RCR_MII_MODE = 1U << 2 ;

  // Boolean field: Promiscuous Mode
    static const uint32_t ENET_RCR_PROM = 1U << 3 ;

  // Boolean field: Broadcast Frame Reject
    static const uint32_t ENET_RCR_BC_REJ = 1U << 4 ;

  // Boolean field: Flow Control Enable
    static const uint32_t ENET_RCR_FCE = 1U << 5 ;

  // Boolean field: RMII Mode Enable
    static const uint32_t ENET_RCR_RMII_MODE = 1U << 8 ;

  // Boolean field: Enables 10-Mbps mode of the RMII .
    static const uint32_t ENET_RCR_RMII_10T = 1U << 9 ;

  // Boolean field: Enable Frame Padding Remove On Receive
    static const uint32_t ENET_RCR_PADEN = 1U << 12 ;

  // Boolean field: Terminate/Forward Pause Frames
    static const uint32_t ENET_RCR_PAUFWD = 1U << 13 ;

  // Boolean field: Terminate/Forward Received CRC
    static const uint32_t ENET_RCR_CRCFWD = 1U << 14 ;

  // Boolean field: MAC Control Frame Enable
    static const uint32_t ENET_RCR_CFEN = 1U << 15 ;

  // Field (width: 14 bits): Maximum Frame Length
    inline uint32_t ENET_RCR_MAX_FL (const uint32_t inValue) { return (inValue & 16383U) << 16 ; }

  // Boolean field: Payload Length Check Disable
    static const uint32_t ENET_RCR_NLC = 1U << 30 ;

  // Boolean field: Graceful Receive Stopped
    static const uint32_t ENET_RCR_GRS = 1U << 31 ;

//-------------------- Transmit Control Register
#define ENET_TCR (* ((volatile uint32_t *) (0x400C0000 + 0xC4)))

  // Boolean field: Graceful Transmit Stop
    static const uint32_t ENET_TCR_GTS = 1U << 0 ;

  // Boolean field: Full-Duplex Enable
    static const uint32_t ENET_TCR_FDEN = 1U << 2 ;

  // Boolean field: Transmit Frame Control Pause
    static const uint32_t ENET_TCR_TFC_PAUSE = 1U << 3 ;

  // Boolean field: Receive Frame Control Pause
    static const uint32_t ENET_TCR_RFC_PAUSE = 1U << 4 ;

  // Field (width: 3 bits): Source MAC Address Select On Transmit
    inline uint32_t ENET_TCR_ADDSEL (const uint32_t inValue) { return (inValue & 7U) << 5 ; }

  // Boolean field: Set MAC Address On Transmit
    static const uint32_t ENET_TCR_ADDINS = 1U << 8 ;

  // Boolean field: Forward Frame From Application With CRC
    static const uint32_t ENET_TCR_CRCFWD = 1U << 9 ;

//-------------------- Physical Address Lower Register
#define ENET_PALR (* ((volatile uint32_t *) (0x400C0000 + 0xE4)))

//-------------------- Physical Address Upper Register
#define ENET_PAUR (* ((volatile uint32_t *) (0x400C0000 + 0xE8)))

  // Field (width: 16 bits): Type Field In PAUSE Frames
    inline uint32_t ENET_PAUR_TYPE (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Field (width: 16 bits): Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address used for exact match, and the source address field in PAUSE frames
    inline uint32_t ENET_PAUR_PADDR2 (const uint32_t inValue) { return (inValue & 65535U) << 16 ; }

//-------------------- Opcode/Pause Duration Register
#define ENET_OPD (* ((volatile uint32_t *) (0x400C0000 + 0xEC)))

  // Field (width: 16 bits): Pause Duration
    inline uint32_t ENET_OPD_PAUSE_DUR (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Field (width: 16 bits): Opcode Field In PAUSE Frames
    inline uint32_t ENET_OPD_OPCODE (const uint32_t inValue) { return (inValue & 65535U) << 16 ; }

//-------------------- Descriptor Individual Upper Address Register
#define ENET_IAUR (* ((volatile uint32_t *) (0x400C0000 + 0x118)))

//-------------------- Descriptor Individual Lower Address Register
#define ENET_IALR (* ((volatile uint32_t *) (0x400C0000 + 0x11C)))

//-------------------- Descriptor Group Upper Address Register
#define ENET_GAUR (* ((volatile uint32_t *) (0x400C0000 + 0x120)))

//-------------------- Descriptor Group Lower Address Register
#define ENET_GALR (* ((volatile uint32_t *) (0x400C0000 + 0x124)))

//-------------------- Transmit FIFO Watermark Register
#define ENET_TFWR (* ((volatile uint32_t *) (0x400C0000 + 0x144)))

  // Field (width: 6 bits): Transmit FIFO Write
    inline uint32_t ENET_TFWR_TFWR (const uint32_t inValue) { return (inValue & 63U) << 0 ; }

  // Boolean field: Store And Forward Enable
    static const uint32_t ENET_TFWR_STRFWD = 1U << 8 ;

//-------------------- Receive Descriptor Ring Start Register
#define ENET_RDSR (* ((volatile uint32_t *) (0x400C0000 + 0x180)))

  // Field (width: 29 bits): Pointer to the beginning of the receive buffer descriptor queue.
    inline uint32_t ENET_RDSR_R_DES_START (const uint32_t inValue) { return (inValue & 536870911U) << 3 ; }

//-------------------- Transmit Buffer Descriptor Ring Start Register
#define ENET_TDSR (* ((volatile uint32_t *) (0x400C0000 + 0x184)))

  // Field (width: 29 bits): Pointer to the beginning of the transmit buffer descriptor queue.
    inline uint32_t ENET_TDSR_X_DES_START (const uint32_t inValue) { return (inValue & 536870911U) << 3 ; }

//-------------------- Maximum Receive Buffer Size Register
#define ENET_MRBR (* ((volatile uint32_t *) (0x400C0000 + 0x188)))

  // Field (width: 7 bits): Receive buffer size in bytes
    inline uint32_t ENET_MRBR_R_BUF_SIZE (const uint32_t inValue) { return (inValue & 127U) << 4 ; }

//-------------------- Receive FIFO Section Full Threshold
#define ENET_RSFL (* ((volatile uint32_t *) (0x400C0000 + 0x190)))

  // Field (width: 8 bits): Value Of Receive FIFO Section Full Threshold
    inline uint32_t ENET_RSFL_RX_SECTION_FULL (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

//-------------------- Receive FIFO Section Empty Threshold
#define ENET_RSEM (* ((volatile uint32_t *) (0x400C0000 + 0x194)))

  // Field (width: 8 bits): Value Of The Receive FIFO Section Empty Threshold
    inline uint32_t ENET_RSEM_RX_SECTION_EMPTY (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 5 bits): RX Status FIFO Section Empty Threshold
    inline uint32_t ENET_RSEM_STAT_SECTION_EMPTY (const uint32_t inValue) { return (inValue & 31U) << 16 ; }

//-------------------- Receive FIFO Almost Empty Threshold
#define ENET_RAEM (* ((volatile uint32_t *) (0x400C0000 + 0x198)))

  // Field (width: 8 bits): Value Of The Receive FIFO Almost Empty Threshold
    inline uint32_t ENET_RAEM_RX_ALMOST_EMPTY (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

//-------------------- Receive FIFO Almost Full Threshold
#define ENET_RAFL (* ((volatile uint32_t *) (0x400C0000 + 0x19C)))

  // Field (width: 8 bits): Value Of The Receive FIFO Almost Full Threshold
    inline uint32_t ENET_RAFL_RX_ALMOST_FULL (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

//-------------------- Transmit FIFO Section Empty Threshold
#define ENET_TSEM (* ((volatile uint32_t *) (0x400C0000 + 0x1A0)))

  // Field (width: 8 bits): Value Of The Transmit FIFO Section Empty Threshold
    inline uint32_t ENET_TSEM_TX_SECTION_EMPTY (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

//-------------------- Transmit FIFO Almost Empty Threshold
#define ENET_TAEM (* ((volatile uint32_t *) (0x400C0000 + 0x1A4)))

  // Field (width: 8 bits): Value of Transmit FIFO Almost Empty Threshold
    inline uint32_t ENET_TAEM_TX_ALMOST_EMPTY (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

//-------------------- Transmit FIFO Almost Full Threshold
#define ENET_TAFL (* ((volatile uint32_t *) (0x400C0000 + 0x1A8)))

  // Field (width: 8 bits): Value Of The Transmit FIFO Almost Full Threshold
    inline uint32_t ENET_TAFL_TX_ALMOST_FULL (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

//-------------------- Transmit Inter-Packet Gap
#define ENET_TIPG (* ((volatile uint32_t *) (0x400C0000 + 0x1AC)))

  // Field (width: 5 bits): Transmit Inter-Packet Gap
    inline uint32_t ENET_TIPG_IPG (const uint32_t inValue) { return (inValue & 31U) << 0 ; }

//-------------------- Frame Truncation Length
#define ENET_FTRL (* ((volatile uint32_t *) (0x400C0000 + 0x1B0)))

  // Field (width: 14 bits): Frame Truncation Length
    inline uint32_t ENET_FTRL_TRUNC_FL (const uint32_t inValue) { return (inValue & 16383U) << 0 ; }

//-------------------- Transmit Accelerator Function Configuration
#define ENET_TACC (* ((volatile uint32_t *) (0x400C0000 + 0x1C0)))

  // Boolean field: TX FIFO Shift-16
    static const uint32_t ENET_TACC_SHIFT16 = 1U << 0 ;

  // Boolean field: Enables insertion of IP header checksum.
    static const uint32_t ENET_TACC_IPCHK = 1U << 3 ;

  // Boolean field: Enables insertion of protocol checksum.
    static const uint32_t ENET_TACC_PROCHK = 1U << 4 ;

//-------------------- Receive Accelerator Function Configuration
#define ENET_RACC (* ((volatile uint32_t *) (0x400C0000 + 0x1C4)))

  // Boolean field: Enable Padding Removal For Short IP Frames
    static const uint32_t ENET_RACC_PADREM = 1U << 0 ;

  // Boolean field: Enable Discard Of Frames With Wrong IPv4 Header Checksum
    static const uint32_t ENET_RACC_IPDIS = 1U << 1 ;

  // Boolean field: Enable Discard Of Frames With Wrong Protocol Checksum
    static const uint32_t ENET_RACC_PRODIS = 1U << 2 ;

  // Boolean field: Enable Discard Of Frames With MAC Layer Errors
    static const uint32_t ENET_RACC_LINEDIS = 1U << 6 ;

  // Boolean field: RX FIFO Shift-16
    static const uint32_t ENET_RACC_SHIFT16 = 1U << 7 ;

//-------------------- Reserved Statistic Register
#define ENET_RMON_T_DROP (* ((const volatile uint32_t *) (0x400C0000 + 0x200)))

//-------------------- Tx Packet Count Statistic Register
#define ENET_RMON_T_PACKETS (* ((const volatile uint32_t *) (0x400C0000 + 0x204)))

  // Field (width: 16 bits): Packet count
    inline uint32_t ENET_RMON_T_PACKETS_TXPKTS (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Tx Broadcast Packets Statistic Register
#define ENET_RMON_T_BC_PKT (* ((const volatile uint32_t *) (0x400C0000 + 0x208)))

  // Field (width: 16 bits): Broadcast packets
    inline uint32_t ENET_RMON_T_BC_PKT_TXPKTS (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Tx Multicast Packets Statistic Register
#define ENET_RMON_T_MC_PKT (* ((const volatile uint32_t *) (0x400C0000 + 0x20C)))

  // Field (width: 16 bits): Multicast packets
    inline uint32_t ENET_RMON_T_MC_PKT_TXPKTS (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Tx Packets with CRC/Align Error Statistic Register
#define ENET_RMON_T_CRC_ALIGN (* ((const volatile uint32_t *) (0x400C0000 + 0x210)))

  // Field (width: 16 bits): Packets with CRC/align error
    inline uint32_t ENET_RMON_T_CRC_ALIGN_TXPKTS (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Tx Packets Less Than Bytes and Good CRC Statistic Register
#define ENET_RMON_T_UNDERSIZE (* ((const volatile uint32_t *) (0x400C0000 + 0x214)))

  // Field (width: 16 bits): Number of transmit packets less than 64 bytes with good CRC
    inline uint32_t ENET_RMON_T_UNDERSIZE_TXPKTS (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Tx Packets GT MAX_FL bytes and Good CRC Statistic Register
#define ENET_RMON_T_OVERSIZE (* ((const volatile uint32_t *) (0x400C0000 + 0x218)))

  // Field (width: 16 bits): Number of transmit packets greater than MAX_FL bytes with good CRC
    inline uint32_t ENET_RMON_T_OVERSIZE_TXPKTS (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Tx Packets Less Than 64 Bytes and Bad CRC Statistic Register
#define ENET_RMON_T_FRAG (* ((const volatile uint32_t *) (0x400C0000 + 0x21C)))

  // Field (width: 16 bits): Number of packets less than 64 bytes with bad CRC
    inline uint32_t ENET_RMON_T_FRAG_TXPKTS (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Tx Packets Greater Than MAX_FL bytes and Bad CRC Statistic Register
#define ENET_RMON_T_JAB (* ((const volatile uint32_t *) (0x400C0000 + 0x220)))

  // Field (width: 16 bits): Number of transmit packets greater than MAX_FL bytes and bad CRC
    inline uint32_t ENET_RMON_T_JAB_TXPKTS (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Tx Collision Count Statistic Register
#define ENET_RMON_T_COL (* ((const volatile uint32_t *) (0x400C0000 + 0x224)))

  // Field (width: 16 bits): Number of transmit collisions
    inline uint32_t ENET_RMON_T_COL_TXPKTS (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Tx 64-Byte Packets Statistic Register
#define ENET_RMON_T_P64 (* ((const volatile uint32_t *) (0x400C0000 + 0x228)))

  // Field (width: 16 bits): Number of 64-byte transmit packets
    inline uint32_t ENET_RMON_T_P64_TXPKTS (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Tx 65- to 127-byte Packets Statistic Register
#define ENET_RMON_T_P65TO127 (* ((const volatile uint32_t *) (0x400C0000 + 0x22C)))

  // Field (width: 16 bits): Number of 65- to 127-byte transmit packets
    inline uint32_t ENET_RMON_T_P65TO127_TXPKTS (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Tx 128- to 255-byte Packets Statistic Register
#define ENET_RMON_T_P128TO255 (* ((const volatile uint32_t *) (0x400C0000 + 0x230)))

  // Field (width: 16 bits): Number of 128- to 255-byte transmit packets
    inline uint32_t ENET_RMON_T_P128TO255_TXPKTS (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Tx 256- to 511-byte Packets Statistic Register
#define ENET_RMON_T_P256TO511 (* ((const volatile uint32_t *) (0x400C0000 + 0x234)))

  // Field (width: 16 bits): Number of 256- to 511-byte transmit packets
    inline uint32_t ENET_RMON_T_P256TO511_TXPKTS (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Tx 512- to 1023-byte Packets Statistic Register
#define ENET_RMON_T_P512TO1023 (* ((const volatile uint32_t *) (0x400C0000 + 0x238)))

  // Field (width: 16 bits): Number of 512- to 1023-byte transmit packets
    inline uint32_t ENET_RMON_T_P512TO1023_TXPKTS (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Tx 1024- to 2047-byte Packets Statistic Register
#define ENET_RMON_T_P1024TO2047 (* ((const volatile uint32_t *) (0x400C0000 + 0x23C)))

  // Field (width: 16 bits): Number of 1024- to 2047-byte transmit packets
    inline uint32_t ENET_RMON_T_P1024TO2047_TXPKTS (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Tx Packets Greater Than 2048 Bytes Statistic Register
#define ENET_RMON_T_P_GTE2048 (* ((const volatile uint32_t *) (0x400C0000 + 0x240)))

  // Field (width: 16 bits): Number of transmit packets greater than 2048 bytes
    inline uint32_t ENET_RMON_T_P_GTE2048_TXPKTS (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Tx Octets Statistic Register
#define ENET_RMON_T_OCTETS (* ((const volatile uint32_t *) (0x400C0000 + 0x244)))

//-------------------- IEEE_T_DROP Reserved Statistic Register
#define ENET_IEEE_T_DROP (* ((const volatile uint32_t *) (0x400C0000 + 0x248)))

//-------------------- Frames Transmitted OK Statistic Register
#define ENET_IEEE_T_FRAME_OK (* ((const volatile uint32_t *) (0x400C0000 + 0x24C)))

  // Field (width: 16 bits): Number of frames transmitted OK
    inline uint32_t ENET_IEEE_T_FRAME_OK_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Frames Transmitted with Single Collision Statistic Register
#define ENET_IEEE_T_1COL (* ((const volatile uint32_t *) (0x400C0000 + 0x250)))

  // Field (width: 16 bits): Number of frames transmitted with one collision
    inline uint32_t ENET_IEEE_T_1COL_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Frames Transmitted with Multiple Collisions Statistic Register
#define ENET_IEEE_T_MCOL (* ((const volatile uint32_t *) (0x400C0000 + 0x254)))

  // Field (width: 16 bits): Number of frames transmitted with multiple collisions
    inline uint32_t ENET_IEEE_T_MCOL_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Frames Transmitted after Deferral Delay Statistic Register
#define ENET_IEEE_T_DEF (* ((const volatile uint32_t *) (0x400C0000 + 0x258)))

  // Field (width: 16 bits): Number of frames transmitted with deferral delay
    inline uint32_t ENET_IEEE_T_DEF_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Frames Transmitted with Late Collision Statistic Register
#define ENET_IEEE_T_LCOL (* ((const volatile uint32_t *) (0x400C0000 + 0x25C)))

  // Field (width: 16 bits): Number of frames transmitted with late collision
    inline uint32_t ENET_IEEE_T_LCOL_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Frames Transmitted with Excessive Collisions Statistic Register
#define ENET_IEEE_T_EXCOL (* ((const volatile uint32_t *) (0x400C0000 + 0x260)))

  // Field (width: 16 bits): Number of frames transmitted with excessive collisions
    inline uint32_t ENET_IEEE_T_EXCOL_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Frames Transmitted with Tx FIFO Underrun Statistic Register
#define ENET_IEEE_T_MACERR (* ((const volatile uint32_t *) (0x400C0000 + 0x264)))

  // Field (width: 16 bits): Number of frames transmitted with transmit FIFO underrun
    inline uint32_t ENET_IEEE_T_MACERR_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Frames Transmitted with Carrier Sense Error Statistic Register
#define ENET_IEEE_T_CSERR (* ((const volatile uint32_t *) (0x400C0000 + 0x268)))

  // Field (width: 16 bits): Number of frames transmitted with carrier sense error
    inline uint32_t ENET_IEEE_T_CSERR_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- no description available
#define ENET_IEEE_T_SQE (* ((const volatile uint32_t *) (0x400C0000 + 0x26C)))

  // Field (width: 16 bits): Number of frames transmitted with SQE error
    inline uint32_t ENET_IEEE_T_SQE_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Flow Control Pause Frames Transmitted Statistic Register
#define ENET_IEEE_T_FDXFC (* ((const volatile uint32_t *) (0x400C0000 + 0x270)))

  // Field (width: 16 bits): Number of flow-control pause frames transmitted
    inline uint32_t ENET_IEEE_T_FDXFC_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Octet Count for Frames Transmitted w/o Error Statistic Register
#define ENET_IEEE_T_OCTETS_OK (* ((const volatile uint32_t *) (0x400C0000 + 0x274)))

//-------------------- Rx Packet Count Statistic Register
#define ENET_RMON_R_PACKETS (* ((const volatile uint32_t *) (0x400C0000 + 0x284)))

  // Field (width: 16 bits): Number of packets received
    inline uint32_t ENET_RMON_R_PACKETS_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Rx Broadcast Packets Statistic Register
#define ENET_RMON_R_BC_PKT (* ((const volatile uint32_t *) (0x400C0000 + 0x288)))

  // Field (width: 16 bits): Number of receive broadcast packets
    inline uint32_t ENET_RMON_R_BC_PKT_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Rx Multicast Packets Statistic Register
#define ENET_RMON_R_MC_PKT (* ((const volatile uint32_t *) (0x400C0000 + 0x28C)))

  // Field (width: 16 bits): Number of receive multicast packets
    inline uint32_t ENET_RMON_R_MC_PKT_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Rx Packets with CRC/Align Error Statistic Register
#define ENET_RMON_R_CRC_ALIGN (* ((const volatile uint32_t *) (0x400C0000 + 0x290)))

  // Field (width: 16 bits): Number of receive packets with CRC or align error
    inline uint32_t ENET_RMON_R_CRC_ALIGN_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Rx Packets with Less Than 64 Bytes and Good CRC Statistic Register
#define ENET_RMON_R_UNDERSIZE (* ((const volatile uint32_t *) (0x400C0000 + 0x294)))

  // Field (width: 16 bits): Number of receive packets with less than 64 bytes and good CRC
    inline uint32_t ENET_RMON_R_UNDERSIZE_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Rx Packets Greater Than MAX_FL and Good CRC Statistic Register
#define ENET_RMON_R_OVERSIZE (* ((const volatile uint32_t *) (0x400C0000 + 0x298)))

  // Field (width: 16 bits): Number of receive packets greater than MAX_FL and good CRC
    inline uint32_t ENET_RMON_R_OVERSIZE_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Rx Packets Less Than 64 Bytes and Bad CRC Statistic Register
#define ENET_RMON_R_FRAG (* ((const volatile uint32_t *) (0x400C0000 + 0x29C)))

  // Field (width: 16 bits): Number of receive packets with less than 64 bytes and bad CRC
    inline uint32_t ENET_RMON_R_FRAG_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Rx Packets Greater Than MAX_FL Bytes and Bad CRC Statistic Register
#define ENET_RMON_R_JAB (* ((const volatile uint32_t *) (0x400C0000 + 0x2A0)))

  // Field (width: 16 bits): Number of receive packets greater than MAX_FL and bad CRC
    inline uint32_t ENET_RMON_R_JAB_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Reserved Statistic Register
#define ENET_RMON_R_RESVD_0 (* ((const volatile uint32_t *) (0x400C0000 + 0x2A4)))

//-------------------- Rx 64-Byte Packets Statistic Register
#define ENET_RMON_R_P64 (* ((const volatile uint32_t *) (0x400C0000 + 0x2A8)))

  // Field (width: 16 bits): Number of 64-byte receive packets
    inline uint32_t ENET_RMON_R_P64_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Rx 65- to 127-Byte Packets Statistic Register
#define ENET_RMON_R_P65TO127 (* ((const volatile uint32_t *) (0x400C0000 + 0x2AC)))

  // Field (width: 16 bits): Number of 65- to 127-byte recieve packets
    inline uint32_t ENET_RMON_R_P65TO127_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Rx 128- to 255-Byte Packets Statistic Register
#define ENET_RMON_R_P128TO255 (* ((const volatile uint32_t *) (0x400C0000 + 0x2B0)))

  // Field (width: 16 bits): Number of 128- to 255-byte recieve packets
    inline uint32_t ENET_RMON_R_P128TO255_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Rx 256- to 511-Byte Packets Statistic Register
#define ENET_RMON_R_P256TO511 (* ((const volatile uint32_t *) (0x400C0000 + 0x2B4)))

  // Field (width: 16 bits): Number of 256- to 511-byte recieve packets
    inline uint32_t ENET_RMON_R_P256TO511_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Rx 512- to 1023-Byte Packets Statistic Register
#define ENET_RMON_R_P512TO1023 (* ((const volatile uint32_t *) (0x400C0000 + 0x2B8)))

  // Field (width: 16 bits): Number of 512- to 1023-byte recieve packets
    inline uint32_t ENET_RMON_R_P512TO1023_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Rx 1024- to 2047-Byte Packets Statistic Register
#define ENET_RMON_R_P1024TO2047 (* ((const volatile uint32_t *) (0x400C0000 + 0x2BC)))

  // Field (width: 16 bits): Number of 1024- to 2047-byte recieve packets
    inline uint32_t ENET_RMON_R_P1024TO2047_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Rx Packets Greater than 2048 Bytes Statistic Register
#define ENET_RMON_R_P_GTE2048 (* ((const volatile uint32_t *) (0x400C0000 + 0x2C0)))

  // Field (width: 16 bits): Number of greater-than-2048-byte recieve packets
    inline uint32_t ENET_RMON_R_P_GTE2048_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Rx Octets Statistic Register
#define ENET_RMON_R_OCTETS (* ((const volatile uint32_t *) (0x400C0000 + 0x2C4)))

//-------------------- Frames not Counted Correctly Statistic Register
#define ENET_IEEE_R_DROP (* ((const volatile uint32_t *) (0x400C0000 + 0x2C8)))

  // Field (width: 16 bits): Frame count
    inline uint32_t ENET_IEEE_R_DROP_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Frames Received OK Statistic Register
#define ENET_IEEE_R_FRAME_OK (* ((const volatile uint32_t *) (0x400C0000 + 0x2CC)))

  // Field (width: 16 bits): Number of frames received OK
    inline uint32_t ENET_IEEE_R_FRAME_OK_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Frames Received with CRC Error Statistic Register
#define ENET_IEEE_R_CRC (* ((const volatile uint32_t *) (0x400C0000 + 0x2D0)))

  // Field (width: 16 bits): Number of frames received with CRC error
    inline uint32_t ENET_IEEE_R_CRC_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Frames Received with Alignment Error Statistic Register
#define ENET_IEEE_R_ALIGN (* ((const volatile uint32_t *) (0x400C0000 + 0x2D4)))

  // Field (width: 16 bits): Number of frames received with alignment error
    inline uint32_t ENET_IEEE_R_ALIGN_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Receive FIFO Overflow Count Statistic Register
#define ENET_IEEE_R_MACERR (* ((const volatile uint32_t *) (0x400C0000 + 0x2D8)))

  // Field (width: 16 bits): Receive FIFO overflow count
    inline uint32_t ENET_IEEE_R_MACERR_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Flow Control Pause Frames Received Statistic Register
#define ENET_IEEE_R_FDXFC (* ((const volatile uint32_t *) (0x400C0000 + 0x2DC)))

  // Field (width: 16 bits): Number of flow-control pause frames received
    inline uint32_t ENET_IEEE_R_FDXFC_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Octet Count for Frames Received without Error Statistic Register
#define ENET_IEEE_R_OCTETS_OK (* ((const volatile uint32_t *) (0x400C0000 + 0x2E0)))

//-------------------- Adjustable Timer Control Register
#define ENET_ATCR (* ((volatile uint32_t *) (0x400C0000 + 0x400)))

  // Boolean field: Enable Timer
    static const uint32_t ENET_ATCR_EN = 1U << 0 ;

  // Boolean field: Enable One-Shot Offset Event
    static const uint32_t ENET_ATCR_OFFEN = 1U << 2 ;

  // Boolean field: Reset Timer On Offset Event
    static const uint32_t ENET_ATCR_OFFRST = 1U << 3 ;

  // Boolean field: Enable Periodical Event
    static const uint32_t ENET_ATCR_PEREN = 1U << 4 ;

  // Boolean field: Enables event signal output assertion on period event
    static const uint32_t ENET_ATCR_PINPER = 1U << 7 ;

  // Boolean field: Reset Timer
    static const uint32_t ENET_ATCR_RESTART = 1U << 9 ;

  // Boolean field: Capture Timer Value
    static const uint32_t ENET_ATCR_CAPTURE = 1U << 11 ;

  // Boolean field: Enable Timer Slave Mode
    static const uint32_t ENET_ATCR_SLAVE = 1U << 13 ;

//-------------------- Timer Value Register
#define ENET_ATVR (* ((volatile uint32_t *) (0x400C0000 + 0x404)))

//-------------------- Timer Offset Register
#define ENET_ATOFF (* ((volatile uint32_t *) (0x400C0000 + 0x408)))

//-------------------- Timer Period Register
#define ENET_ATPER (* ((volatile uint32_t *) (0x400C0000 + 0x40C)))

//-------------------- Timer Correction Register
#define ENET_ATCOR (* ((volatile uint32_t *) (0x400C0000 + 0x410)))

  // Field (width: 31 bits): Correction Counter Wrap-Around Value
    inline uint32_t ENET_ATCOR_COR (const uint32_t inValue) { return (inValue & 2147483647U) << 0 ; }

//-------------------- Time-Stamping Clock Period Register
#define ENET_ATINC (* ((volatile uint32_t *) (0x400C0000 + 0x414)))

  // Field (width: 7 bits): Clock Period Of The Timestamping Clock (ts_clk) In Nanoseconds
    inline uint32_t ENET_ATINC_INC (const uint32_t inValue) { return (inValue & 127U) << 0 ; }

  // Field (width: 7 bits): Correction Increment Value
    inline uint32_t ENET_ATINC_INC_CORR (const uint32_t inValue) { return (inValue & 127U) << 8 ; }

//-------------------- Timestamp of Last Transmitted Frame
#define ENET_ATSTMP (* ((const volatile uint32_t *) (0x400C0000 + 0x418)))

//-------------------- Timer Global Status Register
#define ENET_TGSR (* ((volatile uint32_t *) (0x400C0000 + 0x604)))

  // Boolean field: Copy Of Timer Flag For Channel 0
    static const uint32_t ENET_TGSR_TF0 = 1U << 0 ;

  // Boolean field: Copy Of Timer Flag For Channel 1
    static const uint32_t ENET_TGSR_TF1 = 1U << 1 ;

  // Boolean field: Copy Of Timer Flag For Channel 2
    static const uint32_t ENET_TGSR_TF2 = 1U << 2 ;

  // Boolean field: Copy Of Timer Flag For Channel 3
    static const uint32_t ENET_TGSR_TF3 = 1U << 3 ;

//-------------------- Timer Control Status Register (idx = 0 ... 3)
#define ENET_TCSR(idx) (* ((volatile uint32_t *) (0x400C0000 + 0x608 + 0x8 * (idx))))

  // Boolean field: Timer DMA Request Enable
    static const uint32_t ENET_TCSR_TDRE = 1U << 0 ;

  // Field (width: 4 bits): Timer Mode
    inline uint32_t ENET_TCSR_TMODE (const uint32_t inValue) { return (inValue & 15U) << 2 ; }

  // Boolean field: Timer Interrupt Enable
    static const uint32_t ENET_TCSR_TIE = 1U << 6 ;

  // Boolean field: Timer Flag
    static const uint32_t ENET_TCSR_TF = 1U << 7 ;

//-------------------- Timer Compare Capture Register (idx = 0 ... 3)
#define ENET_TCCR(idx) (* ((volatile uint32_t *) (0x400C0000 + 0x60C + 0x8 * (idx))))

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral LPUART0
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- LPUART Baud Rate Register
#define LPUART0_BAUD (* ((volatile uint32_t *) (0x400C4000 + 0)))

  // Field (width: 13 bits): Baud Rate Modulo Divisor.
    inline uint32_t LPUART0_BAUD_SBR (const uint32_t inValue) { return (inValue & 8191U) << 0 ; }

  // Boolean field: Stop Bit Number Select
    static const uint32_t LPUART0_BAUD_SBNS = 1U << 13 ;

  // Boolean field: RX Input Active Edge Interrupt Enable
    static const uint32_t LPUART0_BAUD_RXEDGIE = 1U << 14 ;

  // Boolean field: LIN Break Detect Interrupt Enable
    static const uint32_t LPUART0_BAUD_LBKDIE = 1U << 15 ;

  // Boolean field: Resynchronization Disable
    static const uint32_t LPUART0_BAUD_RESYNCDIS = 1U << 16 ;

  // Boolean field: Both Edge Sampling
    static const uint32_t LPUART0_BAUD_BOTHEDGE = 1U << 17 ;

  // Field (width: 2 bits): Match Configuration
    inline uint32_t LPUART0_BAUD_MATCFG (const uint32_t inValue) { return (inValue & 3U) << 18 ; }

  // Boolean field: Receiver Full DMA Enable
    static const uint32_t LPUART0_BAUD_RDMAE = 1U << 21 ;

  // Boolean field: Transmitter DMA Enable
    static const uint32_t LPUART0_BAUD_TDMAE = 1U << 23 ;

  // Field (width: 5 bits): Over Sampling Ratio
    inline uint32_t LPUART0_BAUD_OSR (const uint32_t inValue) { return (inValue & 31U) << 24 ; }

  // Boolean field: 10-bit Mode select
    static const uint32_t LPUART0_BAUD_M10 = 1U << 29 ;

  // Boolean field: Match Address Mode Enable 2
    static const uint32_t LPUART0_BAUD_MAEN2 = 1U << 30 ;

  // Boolean field: Match Address Mode Enable 1
    static const uint32_t LPUART0_BAUD_MAEN1 = 1U << 31 ;

//-------------------- LPUART Status Register
#define LPUART0_STAT (* ((volatile uint32_t *) (0x400C4000 + 0x4)))

  // Boolean field: Match 2 Flag
    static const uint32_t LPUART0_STAT_MA2F = 1U << 14 ;

  // Boolean field: Match 1 Flag
    static const uint32_t LPUART0_STAT_MA1F = 1U << 15 ;

  // Boolean field: Parity Error Flag
    static const uint32_t LPUART0_STAT_PF = 1U << 16 ;

  // Boolean field: Framing Error Flag
    static const uint32_t LPUART0_STAT_FE = 1U << 17 ;

  // Boolean field: Noise Flag
    static const uint32_t LPUART0_STAT_NF = 1U << 18 ;

  // Boolean field: Receiver Overrun Flag
    static const uint32_t LPUART0_STAT_OR = 1U << 19 ;

  // Boolean field: Idle Line Flag
    static const uint32_t LPUART0_STAT_IDLE = 1U << 20 ;

  // Boolean field: Receive Data Register Full Flag
    static const uint32_t LPUART0_STAT_RDRF = 1U << 21 ;

  // Boolean field: Transmission Complete Flag
    static const uint32_t LPUART0_STAT_TC = 1U << 22 ;

  // Boolean field: Transmit Data Register Empty Flag
    static const uint32_t LPUART0_STAT_TDRE = 1U << 23 ;

  // Boolean field: Receiver Active Flag
    static const uint32_t LPUART0_STAT_RAF = 1U << 24 ;

  // Boolean field: LIN Break Detection Enable
    static const uint32_t LPUART0_STAT_LBKDE = 1U << 25 ;

  // Boolean field: Break Character Generation Length
    static const uint32_t LPUART0_STAT_BRK13 = 1U << 26 ;

  // Boolean field: Receive Wake Up Idle Detect
    static const uint32_t LPUART0_STAT_RWUID = 1U << 27 ;

  // Boolean field: Receive Data Inversion
    static const uint32_t LPUART0_STAT_RXINV = 1U << 28 ;

  // Boolean field: MSB First
    static const uint32_t LPUART0_STAT_MSBF = 1U << 29 ;

  // Boolean field: LPUART_RX Pin Active Edge Interrupt Flag
    static const uint32_t LPUART0_STAT_RXEDGIF = 1U << 30 ;

  // Boolean field: LIN Break Detect Interrupt Flag
    static const uint32_t LPUART0_STAT_LBKDIF = 1U << 31 ;

//-------------------- LPUART Control Register
#define LPUART0_CTRL (* ((volatile uint32_t *) (0x400C4000 + 0x8)))

  // Boolean field: Parity Type
    static const uint32_t LPUART0_CTRL_PT = 1U << 0 ;

  // Boolean field: Parity Enable
    static const uint32_t LPUART0_CTRL_PE = 1U << 1 ;

  // Boolean field: Idle Line Type Select
    static const uint32_t LPUART0_CTRL_ILT = 1U << 2 ;

  // Boolean field: Receiver Wakeup Method Select
    static const uint32_t LPUART0_CTRL_WAKE = 1U << 3 ;

  // Boolean field: 9-Bit or 8-Bit Mode Select
    static const uint32_t LPUART0_CTRL_M = 1U << 4 ;

  // Boolean field: Receiver Source Select
    static const uint32_t LPUART0_CTRL_RSRC = 1U << 5 ;

  // Boolean field: Doze Enable
    static const uint32_t LPUART0_CTRL_DOZEEN = 1U << 6 ;

  // Boolean field: Loop Mode Select
    static const uint32_t LPUART0_CTRL_LOOPS = 1U << 7 ;

  // Field (width: 3 bits): Idle Configuration
    inline uint32_t LPUART0_CTRL_IDLECFG (const uint32_t inValue) { return (inValue & 7U) << 8 ; }

  // Boolean field: Match 2 Interrupt Enable
    static const uint32_t LPUART0_CTRL_MA2IE = 1U << 14 ;

  // Boolean field: Match 1 Interrupt Enable
    static const uint32_t LPUART0_CTRL_MA1IE = 1U << 15 ;

  // Boolean field: Send Break
    static const uint32_t LPUART0_CTRL_SBK = 1U << 16 ;

  // Boolean field: Receiver Wakeup Control
    static const uint32_t LPUART0_CTRL_RWU = 1U << 17 ;

  // Boolean field: Receiver Enable
    static const uint32_t LPUART0_CTRL_RE = 1U << 18 ;

  // Boolean field: Transmitter Enable
    static const uint32_t LPUART0_CTRL_TE = 1U << 19 ;

  // Boolean field: Idle Line Interrupt Enable
    static const uint32_t LPUART0_CTRL_ILIE = 1U << 20 ;

  // Boolean field: Receiver Interrupt Enable
    static const uint32_t LPUART0_CTRL_RIE = 1U << 21 ;

  // Boolean field: Transmission Complete Interrupt Enable for
    static const uint32_t LPUART0_CTRL_TCIE = 1U << 22 ;

  // Boolean field: Transmit Interrupt Enable
    static const uint32_t LPUART0_CTRL_TIE = 1U << 23 ;

  // Boolean field: Parity Error Interrupt Enable
    static const uint32_t LPUART0_CTRL_PEIE = 1U << 24 ;

  // Boolean field: Framing Error Interrupt Enable
    static const uint32_t LPUART0_CTRL_FEIE = 1U << 25 ;

  // Boolean field: Noise Error Interrupt Enable
    static const uint32_t LPUART0_CTRL_NEIE = 1U << 26 ;

  // Boolean field: Overrun Interrupt Enable
    static const uint32_t LPUART0_CTRL_ORIE = 1U << 27 ;

  // Boolean field: Transmit Data Inversion
    static const uint32_t LPUART0_CTRL_TXINV = 1U << 28 ;

  // Boolean field: LPUART_TX Pin Direction in Single-Wire Mode
    static const uint32_t LPUART0_CTRL_TXDIR = 1U << 29 ;

  // Boolean field: Receive Bit 9 / Transmit Bit 8
    static const uint32_t LPUART0_CTRL_R9T8 = 1U << 30 ;

  // Boolean field: Receive Bit 8 / Transmit Bit 9
    static const uint32_t LPUART0_CTRL_R8T9 = 1U << 31 ;

//-------------------- LPUART Data Register
#define LPUART0_DATA (* ((volatile uint32_t *) (0x400C4000 + 0xC)))

  // Boolean field: Read receive data buffer 0 or write transmit data buffer 0.
    static const uint32_t LPUART0_DATA_R0T0 = 1U << 0 ;

  // Boolean field: Read receive data buffer 1 or write transmit data buffer 1.
    static const uint32_t LPUART0_DATA_R1T1 = 1U << 1 ;

  // Boolean field: Read receive data buffer 2 or write transmit data buffer 2.
    static const uint32_t LPUART0_DATA_R2T2 = 1U << 2 ;

  // Boolean field: Read receive data buffer 3 or write transmit data buffer 3.
    static const uint32_t LPUART0_DATA_R3T3 = 1U << 3 ;

  // Boolean field: Read receive data buffer 4 or write transmit data buffer 4.
    static const uint32_t LPUART0_DATA_R4T4 = 1U << 4 ;

  // Boolean field: Read receive data buffer 5 or write transmit data buffer 5.
    static const uint32_t LPUART0_DATA_R5T5 = 1U << 5 ;

  // Boolean field: Read receive data buffer 6 or write transmit data buffer 6.
    static const uint32_t LPUART0_DATA_R6T6 = 1U << 6 ;

  // Boolean field: Read receive data buffer 7 or write transmit data buffer 7.
    static const uint32_t LPUART0_DATA_R7T7 = 1U << 7 ;

  // Boolean field: Read receive data buffer 8 or write transmit data buffer 8.
    static const uint32_t LPUART0_DATA_R8T8 = 1U << 8 ;

  // Boolean field: Read receive data buffer 9 or write transmit data buffer 9.
    static const uint32_t LPUART0_DATA_R9T9 = 1U << 9 ;

  // Boolean field: Idle Line
    static const uint32_t LPUART0_DATA_IDLINE = 1U << 11 ;

  // Boolean field: Receive Buffer Empty
    static const uint32_t LPUART0_DATA_RXEMPT = 1U << 12 ;

  // Boolean field: Frame Error / Transmit Special Character
    static const uint32_t LPUART0_DATA_FRETSC = 1U << 13 ;

  // Boolean field: The current received dataword contained in DATA[R9:R0] was received with a parity error.
    static const uint32_t LPUART0_DATA_PARITYE = 1U << 14 ;

  // Boolean field: The current received dataword contained in DATA[R9:R0] was received with noise.
    static const uint32_t LPUART0_DATA_NOISY = 1U << 15 ;

//-------------------- LPUART Match Address Register
#define LPUART0_MATCH (* ((volatile uint32_t *) (0x400C4000 + 0x10)))

  // Field (width: 10 bits): Match Address 1
    inline uint32_t LPUART0_MATCH_MA1 (const uint32_t inValue) { return (inValue & 1023U) << 0 ; }

  // Field (width: 10 bits): Match Address 2
    inline uint32_t LPUART0_MATCH_MA2 (const uint32_t inValue) { return (inValue & 1023U) << 16 ; }

//-------------------- LPUART Modem IrDA Register
#define LPUART0_MODIR (* ((volatile uint32_t *) (0x400C4000 + 0x14)))

  // Boolean field: Transmitter clear-to-send enable
    static const uint32_t LPUART0_MODIR_TXCTSE = 1U << 0 ;

  // Boolean field: Transmitter request-to-send enable
    static const uint32_t LPUART0_MODIR_TXRTSE = 1U << 1 ;

  // Boolean field: Transmitter request-to-send polarity
    static const uint32_t LPUART0_MODIR_TXRTSPOL = 1U << 2 ;

  // Boolean field: Receiver request-to-send enable
    static const uint32_t LPUART0_MODIR_RXRTSE = 1U << 3 ;

  // Boolean field: Transmit CTS Configuration
    static const uint32_t LPUART0_MODIR_TXCTSC = 1U << 4 ;

  // Boolean field: Transmit CTS Source
    static const uint32_t LPUART0_MODIR_TXCTSSRC = 1U << 5 ;

  // Field (width: 2 bits): Transmitter narrow pulse
    inline uint32_t LPUART0_MODIR_TNP (const uint32_t inValue) { return (inValue & 3U) << 16 ; }

  // Boolean field: Infrared enable
    static const uint32_t LPUART0_MODIR_IREN = 1U << 18 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral MCM
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Crossbar Switch (AXBS) Slave Configuration
#define MCM_PLASC (* ((const volatile uint16_t *) (0xE0080000 + 0x8)))

  // Field (width: 8 bits): Each bit in the ASC field indicates whether there is a corresponding connection to the crossbar switch's slave input port.
    inline uint16_t MCM_PLASC_ASC (const uint16_t inValue) { return (inValue & 255U) << 0 ; }

//-------------------- Crossbar Switch (AXBS) Master Configuration
#define MCM_PLAMC (* ((const volatile uint16_t *) (0xE0080000 + 0xA)))

  // Field (width: 8 bits): Each bit in the AMC field indicates whether there is a corresponding connection to the AXBS master input port.
    inline uint16_t MCM_PLAMC_AMC (const uint16_t inValue) { return (inValue & 255U) << 0 ; }

//-------------------- Control Register
#define MCM_CR (* ((volatile uint32_t *) (0xE0080000 + 0xC)))

  // Field (width: 2 bits): SRAM_U arbitration priority
    inline uint32_t MCM_CR_SRAMUAP (const uint32_t inValue) { return (inValue & 3U) << 24 ; }

  // Boolean field: SRAM_U write protect
    static const uint32_t MCM_CR_SRAMUWP = 1U << 26 ;

  // Field (width: 2 bits): SRAM_L arbitration priority
    inline uint32_t MCM_CR_SRAMLAP (const uint32_t inValue) { return (inValue & 3U) << 28 ; }

  // Boolean field: SRAM_L Write Protect
    static const uint32_t MCM_CR_SRAMLWP = 1U << 30 ;

//-------------------- Interrupt Status Register
#define MCM_ISCR (* ((volatile uint32_t *) (0xE0080000 + 0x10)))

  // Boolean field: Normal Interrupt Pending
    static const uint32_t MCM_ISCR_IRQ = 1U << 1 ;

  // Boolean field: Non-maskable Interrupt Pending
    static const uint32_t MCM_ISCR_NMI = 1U << 2 ;

  // Boolean field: Debug Halt Request Indicator
    static const uint32_t MCM_ISCR_DHREQ = 1U << 3 ;

  // Boolean field: FPU invalid operation interrupt status
    static const uint32_t MCM_ISCR_FIOC = 1U << 8 ;

  // Boolean field: FPU divide-by-zero interrupt status
    static const uint32_t MCM_ISCR_FDZC = 1U << 9 ;

  // Boolean field: FPU overflow interrupt status
    static const uint32_t MCM_ISCR_FOFC = 1U << 10 ;

  // Boolean field: FPU underflow interrupt status
    static const uint32_t MCM_ISCR_FUFC = 1U << 11 ;

  // Boolean field: FPU inexact interrupt status
    static const uint32_t MCM_ISCR_FIXC = 1U << 12 ;

  // Boolean field: FPU input denormal interrupt status
    static const uint32_t MCM_ISCR_FIDC = 1U << 15 ;

  // Boolean field: FPU invalid operation interrupt enable
    static const uint32_t MCM_ISCR_FIOCE = 1U << 24 ;

  // Boolean field: FPU divide-by-zero interrupt enable
    static const uint32_t MCM_ISCR_FDZCE = 1U << 25 ;

  // Boolean field: FPU overflow interrupt enable
    static const uint32_t MCM_ISCR_FOFCE = 1U << 26 ;

  // Boolean field: FPU underflow interrupt enable
    static const uint32_t MCM_ISCR_FUFCE = 1U << 27 ;

  // Boolean field: FPU inexact interrupt enable
    static const uint32_t MCM_ISCR_FIXCE = 1U << 28 ;

  // Boolean field: FPU input denormal interrupt enable
    static const uint32_t MCM_ISCR_FIDCE = 1U << 31 ;

//-------------------- ETB Counter Control register
#define MCM_ETBCC (* ((volatile uint32_t *) (0xE0080000 + 0x14)))

  // Boolean field: Counter Enable
    static const uint32_t MCM_ETBCC_CNTEN = 1U << 0 ;

  // Field (width: 2 bits): Response Type
    inline uint32_t MCM_ETBCC_RSPT (const uint32_t inValue) { return (inValue & 3U) << 1 ; }

  // Boolean field: Reload Request
    static const uint32_t MCM_ETBCC_RLRQ = 1U << 3 ;

  // Boolean field: ETM-To-TPIU Disable
    static const uint32_t MCM_ETBCC_ETDIS = 1U << 4 ;

  // Boolean field: ITM-To-TPIU Disable
    static const uint32_t MCM_ETBCC_ITDIS = 1U << 5 ;

//-------------------- ETB Reload register
#define MCM_ETBRL (* ((volatile uint32_t *) (0xE0080000 + 0x18)))

  // Field (width: 11 bits): Byte Count Reload Value
    inline uint32_t MCM_ETBRL_RELOAD (const uint32_t inValue) { return (inValue & 2047U) << 0 ; }

//-------------------- ETB Counter Value register
#define MCM_ETBCNT (* ((const volatile uint32_t *) (0xE0080000 + 0x1C)))

  // Field (width: 11 bits): Byte Count Counter Value
    inline uint32_t MCM_ETBCNT_COUNTER (const uint32_t inValue) { return (inValue & 2047U) << 0 ; }

//-------------------- Fault address register
#define MCM_FADR (* ((const volatile uint32_t *) (0xE0080000 + 0x20)))

//-------------------- Fault attributes register
#define MCM_FATR (* ((const volatile uint32_t *) (0xE0080000 + 0x24)))

  // Boolean field: Bus error access type
    static const uint32_t MCM_FATR_BEDA = 1U << 0 ;

  // Boolean field: Bus error privilege level
    static const uint32_t MCM_FATR_BEMD = 1U << 1 ;

  // Field (width: 2 bits): Bus error size
    inline uint32_t MCM_FATR_BESZ (const uint32_t inValue) { return (inValue & 3U) << 4 ; }

  // Boolean field: Bus error write
    static const uint32_t MCM_FATR_BEWT = 1U << 7 ;

  // Field (width: 4 bits): Bus error master number
    inline uint32_t MCM_FATR_BEMN (const uint32_t inValue) { return (inValue & 15U) << 8 ; }

  // Boolean field: Bus error overrun
    static const uint32_t MCM_FATR_BEOVR = 1U << 31 ;

//-------------------- Fault data register
#define MCM_FDR (* ((const volatile uint32_t *) (0xE0080000 + 0x28)))

//-------------------- Process ID register
#define MCM_PID (* ((volatile uint32_t *) (0xE0080000 + 0x30)))

  // Field (width: 8 bits): M0_PID And M1_PID For MPU
    inline uint32_t MCM_PID_PID (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

//-------------------- Compute Operation Control Register
#define MCM_CPO (* ((volatile uint32_t *) (0xE0080000 + 0x40)))

  // Boolean field: Compute Operation request
    static const uint32_t MCM_CPO_CPOREQ = 1U << 0 ;

  // Boolean field: Compute Operation acknowledge
    static const uint32_t MCM_CPO_CPOACK = 1U << 1 ;

  // Boolean field: Compute Operation wakeup on interrupt
    static const uint32_t MCM_CPO_CPOWOI = 1U << 2 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral CAU
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Direct access register 0
#define CAU_CAU_DIRECT0 (* ((volatile uint32_t *) (0xE0081000 + 0)))

//-------------------- Direct access register 1
#define CAU_CAU_DIRECT1 (* ((volatile uint32_t *) (0xE0081000 + 0x4)))

//-------------------- Direct access register 2
#define CAU_CAU_DIRECT2 (* ((volatile uint32_t *) (0xE0081000 + 0x8)))

//-------------------- Direct access register 3
#define CAU_CAU_DIRECT3 (* ((volatile uint32_t *) (0xE0081000 + 0xC)))

//-------------------- Direct access register 4
#define CAU_CAU_DIRECT4 (* ((volatile uint32_t *) (0xE0081000 + 0x10)))

//-------------------- Direct access register 5
#define CAU_CAU_DIRECT5 (* ((volatile uint32_t *) (0xE0081000 + 0x14)))

//-------------------- Direct access register 6
#define CAU_CAU_DIRECT6 (* ((volatile uint32_t *) (0xE0081000 + 0x18)))

//-------------------- Direct access register 7
#define CAU_CAU_DIRECT7 (* ((volatile uint32_t *) (0xE0081000 + 0x1C)))

//-------------------- Direct access register 8
#define CAU_CAU_DIRECT8 (* ((volatile uint32_t *) (0xE0081000 + 0x20)))

//-------------------- Direct access register 9
#define CAU_CAU_DIRECT9 (* ((volatile uint32_t *) (0xE0081000 + 0x24)))

//-------------------- Direct access register 10
#define CAU_CAU_DIRECT10 (* ((volatile uint32_t *) (0xE0081000 + 0x28)))

//-------------------- Direct access register 11
#define CAU_CAU_DIRECT11 (* ((volatile uint32_t *) (0xE0081000 + 0x2C)))

//-------------------- Direct access register 12
#define CAU_CAU_DIRECT12 (* ((volatile uint32_t *) (0xE0081000 + 0x30)))

//-------------------- Direct access register 13
#define CAU_CAU_DIRECT13 (* ((volatile uint32_t *) (0xE0081000 + 0x34)))

//-------------------- Direct access register 14
#define CAU_CAU_DIRECT14 (* ((volatile uint32_t *) (0xE0081000 + 0x38)))

//-------------------- Direct access register 15
#define CAU_CAU_DIRECT15 (* ((volatile uint32_t *) (0xE0081000 + 0x3C)))

//-------------------- Status register - Load Register command
#define CAU_CAU_LDR_CASR (* ((volatile uint32_t *) (0xE0081000 + 0x840)))

  // Boolean field: no description available
    static const uint32_t CAU_CAU_LDR_CASR_IC = 1U << 0 ;

  // Boolean field: no description available
    static const uint32_t CAU_CAU_LDR_CASR_DPE = 1U << 1 ;

  // Field (width: 4 bits): CAU version
    inline uint32_t CAU_CAU_LDR_CASR_VER (const uint32_t inValue) { return (inValue & 15U) << 28 ; }

//-------------------- Accumulator register - Load Register command
#define CAU_CAU_LDR_CAA (* ((volatile uint32_t *) (0xE0081000 + 0x844)))

//-------------------- General Purpose Register 0 - Load Register command
#define CAU_CAU_LDR_CA0 (* ((volatile uint32_t *) (0xE0081000 + 0x848)))

//-------------------- General Purpose Register 1 - Load Register command
#define CAU_CAU_LDR_CA1 (* ((volatile uint32_t *) (0xE0081000 + 0x84C)))

//-------------------- General Purpose Register 2 - Load Register command
#define CAU_CAU_LDR_CA2 (* ((volatile uint32_t *) (0xE0081000 + 0x850)))

//-------------------- General Purpose Register 3 - Load Register command
#define CAU_CAU_LDR_CA3 (* ((volatile uint32_t *) (0xE0081000 + 0x854)))

//-------------------- General Purpose Register 4 - Load Register command
#define CAU_CAU_LDR_CA4 (* ((volatile uint32_t *) (0xE0081000 + 0x858)))

//-------------------- General Purpose Register 5 - Load Register command
#define CAU_CAU_LDR_CA5 (* ((volatile uint32_t *) (0xE0081000 + 0x85C)))

//-------------------- General Purpose Register 6 - Load Register command
#define CAU_CAU_LDR_CA6 (* ((volatile uint32_t *) (0xE0081000 + 0x860)))

//-------------------- General Purpose Register 7 - Load Register command
#define CAU_CAU_LDR_CA7 (* ((volatile uint32_t *) (0xE0081000 + 0x864)))

//-------------------- General Purpose Register 8 - Load Register command
#define CAU_CAU_LDR_CA8 (* ((volatile uint32_t *) (0xE0081000 + 0x868)))

//-------------------- Status register - Store Register command
#define CAU_CAU_STR_CASR (* ((const volatile uint32_t *) (0xE0081000 + 0x880)))

  // Boolean field: no description available
    static const uint32_t CAU_CAU_STR_CASR_IC = 1U << 0 ;

  // Boolean field: no description available
    static const uint32_t CAU_CAU_STR_CASR_DPE = 1U << 1 ;

  // Field (width: 4 bits): CAU version
    inline uint32_t CAU_CAU_STR_CASR_VER (const uint32_t inValue) { return (inValue & 15U) << 28 ; }

//-------------------- Accumulator register - Store Register command
#define CAU_CAU_STR_CAA (* ((const volatile uint32_t *) (0xE0081000 + 0x884)))

//-------------------- General Purpose Register 0 - Store Register command
#define CAU_CAU_STR_CA0 (* ((const volatile uint32_t *) (0xE0081000 + 0x888)))

//-------------------- General Purpose Register 1 - Store Register command
#define CAU_CAU_STR_CA1 (* ((const volatile uint32_t *) (0xE0081000 + 0x88C)))

//-------------------- General Purpose Register 2 - Store Register command
#define CAU_CAU_STR_CA2 (* ((const volatile uint32_t *) (0xE0081000 + 0x890)))

//-------------------- General Purpose Register 3 - Store Register command
#define CAU_CAU_STR_CA3 (* ((const volatile uint32_t *) (0xE0081000 + 0x894)))

//-------------------- General Purpose Register 4 - Store Register command
#define CAU_CAU_STR_CA4 (* ((const volatile uint32_t *) (0xE0081000 + 0x898)))

//-------------------- General Purpose Register 5 - Store Register command
#define CAU_CAU_STR_CA5 (* ((const volatile uint32_t *) (0xE0081000 + 0x89C)))

//-------------------- General Purpose Register 6 - Store Register command
#define CAU_CAU_STR_CA6 (* ((const volatile uint32_t *) (0xE0081000 + 0x8A0)))

//-------------------- General Purpose Register 7 - Store Register command
#define CAU_CAU_STR_CA7 (* ((const volatile uint32_t *) (0xE0081000 + 0x8A4)))

//-------------------- General Purpose Register 8 - Store Register command
#define CAU_CAU_STR_CA8 (* ((const volatile uint32_t *) (0xE0081000 + 0x8A8)))

//-------------------- Status register - Add Register command
#define CAU_CAU_ADR_CASR (* ((volatile uint32_t *) (0xE0081000 + 0x8C0)))

  // Boolean field: no description available
    static const uint32_t CAU_CAU_ADR_CASR_IC = 1U << 0 ;

  // Boolean field: no description available
    static const uint32_t CAU_CAU_ADR_CASR_DPE = 1U << 1 ;

  // Field (width: 4 bits): CAU version
    inline uint32_t CAU_CAU_ADR_CASR_VER (const uint32_t inValue) { return (inValue & 15U) << 28 ; }

//-------------------- Accumulator register - Add to register command
#define CAU_CAU_ADR_CAA (* ((volatile uint32_t *) (0xE0081000 + 0x8C4)))

//-------------------- General Purpose Register 0 - Add to register command
#define CAU_CAU_ADR_CA0 (* ((volatile uint32_t *) (0xE0081000 + 0x8C8)))

//-------------------- General Purpose Register 1 - Add to register command
#define CAU_CAU_ADR_CA1 (* ((volatile uint32_t *) (0xE0081000 + 0x8CC)))

//-------------------- General Purpose Register 2 - Add to register command
#define CAU_CAU_ADR_CA2 (* ((volatile uint32_t *) (0xE0081000 + 0x8D0)))

//-------------------- General Purpose Register 3 - Add to register command
#define CAU_CAU_ADR_CA3 (* ((volatile uint32_t *) (0xE0081000 + 0x8D4)))

//-------------------- General Purpose Register 4 - Add to register command
#define CAU_CAU_ADR_CA4 (* ((volatile uint32_t *) (0xE0081000 + 0x8D8)))

//-------------------- General Purpose Register 5 - Add to register command
#define CAU_CAU_ADR_CA5 (* ((volatile uint32_t *) (0xE0081000 + 0x8DC)))

//-------------------- General Purpose Register 6 - Add to register command
#define CAU_CAU_ADR_CA6 (* ((volatile uint32_t *) (0xE0081000 + 0x8E0)))

//-------------------- General Purpose Register 7 - Add to register command
#define CAU_CAU_ADR_CA7 (* ((volatile uint32_t *) (0xE0081000 + 0x8E4)))

//-------------------- General Purpose Register 8 - Add to register command
#define CAU_CAU_ADR_CA8 (* ((volatile uint32_t *) (0xE0081000 + 0x8E8)))

//-------------------- Status register - Reverse and Add to Register command
#define CAU_CAU_RADR_CASR (* ((volatile uint32_t *) (0xE0081000 + 0x900)))

  // Boolean field: no description available
    static const uint32_t CAU_CAU_RADR_CASR_IC = 1U << 0 ;

  // Boolean field: no description available
    static const uint32_t CAU_CAU_RADR_CASR_DPE = 1U << 1 ;

  // Field (width: 4 bits): CAU version
    inline uint32_t CAU_CAU_RADR_CASR_VER (const uint32_t inValue) { return (inValue & 15U) << 28 ; }

//-------------------- Accumulator register - Reverse and Add to Register command
#define CAU_CAU_RADR_CAA (* ((volatile uint32_t *) (0xE0081000 + 0x904)))

//-------------------- General Purpose Register 0 - Reverse and Add to Register command
#define CAU_CAU_RADR_CA0 (* ((volatile uint32_t *) (0xE0081000 + 0x908)))

//-------------------- General Purpose Register 1 - Reverse and Add to Register command
#define CAU_CAU_RADR_CA1 (* ((volatile uint32_t *) (0xE0081000 + 0x90C)))

//-------------------- General Purpose Register 2 - Reverse and Add to Register command
#define CAU_CAU_RADR_CA2 (* ((volatile uint32_t *) (0xE0081000 + 0x910)))

//-------------------- General Purpose Register 3 - Reverse and Add to Register command
#define CAU_CAU_RADR_CA3 (* ((volatile uint32_t *) (0xE0081000 + 0x914)))

//-------------------- General Purpose Register 4 - Reverse and Add to Register command
#define CAU_CAU_RADR_CA4 (* ((volatile uint32_t *) (0xE0081000 + 0x918)))

//-------------------- General Purpose Register 5 - Reverse and Add to Register command
#define CAU_CAU_RADR_CA5 (* ((volatile uint32_t *) (0xE0081000 + 0x91C)))

//-------------------- General Purpose Register 6 - Reverse and Add to Register command
#define CAU_CAU_RADR_CA6 (* ((volatile uint32_t *) (0xE0081000 + 0x920)))

//-------------------- General Purpose Register 7 - Reverse and Add to Register command
#define CAU_CAU_RADR_CA7 (* ((volatile uint32_t *) (0xE0081000 + 0x924)))

//-------------------- General Purpose Register 8 - Reverse and Add to Register command
#define CAU_CAU_RADR_CA8 (* ((volatile uint32_t *) (0xE0081000 + 0x928)))

//-------------------- Status register - Exclusive Or command
#define CAU_CAU_XOR_CASR (* ((volatile uint32_t *) (0xE0081000 + 0x980)))

  // Boolean field: no description available
    static const uint32_t CAU_CAU_XOR_CASR_IC = 1U << 0 ;

  // Boolean field: no description available
    static const uint32_t CAU_CAU_XOR_CASR_DPE = 1U << 1 ;

  // Field (width: 4 bits): CAU version
    inline uint32_t CAU_CAU_XOR_CASR_VER (const uint32_t inValue) { return (inValue & 15U) << 28 ; }

//-------------------- Accumulator register - Exclusive Or command
#define CAU_CAU_XOR_CAA (* ((volatile uint32_t *) (0xE0081000 + 0x984)))

//-------------------- General Purpose Register 0 - Exclusive Or command
#define CAU_CAU_XOR_CA0 (* ((volatile uint32_t *) (0xE0081000 + 0x988)))

//-------------------- General Purpose Register 1 - Exclusive Or command
#define CAU_CAU_XOR_CA1 (* ((volatile uint32_t *) (0xE0081000 + 0x98C)))

//-------------------- General Purpose Register 2 - Exclusive Or command
#define CAU_CAU_XOR_CA2 (* ((volatile uint32_t *) (0xE0081000 + 0x990)))

//-------------------- General Purpose Register 3 - Exclusive Or command
#define CAU_CAU_XOR_CA3 (* ((volatile uint32_t *) (0xE0081000 + 0x994)))

//-------------------- General Purpose Register 4 - Exclusive Or command
#define CAU_CAU_XOR_CA4 (* ((volatile uint32_t *) (0xE0081000 + 0x998)))

//-------------------- General Purpose Register 5 - Exclusive Or command
#define CAU_CAU_XOR_CA5 (* ((volatile uint32_t *) (0xE0081000 + 0x99C)))

//-------------------- General Purpose Register 6 - Exclusive Or command
#define CAU_CAU_XOR_CA6 (* ((volatile uint32_t *) (0xE0081000 + 0x9A0)))

//-------------------- General Purpose Register 7 - Exclusive Or command
#define CAU_CAU_XOR_CA7 (* ((volatile uint32_t *) (0xE0081000 + 0x9A4)))

//-------------------- General Purpose Register 8 - Exclusive Or command
#define CAU_CAU_XOR_CA8 (* ((volatile uint32_t *) (0xE0081000 + 0x9A8)))

//-------------------- Status register - Rotate Left command
#define CAU_CAU_ROTL_CASR (* ((volatile uint32_t *) (0xE0081000 + 0x9C0)))

  // Boolean field: no description available
    static const uint32_t CAU_CAU_ROTL_CASR_IC = 1U << 0 ;

  // Boolean field: no description available
    static const uint32_t CAU_CAU_ROTL_CASR_DPE = 1U << 1 ;

  // Field (width: 4 bits): CAU version
    inline uint32_t CAU_CAU_ROTL_CASR_VER (const uint32_t inValue) { return (inValue & 15U) << 28 ; }

//-------------------- Accumulator register - Rotate Left command
#define CAU_CAU_ROTL_CAA (* ((volatile uint32_t *) (0xE0081000 + 0x9C4)))

//-------------------- General Purpose Register 0 - Rotate Left command
#define CAU_CAU_ROTL_CA0 (* ((volatile uint32_t *) (0xE0081000 + 0x9C8)))

//-------------------- General Purpose Register 1 - Rotate Left command
#define CAU_CAU_ROTL_CA1 (* ((volatile uint32_t *) (0xE0081000 + 0x9CC)))

//-------------------- General Purpose Register 2 - Rotate Left command
#define CAU_CAU_ROTL_CA2 (* ((volatile uint32_t *) (0xE0081000 + 0x9D0)))

//-------------------- General Purpose Register 3 - Rotate Left command
#define CAU_CAU_ROTL_CA3 (* ((volatile uint32_t *) (0xE0081000 + 0x9D4)))

//-------------------- General Purpose Register 4 - Rotate Left command
#define CAU_CAU_ROTL_CA4 (* ((volatile uint32_t *) (0xE0081000 + 0x9D8)))

//-------------------- General Purpose Register 5 - Rotate Left command
#define CAU_CAU_ROTL_CA5 (* ((volatile uint32_t *) (0xE0081000 + 0x9DC)))

//-------------------- General Purpose Register 6 - Rotate Left command
#define CAU_CAU_ROTL_CA6 (* ((volatile uint32_t *) (0xE0081000 + 0x9E0)))

//-------------------- General Purpose Register 7 - Rotate Left command
#define CAU_CAU_ROTL_CA7 (* ((volatile uint32_t *) (0xE0081000 + 0x9E4)))

//-------------------- General Purpose Register 8 - Rotate Left command
#define CAU_CAU_ROTL_CA8 (* ((volatile uint32_t *) (0xE0081000 + 0x9E8)))

//-------------------- Status register - AES Column Operation command
#define CAU_CAU_AESC_CASR (* ((volatile uint32_t *) (0xE0081000 + 0xB00)))

  // Boolean field: no description available
    static const uint32_t CAU_CAU_AESC_CASR_IC = 1U << 0 ;

  // Boolean field: no description available
    static const uint32_t CAU_CAU_AESC_CASR_DPE = 1U << 1 ;

  // Field (width: 4 bits): CAU version
    inline uint32_t CAU_CAU_AESC_CASR_VER (const uint32_t inValue) { return (inValue & 15U) << 28 ; }

//-------------------- Accumulator register - AES Column Operation command
#define CAU_CAU_AESC_CAA (* ((volatile uint32_t *) (0xE0081000 + 0xB04)))

//-------------------- General Purpose Register 0 - AES Column Operation command
#define CAU_CAU_AESC_CA0 (* ((volatile uint32_t *) (0xE0081000 + 0xB08)))

//-------------------- General Purpose Register 1 - AES Column Operation command
#define CAU_CAU_AESC_CA1 (* ((volatile uint32_t *) (0xE0081000 + 0xB0C)))

//-------------------- General Purpose Register 2 - AES Column Operation command
#define CAU_CAU_AESC_CA2 (* ((volatile uint32_t *) (0xE0081000 + 0xB10)))

//-------------------- General Purpose Register 3 - AES Column Operation command
#define CAU_CAU_AESC_CA3 (* ((volatile uint32_t *) (0xE0081000 + 0xB14)))

//-------------------- General Purpose Register 4 - AES Column Operation command
#define CAU_CAU_AESC_CA4 (* ((volatile uint32_t *) (0xE0081000 + 0xB18)))

//-------------------- General Purpose Register 5 - AES Column Operation command
#define CAU_CAU_AESC_CA5 (* ((volatile uint32_t *) (0xE0081000 + 0xB1C)))

//-------------------- General Purpose Register 6 - AES Column Operation command
#define CAU_CAU_AESC_CA6 (* ((volatile uint32_t *) (0xE0081000 + 0xB20)))

//-------------------- General Purpose Register 7 - AES Column Operation command
#define CAU_CAU_AESC_CA7 (* ((volatile uint32_t *) (0xE0081000 + 0xB24)))

//-------------------- General Purpose Register 8 - AES Column Operation command
#define CAU_CAU_AESC_CA8 (* ((volatile uint32_t *) (0xE0081000 + 0xB28)))

//-------------------- Status register - AES Inverse Column Operation command
#define CAU_CAU_AESIC_CASR (* ((volatile uint32_t *) (0xE0081000 + 0xB40)))

  // Boolean field: no description available
    static const uint32_t CAU_CAU_AESIC_CASR_IC = 1U << 0 ;

  // Boolean field: no description available
    static const uint32_t CAU_CAU_AESIC_CASR_DPE = 1U << 1 ;

  // Field (width: 4 bits): CAU version
    inline uint32_t CAU_CAU_AESIC_CASR_VER (const uint32_t inValue) { return (inValue & 15U) << 28 ; }

//-------------------- Accumulator register - AES Inverse Column Operation command
#define CAU_CAU_AESIC_CAA (* ((volatile uint32_t *) (0xE0081000 + 0xB44)))

//-------------------- General Purpose Register 0 - AES Inverse Column Operation command
#define CAU_CAU_AESIC_CA0 (* ((volatile uint32_t *) (0xE0081000 + 0xB48)))

//-------------------- General Purpose Register 1 - AES Inverse Column Operation command
#define CAU_CAU_AESIC_CA1 (* ((volatile uint32_t *) (0xE0081000 + 0xB4C)))

//-------------------- General Purpose Register 2 - AES Inverse Column Operation command
#define CAU_CAU_AESIC_CA2 (* ((volatile uint32_t *) (0xE0081000 + 0xB50)))

//-------------------- General Purpose Register 3 - AES Inverse Column Operation command
#define CAU_CAU_AESIC_CA3 (* ((volatile uint32_t *) (0xE0081000 + 0xB54)))

//-------------------- General Purpose Register 4 - AES Inverse Column Operation command
#define CAU_CAU_AESIC_CA4 (* ((volatile uint32_t *) (0xE0081000 + 0xB58)))

//-------------------- General Purpose Register 5 - AES Inverse Column Operation command
#define CAU_CAU_AESIC_CA5 (* ((volatile uint32_t *) (0xE0081000 + 0xB5C)))

//-------------------- General Purpose Register 6 - AES Inverse Column Operation command
#define CAU_CAU_AESIC_CA6 (* ((volatile uint32_t *) (0xE0081000 + 0xB60)))

//-------------------- General Purpose Register 7 - AES Inverse Column Operation command
#define CAU_CAU_AESIC_CA7 (* ((volatile uint32_t *) (0xE0081000 + 0xB64)))

//-------------------- General Purpose Register 8 - AES Inverse Column Operation command
#define CAU_CAU_AESIC_CA8 (* ((volatile uint32_t *) (0xE0081000 + 0xB68)))

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral LMEM
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Cache control register
#define LMEM_PCCCR (* ((volatile uint32_t *) (0xE0082000 + 0)))

  // Boolean field: Cache enable
    static const uint32_t LMEM_PCCCR_ENCACHE = 1U << 0 ;

  // Boolean field: Enable Write Buffer
    static const uint32_t LMEM_PCCCR_ENWRBUF = 1U << 1 ;

  // Boolean field: Forces all cacheable spaces to write through
    static const uint32_t LMEM_PCCCR_PCCR2 = 1U << 2 ;

  // Boolean field: Forces no allocation on cache misses (must also have PCCR2 asserted)
    static const uint32_t LMEM_PCCCR_PCCR3 = 1U << 3 ;

  // Boolean field: Invalidate Way 0
    static const uint32_t LMEM_PCCCR_INVW0 = 1U << 24 ;

  // Boolean field: Push Way 0
    static const uint32_t LMEM_PCCCR_PUSHW0 = 1U << 25 ;

  // Boolean field: Invalidate Way 1
    static const uint32_t LMEM_PCCCR_INVW1 = 1U << 26 ;

  // Boolean field: Push Way 1
    static const uint32_t LMEM_PCCCR_PUSHW1 = 1U << 27 ;

  // Boolean field: Initiate Cache Command
    static const uint32_t LMEM_PCCCR_GO = 1U << 31 ;

//-------------------- Cache line control register
#define LMEM_PCCLCR (* ((volatile uint32_t *) (0xE0082000 + 0x4)))

  // Boolean field: Initiate Cache Line Command
    static const uint32_t LMEM_PCCLCR_LGO = 1U << 0 ;

  // Field (width: 10 bits): Cache address
    inline uint32_t LMEM_PCCLCR_CACHEADDR (const uint32_t inValue) { return (inValue & 1023U) << 2 ; }

  // Boolean field: Way select
    static const uint32_t LMEM_PCCLCR_WSEL = 1U << 14 ;

  // Boolean field: Tag/Data Select
    static const uint32_t LMEM_PCCLCR_TDSEL = 1U << 16 ;

  // Boolean field: Line Command Initial Valid Bit
    static const uint32_t LMEM_PCCLCR_LCIVB = 1U << 20 ;

  // Boolean field: Line Command Initial Modified Bit
    static const uint32_t LMEM_PCCLCR_LCIMB = 1U << 21 ;

  // Boolean field: Line Command Way
    static const uint32_t LMEM_PCCLCR_LCWAY = 1U << 22 ;

  // Field (width: 2 bits): Line Command
    inline uint32_t LMEM_PCCLCR_LCMD (const uint32_t inValue) { return (inValue & 3U) << 24 ; }

  // Boolean field: Line Address Select
    static const uint32_t LMEM_PCCLCR_LADSEL = 1U << 26 ;

  // Boolean field: Line access type
    static const uint32_t LMEM_PCCLCR_LACC = 1U << 27 ;

//-------------------- Cache search address register
#define LMEM_PCCSAR (* ((volatile uint32_t *) (0xE0082000 + 0x8)))

  // Boolean field: Initiate Cache Line Command
    static const uint32_t LMEM_PCCSAR_LGO = 1U << 0 ;

  // Field (width: 30 bits): Physical Address
    inline uint32_t LMEM_PCCSAR_PHYADDR (const uint32_t inValue) { return (inValue & 1073741823U) << 2 ; }

//-------------------- Cache read/write value register
#define LMEM_PCCCVR (* ((volatile uint32_t *) (0xE0082000 + 0xC)))

//-------------------- Cache regions mode register
#define LMEM_PCCRMR (* ((volatile uint32_t *) (0xE0082000 + 0x20)))

  // Field (width: 2 bits): Region 15 mode
    inline uint32_t LMEM_PCCRMR_R15 (const uint32_t inValue) { return (inValue & 3U) << 0 ; }

  // Field (width: 2 bits): Region 14 mode
    inline uint32_t LMEM_PCCRMR_R14 (const uint32_t inValue) { return (inValue & 3U) << 2 ; }

  // Field (width: 2 bits): Region 13 mode
    inline uint32_t LMEM_PCCRMR_R13 (const uint32_t inValue) { return (inValue & 3U) << 4 ; }

  // Field (width: 2 bits): Region 12 mode
    inline uint32_t LMEM_PCCRMR_R12 (const uint32_t inValue) { return (inValue & 3U) << 6 ; }

  // Field (width: 2 bits): Region 11 mode
    inline uint32_t LMEM_PCCRMR_R11 (const uint32_t inValue) { return (inValue & 3U) << 8 ; }

  // Field (width: 2 bits): Region 10 mode
    inline uint32_t LMEM_PCCRMR_R10 (const uint32_t inValue) { return (inValue & 3U) << 10 ; }

  // Field (width: 2 bits): Region 9 mode
    inline uint32_t LMEM_PCCRMR_R9 (const uint32_t inValue) { return (inValue & 3U) << 12 ; }

  // Field (width: 2 bits): Region 8 mode
    inline uint32_t LMEM_PCCRMR_R8 (const uint32_t inValue) { return (inValue & 3U) << 14 ; }

  // Field (width: 2 bits): Region 7 mode
    inline uint32_t LMEM_PCCRMR_R7 (const uint32_t inValue) { return (inValue & 3U) << 16 ; }

  // Field (width: 2 bits): Region 6 mode
    inline uint32_t LMEM_PCCRMR_R6 (const uint32_t inValue) { return (inValue & 3U) << 18 ; }

  // Field (width: 2 bits): Region 5 mode
    inline uint32_t LMEM_PCCRMR_R5 (const uint32_t inValue) { return (inValue & 3U) << 20 ; }

  // Field (width: 2 bits): Region 4 mode
    inline uint32_t LMEM_PCCRMR_R4 (const uint32_t inValue) { return (inValue & 3U) << 22 ; }

  // Field (width: 2 bits): Region 3 mode
    inline uint32_t LMEM_PCCRMR_R3 (const uint32_t inValue) { return (inValue & 3U) << 24 ; }

  // Field (width: 2 bits): Region 2 mode
    inline uint32_t LMEM_PCCRMR_R2 (const uint32_t inValue) { return (inValue & 3U) << 26 ; }

  // Field (width: 2 bits): Region 1 mode
    inline uint32_t LMEM_PCCRMR_R1 (const uint32_t inValue) { return (inValue & 3U) << 28 ; }

  // Field (width: 2 bits): Region 0 mode
    inline uint32_t LMEM_PCCRMR_R0 (const uint32_t inValue) { return (inValue & 3U) << 30 ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral group ADC
//                ADC0 at 0x4003B000
//                ADC1 at 0x400BB000
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint32_t kBaseAddress_ADC [2] = {0x4003B000, 0x400BB000} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- ADC Minus-Side General Calibration Value Register
#define ADC_CLMD(group) (* ((volatile uint32_t *) (kBaseAddress_ADC [group] + 0x54)))
#define ADC0_CLMD (* ((volatile uint32_t *) (0x4003B000 + 0x54)))
#define ADC1_CLMD (* ((volatile uint32_t *) (0x400BB000 + 0x54)))

  // Field (width: 6 bits): Calibration Value
    inline uint32_t ADC_CLMD_CLMD (const uint32_t inValue) { return (inValue & 63U) << 0 ; }

//-------------------- ADC Configuration Register 2
#define ADC_CFG2(group) (* ((volatile uint32_t *) (kBaseAddress_ADC [group] + 0xC)))
#define ADC0_CFG2 (* ((volatile uint32_t *) (0x4003B000 + 0xC)))
#define ADC1_CFG2 (* ((volatile uint32_t *) (0x400BB000 + 0xC)))

  // Boolean field: ADC Mux Select
    static const uint32_t ADC_CFG2_MUXSEL = 1U << 4 ;

  // Field (width: 2 bits): Long Sample Time Select
    inline uint32_t ADC_CFG2_ADLSTS (const uint32_t inValue) { return (inValue & 3U) << 0 ; }

  // Boolean field: High-Speed Configuration
    static const uint32_t ADC_CFG2_ADHSC = 1U << 2 ;

  // Boolean field: Asynchronous Clock Output Enable
    static const uint32_t ADC_CFG2_ADACKEN = 1U << 3 ;

//-------------------- ADC Plus-Side General Calibration Value Register
#define ADC_CLPS(group) (* ((volatile uint32_t *) (kBaseAddress_ADC [group] + 0x38)))
#define ADC0_CLPS (* ((volatile uint32_t *) (0x4003B000 + 0x38)))
#define ADC1_CLPS (* ((volatile uint32_t *) (0x400BB000 + 0x38)))

  // Field (width: 6 bits): Calibration Value
    inline uint32_t ADC_CLPS_CLPS (const uint32_t inValue) { return (inValue & 63U) << 0 ; }

//-------------------- ADC Configuration Register 1
#define ADC_CFG1(group) (* ((volatile uint32_t *) (kBaseAddress_ADC [group] + 0x8)))
#define ADC0_CFG1 (* ((volatile uint32_t *) (0x4003B000 + 0x8)))
#define ADC1_CFG1 (* ((volatile uint32_t *) (0x400BB000 + 0x8)))

  // Boolean field: Sample Time Configuration
    static const uint32_t ADC_CFG1_ADLSMP = 1U << 4 ;

  // Field (width: 2 bits): Clock Divide Select
    inline uint32_t ADC_CFG1_ADIV (const uint32_t inValue) { return (inValue & 3U) << 5 ; }

  // Field (width: 2 bits): Conversion mode selection
    inline uint32_t ADC_CFG1_MODE (const uint32_t inValue) { return (inValue & 3U) << 2 ; }

  // Field (width: 2 bits): Input Clock Select
    inline uint32_t ADC_CFG1_ADICLK (const uint32_t inValue) { return (inValue & 3U) << 0 ; }

  // Boolean field: Low-Power Configuration
    static const uint32_t ADC_CFG1_ADLPC = 1U << 7 ;

//-------------------- ADC Minus-Side General Calibration Value Register
#define ADC_CLMS(group) (* ((volatile uint32_t *) (kBaseAddress_ADC [group] + 0x58)))
#define ADC0_CLMS (* ((volatile uint32_t *) (0x4003B000 + 0x58)))
#define ADC1_CLMS (* ((volatile uint32_t *) (0x400BB000 + 0x58)))

  // Field (width: 6 bits): Calibration Value
    inline uint32_t ADC_CLMS_CLMS (const uint32_t inValue) { return (inValue & 63U) << 0 ; }

//-------------------- ADC Plus-Side General Calibration Value Register
#define ADC_CLPD(group) (* ((volatile uint32_t *) (kBaseAddress_ADC [group] + 0x34)))
#define ADC0_CLPD (* ((volatile uint32_t *) (0x4003B000 + 0x34)))
#define ADC1_CLPD (* ((volatile uint32_t *) (0x400BB000 + 0x34)))

  // Field (width: 6 bits): Calibration Value
    inline uint32_t ADC_CLPD_CLPD (const uint32_t inValue) { return (inValue & 63U) << 0 ; }

//-------------------- ADC Status and Control Registers 1 (idx = 0 ... 1)
#define ADC_SC1(group,idx) (* ((volatile uint32_t *) (kBaseAddress_ADC [group] + 0 + 0x4 * (idx))))
#define ADC0_SC1(idx) (* ((volatile uint32_t *) (0x4003B000 + 0 + 0x4 * (idx))))
#define ADC1_SC1(idx) (* ((volatile uint32_t *) (0x400BB000 + 0 + 0x4 * (idx))))

  // Boolean field: Conversion Complete Flag
    static const uint32_t ADC_SC1_COCO = 1U << 7 ;

  // Boolean field: Differential Mode Enable
    static const uint32_t ADC_SC1_DIFF = 1U << 5 ;

  // Boolean field: Interrupt Enable
    static const uint32_t ADC_SC1_AIEN = 1U << 6 ;

  // Field (width: 5 bits): Input channel select
    inline uint32_t ADC_SC1_ADCH (const uint32_t inValue) { return (inValue & 31U) << 0 ; }

//-------------------- Compare Value Registers (idx = 0 ... 1)
#define ADC_CV(group,idx) (* ((volatile uint32_t *) (kBaseAddress_ADC [group] + 0x18 + 0x4 * (idx))))
#define ADC0_CV(idx) (* ((volatile uint32_t *) (0x4003B000 + 0x18 + 0x4 * (idx))))
#define ADC1_CV(idx) (* ((volatile uint32_t *) (0x400BB000 + 0x18 + 0x4 * (idx))))

  // Field (width: 16 bits): Compare Value.
    inline uint32_t ADC_CV_CV (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- ADC Plus-Side Gain Register
#define ADC_PG(group) (* ((volatile uint32_t *) (kBaseAddress_ADC [group] + 0x2C)))
#define ADC0_PG (* ((volatile uint32_t *) (0x4003B000 + 0x2C)))
#define ADC1_PG (* ((volatile uint32_t *) (0x400BB000 + 0x2C)))

  // Field (width: 16 bits): Plus-Side Gain
    inline uint32_t ADC_PG_PG (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- ADC Data Result Register (idx = 0 ... 1)
#define ADC_R(group,idx) (* ((const volatile uint32_t *) (kBaseAddress_ADC [group] + 0x10 + 0x4 * (idx))))
#define ADC0_R(idx) (* ((const volatile uint32_t *) (0x4003B000 + 0x10 + 0x4 * (idx))))
#define ADC1_R(idx) (* ((const volatile uint32_t *) (0x400BB000 + 0x10 + 0x4 * (idx))))

  // Field (width: 16 bits): Data result
    inline uint32_t ADC_R_D (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- ADC Offset Correction Register
#define ADC_OFS(group) (* ((volatile uint32_t *) (kBaseAddress_ADC [group] + 0x28)))
#define ADC0_OFS (* ((volatile uint32_t *) (0x4003B000 + 0x28)))
#define ADC1_OFS (* ((volatile uint32_t *) (0x400BB000 + 0x28)))

  // Field (width: 16 bits): Offset Error Correction Value
    inline uint32_t ADC_OFS_OFS (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Status and Control Register 3
#define ADC_SC3(group) (* ((volatile uint32_t *) (kBaseAddress_ADC [group] + 0x24)))
#define ADC0_SC3 (* ((volatile uint32_t *) (0x4003B000 + 0x24)))
#define ADC1_SC3 (* ((volatile uint32_t *) (0x400BB000 + 0x24)))

  // Boolean field: Hardware Average Enable
    static const uint32_t ADC_SC3_AVGE = 1U << 2 ;

  // Boolean field: Continuous Conversion Enable
    static const uint32_t ADC_SC3_ADCO = 1U << 3 ;

  // Boolean field: Calibration
    static const uint32_t ADC_SC3_CAL = 1U << 7 ;

  // Boolean field: Calibration Failed Flag
    static const uint32_t ADC_SC3_CALF = 1U << 6 ;

  // Field (width: 2 bits): Hardware Average Select
    inline uint32_t ADC_SC3_AVGS (const uint32_t inValue) { return (inValue & 3U) << 0 ; }

//-------------------- Status and Control Register 2
#define ADC_SC2(group) (* ((volatile uint32_t *) (kBaseAddress_ADC [group] + 0x20)))
#define ADC0_SC2 (* ((volatile uint32_t *) (0x4003B000 + 0x20)))
#define ADC1_SC2 (* ((volatile uint32_t *) (0x400BB000 + 0x20)))

  // Boolean field: DMA Enable
    static const uint32_t ADC_SC2_DMAEN = 1U << 2 ;

  // Field (width: 2 bits): Voltage Reference Selection
    inline uint32_t ADC_SC2_REFSEL (const uint32_t inValue) { return (inValue & 3U) << 0 ; }

  // Boolean field: Conversion Active
    static const uint32_t ADC_SC2_ADACT = 1U << 7 ;

  // Boolean field: Compare Function Greater Than Enable
    static const uint32_t ADC_SC2_ACFGT = 1U << 4 ;

  // Boolean field: Conversion Trigger Select
    static const uint32_t ADC_SC2_ADTRG = 1U << 6 ;

  // Boolean field: Compare Function Range Enable
    static const uint32_t ADC_SC2_ACREN = 1U << 3 ;

  // Boolean field: Compare Function Enable
    static const uint32_t ADC_SC2_ACFE = 1U << 5 ;

//-------------------- ADC Minus-Side Gain Register
#define ADC_MG(group) (* ((volatile uint32_t *) (kBaseAddress_ADC [group] + 0x30)))
#define ADC0_MG (* ((volatile uint32_t *) (0x4003B000 + 0x30)))
#define ADC1_MG (* ((volatile uint32_t *) (0x400BB000 + 0x30)))

  // Field (width: 16 bits): Minus-Side Gain
    inline uint32_t ADC_MG_MG (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- ADC Plus-Side General Calibration Value Register
#define ADC_CLP1(group) (* ((volatile uint32_t *) (kBaseAddress_ADC [group] + 0x48)))
#define ADC0_CLP1 (* ((volatile uint32_t *) (0x4003B000 + 0x48)))
#define ADC1_CLP1 (* ((volatile uint32_t *) (0x400BB000 + 0x48)))

  // Field (width: 7 bits): Calibration Value
    inline uint32_t ADC_CLP1_CLP1 (const uint32_t inValue) { return (inValue & 127U) << 0 ; }

//-------------------- ADC Plus-Side General Calibration Value Register
#define ADC_CLP0(group) (* ((volatile uint32_t *) (kBaseAddress_ADC [group] + 0x4C)))
#define ADC0_CLP0 (* ((volatile uint32_t *) (0x4003B000 + 0x4C)))
#define ADC1_CLP0 (* ((volatile uint32_t *) (0x400BB000 + 0x4C)))

  // Field (width: 6 bits): Calibration Value
    inline uint32_t ADC_CLP0_CLP0 (const uint32_t inValue) { return (inValue & 63U) << 0 ; }

//-------------------- ADC Plus-Side General Calibration Value Register
#define ADC_CLP3(group) (* ((volatile uint32_t *) (kBaseAddress_ADC [group] + 0x40)))
#define ADC0_CLP3 (* ((volatile uint32_t *) (0x4003B000 + 0x40)))
#define ADC1_CLP3 (* ((volatile uint32_t *) (0x400BB000 + 0x40)))

  // Field (width: 9 bits): Calibration Value
    inline uint32_t ADC_CLP3_CLP3 (const uint32_t inValue) { return (inValue & 511U) << 0 ; }

//-------------------- ADC Plus-Side General Calibration Value Register
#define ADC_CLP2(group) (* ((volatile uint32_t *) (kBaseAddress_ADC [group] + 0x44)))
#define ADC0_CLP2 (* ((volatile uint32_t *) (0x4003B000 + 0x44)))
#define ADC1_CLP2 (* ((volatile uint32_t *) (0x400BB000 + 0x44)))

  // Field (width: 8 bits): Calibration Value
    inline uint32_t ADC_CLP2_CLP2 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

//-------------------- ADC Plus-Side General Calibration Value Register
#define ADC_CLP4(group) (* ((volatile uint32_t *) (kBaseAddress_ADC [group] + 0x3C)))
#define ADC0_CLP4 (* ((volatile uint32_t *) (0x4003B000 + 0x3C)))
#define ADC1_CLP4 (* ((volatile uint32_t *) (0x400BB000 + 0x3C)))

  // Field (width: 10 bits): Calibration Value
    inline uint32_t ADC_CLP4_CLP4 (const uint32_t inValue) { return (inValue & 1023U) << 0 ; }

//-------------------- ADC Minus-Side General Calibration Value Register
#define ADC_CLM2(group) (* ((volatile uint32_t *) (kBaseAddress_ADC [group] + 0x64)))
#define ADC0_CLM2 (* ((volatile uint32_t *) (0x4003B000 + 0x64)))
#define ADC1_CLM2 (* ((volatile uint32_t *) (0x400BB000 + 0x64)))

  // Field (width: 8 bits): Calibration Value
    inline uint32_t ADC_CLM2_CLM2 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

//-------------------- ADC Minus-Side General Calibration Value Register
#define ADC_CLM3(group) (* ((volatile uint32_t *) (kBaseAddress_ADC [group] + 0x60)))
#define ADC0_CLM3 (* ((volatile uint32_t *) (0x4003B000 + 0x60)))
#define ADC1_CLM3 (* ((volatile uint32_t *) (0x400BB000 + 0x60)))

  // Field (width: 9 bits): Calibration Value
    inline uint32_t ADC_CLM3_CLM3 (const uint32_t inValue) { return (inValue & 511U) << 0 ; }

//-------------------- ADC Minus-Side General Calibration Value Register
#define ADC_CLM0(group) (* ((volatile uint32_t *) (kBaseAddress_ADC [group] + 0x6C)))
#define ADC0_CLM0 (* ((volatile uint32_t *) (0x4003B000 + 0x6C)))
#define ADC1_CLM0 (* ((volatile uint32_t *) (0x400BB000 + 0x6C)))

  // Field (width: 6 bits): Calibration Value
    inline uint32_t ADC_CLM0_CLM0 (const uint32_t inValue) { return (inValue & 63U) << 0 ; }

//-------------------- ADC Minus-Side General Calibration Value Register
#define ADC_CLM1(group) (* ((volatile uint32_t *) (kBaseAddress_ADC [group] + 0x68)))
#define ADC0_CLM1 (* ((volatile uint32_t *) (0x4003B000 + 0x68)))
#define ADC1_CLM1 (* ((volatile uint32_t *) (0x400BB000 + 0x68)))

  // Field (width: 7 bits): Calibration Value
    inline uint32_t ADC_CLM1_CLM1 (const uint32_t inValue) { return (inValue & 127U) << 0 ; }

//-------------------- ADC Minus-Side General Calibration Value Register
#define ADC_CLM4(group) (* ((volatile uint32_t *) (kBaseAddress_ADC [group] + 0x5C)))
#define ADC0_CLM4 (* ((volatile uint32_t *) (0x4003B000 + 0x5C)))
#define ADC1_CLM4 (* ((volatile uint32_t *) (0x400BB000 + 0x5C)))

  // Field (width: 10 bits): Calibration Value
    inline uint32_t ADC_CLM4_CLM4 (const uint32_t inValue) { return (inValue & 1023U) << 0 ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral group AIPS
//                AIPS0 at 0x40000000
//                AIPS1 at 0x40080000
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint32_t kBaseAddress_AIPS [2] = {0x40000000, 0x40080000} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Master Privilege Register A
#define AIPS_MPRA(group) (* ((volatile uint32_t *) (kBaseAddress_AIPS [group] + 0)))
#define AIPS0_MPRA (* ((volatile uint32_t *) (0x40000000 + 0)))
#define AIPS1_MPRA (* ((volatile uint32_t *) (0x40080000 + 0)))

  // Boolean field: Master 6 Privilege Level
    static const uint32_t AIPS_MPRA_MPL6 = 1U << 4 ;

  // Boolean field: Master 5 Privilege Level
    static const uint32_t AIPS_MPRA_MPL5 = 1U << 8 ;

  // Boolean field: Master 4 Privilege Level
    static const uint32_t AIPS_MPRA_MPL4 = 1U << 12 ;

  // Boolean field: Master 3 Privilege Level
    static const uint32_t AIPS_MPRA_MPL3 = 1U << 16 ;

  // Boolean field: Master 2 Privilege Level
    static const uint32_t AIPS_MPRA_MPL2 = 1U << 20 ;

  // Boolean field: Master 1 Privilege Level
    static const uint32_t AIPS_MPRA_MPL1 = 1U << 24 ;

  // Boolean field: Master 0 Privilege Level
    static const uint32_t AIPS_MPRA_MPL0 = 1U << 28 ;

  // Boolean field: Master 5 Trusted For Read
    static const uint32_t AIPS_MPRA_MTR5 = 1U << 10 ;

  // Boolean field: Master 4 Trusted For Read
    static const uint32_t AIPS_MPRA_MTR4 = 1U << 14 ;

  // Boolean field: Master 6 Trusted for Read
    static const uint32_t AIPS_MPRA_MTR6 = 1U << 6 ;

  // Boolean field: Master 1 Trusted for Read
    static const uint32_t AIPS_MPRA_MTR1 = 1U << 26 ;

  // Boolean field: Master 0 Trusted For Read
    static const uint32_t AIPS_MPRA_MTR0 = 1U << 30 ;

  // Boolean field: Master 3 Trusted For Read
    static const uint32_t AIPS_MPRA_MTR3 = 1U << 18 ;

  // Boolean field: Master 2 Trusted For Read
    static const uint32_t AIPS_MPRA_MTR2 = 1U << 22 ;

  // Boolean field: Master 6 Trusted for Writes
    static const uint32_t AIPS_MPRA_MTW6 = 1U << 5 ;

  // Boolean field: Master 4 Trusted For Writes
    static const uint32_t AIPS_MPRA_MTW4 = 1U << 13 ;

  // Boolean field: Master 5 Trusted For Writes
    static const uint32_t AIPS_MPRA_MTW5 = 1U << 9 ;

  // Boolean field: Master 2 Trusted For Writes
    static const uint32_t AIPS_MPRA_MTW2 = 1U << 21 ;

  // Boolean field: Master 3 Trusted For Writes
    static const uint32_t AIPS_MPRA_MTW3 = 1U << 17 ;

  // Boolean field: Master 0 Trusted For Writes
    static const uint32_t AIPS_MPRA_MTW0 = 1U << 29 ;

  // Boolean field: Master 1 Trusted for Writes
    static const uint32_t AIPS_MPRA_MTW1 = 1U << 25 ;

//-------------------- Peripheral Access Control Register
#define AIPS_PACRB(group) (* ((volatile uint32_t *) (kBaseAddress_AIPS [group] + 0x24)))
#define AIPS0_PACRB (* ((volatile uint32_t *) (0x40000000 + 0x24)))
#define AIPS1_PACRB (* ((volatile uint32_t *) (0x40080000 + 0x24)))

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRB_WP0 = 1U << 29 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRB_TP0 = 1U << 28 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRB_TP7 = 1U << 0 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRB_TP6 = 1U << 4 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRB_TP5 = 1U << 8 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRB_TP4 = 1U << 12 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRB_TP3 = 1U << 16 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRB_TP2 = 1U << 20 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRB_TP1 = 1U << 24 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRB_SP1 = 1U << 26 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRB_SP2 = 1U << 22 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRB_WP7 = 1U << 1 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRB_WP4 = 1U << 13 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRB_WP5 = 1U << 9 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRB_WP6 = 1U << 5 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRB_SP3 = 1U << 18 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRB_SP4 = 1U << 14 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRB_WP1 = 1U << 25 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRB_WP2 = 1U << 21 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRB_SP5 = 1U << 10 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRB_SP6 = 1U << 6 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRB_SP7 = 1U << 2 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRB_WP3 = 1U << 17 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRB_SP0 = 1U << 30 ;

//-------------------- Peripheral Access Control Register
#define AIPS_PACRA(group) (* ((volatile uint32_t *) (kBaseAddress_AIPS [group] + 0x20)))
#define AIPS0_PACRA (* ((volatile uint32_t *) (0x40000000 + 0x20)))
#define AIPS1_PACRA (* ((volatile uint32_t *) (0x40080000 + 0x20)))

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRA_WP0 = 1U << 29 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRA_TP0 = 1U << 28 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRA_TP7 = 1U << 0 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRA_TP6 = 1U << 4 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRA_TP5 = 1U << 8 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRA_TP4 = 1U << 12 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRA_TP3 = 1U << 16 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRA_TP2 = 1U << 20 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRA_TP1 = 1U << 24 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRA_SP1 = 1U << 26 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRA_SP2 = 1U << 22 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRA_WP7 = 1U << 1 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRA_WP4 = 1U << 13 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRA_WP5 = 1U << 9 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRA_WP6 = 1U << 5 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRA_SP3 = 1U << 18 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRA_SP4 = 1U << 14 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRA_WP1 = 1U << 25 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRA_WP2 = 1U << 21 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRA_SP5 = 1U << 10 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRA_SP6 = 1U << 6 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRA_SP7 = 1U << 2 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRA_WP3 = 1U << 17 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRA_SP0 = 1U << 30 ;

//-------------------- Peripheral Access Control Register
#define AIPS_PACRG(group) (* ((volatile uint32_t *) (kBaseAddress_AIPS [group] + 0x48)))
#define AIPS0_PACRG (* ((volatile uint32_t *) (0x40000000 + 0x48)))
#define AIPS1_PACRG (* ((volatile uint32_t *) (0x40080000 + 0x48)))

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRG_WP0 = 1U << 29 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRG_TP0 = 1U << 28 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRG_TP7 = 1U << 0 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRG_TP6 = 1U << 4 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRG_TP5 = 1U << 8 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRG_TP4 = 1U << 12 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRG_TP3 = 1U << 16 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRG_TP2 = 1U << 20 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRG_TP1 = 1U << 24 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRG_SP1 = 1U << 26 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRG_SP2 = 1U << 22 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRG_WP7 = 1U << 1 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRG_WP4 = 1U << 13 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRG_WP5 = 1U << 9 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRG_WP6 = 1U << 5 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRG_SP3 = 1U << 18 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRG_SP4 = 1U << 14 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRG_WP1 = 1U << 25 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRG_WP2 = 1U << 21 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRG_SP5 = 1U << 10 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRG_SP6 = 1U << 6 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRG_SP7 = 1U << 2 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRG_WP3 = 1U << 17 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRG_SP0 = 1U << 30 ;

//-------------------- Peripheral Access Control Register
#define AIPS_PACRF(group) (* ((volatile uint32_t *) (kBaseAddress_AIPS [group] + 0x44)))
#define AIPS0_PACRF (* ((volatile uint32_t *) (0x40000000 + 0x44)))
#define AIPS1_PACRF (* ((volatile uint32_t *) (0x40080000 + 0x44)))

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRF_WP0 = 1U << 29 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRF_TP0 = 1U << 28 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRF_TP7 = 1U << 0 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRF_TP6 = 1U << 4 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRF_TP5 = 1U << 8 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRF_TP4 = 1U << 12 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRF_TP3 = 1U << 16 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRF_TP2 = 1U << 20 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRF_TP1 = 1U << 24 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRF_SP1 = 1U << 26 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRF_SP2 = 1U << 22 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRF_WP7 = 1U << 1 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRF_WP4 = 1U << 13 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRF_WP5 = 1U << 9 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRF_WP6 = 1U << 5 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRF_SP3 = 1U << 18 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRF_SP4 = 1U << 14 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRF_WP1 = 1U << 25 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRF_WP2 = 1U << 21 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRF_SP5 = 1U << 10 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRF_SP6 = 1U << 6 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRF_SP7 = 1U << 2 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRF_WP3 = 1U << 17 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRF_SP0 = 1U << 30 ;

//-------------------- Peripheral Access Control Register
#define AIPS_PACRE(group) (* ((volatile uint32_t *) (kBaseAddress_AIPS [group] + 0x40)))
#define AIPS0_PACRE (* ((volatile uint32_t *) (0x40000000 + 0x40)))
#define AIPS1_PACRE (* ((volatile uint32_t *) (0x40080000 + 0x40)))

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRE_WP0 = 1U << 29 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRE_TP0 = 1U << 28 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRE_TP7 = 1U << 0 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRE_TP6 = 1U << 4 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRE_TP5 = 1U << 8 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRE_TP4 = 1U << 12 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRE_TP3 = 1U << 16 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRE_TP2 = 1U << 20 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRE_TP1 = 1U << 24 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRE_SP1 = 1U << 26 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRE_SP2 = 1U << 22 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRE_WP7 = 1U << 1 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRE_WP4 = 1U << 13 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRE_WP5 = 1U << 9 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRE_WP6 = 1U << 5 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRE_SP3 = 1U << 18 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRE_SP4 = 1U << 14 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRE_WP1 = 1U << 25 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRE_WP2 = 1U << 21 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRE_SP5 = 1U << 10 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRE_SP6 = 1U << 6 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRE_SP7 = 1U << 2 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRE_WP3 = 1U << 17 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRE_SP0 = 1U << 30 ;

//-------------------- Peripheral Access Control Register
#define AIPS_PACRD(group) (* ((volatile uint32_t *) (kBaseAddress_AIPS [group] + 0x2C)))
#define AIPS0_PACRD (* ((volatile uint32_t *) (0x40000000 + 0x2C)))
#define AIPS1_PACRD (* ((volatile uint32_t *) (0x40080000 + 0x2C)))

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRD_WP0 = 1U << 29 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRD_TP0 = 1U << 28 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRD_TP7 = 1U << 0 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRD_TP6 = 1U << 4 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRD_TP5 = 1U << 8 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRD_TP4 = 1U << 12 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRD_TP3 = 1U << 16 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRD_TP2 = 1U << 20 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRD_TP1 = 1U << 24 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRD_SP1 = 1U << 26 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRD_SP2 = 1U << 22 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRD_WP7 = 1U << 1 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRD_WP4 = 1U << 13 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRD_WP5 = 1U << 9 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRD_WP6 = 1U << 5 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRD_SP3 = 1U << 18 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRD_SP4 = 1U << 14 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRD_WP1 = 1U << 25 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRD_WP2 = 1U << 21 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRD_SP5 = 1U << 10 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRD_SP6 = 1U << 6 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRD_SP7 = 1U << 2 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRD_WP3 = 1U << 17 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRD_SP0 = 1U << 30 ;

//-------------------- Peripheral Access Control Register
#define AIPS_PACRK(group) (* ((volatile uint32_t *) (kBaseAddress_AIPS [group] + 0x58)))
#define AIPS0_PACRK (* ((volatile uint32_t *) (0x40000000 + 0x58)))
#define AIPS1_PACRK (* ((volatile uint32_t *) (0x40080000 + 0x58)))

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRK_WP0 = 1U << 29 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRK_TP0 = 1U << 28 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRK_TP7 = 1U << 0 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRK_TP6 = 1U << 4 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRK_TP5 = 1U << 8 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRK_TP4 = 1U << 12 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRK_TP3 = 1U << 16 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRK_TP2 = 1U << 20 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRK_TP1 = 1U << 24 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRK_SP1 = 1U << 26 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRK_SP2 = 1U << 22 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRK_WP7 = 1U << 1 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRK_WP4 = 1U << 13 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRK_WP5 = 1U << 9 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRK_WP6 = 1U << 5 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRK_SP3 = 1U << 18 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRK_SP4 = 1U << 14 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRK_WP1 = 1U << 25 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRK_WP2 = 1U << 21 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRK_SP5 = 1U << 10 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRK_SP6 = 1U << 6 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRK_SP7 = 1U << 2 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRK_WP3 = 1U << 17 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRK_SP0 = 1U << 30 ;

//-------------------- Peripheral Access Control Register
#define AIPS_PACRJ(group) (* ((volatile uint32_t *) (kBaseAddress_AIPS [group] + 0x54)))
#define AIPS0_PACRJ (* ((volatile uint32_t *) (0x40000000 + 0x54)))
#define AIPS1_PACRJ (* ((volatile uint32_t *) (0x40080000 + 0x54)))

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRJ_WP0 = 1U << 29 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRJ_TP0 = 1U << 28 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRJ_TP7 = 1U << 0 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRJ_TP6 = 1U << 4 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRJ_TP5 = 1U << 8 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRJ_TP4 = 1U << 12 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRJ_TP3 = 1U << 16 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRJ_TP2 = 1U << 20 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRJ_TP1 = 1U << 24 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRJ_SP1 = 1U << 26 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRJ_SP2 = 1U << 22 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRJ_WP7 = 1U << 1 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRJ_WP4 = 1U << 13 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRJ_WP5 = 1U << 9 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRJ_WP6 = 1U << 5 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRJ_SP3 = 1U << 18 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRJ_SP4 = 1U << 14 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRJ_WP1 = 1U << 25 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRJ_WP2 = 1U << 21 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRJ_SP5 = 1U << 10 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRJ_SP6 = 1U << 6 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRJ_SP7 = 1U << 2 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRJ_WP3 = 1U << 17 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRJ_SP0 = 1U << 30 ;

//-------------------- Peripheral Access Control Register
#define AIPS_PACRI(group) (* ((volatile uint32_t *) (kBaseAddress_AIPS [group] + 0x50)))
#define AIPS0_PACRI (* ((volatile uint32_t *) (0x40000000 + 0x50)))
#define AIPS1_PACRI (* ((volatile uint32_t *) (0x40080000 + 0x50)))

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRI_WP0 = 1U << 29 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRI_TP0 = 1U << 28 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRI_TP7 = 1U << 0 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRI_TP6 = 1U << 4 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRI_TP5 = 1U << 8 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRI_TP4 = 1U << 12 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRI_TP3 = 1U << 16 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRI_TP2 = 1U << 20 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRI_TP1 = 1U << 24 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRI_SP1 = 1U << 26 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRI_SP2 = 1U << 22 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRI_WP7 = 1U << 1 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRI_WP4 = 1U << 13 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRI_WP5 = 1U << 9 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRI_WP6 = 1U << 5 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRI_SP3 = 1U << 18 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRI_SP4 = 1U << 14 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRI_WP1 = 1U << 25 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRI_WP2 = 1U << 21 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRI_SP5 = 1U << 10 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRI_SP6 = 1U << 6 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRI_SP7 = 1U << 2 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRI_WP3 = 1U << 17 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRI_SP0 = 1U << 30 ;

//-------------------- Peripheral Access Control Register
#define AIPS_PACRH(group) (* ((volatile uint32_t *) (kBaseAddress_AIPS [group] + 0x4C)))
#define AIPS0_PACRH (* ((volatile uint32_t *) (0x40000000 + 0x4C)))
#define AIPS1_PACRH (* ((volatile uint32_t *) (0x40080000 + 0x4C)))

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRH_WP0 = 1U << 29 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRH_TP0 = 1U << 28 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRH_TP7 = 1U << 0 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRH_TP6 = 1U << 4 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRH_TP5 = 1U << 8 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRH_TP4 = 1U << 12 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRH_TP3 = 1U << 16 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRH_TP2 = 1U << 20 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRH_TP1 = 1U << 24 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRH_SP1 = 1U << 26 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRH_SP2 = 1U << 22 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRH_WP7 = 1U << 1 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRH_WP4 = 1U << 13 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRH_WP5 = 1U << 9 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRH_WP6 = 1U << 5 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRH_SP3 = 1U << 18 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRH_SP4 = 1U << 14 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRH_WP1 = 1U << 25 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRH_WP2 = 1U << 21 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRH_SP5 = 1U << 10 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRH_SP6 = 1U << 6 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRH_SP7 = 1U << 2 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRH_WP3 = 1U << 17 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRH_SP0 = 1U << 30 ;

//-------------------- Peripheral Access Control Register
#define AIPS_PACRO(group) (* ((volatile uint32_t *) (kBaseAddress_AIPS [group] + 0x68)))
#define AIPS0_PACRO (* ((volatile uint32_t *) (0x40000000 + 0x68)))
#define AIPS1_PACRO (* ((volatile uint32_t *) (0x40080000 + 0x68)))

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRO_WP0 = 1U << 29 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRO_TP0 = 1U << 28 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRO_TP7 = 1U << 0 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRO_TP6 = 1U << 4 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRO_TP5 = 1U << 8 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRO_TP4 = 1U << 12 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRO_TP3 = 1U << 16 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRO_TP2 = 1U << 20 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRO_TP1 = 1U << 24 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRO_SP1 = 1U << 26 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRO_SP2 = 1U << 22 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRO_WP7 = 1U << 1 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRO_WP4 = 1U << 13 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRO_WP5 = 1U << 9 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRO_WP6 = 1U << 5 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRO_SP3 = 1U << 18 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRO_SP4 = 1U << 14 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRO_WP1 = 1U << 25 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRO_WP2 = 1U << 21 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRO_SP5 = 1U << 10 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRO_SP6 = 1U << 6 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRO_SP7 = 1U << 2 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRO_WP3 = 1U << 17 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRO_SP0 = 1U << 30 ;

//-------------------- Peripheral Access Control Register
#define AIPS_PACRN(group) (* ((volatile uint32_t *) (kBaseAddress_AIPS [group] + 0x64)))
#define AIPS0_PACRN (* ((volatile uint32_t *) (0x40000000 + 0x64)))
#define AIPS1_PACRN (* ((volatile uint32_t *) (0x40080000 + 0x64)))

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRN_WP0 = 1U << 29 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRN_TP0 = 1U << 28 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRN_TP7 = 1U << 0 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRN_TP6 = 1U << 4 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRN_TP5 = 1U << 8 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRN_TP4 = 1U << 12 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRN_TP3 = 1U << 16 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRN_TP2 = 1U << 20 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRN_TP1 = 1U << 24 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRN_SP1 = 1U << 26 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRN_SP2 = 1U << 22 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRN_WP7 = 1U << 1 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRN_WP4 = 1U << 13 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRN_WP5 = 1U << 9 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRN_WP6 = 1U << 5 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRN_SP3 = 1U << 18 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRN_SP4 = 1U << 14 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRN_WP1 = 1U << 25 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRN_WP2 = 1U << 21 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRN_SP5 = 1U << 10 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRN_SP6 = 1U << 6 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRN_SP7 = 1U << 2 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRN_WP3 = 1U << 17 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRN_SP0 = 1U << 30 ;

//-------------------- Peripheral Access Control Register
#define AIPS_PACRM(group) (* ((volatile uint32_t *) (kBaseAddress_AIPS [group] + 0x60)))
#define AIPS0_PACRM (* ((volatile uint32_t *) (0x40000000 + 0x60)))
#define AIPS1_PACRM (* ((volatile uint32_t *) (0x40080000 + 0x60)))

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRM_WP0 = 1U << 29 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRM_TP0 = 1U << 28 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRM_TP7 = 1U << 0 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRM_TP6 = 1U << 4 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRM_TP5 = 1U << 8 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRM_TP4 = 1U << 12 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRM_TP3 = 1U << 16 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRM_TP2 = 1U << 20 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRM_TP1 = 1U << 24 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRM_SP1 = 1U << 26 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRM_SP2 = 1U << 22 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRM_WP7 = 1U << 1 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRM_WP4 = 1U << 13 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRM_WP5 = 1U << 9 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRM_WP6 = 1U << 5 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRM_SP3 = 1U << 18 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRM_SP4 = 1U << 14 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRM_WP1 = 1U << 25 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRM_WP2 = 1U << 21 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRM_SP5 = 1U << 10 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRM_SP6 = 1U << 6 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRM_SP7 = 1U << 2 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRM_WP3 = 1U << 17 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRM_SP0 = 1U << 30 ;

//-------------------- Peripheral Access Control Register
#define AIPS_PACRL(group) (* ((volatile uint32_t *) (kBaseAddress_AIPS [group] + 0x5C)))
#define AIPS0_PACRL (* ((volatile uint32_t *) (0x40000000 + 0x5C)))
#define AIPS1_PACRL (* ((volatile uint32_t *) (0x40080000 + 0x5C)))

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRL_WP0 = 1U << 29 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRL_TP0 = 1U << 28 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRL_TP7 = 1U << 0 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRL_TP6 = 1U << 4 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRL_TP5 = 1U << 8 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRL_TP4 = 1U << 12 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRL_TP3 = 1U << 16 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRL_TP2 = 1U << 20 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRL_TP1 = 1U << 24 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRL_SP1 = 1U << 26 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRL_SP2 = 1U << 22 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRL_WP7 = 1U << 1 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRL_WP4 = 1U << 13 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRL_WP5 = 1U << 9 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRL_WP6 = 1U << 5 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRL_SP3 = 1U << 18 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRL_SP4 = 1U << 14 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRL_WP1 = 1U << 25 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRL_WP2 = 1U << 21 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRL_SP5 = 1U << 10 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRL_SP6 = 1U << 6 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRL_SP7 = 1U << 2 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRL_WP3 = 1U << 17 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRL_SP0 = 1U << 30 ;

//-------------------- Peripheral Access Control Register
#define AIPS_PACRP(group) (* ((volatile uint32_t *) (kBaseAddress_AIPS [group] + 0x6C)))
#define AIPS0_PACRP (* ((volatile uint32_t *) (0x40000000 + 0x6C)))
#define AIPS1_PACRP (* ((volatile uint32_t *) (0x40080000 + 0x6C)))

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRP_WP0 = 1U << 29 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRP_TP0 = 1U << 28 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRP_TP7 = 1U << 0 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRP_TP6 = 1U << 4 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRP_TP5 = 1U << 8 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRP_TP4 = 1U << 12 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRP_TP3 = 1U << 16 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRP_TP2 = 1U << 20 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRP_TP1 = 1U << 24 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRP_SP1 = 1U << 26 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRP_SP2 = 1U << 22 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRP_WP7 = 1U << 1 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRP_WP4 = 1U << 13 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRP_WP5 = 1U << 9 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRP_WP6 = 1U << 5 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRP_SP3 = 1U << 18 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRP_SP4 = 1U << 14 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRP_WP1 = 1U << 25 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRP_WP2 = 1U << 21 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRP_SP5 = 1U << 10 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRP_SP6 = 1U << 6 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRP_SP7 = 1U << 2 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRP_WP3 = 1U << 17 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRP_SP0 = 1U << 30 ;

//-------------------- Peripheral Access Control Register
#define AIPS_PACRC(group) (* ((volatile uint32_t *) (kBaseAddress_AIPS [group] + 0x28)))
#define AIPS0_PACRC (* ((volatile uint32_t *) (0x40000000 + 0x28)))
#define AIPS1_PACRC (* ((volatile uint32_t *) (0x40080000 + 0x28)))

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRC_WP0 = 1U << 29 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRC_TP0 = 1U << 28 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRC_TP7 = 1U << 0 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRC_TP6 = 1U << 4 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRC_TP5 = 1U << 8 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRC_TP4 = 1U << 12 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRC_TP3 = 1U << 16 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRC_TP2 = 1U << 20 ;

  // Boolean field: Trusted Protect
    static const uint32_t AIPS_PACRC_TP1 = 1U << 24 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRC_SP1 = 1U << 26 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRC_SP2 = 1U << 22 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRC_WP7 = 1U << 1 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRC_WP4 = 1U << 13 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRC_WP5 = 1U << 9 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRC_WP6 = 1U << 5 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRC_SP3 = 1U << 18 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRC_SP4 = 1U << 14 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRC_WP1 = 1U << 25 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRC_WP2 = 1U << 21 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRC_SP5 = 1U << 10 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRC_SP6 = 1U << 6 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRC_SP7 = 1U << 2 ;

  // Boolean field: Write Protect
    static const uint32_t AIPS_PACRC_WP3 = 1U << 17 ;

  // Boolean field: Supervisor Protect
    static const uint32_t AIPS_PACRC_SP0 = 1U << 30 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral group CAN
//                CAN0 at 0x40024000
//                CAN1 at 0x400A4000
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint32_t kBaseAddress_CAN [2] = {0x40024000, 0x400A4000} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Message Buffer 5 WORD1 Register
#define CAN_WORD15(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xDC)))
#define CAN0_WORD15 (* ((volatile uint32_t *) (0x40024000 + 0xDC)))
#define CAN1_WORD15 (* ((volatile uint32_t *) (0x400A4000 + 0xDC)))

  // Field (width: 8 bits): Data byte 7 of Rx/Tx frame.
    inline uint32_t CAN_WORD15_DATA_BYTE_7 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 6 of Rx/Tx frame.
    inline uint32_t CAN_WORD15_DATA_BYTE_6 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 5 of Rx/Tx frame.
    inline uint32_t CAN_WORD15_DATA_BYTE_5 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 4 of Rx/Tx frame.
    inline uint32_t CAN_WORD15_DATA_BYTE_4 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 4 WORD1 Register
#define CAN_WORD14(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xCC)))
#define CAN0_WORD14 (* ((volatile uint32_t *) (0x40024000 + 0xCC)))
#define CAN1_WORD14 (* ((volatile uint32_t *) (0x400A4000 + 0xCC)))

  // Field (width: 8 bits): Data byte 7 of Rx/Tx frame.
    inline uint32_t CAN_WORD14_DATA_BYTE_7 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 6 of Rx/Tx frame.
    inline uint32_t CAN_WORD14_DATA_BYTE_6 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 5 of Rx/Tx frame.
    inline uint32_t CAN_WORD14_DATA_BYTE_5 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 4 of Rx/Tx frame.
    inline uint32_t CAN_WORD14_DATA_BYTE_4 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 7 WORD1 Register
#define CAN_WORD17(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xFC)))
#define CAN0_WORD17 (* ((volatile uint32_t *) (0x40024000 + 0xFC)))
#define CAN1_WORD17 (* ((volatile uint32_t *) (0x400A4000 + 0xFC)))

  // Field (width: 8 bits): Data byte 7 of Rx/Tx frame.
    inline uint32_t CAN_WORD17_DATA_BYTE_7 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 6 of Rx/Tx frame.
    inline uint32_t CAN_WORD17_DATA_BYTE_6 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 5 of Rx/Tx frame.
    inline uint32_t CAN_WORD17_DATA_BYTE_5 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 4 of Rx/Tx frame.
    inline uint32_t CAN_WORD17_DATA_BYTE_4 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 5 ID Register
#define CAN_ID5(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xD4)))
#define CAN0_ID5 (* ((volatile uint32_t *) (0x40024000 + 0xD4)))
#define CAN1_ID5 (* ((volatile uint32_t *) (0x400A4000 + 0xD4)))

  // Field (width: 11 bits): Contains standard/extended (HIGH word) identifier of message buffer.
    inline uint32_t CAN_ID5_STD (const uint32_t inValue) { return (inValue & 2047U) << 18 ; }

  // Field (width: 18 bits): Contains extended (LOW word) identifier of message buffer.
    inline uint32_t CAN_ID5_EXT (const uint32_t inValue) { return (inValue & 262143U) << 0 ; }

  // Field (width: 3 bits): Local priority. This 3-bit fieldis only used when LPRIO_EN bit is set in MCR and it only makes sense for Tx buffers. These bits are not transmitted. They are appended to the regular ID to define the transmission priority.
    inline uint32_t CAN_ID5_PRIO (const uint32_t inValue) { return (inValue & 7U) << 29 ; }

//-------------------- Message Buffer 1 WORD1 Register
#define CAN_WORD11(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x9C)))
#define CAN0_WORD11 (* ((volatile uint32_t *) (0x40024000 + 0x9C)))
#define CAN1_WORD11 (* ((volatile uint32_t *) (0x400A4000 + 0x9C)))

  // Field (width: 8 bits): Data byte 7 of Rx/Tx frame.
    inline uint32_t CAN_WORD11_DATA_BYTE_7 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 6 of Rx/Tx frame.
    inline uint32_t CAN_WORD11_DATA_BYTE_6 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 5 of Rx/Tx frame.
    inline uint32_t CAN_WORD11_DATA_BYTE_5 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 4 of Rx/Tx frame.
    inline uint32_t CAN_WORD11_DATA_BYTE_4 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 0 WORD1 Register
#define CAN_WORD10(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x8C)))
#define CAN0_WORD10 (* ((volatile uint32_t *) (0x40024000 + 0x8C)))
#define CAN1_WORD10 (* ((volatile uint32_t *) (0x400A4000 + 0x8C)))

  // Field (width: 8 bits): Data byte 7 of Rx/Tx frame.
    inline uint32_t CAN_WORD10_DATA_BYTE_7 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 6 of Rx/Tx frame.
    inline uint32_t CAN_WORD10_DATA_BYTE_6 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 5 of Rx/Tx frame.
    inline uint32_t CAN_WORD10_DATA_BYTE_5 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 4 of Rx/Tx frame.
    inline uint32_t CAN_WORD10_DATA_BYTE_4 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 3 WORD1 Register
#define CAN_WORD13(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xBC)))
#define CAN0_WORD13 (* ((volatile uint32_t *) (0x40024000 + 0xBC)))
#define CAN1_WORD13 (* ((volatile uint32_t *) (0x400A4000 + 0xBC)))

  // Field (width: 8 bits): Data byte 7 of Rx/Tx frame.
    inline uint32_t CAN_WORD13_DATA_BYTE_7 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 6 of Rx/Tx frame.
    inline uint32_t CAN_WORD13_DATA_BYTE_6 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 5 of Rx/Tx frame.
    inline uint32_t CAN_WORD13_DATA_BYTE_5 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 4 of Rx/Tx frame.
    inline uint32_t CAN_WORD13_DATA_BYTE_4 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 2 WORD1 Register
#define CAN_WORD12(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xAC)))
#define CAN0_WORD12 (* ((volatile uint32_t *) (0x40024000 + 0xAC)))
#define CAN1_WORD12 (* ((volatile uint32_t *) (0x400A4000 + 0xAC)))

  // Field (width: 8 bits): Data byte 7 of Rx/Tx frame.
    inline uint32_t CAN_WORD12_DATA_BYTE_7 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 6 of Rx/Tx frame.
    inline uint32_t CAN_WORD12_DATA_BYTE_6 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 5 of Rx/Tx frame.
    inline uint32_t CAN_WORD12_DATA_BYTE_5 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 4 of Rx/Tx frame.
    inline uint32_t CAN_WORD12_DATA_BYTE_4 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Module Configuration Register
#define CAN_MCR(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0)))
#define CAN0_MCR (* ((volatile uint32_t *) (0x40024000 + 0)))
#define CAN1_MCR (* ((volatile uint32_t *) (0x400A4000 + 0)))

  // Boolean field: Halt FlexCAN
    static const uint32_t CAN_MCR_HALT = 1U << 28 ;

  // Boolean field: Soft Reset
    static const uint32_t CAN_MCR_SOFTRST = 1U << 25 ;

  // Boolean field: Wake Up Source
    static const uint32_t CAN_MCR_WAKSRC = 1U << 19 ;

  // Boolean field: Warning Interrupt Enable
    static const uint32_t CAN_MCR_WRNEN = 1U << 21 ;

  // Boolean field: Freeze Mode Acknowledge
    static const uint32_t CAN_MCR_FRZACK = 1U << 24 ;

  // Boolean field: Local Priority Enable
    static const uint32_t CAN_MCR_LPRIOEN = 1U << 13 ;

  // Boolean field: Self Wake Up
    static const uint32_t CAN_MCR_SLFWAK = 1U << 22 ;

  // Boolean field: Supervisor Mode
    static const uint32_t CAN_MCR_SUPV = 1U << 23 ;

  // Boolean field: Freeze Enable
    static const uint32_t CAN_MCR_FRZ = 1U << 30 ;

  // Boolean field: Low-Power Mode Acknowledge
    static const uint32_t CAN_MCR_LPMACK = 1U << 20 ;

  // Boolean field: Rx FIFO Enable
    static const uint32_t CAN_MCR_RFEN = 1U << 29 ;

  // Boolean field: Individual Rx Masking And Queue Enable
    static const uint32_t CAN_MCR_IRMQ = 1U << 16 ;

  // Boolean field: FlexCAN Not Ready
    static const uint32_t CAN_MCR_NOTRDY = 1U << 27 ;

  // Boolean field: Self Reception Disable
    static const uint32_t CAN_MCR_SRXDIS = 1U << 17 ;

  // Boolean field: Module Disable
    static const uint32_t CAN_MCR_MDIS = 1U << 31 ;

  // Boolean field: Wake Up Interrupt Mask
    static const uint32_t CAN_MCR_WAKMSK = 1U << 26 ;

  // Field (width: 2 bits): ID Acceptance Mode
    inline uint32_t CAN_MCR_IDAM (const uint32_t inValue) { return (inValue & 3U) << 8 ; }

  // Field (width: 7 bits): Number Of The Last Message Buffer
    inline uint32_t CAN_MCR_MAXMB (const uint32_t inValue) { return (inValue & 127U) << 0 ; }

  // Boolean field: Abort Enable
    static const uint32_t CAN_MCR_AEN = 1U << 12 ;

//-------------------- Message Buffer 9 WORD1 Register
#define CAN_WORD19(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x11C)))
#define CAN0_WORD19 (* ((volatile uint32_t *) (0x40024000 + 0x11C)))
#define CAN1_WORD19 (* ((volatile uint32_t *) (0x400A4000 + 0x11C)))

  // Field (width: 8 bits): Data byte 7 of Rx/Tx frame.
    inline uint32_t CAN_WORD19_DATA_BYTE_7 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 6 of Rx/Tx frame.
    inline uint32_t CAN_WORD19_DATA_BYTE_6 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 5 of Rx/Tx frame.
    inline uint32_t CAN_WORD19_DATA_BYTE_5 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 4 of Rx/Tx frame.
    inline uint32_t CAN_WORD19_DATA_BYTE_4 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 8 WORD1 Register
#define CAN_WORD18(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x10C)))
#define CAN0_WORD18 (* ((volatile uint32_t *) (0x40024000 + 0x10C)))
#define CAN1_WORD18 (* ((volatile uint32_t *) (0x400A4000 + 0x10C)))

  // Field (width: 8 bits): Data byte 7 of Rx/Tx frame.
    inline uint32_t CAN_WORD18_DATA_BYTE_7 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 6 of Rx/Tx frame.
    inline uint32_t CAN_WORD18_DATA_BYTE_6 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 5 of Rx/Tx frame.
    inline uint32_t CAN_WORD18_DATA_BYTE_5 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 4 of Rx/Tx frame.
    inline uint32_t CAN_WORD18_DATA_BYTE_4 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Rx FIFO Information Register
#define CAN_RXFIR(group) (* ((const volatile uint32_t *) (kBaseAddress_CAN [group] + 0x4C)))
#define CAN0_RXFIR (* ((const volatile uint32_t *) (0x40024000 + 0x4C)))
#define CAN1_RXFIR (* ((const volatile uint32_t *) (0x400A4000 + 0x4C)))

  // Field (width: 9 bits): Identifier Acceptance Filter Hit Indicator
    inline uint32_t CAN_RXFIR_IDHIT (const uint32_t inValue) { return (inValue & 511U) << 0 ; }

//-------------------- Message Buffer 8 CS Register
#define CAN_CS8(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x100)))
#define CAN0_CS8 (* ((volatile uint32_t *) (0x40024000 + 0x100)))
#define CAN1_CS8 (* ((volatile uint32_t *) (0x400A4000 + 0x100)))

  // Field (width: 4 bits): Length of the data to be stored/transmitted.
    inline uint32_t CAN_CS8_DLC (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 4 bits): Reserved
    inline uint32_t CAN_CS8_CODE (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Boolean field: Substitute Remote Request. Contains a fixed recessive bit.
    static const uint32_t CAN_CS8_SRR = 1U << 22 ;

  // Boolean field: Remote Transmission Request. One/zero for remote/data frame.
    static const uint32_t CAN_CS8_RTR = 1U << 20 ;

  // Field (width: 16 bits): Free-Running Counter Time stamp. This 16-bit field is a copy of the Free-Running Timer, captured for Tx and Rx frames at the time when the beginning of the Identifier field appears on the CAN bus.
    inline uint32_t CAN_CS8_TIME_STAMP (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Boolean field: ID Extended. One/zero for extended/standard format frame.
    static const uint32_t CAN_CS8_IDE = 1U << 21 ;

//-------------------- Message Buffer 11 WORD0 Register
#define CAN_WORD011(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x138)))
#define CAN0_WORD011 (* ((volatile uint32_t *) (0x40024000 + 0x138)))
#define CAN1_WORD011 (* ((volatile uint32_t *) (0x400A4000 + 0x138)))

  // Field (width: 8 bits): Data byte 3 of Rx/Tx frame.
    inline uint32_t CAN_WORD011_DATA_BYTE_3 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 2 of Rx/Tx frame.
    inline uint32_t CAN_WORD011_DATA_BYTE_2 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 1 of Rx/Tx frame.
    inline uint32_t CAN_WORD011_DATA_BYTE_1 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 0 of Rx/Tx frame.
    inline uint32_t CAN_WORD011_DATA_BYTE_0 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 6 WORD1 Register
#define CAN_WORD16(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xEC)))
#define CAN0_WORD16 (* ((volatile uint32_t *) (0x40024000 + 0xEC)))
#define CAN1_WORD16 (* ((volatile uint32_t *) (0x400A4000 + 0xEC)))

  // Field (width: 8 bits): Data byte 7 of Rx/Tx frame.
    inline uint32_t CAN_WORD16_DATA_BYTE_7 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 6 of Rx/Tx frame.
    inline uint32_t CAN_WORD16_DATA_BYTE_6 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 5 of Rx/Tx frame.
    inline uint32_t CAN_WORD16_DATA_BYTE_5 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 4 of Rx/Tx frame.
    inline uint32_t CAN_WORD16_DATA_BYTE_4 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 13 CS Register
#define CAN_CS13(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x150)))
#define CAN0_CS13 (* ((volatile uint32_t *) (0x40024000 + 0x150)))
#define CAN1_CS13 (* ((volatile uint32_t *) (0x400A4000 + 0x150)))

  // Field (width: 4 bits): Length of the data to be stored/transmitted.
    inline uint32_t CAN_CS13_DLC (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 4 bits): Reserved
    inline uint32_t CAN_CS13_CODE (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Boolean field: Substitute Remote Request. Contains a fixed recessive bit.
    static const uint32_t CAN_CS13_SRR = 1U << 22 ;

  // Boolean field: Remote Transmission Request. One/zero for remote/data frame.
    static const uint32_t CAN_CS13_RTR = 1U << 20 ;

  // Field (width: 16 bits): Free-Running Counter Time stamp. This 16-bit field is a copy of the Free-Running Timer, captured for Tx and Rx frames at the time when the beginning of the Identifier field appears on the CAN bus.
    inline uint32_t CAN_CS13_TIME_STAMP (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Boolean field: ID Extended. One/zero for extended/standard format frame.
    static const uint32_t CAN_CS13_IDE = 1U << 21 ;

//-------------------- Message Buffer 14 WORD0 Register
#define CAN_WORD014(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x168)))
#define CAN0_WORD014 (* ((volatile uint32_t *) (0x40024000 + 0x168)))
#define CAN1_WORD014 (* ((volatile uint32_t *) (0x400A4000 + 0x168)))

  // Field (width: 8 bits): Data byte 3 of Rx/Tx frame.
    inline uint32_t CAN_WORD014_DATA_BYTE_3 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 2 of Rx/Tx frame.
    inline uint32_t CAN_WORD014_DATA_BYTE_2 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 1 of Rx/Tx frame.
    inline uint32_t CAN_WORD014_DATA_BYTE_1 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 0 of Rx/Tx frame.
    inline uint32_t CAN_WORD014_DATA_BYTE_0 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 15 WORD0 Register
#define CAN_WORD015(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x178)))
#define CAN0_WORD015 (* ((volatile uint32_t *) (0x40024000 + 0x178)))
#define CAN1_WORD015 (* ((volatile uint32_t *) (0x400A4000 + 0x178)))

  // Field (width: 8 bits): Data byte 3 of Rx/Tx frame.
    inline uint32_t CAN_WORD015_DATA_BYTE_3 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 2 of Rx/Tx frame.
    inline uint32_t CAN_WORD015_DATA_BYTE_2 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 1 of Rx/Tx frame.
    inline uint32_t CAN_WORD015_DATA_BYTE_1 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 0 of Rx/Tx frame.
    inline uint32_t CAN_WORD015_DATA_BYTE_0 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 14 WORD1 Register
#define CAN_WORD114(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x16C)))
#define CAN0_WORD114 (* ((volatile uint32_t *) (0x40024000 + 0x16C)))
#define CAN1_WORD114 (* ((volatile uint32_t *) (0x400A4000 + 0x16C)))

  // Field (width: 8 bits): Data byte 7 of Rx/Tx frame.
    inline uint32_t CAN_WORD114_DATA_BYTE_7 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 6 of Rx/Tx frame.
    inline uint32_t CAN_WORD114_DATA_BYTE_6 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 5 of Rx/Tx frame.
    inline uint32_t CAN_WORD114_DATA_BYTE_5 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 4 of Rx/Tx frame.
    inline uint32_t CAN_WORD114_DATA_BYTE_4 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 10 WORD0 Register
#define CAN_WORD010(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x128)))
#define CAN0_WORD010 (* ((volatile uint32_t *) (0x40024000 + 0x128)))
#define CAN1_WORD010 (* ((volatile uint32_t *) (0x400A4000 + 0x128)))

  // Field (width: 8 bits): Data byte 3 of Rx/Tx frame.
    inline uint32_t CAN_WORD010_DATA_BYTE_3 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 2 of Rx/Tx frame.
    inline uint32_t CAN_WORD010_DATA_BYTE_2 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 1 of Rx/Tx frame.
    inline uint32_t CAN_WORD010_DATA_BYTE_1 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 0 of Rx/Tx frame.
    inline uint32_t CAN_WORD010_DATA_BYTE_0 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Rx Individual Mask Registers (idx = 0 ... 15)
#define CAN_RXIMR(group,idx) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x880 + 0x4 * (idx))))
#define CAN0_RXIMR(idx) (* ((volatile uint32_t *) (0x40024000 + 0x880 + 0x4 * (idx))))
#define CAN1_RXIMR(idx) (* ((volatile uint32_t *) (0x400A4000 + 0x880 + 0x4 * (idx))))

//-------------------- Message Buffer 11 WORD1 Register
#define CAN_WORD111(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x13C)))
#define CAN0_WORD111 (* ((volatile uint32_t *) (0x40024000 + 0x13C)))
#define CAN1_WORD111 (* ((volatile uint32_t *) (0x400A4000 + 0x13C)))

  // Field (width: 8 bits): Data byte 7 of Rx/Tx frame.
    inline uint32_t CAN_WORD111_DATA_BYTE_7 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 6 of Rx/Tx frame.
    inline uint32_t CAN_WORD111_DATA_BYTE_6 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 5 of Rx/Tx frame.
    inline uint32_t CAN_WORD111_DATA_BYTE_5 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 4 of Rx/Tx frame.
    inline uint32_t CAN_WORD111_DATA_BYTE_4 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 10 WORD1 Register
#define CAN_WORD110(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x12C)))
#define CAN0_WORD110 (* ((volatile uint32_t *) (0x40024000 + 0x12C)))
#define CAN1_WORD110 (* ((volatile uint32_t *) (0x400A4000 + 0x12C)))

  // Field (width: 8 bits): Data byte 7 of Rx/Tx frame.
    inline uint32_t CAN_WORD110_DATA_BYTE_7 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 6 of Rx/Tx frame.
    inline uint32_t CAN_WORD110_DATA_BYTE_6 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 5 of Rx/Tx frame.
    inline uint32_t CAN_WORD110_DATA_BYTE_5 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 4 of Rx/Tx frame.
    inline uint32_t CAN_WORD110_DATA_BYTE_4 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 13 WORD1 Register
#define CAN_WORD113(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x15C)))
#define CAN0_WORD113 (* ((volatile uint32_t *) (0x40024000 + 0x15C)))
#define CAN1_WORD113 (* ((volatile uint32_t *) (0x400A4000 + 0x15C)))

  // Field (width: 8 bits): Data byte 7 of Rx/Tx frame.
    inline uint32_t CAN_WORD113_DATA_BYTE_7 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 6 of Rx/Tx frame.
    inline uint32_t CAN_WORD113_DATA_BYTE_6 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 5 of Rx/Tx frame.
    inline uint32_t CAN_WORD113_DATA_BYTE_5 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 4 of Rx/Tx frame.
    inline uint32_t CAN_WORD113_DATA_BYTE_4 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 12 WORD1 Register
#define CAN_WORD112(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x14C)))
#define CAN0_WORD112 (* ((volatile uint32_t *) (0x40024000 + 0x14C)))
#define CAN1_WORD112 (* ((volatile uint32_t *) (0x400A4000 + 0x14C)))

  // Field (width: 8 bits): Data byte 7 of Rx/Tx frame.
    inline uint32_t CAN_WORD112_DATA_BYTE_7 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 6 of Rx/Tx frame.
    inline uint32_t CAN_WORD112_DATA_BYTE_6 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 5 of Rx/Tx frame.
    inline uint32_t CAN_WORD112_DATA_BYTE_5 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 4 of Rx/Tx frame.
    inline uint32_t CAN_WORD112_DATA_BYTE_4 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 9 CS Register
#define CAN_CS9(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x110)))
#define CAN0_CS9 (* ((volatile uint32_t *) (0x40024000 + 0x110)))
#define CAN1_CS9 (* ((volatile uint32_t *) (0x400A4000 + 0x110)))

  // Field (width: 4 bits): Length of the data to be stored/transmitted.
    inline uint32_t CAN_CS9_DLC (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 4 bits): Reserved
    inline uint32_t CAN_CS9_CODE (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Boolean field: Substitute Remote Request. Contains a fixed recessive bit.
    static const uint32_t CAN_CS9_SRR = 1U << 22 ;

  // Boolean field: Remote Transmission Request. One/zero for remote/data frame.
    static const uint32_t CAN_CS9_RTR = 1U << 20 ;

  // Field (width: 16 bits): Free-Running Counter Time stamp. This 16-bit field is a copy of the Free-Running Timer, captured for Tx and Rx frames at the time when the beginning of the Identifier field appears on the CAN bus.
    inline uint32_t CAN_CS9_TIME_STAMP (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Boolean field: ID Extended. One/zero for extended/standard format frame.
    static const uint32_t CAN_CS9_IDE = 1U << 21 ;

//-------------------- Error Counter
#define CAN_ECR(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x1C)))
#define CAN0_ECR (* ((volatile uint32_t *) (0x40024000 + 0x1C)))
#define CAN1_ECR (* ((volatile uint32_t *) (0x400A4000 + 0x1C)))

  // Field (width: 8 bits): Receive Error Counter
    inline uint32_t CAN_ECR_RXERRCNT (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Transmit Error Counter
    inline uint32_t CAN_ECR_TXERRCNT (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

//-------------------- Message Buffer 12 WORD0 Register
#define CAN_WORD012(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x148)))
#define CAN0_WORD012 (* ((volatile uint32_t *) (0x40024000 + 0x148)))
#define CAN1_WORD012 (* ((volatile uint32_t *) (0x400A4000 + 0x148)))

  // Field (width: 8 bits): Data byte 3 of Rx/Tx frame.
    inline uint32_t CAN_WORD012_DATA_BYTE_3 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 2 of Rx/Tx frame.
    inline uint32_t CAN_WORD012_DATA_BYTE_2 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 1 of Rx/Tx frame.
    inline uint32_t CAN_WORD012_DATA_BYTE_1 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 0 of Rx/Tx frame.
    inline uint32_t CAN_WORD012_DATA_BYTE_0 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 13 WORD0 Register
#define CAN_WORD013(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x158)))
#define CAN0_WORD013 (* ((volatile uint32_t *) (0x40024000 + 0x158)))
#define CAN1_WORD013 (* ((volatile uint32_t *) (0x400A4000 + 0x158)))

  // Field (width: 8 bits): Data byte 3 of Rx/Tx frame.
    inline uint32_t CAN_WORD013_DATA_BYTE_3 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 2 of Rx/Tx frame.
    inline uint32_t CAN_WORD013_DATA_BYTE_2 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 1 of Rx/Tx frame.
    inline uint32_t CAN_WORD013_DATA_BYTE_1 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 0 of Rx/Tx frame.
    inline uint32_t CAN_WORD013_DATA_BYTE_0 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Interrupt Masks 1 register
#define CAN_IMASK1(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x28)))
#define CAN0_IMASK1 (* ((volatile uint32_t *) (0x40024000 + 0x28)))
#define CAN1_IMASK1 (* ((volatile uint32_t *) (0x400A4000 + 0x28)))

//-------------------- Message Buffer 4 CS Register
#define CAN_CS4(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xC0)))
#define CAN0_CS4 (* ((volatile uint32_t *) (0x40024000 + 0xC0)))
#define CAN1_CS4 (* ((volatile uint32_t *) (0x400A4000 + 0xC0)))

  // Field (width: 4 bits): Length of the data to be stored/transmitted.
    inline uint32_t CAN_CS4_DLC (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 4 bits): Reserved
    inline uint32_t CAN_CS4_CODE (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Boolean field: Substitute Remote Request. Contains a fixed recessive bit.
    static const uint32_t CAN_CS4_SRR = 1U << 22 ;

  // Boolean field: Remote Transmission Request. One/zero for remote/data frame.
    static const uint32_t CAN_CS4_RTR = 1U << 20 ;

  // Field (width: 16 bits): Free-Running Counter Time stamp. This 16-bit field is a copy of the Free-Running Timer, captured for Tx and Rx frames at the time when the beginning of the Identifier field appears on the CAN bus.
    inline uint32_t CAN_CS4_TIME_STAMP (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Boolean field: ID Extended. One/zero for extended/standard format frame.
    static const uint32_t CAN_CS4_IDE = 1U << 21 ;

//-------------------- Message Buffer 7 CS Register
#define CAN_CS7(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xF0)))
#define CAN0_CS7 (* ((volatile uint32_t *) (0x40024000 + 0xF0)))
#define CAN1_CS7 (* ((volatile uint32_t *) (0x400A4000 + 0xF0)))

  // Field (width: 4 bits): Length of the data to be stored/transmitted.
    inline uint32_t CAN_CS7_DLC (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 4 bits): Reserved
    inline uint32_t CAN_CS7_CODE (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Boolean field: Substitute Remote Request. Contains a fixed recessive bit.
    static const uint32_t CAN_CS7_SRR = 1U << 22 ;

  // Boolean field: Remote Transmission Request. One/zero for remote/data frame.
    static const uint32_t CAN_CS7_RTR = 1U << 20 ;

  // Field (width: 16 bits): Free-Running Counter Time stamp. This 16-bit field is a copy of the Free-Running Timer, captured for Tx and Rx frames at the time when the beginning of the Identifier field appears on the CAN bus.
    inline uint32_t CAN_CS7_TIME_STAMP (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Boolean field: ID Extended. One/zero for extended/standard format frame.
    static const uint32_t CAN_CS7_IDE = 1U << 21 ;

//-------------------- Message Buffer 6 CS Register
#define CAN_CS6(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xE0)))
#define CAN0_CS6 (* ((volatile uint32_t *) (0x40024000 + 0xE0)))
#define CAN1_CS6 (* ((volatile uint32_t *) (0x400A4000 + 0xE0)))

  // Field (width: 4 bits): Length of the data to be stored/transmitted.
    inline uint32_t CAN_CS6_DLC (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 4 bits): Reserved
    inline uint32_t CAN_CS6_CODE (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Boolean field: Substitute Remote Request. Contains a fixed recessive bit.
    static const uint32_t CAN_CS6_SRR = 1U << 22 ;

  // Boolean field: Remote Transmission Request. One/zero for remote/data frame.
    static const uint32_t CAN_CS6_RTR = 1U << 20 ;

  // Field (width: 16 bits): Free-Running Counter Time stamp. This 16-bit field is a copy of the Free-Running Timer, captured for Tx and Rx frames at the time when the beginning of the Identifier field appears on the CAN bus.
    inline uint32_t CAN_CS6_TIME_STAMP (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Boolean field: ID Extended. One/zero for extended/standard format frame.
    static const uint32_t CAN_CS6_IDE = 1U << 21 ;

//-------------------- Message Buffer 1 CS Register
#define CAN_CS1(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x90)))
#define CAN0_CS1 (* ((volatile uint32_t *) (0x40024000 + 0x90)))
#define CAN1_CS1 (* ((volatile uint32_t *) (0x400A4000 + 0x90)))

  // Field (width: 4 bits): Length of the data to be stored/transmitted.
    inline uint32_t CAN_CS1_DLC (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 4 bits): Reserved
    inline uint32_t CAN_CS1_CODE (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Boolean field: Substitute Remote Request. Contains a fixed recessive bit.
    static const uint32_t CAN_CS1_SRR = 1U << 22 ;

  // Boolean field: Remote Transmission Request. One/zero for remote/data frame.
    static const uint32_t CAN_CS1_RTR = 1U << 20 ;

  // Field (width: 16 bits): Free-Running Counter Time stamp. This 16-bit field is a copy of the Free-Running Timer, captured for Tx and Rx frames at the time when the beginning of the Identifier field appears on the CAN bus.
    inline uint32_t CAN_CS1_TIME_STAMP (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Boolean field: ID Extended. One/zero for extended/standard format frame.
    static const uint32_t CAN_CS1_IDE = 1U << 21 ;

//-------------------- Message Buffer 0 CS Register
#define CAN_CS0(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x80)))
#define CAN0_CS0 (* ((volatile uint32_t *) (0x40024000 + 0x80)))
#define CAN1_CS0 (* ((volatile uint32_t *) (0x400A4000 + 0x80)))

  // Field (width: 4 bits): Length of the data to be stored/transmitted.
    inline uint32_t CAN_CS0_DLC (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 4 bits): Reserved
    inline uint32_t CAN_CS0_CODE (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Boolean field: Substitute Remote Request. Contains a fixed recessive bit.
    static const uint32_t CAN_CS0_SRR = 1U << 22 ;

  // Boolean field: Remote Transmission Request. One/zero for remote/data frame.
    static const uint32_t CAN_CS0_RTR = 1U << 20 ;

  // Field (width: 16 bits): Free-Running Counter Time stamp. This 16-bit field is a copy of the Free-Running Timer, captured for Tx and Rx frames at the time when the beginning of the Identifier field appears on the CAN bus.
    inline uint32_t CAN_CS0_TIME_STAMP (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Boolean field: ID Extended. One/zero for extended/standard format frame.
    static const uint32_t CAN_CS0_IDE = 1U << 21 ;

//-------------------- Message Buffer 3 CS Register
#define CAN_CS3(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xB0)))
#define CAN0_CS3 (* ((volatile uint32_t *) (0x40024000 + 0xB0)))
#define CAN1_CS3 (* ((volatile uint32_t *) (0x400A4000 + 0xB0)))

  // Field (width: 4 bits): Length of the data to be stored/transmitted.
    inline uint32_t CAN_CS3_DLC (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 4 bits): Reserved
    inline uint32_t CAN_CS3_CODE (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Boolean field: Substitute Remote Request. Contains a fixed recessive bit.
    static const uint32_t CAN_CS3_SRR = 1U << 22 ;

  // Boolean field: Remote Transmission Request. One/zero for remote/data frame.
    static const uint32_t CAN_CS3_RTR = 1U << 20 ;

  // Field (width: 16 bits): Free-Running Counter Time stamp. This 16-bit field is a copy of the Free-Running Timer, captured for Tx and Rx frames at the time when the beginning of the Identifier field appears on the CAN bus.
    inline uint32_t CAN_CS3_TIME_STAMP (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Boolean field: ID Extended. One/zero for extended/standard format frame.
    static const uint32_t CAN_CS3_IDE = 1U << 21 ;

//-------------------- Rx FIFO Global Mask register
#define CAN_RXFGMASK(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x48)))
#define CAN0_RXFGMASK (* ((volatile uint32_t *) (0x40024000 + 0x48)))
#define CAN1_RXFGMASK (* ((volatile uint32_t *) (0x400A4000 + 0x48)))

//-------------------- Message Buffer 6 WORD0 Register
#define CAN_WORD06(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xE8)))
#define CAN0_WORD06 (* ((volatile uint32_t *) (0x40024000 + 0xE8)))
#define CAN1_WORD06 (* ((volatile uint32_t *) (0x400A4000 + 0xE8)))

  // Field (width: 8 bits): Data byte 3 of Rx/Tx frame.
    inline uint32_t CAN_WORD06_DATA_BYTE_3 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 2 of Rx/Tx frame.
    inline uint32_t CAN_WORD06_DATA_BYTE_2 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 1 of Rx/Tx frame.
    inline uint32_t CAN_WORD06_DATA_BYTE_1 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 0 of Rx/Tx frame.
    inline uint32_t CAN_WORD06_DATA_BYTE_0 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 7 WORD0 Register
#define CAN_WORD07(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xF8)))
#define CAN0_WORD07 (* ((volatile uint32_t *) (0x40024000 + 0xF8)))
#define CAN1_WORD07 (* ((volatile uint32_t *) (0x400A4000 + 0xF8)))

  // Field (width: 8 bits): Data byte 3 of Rx/Tx frame.
    inline uint32_t CAN_WORD07_DATA_BYTE_3 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 2 of Rx/Tx frame.
    inline uint32_t CAN_WORD07_DATA_BYTE_2 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 1 of Rx/Tx frame.
    inline uint32_t CAN_WORD07_DATA_BYTE_1 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 0 of Rx/Tx frame.
    inline uint32_t CAN_WORD07_DATA_BYTE_0 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 4 WORD0 Register
#define CAN_WORD04(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xC8)))
#define CAN0_WORD04 (* ((volatile uint32_t *) (0x40024000 + 0xC8)))
#define CAN1_WORD04 (* ((volatile uint32_t *) (0x400A4000 + 0xC8)))

  // Field (width: 8 bits): Data byte 3 of Rx/Tx frame.
    inline uint32_t CAN_WORD04_DATA_BYTE_3 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 2 of Rx/Tx frame.
    inline uint32_t CAN_WORD04_DATA_BYTE_2 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 1 of Rx/Tx frame.
    inline uint32_t CAN_WORD04_DATA_BYTE_1 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 0 of Rx/Tx frame.
    inline uint32_t CAN_WORD04_DATA_BYTE_0 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 5 WORD0 Register
#define CAN_WORD05(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xD8)))
#define CAN0_WORD05 (* ((volatile uint32_t *) (0x40024000 + 0xD8)))
#define CAN1_WORD05 (* ((volatile uint32_t *) (0x400A4000 + 0xD8)))

  // Field (width: 8 bits): Data byte 3 of Rx/Tx frame.
    inline uint32_t CAN_WORD05_DATA_BYTE_3 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 2 of Rx/Tx frame.
    inline uint32_t CAN_WORD05_DATA_BYTE_2 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 1 of Rx/Tx frame.
    inline uint32_t CAN_WORD05_DATA_BYTE_1 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 0 of Rx/Tx frame.
    inline uint32_t CAN_WORD05_DATA_BYTE_0 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 2 WORD0 Register
#define CAN_WORD02(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xA8)))
#define CAN0_WORD02 (* ((volatile uint32_t *) (0x40024000 + 0xA8)))
#define CAN1_WORD02 (* ((volatile uint32_t *) (0x400A4000 + 0xA8)))

  // Field (width: 8 bits): Data byte 3 of Rx/Tx frame.
    inline uint32_t CAN_WORD02_DATA_BYTE_3 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 2 of Rx/Tx frame.
    inline uint32_t CAN_WORD02_DATA_BYTE_2 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 1 of Rx/Tx frame.
    inline uint32_t CAN_WORD02_DATA_BYTE_1 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 0 of Rx/Tx frame.
    inline uint32_t CAN_WORD02_DATA_BYTE_0 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 3 WORD0 Register
#define CAN_WORD03(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xB8)))
#define CAN0_WORD03 (* ((volatile uint32_t *) (0x40024000 + 0xB8)))
#define CAN1_WORD03 (* ((volatile uint32_t *) (0x400A4000 + 0xB8)))

  // Field (width: 8 bits): Data byte 3 of Rx/Tx frame.
    inline uint32_t CAN_WORD03_DATA_BYTE_3 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 2 of Rx/Tx frame.
    inline uint32_t CAN_WORD03_DATA_BYTE_2 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 1 of Rx/Tx frame.
    inline uint32_t CAN_WORD03_DATA_BYTE_1 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 0 of Rx/Tx frame.
    inline uint32_t CAN_WORD03_DATA_BYTE_0 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 0 WORD0 Register
#define CAN_WORD00(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x88)))
#define CAN0_WORD00 (* ((volatile uint32_t *) (0x40024000 + 0x88)))
#define CAN1_WORD00 (* ((volatile uint32_t *) (0x400A4000 + 0x88)))

  // Field (width: 8 bits): Data byte 3 of Rx/Tx frame.
    inline uint32_t CAN_WORD00_DATA_BYTE_3 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 2 of Rx/Tx frame.
    inline uint32_t CAN_WORD00_DATA_BYTE_2 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 1 of Rx/Tx frame.
    inline uint32_t CAN_WORD00_DATA_BYTE_1 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 0 of Rx/Tx frame.
    inline uint32_t CAN_WORD00_DATA_BYTE_0 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 1 WORD0 Register
#define CAN_WORD01(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x98)))
#define CAN0_WORD01 (* ((volatile uint32_t *) (0x40024000 + 0x98)))
#define CAN1_WORD01 (* ((volatile uint32_t *) (0x400A4000 + 0x98)))

  // Field (width: 8 bits): Data byte 3 of Rx/Tx frame.
    inline uint32_t CAN_WORD01_DATA_BYTE_3 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 2 of Rx/Tx frame.
    inline uint32_t CAN_WORD01_DATA_BYTE_2 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 1 of Rx/Tx frame.
    inline uint32_t CAN_WORD01_DATA_BYTE_1 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 0 of Rx/Tx frame.
    inline uint32_t CAN_WORD01_DATA_BYTE_0 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 11 CS Register
#define CAN_CS11(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x130)))
#define CAN0_CS11 (* ((volatile uint32_t *) (0x40024000 + 0x130)))
#define CAN1_CS11 (* ((volatile uint32_t *) (0x400A4000 + 0x130)))

  // Field (width: 4 bits): Length of the data to be stored/transmitted.
    inline uint32_t CAN_CS11_DLC (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 4 bits): Reserved
    inline uint32_t CAN_CS11_CODE (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Boolean field: Substitute Remote Request. Contains a fixed recessive bit.
    static const uint32_t CAN_CS11_SRR = 1U << 22 ;

  // Boolean field: Remote Transmission Request. One/zero for remote/data frame.
    static const uint32_t CAN_CS11_RTR = 1U << 20 ;

  // Field (width: 16 bits): Free-Running Counter Time stamp. This 16-bit field is a copy of the Free-Running Timer, captured for Tx and Rx frames at the time when the beginning of the Identifier field appears on the CAN bus.
    inline uint32_t CAN_CS11_TIME_STAMP (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Boolean field: ID Extended. One/zero for extended/standard format frame.
    static const uint32_t CAN_CS11_IDE = 1U << 21 ;

//-------------------- Message Buffer 10 CS Register
#define CAN_CS10(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x120)))
#define CAN0_CS10 (* ((volatile uint32_t *) (0x40024000 + 0x120)))
#define CAN1_CS10 (* ((volatile uint32_t *) (0x400A4000 + 0x120)))

  // Field (width: 4 bits): Length of the data to be stored/transmitted.
    inline uint32_t CAN_CS10_DLC (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 4 bits): Reserved
    inline uint32_t CAN_CS10_CODE (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Boolean field: Substitute Remote Request. Contains a fixed recessive bit.
    static const uint32_t CAN_CS10_SRR = 1U << 22 ;

  // Boolean field: Remote Transmission Request. One/zero for remote/data frame.
    static const uint32_t CAN_CS10_RTR = 1U << 20 ;

  // Field (width: 16 bits): Free-Running Counter Time stamp. This 16-bit field is a copy of the Free-Running Timer, captured for Tx and Rx frames at the time when the beginning of the Identifier field appears on the CAN bus.
    inline uint32_t CAN_CS10_TIME_STAMP (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Boolean field: ID Extended. One/zero for extended/standard format frame.
    static const uint32_t CAN_CS10_IDE = 1U << 21 ;

//-------------------- Rx Mailboxes Global Mask Register
#define CAN_RXMGMASK(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x10)))
#define CAN0_RXMGMASK (* ((volatile uint32_t *) (0x40024000 + 0x10)))
#define CAN1_RXMGMASK (* ((volatile uint32_t *) (0x400A4000 + 0x10)))

//-------------------- Message Buffer 12 CS Register
#define CAN_CS12(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x140)))
#define CAN0_CS12 (* ((volatile uint32_t *) (0x40024000 + 0x140)))
#define CAN1_CS12 (* ((volatile uint32_t *) (0x400A4000 + 0x140)))

  // Field (width: 4 bits): Length of the data to be stored/transmitted.
    inline uint32_t CAN_CS12_DLC (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 4 bits): Reserved
    inline uint32_t CAN_CS12_CODE (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Boolean field: Substitute Remote Request. Contains a fixed recessive bit.
    static const uint32_t CAN_CS12_SRR = 1U << 22 ;

  // Boolean field: Remote Transmission Request. One/zero for remote/data frame.
    static const uint32_t CAN_CS12_RTR = 1U << 20 ;

  // Field (width: 16 bits): Free-Running Counter Time stamp. This 16-bit field is a copy of the Free-Running Timer, captured for Tx and Rx frames at the time when the beginning of the Identifier field appears on the CAN bus.
    inline uint32_t CAN_CS12_TIME_STAMP (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Boolean field: ID Extended. One/zero for extended/standard format frame.
    static const uint32_t CAN_CS12_IDE = 1U << 21 ;

//-------------------- Message Buffer 15 CS Register
#define CAN_CS15(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x170)))
#define CAN0_CS15 (* ((volatile uint32_t *) (0x40024000 + 0x170)))
#define CAN1_CS15 (* ((volatile uint32_t *) (0x400A4000 + 0x170)))

  // Field (width: 4 bits): Length of the data to be stored/transmitted.
    inline uint32_t CAN_CS15_DLC (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 4 bits): Reserved
    inline uint32_t CAN_CS15_CODE (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Boolean field: Substitute Remote Request. Contains a fixed recessive bit.
    static const uint32_t CAN_CS15_SRR = 1U << 22 ;

  // Boolean field: Remote Transmission Request. One/zero for remote/data frame.
    static const uint32_t CAN_CS15_RTR = 1U << 20 ;

  // Field (width: 16 bits): Free-Running Counter Time stamp. This 16-bit field is a copy of the Free-Running Timer, captured for Tx and Rx frames at the time when the beginning of the Identifier field appears on the CAN bus.
    inline uint32_t CAN_CS15_TIME_STAMP (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Boolean field: ID Extended. One/zero for extended/standard format frame.
    static const uint32_t CAN_CS15_IDE = 1U << 21 ;

//-------------------- Message Buffer 14 CS Register
#define CAN_CS14(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x160)))
#define CAN0_CS14 (* ((volatile uint32_t *) (0x40024000 + 0x160)))
#define CAN1_CS14 (* ((volatile uint32_t *) (0x400A4000 + 0x160)))

  // Field (width: 4 bits): Length of the data to be stored/transmitted.
    inline uint32_t CAN_CS14_DLC (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 4 bits): Reserved
    inline uint32_t CAN_CS14_CODE (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Boolean field: Substitute Remote Request. Contains a fixed recessive bit.
    static const uint32_t CAN_CS14_SRR = 1U << 22 ;

  // Boolean field: Remote Transmission Request. One/zero for remote/data frame.
    static const uint32_t CAN_CS14_RTR = 1U << 20 ;

  // Field (width: 16 bits): Free-Running Counter Time stamp. This 16-bit field is a copy of the Free-Running Timer, captured for Tx and Rx frames at the time when the beginning of the Identifier field appears on the CAN bus.
    inline uint32_t CAN_CS14_TIME_STAMP (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Boolean field: ID Extended. One/zero for extended/standard format frame.
    static const uint32_t CAN_CS14_IDE = 1U << 21 ;

//-------------------- Free Running Timer
#define CAN_TIMER(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x8)))
#define CAN0_TIMER (* ((volatile uint32_t *) (0x40024000 + 0x8)))
#define CAN1_TIMER (* ((volatile uint32_t *) (0x400A4000 + 0x8)))

  // Field (width: 16 bits): Timer Value
    inline uint32_t CAN_TIMER_TIMER (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Message Buffer 9 ID Register
#define CAN_ID9(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x114)))
#define CAN0_ID9 (* ((volatile uint32_t *) (0x40024000 + 0x114)))
#define CAN1_ID9 (* ((volatile uint32_t *) (0x400A4000 + 0x114)))

  // Field (width: 11 bits): Contains standard/extended (HIGH word) identifier of message buffer.
    inline uint32_t CAN_ID9_STD (const uint32_t inValue) { return (inValue & 2047U) << 18 ; }

  // Field (width: 18 bits): Contains extended (LOW word) identifier of message buffer.
    inline uint32_t CAN_ID9_EXT (const uint32_t inValue) { return (inValue & 262143U) << 0 ; }

  // Field (width: 3 bits): Local priority. This 3-bit fieldis only used when LPRIO_EN bit is set in MCR and it only makes sense for Tx buffers. These bits are not transmitted. They are appended to the regular ID to define the transmission priority.
    inline uint32_t CAN_ID9_PRIO (const uint32_t inValue) { return (inValue & 7U) << 29 ; }

//-------------------- Rx 14 Mask register
#define CAN_RX14MASK(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x14)))
#define CAN0_RX14MASK (* ((volatile uint32_t *) (0x40024000 + 0x14)))
#define CAN1_RX14MASK (* ((volatile uint32_t *) (0x400A4000 + 0x14)))

//-------------------- Interrupt Flags 1 register
#define CAN_IFLAG1(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x30)))
#define CAN0_IFLAG1 (* ((volatile uint32_t *) (0x40024000 + 0x30)))
#define CAN1_IFLAG1 (* ((volatile uint32_t *) (0x400A4000 + 0x30)))

  // Field (width: 4 bits): Buffer MB i Interrupt Or "reserved"
    inline uint32_t CAN_IFLAG1_BUF4TO1I (const uint32_t inValue) { return (inValue & 15U) << 1 ; }

  // Field (width: 24 bits): Buffer MBi Interrupt
    inline uint32_t CAN_IFLAG1_BUF31TO8I (const uint32_t inValue) { return (inValue & 16777215U) << 8 ; }

  // Boolean field: Buffer MB0 Interrupt Or "reserved"
    static const uint32_t CAN_IFLAG1_BUF0I = 1U << 0 ;

  // Boolean field: Buffer MB6 Interrupt Or "Rx FIFO Warning"
    static const uint32_t CAN_IFLAG1_BUF6I = 1U << 6 ;

  // Boolean field: Buffer MB7 Interrupt Or "Rx FIFO Overflow"
    static const uint32_t CAN_IFLAG1_BUF7I = 1U << 7 ;

  // Boolean field: Buffer MB5 Interrupt Or "Frames available in Rx FIFO"
    static const uint32_t CAN_IFLAG1_BUF5I = 1U << 5 ;

//-------------------- Message Buffer 8 WORD0 Register
#define CAN_WORD08(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x108)))
#define CAN0_WORD08 (* ((volatile uint32_t *) (0x40024000 + 0x108)))
#define CAN1_WORD08 (* ((volatile uint32_t *) (0x400A4000 + 0x108)))

  // Field (width: 8 bits): Data byte 3 of Rx/Tx frame.
    inline uint32_t CAN_WORD08_DATA_BYTE_3 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 2 of Rx/Tx frame.
    inline uint32_t CAN_WORD08_DATA_BYTE_2 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 1 of Rx/Tx frame.
    inline uint32_t CAN_WORD08_DATA_BYTE_1 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 0 of Rx/Tx frame.
    inline uint32_t CAN_WORD08_DATA_BYTE_0 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 9 WORD0 Register
#define CAN_WORD09(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x118)))
#define CAN0_WORD09 (* ((volatile uint32_t *) (0x40024000 + 0x118)))
#define CAN1_WORD09 (* ((volatile uint32_t *) (0x400A4000 + 0x118)))

  // Field (width: 8 bits): Data byte 3 of Rx/Tx frame.
    inline uint32_t CAN_WORD09_DATA_BYTE_3 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 2 of Rx/Tx frame.
    inline uint32_t CAN_WORD09_DATA_BYTE_2 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 1 of Rx/Tx frame.
    inline uint32_t CAN_WORD09_DATA_BYTE_1 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 0 of Rx/Tx frame.
    inline uint32_t CAN_WORD09_DATA_BYTE_0 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- CRC Register
#define CAN_CRCR(group) (* ((const volatile uint32_t *) (kBaseAddress_CAN [group] + 0x44)))
#define CAN0_CRCR (* ((const volatile uint32_t *) (0x40024000 + 0x44)))
#define CAN1_CRCR (* ((const volatile uint32_t *) (0x400A4000 + 0x44)))

  // Field (width: 15 bits): CRC Transmitted
    inline uint32_t CAN_CRCR_TXCRC (const uint32_t inValue) { return (inValue & 32767U) << 0 ; }

  // Field (width: 7 bits): CRC Mailbox
    inline uint32_t CAN_CRCR_MBCRC (const uint32_t inValue) { return (inValue & 127U) << 16 ; }

//-------------------- Error and Status 2 register
#define CAN_ESR2(group) (* ((const volatile uint32_t *) (kBaseAddress_CAN [group] + 0x38)))
#define CAN0_ESR2 (* ((const volatile uint32_t *) (0x40024000 + 0x38)))
#define CAN1_ESR2 (* ((const volatile uint32_t *) (0x400A4000 + 0x38)))

  // Field (width: 7 bits): Lowest Priority Tx Mailbox
    inline uint32_t CAN_ESR2_LPTM (const uint32_t inValue) { return (inValue & 127U) << 16 ; }

  // Boolean field: Inactive Mailbox
    static const uint32_t CAN_ESR2_IMB = 1U << 13 ;

  // Boolean field: Valid Priority Status
    static const uint32_t CAN_ESR2_VPS = 1U << 14 ;

//-------------------- Message Buffer 8 ID Register
#define CAN_ID8(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x104)))
#define CAN0_ID8 (* ((volatile uint32_t *) (0x40024000 + 0x104)))
#define CAN1_ID8 (* ((volatile uint32_t *) (0x400A4000 + 0x104)))

  // Field (width: 11 bits): Contains standard/extended (HIGH word) identifier of message buffer.
    inline uint32_t CAN_ID8_STD (const uint32_t inValue) { return (inValue & 2047U) << 18 ; }

  // Field (width: 18 bits): Contains extended (LOW word) identifier of message buffer.
    inline uint32_t CAN_ID8_EXT (const uint32_t inValue) { return (inValue & 262143U) << 0 ; }

  // Field (width: 3 bits): Local priority. This 3-bit fieldis only used when LPRIO_EN bit is set in MCR and it only makes sense for Tx buffers. These bits are not transmitted. They are appended to the regular ID to define the transmission priority.
    inline uint32_t CAN_ID8_PRIO (const uint32_t inValue) { return (inValue & 7U) << 29 ; }

//-------------------- Error and Status 1 register
#define CAN_ESR1(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x20)))
#define CAN0_ESR1 (* ((volatile uint32_t *) (0x40024000 + 0x20)))
#define CAN1_ESR1 (* ((volatile uint32_t *) (0x400A4000 + 0x20)))

  // Boolean field: TX Error Warning
    static const uint32_t CAN_ESR1_TXWRN = 1U << 9 ;

  // Boolean field: Rx Error Warning
    static const uint32_t CAN_ESR1_RXWRN = 1U << 8 ;

  // Boolean field: Error Interrupt
    static const uint32_t CAN_ESR1_ERRINT = 1U << 1 ;

  // Boolean field: FlexCAN In Transmission
    static const uint32_t CAN_ESR1_TX = 1U << 6 ;

  // Boolean field: Form Error
    static const uint32_t CAN_ESR1_FRMERR = 1U << 11 ;

  // Boolean field: Bit1 Error
    static const uint32_t CAN_ESR1_BIT1ERR = 1U << 15 ;

  // Boolean field: FlexCAN In Reception
    static const uint32_t CAN_ESR1_RX = 1U << 3 ;

  // Boolean field: Tx Warning Interrupt Flag
    static const uint32_t CAN_ESR1_TWRNINT = 1U << 17 ;

  // Boolean field: Acknowledge Error
    static const uint32_t CAN_ESR1_ACKERR = 1U << 13 ;

  // Boolean field: Rx Warning Interrupt Flag
    static const uint32_t CAN_ESR1_RWRNINT = 1U << 16 ;

  // Boolean field: This bit indicates when CAN bus is in IDLE state
    static const uint32_t CAN_ESR1_IDLE = 1U << 7 ;

  // Boolean field: Bus Off Interrupt
    static const uint32_t CAN_ESR1_BOFFINT = 1U << 2 ;

  // Boolean field: Stuffing Error
    static const uint32_t CAN_ESR1_STFERR = 1U << 10 ;

  // Boolean field: Cyclic Redundancy Check Error
    static const uint32_t CAN_ESR1_CRCERR = 1U << 12 ;

  // Boolean field: CAN Synchronization Status
    static const uint32_t CAN_ESR1_SYNCH = 1U << 18 ;

  // Field (width: 2 bits): Fault Confinement State
    inline uint32_t CAN_ESR1_FLTCONF (const uint32_t inValue) { return (inValue & 3U) << 4 ; }

  // Boolean field: Wake-Up Interrupt
    static const uint32_t CAN_ESR1_WAKINT = 1U << 0 ;

  // Boolean field: Bit0 Error
    static const uint32_t CAN_ESR1_BIT0ERR = 1U << 14 ;

//-------------------- Message Buffer 6 ID Register
#define CAN_ID6(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xE4)))
#define CAN0_ID6 (* ((volatile uint32_t *) (0x40024000 + 0xE4)))
#define CAN1_ID6 (* ((volatile uint32_t *) (0x400A4000 + 0xE4)))

  // Field (width: 11 bits): Contains standard/extended (HIGH word) identifier of message buffer.
    inline uint32_t CAN_ID6_STD (const uint32_t inValue) { return (inValue & 2047U) << 18 ; }

  // Field (width: 18 bits): Contains extended (LOW word) identifier of message buffer.
    inline uint32_t CAN_ID6_EXT (const uint32_t inValue) { return (inValue & 262143U) << 0 ; }

  // Field (width: 3 bits): Local priority. This 3-bit fieldis only used when LPRIO_EN bit is set in MCR and it only makes sense for Tx buffers. These bits are not transmitted. They are appended to the regular ID to define the transmission priority.
    inline uint32_t CAN_ID6_PRIO (const uint32_t inValue) { return (inValue & 7U) << 29 ; }

//-------------------- Message Buffer 7 ID Register
#define CAN_ID7(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xF4)))
#define CAN0_ID7 (* ((volatile uint32_t *) (0x40024000 + 0xF4)))
#define CAN1_ID7 (* ((volatile uint32_t *) (0x400A4000 + 0xF4)))

  // Field (width: 11 bits): Contains standard/extended (HIGH word) identifier of message buffer.
    inline uint32_t CAN_ID7_STD (const uint32_t inValue) { return (inValue & 2047U) << 18 ; }

  // Field (width: 18 bits): Contains extended (LOW word) identifier of message buffer.
    inline uint32_t CAN_ID7_EXT (const uint32_t inValue) { return (inValue & 262143U) << 0 ; }

  // Field (width: 3 bits): Local priority. This 3-bit fieldis only used when LPRIO_EN bit is set in MCR and it only makes sense for Tx buffers. These bits are not transmitted. They are appended to the regular ID to define the transmission priority.
    inline uint32_t CAN_ID7_PRIO (const uint32_t inValue) { return (inValue & 7U) << 29 ; }

//-------------------- Message Buffer 4 ID Register
#define CAN_ID4(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xC4)))
#define CAN0_ID4 (* ((volatile uint32_t *) (0x40024000 + 0xC4)))
#define CAN1_ID4 (* ((volatile uint32_t *) (0x400A4000 + 0xC4)))

  // Field (width: 11 bits): Contains standard/extended (HIGH word) identifier of message buffer.
    inline uint32_t CAN_ID4_STD (const uint32_t inValue) { return (inValue & 2047U) << 18 ; }

  // Field (width: 18 bits): Contains extended (LOW word) identifier of message buffer.
    inline uint32_t CAN_ID4_EXT (const uint32_t inValue) { return (inValue & 262143U) << 0 ; }

  // Field (width: 3 bits): Local priority. This 3-bit fieldis only used when LPRIO_EN bit is set in MCR and it only makes sense for Tx buffers. These bits are not transmitted. They are appended to the regular ID to define the transmission priority.
    inline uint32_t CAN_ID4_PRIO (const uint32_t inValue) { return (inValue & 7U) << 29 ; }

//-------------------- Message Buffer 5 CS Register
#define CAN_CS5(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xD0)))
#define CAN0_CS5 (* ((volatile uint32_t *) (0x40024000 + 0xD0)))
#define CAN1_CS5 (* ((volatile uint32_t *) (0x400A4000 + 0xD0)))

  // Field (width: 4 bits): Length of the data to be stored/transmitted.
    inline uint32_t CAN_CS5_DLC (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 4 bits): Reserved
    inline uint32_t CAN_CS5_CODE (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Boolean field: Substitute Remote Request. Contains a fixed recessive bit.
    static const uint32_t CAN_CS5_SRR = 1U << 22 ;

  // Boolean field: Remote Transmission Request. One/zero for remote/data frame.
    static const uint32_t CAN_CS5_RTR = 1U << 20 ;

  // Field (width: 16 bits): Free-Running Counter Time stamp. This 16-bit field is a copy of the Free-Running Timer, captured for Tx and Rx frames at the time when the beginning of the Identifier field appears on the CAN bus.
    inline uint32_t CAN_CS5_TIME_STAMP (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Boolean field: ID Extended. One/zero for extended/standard format frame.
    static const uint32_t CAN_CS5_IDE = 1U << 21 ;

//-------------------- Message Buffer 2 ID Register
#define CAN_ID2(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xA4)))
#define CAN0_ID2 (* ((volatile uint32_t *) (0x40024000 + 0xA4)))
#define CAN1_ID2 (* ((volatile uint32_t *) (0x400A4000 + 0xA4)))

  // Field (width: 11 bits): Contains standard/extended (HIGH word) identifier of message buffer.
    inline uint32_t CAN_ID2_STD (const uint32_t inValue) { return (inValue & 2047U) << 18 ; }

  // Field (width: 18 bits): Contains extended (LOW word) identifier of message buffer.
    inline uint32_t CAN_ID2_EXT (const uint32_t inValue) { return (inValue & 262143U) << 0 ; }

  // Field (width: 3 bits): Local priority. This 3-bit fieldis only used when LPRIO_EN bit is set in MCR and it only makes sense for Tx buffers. These bits are not transmitted. They are appended to the regular ID to define the transmission priority.
    inline uint32_t CAN_ID2_PRIO (const uint32_t inValue) { return (inValue & 7U) << 29 ; }

//-------------------- Message Buffer 3 ID Register
#define CAN_ID3(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xB4)))
#define CAN0_ID3 (* ((volatile uint32_t *) (0x40024000 + 0xB4)))
#define CAN1_ID3 (* ((volatile uint32_t *) (0x400A4000 + 0xB4)))

  // Field (width: 11 bits): Contains standard/extended (HIGH word) identifier of message buffer.
    inline uint32_t CAN_ID3_STD (const uint32_t inValue) { return (inValue & 2047U) << 18 ; }

  // Field (width: 18 bits): Contains extended (LOW word) identifier of message buffer.
    inline uint32_t CAN_ID3_EXT (const uint32_t inValue) { return (inValue & 262143U) << 0 ; }

  // Field (width: 3 bits): Local priority. This 3-bit fieldis only used when LPRIO_EN bit is set in MCR and it only makes sense for Tx buffers. These bits are not transmitted. They are appended to the regular ID to define the transmission priority.
    inline uint32_t CAN_ID3_PRIO (const uint32_t inValue) { return (inValue & 7U) << 29 ; }

//-------------------- Message Buffer 0 ID Register
#define CAN_ID0(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x84)))
#define CAN0_ID0 (* ((volatile uint32_t *) (0x40024000 + 0x84)))
#define CAN1_ID0 (* ((volatile uint32_t *) (0x400A4000 + 0x84)))

  // Field (width: 11 bits): Contains standard/extended (HIGH word) identifier of message buffer.
    inline uint32_t CAN_ID0_STD (const uint32_t inValue) { return (inValue & 2047U) << 18 ; }

  // Field (width: 18 bits): Contains extended (LOW word) identifier of message buffer.
    inline uint32_t CAN_ID0_EXT (const uint32_t inValue) { return (inValue & 262143U) << 0 ; }

  // Field (width: 3 bits): Local priority. This 3-bit fieldis only used when LPRIO_EN bit is set in MCR and it only makes sense for Tx buffers. These bits are not transmitted. They are appended to the regular ID to define the transmission priority.
    inline uint32_t CAN_ID0_PRIO (const uint32_t inValue) { return (inValue & 7U) << 29 ; }

//-------------------- Message Buffer 1 ID Register
#define CAN_ID1(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x94)))
#define CAN0_ID1 (* ((volatile uint32_t *) (0x40024000 + 0x94)))
#define CAN1_ID1 (* ((volatile uint32_t *) (0x400A4000 + 0x94)))

  // Field (width: 11 bits): Contains standard/extended (HIGH word) identifier of message buffer.
    inline uint32_t CAN_ID1_STD (const uint32_t inValue) { return (inValue & 2047U) << 18 ; }

  // Field (width: 18 bits): Contains extended (LOW word) identifier of message buffer.
    inline uint32_t CAN_ID1_EXT (const uint32_t inValue) { return (inValue & 262143U) << 0 ; }

  // Field (width: 3 bits): Local priority. This 3-bit fieldis only used when LPRIO_EN bit is set in MCR and it only makes sense for Tx buffers. These bits are not transmitted. They are appended to the regular ID to define the transmission priority.
    inline uint32_t CAN_ID1_PRIO (const uint32_t inValue) { return (inValue & 7U) << 29 ; }

//-------------------- Message Buffer 10 ID Register
#define CAN_ID10(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x124)))
#define CAN0_ID10 (* ((volatile uint32_t *) (0x40024000 + 0x124)))
#define CAN1_ID10 (* ((volatile uint32_t *) (0x400A4000 + 0x124)))

  // Field (width: 11 bits): Contains standard/extended (HIGH word) identifier of message buffer.
    inline uint32_t CAN_ID10_STD (const uint32_t inValue) { return (inValue & 2047U) << 18 ; }

  // Field (width: 18 bits): Contains extended (LOW word) identifier of message buffer.
    inline uint32_t CAN_ID10_EXT (const uint32_t inValue) { return (inValue & 262143U) << 0 ; }

  // Field (width: 3 bits): Local priority. This 3-bit fieldis only used when LPRIO_EN bit is set in MCR and it only makes sense for Tx buffers. These bits are not transmitted. They are appended to the regular ID to define the transmission priority.
    inline uint32_t CAN_ID10_PRIO (const uint32_t inValue) { return (inValue & 7U) << 29 ; }

//-------------------- Message Buffer 11 ID Register
#define CAN_ID11(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x134)))
#define CAN0_ID11 (* ((volatile uint32_t *) (0x40024000 + 0x134)))
#define CAN1_ID11 (* ((volatile uint32_t *) (0x400A4000 + 0x134)))

  // Field (width: 11 bits): Contains standard/extended (HIGH word) identifier of message buffer.
    inline uint32_t CAN_ID11_STD (const uint32_t inValue) { return (inValue & 2047U) << 18 ; }

  // Field (width: 18 bits): Contains extended (LOW word) identifier of message buffer.
    inline uint32_t CAN_ID11_EXT (const uint32_t inValue) { return (inValue & 262143U) << 0 ; }

  // Field (width: 3 bits): Local priority. This 3-bit fieldis only used when LPRIO_EN bit is set in MCR and it only makes sense for Tx buffers. These bits are not transmitted. They are appended to the regular ID to define the transmission priority.
    inline uint32_t CAN_ID11_PRIO (const uint32_t inValue) { return (inValue & 7U) << 29 ; }

//-------------------- Message Buffer 12 ID Register
#define CAN_ID12(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x144)))
#define CAN0_ID12 (* ((volatile uint32_t *) (0x40024000 + 0x144)))
#define CAN1_ID12 (* ((volatile uint32_t *) (0x400A4000 + 0x144)))

  // Field (width: 11 bits): Contains standard/extended (HIGH word) identifier of message buffer.
    inline uint32_t CAN_ID12_STD (const uint32_t inValue) { return (inValue & 2047U) << 18 ; }

  // Field (width: 18 bits): Contains extended (LOW word) identifier of message buffer.
    inline uint32_t CAN_ID12_EXT (const uint32_t inValue) { return (inValue & 262143U) << 0 ; }

  // Field (width: 3 bits): Local priority. This 3-bit fieldis only used when LPRIO_EN bit is set in MCR and it only makes sense for Tx buffers. These bits are not transmitted. They are appended to the regular ID to define the transmission priority.
    inline uint32_t CAN_ID12_PRIO (const uint32_t inValue) { return (inValue & 7U) << 29 ; }

//-------------------- Message Buffer 13 ID Register
#define CAN_ID13(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x154)))
#define CAN0_ID13 (* ((volatile uint32_t *) (0x40024000 + 0x154)))
#define CAN1_ID13 (* ((volatile uint32_t *) (0x400A4000 + 0x154)))

  // Field (width: 11 bits): Contains standard/extended (HIGH word) identifier of message buffer.
    inline uint32_t CAN_ID13_STD (const uint32_t inValue) { return (inValue & 2047U) << 18 ; }

  // Field (width: 18 bits): Contains extended (LOW word) identifier of message buffer.
    inline uint32_t CAN_ID13_EXT (const uint32_t inValue) { return (inValue & 262143U) << 0 ; }

  // Field (width: 3 bits): Local priority. This 3-bit fieldis only used when LPRIO_EN bit is set in MCR and it only makes sense for Tx buffers. These bits are not transmitted. They are appended to the regular ID to define the transmission priority.
    inline uint32_t CAN_ID13_PRIO (const uint32_t inValue) { return (inValue & 7U) << 29 ; }

//-------------------- Message Buffer 14 ID Register
#define CAN_ID14(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x164)))
#define CAN0_ID14 (* ((volatile uint32_t *) (0x40024000 + 0x164)))
#define CAN1_ID14 (* ((volatile uint32_t *) (0x400A4000 + 0x164)))

  // Field (width: 11 bits): Contains standard/extended (HIGH word) identifier of message buffer.
    inline uint32_t CAN_ID14_STD (const uint32_t inValue) { return (inValue & 2047U) << 18 ; }

  // Field (width: 18 bits): Contains extended (LOW word) identifier of message buffer.
    inline uint32_t CAN_ID14_EXT (const uint32_t inValue) { return (inValue & 262143U) << 0 ; }

  // Field (width: 3 bits): Local priority. This 3-bit fieldis only used when LPRIO_EN bit is set in MCR and it only makes sense for Tx buffers. These bits are not transmitted. They are appended to the regular ID to define the transmission priority.
    inline uint32_t CAN_ID14_PRIO (const uint32_t inValue) { return (inValue & 7U) << 29 ; }

//-------------------- Message Buffer 15 ID Register
#define CAN_ID15(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x174)))
#define CAN0_ID15 (* ((volatile uint32_t *) (0x40024000 + 0x174)))
#define CAN1_ID15 (* ((volatile uint32_t *) (0x400A4000 + 0x174)))

  // Field (width: 11 bits): Contains standard/extended (HIGH word) identifier of message buffer.
    inline uint32_t CAN_ID15_STD (const uint32_t inValue) { return (inValue & 2047U) << 18 ; }

  // Field (width: 18 bits): Contains extended (LOW word) identifier of message buffer.
    inline uint32_t CAN_ID15_EXT (const uint32_t inValue) { return (inValue & 262143U) << 0 ; }

  // Field (width: 3 bits): Local priority. This 3-bit fieldis only used when LPRIO_EN bit is set in MCR and it only makes sense for Tx buffers. These bits are not transmitted. They are appended to the regular ID to define the transmission priority.
    inline uint32_t CAN_ID15_PRIO (const uint32_t inValue) { return (inValue & 7U) << 29 ; }

//-------------------- Message Buffer 15 WORD1 Register
#define CAN_WORD115(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x17C)))
#define CAN0_WORD115 (* ((volatile uint32_t *) (0x40024000 + 0x17C)))
#define CAN1_WORD115 (* ((volatile uint32_t *) (0x400A4000 + 0x17C)))

  // Field (width: 8 bits): Data byte 7 of Rx/Tx frame.
    inline uint32_t CAN_WORD115_DATA_BYTE_7 (const uint32_t inValue) { return (inValue & 255U) << 0 ; }

  // Field (width: 8 bits): Data byte 6 of Rx/Tx frame.
    inline uint32_t CAN_WORD115_DATA_BYTE_6 (const uint32_t inValue) { return (inValue & 255U) << 8 ; }

  // Field (width: 8 bits): Data byte 5 of Rx/Tx frame.
    inline uint32_t CAN_WORD115_DATA_BYTE_5 (const uint32_t inValue) { return (inValue & 255U) << 16 ; }

  // Field (width: 8 bits): Data byte 4 of Rx/Tx frame.
    inline uint32_t CAN_WORD115_DATA_BYTE_4 (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

//-------------------- Message Buffer 2 CS Register
#define CAN_CS2(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0xA0)))
#define CAN0_CS2 (* ((volatile uint32_t *) (0x40024000 + 0xA0)))
#define CAN1_CS2 (* ((volatile uint32_t *) (0x400A4000 + 0xA0)))

  // Field (width: 4 bits): Length of the data to be stored/transmitted.
    inline uint32_t CAN_CS2_DLC (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Field (width: 4 bits): Reserved
    inline uint32_t CAN_CS2_CODE (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Boolean field: Substitute Remote Request. Contains a fixed recessive bit.
    static const uint32_t CAN_CS2_SRR = 1U << 22 ;

  // Boolean field: Remote Transmission Request. One/zero for remote/data frame.
    static const uint32_t CAN_CS2_RTR = 1U << 20 ;

  // Field (width: 16 bits): Free-Running Counter Time stamp. This 16-bit field is a copy of the Free-Running Timer, captured for Tx and Rx frames at the time when the beginning of the Identifier field appears on the CAN bus.
    inline uint32_t CAN_CS2_TIME_STAMP (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Boolean field: ID Extended. One/zero for extended/standard format frame.
    static const uint32_t CAN_CS2_IDE = 1U << 21 ;

//-------------------- Rx 15 Mask register
#define CAN_RX15MASK(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x18)))
#define CAN0_RX15MASK (* ((volatile uint32_t *) (0x40024000 + 0x18)))
#define CAN1_RX15MASK (* ((volatile uint32_t *) (0x400A4000 + 0x18)))

//-------------------- Control 1 register
#define CAN_CTRL1(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x4)))
#define CAN0_CTRL1 (* ((volatile uint32_t *) (0x40024000 + 0x4)))
#define CAN1_CTRL1 (* ((volatile uint32_t *) (0x400A4000 + 0x4)))

  // Field (width: 2 bits): Resync Jump Width
    inline uint32_t CAN_CTRL1_RJW (const uint32_t inValue) { return (inValue & 3U) << 22 ; }

  // Boolean field: Rx Warning Interrupt Mask
    static const uint32_t CAN_CTRL1_RWRNMSK = 1U << 10 ;

  // Boolean field: Timer Sync
    static const uint32_t CAN_CTRL1_TSYN = 1U << 5 ;

  // Field (width: 3 bits): Phase Segment 1
    inline uint32_t CAN_CTRL1_PSEG1 (const uint32_t inValue) { return (inValue & 7U) << 19 ; }

  // Boolean field: CAN Engine Clock Source
    static const uint32_t CAN_CTRL1_CLKSRC = 1U << 13 ;

  // Boolean field: Bus Off Mask
    static const uint32_t CAN_CTRL1_BOFFMSK = 1U << 15 ;

  // Boolean field: Tx Warning Interrupt Mask
    static const uint32_t CAN_CTRL1_TWRNMSK = 1U << 11 ;

  // Boolean field: CAN Bit Sampling
    static const uint32_t CAN_CTRL1_SMP = 1U << 7 ;

  // Boolean field: Error Mask
    static const uint32_t CAN_CTRL1_ERRMSK = 1U << 14 ;

  // Field (width: 8 bits): Prescaler Division Factor
    inline uint32_t CAN_CTRL1_PRESDIV (const uint32_t inValue) { return (inValue & 255U) << 24 ; }

  // Boolean field: Bus Off Recovery
    static const uint32_t CAN_CTRL1_BOFFREC = 1U << 6 ;

  // Boolean field: Lowest Buffer Transmitted First
    static const uint32_t CAN_CTRL1_LBUF = 1U << 4 ;

  // Field (width: 3 bits): Propagation Segment
    inline uint32_t CAN_CTRL1_PROPSEG (const uint32_t inValue) { return (inValue & 7U) << 0 ; }

  // Boolean field: Listen-Only Mode
    static const uint32_t CAN_CTRL1_LOM = 1U << 3 ;

  // Boolean field: Loop Back Mode
    static const uint32_t CAN_CTRL1_LPB = 1U << 12 ;

  // Field (width: 3 bits): Phase Segment 2
    inline uint32_t CAN_CTRL1_PSEG2 (const uint32_t inValue) { return (inValue & 7U) << 16 ; }

//-------------------- Control 2 register
#define CAN_CTRL2(group) (* ((volatile uint32_t *) (kBaseAddress_CAN [group] + 0x34)))
#define CAN0_CTRL2 (* ((volatile uint32_t *) (0x40024000 + 0x34)))
#define CAN1_CTRL2 (* ((volatile uint32_t *) (0x400A4000 + 0x34)))

  // Boolean field: Write-Access To Memory In Freeze Mode
    static const uint32_t CAN_CTRL2_WRMFRZ = 1U << 28 ;

  // Field (width: 4 bits): Number Of Rx FIFO Filters
    inline uint32_t CAN_CTRL2_RFFN (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Field (width: 5 bits): Tx Arbitration Start Delay
    inline uint32_t CAN_CTRL2_TASD (const uint32_t inValue) { return (inValue & 31U) << 19 ; }

  // Boolean field: Mailboxes Reception Priority
    static const uint32_t CAN_CTRL2_MRP = 1U << 18 ;

  // Boolean field: Entire Frame Arbitration Field Comparison Enable For Rx Mailboxes
    static const uint32_t CAN_CTRL2_EACEN = 1U << 16 ;

  // Boolean field: Remote Request Storing
    static const uint32_t CAN_CTRL2_RRS = 1U << 17 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral group CMP
//                CMP0 at 0x40073000
//                CMP1 at 0x40073008
//                CMP2 at 0x40073010
//                CMP3 at 0x40073018
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint32_t kBaseAddress_CMP [4] = {0x40073000, 0x40073008, 0x40073010, 0x40073018} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- CMP Control Register 0
#define CMP_CR0(group) (* ((volatile uint8_t *) (kBaseAddress_CMP [group] + 0)))
#define CMP0_CR0 (* ((volatile uint8_t *) (0x40073000 + 0)))
#define CMP1_CR0 (* ((volatile uint8_t *) (0x40073008 + 0)))
#define CMP2_CR0 (* ((volatile uint8_t *) (0x40073010 + 0)))
#define CMP3_CR0 (* ((volatile uint8_t *) (0x40073018 + 0)))

  // Field (width: 3 bits): Filter Sample Count
    inline uint8_t CMP_CR0_FILTER_CNT (const uint8_t inValue) { return (inValue & 7U) << 4 ; }

  // Field (width: 2 bits): Comparator hard block hysteresis control
    inline uint8_t CMP_CR0_HYSTCTR (const uint8_t inValue) { return (inValue & 3U) << 0 ; }

//-------------------- CMP Control Register 1
#define CMP_CR1(group) (* ((volatile uint8_t *) (kBaseAddress_CMP [group] + 0x1)))
#define CMP0_CR1 (* ((volatile uint8_t *) (0x40073000 + 0x1)))
#define CMP1_CR1 (* ((volatile uint8_t *) (0x40073008 + 0x1)))
#define CMP2_CR1 (* ((volatile uint8_t *) (0x40073010 + 0x1)))
#define CMP3_CR1 (* ((volatile uint8_t *) (0x40073018 + 0x1)))

  // Boolean field: Comparator Output Select
    static const uint8_t CMP_CR1_COS = 1U << 2 ;

  // Boolean field: Comparator Module Enable
    static const uint8_t CMP_CR1_EN = 1U << 0 ;

  // Boolean field: Power Mode Select
    static const uint8_t CMP_CR1_PMODE = 1U << 4 ;

  // Boolean field: Comparator INVERT
    static const uint8_t CMP_CR1_INV = 1U << 3 ;

  // Boolean field: Trigger Mode Enable
    static const uint8_t CMP_CR1_TRIGM = 1U << 5 ;

  // Boolean field: Comparator Output Pin Enable
    static const uint8_t CMP_CR1_OPE = 1U << 1 ;

  // Boolean field: Sample Enable
    static const uint8_t CMP_CR1_SE = 1U << 7 ;

  // Boolean field: Windowing Enable
    static const uint8_t CMP_CR1_WE = 1U << 6 ;

//-------------------- MUX Control Register
#define CMP_MUXCR(group) (* ((volatile uint8_t *) (kBaseAddress_CMP [group] + 0x5)))
#define CMP0_MUXCR (* ((volatile uint8_t *) (0x40073000 + 0x5)))
#define CMP1_MUXCR (* ((volatile uint8_t *) (0x40073008 + 0x5)))
#define CMP2_MUXCR (* ((volatile uint8_t *) (0x40073010 + 0x5)))
#define CMP3_MUXCR (* ((volatile uint8_t *) (0x40073018 + 0x5)))

  // Field (width: 3 bits): Minus Input Mux Control
    inline uint8_t CMP_MUXCR_MSEL (const uint8_t inValue) { return (inValue & 7U) << 0 ; }

  // Field (width: 3 bits): Plus Input Mux Control
    inline uint8_t CMP_MUXCR_PSEL (const uint8_t inValue) { return (inValue & 7U) << 3 ; }

  // Boolean field: Pass Through Mode Enable
    static const uint8_t CMP_MUXCR_PSTM = 1U << 7 ;

//-------------------- CMP Filter Period Register
#define CMP_FPR(group) (* ((volatile uint8_t *) (kBaseAddress_CMP [group] + 0x2)))
#define CMP0_FPR (* ((volatile uint8_t *) (0x40073000 + 0x2)))
#define CMP1_FPR (* ((volatile uint8_t *) (0x40073008 + 0x2)))
#define CMP2_FPR (* ((volatile uint8_t *) (0x40073010 + 0x2)))
#define CMP3_FPR (* ((volatile uint8_t *) (0x40073018 + 0x2)))

//-------------------- DAC Control Register
#define CMP_DACCR(group) (* ((volatile uint8_t *) (kBaseAddress_CMP [group] + 0x4)))
#define CMP0_DACCR (* ((volatile uint8_t *) (0x40073000 + 0x4)))
#define CMP1_DACCR (* ((volatile uint8_t *) (0x40073008 + 0x4)))
#define CMP2_DACCR (* ((volatile uint8_t *) (0x40073010 + 0x4)))
#define CMP3_DACCR (* ((volatile uint8_t *) (0x40073018 + 0x4)))

  // Boolean field: DAC Enable
    static const uint8_t CMP_DACCR_DACEN = 1U << 7 ;

  // Field (width: 6 bits): DAC Output Voltage Select
    inline uint8_t CMP_DACCR_VOSEL (const uint8_t inValue) { return (inValue & 63U) << 0 ; }

  // Boolean field: Supply Voltage Reference Source Select
    static const uint8_t CMP_DACCR_VRSEL = 1U << 6 ;

//-------------------- CMP Status and Control Register
#define CMP_SCR(group) (* ((volatile uint8_t *) (kBaseAddress_CMP [group] + 0x3)))
#define CMP0_SCR (* ((volatile uint8_t *) (0x40073000 + 0x3)))
#define CMP1_SCR (* ((volatile uint8_t *) (0x40073008 + 0x3)))
#define CMP2_SCR (* ((volatile uint8_t *) (0x40073010 + 0x3)))
#define CMP3_SCR (* ((volatile uint8_t *) (0x40073018 + 0x3)))

  // Boolean field: DMA Enable Control
    static const uint8_t CMP_SCR_DMAEN = 1U << 6 ;

  // Boolean field: Analog Comparator Output
    static const uint8_t CMP_SCR_COUT = 1U << 0 ;

  // Boolean field: Analog Comparator Flag Falling
    static const uint8_t CMP_SCR_CFF = 1U << 1 ;

  // Boolean field: Comparator Interrupt Enable Rising
    static const uint8_t CMP_SCR_IER = 1U << 4 ;

  // Boolean field: Analog Comparator Flag Rising
    static const uint8_t CMP_SCR_CFR = 1U << 2 ;

  // Boolean field: Comparator Interrupt Enable Falling
    static const uint8_t CMP_SCR_IEF = 1U << 3 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral group DAC
//                DAC0 at 0x400CC000
//                DAC1 at 0x400CD000
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint32_t kBaseAddress_DAC [2] = {0x400CC000, 0x400CD000} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- DAC Data High Register (idx = 0 ... 15)
#define DAC_DATH(group,idx) (* ((volatile uint8_t *) (kBaseAddress_DAC [group] + 0x1 + 0x2 * (idx))))
#define DAC0_DATH(idx) (* ((volatile uint8_t *) (0x400CC000 + 0x1 + 0x2 * (idx))))
#define DAC1_DATH(idx) (* ((volatile uint8_t *) (0x400CD000 + 0x1 + 0x2 * (idx))))

  // Field (width: 4 bits): DATA1
    inline uint8_t DAC_DATH_DATA1 (const uint8_t inValue) { return (inValue & 15U) << 0 ; }

//-------------------- DAC Status Register
#define DAC_SR(group) (* ((volatile uint8_t *) (kBaseAddress_DAC [group] + 0x20)))
#define DAC0_SR (* ((volatile uint8_t *) (0x400CC000 + 0x20)))
#define DAC1_SR (* ((volatile uint8_t *) (0x400CD000 + 0x20)))

  // Boolean field: DAC Buffer Read Pointer Top Position Flag
    static const uint8_t DAC_SR_DACBFRPTF = 1U << 1 ;

  // Boolean field: DAC Buffer Watermark Flag
    static const uint8_t DAC_SR_DACBFWMF = 1U << 2 ;

  // Boolean field: DAC Buffer Read Pointer Bottom Position Flag
    static const uint8_t DAC_SR_DACBFRPBF = 1U << 0 ;

//-------------------- DAC Control Register 2
#define DAC_C2(group) (* ((volatile uint8_t *) (kBaseAddress_DAC [group] + 0x23)))
#define DAC0_C2 (* ((volatile uint8_t *) (0x400CC000 + 0x23)))
#define DAC1_C2 (* ((volatile uint8_t *) (0x400CD000 + 0x23)))

  // Field (width: 4 bits): DAC Buffer Upper Limit
    inline uint8_t DAC_C2_DACBFUP (const uint8_t inValue) { return (inValue & 15U) << 0 ; }

  // Field (width: 4 bits): DAC Buffer Read Pointer
    inline uint8_t DAC_C2_DACBFRP (const uint8_t inValue) { return (inValue & 15U) << 4 ; }

//-------------------- DAC Control Register 1
#define DAC_C1(group) (* ((volatile uint8_t *) (kBaseAddress_DAC [group] + 0x22)))
#define DAC0_C1 (* ((volatile uint8_t *) (0x400CC000 + 0x22)))
#define DAC1_C1 (* ((volatile uint8_t *) (0x400CD000 + 0x22)))

  // Field (width: 2 bits): DAC Buffer Work Mode Select
    inline uint8_t DAC_C1_DACBFMD (const uint8_t inValue) { return (inValue & 3U) << 1 ; }

  // Boolean field: DAC Buffer Enable
    static const uint8_t DAC_C1_DACBFEN = 1U << 0 ;

  // Field (width: 2 bits): DAC Buffer Watermark Select
    inline uint8_t DAC_C1_DACBFWM (const uint8_t inValue) { return (inValue & 3U) << 3 ; }

  // Boolean field: DMA Enable Select
    static const uint8_t DAC_C1_DMAEN = 1U << 7 ;

//-------------------- DAC Control Register
#define DAC_C0(group) (* ((volatile uint8_t *) (kBaseAddress_DAC [group] + 0x21)))
#define DAC0_C0 (* ((volatile uint8_t *) (0x400CC000 + 0x21)))
#define DAC1_C0 (* ((volatile uint8_t *) (0x400CD000 + 0x21)))

  // Boolean field: DAC Low Power Control
    static const uint8_t DAC_C0_LPEN = 1U << 3 ;

  // Boolean field: DAC Buffer Read Pointer Bottom Flag Interrupt Enable
    static const uint8_t DAC_C0_DACBBIEN = 1U << 0 ;

  // Boolean field: DAC Reference Select
    static const uint8_t DAC_C0_DACRFS = 1U << 6 ;

  // Boolean field: DAC Software Trigger
    static const uint8_t DAC_C0_DACSWTRG = 1U << 4 ;

  // Boolean field: DAC Trigger Select
    static const uint8_t DAC_C0_DACTRGSEL = 1U << 5 ;

  // Boolean field: DAC Enable
    static const uint8_t DAC_C0_DACEN = 1U << 7 ;

  // Boolean field: DAC Buffer Read Pointer Top Flag Interrupt Enable
    static const uint8_t DAC_C0_DACBTIEN = 1U << 1 ;

  // Boolean field: DAC Buffer Watermark Interrupt Enable
    static const uint8_t DAC_C0_DACBWIEN = 1U << 2 ;

//-------------------- DAC Data Low Register (idx = 0 ... 15)
#define DAC_DATL(group,idx) (* ((volatile uint8_t *) (kBaseAddress_DAC [group] + 0 + 0x2 * (idx))))
#define DAC0_DATL(idx) (* ((volatile uint8_t *) (0x400CC000 + 0 + 0x2 * (idx))))
#define DAC1_DATL(idx) (* ((volatile uint8_t *) (0x400CD000 + 0 + 0x2 * (idx))))

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral group FTM
//                FTM0 at 0x40038000
//                FTM1 at 0x40039000
//                FTM2 at 0x4003A000
//                FTM3 at 0x400B9000
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint32_t kBaseAddress_FTM [4] = {0x40038000, 0x40039000, 0x4003A000, 0x400B9000} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Synchronization
#define FTM_SYNC(group) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0x58)))
#define FTM0_SYNC (* ((volatile uint32_t *) (0x40038000 + 0x58)))
#define FTM1_SYNC (* ((volatile uint32_t *) (0x40039000 + 0x58)))
#define FTM2_SYNC (* ((volatile uint32_t *) (0x4003A000 + 0x58)))
#define FTM3_SYNC (* ((volatile uint32_t *) (0x400B9000 + 0x58)))

  // Boolean field: Minimum Loading Point Enable
    static const uint32_t FTM_SYNC_CNTMIN = 1U << 0 ;

  // Boolean field: Output Mask Synchronization
    static const uint32_t FTM_SYNC_SYNCHOM = 1U << 3 ;

  // Boolean field: FTM Counter Reinitialization By Synchronization (FTM counter synchronization)
    static const uint32_t FTM_SYNC_REINIT = 1U << 2 ;

  // Boolean field: PWM Synchronization Software Trigger
    static const uint32_t FTM_SYNC_SWSYNC = 1U << 7 ;

  // Boolean field: Maximum Loading Point Enable
    static const uint32_t FTM_SYNC_CNTMAX = 1U << 1 ;

  // Boolean field: PWM Synchronization Hardware Trigger 2
    static const uint32_t FTM_SYNC_TRIG2 = 1U << 6 ;

  // Boolean field: PWM Synchronization Hardware Trigger 1
    static const uint32_t FTM_SYNC_TRIG1 = 1U << 5 ;

  // Boolean field: PWM Synchronization Hardware Trigger 0
    static const uint32_t FTM_SYNC_TRIG0 = 1U << 4 ;

//-------------------- Function For Linked Channels
#define FTM_COMBINE(group) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0x64)))
#define FTM0_COMBINE (* ((volatile uint32_t *) (0x40038000 + 0x64)))
#define FTM1_COMBINE (* ((volatile uint32_t *) (0x40039000 + 0x64)))
#define FTM2_COMBINE (* ((volatile uint32_t *) (0x4003A000 + 0x64)))
#define FTM3_COMBINE (* ((volatile uint32_t *) (0x400B9000 + 0x64)))

  // Boolean field: Synchronization Enable For n = 6
    static const uint32_t FTM_COMBINE_SYNCEN3 = 1U << 29 ;

  // Boolean field: Synchronization Enable For n = 4
    static const uint32_t FTM_COMBINE_SYNCEN2 = 1U << 21 ;

  // Boolean field: Synchronization Enable For n = 2
    static const uint32_t FTM_COMBINE_SYNCEN1 = 1U << 13 ;

  // Boolean field: Synchronization Enable For n = 0
    static const uint32_t FTM_COMBINE_SYNCEN0 = 1U << 5 ;

  // Boolean field: Deadtime Enable For n = 4
    static const uint32_t FTM_COMBINE_DTEN2 = 1U << 20 ;

  // Boolean field: Deadtime Enable For n = 6
    static const uint32_t FTM_COMBINE_DTEN3 = 1U << 28 ;

  // Boolean field: Deadtime Enable For n = 0
    static const uint32_t FTM_COMBINE_DTEN0 = 1U << 4 ;

  // Boolean field: Deadtime Enable For n = 2
    static const uint32_t FTM_COMBINE_DTEN1 = 1U << 12 ;

  // Boolean field: Complement Of Channel (n) For n = 4
    static const uint32_t FTM_COMBINE_COMP2 = 1U << 17 ;

  // Boolean field: Complement Of Channel (n) for n = 6
    static const uint32_t FTM_COMBINE_COMP3 = 1U << 25 ;

  // Boolean field: Complement Of Channel (n) For n = 0
    static const uint32_t FTM_COMBINE_COMP0 = 1U << 1 ;

  // Boolean field: Complement Of Channel (n) For n = 2
    static const uint32_t FTM_COMBINE_COMP1 = 1U << 9 ;

  // Boolean field: Combine Channels For n = 2
    static const uint32_t FTM_COMBINE_COMBINE1 = 1U << 8 ;

  // Boolean field: Combine Channels For n = 0
    static const uint32_t FTM_COMBINE_COMBINE0 = 1U << 0 ;

  // Boolean field: Combine Channels For n = 6
    static const uint32_t FTM_COMBINE_COMBINE3 = 1U << 24 ;

  // Boolean field: Combine Channels For n = 4
    static const uint32_t FTM_COMBINE_COMBINE2 = 1U << 16 ;

  // Boolean field: Dual Edge Capture Mode Captures For n = 6
    static const uint32_t FTM_COMBINE_DECAP3 = 1U << 27 ;

  // Boolean field: Dual Edge Capture Mode Captures For n = 4
    static const uint32_t FTM_COMBINE_DECAP2 = 1U << 19 ;

  // Boolean field: Dual Edge Capture Mode Captures For n = 2
    static const uint32_t FTM_COMBINE_DECAP1 = 1U << 11 ;

  // Boolean field: Dual Edge Capture Mode Captures For n = 0
    static const uint32_t FTM_COMBINE_DECAP0 = 1U << 3 ;

  // Boolean field: Dual Edge Capture Mode Enable For n = 4
    static const uint32_t FTM_COMBINE_DECAPEN2 = 1U << 18 ;

  // Boolean field: Dual Edge Capture Mode Enable For n = 6
    static const uint32_t FTM_COMBINE_DECAPEN3 = 1U << 26 ;

  // Boolean field: Dual Edge Capture Mode Enable For n = 0
    static const uint32_t FTM_COMBINE_DECAPEN0 = 1U << 2 ;

  // Boolean field: Dual Edge Capture Mode Enable For n = 2
    static const uint32_t FTM_COMBINE_DECAPEN1 = 1U << 10 ;

  // Boolean field: Fault Control Enable For n = 6
    static const uint32_t FTM_COMBINE_FAULTEN3 = 1U << 30 ;

  // Boolean field: Fault Control Enable For n = 4
    static const uint32_t FTM_COMBINE_FAULTEN2 = 1U << 22 ;

  // Boolean field: Fault Control Enable For n = 2
    static const uint32_t FTM_COMBINE_FAULTEN1 = 1U << 14 ;

  // Boolean field: Fault Control Enable For n = 0
    static const uint32_t FTM_COMBINE_FAULTEN0 = 1U << 6 ;

//-------------------- Counter Initial Value
#define FTM_CNTIN(group) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0x4C)))
#define FTM0_CNTIN (* ((volatile uint32_t *) (0x40038000 + 0x4C)))
#define FTM1_CNTIN (* ((volatile uint32_t *) (0x40039000 + 0x4C)))
#define FTM2_CNTIN (* ((volatile uint32_t *) (0x4003A000 + 0x4C)))
#define FTM3_CNTIN (* ((volatile uint32_t *) (0x400B9000 + 0x4C)))

  // Field (width: 16 bits): Initial Value Of The FTM Counter
    inline uint32_t FTM_CNTIN_INIT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Configuration
#define FTM_CONF(group) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0x84)))
#define FTM0_CONF (* ((volatile uint32_t *) (0x40038000 + 0x84)))
#define FTM1_CONF (* ((volatile uint32_t *) (0x40039000 + 0x84)))
#define FTM2_CONF (* ((volatile uint32_t *) (0x4003A000 + 0x84)))
#define FTM3_CONF (* ((volatile uint32_t *) (0x400B9000 + 0x84)))

  // Boolean field: Global Time Base Output
    static const uint32_t FTM_CONF_GTBEOUT = 1U << 10 ;

  // Field (width: 5 bits): TOF Frequency
    inline uint32_t FTM_CONF_NUMTOF (const uint32_t inValue) { return (inValue & 31U) << 0 ; }

  // Field (width: 2 bits): BDM Mode
    inline uint32_t FTM_CONF_BDMMODE (const uint32_t inValue) { return (inValue & 3U) << 6 ; }

  // Boolean field: Global Time Base Enable
    static const uint32_t FTM_CONF_GTBEEN = 1U << 9 ;

//-------------------- Synchronization Configuration
#define FTM_SYNCONF(group) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0x8C)))
#define FTM0_SYNCONF (* ((volatile uint32_t *) (0x40038000 + 0x8C)))
#define FTM1_SYNCONF (* ((volatile uint32_t *) (0x40039000 + 0x8C)))
#define FTM2_SYNCONF (* ((volatile uint32_t *) (0x4003A000 + 0x8C)))
#define FTM3_SYNCONF (* ((volatile uint32_t *) (0x400B9000 + 0x8C)))

  // Boolean field: FTM counter synchronization is activated by the software trigger.
    static const uint32_t FTM_SYNCONF_SWRSTCNT = 1U << 8 ;

  // Boolean field: Synchronization Mode
    static const uint32_t FTM_SYNCONF_SYNCMODE = 1U << 7 ;

  // Boolean field: Output mask synchronization is activated by the software trigger.
    static const uint32_t FTM_SYNCONF_SWOM = 1U << 10 ;

  // Boolean field: SWOCTRL Register Synchronization
    static const uint32_t FTM_SYNCONF_SWOC = 1U << 5 ;

  // Boolean field: Software output control synchronization is activated by the software trigger.
    static const uint32_t FTM_SYNCONF_SWSOC = 1U << 12 ;

  // Boolean field: Inverting control synchronization is activated by the software trigger.
    static const uint32_t FTM_SYNCONF_SWINVC = 1U << 11 ;

  // Boolean field: Hardware Trigger Mode
    static const uint32_t FTM_SYNCONF_HWTRIGMODE = 1U << 0 ;

  // Boolean field: Output mask synchronization is activated by a hardware trigger.
    static const uint32_t FTM_SYNCONF_HWOM = 1U << 18 ;

  // Boolean field: FTM counter synchronization is activated by a hardware trigger.
    static const uint32_t FTM_SYNCONF_HWRSTCNT = 1U << 16 ;

  // Boolean field: CNTIN Register Synchronization
    static const uint32_t FTM_SYNCONF_CNTINC = 1U << 2 ;

  // Boolean field: MOD, CNTIN, and CV registers synchronization is activated by the software trigger.
    static const uint32_t FTM_SYNCONF_SWWRBUF = 1U << 9 ;

  // Boolean field: MOD, CNTIN, and CV registers synchronization is activated by a hardware trigger.
    static const uint32_t FTM_SYNCONF_HWWRBUF = 1U << 17 ;

  // Boolean field: INVCTRL Register Synchronization
    static const uint32_t FTM_SYNCONF_INVC = 1U << 4 ;

  // Boolean field: Software output control synchronization is activated by a hardware trigger.
    static const uint32_t FTM_SYNCONF_HWSOC = 1U << 20 ;

  // Boolean field: Inverting control synchronization is activated by a hardware trigger.
    static const uint32_t FTM_SYNCONF_HWINVC = 1U << 19 ;

//-------------------- Channel (n) Status And Control (idx = 0 ... 7)
#define FTM_CSC(group,idx) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0xC + 0x8 * (idx))))
#define FTM0_CSC(idx) (* ((volatile uint32_t *) (0x40038000 + 0xC + 0x8 * (idx))))
#define FTM1_CSC(idx) (* ((volatile uint32_t *) (0x40039000 + 0xC + 0x8 * (idx))))
#define FTM2_CSC(idx) (* ((volatile uint32_t *) (0x4003A000 + 0xC + 0x8 * (idx))))
#define FTM3_CSC(idx) (* ((volatile uint32_t *) (0x400B9000 + 0xC + 0x8 * (idx))))

  // Boolean field: DMA Enable
    static const uint32_t FTM_CSC_DMA = 1U << 0 ;

  // Boolean field: Channel Flag
    static const uint32_t FTM_CSC_CHF = 1U << 7 ;

  // Boolean field: Edge or Level Select
    static const uint32_t FTM_CSC_ELSB = 1U << 3 ;

  // Boolean field: Edge or Level Select
    static const uint32_t FTM_CSC_ELSA = 1U << 2 ;

  // Boolean field: Channel Mode Select
    static const uint32_t FTM_CSC_MSB = 1U << 5 ;

  // Boolean field: Channel Mode Select
    static const uint32_t FTM_CSC_MSA = 1U << 4 ;

  // Boolean field: Channel Interrupt Enable
    static const uint32_t FTM_CSC_CHIE = 1U << 6 ;

//-------------------- Channels Polarity
#define FTM_POL(group) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0x70)))
#define FTM0_POL (* ((volatile uint32_t *) (0x40038000 + 0x70)))
#define FTM1_POL (* ((volatile uint32_t *) (0x40039000 + 0x70)))
#define FTM2_POL (* ((volatile uint32_t *) (0x4003A000 + 0x70)))
#define FTM3_POL (* ((volatile uint32_t *) (0x400B9000 + 0x70)))

  // Boolean field: Channel 7 Polarity
    static const uint32_t FTM_POL_POL7 = 1U << 7 ;

  // Boolean field: Channel 6 Polarity
    static const uint32_t FTM_POL_POL6 = 1U << 6 ;

  // Boolean field: Channel 5 Polarity
    static const uint32_t FTM_POL_POL5 = 1U << 5 ;

  // Boolean field: Channel 4 Polarity
    static const uint32_t FTM_POL_POL4 = 1U << 4 ;

  // Boolean field: Channel 3 Polarity
    static const uint32_t FTM_POL_POL3 = 1U << 3 ;

  // Boolean field: Channel 2 Polarity
    static const uint32_t FTM_POL_POL2 = 1U << 2 ;

  // Boolean field: Channel 1 Polarity
    static const uint32_t FTM_POL_POL1 = 1U << 1 ;

  // Boolean field: Channel 0 Polarity
    static const uint32_t FTM_POL_POL0 = 1U << 0 ;

//-------------------- Features Mode Selection
#define FTM_MODE(group) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0x54)))
#define FTM0_MODE (* ((volatile uint32_t *) (0x40038000 + 0x54)))
#define FTM1_MODE (* ((volatile uint32_t *) (0x40039000 + 0x54)))
#define FTM2_MODE (* ((volatile uint32_t *) (0x4003A000 + 0x54)))
#define FTM3_MODE (* ((volatile uint32_t *) (0x400B9000 + 0x54)))

  // Boolean field: FTM Enable
    static const uint32_t FTM_MODE_FTMEN = 1U << 0 ;

  // Boolean field: Fault Interrupt Enable
    static const uint32_t FTM_MODE_FAULTIE = 1U << 7 ;

  // Boolean field: PWM Synchronization Mode
    static const uint32_t FTM_MODE_PWMSYNC = 1U << 3 ;

  // Field (width: 2 bits): Fault Control Mode
    inline uint32_t FTM_MODE_FAULTM (const uint32_t inValue) { return (inValue & 3U) << 5 ; }

  // Boolean field: Initialize The Channels Output
    static const uint32_t FTM_MODE_INIT = 1U << 1 ;

  // Boolean field: Capture Test Mode Enable
    static const uint32_t FTM_MODE_CAPTEST = 1U << 4 ;

  // Boolean field: Write Protection Disable
    static const uint32_t FTM_MODE_WPDIS = 1U << 2 ;

//-------------------- FTM Inverting Control
#define FTM_INVCTRL(group) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0x90)))
#define FTM0_INVCTRL (* ((volatile uint32_t *) (0x40038000 + 0x90)))
#define FTM1_INVCTRL (* ((volatile uint32_t *) (0x40039000 + 0x90)))
#define FTM2_INVCTRL (* ((volatile uint32_t *) (0x4003A000 + 0x90)))
#define FTM3_INVCTRL (* ((volatile uint32_t *) (0x400B9000 + 0x90)))

  // Boolean field: Pair Channels 1 Inverting Enable
    static const uint32_t FTM_INVCTRL_INV1EN = 1U << 1 ;

  // Boolean field: Pair Channels 2 Inverting Enable
    static const uint32_t FTM_INVCTRL_INV2EN = 1U << 2 ;

  // Boolean field: Pair Channels 0 Inverting Enable
    static const uint32_t FTM_INVCTRL_INV0EN = 1U << 0 ;

  // Boolean field: Pair Channels 3 Inverting Enable
    static const uint32_t FTM_INVCTRL_INV3EN = 1U << 3 ;

//-------------------- Capture And Compare Status
#define FTM_STATUS(group) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0x50)))
#define FTM0_STATUS (* ((volatile uint32_t *) (0x40038000 + 0x50)))
#define FTM1_STATUS (* ((volatile uint32_t *) (0x40039000 + 0x50)))
#define FTM2_STATUS (* ((volatile uint32_t *) (0x4003A000 + 0x50)))
#define FTM3_STATUS (* ((volatile uint32_t *) (0x400B9000 + 0x50)))

  // Boolean field: Channel 5 Flag
    static const uint32_t FTM_STATUS_CH5F = 1U << 5 ;

  // Boolean field: Channel 4 Flag
    static const uint32_t FTM_STATUS_CH4F = 1U << 4 ;

  // Boolean field: Channel 2 Flag
    static const uint32_t FTM_STATUS_CH2F = 1U << 2 ;

  // Boolean field: Channel 3 Flag
    static const uint32_t FTM_STATUS_CH3F = 1U << 3 ;

  // Boolean field: Channel 1 Flag
    static const uint32_t FTM_STATUS_CH1F = 1U << 1 ;

  // Boolean field: Channel 0 Flag
    static const uint32_t FTM_STATUS_CH0F = 1U << 0 ;

  // Boolean field: Channel 6 Flag
    static const uint32_t FTM_STATUS_CH6F = 1U << 6 ;

  // Boolean field: Channel 7 Flag
    static const uint32_t FTM_STATUS_CH7F = 1U << 7 ;

//-------------------- Counter
#define FTM_CNT(group) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0x4)))
#define FTM0_CNT (* ((volatile uint32_t *) (0x40038000 + 0x4)))
#define FTM1_CNT (* ((volatile uint32_t *) (0x40039000 + 0x4)))
#define FTM2_CNT (* ((volatile uint32_t *) (0x4003A000 + 0x4)))
#define FTM3_CNT (* ((volatile uint32_t *) (0x400B9000 + 0x4)))

  // Field (width: 16 bits): Counter Value
    inline uint32_t FTM_CNT_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Output Mask
#define FTM_OUTMASK(group) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0x60)))
#define FTM0_OUTMASK (* ((volatile uint32_t *) (0x40038000 + 0x60)))
#define FTM1_OUTMASK (* ((volatile uint32_t *) (0x40039000 + 0x60)))
#define FTM2_OUTMASK (* ((volatile uint32_t *) (0x4003A000 + 0x60)))
#define FTM3_OUTMASK (* ((volatile uint32_t *) (0x400B9000 + 0x60)))

  // Boolean field: Channel 1 Output Mask
    static const uint32_t FTM_OUTMASK_CH1OM = 1U << 1 ;

  // Boolean field: Channel 0 Output Mask
    static const uint32_t FTM_OUTMASK_CH0OM = 1U << 0 ;

  // Boolean field: Channel 5 Output Mask
    static const uint32_t FTM_OUTMASK_CH5OM = 1U << 5 ;

  // Boolean field: Channel 7 Output Mask
    static const uint32_t FTM_OUTMASK_CH7OM = 1U << 7 ;

  // Boolean field: Channel 3 Output Mask
    static const uint32_t FTM_OUTMASK_CH3OM = 1U << 3 ;

  // Boolean field: Channel 4 Output Mask
    static const uint32_t FTM_OUTMASK_CH4OM = 1U << 4 ;

  // Boolean field: Channel 6 Output Mask
    static const uint32_t FTM_OUTMASK_CH6OM = 1U << 6 ;

  // Boolean field: Channel 2 Output Mask
    static const uint32_t FTM_OUTMASK_CH2OM = 1U << 2 ;

//-------------------- Fault Mode Status
#define FTM_FMS(group) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0x74)))
#define FTM0_FMS (* ((volatile uint32_t *) (0x40038000 + 0x74)))
#define FTM1_FMS (* ((volatile uint32_t *) (0x40039000 + 0x74)))
#define FTM2_FMS (* ((volatile uint32_t *) (0x4003A000 + 0x74)))
#define FTM3_FMS (* ((volatile uint32_t *) (0x400B9000 + 0x74)))

  // Boolean field: Write Protection Enable
    static const uint32_t FTM_FMS_WPEN = 1U << 6 ;

  // Boolean field: Fault Inputs
    static const uint32_t FTM_FMS_FAULTIN = 1U << 5 ;

  // Boolean field: Fault Detection Flag 1
    static const uint32_t FTM_FMS_FAULTF1 = 1U << 1 ;

  // Boolean field: Fault Detection Flag 0
    static const uint32_t FTM_FMS_FAULTF0 = 1U << 0 ;

  // Boolean field: Fault Detection Flag 3
    static const uint32_t FTM_FMS_FAULTF3 = 1U << 3 ;

  // Boolean field: Fault Detection Flag 2
    static const uint32_t FTM_FMS_FAULTF2 = 1U << 2 ;

  // Boolean field: Fault Detection Flag
    static const uint32_t FTM_FMS_FAULTF = 1U << 7 ;

//-------------------- FTM Software Output Control
#define FTM_SWOCTRL(group) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0x94)))
#define FTM0_SWOCTRL (* ((volatile uint32_t *) (0x40038000 + 0x94)))
#define FTM1_SWOCTRL (* ((volatile uint32_t *) (0x40039000 + 0x94)))
#define FTM2_SWOCTRL (* ((volatile uint32_t *) (0x4003A000 + 0x94)))
#define FTM3_SWOCTRL (* ((volatile uint32_t *) (0x400B9000 + 0x94)))

  // Boolean field: Channel 5 Software Output Control Enable
    static const uint32_t FTM_SWOCTRL_CH5OC = 1U << 5 ;

  // Boolean field: Channel 0 Software Output Control Enable
    static const uint32_t FTM_SWOCTRL_CH0OC = 1U << 0 ;

  // Boolean field: Channel 4 Software Output Control Value
    static const uint32_t FTM_SWOCTRL_CH4OCV = 1U << 12 ;

  // Boolean field: Channel 1 Software Output Control Value
    static const uint32_t FTM_SWOCTRL_CH1OCV = 1U << 9 ;

  // Boolean field: Channel 6 Software Output Control Value
    static const uint32_t FTM_SWOCTRL_CH6OCV = 1U << 14 ;

  // Boolean field: Channel 3 Software Output Control Value
    static const uint32_t FTM_SWOCTRL_CH3OCV = 1U << 11 ;

  // Boolean field: Channel 1 Software Output Control Enable
    static const uint32_t FTM_SWOCTRL_CH1OC = 1U << 1 ;

  // Boolean field: Channel 2 Software Output Control Enable
    static const uint32_t FTM_SWOCTRL_CH2OC = 1U << 2 ;

  // Boolean field: Channel 0 Software Output Control Value
    static const uint32_t FTM_SWOCTRL_CH0OCV = 1U << 8 ;

  // Boolean field: Channel 2 Software Output Control Value
    static const uint32_t FTM_SWOCTRL_CH2OCV = 1U << 10 ;

  // Boolean field: Channel 6 Software Output Control Enable
    static const uint32_t FTM_SWOCTRL_CH6OC = 1U << 6 ;

  // Boolean field: Channel 4 Software Output Control Enable
    static const uint32_t FTM_SWOCTRL_CH4OC = 1U << 4 ;

  // Boolean field: Channel 3 Software Output Control Enable
    static const uint32_t FTM_SWOCTRL_CH3OC = 1U << 3 ;

  // Boolean field: Channel 5 Software Output Control Value
    static const uint32_t FTM_SWOCTRL_CH5OCV = 1U << 13 ;

  // Boolean field: Channel 7 Software Output Control Value
    static const uint32_t FTM_SWOCTRL_CH7OCV = 1U << 15 ;

  // Boolean field: Channel 7 Software Output Control Enable
    static const uint32_t FTM_SWOCTRL_CH7OC = 1U << 7 ;

//-------------------- Fault Control
#define FTM_FLTCTRL(group) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0x7C)))
#define FTM0_FLTCTRL (* ((volatile uint32_t *) (0x40038000 + 0x7C)))
#define FTM1_FLTCTRL (* ((volatile uint32_t *) (0x40039000 + 0x7C)))
#define FTM2_FLTCTRL (* ((volatile uint32_t *) (0x4003A000 + 0x7C)))
#define FTM3_FLTCTRL (* ((volatile uint32_t *) (0x400B9000 + 0x7C)))

  // Boolean field: Fault Input 3 Enable
    static const uint32_t FTM_FLTCTRL_FAULT3EN = 1U << 3 ;

  // Boolean field: Fault Input 1 Enable
    static const uint32_t FTM_FLTCTRL_FAULT1EN = 1U << 1 ;

  // Boolean field: Fault Input 1 Filter Enable
    static const uint32_t FTM_FLTCTRL_FFLTR1EN = 1U << 5 ;

  // Boolean field: Fault Input 0 Enable
    static const uint32_t FTM_FLTCTRL_FAULT0EN = 1U << 0 ;

  // Boolean field: Fault Input 2 Filter Enable
    static const uint32_t FTM_FLTCTRL_FFLTR2EN = 1U << 6 ;

  // Boolean field: Fault Input 2 Enable
    static const uint32_t FTM_FLTCTRL_FAULT2EN = 1U << 2 ;

  // Field (width: 4 bits): Fault Input Filter
    inline uint32_t FTM_FLTCTRL_FFVAL (const uint32_t inValue) { return (inValue & 15U) << 8 ; }

  // Boolean field: Fault Input 0 Filter Enable
    static const uint32_t FTM_FLTCTRL_FFLTR0EN = 1U << 4 ;

  // Boolean field: Fault Input 3 Filter Enable
    static const uint32_t FTM_FLTCTRL_FFLTR3EN = 1U << 7 ;

//-------------------- FTM PWM Load
#define FTM_PWMLOAD(group) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0x98)))
#define FTM0_PWMLOAD (* ((volatile uint32_t *) (0x40038000 + 0x98)))
#define FTM1_PWMLOAD (* ((volatile uint32_t *) (0x40039000 + 0x98)))
#define FTM2_PWMLOAD (* ((volatile uint32_t *) (0x4003A000 + 0x98)))
#define FTM3_PWMLOAD (* ((volatile uint32_t *) (0x400B9000 + 0x98)))

  // Boolean field: Load Enable
    static const uint32_t FTM_PWMLOAD_LDOK = 1U << 9 ;

  // Boolean field: Channel 2 Select
    static const uint32_t FTM_PWMLOAD_CH2SEL = 1U << 2 ;

  // Boolean field: Channel 5 Select
    static const uint32_t FTM_PWMLOAD_CH5SEL = 1U << 5 ;

  // Boolean field: Channel 6 Select
    static const uint32_t FTM_PWMLOAD_CH6SEL = 1U << 6 ;

  // Boolean field: Channel 3 Select
    static const uint32_t FTM_PWMLOAD_CH3SEL = 1U << 3 ;

  // Boolean field: Channel 7 Select
    static const uint32_t FTM_PWMLOAD_CH7SEL = 1U << 7 ;

  // Boolean field: Channel 1 Select
    static const uint32_t FTM_PWMLOAD_CH1SEL = 1U << 1 ;

  // Boolean field: Channel 0 Select
    static const uint32_t FTM_PWMLOAD_CH0SEL = 1U << 0 ;

  // Boolean field: Channel 4 Select
    static const uint32_t FTM_PWMLOAD_CH4SEL = 1U << 4 ;

//-------------------- FTM Fault Input Polarity
#define FTM_FLTPOL(group) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0x88)))
#define FTM0_FLTPOL (* ((volatile uint32_t *) (0x40038000 + 0x88)))
#define FTM1_FLTPOL (* ((volatile uint32_t *) (0x40039000 + 0x88)))
#define FTM2_FLTPOL (* ((volatile uint32_t *) (0x4003A000 + 0x88)))
#define FTM3_FLTPOL (* ((volatile uint32_t *) (0x400B9000 + 0x88)))

  // Boolean field: Fault Input 3 Polarity
    static const uint32_t FTM_FLTPOL_FLT3POL = 1U << 3 ;

  // Boolean field: Fault Input 0 Polarity
    static const uint32_t FTM_FLTPOL_FLT0POL = 1U << 0 ;

  // Boolean field: Fault Input 2 Polarity
    static const uint32_t FTM_FLTPOL_FLT2POL = 1U << 2 ;

  // Boolean field: Fault Input 1 Polarity
    static const uint32_t FTM_FLTPOL_FLT1POL = 1U << 1 ;

//-------------------- Quadrature Decoder Control And Status
#define FTM_QDCTRL(group) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0x80)))
#define FTM0_QDCTRL (* ((volatile uint32_t *) (0x40038000 + 0x80)))
#define FTM1_QDCTRL (* ((volatile uint32_t *) (0x40039000 + 0x80)))
#define FTM2_QDCTRL (* ((volatile uint32_t *) (0x4003A000 + 0x80)))
#define FTM3_QDCTRL (* ((volatile uint32_t *) (0x400B9000 + 0x80)))

  // Boolean field: Phase A Input Polarity
    static const uint32_t FTM_QDCTRL_PHAPOL = 1U << 5 ;

  // Boolean field: Phase B Input Polarity
    static const uint32_t FTM_QDCTRL_PHBPOL = 1U << 4 ;

  // Boolean field: Phase B Input Filter Enable
    static const uint32_t FTM_QDCTRL_PHBFLTREN = 1U << 6 ;

  // Boolean field: FTM Counter Direction In Quadrature Decoder Mode
    static const uint32_t FTM_QDCTRL_QUADIR = 1U << 2 ;

  // Boolean field: Phase A Input Filter Enable
    static const uint32_t FTM_QDCTRL_PHAFLTREN = 1U << 7 ;

  // Boolean field: Timer Overflow Direction In Quadrature Decoder Mode
    static const uint32_t FTM_QDCTRL_TOFDIR = 1U << 1 ;

  // Boolean field: Quadrature Decoder Mode
    static const uint32_t FTM_QDCTRL_QUADMODE = 1U << 3 ;

  // Boolean field: Quadrature Decoder Mode Enable
    static const uint32_t FTM_QDCTRL_QUADEN = 1U << 0 ;

//-------------------- Input Capture Filter Control
#define FTM_FILTER(group) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0x78)))
#define FTM0_FILTER (* ((volatile uint32_t *) (0x40038000 + 0x78)))
#define FTM1_FILTER (* ((volatile uint32_t *) (0x40039000 + 0x78)))
#define FTM2_FILTER (* ((volatile uint32_t *) (0x4003A000 + 0x78)))
#define FTM3_FILTER (* ((volatile uint32_t *) (0x400B9000 + 0x78)))

  // Field (width: 4 bits): Channel 1 Input Filter
    inline uint32_t FTM_FILTER_CH1FVAL (const uint32_t inValue) { return (inValue & 15U) << 4 ; }

  // Field (width: 4 bits): Channel 0 Input Filter
    inline uint32_t FTM_FILTER_CH0FVAL (const uint32_t inValue) { return (inValue & 15U) << 0 ; }

  // Field (width: 4 bits): Channel 3 Input Filter
    inline uint32_t FTM_FILTER_CH3FVAL (const uint32_t inValue) { return (inValue & 15U) << 12 ; }

  // Field (width: 4 bits): Channel 2 Input Filter
    inline uint32_t FTM_FILTER_CH2FVAL (const uint32_t inValue) { return (inValue & 15U) << 8 ; }

//-------------------- FTM External Trigger
#define FTM_EXTTRIG(group) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0x6C)))
#define FTM0_EXTTRIG (* ((volatile uint32_t *) (0x40038000 + 0x6C)))
#define FTM1_EXTTRIG (* ((volatile uint32_t *) (0x40039000 + 0x6C)))
#define FTM2_EXTTRIG (* ((volatile uint32_t *) (0x4003A000 + 0x6C)))
#define FTM3_EXTTRIG (* ((volatile uint32_t *) (0x400B9000 + 0x6C)))

  // Boolean field: Channel 0 Trigger Enable
    static const uint32_t FTM_EXTTRIG_CH0TRIG = 1U << 4 ;

  // Boolean field: Initialization Trigger Enable
    static const uint32_t FTM_EXTTRIG_INITTRIGEN = 1U << 6 ;

  // Boolean field: Channel Trigger Flag
    static const uint32_t FTM_EXTTRIG_TRIGF = 1U << 7 ;

  // Boolean field: Channel 5 Trigger Enable
    static const uint32_t FTM_EXTTRIG_CH5TRIG = 1U << 3 ;

  // Boolean field: Channel 2 Trigger Enable
    static const uint32_t FTM_EXTTRIG_CH2TRIG = 1U << 0 ;

  // Boolean field: Channel 3 Trigger Enable
    static const uint32_t FTM_EXTTRIG_CH3TRIG = 1U << 1 ;

  // Boolean field: Channel 4 Trigger Enable
    static const uint32_t FTM_EXTTRIG_CH4TRIG = 1U << 2 ;

  // Boolean field: Channel 1 Trigger Enable
    static const uint32_t FTM_EXTTRIG_CH1TRIG = 1U << 5 ;

//-------------------- Initial State For Channels Output
#define FTM_OUTINIT(group) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0x5C)))
#define FTM0_OUTINIT (* ((volatile uint32_t *) (0x40038000 + 0x5C)))
#define FTM1_OUTINIT (* ((volatile uint32_t *) (0x40039000 + 0x5C)))
#define FTM2_OUTINIT (* ((volatile uint32_t *) (0x4003A000 + 0x5C)))
#define FTM3_OUTINIT (* ((volatile uint32_t *) (0x400B9000 + 0x5C)))

  // Boolean field: Channel 1 Output Initialization Value
    static const uint32_t FTM_OUTINIT_CH1OI = 1U << 1 ;

  // Boolean field: Channel 5 Output Initialization Value
    static const uint32_t FTM_OUTINIT_CH5OI = 1U << 5 ;

  // Boolean field: Channel 0 Output Initialization Value
    static const uint32_t FTM_OUTINIT_CH0OI = 1U << 0 ;

  // Boolean field: Channel 3 Output Initialization Value
    static const uint32_t FTM_OUTINIT_CH3OI = 1U << 3 ;

  // Boolean field: Channel 4 Output Initialization Value
    static const uint32_t FTM_OUTINIT_CH4OI = 1U << 4 ;

  // Boolean field: Channel 7 Output Initialization Value
    static const uint32_t FTM_OUTINIT_CH7OI = 1U << 7 ;

  // Boolean field: Channel 2 Output Initialization Value
    static const uint32_t FTM_OUTINIT_CH2OI = 1U << 2 ;

  // Boolean field: Channel 6 Output Initialization Value
    static const uint32_t FTM_OUTINIT_CH6OI = 1U << 6 ;

//-------------------- Channel (n) Value (idx = 0 ... 7)
#define FTM_CV(group,idx) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0x10 + 0x8 * (idx))))
#define FTM0_CV(idx) (* ((volatile uint32_t *) (0x40038000 + 0x10 + 0x8 * (idx))))
#define FTM1_CV(idx) (* ((volatile uint32_t *) (0x40039000 + 0x10 + 0x8 * (idx))))
#define FTM2_CV(idx) (* ((volatile uint32_t *) (0x4003A000 + 0x10 + 0x8 * (idx))))
#define FTM3_CV(idx) (* ((volatile uint32_t *) (0x400B9000 + 0x10 + 0x8 * (idx))))

  // Field (width: 16 bits): Channel Value
    inline uint32_t FTM_CV_VAL (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Status And Control
#define FTM_SC(group) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0)))
#define FTM0_SC (* ((volatile uint32_t *) (0x40038000 + 0)))
#define FTM1_SC (* ((volatile uint32_t *) (0x40039000 + 0)))
#define FTM2_SC (* ((volatile uint32_t *) (0x4003A000 + 0)))
#define FTM3_SC (* ((volatile uint32_t *) (0x400B9000 + 0)))

  // Field (width: 3 bits): Prescale Factor Selection
    inline uint32_t FTM_SC_PS (const uint32_t inValue) { return (inValue & 7U) << 0 ; }

  // Field (width: 2 bits): Clock Source Selection
    inline uint32_t FTM_SC_CLKS (const uint32_t inValue) { return (inValue & 3U) << 3 ; }

  // Boolean field: Timer Overflow Flag
    static const uint32_t FTM_SC_TOF = 1U << 7 ;

  // Boolean field: Center-Aligned PWM Select
    static const uint32_t FTM_SC_CPWMS = 1U << 5 ;

  // Boolean field: Timer Overflow Interrupt Enable
    static const uint32_t FTM_SC_TOIE = 1U << 6 ;

//-------------------- Modulo
#define FTM_MOD(group) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0x8)))
#define FTM0_MOD (* ((volatile uint32_t *) (0x40038000 + 0x8)))
#define FTM1_MOD (* ((volatile uint32_t *) (0x40039000 + 0x8)))
#define FTM2_MOD (* ((volatile uint32_t *) (0x4003A000 + 0x8)))
#define FTM3_MOD (* ((volatile uint32_t *) (0x400B9000 + 0x8)))

  // Field (width: 16 bits): Modulo Value
    inline uint32_t FTM_MOD_MOD (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Deadtime Insertion Control
#define FTM_DEADTIME(group) (* ((volatile uint32_t *) (kBaseAddress_FTM [group] + 0x68)))
#define FTM0_DEADTIME (* ((volatile uint32_t *) (0x40038000 + 0x68)))
#define FTM1_DEADTIME (* ((volatile uint32_t *) (0x40039000 + 0x68)))
#define FTM2_DEADTIME (* ((volatile uint32_t *) (0x4003A000 + 0x68)))
#define FTM3_DEADTIME (* ((volatile uint32_t *) (0x400B9000 + 0x68)))

  // Field (width: 6 bits): Deadtime Value
    inline uint32_t FTM_DEADTIME_DTVAL (const uint32_t inValue) { return (inValue & 63U) << 0 ; }

  // Field (width: 2 bits): Deadtime Prescaler Value
    inline uint32_t FTM_DEADTIME_DTPS (const uint32_t inValue) { return (inValue & 3U) << 6 ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral group GPIO
//                GPIOA at 0x400FF000
//                GPIOB at 0x400FF040
//                GPIOC at 0x400FF080
//                GPIOD at 0x400FF0C0
//                GPIOE at 0x400FF100
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint32_t kBaseAddress_GPIO [5] = {0x400FF000, 0x400FF040, 0x400FF080, 0x400FF0C0, 0x400FF100} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Port Set Output Register
#define GPIO_PSOR(group) (* ((volatile uint32_t *) (kBaseAddress_GPIO [group] + 0x4)))
#define GPIOA_PSOR (* ((volatile uint32_t *) (0x400FF000 + 0x4)))
#define GPIOB_PSOR (* ((volatile uint32_t *) (0x400FF040 + 0x4)))
#define GPIOC_PSOR (* ((volatile uint32_t *) (0x400FF080 + 0x4)))
#define GPIOD_PSOR (* ((volatile uint32_t *) (0x400FF0C0 + 0x4)))
#define GPIOE_PSOR (* ((volatile uint32_t *) (0x400FF100 + 0x4)))

//-------------------- Port Data Input Register
#define GPIO_PDIR(group) (* ((const volatile uint32_t *) (kBaseAddress_GPIO [group] + 0x10)))
#define GPIOA_PDIR (* ((const volatile uint32_t *) (0x400FF000 + 0x10)))
#define GPIOB_PDIR (* ((const volatile uint32_t *) (0x400FF040 + 0x10)))
#define GPIOC_PDIR (* ((const volatile uint32_t *) (0x400FF080 + 0x10)))
#define GPIOD_PDIR (* ((const volatile uint32_t *) (0x400FF0C0 + 0x10)))
#define GPIOE_PDIR (* ((const volatile uint32_t *) (0x400FF100 + 0x10)))

//-------------------- Port Data Output Register
#define GPIO_PDOR(group) (* ((volatile uint32_t *) (kBaseAddress_GPIO [group] + 0)))
#define GPIOA_PDOR (* ((volatile uint32_t *) (0x400FF000 + 0)))
#define GPIOB_PDOR (* ((volatile uint32_t *) (0x400FF040 + 0)))
#define GPIOC_PDOR (* ((volatile uint32_t *) (0x400FF080 + 0)))
#define GPIOD_PDOR (* ((volatile uint32_t *) (0x400FF0C0 + 0)))
#define GPIOE_PDOR (* ((volatile uint32_t *) (0x400FF100 + 0)))

//-------------------- Port Clear Output Register
#define GPIO_PCOR(group) (* ((volatile uint32_t *) (kBaseAddress_GPIO [group] + 0x8)))
#define GPIOA_PCOR (* ((volatile uint32_t *) (0x400FF000 + 0x8)))
#define GPIOB_PCOR (* ((volatile uint32_t *) (0x400FF040 + 0x8)))
#define GPIOC_PCOR (* ((volatile uint32_t *) (0x400FF080 + 0x8)))
#define GPIOD_PCOR (* ((volatile uint32_t *) (0x400FF0C0 + 0x8)))
#define GPIOE_PCOR (* ((volatile uint32_t *) (0x400FF100 + 0x8)))

//-------------------- Port Data Direction Register
#define GPIO_PDDR(group) (* ((volatile uint32_t *) (kBaseAddress_GPIO [group] + 0x14)))
#define GPIOA_PDDR (* ((volatile uint32_t *) (0x400FF000 + 0x14)))
#define GPIOB_PDDR (* ((volatile uint32_t *) (0x400FF040 + 0x14)))
#define GPIOC_PDDR (* ((volatile uint32_t *) (0x400FF080 + 0x14)))
#define GPIOD_PDDR (* ((volatile uint32_t *) (0x400FF0C0 + 0x14)))
#define GPIOE_PDDR (* ((volatile uint32_t *) (0x400FF100 + 0x14)))

//-------------------- Port Toggle Output Register
#define GPIO_PTOR(group) (* ((volatile uint32_t *) (kBaseAddress_GPIO [group] + 0xC)))
#define GPIOA_PTOR (* ((volatile uint32_t *) (0x400FF000 + 0xC)))
#define GPIOB_PTOR (* ((volatile uint32_t *) (0x400FF040 + 0xC)))
#define GPIOC_PTOR (* ((volatile uint32_t *) (0x400FF080 + 0xC)))
#define GPIOD_PTOR (* ((volatile uint32_t *) (0x400FF0C0 + 0xC)))
#define GPIOE_PTOR (* ((volatile uint32_t *) (0x400FF100 + 0xC)))

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral group I2C
//                I2C0 at 0x40066000
//                I2C1 at 0x40067000
//                I2C2 at 0x400E6000
//                I2C3 at 0x400E7000
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint32_t kBaseAddress_I2C [4] = {0x40066000, 0x40067000, 0x400E6000, 0x400E7000} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- I2C Data I/O register
#define I2C_D(group) (* ((volatile uint8_t *) (kBaseAddress_I2C [group] + 0x4)))
#define I2C0_D (* ((volatile uint8_t *) (0x40066000 + 0x4)))
#define I2C1_D (* ((volatile uint8_t *) (0x40067000 + 0x4)))
#define I2C2_D (* ((volatile uint8_t *) (0x400E6000 + 0x4)))
#define I2C3_D (* ((volatile uint8_t *) (0x400E7000 + 0x4)))

//-------------------- I2C Frequency Divider register
#define I2C_F(group) (* ((volatile uint8_t *) (kBaseAddress_I2C [group] + 0x1)))
#define I2C0_F (* ((volatile uint8_t *) (0x40066000 + 0x1)))
#define I2C1_F (* ((volatile uint8_t *) (0x40067000 + 0x1)))
#define I2C2_F (* ((volatile uint8_t *) (0x400E6000 + 0x1)))
#define I2C3_F (* ((volatile uint8_t *) (0x400E7000 + 0x1)))

  // Field (width: 6 bits): ClockRate
    inline uint8_t I2C_F_ICR (const uint8_t inValue) { return (inValue & 63U) << 0 ; }

  // Field (width: 2 bits): Multiplier Factor
    inline uint8_t I2C_F_MULT (const uint8_t inValue) { return (inValue & 3U) << 6 ; }

//-------------------- I2C SCL Low Timeout Register Low
#define I2C_SLTL(group) (* ((volatile uint8_t *) (kBaseAddress_I2C [group] + 0xB)))
#define I2C0_SLTL (* ((volatile uint8_t *) (0x40066000 + 0xB)))
#define I2C1_SLTL (* ((volatile uint8_t *) (0x40067000 + 0xB)))
#define I2C2_SLTL (* ((volatile uint8_t *) (0x400E6000 + 0xB)))
#define I2C3_SLTL (* ((volatile uint8_t *) (0x400E7000 + 0xB)))

//-------------------- I2C Programmable Input Glitch Filter Register
#define I2C_FLT(group) (* ((volatile uint8_t *) (kBaseAddress_I2C [group] + 0x6)))
#define I2C0_FLT (* ((volatile uint8_t *) (0x40066000 + 0x6)))
#define I2C1_FLT (* ((volatile uint8_t *) (0x40067000 + 0x6)))
#define I2C2_FLT (* ((volatile uint8_t *) (0x400E6000 + 0x6)))
#define I2C3_FLT (* ((volatile uint8_t *) (0x400E7000 + 0x6)))

  // Boolean field: Stop Hold Enable
    static const uint8_t I2C_FLT_SHEN = 1U << 7 ;

  // Boolean field: I2C Bus Stop or Start Interrupt Enable
    static const uint8_t I2C_FLT_SSIE = 1U << 5 ;

  // Boolean field: I2C Bus Stop Detect Flag
    static const uint8_t I2C_FLT_STOPF = 1U << 6 ;

  // Boolean field: I2C Bus Start Detect Flag
    static const uint8_t I2C_FLT_STARTF = 1U << 4 ;

  // Field (width: 4 bits): I2C Programmable Filter Factor
    inline uint8_t I2C_FLT_FLT (const uint8_t inValue) { return (inValue & 15U) << 0 ; }

//-------------------- I2C SCL Low Timeout Register High
#define I2C_SLTH(group) (* ((volatile uint8_t *) (kBaseAddress_I2C [group] + 0xA)))
#define I2C0_SLTH (* ((volatile uint8_t *) (0x40066000 + 0xA)))
#define I2C1_SLTH (* ((volatile uint8_t *) (0x40067000 + 0xA)))
#define I2C2_SLTH (* ((volatile uint8_t *) (0x400E6000 + 0xA)))
#define I2C3_SLTH (* ((volatile uint8_t *) (0x400E7000 + 0xA)))

//-------------------- I2C Address Register 1
#define I2C_A1(group) (* ((volatile uint8_t *) (kBaseAddress_I2C [group] + 0)))
#define I2C0_A1 (* ((volatile uint8_t *) (0x40066000 + 0)))
#define I2C1_A1 (* ((volatile uint8_t *) (0x40067000 + 0)))
#define I2C2_A1 (* ((volatile uint8_t *) (0x400E6000 + 0)))
#define I2C3_A1 (* ((volatile uint8_t *) (0x400E7000 + 0)))

  // Field (width: 7 bits): Address
    inline uint8_t I2C_A1_AD (const uint8_t inValue) { return (inValue & 127U) << 1 ; }

//-------------------- I2C Status register
#define I2C_S(group) (* ((volatile uint8_t *) (kBaseAddress_I2C [group] + 0x3)))
#define I2C0_S (* ((volatile uint8_t *) (0x40066000 + 0x3)))
#define I2C1_S (* ((volatile uint8_t *) (0x40067000 + 0x3)))
#define I2C2_S (* ((volatile uint8_t *) (0x400E6000 + 0x3)))
#define I2C3_S (* ((volatile uint8_t *) (0x400E7000 + 0x3)))

  // Boolean field: Interrupt Flag
    static const uint8_t I2C_S_IICIF = 1U << 1 ;

  // Boolean field: Bus Busy
    static const uint8_t I2C_S_BUSY = 1U << 5 ;

  // Boolean field: Range Address Match
    static const uint8_t I2C_S_RAM = 1U << 3 ;

  // Boolean field: Receive Acknowledge
    static const uint8_t I2C_S_RXAK = 1U << 0 ;

  // Boolean field: Slave Read/Write
    static const uint8_t I2C_S_SRW = 1U << 2 ;

  // Boolean field: Transfer Complete Flag
    static const uint8_t I2C_S_TCF = 1U << 7 ;

  // Boolean field: Addressed As A Slave
    static const uint8_t I2C_S_IAAS = 1U << 6 ;

  // Boolean field: Arbitration Lost
    static const uint8_t I2C_S_ARBL = 1U << 4 ;

//-------------------- I2C Address Register 2
#define I2C_A2(group) (* ((volatile uint8_t *) (kBaseAddress_I2C [group] + 0x9)))
#define I2C0_A2 (* ((volatile uint8_t *) (0x40066000 + 0x9)))
#define I2C1_A2 (* ((volatile uint8_t *) (0x40067000 + 0x9)))
#define I2C2_A2 (* ((volatile uint8_t *) (0x400E6000 + 0x9)))
#define I2C3_A2 (* ((volatile uint8_t *) (0x400E7000 + 0x9)))

  // Field (width: 7 bits): SMBus Address
    inline uint8_t I2C_A2_SAD (const uint8_t inValue) { return (inValue & 127U) << 1 ; }

//-------------------- I2C Range Address register
#define I2C_RA(group) (* ((volatile uint8_t *) (kBaseAddress_I2C [group] + 0x7)))
#define I2C0_RA (* ((volatile uint8_t *) (0x40066000 + 0x7)))
#define I2C1_RA (* ((volatile uint8_t *) (0x40067000 + 0x7)))
#define I2C2_RA (* ((volatile uint8_t *) (0x400E6000 + 0x7)))
#define I2C3_RA (* ((volatile uint8_t *) (0x400E7000 + 0x7)))

  // Field (width: 7 bits): Range Slave Address
    inline uint8_t I2C_RA_RAD (const uint8_t inValue) { return (inValue & 127U) << 1 ; }

//-------------------- I2C Control Register 2
#define I2C_C2(group) (* ((volatile uint8_t *) (kBaseAddress_I2C [group] + 0x5)))
#define I2C0_C2 (* ((volatile uint8_t *) (0x40066000 + 0x5)))
#define I2C1_C2 (* ((volatile uint8_t *) (0x40067000 + 0x5)))
#define I2C2_C2 (* ((volatile uint8_t *) (0x400E6000 + 0x5)))
#define I2C3_C2 (* ((volatile uint8_t *) (0x400E7000 + 0x5)))

  // Boolean field: High Drive Select
    static const uint8_t I2C_C2_HDRS = 1U << 5 ;

  // Boolean field: Address Extension
    static const uint8_t I2C_C2_ADEXT = 1U << 6 ;

  // Boolean field: Slave Baud Rate Control
    static const uint8_t I2C_C2_SBRC = 1U << 4 ;

  // Boolean field: General Call Address Enable
    static const uint8_t I2C_C2_GCAEN = 1U << 7 ;

  // Boolean field: Range Address Matching Enable
    static const uint8_t I2C_C2_RMEN = 1U << 3 ;

  // Field (width: 3 bits): Slave Address
    inline uint8_t I2C_C2_AD (const uint8_t inValue) { return (inValue & 7U) << 0 ; }

//-------------------- I2C Control Register 1
#define I2C_C1(group) (* ((volatile uint8_t *) (kBaseAddress_I2C [group] + 0x2)))
#define I2C0_C1 (* ((volatile uint8_t *) (0x40066000 + 0x2)))
#define I2C1_C1 (* ((volatile uint8_t *) (0x40067000 + 0x2)))
#define I2C2_C1 (* ((volatile uint8_t *) (0x400E6000 + 0x2)))
#define I2C3_C1 (* ((volatile uint8_t *) (0x400E7000 + 0x2)))

  // Boolean field: DMA Enable
    static const uint8_t I2C_C1_DMAEN = 1U << 0 ;

  // Boolean field: I2C Enable
    static const uint8_t I2C_C1_IICEN = 1U << 7 ;

  // Boolean field: Transmit Mode Select
    static const uint8_t I2C_C1_TX = 1U << 4 ;

  // Boolean field: Transmit Acknowledge Enable
    static const uint8_t I2C_C1_TXAK = 1U << 3 ;

  // Boolean field: Master Mode Select
    static const uint8_t I2C_C1_MST = 1U << 5 ;

  // Boolean field: I2C Interrupt Enable
    static const uint8_t I2C_C1_IICIE = 1U << 6 ;

  // Boolean field: Repeat START
    static const uint8_t I2C_C1_RSTA = 1U << 2 ;

  // Boolean field: Wakeup Enable
    static const uint8_t I2C_C1_WUEN = 1U << 1 ;

//-------------------- I2C SMBus Control and Status register
#define I2C_SMB(group) (* ((volatile uint8_t *) (kBaseAddress_I2C [group] + 0x8)))
#define I2C0_SMB (* ((volatile uint8_t *) (0x40066000 + 0x8)))
#define I2C1_SMB (* ((volatile uint8_t *) (0x40067000 + 0x8)))
#define I2C2_SMB (* ((volatile uint8_t *) (0x400E6000 + 0x8)))
#define I2C3_SMB (* ((volatile uint8_t *) (0x400E7000 + 0x8)))

  // Boolean field: Fast NACK/ACK Enable
    static const uint8_t I2C_SMB_FACK = 1U << 7 ;

  // Boolean field: SCL Low Timeout Flag
    static const uint8_t I2C_SMB_SLTF = 1U << 3 ;

  // Boolean field: Timeout Counter Clock Select
    static const uint8_t I2C_SMB_TCKSEL = 1U << 4 ;

  // Boolean field: SCL High Timeout Flag 1
    static const uint8_t I2C_SMB_SHTF1 = 1U << 2 ;

  // Boolean field: SCL High Timeout Flag 2
    static const uint8_t I2C_SMB_SHTF2 = 1U << 1 ;

  // Boolean field: Second I2C Address Enable
    static const uint8_t I2C_SMB_SIICAEN = 1U << 5 ;

  // Boolean field: SMBus Alert Response Address Enable
    static const uint8_t I2C_SMB_ALERTEN = 1U << 6 ;

  // Boolean field: SHTF2 Interrupt Enable
    static const uint8_t I2C_SMB_SHTF2IE = 1U << 0 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral group PORT
//                PORTA at 0x40049000
//                PORTB at 0x4004A000
//                PORTC at 0x4004B000
//                PORTD at 0x4004C000
//                PORTE at 0x4004D000
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint32_t kBaseAddress_PORT [5] = {0x40049000, 0x4004A000, 0x4004B000, 0x4004C000, 0x4004D000} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Digital Filter Clock Register
#define PORT_DFCR(group) (* ((volatile uint32_t *) (kBaseAddress_PORT [group] + 0xC4)))
#define PORTA_DFCR (* ((volatile uint32_t *) (0x40049000 + 0xC4)))
#define PORTB_DFCR (* ((volatile uint32_t *) (0x4004A000 + 0xC4)))
#define PORTC_DFCR (* ((volatile uint32_t *) (0x4004B000 + 0xC4)))
#define PORTD_DFCR (* ((volatile uint32_t *) (0x4004C000 + 0xC4)))
#define PORTE_DFCR (* ((volatile uint32_t *) (0x4004D000 + 0xC4)))

  // Boolean field: Clock Source
    static const uint32_t PORT_DFCR_CS = 1U << 0 ;

//-------------------- Digital Filter Enable Register
#define PORT_DFER(group) (* ((volatile uint32_t *) (kBaseAddress_PORT [group] + 0xC0)))
#define PORTA_DFER (* ((volatile uint32_t *) (0x40049000 + 0xC0)))
#define PORTB_DFER (* ((volatile uint32_t *) (0x4004A000 + 0xC0)))
#define PORTC_DFER (* ((volatile uint32_t *) (0x4004B000 + 0xC0)))
#define PORTD_DFER (* ((volatile uint32_t *) (0x4004C000 + 0xC0)))
#define PORTE_DFER (* ((volatile uint32_t *) (0x4004D000 + 0xC0)))

//-------------------- Interrupt Status Flag Register
#define PORT_ISFR(group) (* ((volatile uint32_t *) (kBaseAddress_PORT [group] + 0xA0)))
#define PORTA_ISFR (* ((volatile uint32_t *) (0x40049000 + 0xA0)))
#define PORTB_ISFR (* ((volatile uint32_t *) (0x4004A000 + 0xA0)))
#define PORTC_ISFR (* ((volatile uint32_t *) (0x4004B000 + 0xA0)))
#define PORTD_ISFR (* ((volatile uint32_t *) (0x4004C000 + 0xA0)))
#define PORTE_ISFR (* ((volatile uint32_t *) (0x4004D000 + 0xA0)))

//-------------------- Digital Filter Width Register
#define PORT_DFWR(group) (* ((volatile uint32_t *) (kBaseAddress_PORT [group] + 0xC8)))
#define PORTA_DFWR (* ((volatile uint32_t *) (0x40049000 + 0xC8)))
#define PORTB_DFWR (* ((volatile uint32_t *) (0x4004A000 + 0xC8)))
#define PORTC_DFWR (* ((volatile uint32_t *) (0x4004B000 + 0xC8)))
#define PORTD_DFWR (* ((volatile uint32_t *) (0x4004C000 + 0xC8)))
#define PORTE_DFWR (* ((volatile uint32_t *) (0x4004D000 + 0xC8)))

  // Field (width: 5 bits): Filter Length
    inline uint32_t PORT_DFWR_FILT (const uint32_t inValue) { return (inValue & 31U) << 0 ; }

//-------------------- Global Pin Control Low Register
#define PORT_GPCLR(group) (* ((volatile uint32_t *) (kBaseAddress_PORT [group] + 0x80)))
#define PORTA_GPCLR (* ((volatile uint32_t *) (0x40049000 + 0x80)))
#define PORTB_GPCLR (* ((volatile uint32_t *) (0x4004A000 + 0x80)))
#define PORTC_GPCLR (* ((volatile uint32_t *) (0x4004B000 + 0x80)))
#define PORTD_GPCLR (* ((volatile uint32_t *) (0x4004C000 + 0x80)))
#define PORTE_GPCLR (* ((volatile uint32_t *) (0x4004D000 + 0x80)))

  // Field (width: 16 bits): Global Pin Write Data
    inline uint32_t PORT_GPCLR_GPWD (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Field (width: 16 bits): Global Pin Write Enable
    inline uint32_t PORT_GPCLR_GPWE (const uint32_t inValue) { return (inValue & 65535U) << 16 ; }

//-------------------- Global Pin Control High Register
#define PORT_GPCHR(group) (* ((volatile uint32_t *) (kBaseAddress_PORT [group] + 0x84)))
#define PORTA_GPCHR (* ((volatile uint32_t *) (0x40049000 + 0x84)))
#define PORTB_GPCHR (* ((volatile uint32_t *) (0x4004A000 + 0x84)))
#define PORTC_GPCHR (* ((volatile uint32_t *) (0x4004B000 + 0x84)))
#define PORTD_GPCHR (* ((volatile uint32_t *) (0x4004C000 + 0x84)))
#define PORTE_GPCHR (* ((volatile uint32_t *) (0x4004D000 + 0x84)))

  // Field (width: 16 bits): Global Pin Write Data
    inline uint32_t PORT_GPCHR_GPWD (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Field (width: 16 bits): Global Pin Write Enable
    inline uint32_t PORT_GPCHR_GPWE (const uint32_t inValue) { return (inValue & 65535U) << 16 ; }

//-------------------- Pin Control Register n (idx = 0 ... 31)
#define PORT_PCR(group,idx) (* ((volatile uint32_t *) (kBaseAddress_PORT [group] + 0 + 0x4 * (idx))))
#define PORTA_PCR(idx) (* ((volatile uint32_t *) (0x40049000 + 0 + 0x4 * (idx))))
#define PORTB_PCR(idx) (* ((volatile uint32_t *) (0x4004A000 + 0 + 0x4 * (idx))))
#define PORTC_PCR(idx) (* ((volatile uint32_t *) (0x4004B000 + 0 + 0x4 * (idx))))
#define PORTD_PCR(idx) (* ((volatile uint32_t *) (0x4004C000 + 0 + 0x4 * (idx))))
#define PORTE_PCR(idx) (* ((volatile uint32_t *) (0x4004D000 + 0 + 0x4 * (idx))))

  // Boolean field: Pull Select
    static const uint32_t PORT_PCR_PS = 1U << 0 ;

  // Boolean field: Passive Filter Enable
    static const uint32_t PORT_PCR_PFE = 1U << 4 ;

  // Boolean field: Interrupt Status Flag
    static const uint32_t PORT_PCR_ISF = 1U << 24 ;

  // Boolean field: Slew Rate Enable
    static const uint32_t PORT_PCR_SRE = 1U << 2 ;

  // Field (width: 3 bits): Pin Mux Control
    inline uint32_t PORT_PCR_MUX (const uint32_t inValue) { return (inValue & 7U) << 8 ; }

  // Boolean field: Lock Register
    static const uint32_t PORT_PCR_LK = 1U << 15 ;

  // Boolean field: Pull Enable
    static const uint32_t PORT_PCR_PE = 1U << 1 ;

  // Field (width: 4 bits): Interrupt Configuration
    inline uint32_t PORT_PCR_IRQC (const uint32_t inValue) { return (inValue & 15U) << 16 ; }

  // Boolean field: Drive Strength Enable
    static const uint32_t PORT_PCR_DSE = 1U << 6 ;

  // Boolean field: Open Drain Enable
    static const uint32_t PORT_PCR_ODE = 1U << 5 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral group SPI
//                SPI0 at 0x4002C000
//                SPI1 at 0x4002D000
//                SPI2 at 0x400AC000
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint32_t kBaseAddress_SPI [3] = {0x4002C000, 0x4002D000, 0x400AC000} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Receive FIFO Registers (idx = 0 ... 3)
#define SPI_RXFR(group,idx) (* ((const volatile uint32_t *) (kBaseAddress_SPI [group] + 0x7C + 0x4 * (idx))))
#define SPI0_RXFR(idx) (* ((const volatile uint32_t *) (0x4002C000 + 0x7C + 0x4 * (idx))))
#define SPI1_RXFR(idx) (* ((const volatile uint32_t *) (0x4002D000 + 0x7C + 0x4 * (idx))))
#define SPI2_RXFR(idx) (* ((const volatile uint32_t *) (0x400AC000 + 0x7C + 0x4 * (idx))))

//-------------------- PUSH TX FIFO Register In Slave Mode
#define SPI_PUSHR_SLAVE(group) (* ((volatile uint32_t *) (kBaseAddress_SPI [group] + 0x34)))
#define SPI0_PUSHR_SLAVE (* ((volatile uint32_t *) (0x4002C000 + 0x34)))
#define SPI1_PUSHR_SLAVE (* ((volatile uint32_t *) (0x4002D000 + 0x34)))
#define SPI2_PUSHR_SLAVE (* ((volatile uint32_t *) (0x400AC000 + 0x34)))

//-------------------- PUSH TX FIFO Register In Master Mode
#define SPI_PUSHR(group) (* ((volatile uint32_t *) (kBaseAddress_SPI [group] + 0x34)))
#define SPI0_PUSHR (* ((volatile uint32_t *) (0x4002C000 + 0x34)))
#define SPI1_PUSHR (* ((volatile uint32_t *) (0x4002D000 + 0x34)))
#define SPI2_PUSHR (* ((volatile uint32_t *) (0x400AC000 + 0x34)))

  // Boolean field: Continuous Peripheral Chip Select Enable
    static const uint32_t SPI_PUSHR_CONT = 1U << 31 ;

  // Boolean field: Clear Transfer Counter
    static const uint32_t SPI_PUSHR_CTCNT = 1U << 26 ;

  // Field (width: 6 bits): Select which PCS signals are to be asserted for the transfer
    inline uint32_t SPI_PUSHR_PCS (const uint32_t inValue) { return (inValue & 63U) << 16 ; }

  // Boolean field: End Of Queue
    static const uint32_t SPI_PUSHR_EOQ = 1U << 27 ;

  // Field (width: 3 bits): Clock and Transfer Attributes Select
    inline uint32_t SPI_PUSHR_CTAS (const uint32_t inValue) { return (inValue & 7U) << 28 ; }

  // Field (width: 16 bits): Transmit Data
    inline uint32_t SPI_PUSHR_TXDATA (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- DMA/Interrupt Request Select and Enable Register
#define SPI_RSER(group) (* ((volatile uint32_t *) (kBaseAddress_SPI [group] + 0x30)))
#define SPI0_RSER (* ((volatile uint32_t *) (0x4002C000 + 0x30)))
#define SPI1_RSER (* ((volatile uint32_t *) (0x4002D000 + 0x30)))
#define SPI2_RSER (* ((volatile uint32_t *) (0x400AC000 + 0x30)))

  // Boolean field: Receive FIFO Drain Request Enable
    static const uint32_t SPI_RSER_RFDF_RE = 1U << 17 ;

  // Boolean field: Transmit FIFO Fill DMA or Interrupt Request Select
    static const uint32_t SPI_RSER_TFFF_DIRS = 1U << 24 ;

  // Boolean field: Receive FIFO Overflow Request Enable
    static const uint32_t SPI_RSER_RFOF_RE = 1U << 19 ;

  // Boolean field: Transmission Complete Request Enable
    static const uint32_t SPI_RSER_TCF_RE = 1U << 31 ;

  // Boolean field: Finished Request Enable
    static const uint32_t SPI_RSER_EOQF_RE = 1U << 28 ;

  // Boolean field: Transmit FIFO Fill Request Enable
    static const uint32_t SPI_RSER_TFFF_RE = 1U << 25 ;

  // Boolean field: Transmit FIFO Underflow Request Enable
    static const uint32_t SPI_RSER_TFUF_RE = 1U << 27 ;

  // Boolean field: Receive FIFO Drain DMA or Interrupt Request Select
    static const uint32_t SPI_RSER_RFDF_DIRS = 1U << 16 ;

//-------------------- Status Register
#define SPI_SR(group) (* ((volatile uint32_t *) (kBaseAddress_SPI [group] + 0x2C)))
#define SPI0_SR (* ((volatile uint32_t *) (0x4002C000 + 0x2C)))
#define SPI1_SR (* ((volatile uint32_t *) (0x4002D000 + 0x2C)))
#define SPI2_SR (* ((volatile uint32_t *) (0x400AC000 + 0x2C)))

  // Boolean field: TX and RX Status
    static const uint32_t SPI_SR_TXRXS = 1U << 30 ;

  // Boolean field: End of Queue Flag
    static const uint32_t SPI_SR_EOQF = 1U << 28 ;

  // Boolean field: Transmit FIFO Underflow Flag
    static const uint32_t SPI_SR_TFUF = 1U << 27 ;

  // Field (width: 4 bits): Transmit Next Pointer
    inline uint32_t SPI_SR_TXNXTPTR (const uint32_t inValue) { return (inValue & 15U) << 8 ; }

  // Field (width: 4 bits): Pop Next Pointer
    inline uint32_t SPI_SR_POPNXTPTR (const uint32_t inValue) { return (inValue & 15U) << 0 ; }

  // Field (width: 4 bits): RX FIFO Counter
    inline uint32_t SPI_SR_RXCTR (const uint32_t inValue) { return (inValue & 15U) << 4 ; }

  // Boolean field: Transfer Complete Flag
    static const uint32_t SPI_SR_TCF = 1U << 31 ;

  // Field (width: 4 bits): TX FIFO Counter
    inline uint32_t SPI_SR_TXCTR (const uint32_t inValue) { return (inValue & 15U) << 12 ; }

  // Boolean field: Transmit FIFO Fill Flag
    static const uint32_t SPI_SR_TFFF = 1U << 25 ;

  // Boolean field: Receive FIFO Drain Flag
    static const uint32_t SPI_SR_RFDF = 1U << 17 ;

  // Boolean field: Receive FIFO Overflow Flag
    static const uint32_t SPI_SR_RFOF = 1U << 19 ;

//-------------------- Clock and Transfer Attributes Register (In Master Mode) (idx = 0 ... 1)
#define SPI_CTAR(group,idx) (* ((volatile uint32_t *) (kBaseAddress_SPI [group] + 0xC + 0x4 * (idx))))
#define SPI0_CTAR(idx) (* ((volatile uint32_t *) (0x4002C000 + 0xC + 0x4 * (idx))))
#define SPI1_CTAR(idx) (* ((volatile uint32_t *) (0x4002D000 + 0xC + 0x4 * (idx))))
#define SPI2_CTAR(idx) (* ((volatile uint32_t *) (0x400AC000 + 0xC + 0x4 * (idx))))

  // Field (width: 2 bits): PCS to SCK Delay Prescaler
    inline uint32_t SPI_CTAR_PCSSCK (const uint32_t inValue) { return (inValue & 3U) << 22 ; }

  // Boolean field: Clock Polarity
    static const uint32_t SPI_CTAR_CPOL = 1U << 26 ;

  // Field (width: 2 bits): Baud Rate Prescaler
    inline uint32_t SPI_CTAR_PBR (const uint32_t inValue) { return (inValue & 3U) << 16 ; }

  // Field (width: 2 bits): Delay after Transfer Prescaler
    inline uint32_t SPI_CTAR_PDT (const uint32_t inValue) { return (inValue & 3U) << 18 ; }

  // Boolean field: Clock Phase
    static const uint32_t SPI_CTAR_CPHA = 1U << 25 ;

  // Field (width: 4 bits): After SCK Delay Scaler
    inline uint32_t SPI_CTAR_ASC (const uint32_t inValue) { return (inValue & 15U) << 8 ; }

  // Field (width: 4 bits): PCS to SCK Delay Scaler
    inline uint32_t SPI_CTAR_CSSCK (const uint32_t inValue) { return (inValue & 15U) << 12 ; }

  // Field (width: 4 bits): Frame Size
    inline uint32_t SPI_CTAR_FMSZ (const uint32_t inValue) { return (inValue & 15U) << 27 ; }

  // Field (width: 4 bits): Baud Rate Scaler
    inline uint32_t SPI_CTAR_BR (const uint32_t inValue) { return (inValue & 15U) << 0 ; }

  // Boolean field: LSB First
    static const uint32_t SPI_CTAR_LSBFE = 1U << 24 ;

  // Field (width: 4 bits): Delay After Transfer Scaler
    inline uint32_t SPI_CTAR_DT (const uint32_t inValue) { return (inValue & 15U) << 4 ; }

  // Boolean field: Double Baud Rate
    static const uint32_t SPI_CTAR_DBR = 1U << 31 ;

  // Field (width: 2 bits): After SCK Delay Prescaler
    inline uint32_t SPI_CTAR_PASC (const uint32_t inValue) { return (inValue & 3U) << 20 ; }

//-------------------- Transfer Count Register
#define SPI_TCR(group) (* ((volatile uint32_t *) (kBaseAddress_SPI [group] + 0x8)))
#define SPI0_TCR (* ((volatile uint32_t *) (0x4002C000 + 0x8)))
#define SPI1_TCR (* ((volatile uint32_t *) (0x4002D000 + 0x8)))
#define SPI2_TCR (* ((volatile uint32_t *) (0x400AC000 + 0x8)))

  // Field (width: 16 bits): SPI Transfer Counter
    inline uint32_t SPI_TCR_SPI_TCNT (const uint32_t inValue) { return (inValue & 65535U) << 16 ; }

//-------------------- POP RX FIFO Register
#define SPI_POPR(group) (* ((const volatile uint32_t *) (kBaseAddress_SPI [group] + 0x38)))
#define SPI0_POPR (* ((const volatile uint32_t *) (0x4002C000 + 0x38)))
#define SPI1_POPR (* ((const volatile uint32_t *) (0x4002D000 + 0x38)))
#define SPI2_POPR (* ((const volatile uint32_t *) (0x400AC000 + 0x38)))

//-------------------- Clock and Transfer Attributes Register (In Slave Mode)
#define SPI_CTAR_SLAVE(group) (* ((volatile uint32_t *) (kBaseAddress_SPI [group] + 0xC)))
#define SPI0_CTAR_SLAVE (* ((volatile uint32_t *) (0x4002C000 + 0xC)))
#define SPI1_CTAR_SLAVE (* ((volatile uint32_t *) (0x4002D000 + 0xC)))
#define SPI2_CTAR_SLAVE (* ((volatile uint32_t *) (0x400AC000 + 0xC)))

  // Boolean field: Clock Polarity
    static const uint32_t SPI_CTAR_SLAVE_CPOL = 1U << 26 ;

  // Boolean field: Clock Phase
    static const uint32_t SPI_CTAR_SLAVE_CPHA = 1U << 25 ;

  // Field (width: 4 bits): Frame Size
    inline uint32_t SPI_CTAR_SLAVE_FMSZ (const uint32_t inValue) { return (inValue & 15U) << 27 ; }

//-------------------- Transmit FIFO Registers (idx = 0 ... 3)
#define SPI_TXFR(group,idx) (* ((const volatile uint32_t *) (kBaseAddress_SPI [group] + 0x3C + 0x4 * (idx))))
#define SPI0_TXFR(idx) (* ((const volatile uint32_t *) (0x4002C000 + 0x3C + 0x4 * (idx))))
#define SPI1_TXFR(idx) (* ((const volatile uint32_t *) (0x4002D000 + 0x3C + 0x4 * (idx))))
#define SPI2_TXFR(idx) (* ((const volatile uint32_t *) (0x400AC000 + 0x3C + 0x4 * (idx))))

  // Field (width: 16 bits): Transmit Data
    inline uint32_t SPI_TXFR_TXDATA (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

  // Field (width: 16 bits): Transmit Command or Transmit Data
    inline uint32_t SPI_TXFR_TXCMD_TXDATA (const uint32_t inValue) { return (inValue & 65535U) << 16 ; }

//-------------------- Module Configuration Register
#define SPI_MCR(group) (* ((volatile uint32_t *) (kBaseAddress_SPI [group] + 0)))
#define SPI0_MCR (* ((volatile uint32_t *) (0x4002C000 + 0)))
#define SPI1_MCR (* ((volatile uint32_t *) (0x4002D000 + 0)))
#define SPI2_MCR (* ((volatile uint32_t *) (0x400AC000 + 0)))

  // Boolean field: Disable Receive FIFO
    static const uint32_t SPI_MCR_DIS_RXF = 1U << 12 ;

  // Field (width: 6 bits): Peripheral Chip Select x Inactive State
    inline uint32_t SPI_MCR_PCSIS (const uint32_t inValue) { return (inValue & 63U) << 16 ; }

  // Boolean field: Halt
    static const uint32_t SPI_MCR_HALT = 1U << 0 ;

  // Boolean field: Peripheral Chip Select Strobe Enable
    static const uint32_t SPI_MCR_PCSSE = 1U << 25 ;

  // Boolean field: Modified Transfer Format Enable
    static const uint32_t SPI_MCR_MTFE = 1U << 26 ;

  // Boolean field: Continuous SCK Enable
    static const uint32_t SPI_MCR_CONT_SCKE = 1U << 30 ;

  // Boolean field: Receive FIFO Overflow Overwrite Enable
    static const uint32_t SPI_MCR_ROOE = 1U << 24 ;

  // Boolean field: Master/Slave Mode Select
    static const uint32_t SPI_MCR_MSTR = 1U << 31 ;

  // Boolean field: CLR_RXF
    static const uint32_t SPI_MCR_CLR_RXF = 1U << 10 ;

  // Boolean field: Disable Transmit FIFO
    static const uint32_t SPI_MCR_DIS_TXF = 1U << 13 ;

  // Boolean field: Clear TX FIFO
    static const uint32_t SPI_MCR_CLR_TXF = 1U << 11 ;

  // Boolean field: Module Disable
    static const uint32_t SPI_MCR_MDIS = 1U << 14 ;

  // Boolean field: Doze Enable
    static const uint32_t SPI_MCR_DOZE = 1U << 15 ;

  // Boolean field: Freeze
    static const uint32_t SPI_MCR_FRZ = 1U << 27 ;

  // Field (width: 2 bits): SPI Configuration.
    inline uint32_t SPI_MCR_DCONF (const uint32_t inValue) { return (inValue & 3U) << 28 ; }

  // Field (width: 2 bits): Sample Point
    inline uint32_t SPI_MCR_SMPL_PT (const uint32_t inValue) { return (inValue & 3U) << 8 ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral group TPM
//                TPM1 at 0x400C9000
//                TPM2 at 0x400CA000
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint32_t kBaseAddress_TPM [2] = {0x400C9000, 0x400CA000} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- Capture and Compare Status
#define TPM_STATUS(group) (* ((volatile uint32_t *) (kBaseAddress_TPM [group] + 0x50)))
#define TPM1_STATUS (* ((volatile uint32_t *) (0x400C9000 + 0x50)))
#define TPM2_STATUS (* ((volatile uint32_t *) (0x400CA000 + 0x50)))

  // Boolean field: Timer Overflow Flag
    static const uint32_t TPM_STATUS_TOF = 1U << 8 ;

  // Boolean field: Channel 0 Flag
    static const uint32_t TPM_STATUS_CH0F = 1U << 0 ;

  // Boolean field: Channel 1 Flag
    static const uint32_t TPM_STATUS_CH1F = 1U << 1 ;

//-------------------- Counter
#define TPM_CNT(group) (* ((volatile uint32_t *) (kBaseAddress_TPM [group] + 0x4)))
#define TPM1_CNT (* ((volatile uint32_t *) (0x400C9000 + 0x4)))
#define TPM2_CNT (* ((volatile uint32_t *) (0x400CA000 + 0x4)))

  // Field (width: 16 bits): Counter value
    inline uint32_t TPM_CNT_COUNT (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Channel (n) Status and Control (idx = 0 ... 7)
#define TPM_CSC(group,idx) (* ((volatile uint32_t *) (kBaseAddress_TPM [group] + 0xC + 0x8 * (idx))))
#define TPM1_CSC(idx) (* ((volatile uint32_t *) (0x400C9000 + 0xC + 0x8 * (idx))))
#define TPM2_CSC(idx) (* ((volatile uint32_t *) (0x400CA000 + 0xC + 0x8 * (idx))))

  // Boolean field: DMA Enable
    static const uint32_t TPM_CSC_DMA = 1U << 0 ;

  // Boolean field: Channel Flag
    static const uint32_t TPM_CSC_CHF = 1U << 7 ;

  // Boolean field: Edge or Level Select
    static const uint32_t TPM_CSC_ELSB = 1U << 3 ;

  // Boolean field: Edge or Level Select
    static const uint32_t TPM_CSC_ELSA = 1U << 2 ;

  // Boolean field: Channel Mode Select
    static const uint32_t TPM_CSC_MSB = 1U << 5 ;

  // Boolean field: Channel Mode Select
    static const uint32_t TPM_CSC_MSA = 1U << 4 ;

  // Boolean field: Channel Interrupt Enable
    static const uint32_t TPM_CSC_CHIE = 1U << 6 ;

//-------------------- Quadrature Decoder Control and Status
#define TPM_QDCTRL(group) (* ((volatile uint32_t *) (kBaseAddress_TPM [group] + 0x80)))
#define TPM1_QDCTRL (* ((volatile uint32_t *) (0x400C9000 + 0x80)))
#define TPM2_QDCTRL (* ((volatile uint32_t *) (0x400CA000 + 0x80)))

  // Boolean field: Quadrature Decoder Mode
    static const uint32_t TPM_QDCTRL_QUADMODE = 1U << 3 ;

  // Boolean field: Indicates if the TOF bit was set on the top or the bottom of counting.
    static const uint32_t TPM_QDCTRL_TOFDIR = 1U << 1 ;

  // Boolean field: Counter Direction in Quadrature Decode Mode
    static const uint32_t TPM_QDCTRL_QUADIR = 1U << 2 ;

  // Boolean field: Enables the quadrature decoder mode
    static const uint32_t TPM_QDCTRL_QUADEN = 1U << 0 ;

//-------------------- Filter Control
#define TPM_FILTER(group) (* ((volatile uint32_t *) (kBaseAddress_TPM [group] + 0x78)))
#define TPM1_FILTER (* ((volatile uint32_t *) (0x400C9000 + 0x78)))
#define TPM2_FILTER (* ((volatile uint32_t *) (0x400CA000 + 0x78)))

  // Field (width: 4 bits): Channel 1 Filter Value
    inline uint32_t TPM_FILTER_CH1FVAL (const uint32_t inValue) { return (inValue & 15U) << 4 ; }

  // Field (width: 4 bits): Channel 0 Filter Value
    inline uint32_t TPM_FILTER_CH0FVAL (const uint32_t inValue) { return (inValue & 15U) << 0 ; }

//-------------------- Channel Polarity
#define TPM_POL(group) (* ((volatile uint32_t *) (kBaseAddress_TPM [group] + 0x70)))
#define TPM1_POL (* ((volatile uint32_t *) (0x400C9000 + 0x70)))
#define TPM2_POL (* ((volatile uint32_t *) (0x400CA000 + 0x70)))

  // Boolean field: Channel 1 Polarity
    static const uint32_t TPM_POL_POL1 = 1U << 1 ;

  // Boolean field: Channel 0 Polarity
    static const uint32_t TPM_POL_POL0 = 1U << 0 ;

//-------------------- Combine Channel Register
#define TPM_COMBINE(group) (* ((volatile uint32_t *) (kBaseAddress_TPM [group] + 0x64)))
#define TPM1_COMBINE (* ((volatile uint32_t *) (0x400C9000 + 0x64)))
#define TPM2_COMBINE (* ((volatile uint32_t *) (0x400CA000 + 0x64)))

  // Boolean field: Combine Channels 0 and 1
    static const uint32_t TPM_COMBINE_COMBINE0 = 1U << 0 ;

  // Boolean field: Combine Channel 0 and 1 Swap
    static const uint32_t TPM_COMBINE_COMSWAP0 = 1U << 1 ;

//-------------------- Configuration
#define TPM_CONF(group) (* ((volatile uint32_t *) (kBaseAddress_TPM [group] + 0x84)))
#define TPM1_CONF (* ((volatile uint32_t *) (0x400C9000 + 0x84)))
#define TPM2_CONF (* ((volatile uint32_t *) (0x400CA000 + 0x84)))

  // Field (width: 4 bits): Trigger Select
    inline uint32_t TPM_CONF_TRGSEL (const uint32_t inValue) { return (inValue & 15U) << 24 ; }

  // Boolean field: Global Time Base Synchronization
    static const uint32_t TPM_CONF_GTBSYNC = 1U << 8 ;

  // Field (width: 2 bits): Debug Mode
    inline uint32_t TPM_CONF_DBGMODE (const uint32_t inValue) { return (inValue & 3U) << 6 ; }

  // Boolean field: Counter Stop On Overflow
    static const uint32_t TPM_CONF_CSOO = 1U << 17 ;

  // Boolean field: Counter Reload On Trigger
    static const uint32_t TPM_CONF_CROT = 1U << 18 ;

  // Boolean field: Global time base enable
    static const uint32_t TPM_CONF_GTBEEN = 1U << 9 ;

  // Boolean field: Trigger Source
    static const uint32_t TPM_CONF_TRGSRC = 1U << 23 ;

  // Boolean field: Counter Start on Trigger
    static const uint32_t TPM_CONF_CSOT = 1U << 16 ;

  // Boolean field: Trigger Polarity
    static const uint32_t TPM_CONF_TRGPOL = 1U << 22 ;

  // Boolean field: Doze Enable
    static const uint32_t TPM_CONF_DOZEEN = 1U << 5 ;

  // Boolean field: Counter Pause On Trigger
    static const uint32_t TPM_CONF_CPOT = 1U << 19 ;

//-------------------- Channel (n) Value (idx = 0 ... 1)
#define TPM_CV(group,idx) (* ((volatile uint32_t *) (kBaseAddress_TPM [group] + 0x10 + 0x8 * (idx))))
#define TPM1_CV(idx) (* ((volatile uint32_t *) (0x400C9000 + 0x10 + 0x8 * (idx))))
#define TPM2_CV(idx) (* ((volatile uint32_t *) (0x400CA000 + 0x10 + 0x8 * (idx))))

  // Field (width: 16 bits): Channel Value
    inline uint32_t TPM_CV_VAL (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//-------------------- Status and Control
#define TPM_SC(group) (* ((volatile uint32_t *) (kBaseAddress_TPM [group] + 0)))
#define TPM1_SC (* ((volatile uint32_t *) (0x400C9000 + 0)))
#define TPM2_SC (* ((volatile uint32_t *) (0x400CA000 + 0)))

  // Boolean field: DMA Enable
    static const uint32_t TPM_SC_DMA = 1U << 8 ;

  // Field (width: 3 bits): Prescale Factor Selection
    inline uint32_t TPM_SC_PS (const uint32_t inValue) { return (inValue & 7U) << 0 ; }

  // Field (width: 2 bits): Clock Mode Selection
    inline uint32_t TPM_SC_CMOD (const uint32_t inValue) { return (inValue & 3U) << 3 ; }

  // Boolean field: Timer Overflow Interrupt Enable
    static const uint32_t TPM_SC_TOIE = 1U << 6 ;

  // Boolean field: Timer Overflow Flag
    static const uint32_t TPM_SC_TOF = 1U << 7 ;

  // Boolean field: Center-Aligned PWM Select
    static const uint32_t TPM_SC_CPWMS = 1U << 5 ;

//-------------------- Modulo
#define TPM_MOD(group) (* ((volatile uint32_t *) (kBaseAddress_TPM [group] + 0x8)))
#define TPM1_MOD (* ((volatile uint32_t *) (0x400C9000 + 0x8)))
#define TPM2_MOD (* ((volatile uint32_t *) (0x400CA000 + 0x8)))

  // Field (width: 16 bits): Modulo value
    inline uint32_t TPM_MOD_MOD (const uint32_t inValue) { return (inValue & 65535U) << 0 ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Peripheral group UART
//                UART0 at 0x4006A000
//                UART1 at 0x4006B000
//                UART2 at 0x4006C000
//                UART3 at 0x4006D000
//                UART4 at 0x400EA000
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint32_t kBaseAddress_UART [5] = {0x4006A000, 0x4006B000, 0x4006C000, 0x4006D000, 0x400EA000} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//-------------------- UART Match Address Registers 1
#define UART_MA1(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x8)))
#define UART0_MA1 (* ((volatile uint8_t *) (0x4006A000 + 0x8)))
#define UART1_MA1 (* ((volatile uint8_t *) (0x4006B000 + 0x8)))
#define UART2_MA1 (* ((volatile uint8_t *) (0x4006C000 + 0x8)))
#define UART3_MA1 (* ((volatile uint8_t *) (0x4006D000 + 0x8)))
#define UART4_MA1 (* ((volatile uint8_t *) (0x400EA000 + 0x8)))

//-------------------- UART Match Address Registers 2
#define UART_MA2(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x9)))
#define UART0_MA2 (* ((volatile uint8_t *) (0x4006A000 + 0x9)))
#define UART1_MA2 (* ((volatile uint8_t *) (0x4006B000 + 0x9)))
#define UART2_MA2 (* ((volatile uint8_t *) (0x4006C000 + 0x9)))
#define UART3_MA2 (* ((volatile uint8_t *) (0x4006D000 + 0x9)))
#define UART4_MA2 (* ((volatile uint8_t *) (0x400EA000 + 0x9)))

//-------------------- UART FIFO Status Register
#define UART_SFIFO(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x12)))
#define UART0_SFIFO (* ((volatile uint8_t *) (0x4006A000 + 0x12)))
#define UART1_SFIFO (* ((volatile uint8_t *) (0x4006B000 + 0x12)))
#define UART2_SFIFO (* ((volatile uint8_t *) (0x4006C000 + 0x12)))
#define UART3_SFIFO (* ((volatile uint8_t *) (0x4006D000 + 0x12)))
#define UART4_SFIFO (* ((volatile uint8_t *) (0x400EA000 + 0x12)))

  // Boolean field: Receive Buffer/FIFO Empty
    static const uint8_t UART_SFIFO_RXEMPT = 1U << 6 ;

  // Boolean field: Transmitter Buffer Overflow Flag
    static const uint8_t UART_SFIFO_TXOF = 1U << 1 ;

  // Boolean field: Transmit Buffer/FIFO Empty
    static const uint8_t UART_SFIFO_TXEMPT = 1U << 7 ;

  // Boolean field: Receiver Buffer Overflow Flag
    static const uint8_t UART_SFIFO_RXOF = 1U << 2 ;

  // Boolean field: Receiver Buffer Underflow Flag
    static const uint8_t UART_SFIFO_RXUF = 1U << 0 ;

//-------------------- UART Status Register 2
#define UART_S2(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x5)))
#define UART0_S2 (* ((volatile uint8_t *) (0x4006A000 + 0x5)))
#define UART1_S2 (* ((volatile uint8_t *) (0x4006B000 + 0x5)))
#define UART2_S2 (* ((volatile uint8_t *) (0x4006C000 + 0x5)))
#define UART3_S2 (* ((volatile uint8_t *) (0x4006D000 + 0x5)))
#define UART4_S2 (* ((volatile uint8_t *) (0x400EA000 + 0x5)))

  // Boolean field: Receiver Active Flag
    static const uint8_t UART_S2_RAF = 1U << 0 ;

  // Boolean field: Receive Wakeup Idle Detect
    static const uint8_t UART_S2_RWUID = 1U << 3 ;

  // Boolean field: Receive Data Inversion
    static const uint8_t UART_S2_RXINV = 1U << 4 ;

  // Boolean field: Break Transmit Character Length
    static const uint8_t UART_S2_BRK13 = 1U << 2 ;

  // Boolean field: LIN Break Detect Interrupt Flag
    static const uint8_t UART_S2_LBKDIF = 1U << 7 ;

  // Boolean field: LIN Break Detection Enable
    static const uint8_t UART_S2_LBKDE = 1U << 1 ;

  // Boolean field: RxD Pin Active Edge Interrupt Flag
    static const uint8_t UART_S2_RXEDGIF = 1U << 6 ;

  // Boolean field: Most Significant Bit First
    static const uint8_t UART_S2_MSBF = 1U << 5 ;

//-------------------- UART Status Register 1
#define UART_S1(group) (* ((const volatile uint8_t *) (kBaseAddress_UART [group] + 0x4)))
#define UART0_S1 (* ((const volatile uint8_t *) (0x4006A000 + 0x4)))
#define UART1_S1 (* ((const volatile uint8_t *) (0x4006B000 + 0x4)))
#define UART2_S1 (* ((const volatile uint8_t *) (0x4006C000 + 0x4)))
#define UART3_S1 (* ((const volatile uint8_t *) (0x4006D000 + 0x4)))
#define UART4_S1 (* ((const volatile uint8_t *) (0x400EA000 + 0x4)))

  // Boolean field: Noise Flag
    static const uint8_t UART_S1_NF = 1U << 2 ;

  // Boolean field: Receive Data Register Full Flag
    static const uint8_t UART_S1_RDRF = 1U << 5 ;

  // Boolean field: Transmit Complete Flag
    static const uint8_t UART_S1_TC = 1U << 6 ;

  // Boolean field: Idle Line Flag
    static const uint8_t UART_S1_IDLE = 1U << 4 ;

  // Boolean field: Parity Error Flag
    static const uint8_t UART_S1_PF = 1U << 0 ;

  // Boolean field: Framing Error Flag
    static const uint8_t UART_S1_FE = 1U << 1 ;

  // Boolean field: Transmit Data Register Empty Flag
    static const uint8_t UART_S1_TDRE = 1U << 7 ;

  // Boolean field: Receiver Overrun Flag
    static const uint8_t UART_S1_OR = 1U << 3 ;

//-------------------- UART 7816 Wait Parameter Register B
#define UART_WP7816B_T0(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x3D)))
#define UART0_WP7816B_T0 (* ((volatile uint8_t *) (0x4006A000 + 0x3D)))
#define UART1_WP7816B_T0 (* ((volatile uint8_t *) (0x4006B000 + 0x3D)))
#define UART2_WP7816B_T0 (* ((volatile uint8_t *) (0x4006C000 + 0x3D)))
#define UART3_WP7816B_T0 (* ((volatile uint8_t *) (0x4006D000 + 0x3D)))
#define UART4_WP7816B_T0 (* ((volatile uint8_t *) (0x400EA000 + 0x3D)))

//-------------------- UART 7816 Wait Parameter Register B
#define UART_WP7816B_T1(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x3D)))
#define UART0_WP7816B_T1 (* ((volatile uint8_t *) (0x4006A000 + 0x3D)))
#define UART1_WP7816B_T1 (* ((volatile uint8_t *) (0x4006B000 + 0x3D)))
#define UART2_WP7816B_T1 (* ((volatile uint8_t *) (0x4006C000 + 0x3D)))
#define UART3_WP7816B_T1 (* ((volatile uint8_t *) (0x4006D000 + 0x3D)))
#define UART4_WP7816B_T1 (* ((volatile uint8_t *) (0x400EA000 + 0x3D)))

//-------------------- UART 7816 ATR Duration Timer Register B
#define UART_AP7816B_T0(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x3B)))
#define UART0_AP7816B_T0 (* ((volatile uint8_t *) (0x4006A000 + 0x3B)))
#define UART1_AP7816B_T0 (* ((volatile uint8_t *) (0x4006B000 + 0x3B)))
#define UART2_AP7816B_T0 (* ((volatile uint8_t *) (0x4006C000 + 0x3B)))
#define UART3_AP7816B_T0 (* ((volatile uint8_t *) (0x4006D000 + 0x3B)))
#define UART4_AP7816B_T0 (* ((volatile uint8_t *) (0x400EA000 + 0x3B)))

//-------------------- UART FIFO Transmit Count
#define UART_TCFIFO(group) (* ((const volatile uint8_t *) (kBaseAddress_UART [group] + 0x14)))
#define UART0_TCFIFO (* ((const volatile uint8_t *) (0x4006A000 + 0x14)))
#define UART1_TCFIFO (* ((const volatile uint8_t *) (0x4006B000 + 0x14)))
#define UART2_TCFIFO (* ((const volatile uint8_t *) (0x4006C000 + 0x14)))
#define UART3_TCFIFO (* ((const volatile uint8_t *) (0x4006D000 + 0x14)))
#define UART4_TCFIFO (* ((const volatile uint8_t *) (0x400EA000 + 0x14)))

//-------------------- UART 7816 Interrupt Enable Register
#define UART_IE7816(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x19)))
#define UART0_IE7816 (* ((volatile uint8_t *) (0x4006A000 + 0x19)))
#define UART1_IE7816 (* ((volatile uint8_t *) (0x4006B000 + 0x19)))
#define UART2_IE7816 (* ((volatile uint8_t *) (0x4006C000 + 0x19)))
#define UART3_IE7816 (* ((volatile uint8_t *) (0x4006D000 + 0x19)))
#define UART4_IE7816 (* ((volatile uint8_t *) (0x400EA000 + 0x19)))

  // Boolean field: ATR Duration Timer Interrupt Enable
    static const uint8_t UART_IE7816_ADTE = 1U << 3 ;

  // Boolean field: Transmit Threshold Exceeded Interrupt Enable
    static const uint8_t UART_IE7816_TXTE = 1U << 1 ;

  // Boolean field: Character Wait Timer Interrupt Enable
    static const uint8_t UART_IE7816_CWTE = 1U << 6 ;

  // Boolean field: Initial Character Detected Interrupt Enable
    static const uint8_t UART_IE7816_INITDE = 1U << 4 ;

  // Boolean field: Block Wait Timer Interrupt Enable
    static const uint8_t UART_IE7816_BWTE = 1U << 5 ;

  // Boolean field: Wait Timer Interrupt Enable
    static const uint8_t UART_IE7816_WTE = 1U << 7 ;

  // Boolean field: Receive Threshold Exceeded Interrupt Enable
    static const uint8_t UART_IE7816_RXTE = 1U << 0 ;

  // Boolean field: Guard Timer Violated Interrupt Enable
    static const uint8_t UART_IE7816_GTVE = 1U << 2 ;

//-------------------- UART 7816 Wait FD Register
#define UART_WF7816(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x1D)))
#define UART0_WF7816 (* ((volatile uint8_t *) (0x4006A000 + 0x1D)))
#define UART1_WF7816 (* ((volatile uint8_t *) (0x4006B000 + 0x1D)))
#define UART2_WF7816 (* ((volatile uint8_t *) (0x4006C000 + 0x1D)))
#define UART3_WF7816 (* ((volatile uint8_t *) (0x4006D000 + 0x1D)))
#define UART4_WF7816 (* ((volatile uint8_t *) (0x400EA000 + 0x1D)))

//-------------------- UART FIFO Receive Count
#define UART_RCFIFO(group) (* ((const volatile uint8_t *) (kBaseAddress_UART [group] + 0x16)))
#define UART0_RCFIFO (* ((const volatile uint8_t *) (0x4006A000 + 0x16)))
#define UART1_RCFIFO (* ((const volatile uint8_t *) (0x4006B000 + 0x16)))
#define UART2_RCFIFO (* ((const volatile uint8_t *) (0x4006C000 + 0x16)))
#define UART3_RCFIFO (* ((const volatile uint8_t *) (0x4006D000 + 0x16)))
#define UART4_RCFIFO (* ((const volatile uint8_t *) (0x400EA000 + 0x16)))

//-------------------- UART Modem Register
#define UART_MODEM(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0xD)))
#define UART0_MODEM (* ((volatile uint8_t *) (0x4006A000 + 0xD)))
#define UART1_MODEM (* ((volatile uint8_t *) (0x4006B000 + 0xD)))
#define UART2_MODEM (* ((volatile uint8_t *) (0x4006C000 + 0xD)))
#define UART3_MODEM (* ((volatile uint8_t *) (0x4006D000 + 0xD)))
#define UART4_MODEM (* ((volatile uint8_t *) (0x400EA000 + 0xD)))

  // Boolean field: Transmitter request-to-send enable
    static const uint8_t UART_MODEM_TXRTSE = 1U << 1 ;

  // Boolean field: Transmitter clear-to-send enable
    static const uint8_t UART_MODEM_TXCTSE = 1U << 0 ;

  // Boolean field: Receiver request-to-send enable
    static const uint8_t UART_MODEM_RXRTSE = 1U << 3 ;

  // Boolean field: Transmitter request-to-send polarity
    static const uint8_t UART_MODEM_TXRTSPOL = 1U << 2 ;

//-------------------- UART 7816 Wait N Register
#define UART_WN7816(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x1C)))
#define UART0_WN7816 (* ((volatile uint8_t *) (0x4006A000 + 0x1C)))
#define UART1_WN7816 (* ((volatile uint8_t *) (0x4006B000 + 0x1C)))
#define UART2_WN7816 (* ((volatile uint8_t *) (0x4006C000 + 0x1C)))
#define UART3_WN7816 (* ((volatile uint8_t *) (0x4006D000 + 0x1C)))
#define UART4_WN7816 (* ((volatile uint8_t *) (0x400EA000 + 0x1C)))

//-------------------- UART 7816 Transmit Length Register
#define UART_TL7816(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x1F)))
#define UART0_TL7816 (* ((volatile uint8_t *) (0x4006A000 + 0x1F)))
#define UART1_TL7816 (* ((volatile uint8_t *) (0x4006B000 + 0x1F)))
#define UART2_TL7816 (* ((volatile uint8_t *) (0x4006C000 + 0x1F)))
#define UART3_TL7816 (* ((volatile uint8_t *) (0x4006D000 + 0x1F)))
#define UART4_TL7816 (* ((volatile uint8_t *) (0x400EA000 + 0x1F)))

//-------------------- UART Baud Rate Registers: Low
#define UART_BDL(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x1)))
#define UART0_BDL (* ((volatile uint8_t *) (0x4006A000 + 0x1)))
#define UART1_BDL (* ((volatile uint8_t *) (0x4006B000 + 0x1)))
#define UART2_BDL (* ((volatile uint8_t *) (0x4006C000 + 0x1)))
#define UART3_BDL (* ((volatile uint8_t *) (0x4006D000 + 0x1)))
#define UART4_BDL (* ((volatile uint8_t *) (0x400EA000 + 0x1)))

//-------------------- UART Control Register 3
#define UART_C3(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x6)))
#define UART0_C3 (* ((volatile uint8_t *) (0x4006A000 + 0x6)))
#define UART1_C3 (* ((volatile uint8_t *) (0x4006B000 + 0x6)))
#define UART2_C3 (* ((volatile uint8_t *) (0x4006C000 + 0x6)))
#define UART3_C3 (* ((volatile uint8_t *) (0x4006D000 + 0x6)))
#define UART4_C3 (* ((volatile uint8_t *) (0x400EA000 + 0x6)))

  // Boolean field: Parity Error Interrupt Enable
    static const uint8_t UART_C3_PEIE = 1U << 0 ;

  // Boolean field: Transmitter Pin Data Direction in Single-Wire mode
    static const uint8_t UART_C3_TXDIR = 1U << 5 ;

  // Boolean field: Framing Error Interrupt Enable
    static const uint8_t UART_C3_FEIE = 1U << 1 ;

  // Boolean field: Transmit Bit 8
    static const uint8_t UART_C3_T8 = 1U << 6 ;

  // Boolean field: Received Bit 8
    static const uint8_t UART_C3_R8 = 1U << 7 ;

  // Boolean field: Noise Error Interrupt Enable
    static const uint8_t UART_C3_NEIE = 1U << 2 ;

  // Boolean field: Transmit Data Inversion.
    static const uint8_t UART_C3_TXINV = 1U << 4 ;

  // Boolean field: Overrun Error Interrupt Enable
    static const uint8_t UART_C3_ORIE = 1U << 3 ;

//-------------------- UART Control Register 2
#define UART_C2(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x3)))
#define UART0_C2 (* ((volatile uint8_t *) (0x4006A000 + 0x3)))
#define UART1_C2 (* ((volatile uint8_t *) (0x4006B000 + 0x3)))
#define UART2_C2 (* ((volatile uint8_t *) (0x4006C000 + 0x3)))
#define UART3_C2 (* ((volatile uint8_t *) (0x4006D000 + 0x3)))
#define UART4_C2 (* ((volatile uint8_t *) (0x400EA000 + 0x3)))

  // Boolean field: Transmitter Enable
    static const uint8_t UART_C2_TE = 1U << 3 ;

  // Boolean field: Idle Line Interrupt Enable
    static const uint8_t UART_C2_ILIE = 1U << 4 ;

  // Boolean field: Receiver Enable
    static const uint8_t UART_C2_RE = 1U << 2 ;

  // Boolean field: Receiver Wakeup Control
    static const uint8_t UART_C2_RWU = 1U << 1 ;

  // Boolean field: Transmitter Interrupt or DMA Transfer Enable.
    static const uint8_t UART_C2_TIE = 1U << 7 ;

  // Boolean field: Send Break
    static const uint8_t UART_C2_SBK = 1U << 0 ;

  // Boolean field: Receiver Full Interrupt or DMA Transfer Enable
    static const uint8_t UART_C2_RIE = 1U << 5 ;

  // Boolean field: Transmission Complete Interrupt Enable
    static const uint8_t UART_C2_TCIE = 1U << 6 ;

//-------------------- UART Control Register 1
#define UART_C1(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x2)))
#define UART0_C1 (* ((volatile uint8_t *) (0x4006A000 + 0x2)))
#define UART1_C1 (* ((volatile uint8_t *) (0x4006B000 + 0x2)))
#define UART2_C1 (* ((volatile uint8_t *) (0x4006C000 + 0x2)))
#define UART3_C1 (* ((volatile uint8_t *) (0x4006D000 + 0x2)))
#define UART4_C1 (* ((volatile uint8_t *) (0x400EA000 + 0x2)))

  // Boolean field: UART Stops in Wait Mode
    static const uint8_t UART_C1_UARTSWAI = 1U << 6 ;

  // Boolean field: Parity Type
    static const uint8_t UART_C1_PT = 1U << 0 ;

  // Boolean field: 9-bit or 8-bit Mode Select
    static const uint8_t UART_C1_M = 1U << 4 ;

  // Boolean field: Receiver Source Select
    static const uint8_t UART_C1_RSRC = 1U << 5 ;

  // Boolean field: Idle Line Type Select
    static const uint8_t UART_C1_ILT = 1U << 2 ;

  // Boolean field: Receiver Wakeup Method Select
    static const uint8_t UART_C1_WAKE = 1U << 3 ;

  // Boolean field: Parity Enable
    static const uint8_t UART_C1_PE = 1U << 1 ;

  // Boolean field: Loop Mode Select
    static const uint8_t UART_C1_LOOPS = 1U << 7 ;

//-------------------- UART Control Register 5
#define UART_C5(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0xB)))
#define UART0_C5 (* ((volatile uint8_t *) (0x4006A000 + 0xB)))
#define UART1_C5 (* ((volatile uint8_t *) (0x4006B000 + 0xB)))
#define UART2_C5 (* ((volatile uint8_t *) (0x4006C000 + 0xB)))
#define UART3_C5 (* ((volatile uint8_t *) (0x4006D000 + 0xB)))
#define UART4_C5 (* ((volatile uint8_t *) (0x400EA000 + 0xB)))

  // Boolean field: Transmitter DMA Select
    static const uint8_t UART_C5_TDMAS = 1U << 7 ;

  // Boolean field: Receiver Full DMA Select
    static const uint8_t UART_C5_RDMAS = 1U << 5 ;

//-------------------- UART Control Register 4
#define UART_C4(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0xA)))
#define UART0_C4 (* ((volatile uint8_t *) (0x4006A000 + 0xA)))
#define UART1_C4 (* ((volatile uint8_t *) (0x4006B000 + 0xA)))
#define UART2_C4 (* ((volatile uint8_t *) (0x4006C000 + 0xA)))
#define UART3_C4 (* ((volatile uint8_t *) (0x4006D000 + 0xA)))
#define UART4_C4 (* ((volatile uint8_t *) (0x400EA000 + 0xA)))

  // Boolean field: 10-bit Mode select
    static const uint8_t UART_C4_M10 = 1U << 5 ;

  // Field (width: 5 bits): Baud Rate Fine Adjust
    inline uint8_t UART_C4_BRFA (const uint8_t inValue) { return (inValue & 31U) << 0 ; }

  // Boolean field: Match Address Mode Enable 1
    static const uint8_t UART_C4_MAEN1 = 1U << 7 ;

  // Boolean field: Match Address Mode Enable 2
    static const uint8_t UART_C4_MAEN2 = 1U << 6 ;

//-------------------- UART 7816 Wait Parameter Register
#define UART_WP7816(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x1B)))
#define UART0_WP7816 (* ((volatile uint8_t *) (0x4006A000 + 0x1B)))
#define UART1_WP7816 (* ((volatile uint8_t *) (0x4006B000 + 0x1B)))
#define UART2_WP7816 (* ((volatile uint8_t *) (0x4006C000 + 0x1B)))
#define UART3_WP7816 (* ((volatile uint8_t *) (0x4006D000 + 0x1B)))
#define UART4_WP7816 (* ((volatile uint8_t *) (0x400EA000 + 0x1B)))

//-------------------- UART Data Register
#define UART_D(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x7)))
#define UART0_D (* ((volatile uint8_t *) (0x4006A000 + 0x7)))
#define UART1_D (* ((volatile uint8_t *) (0x4006B000 + 0x7)))
#define UART2_D (* ((volatile uint8_t *) (0x4006C000 + 0x7)))
#define UART3_D (* ((volatile uint8_t *) (0x4006D000 + 0x7)))
#define UART4_D (* ((volatile uint8_t *) (0x400EA000 + 0x7)))

//-------------------- UART Extended Data Register
#define UART_ED(group) (* ((const volatile uint8_t *) (kBaseAddress_UART [group] + 0xC)))
#define UART0_ED (* ((const volatile uint8_t *) (0x4006A000 + 0xC)))
#define UART1_ED (* ((const volatile uint8_t *) (0x4006B000 + 0xC)))
#define UART2_ED (* ((const volatile uint8_t *) (0x4006C000 + 0xC)))
#define UART3_ED (* ((const volatile uint8_t *) (0x4006D000 + 0xC)))
#define UART4_ED (* ((const volatile uint8_t *) (0x400EA000 + 0xC)))

  // Boolean field: The current received dataword contained in D and C3[R8] was received with noise.
    static const uint8_t UART_ED_NOISY = 1U << 7 ;

  // Boolean field: The current received dataword contained in D and C3[R8] was received with a parity error.
    static const uint8_t UART_ED_PARITYE = 1U << 6 ;

//-------------------- UART Infrared Register
#define UART_IR(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0xE)))
#define UART0_IR (* ((volatile uint8_t *) (0x4006A000 + 0xE)))
#define UART1_IR (* ((volatile uint8_t *) (0x4006B000 + 0xE)))
#define UART2_IR (* ((volatile uint8_t *) (0x4006C000 + 0xE)))
#define UART3_IR (* ((volatile uint8_t *) (0x4006D000 + 0xE)))
#define UART4_IR (* ((volatile uint8_t *) (0x400EA000 + 0xE)))

  // Boolean field: Infrared enable
    static const uint8_t UART_IR_IREN = 1U << 2 ;

  // Field (width: 2 bits): Transmitter narrow pulse
    inline uint8_t UART_IR_TNP (const uint8_t inValue) { return (inValue & 3U) << 0 ; }

//-------------------- UART Baud Rate Registers: High
#define UART_BDH(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0)))
#define UART0_BDH (* ((volatile uint8_t *) (0x4006A000 + 0)))
#define UART1_BDH (* ((volatile uint8_t *) (0x4006B000 + 0)))
#define UART2_BDH (* ((volatile uint8_t *) (0x4006C000 + 0)))
#define UART3_BDH (* ((volatile uint8_t *) (0x4006D000 + 0)))
#define UART4_BDH (* ((volatile uint8_t *) (0x400EA000 + 0)))

  // Field (width: 5 bits): UART Baud Rate Bits
    inline uint8_t UART_BDH_SBR (const uint8_t inValue) { return (inValue & 31U) << 0 ; }

  // Boolean field: Stop Bit Number Select
    static const uint8_t UART_BDH_SBNS = 1U << 5 ;

  // Boolean field: RxD Input Active Edge Interrupt Enable
    static const uint8_t UART_BDH_RXEDGIE = 1U << 6 ;

  // Boolean field: LIN Break Detect Interrupt Enable
    static const uint8_t UART_BDH_LBKDIE = 1U << 7 ;

//-------------------- UART FIFO Receive Watermark
#define UART_RWFIFO(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x15)))
#define UART0_RWFIFO (* ((volatile uint8_t *) (0x4006A000 + 0x15)))
#define UART1_RWFIFO (* ((volatile uint8_t *) (0x4006B000 + 0x15)))
#define UART2_RWFIFO (* ((volatile uint8_t *) (0x4006C000 + 0x15)))
#define UART3_RWFIFO (* ((volatile uint8_t *) (0x4006D000 + 0x15)))
#define UART4_RWFIFO (* ((volatile uint8_t *) (0x400EA000 + 0x15)))

//-------------------- UART 7816 Control Register
#define UART_C7816(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x18)))
#define UART0_C7816 (* ((volatile uint8_t *) (0x4006A000 + 0x18)))
#define UART1_C7816 (* ((volatile uint8_t *) (0x4006B000 + 0x18)))
#define UART2_C7816 (* ((volatile uint8_t *) (0x4006C000 + 0x18)))
#define UART3_C7816 (* ((volatile uint8_t *) (0x4006D000 + 0x18)))
#define UART4_C7816 (* ((volatile uint8_t *) (0x400EA000 + 0x18)))

  // Boolean field: Transfer Type
    static const uint8_t UART_C7816_TTYPE = 1U << 1 ;

  // Boolean field: Detect Initial Character
    static const uint8_t UART_C7816_INIT = 1U << 2 ;

  // Boolean field: Generate NACK on Error
    static const uint8_t UART_C7816_ANACK = 1U << 3 ;

  // Boolean field: ISO-7816 Functionality Enabled
    static const uint8_t UART_C7816_ISO_7816E = 1U << 0 ;

  // Boolean field: Generate NACK on Overflow
    static const uint8_t UART_C7816_ONACK = 1U << 4 ;

//-------------------- UART 7816 ATR Duration Timer Register A
#define UART_AP7816A_T0(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x3A)))
#define UART0_AP7816A_T0 (* ((volatile uint8_t *) (0x4006A000 + 0x3A)))
#define UART1_AP7816A_T0 (* ((volatile uint8_t *) (0x4006B000 + 0x3A)))
#define UART2_AP7816A_T0 (* ((volatile uint8_t *) (0x4006C000 + 0x3A)))
#define UART3_AP7816A_T0 (* ((volatile uint8_t *) (0x4006D000 + 0x3A)))
#define UART4_AP7816A_T0 (* ((volatile uint8_t *) (0x400EA000 + 0x3A)))

//-------------------- UART 7816 Wait Parameter Register A
#define UART_WP7816A_T1(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x3C)))
#define UART0_WP7816A_T1 (* ((volatile uint8_t *) (0x4006A000 + 0x3C)))
#define UART1_WP7816A_T1 (* ((volatile uint8_t *) (0x4006B000 + 0x3C)))
#define UART2_WP7816A_T1 (* ((volatile uint8_t *) (0x4006C000 + 0x3C)))
#define UART3_WP7816A_T1 (* ((volatile uint8_t *) (0x4006D000 + 0x3C)))
#define UART4_WP7816A_T1 (* ((volatile uint8_t *) (0x400EA000 + 0x3C)))

//-------------------- UART 7816 Wait Parameter Register A
#define UART_WP7816A_T0(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x3C)))
#define UART0_WP7816A_T0 (* ((volatile uint8_t *) (0x4006A000 + 0x3C)))
#define UART1_WP7816A_T0 (* ((volatile uint8_t *) (0x4006B000 + 0x3C)))
#define UART2_WP7816A_T0 (* ((volatile uint8_t *) (0x4006C000 + 0x3C)))
#define UART3_WP7816A_T0 (* ((volatile uint8_t *) (0x4006D000 + 0x3C)))
#define UART4_WP7816A_T0 (* ((volatile uint8_t *) (0x400EA000 + 0x3C)))

//-------------------- UART FIFO Parameters
#define UART_PFIFO(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x10)))
#define UART0_PFIFO (* ((volatile uint8_t *) (0x4006A000 + 0x10)))
#define UART1_PFIFO (* ((volatile uint8_t *) (0x4006B000 + 0x10)))
#define UART2_PFIFO (* ((volatile uint8_t *) (0x4006C000 + 0x10)))
#define UART3_PFIFO (* ((volatile uint8_t *) (0x4006D000 + 0x10)))
#define UART4_PFIFO (* ((volatile uint8_t *) (0x400EA000 + 0x10)))

  // Boolean field: Transmit FIFO Enable
    static const uint8_t UART_PFIFO_TXFE = 1U << 7 ;

  // Field (width: 3 bits): Transmit FIFO. Buffer Depth
    inline uint8_t UART_PFIFO_TXFIFOSIZE (const uint8_t inValue) { return (inValue & 7U) << 4 ; }

  // Field (width: 3 bits): Receive FIFO. Buffer Depth
    inline uint8_t UART_PFIFO_RXFIFOSIZE (const uint8_t inValue) { return (inValue & 7U) << 0 ; }

  // Boolean field: Receive FIFO Enable
    static const uint8_t UART_PFIFO_RXFE = 1U << 3 ;

//-------------------- UART 7816 Wait and Guard Parameter Register
#define UART_WGP7816_T1(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x3E)))
#define UART0_WGP7816_T1 (* ((volatile uint8_t *) (0x4006A000 + 0x3E)))
#define UART1_WGP7816_T1 (* ((volatile uint8_t *) (0x4006B000 + 0x3E)))
#define UART2_WGP7816_T1 (* ((volatile uint8_t *) (0x4006C000 + 0x3E)))
#define UART3_WGP7816_T1 (* ((volatile uint8_t *) (0x4006D000 + 0x3E)))
#define UART4_WGP7816_T1 (* ((volatile uint8_t *) (0x400EA000 + 0x3E)))

  // Field (width: 4 bits): Block Guard Time Integer (C7816[TTYPE] = 1)
    inline uint8_t UART_WGP7816_T1_BGI (const uint8_t inValue) { return (inValue & 15U) << 0 ; }

  // Field (width: 4 bits): Character Wait Time Integer 1 (C7816[TTYPE] = 1)
    inline uint8_t UART_WGP7816_T1_CWI1 (const uint8_t inValue) { return (inValue & 15U) << 4 ; }

//-------------------- UART FIFO Control Register
#define UART_CFIFO(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x11)))
#define UART0_CFIFO (* ((volatile uint8_t *) (0x4006A000 + 0x11)))
#define UART1_CFIFO (* ((volatile uint8_t *) (0x4006B000 + 0x11)))
#define UART2_CFIFO (* ((volatile uint8_t *) (0x4006C000 + 0x11)))
#define UART3_CFIFO (* ((volatile uint8_t *) (0x4006D000 + 0x11)))
#define UART4_CFIFO (* ((volatile uint8_t *) (0x400EA000 + 0x11)))

  // Boolean field: Receive FIFO Underflow Interrupt Enable
    static const uint8_t UART_CFIFO_RXUFE = 1U << 0 ;

  // Boolean field: Receive FIFO Overflow Interrupt Enable
    static const uint8_t UART_CFIFO_RXOFE = 1U << 2 ;

  // Boolean field: Transmit FIFO Overflow Interrupt Enable
    static const uint8_t UART_CFIFO_TXOFE = 1U << 1 ;

  // Boolean field: Receive FIFO/Buffer Flush
    static const uint8_t UART_CFIFO_RXFLUSH = 1U << 6 ;

  // Boolean field: Transmit FIFO/Buffer Flush
    static const uint8_t UART_CFIFO_TXFLUSH = 1U << 7 ;

//-------------------- UART 7816 Wait Parameter Register C
#define UART_WP7816C_T1(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x3F)))
#define UART0_WP7816C_T1 (* ((volatile uint8_t *) (0x4006A000 + 0x3F)))
#define UART1_WP7816C_T1 (* ((volatile uint8_t *) (0x4006B000 + 0x3F)))
#define UART2_WP7816C_T1 (* ((volatile uint8_t *) (0x4006C000 + 0x3F)))
#define UART3_WP7816C_T1 (* ((volatile uint8_t *) (0x4006D000 + 0x3F)))
#define UART4_WP7816C_T1 (* ((volatile uint8_t *) (0x400EA000 + 0x3F)))

  // Field (width: 5 bits): Character Wait Time Integer 2 (C7816[TTYPE] = 1)
    inline uint8_t UART_WP7816C_T1_CWI2 (const uint8_t inValue) { return (inValue & 31U) << 0 ; }

//-------------------- UART 7816 Interrupt Status Register
#define UART_IS7816(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x1A)))
#define UART0_IS7816 (* ((volatile uint8_t *) (0x4006A000 + 0x1A)))
#define UART1_IS7816 (* ((volatile uint8_t *) (0x4006B000 + 0x1A)))
#define UART2_IS7816 (* ((volatile uint8_t *) (0x4006C000 + 0x1A)))
#define UART3_IS7816 (* ((volatile uint8_t *) (0x4006D000 + 0x1A)))
#define UART4_IS7816 (* ((volatile uint8_t *) (0x400EA000 + 0x1A)))

  // Boolean field: ATR Duration Time Interrupt
    static const uint8_t UART_IS7816_ADT = 1U << 3 ;

  // Boolean field: Initial Character Detected Interrupt
    static const uint8_t UART_IS7816_INITD = 1U << 4 ;

  // Boolean field: Block Wait Timer Interrupt
    static const uint8_t UART_IS7816_BWT = 1U << 5 ;

  // Boolean field: Character Wait Timer Interrupt
    static const uint8_t UART_IS7816_CWT = 1U << 6 ;

  // Boolean field: Wait Timer Interrupt
    static const uint8_t UART_IS7816_WT = 1U << 7 ;

  // Boolean field: Guard Timer Violated Interrupt
    static const uint8_t UART_IS7816_GTV = 1U << 2 ;

  // Boolean field: Transmit Threshold Exceeded Interrupt
    static const uint8_t UART_IS7816_TXT = 1U << 1 ;

  // Boolean field: Receive Threshold Exceeded Interrupt
    static const uint8_t UART_IS7816_RXT = 1U << 0 ;

//-------------------- UART 7816 Error Threshold Register
#define UART_ET7816(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x1E)))
#define UART0_ET7816 (* ((volatile uint8_t *) (0x4006A000 + 0x1E)))
#define UART1_ET7816 (* ((volatile uint8_t *) (0x4006B000 + 0x1E)))
#define UART2_ET7816 (* ((volatile uint8_t *) (0x4006C000 + 0x1E)))
#define UART3_ET7816 (* ((volatile uint8_t *) (0x4006D000 + 0x1E)))
#define UART4_ET7816 (* ((volatile uint8_t *) (0x400EA000 + 0x1E)))

  // Field (width: 4 bits): Receive NACK Threshold
    inline uint8_t UART_ET7816_RXTHRESHOLD (const uint8_t inValue) { return (inValue & 15U) << 0 ; }

  // Field (width: 4 bits): Transmit NACK Threshold
    inline uint8_t UART_ET7816_TXTHRESHOLD (const uint8_t inValue) { return (inValue & 15U) << 4 ; }

//-------------------- UART FIFO Transmit Watermark
#define UART_TWFIFO(group) (* ((volatile uint8_t *) (kBaseAddress_UART [group] + 0x13)))
#define UART0_TWFIFO (* ((volatile uint8_t *) (0x4006A000 + 0x13)))
#define UART1_TWFIFO (* ((volatile uint8_t *) (0x4006B000 + 0x13)))
#define UART2_TWFIFO (* ((volatile uint8_t *) (0x4006C000 + 0x13)))
#define UART3_TWFIFO (* ((volatile uint8_t *) (0x4006D000 + 0x13)))
#define UART4_TWFIFO (* ((volatile uint8_t *) (0x400EA000 + 0x13)))

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INTERRUPTS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

enum class ISRSlot : uint8_t {
  ADC0 = 39,
  ADC1 = 73,
  CAN0_Bus_Off = 76,
  CAN0_Error = 77,
  CAN0_ORed_Message_buffer = 75,
  CAN0_Rx_Warning = 79,
  CAN0_Tx_Warning = 78,
  CAN0_Wake_Up = 80,
  CAN1_Bus_Off = 95,
  CAN1_Error = 96,
  CAN1_ORed_Message_buffer = 94,
  CAN1_Rx_Warning = 98,
  CAN1_Tx_Warning = 97,
  CAN1_Wake_Up = 99,
  CMP0 = 40,
  CMP1 = 41,
  CMP2 = 70,
  CMP3 = 92,
  CMT = 45,
  DAC0 = 56,
  DAC1 = 72,
  DMA0_DMA16 = 0,
  DMA10_DMA26 = 10,
  DMA11_DMA27 = 11,
  DMA12_DMA28 = 12,
  DMA13_DMA29 = 13,
  DMA14_DMA30 = 14,
  DMA15_DMA31 = 15,
  DMA1_DMA17 = 1,
  DMA2_DMA18 = 2,
  DMA3_DMA19 = 3,
  DMA4_DMA20 = 4,
  DMA5_DMA21 = 5,
  DMA6_DMA22 = 6,
  DMA7_DMA23 = 7,
  DMA8_DMA24 = 8,
  DMA9_DMA25 = 9,
  DMA_Error = 16,
  ENET_1588_Timer = 82,
  ENET_Error = 85,
  ENET_Receive = 84,
  ENET_Transmit = 83,
  FTFE = 18,
  FTM0 = 42,
  FTM1 = 43,
  FTM2 = 44,
  FTM3 = 71,
  I2C0 = 24,
  I2C1 = 25,
  I2C2 = 74,
  I2C3 = 91,
  I2S0_Rx = 29,
  I2S0_Tx = 28,
  LLWU = 21,
  LPTMR0 = 58,
  LPUART0 = 86,
  LVD_LVW = 20,
  MCG = 57,
  MCM = 17,
  PDB0 = 52,
  PIT0 = 48,
  PIT1 = 49,
  PIT2 = 50,
  PIT3 = 51,
  PORTA = 59,
  PORTB = 60,
  PORTC = 61,
  PORTD = 62,
  PORTE = 63,
  RNG = 23,
  RTC = 46,
  RTC_Seconds = 47,
  Read_Collision = 19,
  SDHC = 81,
  SPI0 = 26,
  SPI1 = 27,
  SPI2 = 65,
  TPM1 = 88,
  TPM2 = 89,
  TSI0 = 87,
  UART0_ERR = 32,
  UART0_RX_TX = 31,
  UART1_ERR = 34,
  UART1_RX_TX = 33,
  UART2_ERR = 36,
  UART2_RX_TX = 35,
  UART3_ERR = 38,
  UART3_RX_TX = 37,
  UART4_ERR = 67,
  UART4_RX_TX = 66,
  USB0 = 53,
  USBDCD = 54,
  USBHS = 93,
  USBHSDCD = 90,
  WDOG_EWM = 22,
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

inline void NVIC_ENABLE_IRQ (const ISRSlot inInterrupt) {
  const uint32_t it = static_cast <uint32_t> (inInterrupt) ;
  *((volatile uint32_t *) (0xE000E100 + 4 * (it >> 5))) = 1U << (it & 31) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

inline void NVIC_DISABLE_IRQ (const ISRSlot inInterrupt) {
  const uint32_t it = static_cast <uint32_t> (inInterrupt) ;
  *((volatile uint32_t *) (0xE000E180 + 4 * (it >> 5))) = 1U << (it & 31) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// BITBAND
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

inline void bitband32 (const volatile uint32_t & inRegister, const uint8_t inBit, const bool inValue) {
  const uint32_t address = ((uint32_t) &inRegister - 0x40000000) * 32 + ((uint32_t) inBit) * 4 + 0x42000000 ;
  volatile uint32_t * ptr = (volatile uint32_t *) address ;
  *ptr = (uint32_t) inValue ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
