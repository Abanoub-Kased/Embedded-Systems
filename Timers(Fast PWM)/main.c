#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>
volatile unsigned char counter0=0;
void init_timer0_pwm();// sine wave task 

//define unsigned char string variable of 256 char  
unsigned char sin_table[256];

int main(){
	
	
	cli();
	int i=0;
	int steps = 256 ;//top=256 timer0 fast PWM
	
	// In this loop, a complete sine cycle is generated discretized to 256 steps
	// In this task, each discrete sample is sent to output every Timer0 overflow (Every TOPV0/F_Timer0 = 256/8M = 0.032 ms)
	// Then, a complete sine cycle is out every 0.032 ms * 256 = 8.192 ms
	// Finally, sine frequency = 1/8.192ms ~= 122 Hz
	//in other words pwm freuency= f_cpu / (N*top)=8M/1*256= 31250
	// sine wave frequency = pwm frequency / steps = 31250/256=122
	
	
	//this for loop calculates the sin_table[256] values according to the step value equation of sine wave   
	for (i=0;i<256;i++)
	{
		sin_table[i]=(unsigned char)(((254)/2)*sin((2*3.14*i)/255)+((255+1)/2));
	}
	init_timer0_pwm();
	sei();
	while(1){
		
	}
}

void init_timer0_pwm()//sine wave PWM
{
TCNT0 = 0;
//set OCR0 to the middle value of the step values as the 0 of the sinewave 	
	 OCR0=sin_table[0];
		
	//  PWM Fast
	TCCR0|=(1<<WGM01)|(1<<WGM00);
	//  Non-inverting mode
	TCCR0|=(1<<COM01);
	//  Prescaler 1
	TCCR0|=(1<<CS00);
	// set PB3 as output 
	DDRB=0x0f;
	//enable overflow interrupt 
	TIMSK|=(1<<TOIE0);

}

ISR(TIMER0_OVF_vect)		// Timer0 overflow interrupt handler sine wave
{
//update the new OCR0 value to update the new duty cycle from the sin_table
	static int i=0;
	OCR0=sin_table[i];
    i++;
	if(i==256){
		i=0;
	}
}