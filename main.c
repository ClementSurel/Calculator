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

void printDigit (char letter)
{
    // Activate the last digit
    TRISBbits.TRISB12 = 0;
    LATBbits.LATB12 = 0;
    
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
            up() = 0; // Segment haut-haut
            up_left() = 0;  // Segment haut-gauche
            up_right() = 0; // Segment haut-droit
            middle() = 0;
            down_left() = 0; // Segment bas-gauche
            down_right() = 0;  // Segment bas-droit
            down() = 1; // Segment bas-bas
            break;
        case 'b':
            up() = 1; // Segment haut-haut
            up_left() = 0;  // Segment haut-gauche
            up_right() = 1; // Segment haut-droit
            middle() = 0;
            down_left() = 0; // Segment bas-gauche
            down_right() = 0;  // Segment bas-droit
            down() = 0; // Segment bas-bas
            break;
        case 'c':            
            up() = 0; // Segment haut-haut
            up_left() = 0;  // Segment haut-gauche
            up_right() = 1; // Segment haut-droit
            middle() = 1;
            down_left() = 0; // Segment bas-gauche
            down_right() = 1;  // Segment bas-droit
            down() = 0; // Segment bas-bas
            break;
        case 'd':            //"Exécution des commandes" des segments
            up() = 1; // Segment haut-haut
            up_left() = 1;  // Segment haut-gauche
            up_right() = 0; // Segment haut-droit
            middle() = 0;
            down_left() = 0; // Segment bas-gauche
            down_right() = 0;  // Segment bas-droit
            down() = 0; // Segment bas-bas
            break;
        case 'e':            //"Exécution des commandes" des segments
            up() = 0; // Segment haut-haut
            up_left() = 0;  // Segment haut-gauche
            up_right() = 1; // Segment haut-droit
            middle() = 0;
            down_left() = 0; // Segment bas-gauche
            down_right() = 1;  // Segment bas-droit
            down() = 0; // Segment bas-bas
            break;       
        case 'f': //Afficher lettre F
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
    
    TRISFbits.TRISF3 = 1;
    TRISFbits.TRISF5 = 1;
    TRISFbits.TRISF4 = 1;
    TRISDbits.TRISD15 = 1; 
    
    int number; 
    
    while(1)
    {
        //activateRGB(32, 54, 78);

        number = 0;
        
        if (SW0 == 1)
            number++;
        if (SW1 == 1)
            number += 2;
        if (SW2 == 1)
            number += 4;
        if (SW3 == 1)
            number += 8;
                
        if (number == 10)
            number = 'a';
        else if (number == 11)
            number = 'b';
        else if (number == 12)
            number = 'c';
        else if (number == 13)
            number = 'd';
        else if (number == 14)
            number = 'e';
        else if (number == 15)
            number = 'f';
            
        printDigit(number);
    }
    
    return (EXIT_SUCCESS);
}

