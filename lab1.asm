; Embedded Systems Lab
; Lab1.asm
;
; Created: 09.09.2017 15:04:08
; Author : Biruk Amare
;

.include "m328def.inc"
.org 0x0000
RJMP begin ; Jump to begin
.org 0x0034
begin:
	CLI		; Clear Interrupt
	; Initialize the microcontroller stack pointer
	LDI R16, low(RAMEND)
	OUT SPL, R16
	LDI R16, high(RAMEND)
	OUT SPH, R16
	; Configure portD as an output
	LDI R16, 0xFF
	OUT DDRD, R16
	; Toggle the pins of portD

mainloop: LDI R16, 0xFF
		  OUT PORTD, R16
		  RCALL Delay
		  LDI R16, 0x00
		  OUT PORTD, R16
		  RCALL Delay
		  RJMP mainloop

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



