#ifndef __SetMenu_H
#define __SetMenu_H

#include "stm32f4xx_hal.h"
#include "main.h"
#include "Key.h"
#include "LCD.h"
#include "UIProtact.h"
#include "String.h"
#include "Stdio.h"
#include "AT24C02.h"

void FirstSetMenu(void);
void SetMenu(void);
void Menu_Temp(void);
void Menu_Humi(void);
void Menu_Lux(void);
void Menu_CO2(void);
void Menu_Smoke(void);
void Menu_ReSetSystem(void);

#endif

