#ifndef __DHT_H
#define __DHT_H

#include "stm32f4xx_hal.h"
#include "main.h"

#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t

#define DHT11_GPIO_PORT  DHT11_GPIO_Port
#define DHT11_GPIO_PIN   DHT11_Pin
#define DHT11_GPIO_CLK   RCC_APB2Periph_GPIOA

//输出状态定义
#define OUT 1
#define IN  0

//控制DHT11引脚输出高低电平
#define DHT11_Low  HAL_GPIO_WritePin(DHT11_GPIO_PORT, DHT11_GPIO_PIN, GPIO_PIN_RESET)
#define DHT11_High HAL_GPIO_WritePin(DHT11_GPIO_PORT, DHT11_GPIO_PIN, GPIO_PIN_SET)

u8 DHT11_Init(void);					//初始化DHT11
u8 DHT11_Read_Data(u8 *Temp,u8 *Humi);	//读取温湿度数据
u8 DHT11_Read_Byte(void);				//读取一个字节的数据
u8 DHT11_Read_Bit(void);				//读取一位的数据
void DHT11_Mode(u8 mode);				//DHT11引脚输出模式控制
u8 DHT11_Check(void);					//检测DHT11
void DHT11_Rst(void);					//复位DHT11   

#endif
