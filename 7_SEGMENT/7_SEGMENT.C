# include <reg51.h>
# define seg1 P1 // common cathode
# define seg2 P2  // common anode

void delay (unsigned int);

unsigned int sdata1[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned int sdata2[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

void main()
{
	unsigned char j=0;
	unsigned char k=0;
	while(1)
	{
		for (j=0;j<10;j++)
		{
			seg1 =sdata1[j];
			delay(100);
		}
		for (j=0;j<10;j++)
		{
			seg2 =sdata2[j];
			delay(100);
		}
	}
}

void delay (unsigned int n)
{
	unsigned char i;
	for (n;n>0;n--)
	{
		for (i=255;i>0;i--);
		for (i=255;i>0;i--);
	}
}