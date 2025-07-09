#ifndef __ADCSENSOR_H
#define __ADCSENSOR_H

#include "stm32f4xx_hal.h"
#include "adc.h"  // 确保包含CubeMX生成的ADC头文件
#include "math.h"

// 硬件定义（根据实际电路修改）
#define LightSensor_ADC_CHANNEL     ADC_CHANNEL_10  // PC0对应ADC1_IN10（F405）
#define MQ135Sensor_ADC_CHANNEL     ADC_CHANNEL_11  // PC0对应ADC1_IN11（F405）
#define MQ2Sensor_ADC_CHANNEL       ADC_CHANNEL_12  // PC0对应ADC1_IN12（F405）
#define READ_TIMES      10              // 均值滤波采样次数

uint16_t LightSensor_GetADCValue(void);
float LightSensor_GetLux(void);
uint16_t MQ135_GetData(void);
float MQ135_GetData_PPM(void);
uint16_t MQ2_GetData(void);
float MQ2_GetData_PPM(void);

#endif
