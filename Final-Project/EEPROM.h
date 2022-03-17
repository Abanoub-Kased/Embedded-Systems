#ifndef EEPROM
#define EEPROM
#include "I2C.h"
#include <string.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#define EEPROM_Adress_W 0b10100000
#define EEPROM_Adress_R 0b10100001

void write_to_EEPROM(char *key,char *time,char *date,int high_address_eeprom,int low_address_eeprom);
void read_from_EEPROM(char *data,int high_address_eeprom,int low_address_eeprom);
void earse_EEPROM();
void earse_byte(int high_address,int low_address_eeprom);
#endif