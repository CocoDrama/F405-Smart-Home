#ifndef __ADCSENSOR_H
#define __ADCSENSOR_H

#include "stm32f4xx_hal.h"
#include "adc.h"  // ȷ������CubeMX���ɵ�ADCͷ�ļ�
#include "math.h"

// Ӳ�����壨����ʵ�ʵ�·�޸ģ�
#define LightSensor_ADC_CHANNEL     ADC_CHANNEL_10  // PC0��ӦADC1_IN10��F405��
#define MQ135Sensor_ADC_CHANNEL     ADC_CHANNEL_11  // PC0��ӦADC1_IN11��F405��
#define MQ2Sensor_ADC_CHANNEL       ADC_CHANNEL_12  // PC0��ӦADC1_IN12��F405��
#define READ_TIMES      10              // ��ֵ�˲���������

uint16_t LightSensor_GetADCValue(void);
float LightSensor_GetLux(void);
uint16_t MQ135_GetData(void);
float MQ135_GetData_PPM(void);
uint16_t MQ2_GetData(void);
float MQ2_GetData_PPM(void);

#endif
