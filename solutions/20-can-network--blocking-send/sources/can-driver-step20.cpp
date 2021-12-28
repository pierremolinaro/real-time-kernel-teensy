//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Teensy 3.6 (__MK66FX1M0__)
//   Two CAN modules (CAN0, CAN1)
//        CAN0: 3=PTA12=CAN0_TX,  4=PTA13=CAN0_RX (default)
//        CAN0: 29=PTB18=CAN0_TX, 30=PTB19=CAN0_RX (alternative)
//        CAN1: 33=PTE24=CAN1_TX, 34=PTE25=CAN1_RX (default)
//
//        CAN0: NOTE: Alternative CAN0 pins are always used by the driver
//        CAN1: NOTE: Alternative CAN1 pins are not broken out on Teensy 3.6
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "all-headers.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//    FlexCAN Register access
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint32_t FLEXCAN0_BASE = 0x40024000 ;
static const uint32_t FLEXCAN1_BASE = 0x400A4000 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

typedef volatile uint32_t vuint32_t ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#define FLEXCANb_MCR(b)                   (*((vuint32_t *) (b)))
#define FLEXCANb_CTRL1(b)                 (*((vuint32_t *) ((b)+0x04)))
#define FLEXCANb_ECR(b)                   (*((vuint32_t *) ((b)+0x1C)))
#define FLEXCANb_ESR1(b)                  (*((vuint32_t *) ((b)+0x20)))
#define FLEXCANb_IMASK1(b)                (*((vuint32_t *) ((b)+0x28)))
#define FLEXCANb_IFLAG1(b)                (*((vuint32_t *) ((b)+0x30)))
#define FLEXCANb_CTRL2(b)                 (*((vuint32_t *) ((b)+0x34)))
#define FLEXCANb_RXFGMASK(b)              (*((vuint32_t *) ((b)+0x48)))
#define FLEXCANb_RXFIR(b)                 (*((vuint32_t *) ((b)+0x4C)))
#define FLEXCANb_MBn_CS(b, n)             (*((vuint32_t *) ((b)+0x80+(n)*16)))
#define FLEXCANb_MBn_ID(b, n)             (*((vuint32_t *) ((b)+0x84+(n)*16)))
#define FLEXCANb_MBn_WORD0(b, n)          (*((vuint32_t *) ((b)+0x88+(n)*16)))
#define FLEXCANb_MBn_WORD1(b, n)          (*((vuint32_t *) ((b)+0x8C+(n)*16)))
#define FLEXCANb_IDAF(b, n)               (*((vuint32_t *) ((b)+0xE0+(n)*4)))
#define FLEXCANb_MB_MASK(b, n)            (*((vuint32_t *) ((b)+0x880+(n)*4)))

/* Bit definitions and macros for FLEXCAN_MB_CS */
#define FLEXCAN_MB_CS_TIMESTAMP(x)    (((x)&0x0000FFFF)<<0)
#define FLEXCAN_MB_CS_TIMESTAMP_MASK  (0x0000FFFFL)
#define FLEXCAN_MB_CS_LENGTH(x)       (((x)&0x0000000FU)<<16)
#define FLEXCAN_MB_CS_RTR             (0x00100000)
#define FLEXCAN_MB_CS_IDE             (0x00200000)
#define FLEXCAN_MB_CS_SRR             (0x00400000)
#define FLEXCAN_MB_CS_CODE(x)         (((x)&0x0000000FU)<<24)
#define FLEXCAN_MB_CS_CODE_MASK       (0x0F000000L)
#define FLEXCAN_MB_CS_DLC_MASK        (0x000F0000L)
#define FLEXCAN_MB_CODE_RX_INACTIVE   (0)
#define FLEXCAN_MB_CODE_RX_EMPTY      (4)
#define FLEXCAN_MB_CODE_RX_FULL       (2)
#define FLEXCAN_MB_CODE_RX_OVERRUN    (6)
#define FLEXCAN_MB_CODE_RX_BUSY       (1)

