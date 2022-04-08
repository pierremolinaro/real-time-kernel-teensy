#include "all-headers.h"

//-----------------------------------------------------------------------------
//   MICROCONTROLLER SERIAL NUMBER
//-----------------------------------------------------------------------------

static uint32_t gMicrocontrollerSerialNumber ;
static uint32_t readMicrocontrollerSerialNumber (void) ;

//-----------------------------------------------------------------------------
// CLOCK SETTINGS
//-----------------------------------------------------------------------------
// The MCGCLOCKOUT frequency is given by (the 16 MHz quartz frequency is divided by 2 for the PPL)
//  MCGCLOCKOUT = 16 MHz / 2 * (MCG:C6:VDIV + 16) / (MCG:C5:PRDIV + 1)
//
//-----------------------------------------------------------------------------
// CPU CLOCK
//-----------------------------------------------------------------------------
//  The CPU Clock is given by: MCGCLOCKOUT / (SIM:CLKDIV1:OUTDIV1 + 1)
//
//  Here, CPU_MHZ is a given constant, so we only check that settings are correct by asserting:
//     CPU_MHZ * (MCG:C5:PRDIV + 1) * (SIM:CLKDIV1:OUTDIV1 + 1) = (16 MHz / 2) * (MCG:C6:VDIV + 16)
//
//-----------------------------------------------------------------------------
// BUS (peripheral) CLOCK
//-----------------------------------------------------------------------------
//  The peripheral Clock is given by: MCGCLOCKOUT / (SIM:CLKDIV1:OUTDIV2 + 1)
//
//  Here, SIM:CLKDIV1:OUTDIV2 is a given constant, so we compute BUS_MHZ by:
//     BUS_MHZ = (16 MHz / 2) * (MCG:C6:VDIV + 16) / (MCG:C5:PRDIV + 1) / (SIM:CLKDIV1:OUTDIV2 + 1)
//
//-----------------------------------------------------------------------------
// Flexbus CLOCK
//-----------------------------------------------------------------------------
//  The Flexbus Clock is given by: MCGCLOCKOUT / (SIM:CLKDIV1:OUTDIV3 + 1)
//
//  Here, SIM:CLKDIV1:OUTDIV3 is a given constant, so we compute FLEXBUS_MHZ by:
//     FLEXBUS_MHZ = (16 MHz / 2) * (MCG:C6:VDIV + 16) /(MCG:C5:PRDIV + 1) / (SIM:CLKDIV1:OUTDIV3 + 1)
//
//-----------------------------------------------------------------------------
// Flash CLOCK
//-----------------------------------------------------------------------------
//  The FLASH Clock is given by: MCGCLOCKOUT / (SIM:CLKDIV1:OUTDIV3 + 1)
//
//  Here, SIM:CLKDIV1:OUTDIV4 is a given constant, so we compute Flash Clock in kHz (result may not be integer):
//     FLASH_KHZ = (16000 kHz / 2) * (MCG:C6:VDIV + 16) / (MCG:C5:PRDIV + 1) / (SIM:CLKDIV1:OUTDIV4 + 1)
//
//-----------------------------------------------------------------------------
// MICRO CONTROLLER REQUIREMENTS
//-----------------------------------------------------------------------------
// The clock dividers are programmed via the SIM module’s CLKDIV registers. Each divider is programmable from a
// divide-by-1 through divide-by-16 setting. The following requirements must be met when configuring the clocks
// for this device:
// 1. The core and system clock frequencies must be 180 MHz or slower in HSRUN, 120 MHz or slower in RUN.
// 2. The bus clock frequency must be programmed to 60 MHz or less in HSRUN or RUN, and an integer divide of the
//      core clock. The core clock to bus clock ratio is limited to a max value of 8.
// 3. The flash clock frequency must be programmed to 28 MHz or less, less than or equal to the bus clock, and an
//      integer divide of the core clock. The core clock to flash clock ratio is limited to a max value of 8.
// 4. The FlexBus clock frequency must be programmed to be less than or equal to the bus clock frequency. The
//      FlexBus also has pad interface restrictions that limits the maximum frequency. For this device the FlexBus
//      maximum frequency is 60 MHz. The core clock to FlexBus clock ratio is limited to a max value of 8.
// 5. Since SDRAMC and FlexBus both use CLKOUT, the same restrictions apply to the SDRAM controller as stated
//      for the FlexBus clock.
//-----------------------------------------------------------------------------
// SETTING SUMMARY
//-----------------------------------------------------------------------------
// F_CPU   MCG_C5   MCG_C6   SIM_CLKDIV1   SIM_CLKDIV1   SIM_CLKDIV1   SIM_CLKDIV1   BUS_MHZ   FLEXBUS    FLASH
// _MHZ    _PRDIV    _VDIV      _OUTDIV1      _OUTDIV2      _OUTDIV3      _OUTDIV4                _MHZ     _KHZ
//  240         0       14             0             3             0             7       60        240   30 000
//  216         0       11             0             1             0             7       54        216   27 000
//  192         0        8             0             1             0             6       28        192   27 428
//  180         1       29             0             1             0             6       60        180   25 714
//  168         0        5             0             2             0             5       56        168   28 000
//  144         0        2             0             1             0             4       28        144   28 800
//  120         1       14             0             1             0             4       60        120   24 000
//   96         1        8             0             1             0             2       24         96   24 000
//   72         1        2             0             0             0             2       36         72   24 000
//   48         1        8             1             1             1             3       48         48   24 000
//   24         1        8             3             3             3             3       24         24   24 000
//-----------------------------------------------------------------------------
// PRDIV SETTINGS
//-----------------------------------------------------------------------------

