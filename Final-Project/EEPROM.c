#include "EEPROM.h"

void write_to_EEPROM(char *key,char *time,char *date,int high_address_eeprom,int low_address_eeprom){
	start_I2C();
	send_SLA_I2C(EEPROM_Adress_W);
	//send memory address
	send_data_I2C(high_address_eeprom);
	send_data_I2C(low_address_eeprom);
	//send data which is written to memory
	//write all data in sequence
	for(int i=0;i<strlen(key);i++){
	send_data_I2C(key[i]);
	}
	for(int i=0;i<strlen(time);i++){
		send_data_I2C(time[i]);
	}
	for(int i=0;i<strlen(date);i++){
		send_data_I2C(date[i]);
	}
	//stop
	stop_I2C();
}

void read_from_EEPROM(char *data,int high_address_eeprom,int low_address_eeprom){
	start_I2C();
	send_SLA_I2C(EEPROM_Adress_W);
	//send memory address
	send_data_I2C(high_address_eeprom);
	send_data_I2C(low_address_eeprom);
	//repeated start
	start_I2C();
	send_SLA_I2C(EEPROM_Adress_R);
	//SEQUENTIAL READ without last byte (send ACK)
	for(int i=0;i<31;i++){
		data[i]=read_data_ACK_I2C();
	}
	//read last byte with (NACK) to stop read
	data[31]=read_data_NACK_I2C();
	stop_I2C();
}
void earse_EEPROM(){
		for(int h=0;h<256;h++)
		{
			for(int l=0;l<256;l++){
				earse_byte(h,l);
				_delay_ms(20);
			}
		}
}
void earse_byte(int high_address,int low_address_eeprom){
	start_I2C();
	send_SLA_I2C(EEPROM_Adress_W);
	send_data_I2C(high_address);
	send_data_I2C(low_address_eeprom);
	send_data_I2C(0x00);
	stop_I2C();
}
