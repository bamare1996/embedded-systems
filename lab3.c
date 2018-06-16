/*
 * lab4.c
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

	TCNT1 = 57724;
	TCCR1B = 0b00000100; //prescale value = 256
	TIMSK1 = 0x01; //TOIE1 enabling overflow
	sei(); //set global interrupt
	while(1){}
}
ISR(TIMER1_OVF_vect)
{
	TCNT1=57724; //16 bit counter value
    PORTD ^= 0xFF;
}
