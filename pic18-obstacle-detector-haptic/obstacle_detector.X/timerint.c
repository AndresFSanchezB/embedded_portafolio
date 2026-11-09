#include <xc.h>
#include <stdint.h>
#include "config.h"
#include "timerint.h"


void TMR0_Init(){ 
    T0CON = 0x88;//configuro los registros del TMR0 como contador
    TMR0 = 0;  
}


