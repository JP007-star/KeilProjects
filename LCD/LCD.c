# include <reg51.h>
# define lcd P2

sbit rs =P3^0;
sbit rw =P3^1;
sbit en =P3^2;


void delay(unsigned int);

void main()
{
	while(1)
	{
		lcd =0x0f;
		rs=0;
		rw=0;
		en=1;
		delay(2);
		en=0;
	}
}

void delay (unsigned int n)
{
	unsigned char i;
	for (n;n>0;n--)
	{
		for(i=250;i>0;i--);
		for(i=247;i>0;i--);
	}
}



