/*
 * Copyright (c) 2011-2013 Sebastian Himmler
 * All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER IN
 * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <avr/io.h>
#include <util/delay.h>

#include "board.h"
#include "tc1602a.h"

int tc1602a_Init(void){

	// Set bus port as output
	DDRA = 0xFF;
	PORTA = 0x00;

	// Wait until Controller is up
	_delay_ms(50);

	// Sending inital stage
	PORTA = 0x03;
	_delay_ms(200);

	// Enable 4-bite mode
	PORTA = 0x02;

	// Send write-signal pulse
	PORTA |= (1 << TC1602A_E);
	PORTA &= ~(1 << TC1602A_E);
	_delay_ms(5);	

	// Set Display Mode ==> 2-Line / 5x8 dots
	tc1602a_cmd(TC1602A_FUNCTION_SET);
	tc1602a_cmd(TC1602A_OFF);
	tc1602a_cmd(TC1602A_CLEAR);
	tc1602a_cmd(TC1602A_ENTRY_MODE_AUTO_RIGHT);
	tc1602a_cmd(TC1602A_ON);

	return (0);
	 
}

void tc1602a_cmd(unsigned char cmd)
{
	// Delete RS bit => Command following
	PORTA &= ~(1 << TC1602A_RS);
	tc1602a_send(cmd);
}

void tc1602a_putc(unsigned char data)
{
	PORTA |= (1 << TC1602A_RS);
	tc1602a_send(data);
}

void tc1602a_puts(const char *data)
{
	unsigned char c;
	while ((c = *data++))
	{
		tc1602a_putc(c);
	}
}

void tc1602a_send(unsigned char data)
{
	// calculate current RS
	unsigned char rs = PORTA;
	rs &= 4;

	// Send High 4 bits
	unsigned char tmp = data;
	tmp &= 0xf0;
	tmp |= rs;
	PORTA = tmp;

	// Send write-signal pulse
	PORTA |= (1 << TC1602A_E);
	PORTA &= ~(1 << TC1602A_E);
	
	// Send Low 4 bits
	tmp = data;
	tmp &= 0x0f;
	tmp *= 16;
	tmp |= rs;
	PORTA = tmp;

	// Send write-signal pulse
	PORTA |= (1 << TC1602A_E);
	PORTA &= ~(1 << TC1602A_E);

	_delay_ms(1);
}
