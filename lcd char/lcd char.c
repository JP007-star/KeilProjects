# include <reg51.h>
# define lcd P2


sbit rs =P3^0;
sbit wr =P3^1;
sbit en =P3^2;

void init (void);
void command(unsigned char);
void display(unsigned char);


void delay(unsigned int);

void main()
{
	while(1)
	{
		init();
		display('S');
		while(1);
	}
}



void init()
{
	command (0x01);   //  clear display screen
	command (0x02);   // Return Home
	command (0x0c);  // Display On cursor OFF 
	command (0x38);  //2 lines and 5*7 matrix
	command (0x80);  //Forces cursor to begining 1st line
}                    // (0xc0) 2nd line

void command(unsigned char c) // command function
{
	lcd =c;      //command
	rs=0;        //rs 0 for command
	wr=0;        //write
	en=1;        //Enable
	delay(2);    // delay for 2 s
	en=0;        //disable
}

void display (unsigned char d)
{
	lcd =d;         
	rs=1;
	wr=0;
	en=1;
	delay(2);
	en=0;
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



