/*Programa  que aciona CH1 no PORTB em linguagem C no PIC 18F4550*/

#include<P18F4550.h>
#pragma config PLLDIV = 5					//PLL para 20Mhz
#pragma config CPUDIV = OSC1_PLL2			//PLL desligado
#pragma config FOSC = HS					//Fosc = 20Mhz -> Tcy = 200ns
#pragma config WDT = OFF					//Watchdog desativado
#pragma config PBADEN = OFF					//PortB começa como digital
#pragma config LVP = OFF						//Sem gravação em baixa tensão
#pragma config DEBUG = ON					//habilita debug
#define CH1 PORTBbits.RB6					
#define CH2 PORTBbits.RB7					
#define led PORTDbits.RD0					


void main(void){
	DDRD = 0b00000000;
	DDRB = 0b11000000;
	DDRC = 0x00;
	

	for(;;){
		if(PORTBbits.RB6 == 0)
			{
				PORTDbits.RD0 = 1;
				PORTC = 0b11111111;
			}
		if(PORTBbits.RB7 == 0) 
			{
				PORTDbits.RD0 = 0;
				PORTC = 0b00000000;
			}
		if(!CH1 && CH2)
			{
				led = 0;
				PORTC = 0b00000000;
			}
		if(!CH2 && CH1)
			{
				led = 1;
				PORTC = 0b11111111;
				
			}

			
	}

}
