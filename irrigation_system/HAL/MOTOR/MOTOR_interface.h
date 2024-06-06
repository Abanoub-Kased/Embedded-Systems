
#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

#include "../../MCAL/DIO/DIO_interface.h"

void MOTOR_init(uint8_t portNumber, uint8_t pinNumber);
void MOTOR_ON(uint8_t portNumber, uint8_t pinNumber);
void MOTOR_OFF(uint8_t portNumber, uint8_t pinNumber);

#endif 