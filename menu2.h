/*
 * menu2.h
 *
 * Created: 15.03.2017 10:20:04
 *  Author: Waldek
 */ 


#ifndef MENU2_H_
#define MENU2_H_
#include "defines.h"

void Menu_Show();
void Menu_SelectNext();
void Menu_SelectPrev();
void Home();
void RefreshMenu(int);

void MainMenu();
void Settings();
void MaxTemp();
void MaxTime();
void Return();
void Etching();
void SetTime();
void SetTemp();


struct menubox;
typedef void (*action)();

typedef struct menubox{
	char name[20];
	action funkcja ;
	 struct menubox *parent;
	 struct menubox *child;
	 struct menubox *next;
};

extern struct menubox  menuA1;
extern struct menubox  menuB1;
extern struct menubox  menuB2;
extern struct menubox  menuA2;
extern struct menubox  menuC1;
extern struct menubox  menuC2;

extern volatile uint16_t sec;


#endif /* MENU2_H_ */