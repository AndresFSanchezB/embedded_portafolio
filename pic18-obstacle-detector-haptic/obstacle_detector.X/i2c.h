/* Project name: obstacle_detector
 * 
 * Comment: This header set the initial configuration for the I2C comunication
 *  protocol for PIC18f4550.
 */

/* 
 * File: i2c.h  
 * Author: Andrés Sánchez
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef i2c
#define	i2c

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h> // includes the typedefs that replace the primitive types.

#define Pin_in 1;
#define Pin_our 0;

// prototypes for I2C comunication protocol

void I2C_Master_Init(uint32_t clock);
void I2C_Master_Wait(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Repeated_Start(void);
void I2C_Master_Write(uint8_t dato);
uint8_t I2C_Master_Read(uint8_t ACK);

#endif	/* i2c */

