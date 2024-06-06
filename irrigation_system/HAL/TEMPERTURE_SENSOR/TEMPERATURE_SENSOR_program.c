#include "TEMPERATURE_SENSOR_interface.h"

void tempSensor_init(uint8_t portNumber, uint8_t pinNumber){
	ADC_Init(portNumber, pinNumber);
}

float tempSensor_read(uint8_t channel){
	float ADC_value = ADC_read(channel); 
	float temperature = (ADC_value*4.88)/(10.00);
	return temperature;
}