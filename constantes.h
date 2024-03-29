/* 
 * File:   constantes.h
 * Author: arinfo
 *
 * Created on December 10, 2019, 9:42 AM
 */

#ifndef CONSTANTES_H
#define	CONSTANTES_H

#ifdef	__cplusplus
extern "C" {
#endif

// switchs
#define SW0   PORTFbits.RF3
#define SW1   PORTFbits.RF5
#define SW2   PORTFbits.RF4
#define SW3   PORTDbits.RD15
#define SW4     PORTDbits.RD14
#define SW5     PORTBbits.RB11
#define SW6     PORTBbits.RB10
#define SW7     PORTBbits.RB9
    
// Buttons
#define BUT_UP  PORTBbits.RB1
#define BUT_RIGHT   PORTBbits.RB8
#define BUT_DOWN    PORTAbits.RA15
#define BUT_LEFT    PORTBbits.RB0
#define BUT_MIDDLE  PORTFbits.RF0    
    
// 7-segments
#define up()  LATGbits.LATG12 // Segment haut-haut
#define up_right()  LATAbits.LATA14 // Segment haut-droit
#define up_left()  LATDbits.LATD7 // Segment haut-gauche
#define middle()  LATDbits.LATD13 //Middle Segment
#define down_right()  LATDbits.LATD6 // Segment bas-droit
#define down_left()  LATGbits.LATG15 // Segment bas-gauche
#define down()  LATGbits.LATG13 // Segment bas-bas

typedef enum State
{
    
    start,
    number_saved1,
    wait_secondNumber,
    calculate,
    print_result,
    done
} State;

typedef enum Operation
{
    plus,
    minus,
    divide,
    mult,
    no_operation
} Operation;

#ifdef	__cplusplus
    
}
#endif

#endif	/* CONSTANTES_H */

