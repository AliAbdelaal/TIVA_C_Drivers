//@author : Ali Abdelaal 17/09/16

#include "GPIO.h"
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))


void 	GPIO_init	(uint8_t port , uint8_t mask , uint8_t state , uint8_t pullResistor)
{
	switch(port)
	{
		case PORTA :
		
		//enable the clock for the bit
		SYSCTL->RCGCGPIO |= (1<<PORTA) ;
		//set the direction
		GPIOA->DIR &= ~(mask) ;
		GPIOA->DIR |= mask&state ;
		//enable the bit 
		GPIOA->DEN |= mask ;
		//in case input and pull resistor is required 
		if(state == INPUT)
		switch(pullResistor)
		{
			case PULLUP:
			GPIOA->PUR |= mask ;
			break;
			case PULLDN:
			GPIOA->PDR  |= mask ;
			break;
			case NONE :
			break;
		}

		break;
		case PORTB :
		
		//enable the clock for the bit
		SYSCTL->RCGCGPIO |= (1<<PORTB) ;
		//set the direction
		GPIOB->DIR &= ~(mask) ;
		GPIOB->DIR |= mask&state ;
		//enable the bit 
		GPIOB->DEN |= mask ;
		//in case input and pull resistor is required
		if(state == INPUT)
		switch(pullResistor)
		{
			case PULLUP:
			GPIOB->PUR |= mask ;
			break;
			case PULLDN:
			GPIOB->PDR  |= mask ;
			break;
			case NONE :
			break;
		}

		break;
		case PORTC :

		//enable the clock for the bit
		SYSCTL->RCGCGPIO |= (1<<PORTC) ;
		//check for unlocking 
		if(mask&0x07)
		{
			GPIOC->LOCK  = 0x4C4F434B;
			GPIO_PORTF_CR_R		|= (mask&0x07);
		}
		//set the direction
		GPIOC->DIR &= ~(mask) ;
		GPIOC->DIR |= mask&state ;
		//enable the bit 
		GPIOC->DEN |= mask ;
		//in case input and pull resistor is required
		if(state == INPUT)
		switch(pullResistor)
		{
			case PULLUP:
			GPIOC->PUR |= mask ;
			break;
			case PULLDN:
			GPIOC->PDR  |= mask ;
			break;
			case NONE :
			break;
		}

		break;
		case PORTD :

		//enable the clock for the bit
		SYSCTL->RCGCGPIO |= (1<<PORTD) ;
		//check for unlocking 
		if(mask&(1<<7))
		{
			GPIOC->LOCK  = 0x4C4F434B;
			GPIO_PORTF_CR_R		|= (mask&(1<<7));
		}
		//set the direction
		GPIOD->DIR &= ~(mask) ;
		GPIOD->DIR |= mask&state ;
		//enable the bit 
		GPIOD->DEN |= mask ;
		//in case input and pull resistor is required
		if(state == INPUT)
		switch(pullResistor)
		{
			case PULLUP:
			GPIOD->PUR |= mask ;
			break;
			case PULLDN:
			GPIOD->PDR  |= mask ;
			break;
			case NONE :
			break;
		}

		break;
		case PORTE :

		//enable the clock for the bit
		SYSCTL->RCGCGPIO |= (1<<PORTE) ;
		//set the direction
		GPIOE->DIR &= ~(mask) ;
		GPIOE->DIR |= mask&state ;
		//enable the bit 
		GPIOE->DEN |= mask ;
		//in case input and pull resistor is required
		if(state == INPUT)
		switch(pullResistor)
		{
			case PULLUP:
			GPIOE->PUR |= mask ;
			break;
			case PULLDN:
			GPIOE->PDR  |= mask ;
			break;
			case NONE :
			break;
		}

		break;
		case PORTF :

		//enable the clock for the bit
		SYSCTL->RCGCGPIO |= (1<<PORTF) ;
		//check for unlocking 
		if(mask&0x01)
		{
			GPIOF->LOCK  = 0x4C4F434B;
			GPIO_PORTF_CR_R	|= (mask&0x01);
		}
		//set the direction
		GPIOF->DIR &= ~(mask) ;
		GPIOF->DIR |= mask&state ;
		//enable the bit 
		GPIOF->DEN |= mask ;
		//in case input and pull resistor is required
		if(state == INPUT)
		switch(pullResistor)
		{
			case PULLUP:
			GPIOF->PUR |= mask ;
			break;
			case PULLDN:
			GPIOF->PDR  |= mask ;
			break;
			case NONE :
			break;
		}

		break;
		
	}
}
void 	GPIO_write	(uint8_t port , uint8_t mask , uint8_t state )
{
	switch(port)
	{
		case PORTA :
		
		//write to the bit 
		GPIOA->DATA &= ~(mask);
		GPIOA->DATA |= (mask&state) ;

		break;
		case PORTB :
		
		//write to the bit 
		GPIOB->DATA &= ~(mask);
		GPIOB->DATA |= (mask&state) ;

		break;
		case PORTC :

		//write to the bit 
		GPIOC->DATA &= ~(mask);
		GPIOC->DATA |= (mask&state) ;

		break;
		case PORTD :

		//write to the bit 
		GPIOD->DATA &= ~(mask);
		GPIOD->DATA |= (mask&state) ;

		break;
		case PORTE :

		//write to the bit 
		GPIOE->DATA &= ~(mask);
		GPIOE->DATA |= (mask&state) ;

		break;
		case PORTF :

		//write to the bit 
		GPIOF->DATA &= ~(mask);
		GPIOF->DATA |= (mask&state) ;

		break;
		
	}

}

uint8_t	GPIO_read 	(uint8_t port , uint8_t mask)
{
	uint8_t read = 0x00 ;
	switch(port)
	{
		case PORTA :
		
		read = ( (GPIOA->DATA) & mask);

		break;
		case PORTB :
		
		read = ( (GPIOB->DATA) & mask);

		break;
		case PORTC :

		read = ( (GPIOC->DATA) & mask);

		break;
		case PORTD :

		read = ( (GPIOD->DATA) & mask);

		break;
		case PORTE :

		read = ( (GPIOE->DATA) & mask);

		break;
		case PORTF :

		read = ( (GPIOF->DATA) & mask);

		break;
		
	}
	return read ;
}
