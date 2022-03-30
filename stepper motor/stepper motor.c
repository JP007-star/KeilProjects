# include <reg51.h>
# define mot P1

void delay(unsigned int);
void main()
{
	while(1)
	{
		P1=0x0a;      // 0000 1010
		delay(100);
		
		P1=0x06;    // 0000 0110
		delay(100);
		
		P1=(0x05);   // 0000 0101
		delay(100);
		
		P1=0x09;    // 0000 1001
		delay(100);
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

