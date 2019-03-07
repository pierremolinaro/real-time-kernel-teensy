//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#pragma once

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "software-modes.h"
#include "can-settings.h"
#include "CANMessage.h"
#include "Semaphore.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint32_t TRANSMIT_BUFFER_SIZE = 16 ;
static const uint32_t RECEIVE_BUFFER_SIZE  = 32 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class ACAN {

//······················································································································
//   Constructor
//······················································································································

  private: ACAN (const uint32_t inFlexcanBaseAddress) ;

//······················································································································
//   begin
//······················································································································

  public: uint32_t begin (INIT_MODE_
                          const ACANSettings & inSettings) ;

//--- begin; returns a result code :
//  0 : Ok
//  other: every bit denotes an error
  public: static const uint32_t kTooMuchPrimaryFilters     = 1 << 12 ;
  public: static const uint32_t kNotConformPrimaryFilter   = 1 << 13 ;
  public: static const uint32_t kTooMuchSecondaryFilters   = 1 << 14 ;
  public: static const uint32_t kNotConformSecondaryFilter = 1 << 15 ;
  public: static const uint32_t kCANBitConfiguration       = 1 << 18 ;

//······················································································································
//   Base address
//······················································································································

  private: const uint32_t mFlexcanBaseAddress ; // Initialized in constructor

//······················································································································
//   Transmitting messages
//······················································································································

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

//······················································································································
//   Receiving messages
//······················································································································

//$section can.receive
  public: bool receive (USER_MODE_ CANMessage & outMessage) asm ("can.receive") ;
  public: bool section_receive (SECTION_MODE_ CANMessage & outMessage) asm ("section.can.receive") ;

//--- Driver receive buffer
  private: CANMessage mReceiveBuffer [RECEIVE_BUFFER_SIZE] ;
  private: uint32_t mReceiveBufferReadIndex ;
  private: uint32_t mReceiveBufferCount ;
  private: uint32_t mReceiveBufferPeakCount ; // == mReceiveBufferSize + 1 if overflow did occur
  private: uint8_t mFlexcanRxFIFOFlags ;
  private: uint32_t setupReceptionFilters (INIT_MODE) ;
  private: void readRxRegisters (IRQ_MODE_ CANMessage & outMessage) ;

//······················································································································
//   Message interrupt service routines
//······················································································································

  private: void message_isr (IRQ_MODE) ;
  friend void can0_message_isr (IRQ_MODE) ;
  friend void can1_message_isr (IRQ_MODE) ;

//······················································································································
//   Driver instances
//······················································································································

  public: static ACAN can0 ;
  public: static ACAN can1 ;

//······················································································································
//   No copy
//······················································································································

  private : ACAN (const ACAN &) = delete ;
  private : ACAN & operator = (const ACAN &) = delete ;

//······················································································································

} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   INTERRUPT ROUTINES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//$interrupt-service CAN0_ORed_Message_buffer
void can0_message_isr (IRQ_MODE) asm ("interrupt.service.CAN0_ORed_Message_buffer") ;


//$interrupt-service CAN1_ORed_Message_buffer
void can1_message_isr (IRQ_MODE) asm ("interrupt.service.CAN1_ORed_Message_buffer") ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
