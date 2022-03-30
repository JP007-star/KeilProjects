# include <reg51.h>
# define lcd P2


sbit rs =P3^0;
sbit wr =P3^1;
sbit en =P3^2;

void init (void);
void comd(unsigned char);
void display(unsigned char);

void cgram(void); 



void delay(unsigned int);
unsigned char ohmdata[]={0x00,0x0e,0x11,0x11,0x11,0x0a,0x1b,0x00};

void main()
{
	
		init();
		cgram(); // call cgram data stor
	while(1)
	{
		display(0);
		
		while(1);
	}
}



void init(void)
{
	comd (0x01);   //  clear display screen
	comd (0x02);   // Return Home
	comd (0x0c);  // Display On cursor OFF 
	comd (0x38);  //2 lines and 5*7 matrix
	comd (0x80);  //Forces cursor to begining 1st line
}                    // (0xc0) 2nd line

void comd(unsigned char cd) // command function
{
	lcd =cd;      //command
	rs=0;        //rs 0 for command
	wr=0;        //write
	en=1;        //Enable
	delay(2);    // delay for 2 s
	en=0;        //disable
}

void cgram (void)
{
	char i;
	comd(0x40);
	for (i=0;i<8;i++)
	display(ohmdata[i]);
	comd(0x80);
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



