/* 
 * File:   EUSART.c
 * Author: LksDev
 *
 * Created on 13. Februar 2023, 18:29
 */

#include "EUSART.h"

void initEUSART(){
    // Analog Modul disable
    ANSELC = 0x00;
    // On which pin are Rx/ Tx  mode
    APFCON0bits.RXDTSEL =0;     // 1= RA1 - 0= RC5 
    APFCON0bits.TXCKSEL =0;     // 1= RA0 - 0= RC4
    // Input 
    TRISCbits.TRISC4 =1;
    TRISCbits.TRISC5 =1;
    
    // Transmitter Module
    TXSTAbits.SYNC = 0;     // Async operation
    TXSTAbits.TX9 = 0;      // Only 9bits
    TXSTAbits.TXEN = 1;     // Enable transmitter
    
    // Receiver Module
    RCSTAbits.RX9 =0;       // Only 9 bits receive
    RCSTAbits.CREN =1;      // Enable receiver
    RCSTAbits.SPEN =1;      // Enable EUSART module
    
    // Interrupt enable
    INTCON |= 0xC0;         // Global- & Peripherie Interrupt enable
    PIE1bits.RCIE = 1;      // Enable Receive Interrupt
    
    BAUDCONbits.BRG16 = 0;
    TXSTAbits.BRGH =0;
    SPBRGL = 25;
    SPBRGH = 0;
}

void sendChar(char c){
    while (TXSTAbits.TRMT == 0);    // Wait for buffer to be empty
    TXREG = c;       
}