/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 
 */

/* 
 * File:   timerint.h
 * Author: Andres Sanchez
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef timerint
#define	timerint

#include <xc.h> // include processor files - each processor file is guarded.  

void TMR0_Init(void);

#endif	/* timerint */

