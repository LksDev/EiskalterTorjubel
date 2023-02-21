/* 
 * File:   main.h
 * Author: LksDev
 *
 * Created on 13. Februar 2023, 18:29
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

    
#include "config.h"
#include "EUSART.h"
#include "dfplayer.h"

void initIO(void);
void initINT(void);
void interrupt ISR_PORTA(void);

#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

