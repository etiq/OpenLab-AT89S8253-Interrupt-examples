#include <REG8253.H>
void delay_ms(unsigned int time) //delay function using timer0 to generate isec of delay.
{ 
	
	unsigned char i,limit;
	limit=(time/25);
	for(i=0;i<limit;i++)
	{
TMOD=0x01;
TL0=0xCB;
TH0=0x7D;	
TR0=1;
while(!TF0);
TF0=0;
TR0=0;	
}
}