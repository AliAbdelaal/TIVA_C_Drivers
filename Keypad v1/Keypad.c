//@author : Ali Abdelaal 17/09/16


#include "Keypad.h"
#include "GPIO.h"

/*
	the mechanism how this driver works is that , the rows are always driven low , 
	and the coloums are inputs and driven high using a pull up resistor (the internal one)
	when a button is pressed the col reads changes , and this we begin to apply a low voltage 
	in every single row and high on the other rows , so that we can find out exaclty which 
	row is the button in , then we return the button char from the lockup table provided in
	this C file KEYPAD_MAP.
*/

//these variables to know how much the rows and the cols are shifted away from the LSB(least seg. bit)
static uint8_t row_shift = 0x00 ;
static uint8_t col_shift = 0x00 ;

const uint8_t KEYPAD_MAP[KEYPAD_ROWS_NUM][KEYPAD_COLS_NUM]={
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'},
	{'*','0','#'}
};

//function prototype for the delay 
void delayMs(int time);

void 	KEYPAD_init(void)
{
	uint8_t loopIndex = 0x00 ;
	//initial the rows as output 
	GPIO_init(KEYPAD_ROWS_PORT,KEYPAD_ROWS_MASK,OUTPUT,NONE);
	//apply low on all the rows
	GPIO_write(KEYPAD_ROWS_PORT,KEYPAD_ROWS_MASK,LOW);

	//initial the col as inputs and activiate the pull-up resistors to make them high by default
	GPIO_init(KEYPAD_COLS_PORT,KEYPAD_COLS_MASK,INPUT,PULLUP);

	//update the row and col shift
	//one for row
	for( loopIndex=0x01 ; !(loopIndex&KEYPAD_ROWS_MASK) ; loopIndex<<=1 , row_shift++) ;
	//one for col
	for( loopIndex=0x01 ; !(loopIndex&KEYPAD_COLS_MASK) ; loopIndex<<=1 , col_shift++) ;

}

//this function return the char of the key that was pressed 
uint8_t KEYPAD_read(void)
{
	uint8_t pressed_row = 0x01 , pressed_col = 0x01 ;
	uint8_t dummyMask = 0x00 , loopIndex = 0x00 ;
	if(KEYPAD_pressed())
	{
		//find the pressed col
		//store the mask of the col
		dummyMask = GPIO_read(KEYPAD_COLS_PORT,KEYPAD_COLS_MASK);
		//loop in the mask till you find that pressed col
		for(loopIndex = (1<<col_shift) ; loopIndex&dummyMask ; loopIndex <<= 1 , pressed_col++) ;

		//find the pressed row
		//turn up all the rows in order to search for the pressed one 
		GPIO_write(KEYPAD_ROWS_PORT,KEYPAD_ROWS_MASK,HIGH);
		//get the loopIndex ready
		loopIndex = (1<<row_shift) ;
		for(GPIO_write(KEYPAD_ROWS_PORT , KEYPAD_ROWS_MASK , (~loopIndex)) ; 
			GPIO_read(KEYPAD_COLS_PORT,KEYPAD_COLS_MASK) == KEYPAD_COLS_MASK ;
			loopIndex<<=1 , pressed_row++ , GPIO_write(KEYPAD_ROWS_PORT,KEYPAD_ROWS_MASK,(~loopIndex)));
		//release the rows 
		GPIO_write(KEYPAD_ROWS_PORT,KEYPAD_ROWS_MASK,LOW);
		return KEYPAD_MAP[pressed_row-1][pressed_col-1] ;

	}
	else 
		return 0 ;
}
uint8_t KEYPAD_pressed(void)
{
	if(GPIO_read(KEYPAD_COLS_PORT,KEYPAD_COLS_MASK)!=KEYPAD_COLS_MASK)
	{
		delayMs(25);
		if(GPIO_read(KEYPAD_COLS_PORT,KEYPAD_COLS_MASK)!=KEYPAD_COLS_MASK)
			return HIGH ;
		else 
			return LOW  ;
	}
	else 
		return LOW ;
}

void delayMs(int time)
{
	int i, j;
	for(i = 0 ; i < time; i++)
	for(j = 0; j < 3180; j++);
	/* do nothing for 1 ms */
}
