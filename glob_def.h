/*
 * glob_def.h
 *
 * Created: 11.06.2021 12:14:11
 *  Author: LD
 */ 


#ifndef GLOB_DEF_H_
#define GLOB_DEF_H_

#include <stdbool.h>

#ifndef F_CPU
    #define F_CPU 16000000UL	// 16 MHZ
#endif /* F_CPU */

#define BIT(x) (1 << (x))

#define _ON(x, y) (x |= BIT(y))
#define _OFF(x, y) (x &= ~BIT(y))
#define _TOGGLE(x, y) (x ^= BIT(y))

#define _GET(x,y) (!(x & BIT(y)))
#define _SET(x,y,z)	if(x) _ON(y,z); else _OFF(y ,z)

#define OUTPUT(x) _ON(_ ## x ## _ ,x)
#define INPUT(x) _OFF(_ ## x ## _ ,x)

#define ON(x) _ON(_ ## x ,x)
#define OFF(x) _OFF(_ ## x,x)
#define TOGGLE(x) _TOGGLE(_ ## x ,x)

#define GET(x) _GET(__ ## x, x)
#define SET(x,y)	if(x) _ON(_ ## y,y); else _OFF(_ ## y ,y)
#define GETBIT(x,y) (((x)>>(y))%2)

typedef unsigned char byte;

#endif /* GLOB_DEF_H_ */