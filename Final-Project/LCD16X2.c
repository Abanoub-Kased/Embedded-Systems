
#include "LCD16X2.h"
 
 void lcd_data_write(char data)
 {
	 LCD_CONTROL_PORT=LCD_EN;
	 LCD_CONTROL_PORT=LCD_CONTROL_PORT|LCD_RS;
	 LCD_DATA_PORT=data;
	 _delay_ms(1);
	 LCD_CONTROL_PORT=LCD_CONTROL_PORT&0x80;
 }

void lcd_command_write(char command)
{
	LCD_CONTROL_PORT=LCD_EN;
	LCD_DATA_PORT=command;
	 _delay_ms(1);
	LCD_CONTROL_PORT=LCD_CONTROL_PORT&0x00;
	 
}


void lcd_init()
{
	lcd_command_write(0x01); //clear
	_delay_ms(1);
	lcd_command_write(0x38); //function set 
	_delay_ms(1);
	lcd_command_write(0x0C); // display on,cursor on
	_delay_ms(1);
	lcd_command_write(0x06); //mode set (increment)
	_delay_ms(1);
	
}
//bonus
void lcd_string_write(char *string){
  while(*string!='\0'){
	 lcd_data_write(*string);
	 string++;
  }
}