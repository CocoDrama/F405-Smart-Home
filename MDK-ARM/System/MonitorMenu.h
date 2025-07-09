#ifndef __MonitorMenu_H
#define __MonitorMenu_H

#include "stm32f4xx_hal.h"
#include "main.h"
#include "Key.h"
#include "LCD.h"
#include "UIProtact.h"
#include "String.h"
#include "Stdio.h"
#include "AdcSensor.h"
#include "DHT.h"
#include <stdio.h>
#include "SetMenu.h"

extern u8 Temp,Humi;
extern float Lux,CO2,Smoke;
extern int AutoMode_SideLight,AutoMode_Window,AutoMode_Air;

#define AirAutoModeOn        1
#define AirAutoModeOff       0
#define WindowAutoModeOn     1
#define WindowAutoModeOff    0
#define SideLightAutoModeOn  1
#define SideLightAutoModeOff 0

void DataMonitoring(void);

#endif

