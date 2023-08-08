/*
 * GccApplication3.c
 *
 * Created: 2023-08-08 오전 1:15:04
 * Author : yjchoi
 */ 

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int j = 0;

int main(void)
{
	DDRA = 0xFF;
	DDRD = 0x00;
	
	PORTA = 0xFF;
	
	EIMSK = 0b00001111;
	EICRA = 0b10101010;
	
	sei();

	while (1)
	{
		for (int i = j; i < 256; i++)
		{
			PORTA = 0xFF - i;
			_delay_ms(100);
		}

		j = 0;
	}
}

ISR(INT0_vect)
{
	PORTA = 0b00011111;
	_delay_ms(500);
	for (int i = 0; i < 8; i++)
	{
		PORTA = ~PORTA;
		PORTA = PORTA >> 1;
		PORTA = ~PORTA;
		_delay_ms(500);
	}
}

ISR(INT1_vect)
{
	PORTA = 0b11111000;
	_delay_ms(500);
	for (int i = 0; i < 8; i++)
	{
		PORTA = ~PORTA;
		PORTA = PORTA << 1;
		PORTA = ~PORTA;
		_delay_ms(500);
	}
}

ISR(INT2_vect)
{
	PORTA = 0b11111110;
	_delay_ms(100);
	for (int i = 0; i < 8; i++)
	{
		PORTA = ~PORTA;
		PORTA = PORTA << 1;
		PORTA = ~PORTA;
		_delay_ms(100);
	}
	PORTA = 0b01111111;
	_delay_ms(100);
	for (int i = 0; i < 8; i++)
	{
		PORTA = ~PORTA;
		PORTA = PORTA >> 1;
		PORTA = ~PORTA;
		_delay_ms(100);
	}
}

ISR(INT3_vect)
{
	for (int i = 0; i < 256; i++)
	{
		PORTA = 0xFF - i;
		_delay_ms(100);
	}
}


