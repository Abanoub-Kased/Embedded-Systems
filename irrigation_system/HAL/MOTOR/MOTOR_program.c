#include "MOTOR_interface.h"

void MOTOR_init(uint8_t portNumber, uint8_t pinNumber){
	DIO_SetPinDirection(portNumber, pinNumber, OUTPUT);
}

void MOTOR_ON(uint8_t portNumber, uint8_t pinNumber){
	DIO_WritePin(portNumber, pinNumber,HIGH);
}

void MOTOR_OFF(uint8_t portNumber, uint8_t pinNumber){
	DIO_WritePin(portNumber, pinNumber,LOW);
}