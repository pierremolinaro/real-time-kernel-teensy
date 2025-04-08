//--------------------------------------------------------------------------------------------------
//   INTERRUPT VECTORS
//--------------------------------------------------------------------------------------------------

	.syntax unified
	.cpu cortex-m4
	.thumb

//--------------------------------------------------------------------------------------------------

  .section isr.vectors, "a", %progbits

//--------------------------------------------------------------------------------------------------

  .word __system_stack_end
//--- ARM Core System Handler Vectors
  .word reset.handler @ 1
  .word interrupt.NMI @ 2
  .word interrupt.HardFault @ 3
  .word interrupt.MemManage @ 4
  .word interrupt.BusFault @ 5
  .word interrupt.UsageFault @ 6
  .word -1 @ 7, reserved
  .word -1 @ 8, reserved
  .word -1 @ 9, reserved
  .word -1 @ 10, reserved
  .word interrupt.SVC @ 11
  .word interrupt.DebugMonitor @ 12
  .word -1 @ 13, reserved
  .word interrupt.PendSV @ 14
  .word interrupt.SysTick @ 15
//--- Non-Core Vectors
  .word interrupt.DMA0_DMA16 @ 16
  .word interrupt.DMA1_DMA17 @ 17
  .word interrupt.DMA2_DMA18 @ 18
  .word interrupt.DMA3_DMA19 @ 19
  .word interrupt.DMA4_DMA20 @ 20
  .word interrupt.DMA5_DMA21 @ 21
  .word interrupt.DMA6_DMA22 @ 22
  .word interrupt.DMA7_DMA23 @ 23
  .word interrupt.DMA8_DMA24 @ 24
  .word interrupt.DMA9_DMA25 @ 25
  .word interrupt.DMA10_DMA26 @ 26
  .word interrupt.DMA11_DMA27 @ 27
  .word interrupt.DMA12_DMA28 @ 28
  .word interrupt.DMA13_DMA29 @ 29
  .word interrupt.DMA14_DMA30 @ 30
  .word interrupt.DMA15_DMA31 @ 31
  .word interrupt.DMA_Error @ 32
  .word interrupt.MCM @ 33
  .word interrupt.FTFE @ 34
  .word interrupt.Read_Collision @ 35
  .word interrupt.LVD_LVW @ 36
  .word interrupt.LLWU @ 37
  .word interrupt.WDOG_EWM @ 38
  .word interrupt.RNG @ 39
  .word interrupt.I2C0 @ 40
  .word interrupt.I2C1 @ 41
  .word interrupt.SPI0 @ 42
  .word interrupt.SPI1 @ 43
  .word interrupt.I2S0_Tx @ 44
  .word interrupt.I2S0_Rx @ 45
  .word -1 @ 46 (unused)
  .word interrupt.UART0_RX_TX @ 47
  .word interrupt.UART0_ERR @ 48
  .word interrupt.UART1_RX_TX @ 49
  .word interrupt.UART1_ERR @ 50
  .word interrupt.UART2_RX_TX @ 51
  .word interrupt.UART2_ERR @ 52
  .word interrupt.UART3_RX_TX @ 53
  .word interrupt.UART3_ERR @ 54
  .word interrupt.ADC0 @ 55
  .word interrupt.CMP0 @ 56
  .word interrupt.CMP1 @ 57
  .word interrupt.FTM0 @ 58
  .word interrupt.FTM1 @ 59
  .word interrupt.FTM2 @ 60
  .word interrupt.CMT @ 61
  .word interrupt.RTC @ 62
  .word interrupt.RTC_Seconds @ 63
  .word interrupt.PIT0 @ 64
  .word interrupt.PIT1 @ 65
  .word interrupt.PIT2 @ 66
  .word interrupt.PIT3 @ 67
  .word interrupt.PDB0 @ 68
  .word interrupt.USB0 @ 69
  .word interrupt.USBDCD @ 70
  .word -1 @ 71 (unused)
  .word interrupt.DAC0 @ 72
  .word interrupt.MCG @ 73
  .word interrupt.LPTMR0 @ 74
  .word interrupt.PORTA @ 75
  .word interrupt.PORTB @ 76
  .word interrupt.PORTC @ 77
  .word interrupt.PORTD @ 78
  .word interrupt.PORTE @ 79
  .word interrupt.SWINT @ 80
  .word interrupt.SPI2 @ 81
  .word interrupt.UART4_RX_TX @ 82
  .word interrupt.UART4_ERR @ 83
  .word -1 @ 84 (unused)
  .word -1 @ 85 (unused)
  .word interrupt.CMP2 @ 86
  .word interrupt.FTM3 @ 87
  .word interrupt.DAC1 @ 88
  .word interrupt.ADC1 @ 89
  .word interrupt.I2C2 @ 90
  .word interrupt.CAN0_ORed_Message_buffer @ 91
  .word interrupt.CAN0_Bus_Off @ 92
  .word interrupt.CAN0_Error @ 93
  .word interrupt.CAN0_Tx_Warning @ 94
  .word interrupt.CAN0_Rx_Warning @ 95
  .word interrupt.CAN0_Wake_Up @ 96
  .word interrupt.SDHC @ 97
  .word interrupt.ENET_1588_Timer @ 98
  .word interrupt.ENET_Transmit @ 99
  .word interrupt.ENET_Receive @ 100
  .word interrupt.ENET_Error @ 101
  .word interrupt.LPUART0 @ 102
  .word interrupt.TSI0 @ 103
  .word interrupt.TPM1 @ 104
  .word interrupt.TPM2 @ 105
  .word interrupt.USBHSDCD @ 106
  .word interrupt.I2C3 @ 107
  .word interrupt.CMP3 @ 108
  .word interrupt.USBHS @ 109
  .word interrupt.CAN1_ORed_Message_buffer @ 110
  .word interrupt.CAN1_Bus_Off @ 111
  .word interrupt.CAN1_Error @ 112
  .word interrupt.CAN1_Tx_Warning @ 113
  .word interrupt.CAN1_Rx_Warning @ 114
  .word interrupt.CAN1_Wake_Up @ 115
  .word -1 @ 116 (unused)
  .word -1 @ 117 (unused)
  .word -1 @ 118 (unused)
  .word -1 @ 119 (unused)
  .word -1 @ 120 (unused)
  .word -1 @ 121 (unused)
  .word -1 @ 122 (unused)
  .word -1 @ 123 (unused)
  .word -1 @ 124 (unused)
  .word -1 @ 125 (unused)
  .word -1 @ 126 (unused)
  .word -1 @ 127 (unused)
  .word -1 @ 128 (unused)
  .word -1 @ 129 (unused)
  .word -1 @ 130 (unused)
  .word -1 @ 131 (unused)
  .word -1 @ 132 (unused)
  .word -1 @ 133 (unused)
  .word -1 @ 134 (unused)
  .word -1 @ 135 (unused)
  .word -1 @ 136 (unused)
  .word -1 @ 137 (unused)
  .word -1 @ 138 (unused)
  .word -1 @ 139 (unused)
  .word -1 @ 140 (unused)
  .word -1 @ 141 (unused)
  .word -1 @ 142 (unused)
  .word -1 @ 143 (unused)
  .word -1 @ 144 (unused)
  .word -1 @ 145 (unused)
  .word -1 @ 146 (unused)
  .word -1 @ 147 (unused)
  .word -1 @ 148 (unused)
  .word -1 @ 149 (unused)
  .word -1 @ 150 (unused)
  .word -1 @ 151 (unused)
  .word -1 @ 152 (unused)
  .word -1 @ 153 (unused)
  .word -1 @ 154 (unused)
  .word -1 @ 155 (unused)
  .word -1 @ 156 (unused)
  .word -1 @ 157 (unused)
  .word -1 @ 158 (unused)
  .word -1 @ 159 (unused)
  .word -1 @ 160 (unused)
  .word -1 @ 161 (unused)
  .word -1 @ 162 (unused)
  .word -1 @ 163 (unused)
  .word -1 @ 164 (unused)
  .word -1 @ 165 (unused)
  .word -1 @ 166 (unused)
  .word -1 @ 167 (unused)
  .word -1 @ 168 (unused)
  .word -1 @ 169 (unused)
  .word -1 @ 170 (unused)
  .word -1 @ 171 (unused)
  .word -1 @ 172 (unused)
  .word -1 @ 173 (unused)
  .word -1 @ 174 (unused)
  .word -1 @ 175 (unused)
  .word -1 @ 176 (unused)
  .word -1 @ 177 (unused)
  .word -1 @ 178 (unused)
  .word -1 @ 179 (unused)
  .word -1 @ 180 (unused)
  .word -1 @ 181 (unused)
  .word -1 @ 182 (unused)
  .word -1 @ 183 (unused)
  .word -1 @ 184 (unused)
  .word -1 @ 185 (unused)
  .word -1 @ 186 (unused)
  .word -1 @ 187 (unused)
  .word -1 @ 188 (unused)
  .word -1 @ 189 (unused)
  .word -1 @ 190 (unused)
  .word -1 @ 191 (unused)
  .word -1 @ 192 (unused)
  .word -1 @ 193 (unused)
  .word -1 @ 194 (unused)
  .word -1 @ 195 (unused)
  .word -1 @ 196 (unused)
  .word -1 @ 197 (unused)
  .word -1 @ 198 (unused)
  .word -1 @ 199 (unused)
  .word -1 @ 200 (unused)
  .word -1 @ 201 (unused)
  .word -1 @ 202 (unused)
  .word -1 @ 203 (unused)
  .word -1 @ 204 (unused)
  .word -1 @ 205 (unused)
  .word -1 @ 206 (unused)
  .word -1 @ 207 (unused)
  .word -1 @ 208 (unused)
  .word -1 @ 209 (unused)
  .word -1 @ 210 (unused)
  .word -1 @ 211 (unused)
  .word -1 @ 212 (unused)
  .word -1 @ 213 (unused)
  .word -1 @ 214 (unused)
  .word -1 @ 215 (unused)
  .word -1 @ 216 (unused)
  .word -1 @ 217 (unused)
  .word -1 @ 218 (unused)
  .word -1 @ 219 (unused)
  .word -1 @ 220 (unused)
  .word -1 @ 221 (unused)
  .word -1 @ 222 (unused)
  .word -1 @ 223 (unused)
  .word -1 @ 224 (unused)
  .word -1 @ 225 (unused)
  .word -1 @ 226 (unused)
  .word -1 @ 227 (unused)
  .word -1 @ 228 (unused)
  .word -1 @ 229 (unused)
  .word -1 @ 230 (unused)
  .word -1 @ 231 (unused)
  .word -1 @ 232 (unused)
  .word -1 @ 233 (unused)
  .word -1 @ 234 (unused)
  .word -1 @ 235 (unused)
  .word -1 @ 236 (unused)
  .word -1 @ 237 (unused)
  .word -1 @ 238 (unused)
  .word -1 @ 239 (unused)
  .word -1 @ 240 (unused)
  .word -1 @ 241 (unused)
  .word -1 @ 242 (unused)
  .word -1 @ 243 (unused)
  .word -1 @ 244 (unused)
  .word -1 @ 245 (unused)
  .word -1 @ 246 (unused)
  .word -1 @ 247 (unused)
  .word -1 @ 248 (unused)
  .word -1 @ 249 (unused)
  .word -1 @ 250 (unused)
  .word -1 @ 251 (unused)
  .word -1 @ 252 (unused)
  .word -1 @ 253 (unused)
  .word -1 @ 254 (unused)
  .word -1 @ 255 (unused)

//--------------------------------------------------------------------------------------------------
