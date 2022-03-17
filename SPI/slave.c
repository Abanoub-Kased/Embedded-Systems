#include <avr/io.h>
#define F_CPU 8000000UL

void SPI_SlaveInit(void);
unsigned char SPI_SlaveRecieve(void);

int main(void)
{
	DDRA=0xff;
	SPI_SlaveInit();
	unsigned char recive_data;
		
	while (1)
	{
		recive_data=SPI_SlaveRecieve();
		if(recive_data=='0'){
			PORTA=0x01;
		}
		else if(recive_data=='1'){
			PORTA=0x02;
		}
		else if(recive_data=='2'){
			PORTA=0x04;
		}
		else if(recive_data=='3'){
			PORTA=0x08;
		}
	}
}
void SPI_SlaveInit(void){
	DDRB=(1<<6);
	SPCR=(1<<SPE);
}
unsigned char SPI_SlaveRecieve(void){
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}
