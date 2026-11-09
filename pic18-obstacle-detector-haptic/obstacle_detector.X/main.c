/*
 * File:   main.c
 * Author: raven
 *
 * Created on 28 de febrero de 2024, 11:33 PM
 */

#include <xc.h>
#include <stdint.h> //para uint8_t,uint16_t,etc
#include <stdio.h>  //para la funcion "sprintf"
#include "config.h"
#include "timerint.h"
#include "lcdi2c.h"
#include "hcsr04.h"
#include "usart.h"

//definitions

#define unM     1
#define dosM    2
#define tresM   3

//Global Variables
char buff[16];
uint16_t distancia;
int uartSent = 0;

void setup(void){
    
    ADCON1 = 0x0F;    //todos los pines del PORTA,PORTB como digitales
    OSCCON = 0x72;   //oscilador interno a 8MHz
    SPPCONbits.SPPEN = 0;
    TRISD = 0x07;
    PORTD = 0x00;
    CMCON=0x07;
    
    
    //function calling
    HC_SR04_Init();
    TMR0_Init();
    LCD_I2C_Init(); 
    Uart_Init(9600);
    
}
void main(void) {
    setup();
    
    while(1){
        
       int portvalue = PORTD; 
       
        switch(portvalue){
            
            case unM:
                
                if(!uartSent){
                    //Uart_Send_String("a");
                    Uart_Send_Char('a');
                    Uart_Send_String("\r\n");
                    uartSent = 1;    
                }
                
                do {
                    
                    distancia = ObtenerDistancia();
                    LCD_I2C_ClearText();
                    sprintf(buff, "%2d", distancia);
                    LCD_I2C_WriteText(0, 0, "Deteccion <= 1 m");
                    LCD_I2C_WriteText(1, 0, "Dist:");
                    LCD_I2C_WriteText(1, 11, buff);
                     LCD_I2C_WriteText(1, 14, "cm");
                    //Uart_Send_String(buff);
                    __delay_ms(100);
                if (distancia <= 100) {
                    //printf("%i\n\r",distancia);
                    
        
       
                    Uart_Send_String(buff);
                    Uart_Send_String("\r\n");
                    __delay_ms(100);
                }       
                else {
                    Uart_Send_String("100");
                    Uart_Send_String("\r\n");
                    __delay_ms(100);
       
                }
                // Actualizar el valor de portvalue
                portvalue = PORTD;
                } while (portvalue == 0b0001);
               
                LCD_I2C_ClearText(); 
                uartSent = 0;
                break;
            
            case dosM :
                
                if(!uartSent){
                    //Uart_Send_String("b");
                    Uart_Send_Char('b');
                    Uart_Send_String("\r\n");
                    uartSent = 1;    
                }
                
                do {
                    
                    distancia = ObtenerDistancia();
                    LCD_I2C_ClearText();
                    sprintf(buff, "%2d", distancia);
                    LCD_I2C_WriteText(0, 0, "Deteccion <= 2 m");
                    LCD_I2C_WriteText(1, 0, "Dist:");
                    LCD_I2C_WriteText(1, 11, buff);
                     LCD_I2C_WriteText(1, 14, "cm");
                    //Uart_Send_String(buff);
                    __delay_ms(100);
                if (distancia <= 200) {
        
       
                    Uart_Send_String(buff);
                    Uart_Send_String("\r\n");
                    __delay_ms(100);
                }       
                else {
                    Uart_Send_String("200");
                    Uart_Send_String("\r\n");
                    __delay_ms(100);
       
                }
                // Actualizar el valor de portvalue
                portvalue = PORTD;
                } while (portvalue == 0b0010);
               
                LCD_I2C_ClearText();
                uartSent = 0;
                break;
            
            default: 
                //LCD_I2C_ClearText();
                LCD_I2C_WriteText(0,0,"Ingrese la");
                LCD_I2C_WriteText(1,0,"configuracion");
                Uart_Send_String("0");
                Uart_Send_String("\r\n");
                uartSent = 0;
                __delay_ms(100);
                break;    
        }
        
    }
        
}
