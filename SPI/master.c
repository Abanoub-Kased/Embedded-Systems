#include <avr/io.h>
#define F_CPU 8000000UL 

void SPI_MasterInit(void);
void SPI_MasterTransmit(char data);

int main(void)
{
	DDRD=0x00;
    SPI_MasterInit(); 
    while (1) 
    {
		if((PIND&0x10)==0x00){
			SPI_MasterTransmit('0');
		}
		else if((PIND&0x20)==0x00){
			SPI_MasterTransmit('1');
		}
		else if((PIND&0x40)==0x00){
			SPI_MasterTransmit('2');
		}
		else if((PIND&0x80)==0x00){
			SPI_MasterTransmit('3');
		}
    }
}
void SPI_MasterInit(void){
	DDRB=(1<<4)|(1<<5)|(1<<7);
	SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0);
}
void SPI_MasterTransmit(char data){
	SPDR=data;
	while(!(SPSR & (1<<SPIF)));
}