#ifndef CPU_MHZ
  #error "CPU_MHZ is not defined"
  static const uint32_t K_MCG_C5_PRDIV = 0 ;
#elif CPU_MHZ == 240
  static const uint32_t K_MCG_C5_PRDIV = 0 ;
#elif CPU_MHZ == 216
  static const uint32_t K_MCG_C5_PRDIV = 0 ;
#elif CPU_MHZ == 192
  static const uint32_t K_MCG_C5_PRDIV = 0 ;
#elif CPU_MHZ == 180
  static const uint32_t K_MCG_C5_PRDIV = 1 ;
#elif CPU_MHZ == 168
  static const uint32_t K_MCG_C5_PRDIV = 0 ;
#elif CPU_MHZ == 144
  static const uint32_t K_MCG_C5_PRDIV = 0 ;
#elif CPU_MHZ == 120
  static const uint32_t K_MCG_C5_PRDIV = 1 ;
#elif CPU_MHZ == 96
  static const uint32_t K_MCG_C5_PRDIV = 1 ;
#elif CPU_MHZ == 72
  static const uint32_t K_MCG_C5_PRDIV = 1 ;
#elif CPU_MHZ == 48
  static const uint32_t K_MCG_C5_PRDIV = 1 ;
#elif CPU_MHZ == 24
  static const uint32_t K_MCG_C5_PRDIV = 1 ;
#else
  #error "CPU_MHZ has an invalid value"
  static const uint32_t K_MCG_C5_PRDIV = 0 ;
#endif

//-----------------------------------------------------------------------------
// MCG:C6:VDIV SETTINGS
//-----------------------------------------------------------------------------

#ifndef CPU_MHZ
  #error "CPU_MHZ is not defined"
  static const uint32_t K_MCG_C6_VDIV = 0 ;
#elif CPU_MHZ == 240
  static const uint32_t K_MCG_C6_VDIV = 14 ;
#elif CPU_MHZ == 216
  static const uint32_t K_MCG_C6_VDIV = 11 ;
#elif CPU_MHZ == 192
  static const uint32_t K_MCG_C6_VDIV = 8 ;
#elif CPU_MHZ == 180
  static const uint32_t K_MCG_C6_VDIV = 29 ;
#elif CPU_MHZ == 168
  static const uint32_t K_MCG_C6_VDIV = 5 ;
#elif CPU_MHZ == 144
  static const uint32_t K_MCG_C6_VDIV = 2 ;
#elif CPU_MHZ == 120
  static const uint32_t K_MCG_C6_VDIV = 14 ;
#elif CPU_MHZ == 96
  static const uint32_t K_MCG_C6_VDIV = 8 ;
#elif CPU_MHZ == 72
  static const uint32_t K_MCG_C6_VDIV = 2 ;
