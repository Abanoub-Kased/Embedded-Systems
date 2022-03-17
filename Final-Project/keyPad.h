#ifndef keyPad
#define keyPad
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define kp_out_port PORTC
#define kp_in_port PIND

#define scan_Row1 0b11100000
#define scan_Row2 0b11010000
#define scan_Row3 0b10110000
#define scan_Row4 0b01110000

#define  check_in_1_5_9_13 0b11100000
#define  check_in_2_6_10_14 0b11010000
#define  check_in_3_7_11_15 0b10110000
#define  check_in_4_8_12_16 0b01110000

int scan_keypad();

#endif