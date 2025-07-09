#ifndef _SERVO_H
#define _SERVO_H

#include "tim.h"
#include "stm32f4xx_hal.h"
#include "main.h"

/* USER CODE BEGIN Private defines */
#define SERVO_MIN_PULSE 500    // 0.5ms (0度)
#define SERVO_MAX_PULSE 2500   // 2.5ms (180度)
#define SERVO_MIN_ANGLE 0      // 最小角度
#define SERVO_MAX_ANGLE 180    // 最大角度
/* USER CODE END Private defines */

void Servo_Init(void);
void Servo_Turn(uint16_t angle);
void Servo_TurnOn(void);
void Servo_TurnOFF(void);
//void Servo_On (void);
#endif

