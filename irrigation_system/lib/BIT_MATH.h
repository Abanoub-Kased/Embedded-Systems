
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SETBIT(VAR,BIT)			VAR |= (1<<(BIT))
#define CLEARBIT(VAR,BIT)		VAR &= ~(1<<(BIT)) 
#define SETPORT(VAR,PVALUE)     VAR = PVALUE

#endif 