#define FLEXCAN_MB_CS_IDE_BIT_NO      (21)
#define FLEXCAN_MB_CS_RTR_BIT_NO      (20)
#define FLEXCAN_MB_CS_DLC_BIT_NO      (16)

#define FLEXCAN_MB_CODE_TX_BUSY     (0x01)
#define FLEXCAN_MB_CODE_TX_FULL     (0x02)
#define FLEXCAN_MB_CODE_TX_EMPTY    (0x04)
#define FLEXCAN_MB_CODE_TX_OVERRUN  (0x06)
#define FLEXCAN_MB_CODE_TX_INACTIVE  (0x08)
// #define FLEXCAN_MB_CODE_TX_ABORT    (0x09)
#define FLEXCAN_MB_CODE_TX_ONCE      (0x0C)
// #define FLEXCAN_MB_CODE_TX_RESPONSE  (0x0A)
// #define FLEXCAN_MB_CODE_TX_RESPONSE_TEMPO  (0x0E)

#define FLEXCAN_get_code(cs)        (((cs) & FLEXCAN_MB_CS_CODE_MASK)>>24)
#define FLEXCAN_get_length(cs)      (((cs) & FLEXCAN_MB_CS_DLC_MASK)>>16)

/* definitions and macros for FLEXCAN_MCR */
#define FLEXCAN_MCR_MAXMB(x)           (((x)&0x0000007F)<<0)
#define FLEXCAN_MCR_IDAM(x)            (((x)&0x00000003)<<8)
#define FLEXCAN_MCR_MAXMB_MASK         (0x0000007FU)
#define FLEXCAN_MCR_IDAM_MASK          (0x00000300U)
#define FLEXCAN_MCR_IDAM_BIT_NO        (8U)
#define FLEXCAN_MCR_AEN                (0x00001000U)
#define FLEXCAN_MCR_LPRIO_EN           (0x00002000U)
#define FLEXCAN_MCR_IRMQ               (0x00010000U)
#define FLEXCAN_MCR_SRX_DIS            (0x00020000U)
#define FLEXCAN_MCR_DOZE               (0x00040000U)
#define FLEXCAN_MCR_WAK_SRC            (0x00080000U)
#define FLEXCAN_MCR_LPM_ACK            (0x00100000U)
#define FLEXCAN_MCR_WRN_EN             (0x00200000U)
#define FLEXCAN_MCR_SLF_WAK            (0x00400000U)
#define FLEXCAN_MCR_SUPV               (0x00800000U)
#define FLEXCAN_MCR_FRZ_ACK            (0x01000000U)
#define FLEXCAN_MCR_SOFT_RST           (0x02000000U)
#define FLEXCAN_MCR_WAK_MSK            (0x04000000U)
#define FLEXCAN_MCR_NOT_RDY            (0x08000000U)
#define FLEXCAN_MCR_HALT               (0x10000000U)
#define FLEXCAN_MCR_FEN                (0x20000000U)
#define FLEXCAN_MCR_FRZ                (0x40000000U)
#define FLEXCAN_MCR_MDIS               (0x80000000U)

/* Bit definitions and macros for FLEXCAN_CTRL */
#define FLEXCAN_CTRL_PROPSEG(x)        (((uint32_t)(x)) << 0)
#define FLEXCAN_CTRL_LOM               (0x00000008U)
#define FLEXCAN_CTRL_LBUF              (0x00000010U)
#define FLEXCAN_CTRL_TSYNC             (0x00000020U)
#define FLEXCAN_CTRL_BOFF_REC          (0x00000040U)
#define FLEXCAN_CTRL_SMP               (0x00000080U)
#define FLEXCAN_CTRL_RWRN_MSK          (0x00000400U)
#define FLEXCAN_CTRL_TWRN_MSK          (0x00000800U)
#define FLEXCAN_CTRL_LPB               (0x00001000U)
#define FLEXCAN_CTRL_CLK_SRC           (0x00002000U)
#define FLEXCAN_CTRL_ERR_MSK           (0x00004000U)
#define FLEXCAN_CTRL_BOFF_MSK          (0x00008000U)
#define FLEXCAN_CTRL_PSEG2(x)          (((uint32_t) (x)) << 16)
#define FLEXCAN_CTRL_PSEG1(x)          (((uint32_t) (x)) << 19)
#define FLEXCAN_CTRL_RJW(x)            (((uint32_t) (x)) << 22)
#define FLEXCAN_CTRL_PRESDIV(x)        (((uint32_t) (x)) << 24)

