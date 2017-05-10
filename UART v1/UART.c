//@author : Ali Abdelaal 18/09/16

#include "UART.h"

void delayMs(int n);



void 	UART_init( uint8_t uartChannel , uint32_t buadRate , uint8_t dataBits)
{
	uint16_t dummyInt = 0x00 ;
	volatile double dummyDouble = 0.00f ;
	/*
		>>>steps to initial the uart<<<
		>>provide clock to the uart channel
		>>provide clock to the TX and RX port
		>>disable the uart during initializing in UARTCTL
		>>write the integer portion of the buad rate at UARTIBRD
		>>write the fraction portion of the buad rate at UARTFBRD
		>>configure the uart clock in this driver the system clock is used via UARTCC
		>>configure the data frame in UARTLCRH
		>>enable the transmitter and receiver in UARTCTL
		>>enable the uart in UARTCTL
		>>enable the Rx and TX pins as digital pins in GPIOX->DEN
		>>select alternative functionality in GPIOX->AFSEL
		>>disable the analog functionality if any in GPIOX->AMSEL
		>>select the uart functionality GPIOX->PCTL
	*/
	switch(uartChannel)
	{
		case UART_0 :
		//PA0 and PA1
		SYSCTL->RCGCUART |= 0x01 ;											//enable clock for the uart it self 
		SYSCTL->RCGCGPIO |= 0x01 ;											//enable clock for the TX,RX port 
		UART0->CTL &= ~0x01 ;												//disable uart 
		dummyInt = (uint16_t)(1000000UL/buadRate) ;							//calculate the integer part
		UART0->IBRD = dummyInt ;
		dummyDouble = (1000000.0/buadRate) ;
		dummyDouble = dummyDouble - dummyInt ;
		UART0->FBRD = (uint8_t)((dummyDouble*64)+0.5) ;						//calculate the fraction part
		UART0->CC = 0x00 ;													//set the clock source (the system clock-16Mhz-)
		switch(dataBits)													//set the databits
		{
			case 5:
			UART0->LCRH = 0x00 ;
			break;
			case 6:
			UART0->LCRH = 0x20 ;
			break;
			case 7:
			UART0->LCRH = 0x40 ;
			break;
			case 8:
			UART0->LCRH = 0x60 ;
			break;
		}
		UART0->CTL |= (1<<8) | (1<<9) ;										//enable the TX and RX
		UART0->CTL |= 0x01 ;												//enable UART
		//the RX and TX configurations
		GPIOA->DEN 	|= 0x03 ;												//enable the digital pins 
		GPIOA->AFSEL|= 0x03 ;												//enable the alternative function
		GPIOA->PCTL |= 0x11 ;												//configure pins to be uart 
		break ;


		case UART_1 :
		//PB0 and PB1
		SYSCTL->RCGCUART |= 0x02 ;											//enable clock for the uart it self 
		SYSCTL->RCGCGPIO |= 0x02 ;											//enable clock for the TX,RX port 
		UART1->CTL &= ~0x01 ;												//disable uart 
		dummyInt = (uint16_t)(1000000UL/buadRate) ;							//calculate the integer part
		UART1->IBRD = dummyInt ;
		dummyDouble = (1000000.0/buadRate) ;
		dummyDouble = dummyDouble - dummyInt ;
		UART1->FBRD = (uint8_t)((dummyDouble*64)+0.5) ;						//calculate the fraction part
		UART1->CC = 0x00 ;													//set the clock source (the system clock-16Mhz-)
		switch(dataBits)													//set the databits
		{
			case 5:
			UART1->LCRH = 0x00 ;
			break;
			case 6:
			UART1->LCRH = 0x20 ;
			break;
			case 7:
			UART1->LCRH = 0x40 ;
			break;
			case 8:
			UART1->LCRH = 0x60 ;
			break;
		}
		UART1->CTL |= (1<<8) | (1<<9) ;										//enable the TX and RX
		UART1->CTL |= 0x01 ;												//enable UART
		//the RX and TX configurations
		GPIOB->DEN 	 |= 0x03 ;												//enable the digital pins 
		GPIOB->AFSEL |= 0x03 ;												//enable the alternative function
		GPIOB->AMSEL &= 0x00 ;												//disable analog functionality
		GPIOB->PCTL  	= 0x11 ;												//configure pins to be uart 
		break ;


		case UART_2 :
		//PD6 and PD7
		SYSCTL->RCGCUART |= 1<<2 ;											//enable clock for the uart it self 
		SYSCTL->RCGCGPIO |= 1<<3 ;											//enable clock for the TX,RX port 
		UART2->CTL &= ~0x01 ;												//disable uart 
		dummyInt = (uint16_t)(1000000UL/buadRate) ;							//calculate the integer part
		UART2->IBRD = dummyInt ;
		dummyDouble = (1000000.0/buadRate) ;
		dummyDouble = dummyDouble - dummyInt ;
		UART2->FBRD = (uint8_t)((dummyDouble*64)+0.5) ;						//calculate the fraction part
		UART2->CC = 0x00 ;													//set the clock source (the system clock-16Mhz-)
		switch(dataBits)													//set the databits
		{
			case 5:
			UART2->LCRH = 0x00 ;
			break;
			case 6:
			UART2->LCRH = 0x20 ;
			break;
			case 7:
			UART2->LCRH = 0x40 ;
			break;
			case 8:
			UART2->LCRH = 0x60 ;
			break;
		}
		UART2->CTL |= (1<<8) | (1<<9) ;										//enable the TX and RX
		UART2->CTL |= 0x01 ;												//enable UART
		//the RX and TX configurations
		GPIOD->DEN 	 |= (1<<6) | (1<<7) ;									//enable the digital pins 
		GPIOD->AFSEL |= (1<<6) | (1<<7) ;									//enable the alternative function
		GPIOD->AMSEL &= 0x00 ;												//disable analog functionality
		GPIOD->PCTL  |= (1<<24) | (1<<28) ;									//configure pins to be uart 	
		break ;


		case UART_3 :
		//PC6 and PC7
		SYSCTL->RCGCUART |= 1<<3 ;											//enable clock for the uart it self 
		SYSCTL->RCGCGPIO |= 1<<2 ;											//enable clock for the TX,RX port 
		UART3->CTL &= ~0x01 ;												//disable uart 
		dummyInt = (uint16_t)(1000000UL/buadRate) ;							//calculate the integer part
		UART3->IBRD = dummyInt ;
		dummyDouble = (1000000.0/buadRate) ;
		dummyDouble = dummyDouble - dummyInt ;
		UART3->FBRD = (uint8_t)((dummyDouble*64)+0.5) ;						//calculate the fraction part
		UART3->CC = 0x00 ;													//set the clock source (the system clock-16Mhz-)
		switch(dataBits)													//set the databits
		{
			case 5:
			UART3->LCRH = 0x00 ;
			break;
			case 6:
			UART3->LCRH = 0x20 ;
			break;
			case 7:
			UART3->LCRH = 0x40 ;
			break;
			case 8:
			UART3->LCRH = 0x60 ;
			break;
		}
		UART3->CTL |= (1<<8) | (1<<9) ;										//enable the TX and RX
		UART3->CTL |= 0x01 ;												//enable UART
		//the RX and TX configurations
		GPIOC->DEN 	 |= (1<<6) | (1<<7) ;									//enable the digital pins 
		GPIOC->AFSEL |= (1<<6) | (1<<7) ;									//enable the alternative function
		GPIOC->AMSEL &= 0x00 ;												//disable analog functionality
		GPIOC->PCTL  |= (1<<24) | (1<<28) ;									//configure pins to be uart 	
		break ;


		case UART_4 :
		//PC4 and PC5
		SYSCTL->RCGCUART |= 1<<4 ;											//enable clock for the uart it self 
		SYSCTL->RCGCGPIO |= 1<<2 ;											//enable clock for the TX,RX port 
		UART4->CTL &= ~0x01 ;												//disable uart 
		dummyInt = (uint16_t)(1000000UL/buadRate) ;							//calculate the integer part
		UART4->IBRD = dummyInt ;
		dummyDouble = (1000000.0/buadRate) ;
		dummyDouble = dummyDouble - dummyInt ;
		UART4->FBRD = (uint8_t)((dummyDouble*64)+0.5) ;						//calculate the fraction part
		UART4->CC = 0x00 ;													//set the clock source (the system clock-16Mhz-)
		switch(dataBits)													//set the databits
		{
			case 5:
			UART4->LCRH = 0x00 ;
			break;
			case 6:
			UART4->LCRH = 0x20 ;
			break;
			case 7:
			UART4->LCRH = 0x40 ;
			break;
			case 8:
			UART4->LCRH = 0x60 ;
			break;
		}
		UART4->CTL |= (1<<8) | (1<<9) ;										//enable the TX and RX
		UART4->CTL |= 0x01 ;												//enable UART
		//the RX and TX configurations
		GPIOC->DEN 	 |= (1<<4) | (1<<5) ;									//enable the digital pins 
		GPIOC->AFSEL |= (1<<4) | (1<<5) ;									//enable the alternative function
		GPIOC->AMSEL &= 0x00 ;												//disable analog functionality
		GPIOC->PCTL  |= (1<<16) | (1<<20) ;									//configure pins to be uart 	
		break ;


		case UART_5 :
		//PE4 and PE5
		SYSCTL->RCGCUART |= 1<<5 ;											//enable clock for the uart it self 
		SYSCTL->RCGCGPIO |= 1<<4 ;											//enable clock for the TX,RX port 
		UART5->CTL &= ~0x01 ;												//disable uart 
		dummyInt = (uint16_t)(1000000UL/buadRate) ;							//calculate the integer part
		UART5->IBRD = dummyInt ;
		dummyDouble = (1000000.0/buadRate) ;
		dummyDouble = dummyDouble - dummyInt ;
		UART5->FBRD = (uint8_t)((dummyDouble*64)+0.5) ;						//calculate the fraction part
		UART5->CC = 0x00 ;													//set the clock source (the system clock-16Mhz-)
		switch(dataBits)													//set the databits
		{
			case 5:
			UART5->LCRH = 0x00 ;
			break;
			case 6:
			UART5->LCRH = 0x20 ;
			break;
			case 7:
			UART5->LCRH = 0x40 ;
			break;
			case 8:
			UART5->LCRH = 0x60 ;
			break;
		}
		UART5->CTL |= (1<<8) | (1<<9) ;										//enable the TX and RX
		UART5->CTL |= 0x01 ;												//enable UART
		//the RX and TX configurations
		GPIOE->DEN 	 |= (1<<4) | (1<<5) ;									//enable the digital pins 
		GPIOE->AFSEL |= (1<<4) | (1<<5) ;									//enable the alternative function
		GPIOE->AMSEL &= 0x00 ;												//disable analog functionality
		GPIOE->PCTL  |= (1<<16) | (1<<20) ;									//configure pins to be uart 
		break ;


		case UART_6 :
		//PD4 and PD5
		SYSCTL->RCGCUART |= 1<<6 ;											//enable clock for the uart it self 
		SYSCTL->RCGCGPIO |= 1<<3 ;											//enable clock for the TX,RX port 
		UART6->CTL &= ~0x01 ;												//disable uart 
		dummyInt = (uint16_t)(1000000UL/buadRate) ;							//calculate the integer part
		UART6->IBRD = dummyInt ;
		dummyDouble = (1000000.0/buadRate) ;
		dummyDouble = dummyDouble - dummyInt ;
		UART6->FBRD = (uint8_t)((dummyDouble*64)+0.5) ;						//calculate the fraction part
		UART6->CC = 0x00 ;													//set the clock source (the system clock-16Mhz-)
		switch(dataBits)													//set the databits
		{
			case 5:
			UART6->LCRH = 0x00 ;
			break;
			case 6:
			UART6->LCRH = 0x20 ;
			break;
			case 7:
			UART6->LCRH = 0x40 ;
			break;
			case 8:
			UART6->LCRH = 0x60 ;
			break;
		}
		UART6->CTL |= (1<<8) | (1<<9) ;										//enable the TX and RX
		UART6->CTL |= 0x01 ;												//enable UART
		//the RX and TX configurations
		GPIOD->DEN 	 |= (1<<4) | (1<<5) ;									//enable the digital pins 
		GPIOD->AFSEL |= (1<<4) | (1<<5) ;									//enable the alternative function
		GPIOD->AMSEL &= 0x00 ;												//disable analog functionality
		GPIOD->PCTL  |= (1<<16) | (1<<20) ;									//configure pins to be uart
		break ;	


		case UART_7 :
		//PE0 and PE1
		SYSCTL->RCGCUART |= 1<<7 ;											//enable clock for the uart it self 
		SYSCTL->RCGCGPIO |= 1<<4 ;											//enable clock for the TX,RX port 
		UART7->CTL &= ~0x01 ;												//disable uart 
		dummyInt = (uint16_t)(1000000UL/buadRate) ;							//calculate the integer part
		UART7->IBRD = dummyInt ;
		dummyDouble = (1000000.0/buadRate) ;
		dummyDouble = dummyDouble - dummyInt ;
		UART7->FBRD = (uint8_t)((dummyDouble*64)+0.5) ;						//calculate the fraction part
		UART7->CC = 0x00 ;													//set the clock source (the system clock-16Mhz-)
		switch(dataBits)													//set the databits
		{
			case 5:
			UART7->LCRH = 0x00 ;
			break;
			case 6:
			UART7->LCRH = 0x20 ;
			break;
			case 7:
			UART7->LCRH = 0x40 ;
			break;
			case 8:
			UART7->LCRH = 0x60 ;
			break;
		}
		UART7->CTL |= (1<<8) | (1<<9) ;										//enable the TX and RX
		UART7->CTL |= 0x01 ;												//enable UART
		//the RX and TX configurations
		GPIOE->DEN 	 |= (1<<0) | (1<<1) ;									//enable the digital pins 
		GPIOE->AFSEL |= (1<<0) | (1<<1) ;									//enable the alternative function
		GPIOE->AMSEL &= 0x00 ;												//disable analog functionality
		GPIOE->PCTL  |= (1<<0) | (1<<4) ;									//configure pins to be uart
		break ;

	}

	delayMs(1);
}
uint8_t UART_read( uint8_t uartChannel )
{
	uint8_t readData = 0x00 ;
	/*
		>>How it works<<
		>>if the buffer is full read it 
		>>else don't  

	*/
	switch(uartChannel)
	{
		case UART_0 :
		if( (UART0->FR & (1<<6))) 
			readData = UART0->DR&0xFF ;
		break ;


		case UART_1 :
		if( (UART1->FR & (1<<6))) 
			readData = UART1->DR&0xFF ;
		break ;


		case UART_2 :
		if( (UART2->FR & (1<<6))) 
			readData = UART2->DR&0xFF ;
		break ;


		case UART_3 :
		if((UART3->FR & (1<<6))) 
			readData = UART3->DR&0xFF ;
		break ;


		case UART_4 :
		if( (UART4->FR & (1<<6))) 
			readData = UART4->DR&0xFF ;
		break ;


		case UART_5 :
		if( (UART5->FR & (1<<6))) 
			readData = UART5->DR&0xFF ;
		break ;


		case UART_6 :
		if( (UART6->FR & (1<<6))) 
			readData = UART6->DR&0xFF ;
		break ;	


		case UART_7 :
		if( (UART7->FR & (1<<6))) 
			readData = UART7->DR&0xFF ;
		break ;
	}
	return readData ;
}
void UART_send( uint8_t uartChannel , uint8_t msg)
{
	/*
		>>How it works<<
		>>wait till the buffer is not full
		>>send the char to the buffer 
	*/
	switch(uartChannel)
	{
		case UART_0 :
		while( !(UART0->FR&(1<<7)));	//wait till the buffer is empty
		UART0->DR = msg  ;				//send the msg
		break ;
		case UART_1 :
		while( !(UART1->FR&(1<<7)) );	//wait till the buffer is empty
		UART1->DR = msg  ;				//send the msg
		break ;
		case UART_2 :
		while( !(UART2->FR&(1<<7)) );	//wait till the buffer is empty
		UART2->DR = msg  ;				//send the msg
		break ;
		case UART_3 :
		while( !(UART3->FR&(1<<7)) );	//wait till the buffer is empty
		UART3->DR = msg  ;				//send the msg
		break ;
		case UART_4 :
		while( !(UART4->FR&(1<<7)) );	//wait till the buffer is empty
		UART4->DR = msg  ;				//send the msg
		break ;
		case UART_5 :
		while( !(UART5->FR&(1<<7)) );	//wait till the buffer is empty
		UART5->DR = msg  ;				//send the msg
		break ;
		case UART_6 :
		while( !(UART6->FR&(1<<7)) );	//wait till the buffer is empty
		UART6->DR = msg  ;				//send the msg
		break ;	
		case UART_7 :
		while( !(UART7->FR&(1<<7)) );	//wait till the buffer is empty
		UART7->DR = msg  ;				//send the msg
		break ;	
	}
}

//a delay function just to make the driver wait 1ms till the line is stable 
void delayMs(int time)
{
	int i, j;
	for(i = 0 ; i < time; i++)
	for(j = 0; j < 3180; j++);
	/* do nothing for 1 ms */
}
