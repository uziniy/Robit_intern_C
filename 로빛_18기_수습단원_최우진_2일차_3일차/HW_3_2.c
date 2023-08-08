/*
 * robit_3_2.c
 *
 * Created: 2023-08-07 오후 5:30:33
 * Author : yjchoi
 */ 

#include "LCD_Text.h"
#include <util/delay.h>
#include <avr/interrupt.h>
int A=1,B=1,D=1;


int main(void)
{

	DDRD = 0x00;
	EIMSK = 0b00001111;
	EICRA = 0b10101010;
	
	sei();
    
	 lcdInit();
	 lcdClear();
    while (1) 
    {

    }
}
ISR(INT0_vect){
	A++;
}
ISR(INT1_vect){
	D++;
}
ISR(INT2_vect){
	B++;
}
ISR(INT3_vect){
	if(D%4==1){
		lcdString(0,0,"A");
		lcdString(0,1,"+");
		lcdString(0,2,"B");
		lcdString(0,3,"=");
		lcdNumber(0,4,A+B);
	}
	if(D%4==2){
		lcdString(0,0,"A");
		lcdString(0,1,"-");
		lcdString(0,2,"B");
		lcdString(0,3,"=");
		lcdNumber(0,4,A-B);
	}
	if(D%4==3){
		lcdString(0,0,"A");
		lcdString(0,1,"*");
		lcdString(0,2,"B");
		lcdString(0,3,"=");
		lcdNumber(0,4,A*B);
	}
	if(D%4==0){
		lcdString(0,0,"A");
		lcdString(0,1,"/");
		lcdString(0,2,"B");
		lcdString(0,3,"=");
		lcdNumber(0,4,A/B);
	}
	

	
}
