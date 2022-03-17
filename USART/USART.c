#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void USART_Init(uint16_t baud_rate)
{
	 unsigned char ubrr=F_CPU/16/baud_rate-1;
	/* Set baud rate */
	UBRRH=ubrr>>8;
	UBRRL=ubrr;
	/* Set frame format: 8data---ucsz0=1,ucsz1=1, 1stop bit ---usbs=0*/
	UCSRC|=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	/* Enable receiver and transmitter */
	UCSRB|=(1<<RXEN)|(1<<TXEN);
}

//Transmission
void USART_Transmit(unsigned char data )
{
	/* Wait for empty transmit buffer */
	while(!(UCSRA&(1<<UDRE)));
	/* Put data into buffer, sends the data */
    UDR=data;
}

void USART_Transmit_Str(char*  str,unsigned char len)
{
	for(int i=0;i<len;i++){
		USART_Transmit(str[i]);
	}
}

//RX
unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
    while(!(UCSRA&(1<<RXC)));
	/* Get and return received data from buffer */
	return UDR;
}