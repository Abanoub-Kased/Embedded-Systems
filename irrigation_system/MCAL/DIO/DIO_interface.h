
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "DIO_register.h"
#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"

#define  OUTPUT 1
#define  INPUT  0
#define  HIGH   1
#define  LOW    0
  
void DIO_WritePin(uint8_t portNumber, uint8_t pinNumber, uint8_t value);
void DIO_SetPinDirection(uint8_t portNumber, uint8_t pinNumber, uint8_t direction);
void DIO_WritePort(uint8_t portNumber, uint8_t value);
void DIO_SetPortDirection(uint8_t portNumber, uint8_t value);

#endif 