#elif CPU_MHZ == 48
  static const uint32_t K_MCG_C6_VDIV = 8 ;
#elif CPU_MHZ == 24
  static const uint32_t K_MCG_C6_VDIV = 8 ;
#else
  #error "CPU_MHZ has an invalid value"
  static const uint32_t K_MCG_C6_VDIV = 0 ;
#endif

//-----------------------------------------------------------------------------
// SIM:CLKDIV1:OUTDIV1 SETTINGS
//-----------------------------------------------------------------------------

#ifndef CPU_MHZ
  #error "CPU_MHZ is not defined"
  static const uint32_t K_SIM_CLKDIV1_OUTDIV1 = 0 ;
#elif CPU_MHZ == 48
  static const uint32_t K_SIM_CLKDIV1_OUTDIV1 = 1 ;
#elif CPU_MHZ == 24
  static const uint32_t K_SIM_CLKDIV1_OUTDIV1 = 3 ;
#else
  static const uint32_t K_SIM_CLKDIV1_OUTDIV1 = 0 ; // 0 for all other settings
#endif

//-----------------------------------------------------------------------------
// SIM:CLKDIV1:OUTDIV2 SETTINGS (divisor for bus)
//-----------------------------------------------------------------------------

#ifndef CPU_MHZ
  #error "CPU_MHZ is not defined"
  static const uint32_t K_SIM_CLKDIV1_OUTDIV2 = 0 ;
#elif CPU_MHZ == 240
  static const uint32_t K_SIM_CLKDIV1_OUTDIV2 = 3 ;
#elif CPU_MHZ == 216
  static const uint32_t K_SIM_CLKDIV1_OUTDIV2 = 3 ;
#elif CPU_MHZ == 192
  static const uint32_t K_SIM_CLKDIV1_OUTDIV2 = 3 ;
#elif CPU_MHZ == 180
  static const uint32_t K_SIM_CLKDIV1_OUTDIV2 = 2 ;
#elif CPU_MHZ == 168
  static const uint32_t K_SIM_CLKDIV1_OUTDIV2 = 2 ;
#elif CPU_MHZ == 144
  static const uint32_t K_SIM_CLKDIV1_OUTDIV2 = 2 ;
#elif CPU_MHZ == 120
  static const uint32_t K_SIM_CLKDIV1_OUTDIV2 = 1 ;
#elif CPU_MHZ == 96
  static const uint32_t K_SIM_CLKDIV1_OUTDIV2 = 1 ;
#elif CPU_MHZ == 72
  static const uint32_t K_SIM_CLKDIV1_OUTDIV2 = 1 ;
#elif CPU_MHZ == 48
  static const uint32_t K_SIM_CLKDIV1_OUTDIV2 = 1 ;
#elif CPU_MHZ == 24
  static const uint32_t K_SIM_CLKDIV1_OUTDIV2 = 3 ;
#else
  #error "CPU_MHZ has an invalid value"
  static const uint32_t K_SIM_CLKDIV1_OUTDIV2 = 0 ;
#endif

//-----------------------------------------------------------------------------
// BUS_MHZ
//-----------------------------------------------------------------------------

static const uint32_t BUS_MHZ = (16 / 2) * (K_MCG_C6_VDIV + 16) /(K_MCG_C5_PRDIV + 1) / (K_SIM_CLKDIV1_OUTDIV2 + 1) ;

//······················································································································

uint32_t busMHZ (void) {
  return BUS_MHZ ;
}

//-----------------------------------------------------------------------------
// SIM:CLKDIV1:OUTDIV3 SETTINGS (divisor for Flexbus)
//-----------------------------------------------------------------------------

#ifndef CPU_MHZ
  #error "CPU_MHZ is not defined"
  static const uint32_t K_SIM_CLKDIV1_OUTDIV3 = 0 ;
#elif CPU_MHZ == 48
  static const uint32_t K_SIM_CLKDIV1_OUTDIV3 = 1 ;
#elif CPU_MHZ == 24
  static const uint32_t K_SIM_CLKDIV1_OUTDIV3 = 3 ;
#else
  static const uint32_t K_SIM_CLKDIV1_OUTDIV3 = 0 ; // 0 for all other settings
#endif

