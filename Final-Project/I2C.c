#include "I2C.h"

void init_I2C(){
	//8000000/400000=20 so 16+2(TWBR).4^TWPS=20 
	//so TWBR=(4)/2*4^TWPS
	//pre_scalar 1
	TWSR&=(0<<TWPS0);
	TWSR&=(0<<TWPS1);
	TWBR=(4)/(8);
}

void start_I2C(){
	//send start
	TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	//wait to ACK "start"
	while(!(TWCR & (1<<TWINT)));
}

void send_SLA_I2C(char slave_addres){
	//send SLA+W
	TWDR=slave_addres;
	TWCR=(1<<TWEN)|(1<<TWINT);
	//wait to ACK "SLA+W"
	while(!(TWCR & (1<<TWINT)));
}

void send_data_I2C(char data){
	//send data
	TWDR=data;
	TWCR=(1<<TWEN)|(1<<TWINT);
	//wait to ACK "data"
	while(!(TWCR & (1<<TWINT)));
}
char read_data_ACK_I2C(){
	//read data with ACK (read in sequence)
	TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);
	while(!(TWCR&(1<<TWINT)));
	return TWDR;
}
char read_data_NACK_I2C(){
	//read data with NACK to stop
	TWCR=(1<<TWEN)|(1<<TWINT);
	while(!(TWCR&(1<<TWINT)));
	return TWDR;
}

void stop_I2C(){
	TWCR=(1<<TWSTO)|(1<<TWINT)|(1<<TWEN);
}
