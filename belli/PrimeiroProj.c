/*Programa que aciona RD2 com o botão em linguagem C no PIC 18f4550 com cmopiler C18*/

	#include<P18F4550.h>					
	#pragma config PLLDIV = 5				//PLL para 20Mhz
	#pragma config CPUDIV = OSC1_PLL2		//PLL desligado
	#pragma config FOSC = HS				//Fosc = 20Mhz -> Tcy = 200ns
	#pragma config WDT = OFF				//Wacthdog desativado
	#pragma config PBADEN = OFF				//PortB começa como digital
	#pragma config LVP = OFF				//Sem gravação em baixa tensão
	#pragma config DEBUG = ON				//Habilita debug

//Funcao principal

void main(void)

{
	DDRD=0b00000000;			//Todos os pinos do PORTD como saida
	DDRB=0b00000100;			//Apenas o pino RB2 do PORTB como entrada


//Laço infinito

	for(;;)
			{	
			if(PORTBbits.RB2==1)
			PORTD=0b00000000;
			if(PORTBbits.RB2==0)
			
			PORTD= 0b00000001;
			
			}
}