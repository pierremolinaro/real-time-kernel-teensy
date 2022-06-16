#include "all-headers.h"

//-----------------------------------------------------------------------------

void pinMode (const DigitalPort inPort, const DigitalMode inMode) {
//--- Set config and dir to apply
  uint32_t config = 0 ;
  bool output = false ;
  switch (inMode) {
  case DigitalMode::OUTPUT :
    config = PORT_PCR_MUX (1) ;
    output = true ;
    break ;
  case DigitalMode::OUTPUT_OPEN_COLLECTOR :
    config = PORT_PCR_MUX (1) | PORT_PCR_ODE ;
    output = true ;
    break ;
  case DigitalMode::INPUT :
    config = PORT_PCR_MUX(1) ;
    break ;
  case DigitalMode::INPUT_PULLDOWN :
    config = PORT_PCR_MUX(1) | PORT_PCR_PE ;
    break ;
  case DigitalMode::INPUT_PULLUP :
    config = PORT_PCR_MUX(1) | PORT_PCR_PE | PORT_PCR_PS ;
    break ;
  }
//--- Apply
  switch (inPort) {
  case DigitalPort::D0 : // PTB16
    PORTB_PCR (16) = config ;
    bitband32 (GPIOB_PDDR, 16, output) ;
    break ;
  case DigitalPort::D1 : // PTB17
    PORTB_PCR (17) = config ;
    bitband32 (GPIOB_PDDR, 17, output) ;
    break ;
  case DigitalPort::D2 : // PTD0
    PORTD_PCR (0) = config ;
    bitband32 (GPIOD_PDDR, 0, output) ;
    break ;
  case DigitalPort::D3 : // PTA12
    PORTA_PCR (12) = config ;
    bitband32 (GPIOA_PDDR, 12, output) ;
    break ;
  case DigitalPort::D4 : // PTA13
    PORTA_PCR (13) = config ;
    bitband32 (GPIOA_PDDR, 13, output) ;
    break ;
  case DigitalPort::D5 : // PTD7
    PORTD_PCR (7) = config ;
    bitband32 (GPIOD_PDDR, 7, output) ;
    break ;
  case DigitalPort::D6 : // PTD4
    PORTD_PCR (4) = config ;
    bitband32 (GPIOD_PDDR, 4, output) ;
    break ;
  case DigitalPort::D7 : // PTD2
    PORTD_PCR (2) = config ;
    bitband32 (GPIOD_PDDR, 2, output) ;
    break ;
  case DigitalPort::D8 : // PTD3
    PORTD_PCR (3) = config ;
    bitband32 (GPIOD_PDDR, 3, output) ;
    break ;
  case DigitalPort::D9  : // PTC3
    PORTC_PCR (3) = config ;
    bitband32 (GPIOC_PDDR, 3, output) ;
    break ;
  case DigitalPort::D10 : // PTC4
    PORTC_PCR (4) = config ;
    bitband32 (GPIOC_PDDR, 4, output) ;
    break ;
  case DigitalPort::D11 : // PTC6
    PORTC_PCR (6) = config ;
    bitband32 (GPIOC_PDDR, 6, output) ;
    break ;
  case DigitalPort::D12 : // PTC7
    PORTC_PCR (7) = config ;
    bitband32 (GPIOC_PDDR, 7, output) ;
    break ;
  case DigitalPort::D13 : // PTC5
    PORTC_PCR (5) = config ;
    bitband32 (GPIOC_PDDR, 5, output) ;
    break ;
  case DigitalPort::D14 : // PTD1
    PORTD_PCR (1) = config ;
    bitband32 (GPIOD_PDDR, 1, output) ;
    break ;
  case DigitalPort::D15 : // PTC0
    PORTC_PCR (0) = config ;
    bitband32 (GPIOC_PDDR, 0, output) ;
    break ;
  case DigitalPort::D16 : // PTB0
    PORTB_PCR (0) = config ;
    bitband32 (GPIOB_PDDR, 0, output) ;
    break ;
  case DigitalPort::D17 : // PTB1
    PORTB_PCR (1) = config ;
    bitband32 (GPIOB_PDDR, 1, output) ;
    break ;
  case DigitalPort::D18 : // PTB3
    PORTB_PCR (3) = config ;
    bitband32 (GPIOB_PDDR, 3, output) ;
    break ;
  case DigitalPort::D19 : // PTB2
    PORTB_PCR (2) = config ;
    bitband32 (GPIOB_PDDR, 2, output) ;
    break ;
  case DigitalPort::D20 : // PTD5
    PORTD_PCR (5) = config ;
    bitband32 (GPIOD_PDDR, 5, output) ;
    break ;
  case DigitalPort::D21 : // PTD6
    PORTD_PCR (6) = config ;
    bitband32 (GPIOD_PDDR, 6, output) ;
    break ;
  case DigitalPort::D22 : // PTC1
    PORTC_PCR (1) = config ;
    bitband32 (GPIOC_PDDR, 1, output) ;
    break ;
  case DigitalPort::D23 : // PTC2
    PORTC_PCR (2) = config ;
    bitband32 (GPIOC_PDDR, 2, output) ;
    break ;
  case DigitalPort::D24 : // PTE26
    PORTE_PCR (26) = config ;
    bitband32 (GPIOE_PDDR, 26, output) ;
    break ;
  case DigitalPort::D25 : // PTA5
    PORTA_PCR (5) = config ;
    bitband32 (GPIOA_PDDR, 5, output) ;
    break ;
  case DigitalPort::D26 : // PTA14
    PORTA_PCR (14) = config ;
    bitband32 (GPIOA_PDDR, 14, output) ;
    break ;
  case DigitalPort::D27 : // PTA15
    PORTA_PCR (15) = config ;
    bitband32 (GPIOA_PDDR, 15, output) ;
    break ;
  case DigitalPort::D28 : // PTA16
    PORTA_PCR (16) = config ;
    bitband32 (GPIOA_PDDR, 16, output) ;
    break ;
  case DigitalPort::D29 : // PTB18
    PORTB_PCR (18) = config ;
    bitband32 (GPIOB_PDDR, 18, output) ;
    break ;
  case DigitalPort::D30 : // PTB19
    PORTB_PCR (19) = config ;
    bitband32 (GPIOB_PDDR, 19, output) ;
    break ;
  case DigitalPort::D31 : // PTB10
    PORTB_PCR (10) = config ;
    bitband32 (GPIOB_PDDR, 10, output) ;
    break ;
  case DigitalPort::D32 : // PTB11
    PORTB_PCR (11) = config ;
    bitband32 (GPIOB_PDDR, 11, output) ;
    break ;
  case DigitalPort::D33 : // PTE24
    PORTE_PCR (24) = config ;
    bitband32 (GPIOE_PDDR, 24, output) ;
    break ;
  case DigitalPort::D34 : // PTE25
    PORTE_PCR (25) = config ;
    bitband32 (GPIOE_PDDR, 25, output) ;
    break ;
  case DigitalPort::D35 : // PTC8
    PORTC_PCR (8) = config ;
    bitband32 (GPIOC_PDDR, 8, output) ;
    break ;
  case DigitalPort::D36 : // PTC9
    PORTC_PCR (9) = config ;
    bitband32 (GPIOC_PDDR, 9, output) ;
    break ;
  case DigitalPort::D37 : // PTC10
    PORTC_PCR (10) = config ;
    bitband32 (GPIOC_PDDR, 10, output) ;
    break ;
  case DigitalPort::D38 : // PTC11
    PORTC_PCR (11) = config ;
    bitband32 (GPIOC_PDDR, 11, output) ;
    break ;
 case DigitalPort::D39 : // PTA17
    PORTA_PCR (17) = config ;
    bitband32 (GPIOA_PDDR, 17, output) ;
    break ;
  case DigitalPort::D40 : // PTA28
    PORTA_PCR (28) = config ;
    bitband32 (GPIOA_PDDR, 28, output) ;
    break ;
  case DigitalPort::D41 : // PTA29
    PORTA_PCR (29) = config ;
    bitband32 (GPIOA_PDDR, 29, output) ;
    break ;
  case DigitalPort::D42 : // PTA26
    PORTA_PCR (26) = config ;
    bitband32 (GPIOA_PDDR, 26, output) ;
    break ;
  case DigitalPort::D43 : // PTB20
    PORTB_PCR (20) = config ;
    bitband32 (GPIOB_PDDR, 20, output) ;
    break ;
  case DigitalPort::D44 : // PTB22
    PORTB_PCR (22) = config ;
    bitband32 (GPIOB_PDDR, 22, output) ;
    break ;
  case DigitalPort::D45 : // PTB23
    PORTB_PCR (23) = config ;
    bitband32 (GPIOB_PDDR, 23, output) ;
    break ;
  case DigitalPort::D46 : // PTB21
    PORTB_PCR (21) = config ;
    bitband32 (GPIOB_PDDR, 21, output) ;
    break ;
  case DigitalPort::D47 : // PTD8
    PORTD_PCR (8) = config ;
    bitband32 (GPIOD_PDDR, 8, output) ;
    break ;
  case DigitalPort::D48 : // PTD9
    PORTD_PCR (9) = config ;
    bitband32 (GPIOD_PDDR, 9, output) ;
    break ;
  case DigitalPort::D49 : // PTB4
    PORTB_PCR (4) = config ;
    bitband32 (GPIOB_PDDR, 4, output) ;
    break ;
  case DigitalPort::D50 : // PTB5
    PORTB_PCR (5) = config ;
    bitband32 (GPIOB_PDDR, 5, output) ;
    break ;
  case DigitalPort::D51 : // PTD14
    PORTD_PCR (14) = config ;
    bitband32 (GPIOD_PDDR, 14, output) ;
    break ;
  case DigitalPort::D52 : // PTD13
    PORTD_PCR (13) = config ;
    bitband32 (GPIOD_PDDR, 13, output) ;
    break ;
  case DigitalPort::D53 : // PTD12
    PORTD_PCR (12) = config ;
    bitband32 (GPIOD_PDDR, 12, output) ;
    break ;
  case DigitalPort::D54 : // PTD15
    PORTD_PCR (15) = config ;
    bitband32 (GPIOD_PDDR, 15, output) ;
    break ;
 case DigitalPort::D55 : // PTD11
    PORTD_PCR (11) = config ;
    bitband32 (GPIOD_PDDR, 11, output) ;
    break ;
  case DigitalPort::D56 : // PTE10
    PORTE_PCR (10) = config ;
    bitband32 (GPIOE_PDDR, 10, output) ;
    break ;
  case DigitalPort::D57 : // PTE11
    PORTE_PCR (11) = config ;
    bitband32 (GPIOE_PDDR, 11, output) ;
    break ;
  case DigitalPort::True : // No port
  case DigitalPort::False : // No port
    break ;
  }
}

