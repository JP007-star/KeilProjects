
/* OUTPUT:
   1111  1110
	 1111  1101
	 1111  1011
	 1111  0111
	 1110  1111
	 1101  1111
	 1011  1111
	 0111  1111
	 
	 */

# include <reg51.h>
#define LEDs P1
void delay (int);
void main()
{
	unsigned char i=0,val=0x01;
	while(1)
	{
		for (i;i<8;i++) //1
    {
			LEDs=~(val<<i); // 0000 0001//0000 0010
      delay	(100);
		}
    if (i==8)
		{
      i=0;	
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