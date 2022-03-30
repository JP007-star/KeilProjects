// display 0 to 99 digit numbers using two 7 srg

# include <reg51.h>
#define seg P2  // 7 seg Data 8 pin
sbit seg1=P0^0;  // 1 st seg control pin
sbit seg2=P0^1;  // 2nd seg control pin

void delay (unsigned int);
unsigned int sdata [10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void main ()
{
	unsigned char i,j =0;
	while(1)
	{
		for (j=0;j<100;j++) // to display  0 to 99
		{
			for (i=0;i<60;i++)  // displaying the same num for sometime
		  {
				seg = sdata [j/10];
				seg1 =0;
				delay (1);
				seg1 =1;
				seg =sdata[j%10];
				seg2=0;
				delay(1);
				seg2=1;
			}
		}
	}
}

void delay (unsigned int n)  
{
	unsigned char i;
	for (n;n>0;n--)
	{
		for(i=255;i>0;i--);
		for(i=255;i>0;i--);
	}
}
		