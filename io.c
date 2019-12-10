#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <sys/attribs.h>
#include "io.h"

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

int readNumber()
{
    int number=0;
    
    if (SW0==1)
        number=1;
    if(SW1==1)
        number=2;
    if (SW2==1)
        number=3;
    if(SW3==1)
        number=4;
    if (SW4==1)
        number=5;
    if(SW5==1)
        number=6;
    
    printDigit(number);
            
    return number;    
}

State readButtonMiddle(State state)
{
    if (BUT_MIDDLE)
    {
       state=state+1;
    }
    
    return state;
}

Operation readButton()
{
    Operation operation = no_operation;
    
    if (BUT_RIGHT)
        operation= plus;
    if (BUT_LEFT)
        operation= minus;
    if (BUT_UP)
        operation= divide;
    if (BUT_DOWN)
        operation=mult;
    
    return operation;
}



