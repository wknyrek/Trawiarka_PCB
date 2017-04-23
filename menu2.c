
/*
 * menu2.c
 *
 * Created: 15.03.2017 10:19:41
 *  Author: Waldek
 */
#include <avr/io.h>
#include <stdio.h> 
#include "menu2.h"
#include "adc.h"
#include <stdlib.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>

#define PGM_STR(X) ((const __flash char[]) { X })
/*
 struct menubox *prev;
 struct menubox *child;
 struct menubox *next;*/
	
struct menubox  menuB3 = {"return_",Return,&menuB2, &menuA1, &menuB1};
struct menubox  menuB2 = {"max_time_",MaxTime,&menuB1, &menuC2, &menuB3};
struct menubox  menuB1 = {"max_temp_",MaxTemp,&menuB3, &menuC1, &menuB2};
struct menubox  menuB4 = {"etching_",Etching,&menuA2, &menuA1, &menuA2};

struct menubox  menuA2 = {"settings_",Settings,&menuA1, &menuB1, &menuA1};
struct menubox  menuA1 = {"main_menu_",MainMenu,&menuA2, &menuB4, &menuA2};

struct menubox  menuC1 = {"temp_set_",SetTemp,&menuC1, &menuB1, &menuC1};
struct menubox  menuC2 = {"time_set_",SetTime,&menuC2, &menuB2, &menuC2};


struct menubox *current_pos=&menuA1;

uint8_t start=0;
float wynik;
char buf[10];
int wsk;
int last_enc=0;
 uint8_t *brightness=5;

void RefreshMenu(int enc_read)
{
	if(enc_read == 4) 
	{
		current_pos=current_pos->child;	
	}
	if(last_enc != enc_read)
	{
		LCD_Clear();
	}
	switch (enc_read)
	{
		case 2:
			
			current_pos=current_pos->parent;
			current_pos->funkcja();
			break;
		case 0:
			current_pos->funkcja();
			break;
		case 1:
			
			current_pos=current_pos->next;
			current_pos->funkcja();
			break;
		default:
		//Home();
		break;
	}
	
	
	
}
void MainMenu()
{
	LCD_GoTo(0,0);
	LCD_WriteText("Temp. ");
	LCD_WriteText(itoa(ADC_Meas(),buf,10));
	LCD_WriteText(" -> 45");
	LCD_GoTo(0,1);
	LCD_WriteText("Stat -> OK ");
	if(CheckButtons()==4)
	{
		sec=0;
	}
	if(start != 1)
	PORTD &=~(1<<RELAY_LED);
	
}
void Settings()
{
LCD_GoTo(0,0);
LCD_WriteText("  Ustawienia  ");	
}


void Etching()
{
	sei();
	start=1;
	LCD_GoTo(0,0);
	LCD_WriteText("Temp. 25 -> 45");
	LCD_GoTo(0,1);
	LCD_WriteText("Trawienie, ");
	itoa(sec,buf,10);
	LCD_WriteText(buf);
	PORTD |=(1<<RELAY_LED);
	
	
}
void MaxTemp()
{
	LCD_GoTo(0,0);
	LCD_WriteText("Temperatura max");
	
}
void MaxTime()
{
	LCD_GoTo(0,0);
	LCD_WriteText("Czas Max ");
}
void Return()
{
	LCD_GoTo(0,0);
	LCD_WriteText("Powrot");
}

void SetTemp()
{
	LCD_GoTo(0,0);
	LCD_WriteText("ustaw temperature");
}
void SetTime()
{
	LCD_GoTo(0,0);
	LCD_WriteText("ustaw czas");
}

// void Home()
// {
// 	current_pos=&menuA1;
// 	menuA1.funkcja();
// }
