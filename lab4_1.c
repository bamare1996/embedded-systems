/*
 * lab5-1.c
 *
 * Created: 12.09.2017 14:25:23
 * Author : Biruk Amare
 */ 
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
	cli(); //Clear interrupt
	DDRD = 0xFF; //set the portd as output, turn on

	OCR1A = 7812;		//Prescale value 1024
	TCCR1B = 0b00001101; 
	TIMSK1 = 0x02; //enabling overflow
	sei(); //set global interrupt
	while(1){}
}
ISR(TIMER1_COMPA_vect)
{
	OCR1A= 7812; //16 bit counter value
	PORTD ^= 0xFF;
}