/* Bit definitions and macros for FLEXCAN_MB_ID */
#define FLEXCAN_MB_ID_STD_MASK        (0x1FFC0000L)
#define FLEXCAN_MB_ID_EXT_MASK        (0x1FFFFFFFL)
#define FLEXCAN_MB_ID_IDEXT(x)        (((x)&0x0003FFFF)<<0)
#define FLEXCAN_MB_ID_IDSTD(x)        (((x)&0x000007FF)<<18)
#define FLEXCAN_MB_ID_PRIO(x)         (((x)&0x00000007)<<29)
#define FLEXCAN_MB_ID_PRIO_BIT_NO     (29)
#define FLEXCAN_MB_ID_STD_BIT_NO      (18)
#define FLEXCAN_MB_ID_EXT_BIT_NO      (0)

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//    FlexCAN Mailboxes configuration
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const int MB_COUNT = 16 ; // MB count is fixed by hardware

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// FlexCAN is configured for FIFO reception (MCR.FEN bit is set)
// The CTRL2.RFFN field defines the number of Rx FIFO filters (§56.4.12, page 1760)

// RFFN | MB used by RxFIFO | Rx Individual Masks     | Rx Acceptance Filters | Total Filter count
//    0 |    8 (0 ...  7)   |  8 (RXIMR0 ...  RXIMR7) |  0                    |  8
//    1 |   10 (0 ...  9)   | 10 (RXIMR0 ...  RXIMR9) |  6 (10 ... 15)        | 16
//    2 |   12 (0 ... 11)   | 12 (RXIMR0 ... RXIMR11) | 12 (12 ... 23)        | 24
//    3 |   14 (0 ... 13)   | 14 (RXIMR0 ... RXIMR13) | 18 (14 ... 31)        | 32
// Other RFFN values are not available for the Teensy microcontrollers.
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

typedef enum {k8_0_Filters, k10_6_Filters, k12_12_Filters, k14_18_Filters} FilterConfiguration ;

//······················································································································

static const FilterConfiguration kFilterConfiguration = k14_18_Filters ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static inline size_t RFFNForConfiguration (const FilterConfiguration inConfiguration) {
  return (size_t) inConfiguration ;
}

//······················································································································

static inline size_t primaryFilterCountForConfiguration (const FilterConfiguration inConfiguration) {
  return 8 + 2 * (size_t) inConfiguration ;
}

//······················································································································

