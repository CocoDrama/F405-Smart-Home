#ifndef __UIProtact_H
#define __UIProtact_H

#include "stm32f4xx_hal.h"
#include "main.h"
#include "tim.h"
#include "Key.h"
#include "LCD.h"
#include "LED.h"
#include "IoT.h"
#include "String.h"
#include "Stdio.h"
#include "EquipMenu.h"
#include "MonitorMenu.h" 
#include "SetMenu.h" 

void WiFiOnLine(void);
void WiFiConecting(void);
void WiFiOffLine(void);
void HomeUI_Protract(void);
void HouseArt(void);
void EquipManageUnSelect(void);
void EquipManageSelected(void);
void MonitorUnSelect(void);
void MonitorSelected(void);
void SetUnSelect(void);
void SetSelected(void);
void MenuChecking(void);

#endif