//-----------------------------------------------------------------------------
// FLEXBUS_MHZ
//-----------------------------------------------------------------------------

static const uint32_t FLEXBUS_MHZ = (16 / 2) * (K_MCG_C6_VDIV + 16) /(K_MCG_C5_PRDIV + 1) / (K_SIM_CLKDIV1_OUTDIV3 + 1) ;

//······················································································································

uint32_t FlexBusMHZ (void) {
  return FLEXBUS_MHZ ;
}

//-----------------------------------------------------------------------------
// SIM:CLKDIV1:OUTDIV4 SETTINGS (divisor for Flash)
//-----------------------------------------------------------------------------

#ifndef CPU_MHZ
  #error "CPU_MHZ is not defined"
  static const uint32_t K_SIM_CLKDIV1_OUTDIV4 = 0 ;
#elif CPU_MHZ == 240
  static const uint32_t K_SIM_CLKDIV1_OUTDIV4 = 7 ;
#elif CPU_MHZ == 216
  static const uint32_t K_SIM_CLKDIV1_OUTDIV4 = 7 ;
#elif CPU_MHZ == 192
  static const uint32_t K_SIM_CLKDIV1_OUTDIV4 = 6 ;
#elif CPU_MHZ == 180
  static const uint32_t K_SIM_CLKDIV1_OUTDIV4 = 6 ;
#elif CPU_MHZ == 168
  static const uint32_t K_SIM_CLKDIV1_OUTDIV4 = 5 ;
#elif CPU_MHZ == 144
  static const uint32_t K_SIM_CLKDIV1_OUTDIV4 = 4 ;
#elif CPU_MHZ == 120
  static const uint32_t K_SIM_CLKDIV1_OUTDIV4 = 4 ;
#elif CPU_MHZ == 96
  static const uint32_t K_SIM_CLKDIV1_OUTDIV4 = 3 ;
#elif CPU_MHZ == 72
  static const uint32_t K_SIM_CLKDIV1_OUTDIV4 = 2 ;
#elif CPU_MHZ == 48
  static const uint32_t K_SIM_CLKDIV1_OUTDIV4 = 3 ;
#elif CPU_MHZ == 24
  static const uint32_t K_SIM_CLKDIV1_OUTDIV4 = 3 ;
#else
  #error "CPU_MHZ has an invalid value"
  static const uint32_t K_SIM_CLKDIV1_OUTDIV4 = 0 ;
#endif

//-----------------------------------------------------------------------------
// FLASH CLOCK (in kHz)
//-----------------------------------------------------------------------------

static const uint32_t FLASH_KHZ = (16000 / 2) * (K_MCG_C6_VDIV + 16) / (K_MCG_C5_PRDIV + 1) / (K_SIM_CLKDIV1_OUTDIV4 + 1) ;

//······················································································································

uint32_t FlashKHz (void) {
  return FLASH_KHZ ;
}

//-----------------------------------------------------------------------------
// USB CLOCK
//-----------------------------------------------------------------------------
// The USB module SHOULD be driven by a 48 MHz clock.
//
// For all CPU frequencies (but 216 MHz and 180 MHz), this clock is derived from MCGPLLCLK; the MCGPLLCLK is
// identical to MCGCLOCKOUT (as SIM_CLKDIV2_PLL_FLL_SEL=1). So:
//   USB_CLOCK = MCGCLOCKOUT * (K_SIM_CLKDIV2_USBFRAC + 1) / (K_SIM_CLKDIV2_USBDIV + 1)
// We check :
//   48 MHz == 16 MHz / 2 * (MCG:C6:VDIV + 16) / (MCG:C5:PRDIV + 1) * (K_SIM_CLKDIV2_USBFRAC + 1) / (K_SIM_CLKDIV2_USBDIV + 1)
// So:
//   6 * (MCG:C5:PRDIV + 1) * (K_SIM_CLKDIV2_USBDIV + 1) == (MCG:C6:VDIV + 16) * (K_SIM_CLKDIV2_USBFRAC + 1)
//
// For 216 MHz and 180 MHz CPU frequencies, we use directly the built-in 48 MHz clock: SIM_CLKDIV2_PLL_FLL_SEL=3, with
// di divisor (K_SIM_CLKDIV2_USBFRAC=0 and K_SIM_CLKDIV2_USBDIV=0).
//-----------------------------------------------------------------------------
// USB SETTING SUMMARY
//-----------------------------------------------------------------------------
// F_CPU   SIM_CLKDIV2   SIM_CLKDIV2   SIM_SOPT2_
// _MHZ        _USBDIV      _USBFRAC    PLLFLLSEL
//  240              4             0            1
//  216              0             0            3
//  192              3             0            1
//  180              0             0            3
//  168              6             1            1
//  144              2             0            1
//  120              4             1            1
//   96              1             0            1
//   72              2             1            1
//   48              1             0            1
//   24              1             0            1
//-----------------------------------------------------------------------------
// SIM:SOPT2:PLLFLLSEL SETTINGS
//-----------------------------------------------------------------------------

