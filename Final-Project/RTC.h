#ifndef DS
#define DS
#include "I2C.h"
typedef struct {
	uint8_t second;
	uint8_t minute;
	uint8_t hour;
	uint8_t week_day;
	uint8_t day;
	uint8_t month;
	uint8_t year;
}time_date;
	
time_date read_DS();

#endif