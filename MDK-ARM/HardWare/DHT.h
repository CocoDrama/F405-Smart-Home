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

//���״̬����
#define OUT 1
#define IN  0

//����DHT11��������ߵ͵�ƽ
#define DHT11_Low  HAL_GPIO_WritePin(DHT11_GPIO_PORT, DHT11_GPIO_PIN, GPIO_PIN_RESET)
#define DHT11_High HAL_GPIO_WritePin(DHT11_GPIO_PORT, DHT11_GPIO_PIN, GPIO_PIN_SET)

u8 DHT11_Init(void);					//��ʼ��DHT11
u8 DHT11_Read_Data(u8 *Temp,u8 *Humi);	//��ȡ��ʪ������
u8 DHT11_Read_Byte(void);				//��ȡһ���ֽڵ�����
u8 DHT11_Read_Bit(void);				//��ȡһλ������
void DHT11_Mode(u8 mode);				//DHT11�������ģʽ����
u8 DHT11_Check(void);					//���DHT11
void DHT11_Rst(void);					//��λDHT11   

#endif
