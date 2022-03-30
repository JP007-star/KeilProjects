# include <reg51.h>
# define seg P2
sbit s1 = P0^0;
sbit s2 = P0^1;
sbit s3 = P0^2;
sbit s4 = P0^3;

unsigned char a[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

void run(unsigned int);
void delay1ms(unsigned int);
void main()
{
	while (1)
	{
		run(1522);
	}
}

void run (unsigned int n)
{
	{
		seg =a[n/1000];
		s1=0;
		delay1ms(1);
		s1=1;
		
		seg=a[(n/100)%10];
		s2=0;
		delay1ms(1);
		s2=1;
		
		seg=a[(n/10)%10];
		s3=0;
		delay1ms(1);
		s3=1;
		
		seg=a[n%10];
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
		