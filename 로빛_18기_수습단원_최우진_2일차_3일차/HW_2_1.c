/*
 * Interrupt-1.c
 *
 * Created: 2023-08-06 오후 11:25:11
 * Author : yjchoi
 */ 
#define F_CPU 16000000
#define PIND7 7
#define PIND6 6
#define PIND5 5
#define PIND4 4
#define PIND3 3
#define PIND2 2
#define PIND1 1
#define PIND0 0


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRA = 0xFF;
	DDRD = 0x00;
	
	PORTA = 0xFF;
	
	EIMSK = 0b00001100;
	EICRA = 0b10100000;
	
	sei();
	
    /* Replace with your application code */
    while (1) 
    {

		if(!(PIND & (1<<PIND0)))
		{
			PORTA = 0b00001111;
			
				if(!(PIND & (1<<PIND1)))
				{
					PORTA = 0b00000000;
					_delay_ms(500);
				}
		}
		else if(!(PIND & (1<<PIND1)))
		{
			PORTA = 0b11110000;
			_delay_ms(500);
		}
		
		else{
					PORTA = 0b00000000;
					_delay_ms(500);
					PORTA = 0b11111111;
					_delay_ms(500);
		}
		
			
    }
}
ISR(INT2_vect){
	PORTA = 0b01111111;
	_delay_ms(500);
	for (int i=0;i<8;i++)
	{
		PORTA = ~PORTA;
		PORTA = PORTA>>1;
		PORTA = ~PORTA;
		_delay_ms(500);
	
	}

	
}
ISR(INT3_vect){
	
		PORTA = 0b11111110;
		_delay_ms(500);
		for (int i=0;i<8;i++)
		{
			PORTA = ~PORTA;
			PORTA = PORTA<<1;
			PORTA = ~PORTA;
			_delay_ms(500);
			
		}
	
}

