;
; Lab2.asm
;
; Created: 09.09.2017 15:04:08
; Author : Biruk Amare
;

.include "m328def.inc"
.org 0x0000
RJMP begin ; Jump to begin
.org 0x0002
RJMP loop_ext
.org 0x0034
begin:
	; Initialize the microcontroller stack pointer
	LDI R16, low(RAMEND)
	OUT SPL, R16
	LDI R16, high(RAMEND)
	OUT SPH, R16
	; Set external interrupt control and mask register
	LDI R19, 0x02
	STS 0x69, R19
	LDI R20, 0x01
	STS 0x3D, R20
	SEI
	LDI R16, 0xF0
	OUT DDRD, R16
mainloop: LDI R16, 0xFF
		  OUT PORTD, R16
		  RCALL Delay
		  LDI R16, 0x00
		  OUT PORTD, R16
		  RCALL Delay
		  RJMP mainloop

loop_ext: 
		LDI R16, 0xFF
		  OUT PORTD, R16
		  RCALL Delay
		  RCALL Delay
		  LDI R16, 0x00
		  OUT PORTD, R16
		  RCALL Delay
		  RCALL Delay
		RETI
Delay:	  LDI R17, 0xFF
loop0: LDI R20, 0x80
loop1: LDI R19, 0x7B
loop2: DEC R19
	   BRNE loop2
	   DEC R20
	   BRNE loop1
	   DEC R17
	   BRNE loop0
	   RET
