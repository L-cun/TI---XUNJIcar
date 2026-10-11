#ifndef _XUNJI_H_
#define _XUNJI_H_
#include "ti_msp_dl_config.h"

void Get_Sensors(void);

extern uint8_t L4, L3, L2, L1, R1, R2, R3, R4;
extern uint8_t Line_flag ;//=1表示有线，=0表示没线
void Trace(void);
void Get_Sensors(void);
extern uint8_t x;
extern uint8_t flag;
#endif