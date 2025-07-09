#ifndef __Relays_H
#define __Relays_H

#include "stm32f4xx_hal.h"
#include "main.h"

/******************
 * Relay1 --> 灯光
 * Relay2 --> 洗碗机
 * Relay3 --> 电视机
 * Relay4 --> 空调
 * Relay5 --> 热水器
 *****************/
 
void Relay1_ON(void);		//继电器1开启函数
void Relay1_OFF(void);	//继电器1关闭函数
void Relay2_ON(void);		//继电器2开启函数
void Relay2_OFF(void);	//继电器2关闭函数
void Relay3_ON(void);		//继电器3开启函数
void Relay3_OFF(void);	//继电器3关闭函数
void Relay4_ON(void);		//继电器4开启函数
void Relay4_OFF(void);	//继电器4关闭函数
void Relay5_ON(void);		//继电器5开启函数
void Relay5_OFF(void);	//继电器5关闭函数
void Relays_ON(void);		//继电器全开启函数
void Relays_OFF(void);	//继电器全关闭函数

#endif
