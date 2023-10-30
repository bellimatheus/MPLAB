/*Carimbador
Simulação da Automação de uma esteira com carimbadores
Sensor de presença em RB2 
Esteira em funcionamento em RD1 
Carimbador de adesivo em RD1
Carimbador de Rótulo em RD2
Funcionamento: a cada 5 pulsos no botão RB2, a esteira para e o
objeto recebe um adesivo e um rótulo na sequência
Após os carimbamentos a esteira volta a funcionar automaticamente

*/

#include<P18F4550.h>
#include<delays.h>
//config
#pragma config PLLDIV = 5
#pragma config CPUDIV = OSC1_PLL2
#pragma config FOSC = HS
#pragma config WDT = OFF
#pragma config PBADEN = OFF
#pragma config LVP = OFF
#pragma config DEBUG = ON
//Definições
#define senso PORTBbits.RB2
#define esteira PORTDbits.RD0
#define ades PORTDbits.RD1
#define rotulo PORTDbits.RD2
#define led PORTDbits.RD3

void main(void){
		unsigned char contLatas = 0;
		TRISBbits.TRISB2 = 1;
		TRISD = 0b11110000;
		DDRD = 0x00;
		DDRC = 0b00000000;
		DDRC = 0x00;

		INTCON2bits.RBPU = 0;			//Ativa Pull-UPs do PORTB

		//Iniciando Inputs/Output
		esteira = 0;
		ades = 1;
		rotulo = 1;
		led = 1;
		while(1){
			//1° manter acionada a esteira em até 5 latas
			esteira = 1;
			if(senso == 0){
				contLatas++;
				while(senso == 0){
					Delay10KTCYx(50);
				}
			} 
			if(contLatas >= 7){			//atingiu o obj
				contLatas = 0;
				//2°Desligando a esteira
				esteira = 0;


				//3° Acionar aplicador de adesivo por 2s

				ades = 1; 				//adesivando led yello aceso
				
				Delay10KTCYx(250);
				Delay10KTCYx(250);
				Delay10KTCYx(250);
				Delay10KTCYx(250);
				
				ades = 0;				//concluido led yellow apagado
				
				PORTCbits.RC0 = 1;
				Delay10KTCYx(50);
				PORTCbits.RC0 = 0;
				Delay10KTCYx(50);
				PORTCbits.RC0 = 1;
				Delay10KTCYx(50);
				PORTCbits.RC0 = 0;
				//4°Esperar 1s
	 			Delay10KTCYx(250);
				Delay10KTCYx(250);
				
				//5° Acionar o aplicador de rotulo por 2s

				rotulo = 1; 				//led verde aceso, rotulando

				Delay10KTCYx(250);
				Delay10KTCYx(250);
				Delay10KTCYx(250);
				Delay10KTCYx(250);
				
				rotulo = 0;				//led verde apagado, concluido
			
				PORTCbits.RC0 = 1;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 0;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 1;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 0;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 1;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 0;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 1;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 0;
				Delay10KTCYx(250);

				led = 1;

				Delay10KTCYx(250);
				Delay10KTCYx(250);
				Delay10KTCYx(250);
				Delay10KTCYx(250);

				led = 0;

				PORTCbits.RC0 = 1;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 0;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 1;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 0;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 1;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 0;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 1;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 0;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 1;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 0;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 1;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 0;
				Delay10KTCYx(250);
				Delay10KTCYx(250);
				Delay10KTCYx(250);
				Delay10KTCYx(250);
				Delay10KTCYx(250);
				Delay10KTCYx(250);
				Delay10KTCYx(250);
				PORTCbits.RC0 = 1;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 0;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 1;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 0;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 1;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 0;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 1;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 0;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 1;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 0;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 1;
				Delay10KTCYx(250);
				PORTCbits.RC0 = 0;
				//6°Esperar 0,5s
				Delay10KTCYx(250);

				//7°Repetir o processo a partir de 1
		}
	}
}
