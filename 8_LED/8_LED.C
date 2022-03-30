# include <reg51.h>
#define LEDs P1
void delay (int);
void main()
{
	while(1)
	{
		LEDs=0xAA;      // 1010  1010                     //LEDs=0x3C;    3   1100 0011     //LEDs=0xF0;   2   1111 0000        //LEDs=0x00;  1       
		delay(100);
		
		LEDs=0x55;      // 0101  0101                     //LEDs=0xC3;    3   0011 1100     //LEDs=0x0F;   2    0000 1111        //LEDs=0xFF;   2
		delay(100);
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