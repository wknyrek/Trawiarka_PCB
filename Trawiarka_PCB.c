/*
 * Trawiarka_PCB.c
 *
 * Created: 28/03/2017 20:56:00
 *  Author: Waldek
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include "HD44780.h"
#include "defines.h"
#include "buttons.h"
#include "menu2.h"
#include "adc.h"

volatile uint16_t ms=0;
volatile uint16_t sec=0;
volatile uint8_t button_=0;
uint8_t adc=0;



int main(void)
{
	
	LCD_Initalize();
	LCD_Clear();
	ButtonsInit();
	InitializeADC();
	DDRD |=(1<<RELAY_LED);
	//PORTD |=(1<<RELAY_LED);
	DDRB |=(1<<BUZZER_LED);
	//PORTB |=(1<<BUZZER_LED);
	
	//timer0
	TCCR0A |= (1<<WGM01);
	TCCR0B |= ((1<<CS00) | (1<<CS01));
	OCR0A   = 125;
	TIMSK0 |=(1<<OCIE0A);
	/*sei();*/
	//while(!adc){LCD_GoTo(0,0);LCD_WriteText("Blad czujnika temperatury");}
    while(1)
    {
// 		LCD_GoTo(0,0);
// 		LCD_WriteText("Trawiarka sie pisze");
// 		LCD_GoTo(1,1);
// 		LCD_WriteText("Trawiarka sie pisze");
			if(button_){
				button_=0;
				// RefreshMenu(CheckButtons());
			}				 
		RefreshMenu(CheckButtons());
        //TODO:: Please write your application code 
    }
}
ISR(TIMER0_COMPA_vect)
{
	
	ms++;
	
	if(ms%250 == 0)
	{ //100ms
		button_=1;
		
	}
	if(ms == 1000){
		ms=0;
		sec++;
	}
}	