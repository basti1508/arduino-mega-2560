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

#ifndef __TC1602A_H_
#define __TC1602A_H_


/*
 * TC1602A - Display addresses
 *
 *   ,--------------------------------------~//~------.
 *   | Char  |  1  |  2  |  3  |  4  |  5  |    | 16  |
 *   |--------------------------------------~//~------|
 *   | Line1 | x00 | x01 | x02 | x03 | x04 |    | x0F |
 *   |--------------------------------------~//~------|
 *   | Line2 | x40 | x41 | x42 | x42 | x44 |    | x4F |
 *   `--------------------------------------~//~------'
 *
 */

/*
 * Circuitry
 *
 *			TC1602A
 *  
 * ,____________________________________________________________________________________.
 * | ,________________________________________________________________________________. |
 * | |										      | |
 * | |										      | |
 * | |										      | |
 * | `________________________________________________________________________________' |
 * `______________________________.__.__.__.__.__.__.__.__.__.__.__.__.__.__.__.________'
 *				  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
 *				  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
 *				  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
 *				  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
 *				  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  `----- VSS 
 *				  |  |  |  |  |  |  |  |  |  |  |  |  |  |  `-------- VDD
 *				  |  |  |  |  |  |  |  |  |  |  |  |  |  `----------- V0
 *				  |  |  |  |  |  |  |  |  |  |  |  |  `-------------- RS
 *				  |  |  |  |  |  |  |  |  |  |  |  `----------------- R/W
 *				  |  |  |  |  |  |  |  |  |  |  `-------------------- E
 *				  |  |  |  |  |  |  |  |  |  `----------------------- DB0
 *				  |  |  |  |  |  |  |  |  `-------------------------- DB1
 *				  |  |  |  |  |  |  |  `----------------------------- DB2
 *				  |  |  |  |  |  |  `-------------------------------- DB3
 *				  |  |  |  |  |  `----------------------------------- DB4
 *				  |  |  |  |  `-------------------------------------- DB5
 *				  |  |  |  `----------------------------------------- DB6
 *				  |  |  `-------------------------------------------- DB7
 *				  |  `----------------------------------------------- LED+
 *				  `-------------------------------------------------- LED-
 *
 *
 */

#define TC1602A_LINE1_START 0x80
#define TC1602A_LINE2_START 0xC0

/*
 * TC16902A - Connection
 *
 * LCD PORTS  | AVR PORTS     | ARDUINO PORTS
 * -----------------------------------------------
 * DB7	-->	PORTA-7	  --> 	29
 * DB6	-->	PORTA-6	  --> 	28
 * DB5	-->	PORTA-5	  --> 	27
 * DB4	-->	PORTA-4	  --> 	26
 * E 	-->	PORTA-3   -->   25
 * RS	--> 	PORTA-2   -->   24
 *
 * N/A	-->	PORTA-1   -->   23
 * N/A	-->	PORTA-0   -->   22
 *
 */

// Commands D=Data pins   --   C=Control pins
#define TC1602A_CLEAR 0x01
#define TC1602A_HOME 0x02
#define TC1602A_ENTRY_MODE_AUTO_RIGHT 0x07
#define TC1602A_ENTRY_MODE_AUTO_LEFT 0x05
#define TC1602A_ON  0x0C
#define TC1602A_OFF 0x08
#define TC1602A_FUNCTION_SET 0x28

// PIN --> PORT Mapping
#define TC1602A_E 3 
#define TC1602A_RS 2
#define TC1602A_DB7 7
#define TC1602A_DB6 6
#define TC1602A_DB5 5
#define TC1602A_DB4 4

int tc1602A_Init(void);
void tc1602A_cmd(char cmd);
void tc1602A_putc(char cmd);
void tc1602A_send(char data);

#endif // __TC1602A_H_
