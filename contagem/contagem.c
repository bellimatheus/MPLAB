/*contagem crescente em botao rb2, contagem 
decrescente em botao rb3 display 7 seg ligado 
ao portd todo, rd0 a rd6 
*/

#include<P18F4550.h>
#include<delays.h>
#pragma config PLLDIV = 5
#pragma config CPUDIV = OSC1_PLL2
#pragma config FOSC = HS
#pragma config WDT = OFF
#pragma config PBADEN = OFF
#pragma config LVP = OFF
#pragma config DEBUG = ON
#define increment PORTBbits.RB2			//incrementa contagem
#define decrement PORTBbits.RB3 			//decrementa contagem
#define display PORTD					//7 segmentos ligados RD0 a 6

void main(void){
	int i = 0;

	char table[] = {
		0b00111111, //0
		0b00000110, //1
		0b01011011, //2
		0b01001111, //3
		0b01100110, //4
		0b01101101, //5
		0b01111101, //6
		0b00000111, //7
		0b01111111, //8
		0b01100111, //9
		0b01110111, //A
		0b01111100, //B
		0b01011110, //C
		0b01111101, //D
		0b01111001, //E
		0b01110001, //F
		
	};

	ADCON1 = 0x0F; //inicialização
	DDRD = 0x00;
	DDRB = 0xFF;
	INTCON2bits.RBPU = 0; //ativa pull-ups

	for(;;){
		display = table[i];
		//transfere o valor da var i para o display tabela indexada por i botao increment
		if(!increment){
			if(i<0x0F)i++;
			while(!increment){
				Delay10KTCYx(50); //100ms

			}
		}
		else{
			if(!decrement){
				if(i>0)i--;
				while(!decrement){
					Delay10KTCYx(50);
				}
			}
		}
	}	
}