//-----------------------------------------------------------------------------

void digitalWrite (const DigitalPort inPort, const bool inValue) {
  switch (inPort) {
  case DigitalPort::D0 : // PTB16
    if (inValue) {
      GPIOB_PSOR = 1 << 16 ;
    }else{
      GPIOB_PCOR = 1 << 16 ;
    }
    break ;
  case DigitalPort::D1 : // PTB17
    if (inValue) {
      GPIOB_PSOR = 1 << 17 ;
    }else{
      GPIOB_PCOR = 1 << 17 ;
    }
    break ;
  case DigitalPort::D2 : // PTD0
    if (inValue) {
      GPIOD_PSOR = 1 << 0 ;
    }else{
      GPIOD_PCOR = 1 << 0 ;
    }
    break ;
  case DigitalPort::D3 : // PTA12
    if (inValue) {
      GPIOA_PSOR = 1 << 12 ;
    }else{
      GPIOA_PCOR = 1 << 12 ;
    }
    break ;
  case DigitalPort::D4 : // PTA13
    if (inValue) {
      GPIOA_PSOR = 1 << 13 ;
    }else{
      GPIOA_PCOR = 1 << 13 ;
    }
    break ;
  case DigitalPort::D5 : // PTD7
    if (inValue) {
      GPIOD_PSOR = 1 << 7 ;
    }else{
      GPIOD_PCOR = 1 << 7 ;
    }
    break ;
  case DigitalPort::D6 : // PTD4
    if (inValue) {
      GPIOD_PSOR = 1 << 4 ;
    }else{
      GPIOD_PCOR = 1 << 4 ;
    }
    break ;
  case DigitalPort::D7 : // PTD2
    if (inValue) {
      GPIOD_PSOR = 1 << 2 ;
    }else{
      GPIOD_PCOR = 1 << 2 ;
    }
    break ;
  case DigitalPort::D8 : // PTD3
    if (inValue) {
      GPIOD_PSOR = 1 << 3 ;
    }else{
      GPIOD_PCOR = 1 << 3 ;
    }
    break ;
  case DigitalPort::D9  : // PTC3
    if (inValue) {
      GPIOC_PSOR = 1 << 3 ;
    }else{
      GPIOC_PCOR = 1 << 3 ;
    }
    break ;
  case DigitalPort::D10 : // PTC4
    if (inValue) {
      GPIOC_PSOR = 1 << 4 ;
    }else{
      GPIOC_PCOR = 1 << 4 ;
    }
    break ;
  case DigitalPort::D11 : // PTC6
    if (inValue) {
      GPIOC_PSOR = 1 << 6 ;
    }else{
      GPIOC_PCOR = 1 << 6 ;
    }
    break ;
  case DigitalPort::D12 : // PTC7
    if (inValue) {
      GPIOC_PSOR = 1 << 7 ;
    }else{
      GPIOC_PCOR = 1 << 7 ;
    }
    break ;
  case DigitalPort::D13 : // PTC5
    if (inValue) {
      GPIOC_PSOR = 1 << 5 ;
    }else{
      GPIOC_PCOR = 1 << 5 ;
    }
    break ;
  case DigitalPort::D14 : // PTD1
    if (inValue) {
      GPIOD_PSOR = 1 << 1 ;
    }else{
      GPIOD_PCOR = 1 << 1 ;
    }
    break ;
  case DigitalPort::D15 : // PTC0
    if (inValue) {
      GPIOC_PSOR = 1 << 0 ;
    }else{
      GPIOC_PCOR = 1 << 0 ;
    }
    break ;
  case DigitalPort::D16 : // PTB0
    if (inValue) {
      GPIOB_PSOR = 1 << 0 ;
    }else{
      GPIOB_PCOR = 1 << 0 ;
    }
    break ;
  case DigitalPort::D17 : // PTB1
    if (inValue) {
      GPIOB_PSOR = 1 << 1 ;
    }else{
      GPIOB_PCOR = 1 << 1 ;
    }
    break ;
  case DigitalPort::D18 : // PTB3
    if (inValue) {
      GPIOB_PSOR = 1 << 3 ;
    }else{
      GPIOB_PCOR = 1 << 3 ;
    }
    break ;
  case DigitalPort::D19 : // PTB2
    if (inValue) {
      GPIOB_PSOR = 1 << 2 ;
    }else{
      GPIOB_PCOR = 1 << 2 ;
    }
    break ;
  case DigitalPort::D20 : // PTD5
    if (inValue) {
      GPIOD_PSOR = 1 << 5 ;
    }else{
      GPIOD_PCOR = 1 << 5 ;
    }
    break ;
  case DigitalPort::D21 : // PTD6
    if (inValue) {
      GPIOD_PSOR = 1 << 6 ;
    }else{
      GPIOD_PCOR = 1 << 6 ;
    }
    break ;
  case DigitalPort::D22 : // PTC1
    if (inValue) {
      GPIOC_PSOR = 1 << 1 ;
    }else{
      GPIOC_PCOR = 1 << 1 ;
    }
    break ;
  case DigitalPort::D23 : // PTC2
    if (inValue) {
      GPIOC_PSOR = 1 << 2 ;
    }else{
      GPIOC_PCOR = 1 << 2 ;
    }
    break ;
  case DigitalPort::D24 : // PTE26
    if (inValue) {
      GPIOE_PSOR = 1 << 26 ;
    }else{
      GPIOE_PCOR = 1 << 26 ;
    }
    break ;
  case DigitalPort::D25 : // PTA5
    if (inValue) {
      GPIOA_PSOR = 1 << 5 ;
    }else{
      GPIOA_PCOR = 1 << 5 ;
    }
    break ;
  case DigitalPort::D26 : // PTA14
    if (inValue) {
      GPIOA_PSOR = 1 << 14 ;
    }else{
      GPIOA_PCOR = 1 << 14 ;
    }
    break ;
  case DigitalPort::D27 : // PTA15
    if (inValue) {
      GPIOA_PSOR = 1 << 15 ;
    }else{
      GPIOA_PCOR = 1 << 15 ;
    }
    break ;
  case DigitalPort::D28 : // PTA16
    if (inValue) {
      GPIOA_PSOR = 1 << 16 ;
    }else{
      GPIOA_PCOR = 1 << 16 ;
    }
    break ;
  case DigitalPort::D29 : // PTB18
    if (inValue) {
      GPIOB_PSOR = 1 << 18 ;
    }else{
      GPIOB_PCOR = 1 << 18 ;
    }
    break ;
  case DigitalPort::D30 : // PTB19
    if (inValue) {
      GPIOB_PSOR = 1 << 19 ;
    }else{
      GPIOB_PCOR = 1 << 19 ;
    }
    break ;
  case DigitalPort::D31 : // PTB10
    if (inValue) {
      GPIOB_PSOR = 1 << 10 ;
    }else{
      GPIOB_PCOR = 1 << 10 ;
    }
    break ;
  case DigitalPort::D32 : // PTB11
    if (inValue) {
      GPIOB_PSOR = 1 << 11 ;
    }else{
      GPIOB_PCOR = 1 << 11 ;
    }
    break ;
  case DigitalPort::D33 : // PTE24
    if (inValue) {
      GPIOE_PSOR = 1 << 24 ;
    }else{
      GPIOE_PCOR = 1 << 24 ;
    }
    break ;
  case DigitalPort::D34 : // PTE25
    if (inValue) {
      GPIOE_PSOR = 1 << 25 ;
    }else{
      GPIOE_PCOR = 1 << 25 ;
    }
    break ;
  case DigitalPort::D35 : // PTC8
    if (inValue) {
      GPIOC_PSOR = 1 << 8 ;
    }else{
      GPIOC_PCOR = 1 << 8 ;
    }
    break ;
  case DigitalPort::D36 : // PTC9
    if (inValue) {
      GPIOC_PSOR = 1 << 9 ;
    }else{
      GPIOC_PCOR = 1 << 9 ;
    }
    break ;
  case DigitalPort::D37 : // PTC10
    if (inValue) {
      GPIOC_PSOR = 1 << 10 ;
    }else{
      GPIOC_PCOR = 1 << 10 ;
    }
    break ;
  case DigitalPort::D38 : // PTC11
    if (inValue) {
      GPIOC_PSOR = 1 << 11 ;
    }else{
      GPIOC_PCOR = 1 << 11 ;
    }
    break ;
  case DigitalPort::D39 : // PTA17
    if (inValue) {
      GPIOA_PSOR = 1 << 17 ;
    }else{
      GPIOA_PCOR = 1 << 17 ;
    }
    break ;
  case DigitalPort::D40 : // PTA28
    if (inValue) {
      GPIOA_PSOR = 1 << 28 ;
    }else{
      GPIOA_PCOR = 1 << 28 ;
    }
    break ;
  case DigitalPort::D41 : // PTA29
    if (inValue) {
      GPIOA_PSOR = 1 << 29 ;
    }else{
      GPIOA_PCOR = 1 << 29 ;
    }
    break ;
  case DigitalPort::D42 : // PTA26
    if (inValue) {
      GPIOA_PSOR = 1 << 26 ;
    }else{
      GPIOA_PCOR = 1 << 26 ;
    }
    break ;
  case DigitalPort::D43 : // PTB20
    if (inValue) {
      GPIOB_PSOR = 1 << 20 ;
    }else{
      GPIOB_PCOR = 1 << 20 ;
    }
    break ;
  case DigitalPort::D44 : // PTB22
    if (inValue) {
      GPIOB_PSOR = 1 << 22 ;
    }else{
      GPIOB_PCOR = 1 << 22 ;
    }
    break ;
  case DigitalPort::D45 : // PTB23
    if (inValue) {
      GPIOB_PSOR = 1 << 23 ;
    }else{
      GPIOB_PCOR = 1 << 23 ;
    }
    break ;
  case DigitalPort::D46 : // PTB21
    if (inValue) {
      GPIOB_PSOR = 1 << 21 ;
    }else{
      GPIOB_PCOR = 1 << 21 ;
    }
    break ;
  case DigitalPort::D47 : // PTD8
    if (inValue) {
      GPIOD_PSOR = 1 << 8 ;
    }else{
      GPIOD_PCOR = 1 << 8 ;
    }
    break ;
  case DigitalPort::D48 : // PTD9
    if (inValue) {
      GPIOD_PSOR = 1 << 9 ;
    }else{
      GPIOD_PCOR = 1 << 9 ;
    }
    break ;
  case DigitalPort::D49 : // PTB4
    if (inValue) {
      GPIOB_PSOR = 1 << 4 ;
    }else{
      GPIOB_PCOR = 1 << 4 ;
    }
    break ;
  case DigitalPort::D50 : // PTB5
    if (inValue) {
      GPIOB_PSOR = 1 << 5 ;
    }else{
      GPIOB_PCOR = 1 << 5 ;
    }
    break ;
  case DigitalPort::D51 : // PTD14
    if (inValue) {
      GPIOD_PSOR = 1 << 14 ;
    }else{
      GPIOD_PCOR = 1 << 14 ;
    }
    break ;
  case DigitalPort::D52 : // PTD13
    if (inValue) {
      GPIOD_PSOR = 1 << 13 ;
    }else{
      GPIOD_PCOR = 1 << 13 ;
    }
    break ;
  case DigitalPort::D53 : // PTD12
    if (inValue) {
      GPIOD_PSOR = 1 << 12 ;
    }else{
      GPIOD_PCOR = 1 << 12 ;
    }
    break ;
  case DigitalPort::D54 : // PTD15
    if (inValue) {
      GPIOD_PSOR = 1 << 15 ;
    }else{
      GPIOD_PCOR = 1 << 15 ;
    }
    break ;
  case DigitalPort::D55 : // PTD11
    if (inValue) {
      GPIOD_PSOR = 1 << 11 ;
    }else{
      GPIOD_PCOR = 1 << 11 ;
    }
    break ;
  case DigitalPort::D56 : // PTE10
    if (inValue) {
      GPIOE_PSOR = 1 << 10 ;
    }else{
      GPIOE_PCOR = 1 << 10 ;
    }
    break ;
  case DigitalPort::D57 : // PTE11
    if (inValue) {
      GPIOE_PSOR = 1 << 11 ;
    }else{
      GPIOE_PCOR = 1 << 11 ;
    }
    break ;
  case DigitalPort::True : // No port
  case DigitalPort::False : // No port
    break ;
  }
}

