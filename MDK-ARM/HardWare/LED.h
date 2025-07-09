#ifndef __LED_H
#define __LED_H

#include "stm32f4xx.h"                  // Device header
#include "main.h"

void LED_ON(void);
void LED_OFF(void);
void LED_Flashing(void);
void LED_FastFlashing(void);
void LED_LowFlashing(void);

#endif
