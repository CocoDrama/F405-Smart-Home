#ifndef __AT24C02_H
#define __AT24C02_H

#include "stm32f4xx_hal.h"
#include "main.h"
#include "i2c.h"
#include <string.h>

// ���� AT24C02 ��ַ
#define AT24C02_ADDRESS 0xA0
// ������ֵ�洢��ַ
#define THRESHOLDS_ADDRESS 0x00
#define INIT_FLAG_ADDRESS  0x50  // ��ʼ����־λ��ַ

// ��������
void I2C_Init(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef AT24C02_WriteByte(I2C_HandleTypeDef *hi2c, uint16_t memAddress, uint8_t data);
HAL_StatusTypeDef AT24C02_ReadByte(I2C_HandleTypeDef *hi2c, uint16_t memAddress, uint8_t *data);
HAL_StatusTypeDef AT24C02_WritePage(I2C_HandleTypeDef *hi2c, uint16_t memAddress, uint8_t *data, uint16_t size);
HAL_StatusTypeDef AT24C02_ReadBuffer(I2C_HandleTypeDef *hi2c, uint16_t memAddress, uint8_t *data, uint16_t size);
uint8_t AT24C02_IsDeviceReady(I2C_HandleTypeDef *hi2c);


// ��ֵ�ṹ�嶨��
typedef struct {
    int32_t HighTemp;
    int32_t LowTemp;
    int32_t HighHumi;
    int32_t LowHumi;
    float HighLux;
    float HighCO2;
    float HighSmoke;
} Thresholds_TypeDef;

extern Thresholds_TypeDef Thresholds;
// ��������
uint8_t AT24C02_Init(I2C_HandleTypeDef *hi2c);
uint8_t AT24C02_LoadThresholds(Thresholds_TypeDef *thresholds);
uint8_t AT24C02_SaveThresholds(Thresholds_TypeDef *thresholds);
uint8_t AT24C02_IsFirstRun(void);
static uint16_t crc16(const uint8_t *data, uint16_t length);

#endif /* __AT24C02_H */
