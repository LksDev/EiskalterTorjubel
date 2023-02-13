/*
 * File:   main.c
 * Author: Lukas
 *
 * Created on 13. Februar 2023, 18:29
 */


#include <xc.h>
#include "main.h"

void main(void) {
    
    initIO();
    while(1){
        for(int i=0; i<10; i++){
        PORTCbits.RC0 = 1;
        __delay_ms(500);
        PORTCbits.RC0 = 0;
        __delay_ms(500);    
        }
    }
    return;
}

void initIO(){
    // -> bull shit >> 1MHz eingestellt - _XTAL_FREQ ebenfalls auf 1MHz
    OSCCON |= 0b01111010;
    // Analogmodul ausschalten für alle PORTs
    ANSELA = 0x00;
    ANSELC = 0x00;
    /*
     RC0 = LED - OUT
     RC1 = - x
     RC2 = - x
     RC3 = - x
     RC4 = - x
     RC5 = - x
     */
    TRISCbits.TRISC0 = 0;  
    
    PORTCbits.RC0 = 0;
    
    
    /*
     RA0 = ICSPDAT      - X
     RA1 = ICSPCLK      - X
     RA2 = SWTICH_1     - IN
     RA3 = MCLR         - X
     RA4 = SWTICH_2     - IN
     RA5 = SWTICH_3     - IN
     
    TRISA = 0x34;
    // Pull-Up Resistor enable für RA2/RA4/RA5
    WPUA = 0x34;
    // Peripheral Interrupt Enable bit
    
    // Pull-Up Resistor global enable
    OPTION_REGbits.nWPUEN = 0;
    // Interrupt on falling edge of INT pin
    OPTION_REGbits.INTEDG = 0;
    
    // TMR0 configuration
    OPTION_REGbits.PSA = 0;
    // Prescaler 256 
    OPTION_REGbits.PS0 = 1;
    OPTION_REGbits.PS1 = 1;
    OPTION_REGbits.PS2 = 1;
    // Interne Source Clock Fosc/ 4
    OPTION_REGbits.TMR0CS = 0;
    // Preload value
    TMR0 = 5;
    // TMR disable. Enable if BTE device connected
    INTCONbits.TMR0IE = 0;
    
    // Interrupt enable
    INTCON |= 0xD2;         //Global-/Peripherie & INT External Interrupt enable
    INTCONbits.IOCIE    = 1;
    INTCONbits.INTE     = 1;
     * 
     * 
     */
}

