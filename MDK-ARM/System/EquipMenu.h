#ifndef __EquipMenu_H
#define __EquipMenu_H

#include "stm32f4xx_hal.h"
#include "main.h"
#include "Key.h"
#include "LCD.h"
#include "UIProtact.h"
#include "String.h"
#include "Stdio.h"
#include "Relays.h"
#include "Servo.h"

extern int Light_ActMode ;
extern int Air_ActMode ;
extern int Window_ActMode ;
extern int Eat_ActMode ;
extern int TV_ActMode ;
extern int HotWater_ActMode ;

void EquipSetMenu(void);
void Light_Ctrl(void);
void Air_Ctrl(void);
void Window_Ctrl(void);
void Eat_Ctrl(void);
void TV_Ctrl(void);
void HotWater_Ctrl(void);


#endif

