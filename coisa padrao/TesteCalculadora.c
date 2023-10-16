#include <stdio.h>
#include <stdlib.h>
#include <p18f4550.h>                       /*Include header filr for PIC18f definitions*/
#include <osc_config.h>                     /*Include Header file for oscillator configuration*/
#include <string.h>
#include <4x4_keypad.h>                     /*Include Header file for keypad operation*/
#include <LCD_16x2_4bit.h>                  /*Include Header file for LCD operation*/


void display_float( double );


void main()

{
    unsigned int i=0;                       /*Define variable for indexing of array*/
    unsigned long no1,no2;                  /*Define variable for storing no.*/
    unsigned long result=0;                 /*To store Result of operation*/
    double div_result=0;                    /*Store division float result*/
    unsigned char key,operator,flag=0;      /*key for key pressed,Operator for '+','-' etc*/
    unsigned char op1[10],op2[10],a;        
    unsigned long output[10],output1[10];   /*variable for Displaying result on LCD*/
    OSCCON = 0x72;                          /*Use Internal Oscillator with Frequency 8MHZ*/
    TRISB = 0;                              /*PORTB as Output Port*/
    TRISD = 0xf0;                           /*PORTD.0-PORTD.3 as a Output Port and PORTD.4-PORTD.7 as a Input Port*/
    write_port = 0xf0;
    
    lcd_init();                             /*Initialize LCD*/
    
    MSdelay(20);
    lcd_print("CASIO");                     /*Display string on LCD*/
    MSdelay(1000);
    lcd_clr();                              /*clear display screen*/
    
    
    MSdelay(20);
    while(1)
    {
        
         
      key= keyfind();                       /*Call keyfind() function for detecting pressed key*/
      MSdelay(30);
      if(key!=' ')
      {  
            
                if(key!='+' && key!='-' && key!='/' && key!='*' && key!='=')
                 {
                    if(flag==0)
                    {
                        op1[i] = key;       /*Assign 1st no string to op1 stored that in array*/
                        i++;
                    }
                    else
                    {
                        op2[i] = key;       /*Assign 2nd no string to op2 stored that in array*/
                        i++;
                    }    
                 }
                      
             if(key=='+' || key=='-' || key=='*' || key=='/' )
             {
             
                 operator=key;              /*Store operator*/
                 i=0;                       /*For another value enter of 2nd no.*/
                 flag=1;                        
  
             }
                
                
       if(key=='=')
       {   
           no1=atol(op1);                   /*C function(<stdlib.h>) used to convert string into long integer*/
           no2=atol(op2);                   /*C function(<stdlib.h>) used to convert string into long integer*/
           lcd_command(0xc0);               /*Start displaying result on 2nd Row and 1st location*/
           
           
           
        switch(operator)
        {
            /*Case for addition operation*/
            case '+':                       
                       
                        
                        result = no1+no2;
                        ltoa(output,result,10); /*C function(<stdlib.h>) 
                                                 convert long integer value to string for display*/
                        lcd_print(output);
                        break;
                        
            /*Case for Subtraction operation*/            
            case '-':
                        
                        result = no1-no2;
                        ltoa(output,result,10);
                        lcd_print(output);
                        break;
                        
            /*Case for Multiplication operation*/
            case '*':
                        
                        result = no1*no2;
                        ltoa(output,result,10);
                        lcd_print(output);
                        break;
                        
            /*Case for Division operation*/
            case '/':
                        
                        if(no2==0)                  /*Check for math error*/
                        {  
                            
                            lcd_clr();
                            lcd_print("MATH ERROR");
                        }
                        else
                        {   
                           
                            div_result = (float)no1/(float)no2;     /*result should be in float */
                            
                             /*Function used display float value*/
                            display_float(div_result);
                            
                        }   
                        break;
            
            default :
                
                break;
        
        
        }
        
        
       } 
    
    }
      else 
      {
          lcd_clr();                    /*Clear display screen*/    
          MSdelay(10);
         
          memset(op1,0,10);             /*memset Clear array of no.1 by copying 0 to op1's 10 location*/
          memset(op2,0,10);             /*Clear array of no.2*/    
          memset(output,0,10);          /*Clear array of output array which display final result*/
          break;
         
      }
    
       
    MSdelay(50);
    
  }
    
    
}


void display_float(double div_result)
{
    float temp;
    unsigned long output[15],output1[15];
        temp=div_result - ((int)div_result);    /* get value after decimal point i.e. float value*/
        temp=100*temp;                          /*convert it into non-decimal value*/
        itoa(output,(int)div_result,10);        /*convert value before deciaml point into ASCII value*/
        lcd_print(output);                      
        lcd_print(".");                         /*Display Decimal point*/
        itoa(output1,(int)temp,10);             /*convert value after deciaml point into ASCII value*/
        lcd_print(output1);

}