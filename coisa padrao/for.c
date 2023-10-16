//Programa temporizador de contagem bin�ria em linguagem C no PIC 18F4550
//Temporizador com contagem bin�ria no porto com incrementos a cada 500ms OU 1S
//Usa a estrutura "FOR" no lugar da decis�o "IF"
//Programa implementado para incrementar a partir dos LEDS apagados

#include<P18F4550.h>
#include<delays.h>
#pragma config PLLDIV = 5				//PLL para 20Mhz
#pragma config CPUDIV = OSC1_PLL2		//PLL desligado
#pragma config FOSC = HS				//Fosc = 20Mhz -> Tcy=200ns
#pragma config WDT = OFF 				//wacthdog destivado
#pragma config PBADEN = OFF 			//PortB come�a 
#pragma config LVP = OFF 				//sem grava��o em baixa tens�o

unsigned char tempo = 0;				//Vari�vel de 8 bits de contagem inicia em 0

void main (void)
{
	DDRD = 0x00;						//PORTD como sa�da ou 0b00000000
	PORTD = 0xFF;						//PORTD todo desligado
	for(;;)
		{
			for(tempo = 0; tempo < 256; tempo++)

				{
					PORTD =~  tempo; 	//o '~' � a aproximidade do tempo
					Delay10KTCYx(250);
					Delay10KTCYx(250);
				}
		}
	
}