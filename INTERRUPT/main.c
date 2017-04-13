/*
PROJECT Name: LED
Author      : Etiq Technologies
Created on  :16 April 2016
Description:  The Project is a demo project for the AT89S8253 interrupt 
              programming.The Led connected to PORT2 of the controller is 
							made off for a second when afalling edge detected at the INT1 
							pin.The Led connected to the PORT1 of the controller is made 
							on for a second when a falling edge occur at the INT0 pin.

*/


#include <REG8253.H>
#include "delay.h"           //delay header



void ex0_isr (void) interrupt 0    //interrupt subroutine for ext interrupt o
{
P1=0xFF;
delay_ms(1000);	
}

void ex1_isr (void) interrupt 2    //interrupt subroutine for ext interrupt 1
{
P2=0x00;
delay_ms(1000);	
}

/*=============================================================================
=============================================================================*/
void main (void)
{

/*-----------------------------------------------
Configure INT0 (external interrupt 0) to generate
an interrupt on the falling-edge of /INT0 (P3.2).
Enable the EX0 interrupt and then enable the
global interrupt flag.
-----------------------------------------------*/
IT0 = 1;   // Configure interrupt 0 for falling edge on /INT0 (P3.2)
EX0 = 1;   // Enable EX0 Interrupt
IT1 = 1;   // Configure interrupt 2 for falling edge on /INT1 (P3.3)
EX1 = 1;   // Enable EX1 Interrupt
EA =  1;    // Enable Global Interrupt Flag

/*-----------------------------------------------
Wait forever.
-----------------------------------------------*/
while (1)
  {
		P1=0x00;
		P2=0xFF;
  }
}

/*=============================================================================
=============================================================================*/

