
#include "LCD16X2_interface.h"

void lcd_init(uint8_t dataPort, uint8_t controlPort, uint8_t ENPin, uint8_t RSPin)
{
	LCD_DATA_PORT = dataPort;
	LCD_CONTROL_PORT = controlPort;
	LCD_EN = ENPin;
	LCD_RS = RSPin;
	DIO_SetPortDirection(LCD_DATA_PORT,0xff);
	DIO_SetPinDirection(LCD_CONTROL_PORT,LCD_EN,OUTPUT);
	DIO_SetPinDirection(LCD_CONTROL_PORT,LCD_RS,OUTPUT);
	_delay_ms(20);
	lcd_command_write(0x01); //clear
	lcd_command_write(0x30); //function set
	lcd_command_write(0x0E); // display on , cursor on
	lcd_command_write(0x06); //mode set (increment)
	lcd_command_write(0x38); //initalize 16*2
}

void lcd_data_write(char data)
{
	DIO_WritePin(LCD_CONTROL_PORT, LCD_EN, HIGH);
	DIO_WritePin(LCD_CONTROL_PORT, LCD_RS, HIGH);
	DIO_WritePort(LCD_DATA_PORT, data);
	_delay_ms(1);
	DIO_WritePin(LCD_CONTROL_PORT, LCD_EN, LOW);
}

void lcd_command_write( char command)
{
	DIO_WritePin(LCD_CONTROL_PORT, LCD_EN, HIGH);
	DIO_WritePin(LCD_CONTROL_PORT, LCD_RS, LOW);
	DIO_WritePort(LCD_DATA_PORT,command);
	_delay_ms(1);
	DIO_WritePin(LCD_CONTROL_PORT, LCD_EN, LOW);
	
}

void lcd_string_write(const char *string)
{
	while(*string!='\0'){
		lcd_data_write(*string);
		string++;
		_delay_ms(100);
	}
}
