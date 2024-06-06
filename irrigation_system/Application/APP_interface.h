

#ifndef APP_INTERFACE_H_
#define APP_INTERFACE_H_

#include <stdio.h>
#include "../HAL/LCD/LCD16X2_interface.h"
#include "../HAL/MOTOR/MOTOR_interface.h"
#include "../HAL/TEMPERTURE_SENSOR/TEMPERATURE_SENSOR_interface.h"
#include "../HAL/SOIL_MOISTURE_SENSOR/SOIL_MOSITURE_SENSOR_interface.h"

typedef enum {COLD, NORMAL, HEAT} temp_t;
typedef enum {WET, MOIST, DRY} soil_t;
typedef enum {LONG, MEDIUM, SHORT, OFF} water_t;
uint8_t MOTORPort, MOTORPin, tempChannel, soilChannel;
	
void irrigation_init(uint8_t motorPort,uint8_t motorPin,uint8_t tempPort,uint8_t tempPin,uint8_t soilPort,uint8_t soilPin);
void display_init(uint8_t dataPort, uint8_t controlPort, uint8_t ENPin, uint8_t RSPin);
void display_status(const char *status);
temp_t AirTempearture();
soil_t SoilMoisture();
void WaterPumpDuration(water_t pumpTime);
#endif 