/*
 * uno_def.h
 *
 * Created: 11.06.2021 12:04:54
 *  Author: LD
 */ 


#ifndef UNO_DEF_H_
#define UNO_DEF_H_

#include "glob_def.h"
#include <util/setbaud.h>

// LED
#define LED P13
#define _LED _P13
#define __LED __P13
#define _LED_ _P13_

// Pins
#define A0 PORTC0
#define A1 PORTC1
#define A2 PORTC2
#define A3 PORTC3
#define A4 PORTC4
#define A5 PORTC5

#define P13 PORTB5
#define P12 PORTB4
#define P11 PORTB3
#define P10 PORTB2
#define P9 PORTB1
#define P8 PORTB0
#define P7 PORTD7
#define P6 PORTD6
#define P5 PORTD5
#define P4 PORTD4
#define P3 PORTD3
#define P2 PORTD2
#define P1 PORTD1
#define P0 PORTD0

// Port
#define _A0 PORTC
#define _A1 PORTC
#define _A2 PORTC
#define _A3 PORTC
#define _A4 PORTC
#define _A5 PORTC

#define _P13 PORTB
#define _P12 PORTB
#define _P11 PORTB
#define _P10 PORTB
#define _P9 PORTB
#define _P8 PORTB
#define _P7 PORTD
#define _P6 PORTD
#define _P5 PORTD
#define _P4 PORTD
#define _P3 PORTD
#define _P2 PORTD
#define _P1 PORTD
#define _P0 PORTD

// Pin
#define __A0 PINC
#define __A1 PINC
#define __A2 PINC
#define __A3 PINC
#define __A4 PINC
#define __A5 PINC

#define __P13 PINB
#define __P12 PINB
#define __P11 PINB
#define __P10 PINB
#define __P9 PINB
#define __P8 PINB
#define __P7 PIND
#define __P6 PIND
#define __P5 PIND
#define __P4 PIND
#define __P3 PIND
#define __P2 PIND
#define __P1 PIND
#define __P0 PIND

// DDR
#define _A0_ DDRC
#define _A1_ DDRC
#define _A2_ DDRC
#define _A3_ DDRC
#define _A4_ DDRC
#define _A5_ DDRC

#define _P13_ DDRB
#define _P12_ DDRB
#define _P11_ DDRB
#define _P10_ DDRB
#define _P9_ DDRB
#define _P8_ DDRB
#define _P7_ DDRD
#define _P6_ DDRD
#define _P5_ DDRD
#define _P4_ DDRD
#define _P3_ DDRD
#define _P2_ DDRD
#define _P1_ DDRD
#define _P0_ DDRD

#define USART_READY _GET(UCSR0A, UDRE0)
#define USART_RECIVE_COMPLETE _GET(UCSR0A, RXC0)
#define USART_RECIVE_ENABLE() _ON(UCSR0B, RXEN0)
#define USART_RECIVE_DISABLE() _OFF(UCSR0B, RXEN0)
#define USART_TRANSMIT_COMPLETE _GET(UCSR0A, TXC0)
#define USART_TRANSMIT_ENABLE() _ON(UCSR0B, TXEN0)
#define USART_TRANSMIT_DISABLE() _OFF(UCSR0B, TXEN0)

#define USART_ENABLE_INT_RX() _ON(UCSR0B, RXCIE0)
#define USART_ENABLE_INT_TX() _ON(UCSR0B, TXCIE0)
#define USART_ENABLE_INT_UDR() _ON(UCSR0B, UDRIE0)

typedef enum 
{
	DISABLED,
	EVEN,
	ODD
} USART_PARITY;
	
typedef enum 
{
	ONE = 0,
	TWO = 1
} USART_STOP_BIT;

typedef enum 
{
	ASYNC = 0,
	SYNC = 1
} USART_MODE;

typedef enum 
{
	BIT5,
	BIT6,
	BIT7,
	BIT8,
	BIT9
} USART_CHAR_SIZE;

void usart_std_init();
void usart_init(USART_MODE _mode, USART_CHAR_SIZE _charsize, USART_STOP_BIT _stopbit, USART_PARITY _parity);
char usart_getc();
char usart_getc_ifready();
void usart_setc(char c);
void usart_setc_ifready(char c);

#endif /* UNO_DEF_H_ */