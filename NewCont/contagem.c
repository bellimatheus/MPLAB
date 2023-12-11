#include<P18F4550.h>
#include<delays.h>
#pragma config PLLDIV = 5
#pragma config CPUDIV = OSC1_PLL2
#pragma config FOSC = HS
#pragma config WDT = ON
#pragma config PBADEN = OFF
#pragma config LVP = ON
#pragma config DEBUG = ON
#define increment PORTBbits.RB2
#define decrement PORTBbits.RB3
#define trava PORTBbits.RB4
#define disp4 PORTAbits.RA5
#define disp3 PORTAbits.RA4
#define disp2 PORTAbits.RA3
#define disp1 PORTAbits.RA2
#define display PORTD

void main(void){
	int i = 0, valor;
	unsigned char milhar, centena, dezena, unidade, aux0=0, aux1=0, aux=0;
	unsigned char tempo = 25;
	
	
	char table[]={
		0b00111111,
		0b00000110,
		0b01011011,
		0b01001111,
		0b01100110,
		0b01111101,
		0b00000111,
		0b01111111,
		0b01101111,
		0b01110111,
		0b01111100,
		0b01011000,
		0b01011110,
		0b01111001,
		0b01110001
	};
	
	ADCON1 = 0x0F;		//procurar no datasheet
	DDRD = 0x00;
	DDRA = 0b00000000;
	DDRB = 0b11111111;
	DDRAbits.RA5 = 0;		
	DDRAbits.RA4 = 0;
	DDRAbits.RA3 = 0;
	DDRAbits.RA2 = 0;
	
	DDRBbits.RB2 = 1;
	DDRBbits.RB3 = 1;
	DDRBbits.RB4 = 1;
	disp1 = 0;
	disp2 = 0;
	disp3 = 0;
	disp4 = 0;
	INTCON2bits.RBPU = 0;		//pull-ap ativo no portb

	for(;;){
		if(!increment && !aux0){
			if(i < 9999)i++;
			if(trava)aux0=1;

		}
		if(increment) aux0=0;
		if(!decrement && !aux1){
			if(i > 0)i--;
			if(trava) aux1=1;
			
		}
		if(decrement)aux1=0;
		valor = i;
		milhar = valor/1000;
		valor %= 1000;
		centena = valor/100;
		valor %= 100;
		dezena = valor/100;
		unidade = valor%10;
		display = table [milhar];
		disp1 = 0;
		disp2 = 0;
		disp3 = 0;
		disp4 = 1;
		Delay1KTCYx(tempo);
		disp4 = 0;
		display = table[dezena];
		disp1 = 0;
		disp2 = 0; 
		disp3 = 0;
		disp4 = 0;
		Delay1KTCYx(tempo);
		disp1 = 0;
		disp2 = 1;
		disp3 = 0;
		disp4 = 0;
		Delay1KTCYx(tempo);
		disp2 = 0;
		display = table[unidade];
		disp1 = 0;
		disp2 = 0;
		disp3 = 0;
		disp4 = 0;
		Delay1KTCYx(tempo);

	}
}
