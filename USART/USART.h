#ifndef USART_H_
#define USART_H_


void USART_Init(uint16_t baud_rate);

//Transmission
void USART_Transmit(unsigned char data );


void USART_Transmit_Str(char*  str,unsigned char len);


//RX
unsigned char USART_Receive( void );




#endif /* USART_H_ */