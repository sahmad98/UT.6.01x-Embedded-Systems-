// ***** 0. Documentation Section *****
// SwitchLEDInterface.c for Lab 8
// Runs on LM4F120/TM4C123
// Use simple programming structures in C to toggle an LED
// while a button is pressed and turn the LED on when the
// button is released.  This lab requires external hardware
// to be wired to the LaunchPad using the prototyping board.
// January 11, 2014

// Lab 8
//      Jon Valvano and Ramesh Yerraballi
//      November 21, 2013

// ***** 1. Pre-processor Directives Section *****
#include "TExaS.h"
#include "tm4c123gh6pm.h"

// ***** 2. Global Declarations Section *****

// FUNCTION PROTOTYPES: Each subroutine defined
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
void delay(unsigned long time);
// ***** 3. Subroutines Section *****

// PE0, PB0, or PA2 connected to positive logic momentary switch using 10 k ohm pull down resistor
// PE1, PB1, or PA3 connected to positive logic LED through 470 ohm current limiting resistor
// To avoid damaging your hardware, ensure that your circuits match the schematic
// shown in Lab8_artist.sch (PCB Artist schematic file) or 
// Lab8_artist.pdf (compatible with many various readers like Adobe Acrobat).
  unsigned long wait;
int main(void){ 
//**********************************************************************
// The following version tests input on PE0 and output on PE1
//**********************************************************************
  TExaS_Init(SW_PIN_PE0, LED_PIN_PE1);  // activate grader and set system clock to 80 MHz

	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOE;
	wait = SYSCTL_RCGC2_R;
	GPIO_PORTE_DIR_R |= 0x02;
	GPIO_PORTE_AFSEL_R |= 0x00;
	GPIO_PORTE_PCTL_R |= 0x00000000;
	GPIO_PORTE_PDR_R |= 0x00;
	GPIO_PORTE_PUR_R |= 0x00;
	GPIO_PORTE_DEN_R |= 0x03;
	GPIO_PORTE_DATA_R |= 0x02;
	
  EnableInterrupts();           // enable interrupts for the grader
  while(1){
    delay(1);
		if(GPIO_PORTE_DATA_R & 0x01)
			GPIO_PORTE_DATA_R = GPIO_PORTE_DATA_R^0x02;
		else GPIO_PORTE_DATA_R = 0x02;
  }
}
void delay(unsigned long time)
{
	unsigned i=0;
	while(time>0)
	{
		i=1333333;
		while(i>0)
		{
			i -= 1;
		}
		time -=1;
	}
}
