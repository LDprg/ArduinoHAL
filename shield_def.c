/*
 * shield_def.c
 *
 * Created: 12.10.2021 15:25:03
 *  Author: LD
 */ 
#include "shield_def.h"
#include "glob_def.h"

#include <avr/io.h>

// 7 Seg. def
/* Segment byte maps for numbers 0 to F */
const byte SEGMENT_MAP[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0X80,0X90,0x88,0x83,0xC6,0xA1,0x86, 0x8E};
/* Byte maps to select digit 1 to 4 */
const byte SEGMENT_SELECT[] = {0xF8,0xF4,0xF2,0xF1};

void seg_show(byte select, byte data){
	_seg_show(SEGMENT_SELECT[select], SEGMENT_MAP[data]);
}

void seg_show_dot(byte select, byte data, bool dot){
	byte map = SEGMENT_MAP[data];
	_SET(!dot, map, 7);
	_seg_show(SEGMENT_SELECT[select], map);
}

void _seg_show(byte sel, byte map){
	OFF(LATCH_DIO);
	
	for(int i = 0; i < 8; i++)
	{
		SET((map & (1 << (7 - i))),DATA_DIO);
		
		ON(CLK_DIO);
		OFF(CLK_DIO);
	}
	
	for(int i = 0; i < 8; i++)
	{
		SET((sel & (1 << (7 - i))),DATA_DIO);
		
		ON(CLK_DIO);
		OFF(CLK_DIO);
	}
	
	ON(LATCH_DIO);
}