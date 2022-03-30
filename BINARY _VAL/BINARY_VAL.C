# include <reg51.h>
#define LEDs P1
void delay (int);
void main()
{ 
	unsigned char i=1;
	
		while (1)
		{
			for(i;i<=255;i++)
			{
				LEDs = ~ i;
				delay(100);
				if (i==255)
				{
					i=0;
				}
			}
		}
	
}

void delay (int n)
{
	unsigned char i;
	for (n;n>0;n--)
	{
		for(i=255;i>0;i--);
		for(i=255;i>0;i--);
	}
}