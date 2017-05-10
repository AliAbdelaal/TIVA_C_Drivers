//@author : Ali Abdelaal 17/09/16

/*this driver is for TIVA-C kit 
	the driver is used to initialize , output and take input from a GPIO pin */
	
/*this driver is for the TM4C123GH6PM*/

/*NOTE that the kit has PORT A,B,C,D,E and F
	each port has 8 pins , except for port E and F 
	Port E has 6 bits , PORT F has 5 bits
*/

#ifndef	_GPIO_H_
#define _GPIO_H_

//the needed libraries
#include "TM4C123GH6PM.h"
#include <stdint.h>



//define our ports for simplification

#define PORTA		0x00
#define PORTB		0x01
#define PORTC		0x02
#define PORTD		0x03
#define PORTE		0x04
#define PORTF		0x05

//additional macros

#define HIGH			0xFF
#define LOW				0x00
#define INPUT 		LOW
#define OUTPUT 		HIGH
#define PULLUP		HIGH
#define PULLDN		LOW
#define NONE 			0x03

//functions prototype

void 	GPIO_init	(uint8_t port , uint8_t mask , uint8_t state , uint8_t pullResistor);
void 	GPIO_write	(uint8_t port , uint8_t mask , uint8_t state );
uint8_t	GPIO_read 	(uint8_t port , uint8_t mask);





#endif
