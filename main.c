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

void printOneDigit (int nDigit, char letter)
{
                TRISAbits.TRISA10 = 0;
            TRISAbits.TRISA9 = 0;
            TRISBbits.TRISB13 = 0;
            TRISBbits.TRISB12 = 0;

        up() = 1; // Segment haut-haut
        up_right() = 1;// Segment haut-droit
        up_left()  = 1; // Segment bas-droit
        middle() = 1;//Middle Segment
        down() = 1;// Segment bas-bas
        down_left() = 1;// Segment bas-gauche
        down_right() = 1; // Segment bas-droite

    
    switch (nDigit)
    {
        case 1: // AN3
            LATAbits.LATA10 = 0;
            LATAbits.LATA9 = 1;
            LATBbits.LATB13 = 1;
            LATBbits.LATB12 = 1;
            break;
        case 2:
            LATAbits.LATA10 = 1;
            LATAbits.LATA9 = 0;
            LATBbits.LATB13 = 1;
            LATBbits.LATB12 = 1;
            break;
        case 3:
            LATAbits.LATA10 = 1;
            LATAbits.LATA9 = 1;
            LATBbits.LATB13 = 0;
            LATBbits.LATB12 = 1;
            break;
        case 4:
            // Activate the last digit
             LATAbits.LATA10 = 1;
            LATAbits.LATA9 = 1;
            LATBbits.LATB13 = 1;
            LATBbits.LATB12 = 0;
            break;
    }
    
    // Define all 7-segments as output
    TRISGbits.TRISG12 = 0; // Segment haut-haut
    TRISAbits.TRISA14 = 0;// Segment haut-droit
    TRISDbits.TRISD6 = 0; // Segment bas-droit
    TRISDbits.TRISD13 = 0;// Middle Segment
    TRISGbits.TRISG13 = 0;// Segment bas-bas
    TRISGbits.TRISG15 = 0;// Segment bas-gauche
    TRISDbits.TRISD7 = 0; // Segment haut-gauche
    

    switch (letter)
    {
case '5':
        case 5:
      //Afficher numéro 5
        up() = 0; // Segment haut-haut
        up_right() = 1;// Segment haut-droit
        up_left()  = 0; // Segment bas-droit
        middle() = 0;//Middle Segment
        down() = 0;// Segment bas-bas
        down_left() = 1;// Segment bas-gauche
        down_right() = 0; // Segment bas-droite
      break;
           case '4':
        case 4:
      //Afficher numéro 4
        up() = 1; // Segment haut-haut
        up_right() = 0;// Segment haut-droit
        up_left()  = 0; // Segment bas-droit
        middle() = 0;//Middle Segment
        down() = 1;// Segment bas-bas
        down_left() = 1;// Segment bas-gauche
        down_right() = 0; // Segment bas-droite
      break;
        case '3':
        case 3:
           //Afficher numéro 3
           up() = 0; // Segment haut-haut
           up_right() = 0;// Segment haut-droit
           up_left()  = 1; // Segment bas-droit
           middle() = 0;//Middle Segment
           down() = 0;// Segment bas-bas
           down_left() = 1;// Segment bas-gauche
           down_right() = 0; // Segment bas-droite
           break;
        case '2':
        case 2:
          //Afficher numéro 2
            up() = 0; // Segment haut-haut
            up_right() = 0;// Segment haut-droit
            up_left()  = 1; // Segment bas-droit
            middle() = 0;//Middle Segment
            down() = 0;// Segment bas-bas
            down_left() = 0;// Segment bas-gauche
            down_right() = 1; // Segment bas-droite
            break;
        case '1':
        case 1:
           //Afficher numéro 1
           up() = 1; // Segment haut-haut
           up_right() = 0;// Segment haut-droit
           up_left()  = 1; // Segment bas-droit
           middle() = 1;//Middle Segment
           down() = 1;// Segment bas-bas
           down_left() = 1;// Segment bas-gauche
           down_right() = 0; // Segment bas-droite
           break;
        case '0':
        case 0:
            //"Entrés" des segments
            up() = 0; // Segment haut-haut
            up_right() = 0;// Segment haut-droit
            up_left()  = 0; // Segment bas-droit
            middle() = 1;//Middle Segment
            down_left() = 0;// Segment bas-gauche
            down_right() = 0; // Segment bas-droite
            down() = 0;// Segment bas-bas
            break;
        case '6':
        case 6:
         //Afficher numéro 7
            up() = 0; // Segment haut-haut
            up_right() = 1;// Segment haut-droit
            up_left()  = 0; // Segment bas-droit
            middle() = 0;//Middle Segment
            down() = 0;// Segment bas-bas
            down_left() = 0;// Segment bas-gauche
            down_right() = 0; // Segment bas-droite
            break;
        case '7':
        case 7:
            up() = 0; // Segment haut-haut
            up_right() = 0;// Segment haut-droit
            up_left()  = 1; // Segment bas-droit
            middle() = 1;//Middle Segment
            down() = 1;// Segment bas-bas
            down_left() = 1;// Segment bas-gauche
            down_right() = 0; // Segment bas-droite
            break;
        case '8':
        case 8:
            up() = 0; // Segment haut-haut
            up_right() = 0;// Segment haut-droit
            up_left()  = 0; // Segment bas-droit
            middle() = 0;//Middle Segment
            down() = 0;// Segment bas-bas
            down_left() = 0;// Segment bas-gauche
            down_right() = 0; // Segment bas-droite
            break;
        case '9':
        case 9:
         //Afficher numéro 9
           //"Entrés" des segments
           up() = 0; // Segment haut-haut
           up_right() = 0;// Segment haut-droit
           up_left()  = 0; // Segment bas-droit
           middle() = 0;//Middle Segment
           down() = 0;// Segment bas-bas
           down_left() = 1;// Segment bas-gauche
           down_right() = 0; // Segment bas-droite
           break;
        case 'a':
        case 10:
            up() = 0; // Segment haut-haut
            up_left() = 0;  // Segment haut-gauche
            up_right() = 0; // Segment haut-droit
            middle() = 0;
            down_left() = 0; // Segment bas-gauche
            down_right() = 0;  // Segment bas-droit
            down() = 1; // Segment bas-bas
            break;
        case 'b':
        case 11:
            up() = 1; // Segment haut-haut
            up_left() = 0;  // Segment haut-gauche
            up_right() = 1; // Segment haut-droit
            middle() = 0;
            down_left() = 0; // Segment bas-gauche
            down_right() = 0;  // Segment bas-droit
            down() = 0; // Segment bas-bas
            break;
        case 'c':
        case 12:            
            up() = 0; // Segment haut-haut
            up_left() = 0;  // Segment haut-gauche
            up_right() = 1; // Segment haut-droit
            middle() = 1;
            down_left() = 0; // Segment bas-gauche
            down_right() = 1;  // Segment bas-droit
            down() = 0; // Segment bas-bas
            break;
        case 'd': 
        case 13://"Exécution des commandes" des segments
            up() = 1; // Segment haut-haut
            up_left() = 1;  // Segment haut-gauche
            up_right() = 0; // Segment haut-droit
            middle() = 0;
            down_left() = 0; // Segment bas-gauche
            down_right() = 0;  // Segment bas-droit
            down() = 0; // Segment bas-bas
            break;
        case 'e': 
        case 14://"Exécution des commandes" des segments
            up() = 0; // Segment haut-haut
            up_left() = 0;  // Segment haut-gauche
            up_right() = 1; // Segment haut-droit
            middle() = 0;
            down_left() = 0; // Segment bas-gauche
            down_right() = 1;  // Segment bas-droit
            down() = 0; // Segment bas-bas
            break;       
        case 'f':
        case 15://Afficher lettre F
            up() = 0; // Segment haut-haut
            up_left() = 0;  // Segment haut-gauche
            up_right() = 1; // Segment haut-droit
            middle() = 0;
            down_left() = 0; // Segment bas-gauche
            down_right() = 1;  // Segment bas-droit
            down() = 1; // Segment bas-bas
            break;
    }
}

void printDigit (int number)
{    
    printOneDigit(4, number % 16);
    
    number /= 16;
    printOneDigit(3, number % 16);
    
    number /= 16;
    printOneDigit(2, number%16);
    
    number /= 16;
    printOneDigit(1, number%16);
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

        
        printDigit(number);
    }
    
    return (EXIT_SUCCESS);
}

