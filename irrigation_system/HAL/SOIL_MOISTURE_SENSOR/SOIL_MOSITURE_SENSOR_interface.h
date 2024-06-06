
#ifndef SOIL_MOSITURE_SENSOR_INTERFACE_H_
#define SOIL_MOSITURE_SENSOR_INTERFACE_H_

#include "../../MCAL/ADC/ADC_interface.h"

void soilSensor_init(uint8_t portNumber, uint8_t pinNumber);
float soilSensor_read(uint8_t channel);

#endif 