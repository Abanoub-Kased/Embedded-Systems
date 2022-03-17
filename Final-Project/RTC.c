#include "RTC.h"

time_date read_DS(){
	start_I2C();
	send_SLA_I2C(0b11010000);//address of slave "DS"+W
	send_data_I2C(0x00);//address of byte to read from 
	start_I2C();//repeat start
	send_SLA_I2C(0b11010001);//address of slave "DS"+R
	time_date data;
	data.second=read_data_ACK_I2C();
	data.minute=read_data_ACK_I2C();
	data.hour=read_data_ACK_I2C();
	data.week_day= read_data_ACK_I2C();
	data.day=read_data_ACK_I2C();
	data.month=read_data_ACK_I2C();
	data.year=read_data_NACK_I2C();
	stop_I2C();
	return data;
}