#ifndef CPU_MHZ
  #error "CPU_MHZ is not defined"
  static const uint32_t K_SIM_SOPT2_PLLFLLSEL = 0 ;
#elif CPU_MHZ == 216
  static const uint32_t K_SIM_SOPT2_PLLFLLSEL = 3 ;
#elif CPU_MHZ == 180
  static const uint32_t K_SIM_SOPT2_PLLFLLSEL = 3 ;
#else
  static const uint32_t K_SIM_SOPT2_PLLFLLSEL = 1 ; // For all other settings
#endif

//-----------------------------------------------------------------------------
// SIM:CLKDIV2:USBFRAC SETTINGS
//-----------------------------------------------------------------------------

#ifndef CPU_MHZ
  #error "CPU_MHZ is not defined"
  static const uint32_t K_SIM_CLKDIV2_USBFRAC = 0 ;
#elif CPU_MHZ == 168
  static const uint32_t K_SIM_CLKDIV2_USBFRAC = 1 ;
#elif CPU_MHZ == 120
  static const uint32_t K_SIM_CLKDIV2_USBFRAC = 1 ;
#elif CPU_MHZ == 72
  static const uint32_t K_SIM_CLKDIV2_USBFRAC = 1 ;
#else
  static const uint32_t K_SIM_CLKDIV2_USBFRAC = 0 ; // For all other settings
#endif

//-----------------------------------------------------------------------------
// SIM:CLKDIV2:USBDIV SETTINGS
//-----------------------------------------------------------------------------

#ifndef CPU_MHZ
  #error "CPU_MHZ is not defined"
  static const uint32_t K_SIM_CLKDIV2_USBDIV = 0 ;
#elif CPU_MHZ == 240
  static const uint32_t K_SIM_CLKDIV2_USBDIV = 4 ;
#elif CPU_MHZ == 216
  static const uint32_t K_SIM_CLKDIV2_USBDIV = 0 ;
#elif CPU_MHZ == 192
  static const uint32_t K_SIM_CLKDIV2_USBDIV = 3 ;
#elif CPU_MHZ == 180
  static const uint32_t K_SIM_CLKDIV2_USBDIV = 0 ;
#elif CPU_MHZ == 168
  static const uint32_t K_SIM_CLKDIV2_USBDIV = 6 ;
#elif CPU_MHZ == 144
  static const uint32_t K_SIM_CLKDIV2_USBDIV = 2 ;
#elif CPU_MHZ == 120
  static const uint32_t K_SIM_CLKDIV2_USBDIV = 4 ;
#elif CPU_MHZ == 96
  static const uint32_t K_SIM_CLKDIV2_USBDIV = 1 ;
#elif CPU_MHZ == 72
  static const uint32_t K_SIM_CLKDIV2_USBDIV = 2 ;
#elif CPU_MHZ == 48
  static const uint32_t K_SIM_CLKDIV2_USBDIV = 1 ;
#elif CPU_MHZ == 24
  static const uint32_t K_SIM_CLKDIV2_USBDIV = 1 ;
#else
  #error "CPU_MHZ has an invalid value"
  static const uint32_t K_SIM_CLKDIV2_USBDIV = 0 ;
#endif

//-----------------------------------------------------------------------------
//  BOOT ROUTINE
//-----------------------------------------------------------------------------

