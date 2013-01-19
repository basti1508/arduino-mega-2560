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

int main(void)
{

	// Init Display
	_delay_ms(200);
	tc1602A_Init();

	// Mainloop
	while(1)
	{
		tc1602A_putc('B');
		tc1602A_putc('l');
		tc1602A_putc('a');
		tc1602A_putc('F');
		tc1602A_putc('o');
		tc1602A_putc('o');

		_delay_ms(1000);
	}	


	// Never reached
	return (0);
}
