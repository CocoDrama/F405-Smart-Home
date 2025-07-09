#ifndef __Relays_H
#define __Relays_H

#include "stm32f4xx_hal.h"
#include "main.h"

/******************
 * Relay1 --> �ƹ�
 * Relay2 --> ϴ���
 * Relay3 --> ���ӻ�
 * Relay4 --> �յ�
 * Relay5 --> ��ˮ��
 *****************/
 
void Relay1_ON(void);		//�̵���1��������
void Relay1_OFF(void);	//�̵���1�رպ���
void Relay2_ON(void);		//�̵���2��������
void Relay2_OFF(void);	//�̵���2�رպ���
void Relay3_ON(void);		//�̵���3��������
void Relay3_OFF(void);	//�̵���3�رպ���
void Relay4_ON(void);		//�̵���4��������
void Relay4_OFF(void);	//�̵���4�رպ���
void Relay5_ON(void);		//�̵���5��������
void Relay5_OFF(void);	//�̵���5�رպ���
void Relays_ON(void);		//�̵���ȫ��������
void Relays_OFF(void);	//�̵���ȫ�رպ���

#endif
