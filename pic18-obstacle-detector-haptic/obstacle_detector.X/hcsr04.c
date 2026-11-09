#include <xc.h>
#include <stdint.h>
#include "config.h"
#include "hcsr04.h"

#define NUM_MEDICIONES_FILTRO 5

void HC_SR04_Init(void){
    TRIS_PIN_TRIG=0;//trig salida
    TRIS_PIN_ECHO=1;//echo entrada
}

uint16_t ObtenerDistancia(void){
    /*
     * segun datasheet:   range = high_level_time * sound velocity/2;
     * range->la distancia 
     * high_level_time-> tiempo en alto que esta la señal del eco (TMR0)
     * velocity-> velocidad del sonido "340m/s" o "0.034cm/us"
     * Entonces la formula es: Distancia=TMR0*0.034/2
     *                         Distancia=TMR0*0.017
     */
     
    float duracion;
    float distancia;
    float distancia_total = 0;
    
    float distancias[NUM_MEDICIONES_FILTRO];
    uint16_t tiempo;
    
    for (int i = 0; i < NUM_MEDICIONES_FILTRO; i++) {
        PIN_TRIG=1;
        __delay_us(10);
        PIN_TRIG=0;

        while(PIN_ECHO == 0);
        TMR0=0;
        T0CONbits.TMR0ON=1;
    
        while(PIN_ECHO==1);
        T0CONbits.TMR0ON=0;
    
        tiempo = TMR0;
        distancias[i] = tiempo * 0.017/2;
    }
        
      float distancia_promedio = 0;
      for (int i = 0; i < NUM_MEDICIONES_FILTRO; i++) {
        distancia_promedio += distancias[i];
    }
    distancia_promedio /= NUM_MEDICIONES_FILTRO;
         
        return (uint16_t)distancia_promedio;
}

