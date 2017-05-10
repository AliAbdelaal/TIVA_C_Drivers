//@author : Ali Abdelaal 18/09/16

/*
	>>...UART driver for TM4C123GH6PM...<<
	>>this driver needs GPIO driver 
	>>this driver has a delay function that depends on the crystal (16Mhz in this driver case)
	>>this driver support different buad rates ,different databits (5,6,7,8)
	>>this driver based on flags (not interrupt)
	>>the send function is a blocking function , the code won't complete untill the data is sent
	>>the FIFO is disabled in this driver (character mode)
	>>the read function is a non blocking function , it will read what it find or it will return zero if the buffer is empty
	>>no parity support , and a fixed 1 stop bit frame 
	>>UART pins:
		>>UART0 : TX>>PA1	RX>>PA0
		>>UART1 : TX>>PB1	RX>>PB0
		>>UART2 : TX>>PD7	RX>>PD6
		>>UART3 : TX>>PC7	RX>>PC6
		>>UART4 : TX>>PC5	RX>>PC4
		>>UART5 : TX>>PE5	RX>>PE4
		>>UART6 : TX>>PD5	RX>>PD4
		>>UART7 : TX>>PE1	RX>>PE0
	
	>>...How to use...<<
	>>firs initialize the uart by calling UART_init(), select the channel , and the buadrate is sent as it is , (e.g)9600
	  and select the data bits (5,6,7 or 8)
	>>call the send or read function with the channel you want
	>>the send function is blocking, and won't exit untill it sends the data
	>>the read function is non blocking, it will return zero immediately if the buffer is empty, or the char in the buffer
*/




#ifndef _UART_H_
#define _UART_H_

#include "tm4c123gh6pm.h"
#include <stdint.h>



#define UART_0	0x00
#define UART_1	0x01
#define UART_2	0x02
#define UART_3	0x03
#define UART_4	0x04
#define UART_5	0x05
#define UART_6	0x06
#define UART_7	0x07


void 	UART_init( uint8_t uartChannel , uint32_t buadRate , uint8_t dataBits);
uint8_t UART_read( uint8_t uartChannel );
void UART_send( uint8_t uartChannel , uint8_t msg);

#endif
