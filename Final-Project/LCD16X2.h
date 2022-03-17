
#ifndef LCD16X2_H_
#define LCD16X2_H_
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LCD_DATA_PORT PORTB
#define LCD_CONTROL_PORT PORTA
#define LCD_RS 0b10000000//PORTA7
#define LCD_EN 0b01000000//PORTA6

void lcd_data_write(char data);
void lcd_command_write( char command);
void lcd_init();
void lcd_string_write(char *string);

#endif