void startPhase1 (void) {
//--------------------------------------------------- Disable watchdog timer
//--- These two instructions are required for unlocking watchdog timer
  WDOG_UNLOCK = 0xC520 ;
  WDOG_UNLOCK = 0xD928 ;
//--- Disable watchdog timer
  WDOG_STCTRLH = 0 ;
//--------------------------------------------------- Enable clocks to always-used peripherals
  SIM_SCGC3 = SIM_SCGC3_ADC1 | SIM_SCGC3_FTM2 | SIM_SCGC3_FTM3 ;
  SIM_SCGC5 = SIM_SCGC5_PORTA | SIM_SCGC5_PORTB | SIM_SCGC5_PORTC | SIM_SCGC5_PORTD | SIM_SCGC5_PORTE ;    // clocks active to all GPIO
  SIM_SCGC6 = SIM_SCGC6_RTC | SIM_SCGC6_FTM0 | SIM_SCGC6_FTM1 | SIM_SCGC6_ADC0 | SIM_SCGC6_FTF ;
//  SCB_CPACR = 0x00F0_0000; // Enable floating point unit
  LMEM_PCCCR = LMEM_PCCCR_GO | LMEM_PCCCR_INVW1 | LMEM_PCCCR_INVW0 | LMEM_PCCCR_ENWRBUF | LMEM_PCCCR_ENCACHE ;
//--- If the RTC oscillator isn't enabled, get it started early
  if ((RTC_CR & RTC_CR_OSCE) != 0) {
    RTC_SR = 0;
    RTC_CR = RTC_CR_SC16P | RTC_CR_SC4P | RTC_CR_OSCE;
  }
//--- Release I/O pins hold, if we woke up from VLLS mode
  if (PMC_REGSC & PMC_REGSC_ACKISO) {
    PMC_REGSC |= PMC_REGSC_ACKISO;
  }
//---------------------------------------------------
//--- Since this is a write once register, make it visible to all F_CPU's
//    so we can into other sleep modes in the future at any speed
  SMC_PMPROT = SMC_PMPROT_AHSRUN | SMC_PMPROT_AVLP | SMC_PMPROT_ALLS | SMC_PMPROT_AVLLS;
//--------------------------------------------------- PLL initialization (start in FEI mode)
//--- Enable capacitors for crystal
  OSC_CR = OSC_CR_SC8P | OSC_CR_SC2P | OSC_CR_ERCLKEN;
//--- Enable osc, 8-32 MHz range, low power mode
  MCG_C2 = MCG_C2_RANGE (2) | MCG_C2_EREFS;
//--- Switch to crystal as clock source, FLL input = 16 MHz / 512
  MCG_C1 =  MCG_C1_CLKS(2) | MCG_C1_FRDIV(4);
//--- Wait for crystal oscillator to begin
  while ((MCG_S & MCG_S_OSCINIT0) == 0) {}
//--- Wait for FLL to use oscillator
  while ((MCG_S & MCG_S_IREFST) != 0) {}
//--- Wait for MCGOUT to use oscillator
  while ((MCG_S & MCG_S_CLKST (3)) != MCG_S_CLKST(2)) {}
//--- Now we're in FBE mode
//------------------------------------ Read microcontroller serial number
//   This SHOULD be done in normal mode (not in HSRUN mode)
//   We cannot store result in RAM, BSS section will be cleared (see below)
  const uint32_t serialNumber = readMicrocontrollerSerialNumber () ;
//------------------------------------ Turn on the PLL
  SMC_PMCTRL = SMC_PMCTRL_RUNM (3); // enter HSRUN mode
  while (SMC_PMSTAT != SMC_PMPROT_AHSRUN) {} // wait for HSRUN
//--- Configure CPU clock
  MCG_C5 = K_MCG_C5_PRDIV ;
  MCG_C6 = MCG_C6_PLLS | K_MCG_C6_VDIV ;
//--- Wait for PLL to start using xtal as its input
  while (!(MCG_S & MCG_S_PLLST)) {}
//--- Wait for PLL to lock
  while (!(MCG_S & MCG_S_LOCK0)) {}
//------------------------------------ Now we're in PBE mode: program the clock dividers
  SIM_CLKDIV1 =
    SIM_CLKDIV1_OUTDIV1(K_SIM_CLKDIV1_OUTDIV1)
  | SIM_CLKDIV1_OUTDIV2(K_SIM_CLKDIV1_OUTDIV2)
  | SIM_CLKDIV1_OUTDIV3(K_SIM_CLKDIV1_OUTDIV3)
  | SIM_CLKDIV1_OUTDIV4(K_SIM_CLKDIV1_OUTDIV4)
  ;
  SIM_CLKDIV2 =
    SIM_CLKDIV2_USBDIV (K_SIM_CLKDIV2_USBDIV)
  | K_SIM_CLKDIV2_USBFRAC
  ;
//--- Switch to PLL as clock source
  MCG_C1 = MCG_C1_CLKS(0) | MCG_C1_FRDIV(4);
//--- Wait for PLL clock to be used
  while ((MCG_S & MCG_S_CLKST (3)) != MCG_S_CLKST(3)) {}
//--- USB clock
  SIM_SOPT2 =
    SIM_SOPT2_USBSRC
  | (K_SIM_SOPT2_PLLFLLSEL << 16)
  | SIM_SOPT2_TRACECLKSEL
  ;
//------------------------------------ Clear '.bss' section
  extern uint32_t __bss_start ;
  extern const uint32_t __bss_end ;
  uint32_t * p = & __bss_start ;
  while (p != & __bss_end) {
    * p = 0 ;
    p ++ ;
  }
//------------------------------------ Copy .data section in RAM
  extern uint32_t __data_start ;
  extern const uint32_t __data_end ;
  extern uint32_t __data_load_start ;
  uint32_t * pSrc = & __data_load_start ;
  uint32_t * pDest = & __data_start ;
  while (pDest != & __data_end) {
    * pDest = * pSrc ;
    pDest ++ ;
    pSrc ++ ;
  }
//------------------------------------ Now, we can store serial number
  gMicrocontrollerSerialNumber = serialNumber ;
}

