
#include "SOIL_MOSITURE_SENSOR_interface.h"

void soilSensor_init(uint8_t portNumber, uint8_t pinNumber){
	ADC_Init(portNumber, pinNumber);
}
float soilSensor_read(uint8_t channel){
	float ADC_value = ADC_read(channel);
	float moisture = (ADC_value*100.00)/1023.00;
	return moisture;
}
