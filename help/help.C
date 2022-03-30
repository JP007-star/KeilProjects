#include <reg51.h>
# define seg P2

sbit dp1=P0^0;
sbit dp2=P0^1;
sbit dp3=P0^2;
sbit dp4=P0^3;

unsigned char a[5]={0x89,0x86,0xc7,0x8c};

void delay1ms (unsigned int n);
unsigned char i=0;
void main()
{
	while (1)
	{
		seg =a[0]; //0x89 For (H)
		dp1=0;
		delay1ms(1);
		dp1=1;
		
		seg=a[1]; // 0x86 - E
		dp2=0;                           
		delay1ms(1);
		dp2=1;
		
		seg=a[2];//0xC7 
		dp3=0;
		delay1ms(1);
		dp3=1;
		
		seg=a[3];//0x8C FOR P
		dp4=0;
		delay1ms(1);
		dp4=1;
	}
}


void delay1ms (unsigned int n)
{
	unsigned char i;
	for (n;n>0;n--)
	{
		for (i=255;i>0;i--);
		for (i=255;i>0;i--);
	}
}

