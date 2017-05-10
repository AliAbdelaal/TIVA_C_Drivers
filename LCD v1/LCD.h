//@author : Ali Abdelaal 09/09/16

/**	this driver is for Hitachi HD44780 LCD 16x2
	runs in 4 bit operation , 2 line , and 5x7 pixels mode 
	depend on the time delay to wait for the lcd to finish it's process
	
	NOTE :: this driver needs GPIO driver 
	**/
/*
	NOTE :: this driver use delay , so that the lcd has enough time to finish its processes
	NOTE :: this driver depend on the crystal speed of your MCU , and it is set to 16Mhz in this driver
	if you changed your crystal speed you'll have to change the delay functions (both the millis and micros) 
	for the driver to work just fine
*/

/*
	How to use this driver 
	1.	configure the pins of your LCD in the configuration part , please note that your data pins must be adjacent and 
		for now they have to be in the most 4 pins of the port AKA thier mask will be 0xF0 
	2.	call the initialization function ( initialize the lcd pins(based on your choice in the configuration part) and mode )
	3.	call any function you'd like to use
*/

#ifndef _LCD_H_
#define _LCD_H_


//important libraries
#include "GPIO.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>


//configure your LCD pins here

#define DATA_PORT	PORTB
#define CMD_PORT	PORTB
#define RS_PIN		0x00
#define RW_PIN		0x01
#define EN_PIN		0x02
#define DATA_MASK	0xF0

//initialize the LCD pins and mode 
void LCD_init(void);
//clear the LCD
void LCD_clearScreen(void);
//go to x (horizontal) and y (vertical)
void LCD_gotoxy(uint8_t x , uint8_t y);
//shift the whole display left
void LCD_shiftDisplayLeft(void);
//shift the whole display right
void LCD_shiftDisplayRight(void);
//display a char on the LCD
void LCD_displayChar(char character);
//display a string on the LCD
void LCD_displayString(char* string);
//display an integer on the screen (maximume is 5 digits)
void LCD_displayInt(int decimal);
//display a float number on the screen (maximume is 5 digits)
void LCD_displayFloat(float number);






#endif
