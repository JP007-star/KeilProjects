# include <reg51.h>
sbit led=P1^0;
sbit sw=P2^0;

void main ()
{
	while(1)
	{
		if (sw==0)
		{
			led=0x00;
		}
		else
		{
			led=0x01;
		}
	}
}