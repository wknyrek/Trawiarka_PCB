#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

#define VREF 4.93
// ADC PORT/PIN definition for ATmega328p

#define ADC_DDR_PORT		DDRC
#define ADC_PORT			PORTC
#define ADC__CH0			PC0	
#define ADC__CH1			PC1
#define ADC__CH2			PC2
#define ADC__CH3			PC3
#define ADC__CH4			PC4
#define ADC__CH5			PC5

void InitializeADC(void);
uint8_t ADC_Meas(void);


#endif /* ADC_H_ */