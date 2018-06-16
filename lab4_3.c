/*
 * lab5-3.c
 *
 * Created: 12.09.2017 14:25:23
 * Author : Biruk Amare
 */ 
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

int inc = 10;
int on = 0;
 
int main(void)
{
	//cli(); //Clear interrupt
	DDRD = 0xFF; //set the portd as output, turn on

	
	//TCCR1A = 0b00000001;
	TCCR1B = 0b00001001;
	TIMSK1 = 0x02; //enabling overflow
	sei(); //set global interrupt
	while(1){}
}
ISR(TIMER1_COMPA_vect)
{
	if(on){
		OCR1A = inc;
		on = 0;
	}
	else
	{
		OCR1A = 40000;
		on = 1;
	}
	inc -= 10;
	if(inc == 0) inc = 20000;
	PORTD ^= 0xFF;
}
