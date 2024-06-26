
#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

#define PINA *((volatile uint8_t *)0x39)
#define DDRA *((volatile uint8_t *)0x3A)
#define PORTA *((volatile uint8_t *)0x3B)

#define PINB *((volatile uint8_t *)0x36)
#define DDRB *((volatile uint8_t *)0x37)
#define PORTB *((volatile uint8_t *)0x38)

#define PINC *((volatile uint8_t *)0x33)
#define DDRC *((volatile uint8_t *)0x34)
#define PORTC *((volatile uint8_t *)0x35)

#define PIND *((volatile uint8_t *)0x30)
#define DDRD *((volatile uint8_t *)0x31)
#define PORTD *((volatile uint8_t *)0x32)

#endif 