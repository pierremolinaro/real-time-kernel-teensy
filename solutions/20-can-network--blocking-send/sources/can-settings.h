#pragma once

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <stdint.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class ACANSettings {

//······················································································································
//    Constructor for a given baud rate
//······················································································································

  public: explicit ACANSettings (INIT_MODE_
                                 const uint32_t inWhishedBitRate,
                                 const uint32_t inTolerancePPM = 1000) ;

//······················································································································
//   CAN bit timing (default values correspond to 250 kb/s)
//······················································································································

  public: uint32_t mWhishedBitRate = 250 * 1000 ; // In kb/s
  public: uint16_t mBitRatePrescaler = 4 ; // 1...256
  public: uint8_t mPropagationSegment = 5 ; // 1...8
  public: uint8_t mPhaseSegment1 = 5 ; // 1...8
  public: uint8_t mPhaseSegment2 = 5 ;  // 2...8
  public: uint8_t mRJW = 4 ; // 1...4
  public: bool mTripleSampling = false ; // true --> triple sampling, false --> single sampling
  public: bool mBitSettingOk = true ; // The above configuration is correct

//······················································································································
//    Loop Back mode
//······················································································································

  public: bool mLoopBack = false ; // true --> loop back mode, false --> no loop back

//······················································································································
//    Compute actual bit rate
//······················································································································

  public: uint32_t actualBitRate (void) const ;

//······················································································································
//    Exact bit rate ?
//······················································································································

  public: bool exactBitRate (void) const ;

//······················································································································
//    Distance between actual bit rate and requested bit rate (in ppm, part-per-million)
//······················································································································

  public: uint32_t ppmFromWishedBitRate (void) const ;

//······················································································································
//    Distance of sample point from bit start (in ppc, part-per-cent, denoted by %)
//······················································································································

  public: uint32_t samplePointFromBitStart (void) const ;

//······················································································································
//    Bit settings are consistent ? (returns 0 if ok)
//······················································································································

  public: uint32_t CANBitSettingConsistency (void) const ;

//--- Constants returned by CANBitSettingConsistency
  public: static const uint32_t kBitRatePrescalerIsZero            = 1 <<  0 ;
  public: static const uint32_t kBitRatePrescalerIsGreaterThan256  = 1 <<  1 ;
  public: static const uint32_t kPropagationSegmentIsZero          = 1 <<  2 ;
  public: static const uint32_t kPropagationSegmentIsGreaterThan8  = 1 <<  3 ;
  public: static const uint32_t kPhaseSegment1IsZero               = 1 <<  4 ;
  public: static const uint32_t kPhaseSegment1IsGreaterThan8       = 1 <<  5 ;
  public: static const uint32_t kPhaseSegment2IsZero               = 1 <<  6 ;
  public: static const uint32_t kPhaseSegment2IsGreaterThan8       = 1 <<  7 ;
  public: static const uint32_t kRJWIsZero                         = 1 <<  8 ;
  public: static const uint32_t kRJWIsGreaterThan4                 = 1 <<  9 ;
  public: static const uint32_t kRJWIsGreaterThanPhaseSegment2     = 1 << 10 ;
  public: static const uint32_t kPhaseSegment1Is1AndTripleSampling = 1 << 11 ;

//······················································································································

} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
