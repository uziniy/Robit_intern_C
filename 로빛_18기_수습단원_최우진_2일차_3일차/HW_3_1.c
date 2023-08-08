/*
 * robit_3_1.c
 *
 * Created: 2023-08-07 오후 5:19:21
 * Author : yjchoi
 */ 

#include "LCD_Text.h"
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
	int x,n;
	DDRA = 0xFF;
	lcdInit();
	lcdClear();
	//lcdString(0,0,"7th_KH");
	//lcdNumber(1,0,1234);
	DDRF = 0x00;
	ADMUX = 0X40;
	ADCSRA = 0X87;
	sei();


	while (1)
	{
		unsigned int adcValue = 0;
		unsigned char channel = 0x00;
		lcdInit();
		lcdClear();
		
		
		ADMUX = 0x40 | channel;
		ADCSRA |=0x40;
		while((ADCSRA&0x10)==0);
		
		adcValue = ADC;  
		lcdNumber(0,0,adcValue);
		lcdNumber(1,0,0.0048828125*adcValue);
		
		
		if ((adcValue>=0)&&(adcValue<=127))
		{
			PORTA = 0b01111111;
			_delay_ms(100);
		}
		if ((adcValue>=128)&&(adcValue<=255))
		{
			PORTA = 0b10111111;
			_delay_ms(100);
		}
		if ((adcValue>=256)&&(adcValue<=383))
		{
			PORTA = 0b11011111;
			_delay_ms(100);
		}
		if ((adcValue>=384)&&(adcValue<=511))
		{
			PORTA = 0b11101111;
			_delay_ms(100);
		}
		if ((adcValue>=512)&&(adcValue<=639))
		{
			PORTA = 0b11110111;
			_delay_ms(100);
		}
		if ((adcValue>=640)&&(adcValue<=767))
		{
			PORTA = 0b11111011;
			_delay_ms(100);
		}
		if ((adcValue>=768)&&(adcValue<=895))
		{
			PORTA = 0b11111101;
			_delay_ms(100);
		}
		if ((adcValue>=896)&&(adcValue<=1023))
		{
			PORTA = 0b11111110;
			_delay_ms(100);
		}
	
}
}

