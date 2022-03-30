# include <reg51.h>

sbit output =P2^0;

void delay (unsigned int n)
{
	unsigned char i;
	for (n;n>0;n--)
	{
		for(i=255;i>0;i--);
		for(i=255;i>0;i--);
	}
}

void servo_delay (int times)
{
	int m;
	for (m=0;m<times;m++)
	{
		TH0=0XFF;
		TL0=0XD2;
		TR0=1;
		while (TF0==0);
		TF0=0;
		TR0=0;
	}
}


void main()
{
	int n;
	TMOD =0X01;
	output=0;
	while(1)
	{
		for (n=10;n<=30;n=n+5)
		{
			output=1;
			servo_delay(n);
			output=0;
			servo_delay(360);
			delay(1000);
		}
	}
}	