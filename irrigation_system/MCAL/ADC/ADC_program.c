#include "ADC_interface.h"

void ADC_Init(uint8_t portNumber, char pinNumber)
{
	DIO_SetPinDirection(portNumber, pinNumber,INPUT);
	// Enable ADC, fr/128
	SETPORT(ADCSRA,0x87);
}

int ADC_read(char channel)
{
	// Set Vref: Avcc
	SETPORT(ADMUX,0x40);
	// set channel to read
	SETPORT(ADMUX, ADMUX|(channel & 0x0f));
	//Start ADC conversion
	SETBIT(ADCSRA,6);
	//Wait until end of conversion, ADIF-->bit 4
	while (!(ADCSRA & (1<<4)));
	//Clear interrupt flag
	CLEARBIT(ADCSRA,4);
	//Return ADC word
	int ADC_value = ADCL | (ADCH<<8);
	return ADC_value;
}