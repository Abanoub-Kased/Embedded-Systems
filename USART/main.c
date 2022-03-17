#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "USART.h"

int main(void)
{
	DDRC=0xFF;
	DDRB=0xFF;
	
	USART_Init(9600); //9600 baud rate
	unsigned char data;
	PORTC|=0x00;
	while(1)
	{
	data=USART_Receive();
	if(data=='0'){
		PORTC=0x00;
		USART_Transmit_Str("ALL OFF",7);
	}
	else if(data=='1'){
		PORTC=0x01;
		USART_Transmit_Str("ONE ON",6);
	}
	else if(data=='2'){
		PORTC=0x02;
		USART_Transmit_Str("TWO ON",6);
    }
	else if(data=='3'){
		PORTC=0x04;
		USART_Transmit_Str("THREE ON",8);
    }
	else if(data=='4'){
		PORTC=0x08;
		USART_Transmit_Str("FOUR ON",7);
    }
    else if(data=='5'){
		PORTC=0x10;
		USART_Transmit_Str("FIVE ON",7);
    }
    else if(data=='6'){
        PORTC=0x20;
		USART_Transmit_Str("SIX ON",6);
	}
	else if(data=='7'){
	    PORTC=0x40;
		USART_Transmit_Str("SEVEN ON",8);
	}
	else{
		PORTC=0xff;
		USART_Transmit_Str("ERROR!!",7);
	}
}
}