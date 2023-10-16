/* Contador binário */

//Cont bin no PORTD com incrementos por um botão em RB3e o bt RB2 reseta
//Objetivo ao chegar em 20 trava a contagem e liga buzzer em RC0

#include<P18F4550.h>
#include<delays.h>
#pragma config PLLDIV = 5			//PLL 20Mhz
#pragma config CPUDIV = OSC1_PLL2 	//PLL desligado
#pragma config FOSC = HS 			//fosc = 20Mhz -> Tcy = 200ns
#pragma config WDT = OFF 			//watchdog desligado
#pragma config PBADEN = OFF 		//PortB começa como digital
#pragma config LVP = OFF			//Sem gravar em baixa tensão
#pragma config DEBUG = OFF 			//habilita debug
#define BT0 PORTBbits.RB2 			//Apelidado
#define BT1 PORTBbits.RB3			// ""
#define buzzer PORTCbits.RC0		// ""
		
unsigned char cont = 0;				//variavel de 8bits inicializada em 0
unsigned char limite = 10;			// ""

void main(void){
	DDRC = 0x00; 					//PortC como saida
	DDRD = 0x00; 					//PortD como saida
	DDRB = 0b00001100; 				//RB2 e 3 como entrada
	PORTD = 0xFF; 					//Desliga todos os leds do PortD
	buzzer = 0;						//buzzer off


	for(;;){

		PORTD = cont; 				//atribui cont ao PortD
		if(!BT1){					//se a entrada do bt for 0
				
			cont++;					//incrementa ao cont

			while(!BT1);
		}
		while(cont >= limite){
			PORTD = limite;
			buzzer = 1;
		}
		if(!BT0){
			cont = 0;   			//variavel cont reiniciada
			buzzer = 0;				//buzzer desativa
		}
	}
}