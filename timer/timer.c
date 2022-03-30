// timer 0 mode 0 one ms delay

# include <reg51.h>
void delay();
void main()
{
	delay();
}

void delay(unsigned int n)
{
	TMOD =0X00; // (256*32 = 8192 -1000= 7192 --> 1110 0000)
	TL0=0X18;   //0001 1000
	TH0=0XE0;   //1110 0000
	TR0=1;      // TIMER START
	while (TF0==0); // WAITING FOR TF0 FLOG SET
	TR0=0;           // TIMER OFF
	TF0=0;          // TF0 FLOG RESET
}
	