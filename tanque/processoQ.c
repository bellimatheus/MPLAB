//Tanque de processo

/*
Bomba inicia ligada, ao chegar no nivel max, desliga bomba e 
aciona resistência, quando atingir temp desejada desliga bomba e 
abre a válvula, chegando no nivel min fecha válvula e liga bomba 
reiniciando o ciclo
*/

#include<P18F4550.h>
#include<delays.h>
//Config
#pragma config PLLDIV = 5
#pragma config CPUDIV = OSC1_PLL2
#pragma config FOSC = HS
#pragma config WDT = OFF
#pragma config PBADEN = OFF
#pragma config LVP = OFF
#pragma config DEBUG = OFF
//Definições de hardware
#define ledBomba PORTDbits.RD0
#define ledValvula PORTDbits.RD1
#define ledResistencia PORTDbits.RD2
#define btnNMax PORTBbits.RB2
#define btnNMin PORTBbits.RB3
#define btnSensorTemp PORTBbits.RB4
#define btnBuzzer PORTCbits.RC0


void main(void)
		{
			TRISD = 0x00;
			TRISC = 0x00;
			//INTCON2bits.RBPU = 0;
			ledBomba = 0;
			ledValvula = 0;
			ledResistencia = 0;

			for(;;)
			{
				//caso 1
				while(btnNMax == 1){
					ledBomba = 1;
				}
				//caso 2
				ledBomba = 0;
				ledResistencia = 1;

				Delay10KTCYx(250);
				Delay10KTCYx(250);
				Delay10KTCYx(250);
				Delay10KTCYx(250);
				Delay10KTCYx(250);
				Delay10KTCYx(250);
				
				while(btnSensorTemp == 1){
					ledResistencia = 1;
					
					btnBuzzer = 1;
					Delay10KTCYx(250);
					btnBuzzer = 0;
					Delay10KTCYx(250);
					
				}
				//caso 3
				ledResistencia = 0;
				do{
					ledValvula = 1;
					
					PORTCbits.RC0 = 1;
					Delay10KTCYx(50);
					PORTCbits.RC0 = 0;
					Delay10KTCYx(50);
					
				}while(btnNMin == 1);
				
				//caso 4
				ledValvula = 0;
				
			}

		}
