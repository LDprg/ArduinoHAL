/*
 * uno_def.c
 *
 * Created: 18.12.2021 11:56:46
 *  Author: LD
 */ 
#include "uno_def.h"
#include <avr/io.h>
#include <limits.h>

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
		case BIT5:
			break;
		case BIT6:
			_ON(UCSR0C, UCSZ00);
			break;
		case BIT9:
			_ON(UCSR0C, UCSZ02);
		default:
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

void usart_setstr(char *str)
{
	while(*str)
		usart_setc(*str++);
}

void usart_setint(int i, BASE base)
{	
	int size = 0;
	int rev = 0;
	while (i != 0) {
		rev = rev * base + i % base;
		i /= base;
		++size;
	}
	
	for(;size>0;--size)
	{
		usart_setc((rev%base)+'0');
		rev/=base;
	}
}
void usart_win_cursor(bool on)
{
	if(on)
		usart_setstr("\e[?25h");
	else
		usart_setstr("\e[?25l");
}

void i2c_init(unsigned long clock, bool pullup)
{
	TWBR = ((F_CPU/clock) - 16)/2;
	
	INPUT(A5);
	INPUT(A4);
	
	if(pullup)
	{		
		ON(A5);
		ON(A4);
	}
	else
	{
		OFF(A5);
		OFF(A4);
	}
}

void i2c_twi_start()
{
	 TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	 while (!(TWCR & (1<<TWINT)));
}

void i2c_twi_tx(uint8_t data, I2C_ACK ack)
{
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	if (ack) TWCR |= (1<<TWEA);
	while (!(TWCR & (1<<TWINT)));
}

void i2c_twi_tx16(uint16_t data, I2C_ACK ack)
{
	i2c_twi_tx(data>>8, NACK);
	i2c_twi_tx((uint8_t)data, NACK);
}

uint8_t i2c_twi_rx(I2C_ACK ack)
{
	TWCR = (1<<TWINT)|(1<<TWEN);
	if (ack) TWCR |= (1<<TWEA);
	while (!(TWCR & (1<<TWINT)));
	return TWDR;
}

void i2c_twi_stop()
{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void i2c_tx(uint8_t address, uint8_t data, I2C_ACK ack)
{
	i2c_twi_start();
	
	//address &= 0b00000001 & WRITE;
	
	i2c_twi_tx(address, ACK);
	i2c_twi_tx(data, ack);
	
	i2c_twi_stop();
}

uint8_t i2c_rx(uint8_t address, I2C_ACK ack)
{
	uint8_t data = 0;
	i2c_twi_start();
	
	//address &= 0b00000001 & READ;
	
	i2c_twi_tx(address, ACK);
	data = i2c_twi_rx(ack);
	
	i2c_twi_stop();
	return data;
}

void i2c_tx16(uint8_t address, uint16_t data, I2C_ACK ack)
{
	i2c_twi_start();
	
	//address &= 0b00000001 & WRITE;
	
	i2c_twi_tx(data>>8, NACK);
	i2c_twi_tx((uint8_t)data, NACK);
	
	i2c_twi_stop();
}