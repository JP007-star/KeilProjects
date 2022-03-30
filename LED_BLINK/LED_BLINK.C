# include <reg51.h>
#define LEDs P1
sbit led=P2^0;

void delay(int);
void main ()
{
	while(1)
	{
		LEDs=0x00;
		led=0;
		delay(100);
		LEDs=0xff;
		led=1;
		delay(100);
		
	}
	
}
void delay (int n)
{
	unsigned char i;
	for(n;n>0;n--)
	{
		for(i=255;i>0;i--);
		for(i=255;i>0;i--);
	}
	
}
		