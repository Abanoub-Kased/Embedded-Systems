
#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADCSRA *((volatile uint8_t *)0x26)
#define ADMUX *((volatile uint8_t *)0x27)
#define ADCL *((volatile uint8_t *)0x24)
#define ADCH *((volatile uint8_t *)0x25)

#endif 