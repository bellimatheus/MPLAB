//Programa temporizador de contagem binária em linguagem C no PIC 18F4550
//Temporizador com contagem binária no porto com incrementos a cada 500ms OU 1S
//Usa a estrutura "FOR" no lugar da decisão "IF"
//Programa implementado para incrementar a partir dos LEDS apagados

#include<P18F4550.h>
#include<delays.h>
#pragma config PLLDIV = 5				//PLL para 20Mhz
#pragma config CPUDIV = OSC1_PLL2		//PLL desligado
#pragma config FOSC = HS				//Fosc = 20Mhz -> Tcy=200ns
#pragma config WDT = OFF 				//wacthdog destivado
#pragma config PBADEN = OFF 			//PortB começa 
#pragma config LVP = OFF 				//sem gravação em baixa tensão

unsigned char tempo = 0;				//Variável de 8 bits de contagem inicia em 0

void main (void)
{
	DDRD = 0x00;						//PORTD como saída ou 0b00000000
	PORTD = 0xFF;						//PORTD todo desligado
	for(;;)
		{
			for(tempo = 0; tempo < 256; tempo++)

				{
					PORTD =~  tempo; 	//o '~' é a aproximidade do tempo
					Delay10KTCYx(250);
					Delay10KTCYx(250);
				}
		}
	
}