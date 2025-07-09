#ifndef __Work_H
#define __Work_H

#include "stm32f4xx_hal.h"
#include "main.h"
#include "Key.h"
#include "LCD.h"
#include "UIProtact.h"
#include "String.h"
#include "Stdio.h"
#include "LED.h"
#include "BEEP.h"
#include "Servo.h"
#include "Relays.h"
#include "EquipMenu.h"
#include "ASRPRO.h"
#include "BodySW.h"
#include "MonitorMenu.h" 
#include "IoT.h" 

extern int IoTSwitchMode_Light ;
extern int IoTSwitchMode_Light ;
extern int IoTSwitchMode_SideLight;
extern int IoTSwitchMode_SideLight;
extern int IoTSwitchMode_TV ;
extern int IoTSwitchMode_TV ;
extern int IoTSwitchMode_Hot ;
extern int IoTSwitchMode_Hot ;
extern int IoTSwitchMode_Window ;
extern int IoTSwitchMode_Window ;
extern int IoTSwitchMode_Air ;
extern int IoTSwitchMode_Air ;

void SyetemWorking(void);
void WiFiYorN(void);

#endif

