/*
 * defines.h
 *
 * Created: 28/03/2017 20:56:21
 *  Author: Waldek
 */ 


#ifndef DEFINES_H_
#define DEFINES_H_

#include <avr/io.h>
//keyboard
#define KEYS_DIR		DDRB
#define KEYS_PORT		PORTB
#define KEY_LEFT		PB2
#define KEY_OK			PB1
#define KEY_RIGHT		PB0

//relay led

#define RELAY_LED		PD6
//buzzer led
#define BUZZER_LED		PB7
//led



#endif /* DEFINES_H_ */