/*
 * shield_def.h
 *
 * Created: 11.06.2021 12:09:39
 *  Author: LD
 */ 

#include "uno_def.h"
#include "glob_def.h"

#ifndef SHIELD_DEF_H_
#define SHIELD_DEF_H_

// LEDs
#define D1 P13
#define D2 P12
#define D3 P11
#define D4 P10

#define __D1 __P13
#define __D2 __P12
#define __D3 __P11
#define __D4 __P10

#define _D1 _P13
#define _D2 _P12
#define _D3 _P11
#define _D4 _P10

#define _D1_ _P13_
#define _D2_ _P12_
#define _D3_ _P11_
#define _D4_ _P10_

// Sensor, Buzzer
#define TEMP A4
#define IR P2
#define VR A0
#define LSI P3

#define __TEMP __A4
#define __IR __P2
#define __VR __A0
#define __LSI __P3

#define _TEMP _A4
#define _IR _P2
#define _VR _A0
#define _LSI _P3

#define _TEMP_ _A4_
#define _IR_ _P2_
#define _VR_ _A0_
#define _LSI_ _P3_

// 7 Seg. Pins
#define LATCH_DIO P4
#define CLK_DIO P7
#define DATA_DIO P8

#define __LATCH_DIO __P4
#define __CLK_DIO __P7
#define __DATA_DIO __P8

#define _LATCH_DIO _P4
#define _CLK_DIO _P7
#define _DATA_DIO _P8

#define _LATCH_DIO_ _P4_
#define _CLK_DIO_ _P7_
#define _DATA_DIO_ _P8_

// Buttons
#define S1 A1
#define S2 A2
#define S3 A3

#define __S1 __A1
#define __S2 __A2
#define __S3 __A3

#define _S1 _A1
#define _S2 _A2
#define _S3 _A3

#define _S1_ _A1_
#define _S2_ _A2_
#define _S3_ _A3_

extern const byte SEGMENT_MAP[];
extern const byte SEGMENT_SELECT[];

void _seg_show(byte sel, byte map);	

void seg_show(byte select, byte data);

void seg_show_dot(byte select, byte data, bool dot);

#endif /* SHIELD_DEF_H_ */