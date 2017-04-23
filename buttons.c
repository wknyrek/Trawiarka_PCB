/*
 * buttons.c
 *
 * Created: 28/03/2017 22:12:54
 *  Author: Waldek
 */ 
#include "buttons.h"
#include "defines.h"
void ButtonsInit(void)
{
	
	KEYS_DIR &=~( (1<<KEY_LEFT) | (1<<KEY_OK) | (1<<KEY_RIGHT) );
	KEYS_PORT |=( (1<<KEY_LEFT) | (1<<KEY_OK) | (1<<KEY_RIGHT) );
	
}
uint8_t CheckButtons(void)
{
	
	if(!(PINB & (1<<KEY_LEFT))) return 2;
	if(!(PINB & (1<<KEY_RIGHT))) return 1;
	if(!(PINB & (1<<KEY_OK))) return 4;
	return 0;
}