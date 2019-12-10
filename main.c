/* 
 * File:   main.c
 * Author: karlito
 *
 * Created on December 1, 2019, 5:58 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <sys/attribs.h>

#include "constantes.h"
#include "io.h"

#pragma config JTAGEN = OFF     
#pragma config FWDTEN = OFF      


#pragma config FNOSC =	2      // select oscilator externe (quartz at 8MHz)
#pragma config FSOSCEN =	OFF     // Disable secondary oscilator
#pragma config POSCMOD =	XT      // XT oscilator mode
#pragma config OSCIOFNC =	ON      //
#pragma config FPBDIV =     DIV_2   // Peripheralls run at /2 the speed

#pragma config FPLLIDIV =	DIV_2
#pragma config FPLLMUL =	MUL_20
#pragma config FPLLODIV =	DIV_1

void activateRGB (int r, int g, int b)
{
    int i;
    
    LATDbits.LATD2 = 1;
    LATDbits.LATD3 = 1;
    LATDbits.LATD12 = 1;

    for (i = 0; i < 100; i++)
    {
        if (i < r)
            LATDbits.LATD2 = 0;
        if (i < g)
            LATDbits.LATD12 = 0;
        if (i < b)
            LATDbits.LATD3 = 0;
    }
}



int main(int argc, char** argv)
{    
    /*
    TRISDbits.TRISD3 = 0;
    TRISDbits.TRISD2 = 0;
    TRISDbits.TRISD12 = 0;

    TRISAbits.TRISA14 = 0;
    TRISBbits.TRISB12 = 0;
    TRISGbits.TRISG12 = 0;
    TRISDbits.TRISD6 = 0;
    
    LATDbits.LATD6 = 0;
    LATGbits.LATG12 = 0;
    LATAbits.LATA14 = 0;
    LATBbits.LATB12 = 0;
    LATBbits.LATB13 = 0;
    LATAbits.LATA9 = 0;
    LATAbits.LATA10 = 0;
    */
    
    ANSELBbits.ANSB11 = 0;  // SW5 disabled analog
    ANSELBbits.ANSB10 = 0;  // SW6 disabled analog
    ANSELBbits.ANSB9 = 0;   // SW7 disabled analog    
    ANSELBbits.ANSB8 = 0;   // SW7 disabled analog    
    ANSELBbits.ANSB0 = 0;
    ANSELBbits.ANSB1 = 0;
    
    TRISFbits.TRISF3 = 1;
    TRISFbits.TRISF5 = 1;
    TRISFbits.TRISF4 = 1;
    TRISDbits.TRISD15 = 1; 
    TRISDbits.TRISD14 = 1;
    TRISBbits.TRISB11 = 1;
    TRISBbits.TRISB10 = 1;
    TRISBbits.TRISB9 = 1;
    
    // buttons
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB8 = 1;
    TRISAbits.TRISA15 = 1;
    TRISBbits.TRISB0 = 1;
    TRISFbits.TRISF0 = 1;
    
    int number;
    int i;
    enum State state = start;
    int number1 = 0, number2 = 0, result = 0;
    enum Operation operation = no_operation;
    
    
    while(1)
    {
        //activateRGB(32, 54, 78);

        //number = 0;
              
        /*
        if (SW0 == 1)
            number++;
        if (SW1 == 1)
            number += 2;
        if (SW2 == 1)
            number += 4;
        if (SW3 == 1)
            number += 8;
        if (SW4 == 1)
            number += 16;
        if (SW5 == 1)
            number += 32;
        if (SW6 == 1)
            number += 64;
        if (SW7 == 1)
            number += 128;
        */
        
        /*
        if (BUT_LEFT)
            number = 1;
        if (BUT_RIGHT)
            number = 2;
        if (BUT_UP)
            number = 3;
        if (BUT_MIDDLE)
            number = 5;
        if (BUT_DOWN)
            number = 4;
        */
        
        switch(state)
        {
            case start:
                number1 = readNumber();
                state = readButtonMiddle(state);
                break;
            case number_saved1:
                operation = readButton();
                if (operation != no_operation)
                    state = wait_secondNumber;
                break;
            case wait_secondNumber:
                number2 = readNumber();
                state = readButtonMiddle(state);
                break;
            case calculate:
                switch (operation)
                {
                    case plus:
                        result = number1 + number2;
                        break;
                    case minus:
                        result = number1 - number2;
                        break;
                   case divide:
                        result = number1 / number2;
                        break;
                    case mult:
                        result = number1 * number2;
                        break;
                }
                state = print_result;
                break;
            case print_result:
                printDigit(result);
                break;
        }
        
    }
    
    return (EXIT_SUCCESS);
}

