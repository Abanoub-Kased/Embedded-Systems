#include "DIO_interface.h"

void DIO_SetPinDirection(uint8_t portNumber, uint8_t pinNumber, uint8_t direction)
{
   switch(portNumber)
   {
	  case 'A':
	     if(direction == OUTPUT)
		    SETBIT(DDRA,pinNumber);
		 else if(direction == INPUT)
		    CLEARBIT(DDRA,pinNumber);
		 break;
	  case 'B':
		 if(direction == OUTPUT)
			SETBIT(DDRB,pinNumber);
		 else if(direction == INPUT)
			CLEARBIT(DDRB,pinNumber);
		 break;
	  case 'C':
		 if(direction == OUTPUT)
			SETBIT(DDRC,pinNumber);
		 else if(direction == INPUT)
			CLEARBIT(DDRC,pinNumber);
		 break;
	  case 'D':
		 if(direction == OUTPUT)
			SETBIT(DDRD,pinNumber);
	     else if(direction == INPUT)
			CLEARBIT(DDRD,pinNumber);
	     break;	   	    		
   }
}

void DIO_WritePin(uint8_t portNumber, uint8_t pinNumber, uint8_t value)
{
   switch(portNumber)
   {
	   case 'A':
		   if(value == HIGH)
			  SETBIT(PORTA,pinNumber);
	       else if(value == LOW)
	          CLEARBIT(PORTA,pinNumber);
	       break;	   
	   case 'B':
	       if(value == HIGH)
	          SETBIT(PORTB,pinNumber);
	       else if(value == LOW)
	          CLEARBIT(PORTB,pinNumber);
	       break;
	   case 'C':
	      if(value == HIGH)
	         SETBIT(PORTC,pinNumber);
	      else if(value == LOW)
	         CLEARBIT(PORTC,pinNumber);
	      break;
	   case 'D':
	      if(value == HIGH)
	         SETBIT(PORTD,pinNumber);
	      else if(value == LOW)
	         CLEARBIT(PORTD,pinNumber);
	      break;	   		   
   }
	
}

void DIO_WritePort(uint8_t portNumber, uint8_t value)
{
	switch(portNumber)
	{
		case 'A':
			SETPORT(PORTA,value);
		break;
		case 'B':
			SETPORT(PORTB,value);
		break;
		case 'C':
			SETPORT(PORTC,value);
		break;
		case 'D':
			SETPORT(PORTD,value);
		break;				
	}
}

void DIO_SetPortDirection(uint8_t portNumber, uint8_t value)
{
	switch(portNumber)
	{
		case 'A':
			SETPORT(DDRA,value);
		break;
		case 'B':
			SETPORT(DDRB,value);
		break;
		case 'C':
			SETPORT(DDRC,value);
		break;
		case 'D':
			SETPORT(DDRD,value);
		break;
	}
}