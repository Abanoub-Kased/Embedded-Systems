
#ifndef TEMPERATURE_SENSOR_INTERFACE_H_
#define TEMPERATURE_SENSOR_INTERFACE_H_

#include "../../MCAL/ADC/ADC_interface.h"

void tempSensor_init(uint8_t portNumber, uint8_t pinNumber);
float tempSensor_read(uint8_t channel);

#endif 