//-----------------------------------------------------------------------------

bool digitalRead (const DigitalPort inPort) {
  bool result = false ;
  switch (inPort) {
  case DigitalPort::D0 : // PTB16
    result = (GPIOB_PDIR & (1 << 16)) != 0 ;
    break ;
  case DigitalPort::D1 : // PTB17
    result = (GPIOB_PDIR & (1 << 17)) != 0 ;
    break ;
  case DigitalPort::D2 : // PTD0
    result = (GPIOD_PDIR & (1 << 0)) != 0 ;
    break ;
  case DigitalPort::D3 : // PTA12
    result = (GPIOA_PDIR & (1 << 12)) != 0 ;
    break ;
  case DigitalPort::D4 : // PTA13
    result = (GPIOA_PDIR & (1 << 13)) != 0 ;
    break ;
  case DigitalPort::D5 : // PTD7
    result = (GPIOD_PDIR & (1 << 7)) != 0 ;
    break ;
  case DigitalPort::D6 : // PTD4
    result = (GPIOD_PDIR & (1 << 4)) != 0 ;
    break ;
  case DigitalPort::D7 : // PTD2
    result = (GPIOD_PDIR & (1 << 2)) != 0 ;
    break ;
  case DigitalPort::D8 : // PTD3
    result = (GPIOD_PDIR & (1 << 3)) != 0 ;
    break ;
  case DigitalPort::D9  : // PTC3
    result = (GPIOC_PDIR & (1 << 3)) != 0 ;
    break ;
  case DigitalPort::D10 : // PTC4
    result = (GPIOC_PDIR & (1 << 4)) != 0 ;
    break ;
  case DigitalPort::D11 : // PTC6
    result = (GPIOC_PDIR & (1 << 6)) != 0 ;
    break ;
  case DigitalPort::D12 : // PTC7
    result = (GPIOC_PDIR & (1 << 7)) != 0 ;
    break ;
  case DigitalPort::D13 : // PTC5
    result = (GPIOC_PDIR & (1 << 5)) != 0 ;
    break ;
  case DigitalPort::D14 : // PTD1
    result = (GPIOD_PDIR & (1 << 1)) != 0 ;
    break ;
  case DigitalPort::D15 : // PTC0
    result = (GPIOC_PDIR & (1 << 0)) != 0 ;
    break ;
  case DigitalPort::D16 : // PTB0
    result = (GPIOB_PDIR & (1 << 0)) != 0 ;
    break ;
  case DigitalPort::D17 : // PTB1
    result = (GPIOB_PDIR & (1 << 1)) != 0 ;
    break ;
  case DigitalPort::D18 : // PTB3
    result = (GPIOB_PDIR & (1 << 3)) != 0 ;
    break ;
  case DigitalPort::D19 : // PTB2
    result = (GPIOB_PDIR & (1 << 2)) != 0 ;
    break ;
  case DigitalPort::D20 : // PTD5
    result = (GPIOD_PDIR & (1 << 5)) != 0 ;
    break ;
  case DigitalPort::D21 : // PTD6
    result = (GPIOD_PDIR & (1 << 6)) != 0 ;
    break ;
  case DigitalPort::D22 : // PTC1
    result = (GPIOC_PDIR & (1 << 1)) != 0 ;
    break ;
  case DigitalPort::D23 : // PTC2
    result = (GPIOC_PDIR & (1 << 2)) != 0 ;
    break ;
  case DigitalPort::D24 : // PTE26
    result = (GPIOE_PDIR & (1 << 26)) != 0 ;
    break ;
  case DigitalPort::D25 : // PTA5
    result = (GPIOA_PDIR & (1 << 5)) != 0 ;
    break ;
  case DigitalPort::D26 : // PTA14
    result = (GPIOA_PDIR & (1 << 14)) != 0 ;
    break ;
  case DigitalPort::D27 : // PTA15
    result = (GPIOA_PDIR & (1 << 15)) != 0 ;
    break ;
  case DigitalPort::D28 : // PTA16
    result = (GPIOA_PDIR & (1 << 16)) != 0 ;
    break ;
  case DigitalPort::D29 : // PTB18
    result = (GPIOB_PDIR & (1 << 18)) != 0 ;
    break ;
  case DigitalPort::D30 : // PTB19
    result = (GPIOB_PDIR & (1 << 19)) != 0 ;
    break ;
  case DigitalPort::D31 : // PTB10
    result = (GPIOB_PDIR & (1 << 10)) != 0 ;
    break ;
  case DigitalPort::D32 : // PTB11
    result = (GPIOB_PDIR & (1 << 11)) != 0 ;
    break ;
  case DigitalPort::D33 : // PTE24
    result = (GPIOE_PDIR & (1 << 24)) != 0 ;
    break ;
  case DigitalPort::D34 : // PTE25
    result = (GPIOE_PDIR & (1 << 25)) != 0 ;
    break ;
  case DigitalPort::D35 : // PTC8
    result = (GPIOC_PDIR & (1 << 8)) != 0 ;
    break ;
  case DigitalPort::D36 : // PTC9
    result = (GPIOC_PDIR & (1 << 9)) != 0 ;
    break ;
  case DigitalPort::D37 : // PTC10
    result = (GPIOC_PDIR & (1 << 10)) != 0 ;
    break ;
  case DigitalPort::D38 : // PTC11
    result = (GPIOC_PDIR & (1 << 11)) != 0 ;
    break ;
  case DigitalPort::D39 : // PTA17
    result = (GPIOA_PDIR & (1 << 17)) != 0 ;
    break ;
  case DigitalPort::D40 : // PTA28
    result = (GPIOA_PDIR & (1 << 28)) != 0 ;
    break ;
  case DigitalPort::D41 : // PTA29
    result = (GPIOA_PDIR & (1 << 29)) != 0 ;
    break ;
  case DigitalPort::D42 : // PTA26
    result = (GPIOA_PDIR & (1 << 26)) != 0 ;
    break ;
  case DigitalPort::D43 : // PTB20
    result = (GPIOB_PDIR & (1 << 20)) != 0 ;
    break ;
  case DigitalPort::D44 : // PTB22
    result = (GPIOB_PDIR & (1 << 22)) != 0 ;
    break ;
  case DigitalPort::D45 : // PTB23
    result = (GPIOB_PDIR & (1 << 23)) != 0 ;
    break ;
  case DigitalPort::D46 : // PTB21
    result = (GPIOB_PDIR & (1 << 21)) != 0 ;
    break ;
  case DigitalPort::D47 : // PTD8
    result = (GPIOD_PDIR & (1 << 8)) != 0 ;
    break ;
  case DigitalPort::D48 : // PTD9
    result = (GPIOD_PDIR & (1 << 9)) != 0 ;
    break ;
  case DigitalPort::D49 : // PTB4
    result = (GPIOB_PDIR & (1 << 4)) != 0 ;
    break ;
  case DigitalPort::D50 : // PTB5
    result = (GPIOB_PDIR & (1 << 5)) != 0 ;
    break ;
  case DigitalPort::D51 : // PTD14
    result = (GPIOD_PDIR & (1 << 14)) != 0 ;
    break ;
  case DigitalPort::D52 : // PTD13
    result = (GPIOD_PDIR & (1 << 13)) != 0 ;
    break ;
  case DigitalPort::D53 : // PTD12
    result = (GPIOD_PDIR & (1 << 12)) != 0 ;
    break ;
  case DigitalPort::D54 : // PTD15
    result = (GPIOD_PDIR & (1 << 15)) != 0 ;
    break ;
  case DigitalPort::D55 : // PTD11
    result = (GPIOD_PDIR & (1 << 11)) != 0 ;
    break ;
  case DigitalPort::D56 : // PTE10
    result = (GPIOE_PDIR & (1 << 10)) != 0 ;
    break ;
  case DigitalPort::D57 : // PTE11
    result = (GPIOE_PDIR & (1 << 11)) != 0 ;
    break ;
  case DigitalPort::False : // No port, returns always false
    break ;
  case DigitalPort::True : // No port, returns always true
    result = true ;
    break ;
  }
  return result ;
}

