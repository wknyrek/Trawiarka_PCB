/*
 * adc.c
 *
 * Created: 20.02.2017 19:15:39
 *  Author: Waldek
 */ 
#include "adc.h"
float t=0.0;
void InitializeADC(void)
{
	ADC_DDR_PORT &=~ ( (1<<ADC__CH0)|(1<<ADC__CH1)|(1<<ADC__CH2)|(1<<ADC__CH3)|(1<<ADC__CH4)|(1<<ADC__CH5) ); //ADC pins as input

	ADCSRA = (1<<ADEN)|(1<<ADPS1)|(1<<ADPS2);  //ADEN=1 - ADC enable
											   //ADPS - prescaler 64 -> 125kHz fsamp
	ADMUX  = (1<<REFS0);			   //REFS - AVcc with capacitor

 }
uint8_t ADC_Meas(void)
{
	int n=0;
	int srednia=0;
	int wynik;
	while(n <=100)
	{
		
	
	//ADMUX |= (1<<MUX2); // CH_5
	ADCSRA |= (1<<ADSC);//ADSC: Uruchomienie pojedynczej konwersji
	while(ADCSRA & (1<<ADSC)); //czeka na zakoñczenie konwersji
	
	srednia =srednia+ADC;
	n++;
	}	
	wynik=srednia/100;
	
	t=ADC;
	t= t/(1024-ADC);
	t= log(t);
	t=t + 3380/298;
	t=3380/t -283.15;
	return t;
	
}