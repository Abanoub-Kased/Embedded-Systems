
#ifndef LCD16X2_INTERFACE_H_
#define LCD16X2_INTERFACE_H_

#define F_CPU 8000000UL
#include <util/delay.h>
#include "../../MCAL/DIO/DIO_interface.h"

uint8_t LCD_DATA_PORT, LCD_CONTROL_PORT, LCD_EN, LCD_RS;

void lcd_init(uint8_t dataPort, uint8_t controlPort, uint8_t ENPin, uint8_t RSPin);
void lcd_data_write(char data);
void lcd_command_write( char command);
void lcd_string_write(const char *string);

#endif 