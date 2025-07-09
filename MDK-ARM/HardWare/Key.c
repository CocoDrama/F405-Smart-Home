#include "Key.h"
#include "BEEP.h"

/* ��Ӧ Key_Num
 * Key1_Pin --> OK
 * Key2_Pin --> �˵�
 * Key3_Pin --> ��ѡ
 * Key4_Pin --> ��ѡ
 * Key5_Pin --> ����-
 * Key6_Pin --> ����+
 */
 
int Key_Scan(void)
{
	uint8_t Key_Num ;
	if(HAL_GPIO_ReadPin (GPIOC,Key1_Pin)==0)
	{
		HAL_Delay (50);
		if(HAL_GPIO_ReadPin (GPIOC,Key1_Pin)==0)
		{
			Key_Num = 1;   // ���ü�ֵ
			BEEP_BiBi();   // ����������
		}
	}
	else if(HAL_GPIO_ReadPin (GPIOC,Key2_Pin)==0)
	{
		HAL_Delay (50);
		if(HAL_GPIO_ReadPin (GPIOC,Key2_Pin)==0)
		{
			Key_Num = 2;   // ���ü�ֵ
			BEEP_BiBi();   // ����������
		}
	}
	else if(HAL_GPIO_ReadPin (GPIOC,Key3_Pin)==0)
	{
		HAL_Delay (50);
		if(HAL_GPIO_ReadPin (GPIOC,Key3_Pin)==0)
		{
			Key_Num = 3;   // ���ü�ֵ
			BEEP_BiBi();   // ����������
		}
	}
	else if(HAL_GPIO_ReadPin (GPIOC,Key4_Pin)==0)
	{
		HAL_Delay (50);
		if(HAL_GPIO_ReadPin (GPIOC,Key4_Pin)==0)
		{
			Key_Num = 4;   // ���ü�ֵ
			BEEP_BiBi();   // ����������
		}
	}
	else if(HAL_GPIO_ReadPin (GPIOC,Key5_Pin)==0)
	{
		HAL_Delay (50);
		if(HAL_GPIO_ReadPin (GPIOC,Key5_Pin)==0)
		{
			Key_Num = 5;   // ���ü�ֵ
			BEEP_BiBi();   // ����������
		}
	}
	else if(HAL_GPIO_ReadPin (GPIOC,Key6_Pin)==0)
	{
		HAL_Delay (50);
		if(HAL_GPIO_ReadPin (GPIOC,Key6_Pin)==0)
		{
			Key_Num = 6;   // ���ü�ֵ
			BEEP_BiBi();   // ����������
		}
	}
	else
	{
		Key_Num = 0;
	}
	return Key_Num;
}
