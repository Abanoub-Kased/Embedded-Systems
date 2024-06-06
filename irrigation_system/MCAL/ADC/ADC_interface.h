
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "ADC_register.h"
#include "../DIO/DIO_interface.h"

void ADC_Init(uint8_t portNumber, char pinNumber);
int ADC_read(char channel);

#endif 