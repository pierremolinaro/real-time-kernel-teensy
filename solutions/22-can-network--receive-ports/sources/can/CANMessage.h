#pragma once

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <stdint.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

typedef enum {kStandard, kExtended} tFrameFormat ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class CANMessage {
  public: uint32_t mIdentifier = 0 ;  // Frame identifier
  public: tFrameFormat mFormat = kStandard ; // kStandard -> standard frame, kExtended -> extended frame
  public: uint8_t mLength = 0 ;  // Length of data (0 ... 8)
  public: union {
    uint64_t mData64     ; // Caution: subject to endianness
    uint32_t mData32 [2] ; // Caution: subject to endianness
    uint16_t mData16 [4] ; // Caution: subject to endianness
    uint8_t  mData   [8] = {0, 0, 0, 0, 0, 0, 0, 0} ;
  } ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
