
#include "APP_interface.h"

void irrigation_init(uint8_t motorPort,uint8_t motorPin,uint8_t tempPort,uint8_t tempPin,uint8_t soilPort,uint8_t soilPin){
	MOTOR_init(motorPort, motorPin);
	soilSensor_init(soilPort, soilPin);
	tempSensor_init(tempPort, tempPin);
	MOTORPort = motorPort;
	MOTORPin = motorPin;
	tempChannel = tempPin;
	soilChannel = soilPin;
}

void display_init(uint8_t dataPort, uint8_t controlPort, uint8_t ENPin, uint8_t RSPin){
	lcd_init(dataPort, controlPort, ENPin, RSPin);
}

void display_status(const char *status){
	float moisture = soilSensor_read(soilChannel);
	float temp = tempSensor_read(tempChannel);
	char string[5];
	lcd_command_write(0x01); //clear
	_delay_ms(10);
	lcd_string_write("SM=");
	sprintf(string,"%.0f", moisture);
	lcd_string_write(string);
	lcd_string_write("%  T=");
	sprintf(string,"%.0f", temp);
	lcd_string_write(string);
	lcd_string_write("c");
	lcd_command_write(0xc0); //next line
	lcd_string_write(status);	
}

temp_t AirTempearture(){
	float temp = tempSensor_read(tempChannel);
	if (temp>33)
	{
		return HEAT;
	}
	else if (temp<=33 && temp>=23)
	{
		return NORMAL;
	}
	else if (temp<23)
	{
		return COLD;
	}
	return 0;
}
soil_t SoilMoisture(){
	float moisture = soilSensor_read(soilChannel);
	if(moisture>75){
		return WET;
	}
	else if (moisture<=75 && moisture>=35)
	{
		return MOIST;
	}
	else if (moisture<35)
	{
		return DRY;
	}
	return 0;
}

void WaterPumpDuration(water_t pumpTime){
	if(pumpTime==LONG){
		MOTOR_ON(MOTORPort, MOTORPin);
		_delay_ms(6000);
		MOTOR_OFF(MOTORPort, MOTORPin);		
	}
	else if (pumpTime==MEDIUM)
	{
		MOTOR_ON(MOTORPort, MOTORPin);
		_delay_ms(4000);
		MOTOR_OFF(MOTORPort, MOTORPin);		
	}
	else if (pumpTime==SHORT)
	{
		MOTOR_ON(MOTORPort, MOTORPin);
		_delay_ms(2000);
		MOTOR_OFF(MOTORPort, MOTORPin);		
	}
	else if (pumpTime==OFF)
	{
		MOTOR_OFF(MOTORPort, MOTORPin);		
	}
}
