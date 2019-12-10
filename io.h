/* 
 * File:   io.h
 * Author: arinfo
 *
 * Created on December 10, 2019, 5:06 PM
 */

#ifndef IO_H
#define	IO_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "constantes.h"
    
int readNumber();

enum State readButtonMiddle(enum State state);

enum Operation readButton();

void printDigit (int number);

void printOneDigit (int nDigit, char letter);

#ifdef	__cplusplus
}
#endif

#endif	/* IO_H */

