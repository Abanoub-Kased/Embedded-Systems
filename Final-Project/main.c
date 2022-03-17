#include "LCD16X2.h"
#include "keyPad.h"
#include "I2C.h"
#include "EEPROM.h"
#include "RTC.h"
#include <avr/io.h>
#include <string.h>
#include <stdio.h>

int high_address_eeprom=0;
int low_address_eeprom=0;

void print_data_on_lcd(char *key,char *time,char *date);
void save_data_to_eeprom(char *key,char *time,char *date);
void load_last_key();

int main(void){
	DDRD=0x0f;
	DDRC=0xf0;
	DDRB=0xff;
	DDRA=0xff;
	lcd_init();
	init_I2C();
	char key[16];
	char time[20];
	char date[20];
	int key_num;
	time_date DS_data;
	_delay_ms(100);
	while(1){
		key_num=scan_keypad();
		if(key_num!=0){
			if (key_num!=15&&key_num!=16)
			{
				//read time and date from DS
				DS_data=read_DS();
				//convert the key&time&date to string
				sprintf(key, "Key=%02d",key_num);
				sprintf(time, "Time:%02x-%02x-%02x", DS_data.hour, DS_data.minute, DS_data.second);
				sprintf(date, "Date:%02x-%02x-%02x", DS_data.day, DS_data.month, DS_data.year);
				key_num=0;
				//print on LCD
				print_data_on_lcd(key,time,date);
				//save to EEPROM
				save_data_to_eeprom(key,time,date);
			}
			else if(key_num==15){
				//load last key
				load_last_key();
			}
			else if(key_num==16){
				//clear memory
				lcd_command_write(0x01);//clear
				_delay_ms(5);
				lcd_string_write("clearing memory");
				earse_EEPROM();
			}
		}
	}
}

void print_data_on_lcd(char *key,char *time,char *date){
	lcd_command_write(0x01);//clear
	_delay_ms(5);
	lcd_string_write(key);
	_delay_ms(500);
	lcd_command_write(0x01);//clear
	_delay_ms(5);
	lcd_string_write(time);
	lcd_command_write(0xc0);//next line
	lcd_string_write(date);
}

void save_data_to_eeprom(char *key,char *time,char *date){
	write_to_EEPROM(key,time,date,high_address_eeprom,low_address_eeprom);
	//to write key&time&date it take 32 byte so increment the address
	low_address_eeprom+=32; //to next not written bytes
	if (low_address_eeprom>=256)
	{
		low_address_eeprom=0;
		high_address_eeprom++;
		
		if (high_address_eeprom>=256) //EEPROM is full 
		{
			high_address_eeprom=0;
		}
	} 
}

void load_last_key(){
	char loaded_data[40];
	int low,high;
	//to get the address of last written key
	if (low_address_eeprom==0){
		low=224;
		high=high_address_eeprom-1;
	}
	else{
		low=low_address_eeprom-32;
		high=high_address_eeprom;
	}
	//read the key data
	read_from_EEPROM(loaded_data,high,low);
	//print loaded data on LCD
	lcd_command_write(0x01);
	lcd_string_write(" last ");
	//loop on loaded data to write it to LCD
	for(int i=0;i<32;i++){
		lcd_data_write(loaded_data[i]);
		if(i==5){
			//write the part of the key then wait and clear
			_delay_ms(500);
			lcd_command_write(0x01);
			_delay_ms(5);
		}else if(i==18){
			lcd_command_write(0xc0);//next line
		}
	}
}