static inline size_t secondaryFilterCountForConfiguration (const FilterConfiguration inConfiguration) {
  return 6 * (size_t) inConfiguration ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//    Constructor
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

ACAN::ACAN (const uint32_t inFlexcanBaseAddress) :
mFlexcanBaseAddress (inFlexcanBaseAddress),
mTransmitSemaphore (TRANSMIT_BUFFER_SIZE),
mTransmitBuffer (),
mTransmitBufferReadIndex (0),
mTransmitBufferCount (0),
mReceiveBuffer (),
mReceiveBufferReadIndex (0),
mReceiveBufferCount (0),
mReceiveBufferPeakCount (0),
mFlexcanRxFIFOFlags (0) {
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//    begin method
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

uint32_t ACAN::begin (INIT_MODE_
                      const ACANSettings & inSettings) {
  uint32_t errorCode = inSettings.CANBitSettingConsistency () ; // No error code
//--- No configuration if CAN bit settings are incorrect
  if (!inSettings.mBitSettingOk) {
    errorCode |= kCANBitConfiguration ;
  }
  if (0 == errorCode) {
  //---------- Set up the pins
    const uint32_t TxPinConfiguration = PORT_PCR_MUX(2) ; // Select function #2
    const uint32_t RxPinConfiguration = PORT_PCR_MUX(2) ; // Select function #2
    if (mFlexcanBaseAddress == FLEXCAN0_BASE) { // Can0
    // 29=PTB18=CAN0_TX, 30=PTB19=CAN0_RX (alternative)
      PORTB_PCR (18) = TxPinConfiguration ;
      PORTB_PCR (19) = RxPinConfiguration ;
    }else{ // Can1
    // 33=PTE24=CAN1_TX, 34=PTE25=CAN1_RX (default)
      PORTE_PCR (24) = TxPinConfiguration ;
      PORTE_PCR (25) = RxPinConfiguration ;
    }
  //---------- Power on FlexCAN module, select clock source 16MHz xtal
    OSC_CR |= OSC_CR_ERCLKEN ; // Enables external reference clock (§28.8.1.1)
    if (mFlexcanBaseAddress == FLEXCAN0_BASE) { // Teensy 3.6, Can 0
      SIM_SCGC6 |= SIM_SCGC6_FLEXCAN0 ;
    }else{  // Teensy 3.6, Can 1
      SIM_SCGC3 |= SIM_SCGC3_FLEXCAN1 ;
    }
    FLEXCANb_CTRL1 (mFlexcanBaseAddress) &= ~FLEXCAN_CTRL_CLK_SRC; // Use oscillator clock (16 MHz)
  //---------- Enable CAN
    FLEXCANb_MCR (mFlexcanBaseAddress) =
      (1U << 30) | // Enable to enter to freeze mode
      (1U << 23) | // FlexCAN is in supervisor mode
      (15U << 0)   // 16 MB
    ;
    while (FLEXCANb_MCR(mFlexcanBaseAddress) & FLEXCAN_MCR_LPM_ACK) {}
  //---------- Soft reset
    FLEXCANb_MCR(mFlexcanBaseAddress) |= FLEXCAN_MCR_SOFT_RST;
    while (FLEXCANb_MCR(mFlexcanBaseAddress) & FLEXCAN_MCR_SOFT_RST) {}
  //---------- Wait for freeze ack
    while (!(FLEXCANb_MCR(mFlexcanBaseAddress) & FLEXCAN_MCR_FRZ_ACK)) {}
  //---------- Can settings
    FLEXCANb_MCR (mFlexcanBaseAddress) |=
      (inSettings.mLoopBack ? 0 : FLEXCAN_MCR_SRX_DIS) | // Disable self-reception ?
      FLEXCAN_MCR_FEN  | // Set RxFIFO mode
      FLEXCAN_MCR_IRMQ   // Enable per-mailbox filtering (§56.4.2)
    ;
  //---------- Can bit timing (CTRL1)
    FLEXCANb_CTRL1 (mFlexcanBaseAddress) =
      FLEXCAN_CTRL_PROPSEG (inSettings.mPropagationSegment - 1) |
      FLEXCAN_CTRL_RJW (inSettings.mRJW - 1) |
      FLEXCAN_CTRL_PSEG1 (inSettings.mPhaseSegment1 - 1) |
      FLEXCAN_CTRL_PSEG2 (inSettings.mPhaseSegment2 - 1) |
      FLEXCAN_CTRL_PRESDIV (inSettings.mBitRatePrescaler - 1) |
      (inSettings.mTripleSampling ? FLEXCAN_CTRL_SMP : 0) |
      (inSettings.mLoopBack ? FLEXCAN_CTRL_LPB : 0)
    ;
  //---------- FIFO configuration
    const uint32_t RFFN = RFFNForConfiguration (kFilterConfiguration) ;
  //---------- CTRL2
    FLEXCANb_CTRL2 (mFlexcanBaseAddress) =
      (RFFN << 24) | // Number of RxFIFO
      (0x16 << 19) | // TASD: 0x16 is the default value
      (   0 << 18) | // MRP: Matching starts from RxFIFO and continues on mailboxes
      (   1 << 17) | // RRS: Remote request frame is stored
      (   1 << 16)   // EACEN: RTR bit in mask is always compared
    ;
  //---------- Setup reception filters
    errorCode |= setupReceptionFilters (MODE) ;
  //---------- Start CAN
    FLEXCANb_MCR (mFlexcanBaseAddress) &= ~FLEXCAN_MCR_HALT ;
  //---------- Wait till exit of freeze mode
    while (FLEXCANb_MCR (mFlexcanBaseAddress) & FLEXCAN_MCR_FRZ_ACK) {}
  //----------  Wait till ready
    while (FLEXCANb_MCR (mFlexcanBaseAddress) & FLEXCAN_MCR_NOT_RDY) {}
  //---------- Enable NVIC interrupts
    if (mFlexcanBaseAddress == FLEXCAN0_BASE) { // Teensy 3.6, Can 0
      NVIC_ENABLE_IRQ (ISRSlot::CAN0_ORed_Message_buffer);
    }else{  // Teensy 3.6, Can 1
      NVIC_ENABLE_IRQ (ISRSlot::CAN1_ORed_Message_buffer) ;
    }
  //---------- Enable CAN interrupts (§56.4.10)
    FLEXCANb_IMASK1 (mFlexcanBaseAddress) =
      (1 << 15) | // MB15 (data frame sending)
      (1 << 7) | // RxFIFO Overflow
      (1 << 6) | // RxFIFO Warning: number of messages in FIFO goes from 4 to 5
      (1 << 5)   // Data available in RxFIFO
    ;
  }
//--- Return error code (0 --> no error)
  return errorCode ;
}

//······················································································································

uint32_t ACAN::setupReceptionFilters (INIT_MODE) {
//---------- Setup RxFIFO filters
  const uint32_t MAX_PRIMARY_FILTER_COUNT = primaryFilterCountForConfiguration (kFilterConfiguration) ;
  const uint32_t MAX_SECONDARY_FILTER_COUNT = secondaryFilterCountForConfiguration (kFilterConfiguration) ;
//--- Default mask
  uint32_t defaultFilterMask = 0 ; // By default, accept any frame
  uint32_t defaultAcceptanceFilter = 0 ;
//--- Setup primary filters (individual filters in FlexCAN vocabulary)
  for (uint32_t i=0 ; i<MAX_PRIMARY_FILTER_COUNT ; i++) {
    FLEXCANb_MB_MASK (mFlexcanBaseAddress, i) = defaultFilterMask ;
    FLEXCANb_IDAF (mFlexcanBaseAddress, i) = defaultAcceptanceFilter ;
  }
//--- Setup secondary filters (filter mask for Rx individual acceptance filter)
  FLEXCANb_RXFGMASK (mFlexcanBaseAddress) = defaultFilterMask ;
  for (uint32_t i=0 ; i<MAX_SECONDARY_FILTER_COUNT ; i++) {
    FLEXCANb_IDAF (mFlexcanBaseAddress, i + MAX_PRIMARY_FILTER_COUNT) = defaultAcceptanceFilter ;
  }
//---------- Make all other MB inactive
  for (uint32_t i = MAX_PRIMARY_FILTER_COUNT ; i < MB_COUNT ; i++) {
    FLEXCANb_MB_MASK (mFlexcanBaseAddress, i) = 0 ;
    FLEXCANb_MBn_CS (mFlexcanBaseAddress, i) = FLEXCAN_MB_CS_CODE (FLEXCAN_MB_CODE_TX_INACTIVE) ;
  }
//---
  return 0 ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   RECEPTION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool ACAN::section_receive (SECTION_MODE_ CANMessage & outMessage) {
  const bool hasMessage = mReceiveBufferCount > 0 ;
  if (hasMessage) {
    outMessage = mReceiveBuffer [mReceiveBufferReadIndex] ;
    mReceiveBufferReadIndex = (mReceiveBufferReadIndex + 1) % RECEIVE_BUFFER_SIZE ;
    mReceiveBufferCount -= 1 ;
  }
  return hasMessage ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   EMISSION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ACAN::send (USER_MODE_ const CANMessage & inMessage) {
  mTransmitSemaphore.P (MODE) ;
  internalSend (MODE_ inMessage) ;
}

//······················································································································

void ACAN::kernel_internalSend (KERNEL_MODE_ const CANMessage & inMessage) {
//--- Write direcly to send mailbox if inactive
  const uint32_t TxMailBoxIndex = 15 ;
  const uint32_t code = FLEXCAN_get_code (FLEXCANb_MBn_CS (mFlexcanBaseAddress, TxMailBoxIndex)) ;
  if (code == FLEXCAN_MB_CODE_TX_INACTIVE) {
    writeTxRegisters (MODE_ inMessage, TxMailBoxIndex);
    mTransmitSemaphore.sys_V (MODE) ;
  }else{ // Not sent
  //--- Append message to buffer
    const uint32_t transmitBufferWriteIndex = (mTransmitBufferReadIndex + mTransmitBufferCount) % TRANSMIT_BUFFER_SIZE ;
    mTransmitBuffer [transmitBufferWriteIndex] = inMessage ;
    mTransmitBufferCount += 1 ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ACAN::writeTxRegisters (SECTION_MODE_ const CANMessage & inMessage, const uint32_t inMBIndex) {
//--- Make Tx box inactive
  FLEXCANb_MBn_CS (mFlexcanBaseAddress, inMBIndex) = FLEXCAN_MB_CS_CODE (FLEXCAN_MB_CODE_TX_INACTIVE) ;
//--- Write identifier
  FLEXCANb_MBn_ID (mFlexcanBaseAddress, inMBIndex) = (inMessage.mFormat == kExtended)
    ? (inMessage.mIdentifier & FLEXCAN_MB_ID_EXT_MASK)
    : FLEXCAN_MB_ID_IDSTD (inMessage.mIdentifier)
  ;
//--- Write data (registers are big endian, values should be swapped)
  FLEXCANb_MBn_WORD0 (mFlexcanBaseAddress, inMBIndex) = __builtin_bswap32 (inMessage.mData32 [0]) ;
  FLEXCANb_MBn_WORD1 (mFlexcanBaseAddress, inMBIndex) = __builtin_bswap32 (inMessage.mData32 [1]) ;
//--- Send message
  const uint8_t length = (inMessage.mLength <= 8) ? inMessage.mLength : 8 ;
  uint32_t command = FLEXCAN_MB_CS_CODE (FLEXCAN_MB_CODE_TX_ONCE) | FLEXCAN_MB_CS_LENGTH (length) ;
  if (inMessage.mFormat == kExtended) {
    command |= FLEXCAN_MB_CS_SRR | FLEXCAN_MB_CS_IDE ;
  }
  FLEXCANb_MBn_CS (mFlexcanBaseAddress, inMBIndex) = command ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   MESSAGE INTERRUPT SERVICE ROUTINES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ACAN::readRxRegisters (IRQ_MODE_ CANMessage & outMessage) {
//--- Get identifier, ext, rtr and len
  const uint32_t dlc = FLEXCANb_MBn_CS (mFlexcanBaseAddress, 0) ;
  outMessage.mLength = FLEXCAN_get_length (dlc) ;
  if (outMessage.mLength > 8) {
    outMessage.mLength = 8 ;
  }
  outMessage.mFormat = ((dlc & FLEXCAN_MB_CS_IDE) != 0) ? kExtended : kStandard ;
  outMessage.mIdentifier = FLEXCANb_MBn_ID (mFlexcanBaseAddress, 0) & FLEXCAN_MB_ID_EXT_MASK ;
  if (outMessage.mFormat == kStandard) {
    outMessage.mIdentifier >>= FLEXCAN_MB_ID_STD_BIT_NO ;
  }
//-- Get data (registers are big endian, values should be swapped)
  outMessage.mData32 [0] = __builtin_bswap32 (FLEXCANb_MBn_WORD0 (mFlexcanBaseAddress, 0)) ;
  outMessage.mData32 [1] = __builtin_bswap32 (FLEXCANb_MBn_WORD1 (mFlexcanBaseAddress, 0)) ;
//--- Zero unused data entries
  for (uint32_t i = outMessage.mLength ; i < 8 ; i++) {
    outMessage.mData [i] = 0 ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ACAN::message_isr (IRQ_MODE) {
  const uint32_t status = FLEXCANb_IFLAG1 (mFlexcanBaseAddress) ;
//--- A trame has been received in RxFIFO ?
  if ((status & (1 << 5)) != 0) {
    CANMessage message ;
    readRxRegisters (MODE_ message) ;
    if (mReceiveBufferCount == RECEIVE_BUFFER_SIZE) { // Overflow! Receive buffer is full
      mReceiveBufferPeakCount = RECEIVE_BUFFER_SIZE + 1 ; // Mark overflow
    }else{
      uint32_t receiveBufferWriteIndex = mReceiveBufferReadIndex + mReceiveBufferCount ;
      if (receiveBufferWriteIndex >= RECEIVE_BUFFER_SIZE) {
        receiveBufferWriteIndex -= RECEIVE_BUFFER_SIZE ;
      }
      mReceiveBuffer [receiveBufferWriteIndex] = message ;
      mReceiveBufferCount += 1 ;
      if (mReceiveBufferCount > mReceiveBufferPeakCount) {
        mReceiveBufferPeakCount = mReceiveBufferCount ;
      }
    }
  }
//--- RxFIFO warning ? It occurs when the number of messages goes from 4 to 5
  if ((status & (1 << 6)) != 0) {
    mFlexcanRxFIFOFlags |= 1 ;
  }
//--- RxFIFO Overflow ?
  if ((status & (1 << 7)) != 0) {
    mFlexcanRxFIFOFlags |= 2 ;
  }
//--- Handle Tx MBs
  if (mTransmitBufferCount > 0) { // There is a frame in the queue to send
    const uint32_t TxMailBoxIndex = 15 ;
    const uint32_t code = FLEXCAN_get_code (FLEXCANb_MBn_CS (mFlexcanBaseAddress, TxMailBoxIndex));
    if (code == FLEXCAN_MB_CODE_TX_INACTIVE) {
      writeTxRegisters (MODE_ mTransmitBuffer [mTransmitBufferReadIndex], TxMailBoxIndex);
      mTransmitBufferReadIndex = (mTransmitBufferReadIndex + 1) % TRANSMIT_BUFFER_SIZE ;
      mTransmitBufferCount -= 1 ;
      mTransmitSemaphore.sys_V (MODE) ;
    }
  }
//--- Writing its value back to itself clears all flags
  FLEXCANb_IFLAG1 (mFlexcanBaseAddress) = status ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void can0_message_isr (IRQ_MODE) {
  ACAN::can0.message_isr (MODE) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void can1_message_isr (IRQ_MODE) {
  ACAN::can1.message_isr (MODE) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   Drivers as global variables
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

ACAN ACAN::can0 (FLEXCAN0_BASE) ;

//······················································································································

ACAN ACAN::can1 (FLEXCAN1_BASE) ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
