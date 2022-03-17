#ifndef I2C
#define I2C
#include <avr/io.h>
void init_I2C();
void start_I2C();
void send_SLA_I2C(char slave_addres);
void send_data_I2C(char data);
char read_data_ACK_I2C();
char read_data_NACK_I2C();
void stop_I2C();
#endif