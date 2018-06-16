/*
 * lab3.c
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
	EICRA = 0b00001010;
	EIMSK = 0b00000011;
	
	DDRD = 0xF0;
	PORTD = 0x00;
	sei();
	
	while(1){
 		PORTD = 0b10000000;
 		_delay_ms(500); //half a second
 		PORTD = 0x00;
 		_delay_ms(500);
 		PORTD = 0b01000000;
 		_delay_ms(500); //half a second
 		PORTD = 0x00;
 		_delay_ms(500);
 		PORTD = 0b00100000;
 		_delay_ms(500); //half a second
 		PORTD = 0x00;
 		_delay_ms(500);
	}

	//add your codes here
}

ISR(INT1_vect)
{
		unsigned char i;	
		for(i = 0; i<3 ;i++){
			PORTD = 0xFF;
			_delay_ms(500);
			PORTD = 0x00;
			_delay_ms(500);
			PORTD = 0xFF;
			_delay_ms(500); 
		}
	
}
