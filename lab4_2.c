/*
 * lab5-2.c
 *
 * Created: 12.09.2017 14:25:23
 * Author : Biruk Amare
 */ 
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

//Global Variables
int inc= 10;
int on = 1;

int main(void)
{
	cli(); //Clear interrupt
	DDRD = 0xFF; //set the portd as output, turn on
	
	TCCR1A = 0b00000001;
	TCCR1B = 0b00001001; //prescale value = 256
	TIMSK1 = 0x02; //TOIE1 enabling overflow
	sei(); //set global interrupt
	while(1){}
}
ISR(TIMER1_COMPA_vect)
{
	TCNT1 = 1;
	PORTD ^= 0xFF;
}
