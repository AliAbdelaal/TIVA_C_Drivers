//@author : Ali Abdelaal 17/09/16


/*
	>>this driver is made for keypad of maximume size of (8x8)
	>>this driver support cols and rows at different ports 
	>>the driver handles debounce 
	>>the driver depend on the pins of the rows and cols are adjacent , and connected ascedingly
	meaning that the row 0 pin will be the first pin in the mask , for example
		if keypad is connected to mask 0x0f of port A , then bit 0x01 is the row 1 pin , and so on
	>>the driver have a delay function to handle the debounce 
	>>if you press and hold on the button it will return that button many times

	>>How to use<<
	>>first, 	declare size of your keypad in KEYPAD_ROWS_NUM and KEYPAD_COLS_NUM
	>>second, 	modify the KEYPAD_MAP in the C file to match your needs
	>>third, 	specify the ports where the cols and rows are connected in KEYPAD_ROWS_PORT and KEYPAD_COLS_PORT
	>>fourth, 	specify the mask of the rows and cols in KEYPAD_ROWS_MASK and KEYPAD_COLS_MASK
	>>fifth, 	call KEYPAD_init() pefore you use the keypad
	>>sixth,	use KEYPAD_read() to get the pressed key , or KEYPAD_pressed() to get 0xFF if any key pressed or 0x00 if not
	
	>>important notes<<
	>>this driver needs GPIO driver 
	>>this driver depend on a 16Mhz MCU , if u changed the clock , change delayMs in the C file
*/



#ifndef _KEYPAD_H_
#define _KEYPAD_H_


//important libs
#include "GPIO.h"
#include <stdint.h>


#define KEYPAD_ROWS_NUM		0x04
#define KEYPAD_COLS_NUM		0x03
#define KEYPAD_ROWS_PORT	PORTD
#define KEYPAD_COLS_PORT	PORTE
#define KEYPAD_ROWS_MASK	0x0F
#define KEYPAD_COLS_MASK	0x0E




void 	KEYPAD_init(void);
uint8_t KEYPAD_read(void);
uint8_t KEYPAD_pressed(void);




#endif
