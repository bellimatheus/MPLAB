/* Programa em delay ktcyx em linguagem C no PORTD e PORTC pisca led */ 

#include<P18F4550.h>
#include<delays.h>
#pragma config PLLDIV = 5 
#pragma config CPUDIV = OSC1_PLL2
#pragma config FOSC = HS
#pragma config WDT = OFF
#pragma config PBADEN = OFF
#pragma config LVP = OFF
#pragma config DEBUG = ON

void main (void)
    {
           DDRD = 0x00; //PORTD em zero led
           DDRE = 0x00; //PORTE em zero
           DDRC = 0x00; //PORTC em zero

/*for(;;)
        {
          Delay10KTCYx(150);

          PORTD = 0b00000000;

          Delay10KTCYx(150);

          PORTD = 0b11111111;

          Delay10KTCYx(150);

          PORTE = 0b11111000;

          Delay10KTCYx(250);

          PORTD = 0b00000000;

          PORTE = 0b00000000;

          Delay10KTCYx(20);

          PORTC = 0b11111110;

          Delay10KTCYx(20);

          PORTC = 0b0000000000;
          }
*/

for (;;)
		{
		
		//LED protoboard
		Delay10KTCYx(10);
		PORTD = 0b00000000;
		Delay10KTCYx(10);
		PORTD = 0b00000001;
		Delay10KTCYx(10);
		PORTD = 0b00000010;
		Delay10KTCYx(10);
		PORTD = 0b00000100;
		Delay10KTCYx(10);
		PORTD = 0b00001000;
		Delay10KTCYx(10);
		PORTD = 0b00010000;
		Delay10KTCYx(10);
		PORTD = 0b00100000;
		Delay10KTCYx(10);
		PORTD = 0b01000000;
		Delay10KTCYx(10);
		PORTD = 0b10000000;
		Delay10KTCYx(10);
		PORTD = 0b01000000;
		Delay10KTCYx(10);
		PORTD = 0b00100000;
		Delay10KTCYx(10);
		PORTD = 0b00010000;
		Delay10KTCYx(10);
		PORTD = 0b00001000;
		Delay10KTCYx(10);
		PORTD = 0b00000100;
		Delay10KTCYx(10);
		PORTD = 0b00000010;
		Delay10KTCYx(10);
		PORTD = 0b00000001;		
		Delay10KTCYx(10);
		PORTD = 0b00000000;



		//LED PIC18f4550
		Delay10KTCYx(60);
		PORTE = 0b00000000;
		Delay10KTCYx(50);
		PORTE = 0b00000001;
		Delay10KTCYx(40);
		PORTE = 0b00000010;
		Delay10KTCYx(30);
		PORTE = 0b00000100;
		Delay10KTCYx(20);
		PORTE = 0b00000111;
		Delay10KTCYx(10);
		PORTE = 0b00000100;
		Delay10KTCYx(20);
		PORTE = 0b00000010;
		Delay10KTCYx(30);
		PORTE = 0b00000001;				
		Delay10KTCYx(40);
		PORTE = 0b00000000;
		Delay10KTCYx(20);
		PORTC = 0b11111111;
		Delay10KTCYx(85);
		PORTC = 0b00000000;
		
		}

    }
