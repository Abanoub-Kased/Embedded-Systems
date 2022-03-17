 #define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>

#define N 8
#define F_PWM 50 // Servo Standard
#define ICR1_VALUE ((F_CPU)/(2*N*F_PWM)) // Check slides or datasheet for this equation
void init_timer1_phase_correct();//servo task
volatile unsigned char counter1;



int main(void)
{
	cli();
	// Initialize Timer 1 servo
	init_timer1_phase_correct();
	sei();
	
	while (1)
	{
		
		
		
	}
}


void init_timer1_phase_correct()
{
	counter1 = 0;
	//initial OCR1A
	OCR1A = 500;
	//initialize TCNT1
	TCNT1 = 0;
	//  configurations 
	TCCR1A|=(1<<WGM11);
	TCCR1B|=(1<<WGM13);
	TCCR1A|=(1<<COM1A1);
	TCCR1B|=(1<<CS11);  //8
	//recommended: set the top=ICR1
	ICR1 = ICR1_VALUE;  // Makes PWM freq = 50 Hz (Required for Servos) (See Eqn above in #define)
	
	// Make PD5 (OC1A) as output pin
	DDRD=0xff;
	// Enable Timer1 overflow interrupt
    TIMSK|=(1<<TOIE1);
}

ISR(TIMER1_OVF_vect)		// Timer1 overflow interrupt handler
{
	counter1++;
	if(counter1==100){
	static i=0;
	OCR1A=500+i*28;
	counter1=0;
	i++;
	if(i==20){
		i=0;
	}
	}
}