//-----------------------------------------------------------------------------
//   MICROCONTROLLER SERIAL NUMBER
//-----------------------------------------------------------------------------

static uint32_t readMicrocontrollerSerialNumber (void) {
  while ((FTFE_FSTAT & FTFE_FSTAT_CCIF) == 0) {} // Wait
  FTFE_FSTAT = FTFE_FSTAT_RDCOLERR | FTFE_FSTAT_ACCERR | FTFE_FSTAT_FPVIOL;
//--- FTFE_FCCOB3 is a 8-bit register, followed by 3 other 8-bit registers, we write value by a single 32-bit access)
  FTFE_FCCOB_0_3 = 0x41070000 ;
  FTFE_FSTAT = FTFE_FSTAT_CCIF ;
  while ((FTFE_FSTAT & FTFE_FSTAT_CCIF) == 0) {} // Wait
//--- Read serial number (FTFE_FCCOBB is a 8-bit register, followed by 3 other 8-bit registers, we get the serial number with a single 32-bit access)
  return FTFE_FCCOB_8_11 ;
}

//······················································································································

uint32_t microcontrollerSerialNumber (void) {
  return gMicrocontrollerSerialNumber ;
}

//-----------------------------------------------------------------------------

void startPhase2 (void) {
//------------------------------------ Aller exécuter les routines d'initialisation de la section boot.routine.array
  extern void (* __boot_routine_array_start) (void) ;
  extern void (* __boot_routine_array_end) (void) ;
  void (* * ptr) (void) = & __boot_routine_array_start ;
  while (ptr != & __boot_routine_array_end) {
    (* ptr) () ;
    ptr ++ ;
  }
//------------------------------------ Run C++ global variable constructors
  extern void (* __constructor_array_start) (void) ;
  extern void (* __constructor_array_end) (void) ;
  ptr = & __constructor_array_start ;
  while (ptr != & __constructor_array_end) {
    (* ptr) () ;
    ptr ++ ;
  }
//------------------------------------ Aller exécuter les routines d'initialisation de la section init.routine.array
  extern void (* __init_routine_array_start) (void) ;
  extern void (* __init_routine_array_end) (void) ;
  ptr = & __init_routine_array_start ;
  while (ptr != & __init_routine_array_end) {
    (* ptr) () ;
    ptr ++ ;
  }
}

//-----------------------------------------------------------------------------
