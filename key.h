#ifndef KEY_H
#define KEY_H

#include "main.h"

#define key_geshu   4

uint8_t key_Read(void);
void key_scan(void);

extern uint8_t key_val;
extern uint8_t key_down;
extern uint8_t key_up;

#endif
