/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef lcdi2c
#define	lcdi2c

#include <xc.h> // include processor files - each processor file is guarded.  
// P7 P6 P5 P4 P3 P2 P1 P0 (PCF8574)
// D7 D6 D5 D4 K  E  RW RS (LCD16X2)   

// RS: REGISTER SELECT
// RS = 0 (IR:Instruccion Register) - Registro para configuracion de pantalla
// RS = 1 (DR:Data Register)        - Registro para acceder alas memorias RAM ROM

#define PCF8574_ADDRESS 0x7E //0b01001110
//#define PCF8574_ADDRESS 0x40 //0b01000000 

#define  PIN_RS    0x01
#define  PIN_RW    0x02
#define  PIN_EN    0x04
#define  BACKLIGHT 0x08

//Todos estos valores los saco del datasheet del controlador ST7920
#define DISPLAY_CLEAR   0x01 //0b00000001 - 2ms
#define MODE_4_BITS     0x20 //0b00100000 - 37us
#define DISPLAY_ON      0x0C //0b00001100 - 37us
#define ENTRY_MODE_SET  0x06 //0b00000110 - 37us
#define RETURN_HOME     0x02 //0b00000010 - 1.52ms

// RS: REGISTER SELECT
// RS = 0 (IR:Instruccion Register) - Registro para configuracion de pantalla
// RS = 1 (DR:Data Register)        - Registro para acceder alas memorias RAM ROM

void PCF8574_Write(uint8_t byte);
void LCD_I2C_WriteData(uint8_t data);
void LCD_I2C_WriteCommand(uint8_t command);
void LCD_I2C_Init(void);
void LCD_I2C_ClearText(void);
void LCD_I2C_WriteText(uint8_t row, uint8_t col, char* string);



#endif	/* lcdi2c */

