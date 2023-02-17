/* 
 * File:   dfplayer.h
 * Author: LksDev
 *
 * Created on 17. Februar 2023, 15:36
 */

#ifndef DFPLAYER_H
#define	DFPLAYER_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "config.h"


void InitDFPlayer(char argTracksNumber);
void Play(void);
void Stop(void);
void NextTrack(void);
void PreviousTrack(void);
void RandomTrack(void);
void SendData(void);
void FillChecksum();

// Byte 0: Start byte 0x7E
// Byte 1: Version
// Byte 2: the number of bytes after ?Len? (Checksums are not counted)
// Byte 3: Commands
// Byte 4: Command feedback
// Byte 5: Parameter 1 high byte
// Byte 6: Parameter 2 low byte
// Byte 7: Checksum high byte
// Byte 8: Checksum low byte
// Byte 9: End byte 0xEF
char serialData[10] = {	0x7E, 0xFF, 06, 00, 00, 00, 00, 00, 00, 0xEF};

#ifdef	__cplusplus
}
#endif

#endif	/* DFPLAYER_H */

