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

#include "board.h"
#include "pwm.h"


void pwm_write(const uint8_t pin, uint8_t val)
{
	switch(pin)
	{
		case 2:
			// PWM2
			TCCR3A |= (1 << COM3B1);
			OCR3B = val;
			break;
		case 3:
			// PWM3
			TCCR3A |= (1 << COM3C1);
			OCR3C = val;
			break;
		case 4:
			// PWM4
			TCCR0A |= (1 << COM0B1);
			OCR0B = val;
			break;
		case 5:
			// PWM5
			TCCR3A |= (1 << COM3A1);
			OCR3A = val;
			break;
		case 6:
			// PWM6
			TCCR4A |= (1 << COM4A1);
			OCR4A = val;
			break;
		case 7:
			// PWM7
			TCCR4A |= (1 << COM4B1);
			OCR4B = val;
			break;
		case 8:
			// PWM8
			TCCR4A |= (1 << COM4C1);
			OCR4C = val;
			break;
		case 9:
			// PWM9
			TCCR2A |= (1 << COM2B1);
			OCR2B = val;
			break;
		case 1:
			// PWM1
			TCCR2A |= (1 << COM2A1);
			OCR2A = val;
			break;
		case 11:
			// PWM11
			TCCR1A |= (1 << COM1A1);
			OCR1A = val;
			break;
		case 12:
			// PWM12
			TCCR1A |= (1 << COM1B1);
			OCR1B = val;
			break;
		case 13:
			// PWM13
			TCCR0A |= (1 << COM0A1);
			OCR0A = val;
			break;
		case 44:
			// D44
			TCCR5A |= (1 << COM5C1);
			OCR5C = val;
			break;
		case 45:
			// D45
			TCCR5A |= (1 << COM5B1);
			OCR5B = val;
			break;
		case 46:
			// D46
			TCCR5A |= (1 << COM5A1);
			OCR5A = val;
			break;
	}
};


