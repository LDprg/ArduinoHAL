/*
 * uno_def.c
 *
 * Created: 18.12.2021 11:56:46
 *  Author: LD
 */ 
#include "uno_def.h"
#include <avr/io.h>

void usart_std_init()
{
	UBRR0 = UBRR_VALUE;	
		
	USART_TRANSMIT_ENABLE();
	USART_RECIVE_ENABLE();
	
	_ON(UCSR0C, UCSZ01);
	_ON(UCSR0C, UCSZ00);
}

void usart_init(USART_MODE _mode, USART_CHAR_SIZE _charsize, USART_STOP_BIT _stopbit, USART_PARITY _parity)
{
	UBRR0 = UBRR_VALUE;
	
	USART_TRANSMIT_ENABLE();
	USART_RECIVE_ENABLE();
	
	_SET(_mode,UCSR0C, UMSEL00);
	_SET(_stopbit,UCSR0C, USBS0);
	
	switch(_charsize)
	{
		default:
		case BIT5:
			break;
		case BIT6:
			_ON(UCSR0C, UCSZ00);
			break;
		case BIT9:
			_ON(UCSR0C, UCSZ02);
		case BIT8:
			_ON(UCSR0C, UCSZ00);
		case BIT7:
			_ON(UCSR0C, UCSZ01);	
			break;
	}	
	
	switch(_parity)
	{
		default:
		case DISABLED:
			break;
		case EVEN:
			_ON(UCSR0C, UPM00);
		case ODD:
			_ON(UCSR0C, UPM01);
			break;
	}
	
	_ON(UCSR0C, UCSZ01);
	_ON(UCSR0C, UCSZ00);
}

char usart_getc()
{
	while(USART_RECIVE_COMPLETE);
	return UDR0;	
}

char usart_getc_ifready()
{
	if(!USART_RECIVE_COMPLETE)
		return UDR0;
	else
		return 0;
}

void usart_setc(char c)
{
	while(USART_READY);	
	UDR0 = c;
}

void usart_setc_ifready(char c)
{
	if(!USART_READY)
		UDR0 = c;
}
