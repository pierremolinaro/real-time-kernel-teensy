//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#pragma once

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "software-modes.h"
#include "can-settings.h"
#include "CANMessage.h"
#include "Semaphore.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint32_t TRANSMIT_BUFFER_SIZE = 16 ;

typedef void (*ACANCallBackRoutine) (const CANMessage & inMessage) ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class ACANPrimaryFilter {
  public: uint32_t mFilterMask ;
  public: uint32_t mAcceptanceFilter ;
  public: ACANCallBackRoutine mCallBackRoutine ;

  public: inline ACANPrimaryFilter (const ACANCallBackRoutine inCallBackRoutine) :  // Accept any frame
  mFilterMask (0),
  mAcceptanceFilter (0),
  mCallBackRoutine (inCallBackRoutine) {
  }

  public: ACANPrimaryFilter (const tFrameFormat inFormat, // Accept any identifier
                             const ACANCallBackRoutine inCallBackRoutine = NULL) ;

  public: ACANPrimaryFilter (const tFrameFormat inFormat,
                             const uint32_t inIdentifier,
                             const ACANCallBackRoutine inCallBackRoutine = NULL) ;

  public: ACANPrimaryFilter (const tFrameFormat inFormat,
                             const uint32_t inMask,
                             const uint32_t inAcceptance,
                             const ACANCallBackRoutine inCallBackRoutine = NULL) ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class ACANSecondaryFilter {
  public: uint32_t mSingleAcceptanceFilter ;
  public: ACANCallBackRoutine mCallBackRoutine ;

  public: ACANSecondaryFilter (const tFrameFormat inFormat,
                               const uint32_t inIdentifier,
                               const ACANCallBackRoutine inCallBackRoutine = NULL) ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class ACAN {
//--- Constructor
  private: ACAN (const uint32_t inFlexcanBaseAddress) ;

//--- begin; returns a result code :
//  0 : Ok
//  other: every bit denotes an error
  public: static const uint32_t kTooMuchPrimaryFilters     = 1 << 12 ;
  public: static const uint32_t kNotConformPrimaryFilter   = 1 << 13 ;
  public: static const uint32_t kTooMuchSecondaryFilters   = 1 << 14 ;
  public: static const uint32_t kNotConformSecondaryFilter = 1 << 15 ;
  public: static const uint32_t kCANBitConfiguration       = 1 << 18 ;

  public: uint32_t begin (INIT_MODE_
                          const ACANSettings & inSettings,
                          const ACANPrimaryFilter inPrimaryFilters [] = NULL ,
                          const uint32_t inPrimaryFilterCount = 0,
                          const ACANSecondaryFilter inSecondaryFilters [] = NULL,
                          const uint32_t inSecondaryFilterCount = 0) ;

//-------------------------------------- Base address
  private: const uint32_t mFlexcanBaseAddress ; // Initialized in constructor

//-------------------------------------- Transmitting messages
  public: void send (USER_MODE_ const CANMessage & inMessage) ;

//$service internal.send
  private: void internalSend (USER_MODE_ const CANMessage & inMessage) asm ("internal.send") ;
  private: void kernel_internalSend (KERNEL_MODE_ const CANMessage & inMessage) asm ("service.internal.send") ;

//--- Driver transmit buffer
  private: Semaphore mTransmitSemaphore ;
  private: CANMessage mTransmitBuffer [TRANSMIT_BUFFER_SIZE] ;
  private: uint32_t mTransmitBufferReadIndex ; // 0 ... TRANSMIT_BUFFER_SIZE-1
  private: uint32_t mTransmitBufferCount ; // 0 ... TRANSMIT_BUFFER_SIZE

//--- Internal send method
  private: void writeTxRegisters (SECTION_MODE_ const CANMessage & inMessage, const uint32_t inMBIndex) ;

//-------------------------------------- Receiving messages
  public: bool receive (USER_MODE_ CANMessage & outMessage) ;

//--- Call back function array
  private: ACANCallBackRoutine * mCallBackFunctionArray = NULL ;
  private: uint32_t mCallBackFunctionArraySize = 0 ;

//--- Driver receive buffer
  private: CANMessage * volatile mReceiveBuffer = NULL ;
  private: uint32_t mReceiveBufferSize = 0 ;
  private: uint32_t mReceiveBufferReadIndex = 0 ; // Only used in user mode --> no volatile
  private: volatile uint32_t mReceiveBufferCount = 0 ; // Used in isr and user mode --> volatile
  private: volatile uint32_t mReceiveBufferPeakCount = 0 ; // == mReceiveBufferSize + 1 if overflow did occur
  private : uint8_t mFlexcanRxFIFOFlags = 0 ;
  private : void readRxRegisters (IRQ_MODE_ const uint32_t inFlexcanBaseAddress, CANMessage & outMessage) ;

//--- Primary filters
  private : uint8_t mActualPrimaryFilterCount = 0 ;
  private : uint8_t mMaxPrimaryFilterCount = 0 ;

//-------------------------------------- Message interrupt service routine
  private: void message_isr (IRQ_MODE) ;
  friend void can0_message_isr (IRQ_MODE) ;
  friend void can1_message_isr (IRQ_MODE) ;

//-------------------------------------- Driver instances
  public: static ACAN can0 ;
  public: static ACAN can1 ;

//-------------------------------------- No copy
  private : ACAN (const ACAN &) = delete ;
  private : ACAN & operator = (const ACAN &) = delete ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   INTERRUPT ROUTINES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//$interrupt-service CAN0_ORed_Message_buffer
void can0_message_isr (IRQ_MODE) asm ("interrupt.service.CAN0_ORed_Message_buffer") ;


//$interrupt-service CAN1_ORed_Message_buffer
void can1_message_isr (IRQ_MODE) asm ("interrupt.service.CAN1_ORed_Message_buffer") ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
