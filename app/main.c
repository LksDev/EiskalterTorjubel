/*
 * File:   main.c
 * Author: LksDev
 *
 * Created on 13. Februar 2023, 18:29
 */


#include "main.h"

void main(void) {
    
    initIO();
    initEUSART();
    initINT();
    
    
    while(1){
        
    
    }
    return;
}

void initIO(){
    // 16MHz (internal clock)- _XTAL_FREQ ebenfalls auf 16MHz
    OSCCONbits.SCS = 0b10;
    OSCCONbits.IRCF = 0b1111;
    // Analogmodul ausschalten für alle PORTs
    ANSELA = 0x00;
    ANSELC = 0x00;
    
    /*
     RC0 = LED - OUT
     RC1 = - x
     RC2 = - x
     RC3 = Guest Gate - IN 
     RC4 = Home Gate - IN
     RC5 = - x
     */
    TRISCbits.TRISC0 = 0;    
    PORTCbits.RC0 = 0;
    
    
    /*
     RA0 = ICSPDAT      - X
     RA1 = ICSPCLK      - X
     RA2 =      - x
     RA3 = MCLR         - X
     RA4 = Home Gate    - IN
     RA5 = Guest Gate   - IN
     */
    TRISAbits.TRISA4 = 1;
    TRISAbits.TRISA5 = 1;
    
    
    IOCAPbits.IOCAP4 = 0;
    IOCANbits.IOCAN4 = ~IOCAPbits.IOCAP4;
    IOCAPbits.IOCAP5 = 0;
    IOCANbits.IOCAN5 = ~IOCAPbits.IOCAP5;
    
    
    /*
     
     
    TRISA = 0x34;
    // Pull-Up Resistor enable für RA2/RA4/RA5
    WPUA = 0x34;
    // Peripheral Interrupt Enable bit
    */
}

void initINT(void){

    
    
    // Interrupt enable
    //INTCON |= 0xD2;         //Global-/Peripherie & INT External Interrupt enable
    INTCONbits.IOCIE    = 1;
    INTCONbits.INTE     = 0;
    INTCONbits.PEIE     = 1;
    INTCONbits.GIE      = 1;
    INTCONbits.PEIE     = 1;
}

void interrupt ISR_PORTA(void){

    

}