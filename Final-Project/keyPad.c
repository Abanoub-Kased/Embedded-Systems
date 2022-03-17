#include "keyPad.h"
	    
int scan_keypad(){
	
	kp_out_port=scan_Row1;
	_delay_ms(10);
	if(kp_in_port==check_in_1_5_9_13) return 1;
	if(kp_in_port==check_in_2_6_10_14) return 2;
	if(kp_in_port==check_in_3_7_11_15) return 3;
	if(kp_in_port==check_in_4_8_12_16) return 4;
	
	kp_out_port=scan_Row2;
	_delay_ms(10);
	if(kp_in_port==check_in_1_5_9_13) return 5;
	if(kp_in_port==check_in_2_6_10_14) return 6;
	if(kp_in_port==check_in_3_7_11_15) return 7;
	if(kp_in_port==check_in_4_8_12_16) return 8;
	
	kp_out_port=scan_Row3;
	_delay_ms(10);
	if(kp_in_port==check_in_1_5_9_13) return 9;
	if(kp_in_port==check_in_2_6_10_14) return 10;
	if(kp_in_port==check_in_3_7_11_15) return 11;
	if(kp_in_port==check_in_4_8_12_16) return 12;
	
	kp_out_port=scan_Row4;
	_delay_ms(10);
	if(kp_in_port==check_in_1_5_9_13) return 13;
	if(kp_in_port==check_in_2_6_10_14) return 14;
	if(kp_in_port==check_in_3_7_11_15) return 15;
	if(kp_in_port==check_in_4_8_12_16) return 16;
	
	return 0;
}

