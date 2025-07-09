#ifndef __Key_H
#define __Key_H

#include "stm32f4xx.h"                  // Device header
#include "main.h"
#include "BEEP.h"

/* KEY1 --> PB5
 * KEY2 --> PB6
 * KEY3 --> PB7
 * KEY4 --> PB8
 * KEY4 --> PB9
 */

int Key_Scan(void);

#endif
