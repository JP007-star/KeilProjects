# include <reg51.h>
# include "delay1ms.h"
# define seg P2
sbit s1 = P0^0;
sbit s2 = P0^1;
sbit s3 = P0^2;
sbit s4 = P0^3;

unsigned char dp1=0,dp2=0,dp3=0,dp4=0; //This for dot
unsigned char a[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

void flot(float);
void run(unsigned int);
void delay1ms(unsigned int);
void main()
{
	while (1)
	{
		flot( 6.01);
	}
}

void flot(float f) // this fuction for checking dot
{
	int temp;
	if((f>0.0)&&(f<10.0))//0 to 9
	{
		dp1=0x80;
		temp=f*1000;
	}
	else if ((f>=10.0)&&(f<100.0)) //10 To 99
	{
		dp2=0x80;
		temp=f*100;
	}
	else if((f>100.0)&&(f<1000.0)) //100 t0 999
	{
		dp3=0x80;
		temp=f*10;
	}
	run (temp);
}













void run (unsigned int n)
{ 
	unsigned char k;
	for (k=0;k<60;k++)
	{
		seg =a[n/1000]^dp1; //0xf9 =>1111 1001 ^0000 0000
		s1=0;
		delay1ms(1);
		s1=1;
		
		seg=a[(n/100)%10]^dp2;//0x99 =>1001 1001^1000 0000
		s2=0;                           // =0001 1000
		delay1ms(1);
		s2=1;
		
		seg=a[(n/10)%10]^dp3;//0xa4 =>1010 0100 ^0000 0000
		s3=0;
		delay1ms(1);
		s3=1;
		
		seg=a[n%10]^dp4;//0xb0 => 1011 0000 ^ 0000 0000
		s4=0;
		delay1ms(1);
		s4=1;
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
		