//-----------------------------------------------------------------------------

void digitalToggle (const DigitalPort inPort) {
  switch (inPort) {
  case DigitalPort::D0 : // PTB16
    GPIOB_PTOR = 1 << 16 ;
    break ;
  case DigitalPort::D1 : // PTB17
    GPIOB_PTOR = 1 << 17 ;
    break ;
  case DigitalPort::D2 : // PTD0
    GPIOD_PTOR = 1 << 0 ;
    break ;
  case DigitalPort::D3 : // PTA12
    GPIOA_PTOR = 1 << 12 ;
    break ;
  case DigitalPort::D4 : // PTA13
    GPIOA_PTOR = 1 << 13 ;
    break ;
  case DigitalPort::D5 : // PTD7
    GPIOD_PTOR = 1 << 7 ;
    break ;
  case DigitalPort::D6 : // PTD4
    GPIOD_PTOR = 1 << 4 ;
    break ;
  case DigitalPort::D7 : // PTD2
    GPIOD_PTOR = 1 << 2 ;
    break ;
  case DigitalPort::D8 : // PTD3
    GPIOD_PTOR = 1 << 3 ;
    break ;
  case DigitalPort::D9  : // PTC3
    GPIOC_PTOR = 1 << 3 ;
    break ;
  case DigitalPort::D10 : // PTC4
    GPIOC_PTOR = 1 << 4 ;
    break ;
  case DigitalPort::D11 : // PTC6
    GPIOC_PTOR = 1 << 6 ;
    break ;
  case DigitalPort::D12 : // PTC7
    GPIOC_PTOR = 1 << 7 ;
    break ;
  case DigitalPort::D13 : // PTC5
    GPIOC_PTOR = 1 << 5 ;
    break ;
  case DigitalPort::D14 : // PTD1
    GPIOD_PTOR = 1 << 1 ;
    break ;
  case DigitalPort::D15 : // PTC0
    GPIOC_PTOR = 1 << 0 ;
    break ;
  case DigitalPort::D16 : // PTB0
    GPIOB_PTOR = 1 << 0 ;
    break ;
  case DigitalPort::D17 : // PTB1
    GPIOB_PTOR = 1 << 1 ;
    break ;
  case DigitalPort::D18 : // PTB3
    GPIOB_PTOR = 1 << 3 ;
    break ;
  case DigitalPort::D19 : // PTB2
    GPIOB_PTOR = 1 << 2 ;
    break ;
  case DigitalPort::D20 : // PTD5
    GPIOD_PTOR = 1 << 5 ;
    break ;
  case DigitalPort::D21 : // PTD6
    GPIOD_PTOR = 1 << 6 ;
    break ;
  case DigitalPort::D22 : // PTC1
    GPIOC_PTOR = 1 << 1 ;
    break ;
  case DigitalPort::D23 : // PTC2
    GPIOC_PTOR = 1 << 2 ;
    break ;
  case DigitalPort::D24 : // PTE26
    GPIOE_PTOR = 1 << 26 ;
    break ;
  case DigitalPort::D25 : // PTA5
    GPIOA_PTOR = 1 << 5 ;
    break ;
  case DigitalPort::D26 : // PTA14
    GPIOA_PTOR = 1 << 14 ;
    break ;
  case DigitalPort::D27 : // PTA15
    GPIOA_PTOR = 1 << 15 ;
    break ;
  case DigitalPort::D28 : // PTA16
    GPIOA_PTOR = 1 << 16 ;
    break ;
  case DigitalPort::D29 : // PTB18
    GPIOB_PTOR = 1 << 18 ;
    break ;
  case DigitalPort::D30 : // PTB19
    GPIOB_PTOR = 1 << 19 ;
    break ;
  case DigitalPort::D31 : // PTB10
    GPIOB_PTOR = 1 << 10 ;
    break ;
  case DigitalPort::D32 : // PTB11
    GPIOB_PTOR = 1 << 11 ;
    break ;
  case DigitalPort::D33 : // PTE24
    GPIOE_PTOR = 1 << 24 ;
    break ;
  case DigitalPort::D34 : // PTE25
    GPIOE_PTOR = 1 << 25 ;
    break ;
  case DigitalPort::D35 : // PTC8
    GPIOC_PTOR = 1 << 8 ;
    break ;
  case DigitalPort::D36 : // PTC9
    GPIOC_PTOR = 1 << 9 ;
    break ;
  case DigitalPort::D37 : // PTC10
    GPIOC_PTOR = 1 << 10 ;
    break ;
  case DigitalPort::D38 : // PTC11
    GPIOC_PTOR = 1 << 11 ;
    break ;
  case DigitalPort::D39 : // PTA17
    GPIOA_PTOR = 1 << 17 ;
    break ;
  case DigitalPort::D40 : // PTA28
    GPIOA_PTOR = 1 << 28 ;
    break ;
  case DigitalPort::D41 : // PTA29
    GPIOA_PTOR = 1 << 29 ;
    break ;
  case DigitalPort::D42 : // PTA26
    GPIOA_PTOR = 1 << 26 ;
    break ;
  case DigitalPort::D43 : // PTB20
    GPIOB_PTOR = 1 << 20 ;
    break ;
  case DigitalPort::D44 : // PTB22
    GPIOB_PTOR = 1 << 22 ;
    break ;
  case DigitalPort::D45 : // PTB23
    GPIOB_PTOR = 1 << 23 ;
    break ;
  case DigitalPort::D46 : // PTB21
    GPIOB_PTOR = 1 << 21 ;
    break ;
  case DigitalPort::D47 : // PTD8
    GPIOD_PTOR = 1 << 8 ;
    break ;
  case DigitalPort::D48 : // PTD9
    GPIOD_PTOR = 1 << 9 ;
    break ;
  case DigitalPort::D49 : // PTB4
    GPIOB_PTOR = 1 << 4 ;
    break ;
  case DigitalPort::D50 : // PTB5
    GPIOB_PTOR = 1 << 5 ;
    break ;
  case DigitalPort::D51 : // PTD14
    GPIOD_PTOR = 1 << 14 ;
    break ;
  case DigitalPort::D52 : // PTD13
    GPIOD_PTOR = 1 << 13 ;
    break ;
  case DigitalPort::D53 : // PTD12
    GPIOD_PTOR = 1 << 12 ;
    break ;
  case DigitalPort::D54 : // PTD15
    GPIOD_PTOR = 1 << 15 ;
    break ;
  case DigitalPort::D55 : // PTD11
    GPIOD_PTOR = 1 << 11 ;
    break ;
  case DigitalPort::D56 : // PTE10
    GPIOE_PTOR = 1 << 10 ;
    break ;
  case DigitalPort::D57 : // PTE11
    GPIOE_PTOR = 1 << 11 ;
    break ;
  case DigitalPort::False : // No port, no effect
  case DigitalPort::True : // No port, no effect
    break ;
  }
}

//-----------------------------------------------------------------------------
