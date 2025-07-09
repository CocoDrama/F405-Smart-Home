#include "Key.h"
#include "BEEP.h"

/* 对应 Key_Num
 * Key1_Pin --> OK
 * Key2_Pin --> 菜单
 * Key3_Pin --> 下选
 * Key4_Pin --> 上选
 * Key5_Pin --> 数据-
 * Key6_Pin --> 数据+
 */
 
int Key_Scan(void)
{
	uint8_t Key_Num ;
	if(HAL_GPIO_ReadPin (GPIOC,Key1_Pin)==0)
	{
		HAL_Delay (50);
		if(HAL_GPIO_ReadPin (GPIOC,Key1_Pin)==0)
		{
			Key_Num = 1;   // 设置键值
			BEEP_BiBi();   // 蜂鸣器鸣响
		}
	}
	else if(HAL_GPIO_ReadPin (GPIOC,Key2_Pin)==0)
	{
		HAL_Delay (50);
		if(HAL_GPIO_ReadPin (GPIOC,Key2_Pin)==0)
		{
			Key_Num = 2;   // 设置键值
			BEEP_BiBi();   // 蜂鸣器鸣响
		}
	}
	else if(HAL_GPIO_ReadPin (GPIOC,Key3_Pin)==0)
	{
		HAL_Delay (50);
		if(HAL_GPIO_ReadPin (GPIOC,Key3_Pin)==0)
		{
			Key_Num = 3;   // 设置键值
			BEEP_BiBi();   // 蜂鸣器鸣响
		}
	}
	else if(HAL_GPIO_ReadPin (GPIOC,Key4_Pin)==0)
	{
		HAL_Delay (50);
		if(HAL_GPIO_ReadPin (GPIOC,Key4_Pin)==0)
		{
			Key_Num = 4;   // 设置键值
			BEEP_BiBi();   // 蜂鸣器鸣响
		}
	}
	else if(HAL_GPIO_ReadPin (GPIOC,Key5_Pin)==0)
	{
		HAL_Delay (50);
		if(HAL_GPIO_ReadPin (GPIOC,Key5_Pin)==0)
		{
			Key_Num = 5;   // 设置键值
			BEEP_BiBi();   // 蜂鸣器鸣响
		}
	}
	else if(HAL_GPIO_ReadPin (GPIOC,Key6_Pin)==0)
	{
		HAL_Delay (50);
		if(HAL_GPIO_ReadPin (GPIOC,Key6_Pin)==0)
		{
			Key_Num = 6;   // 设置键值
			BEEP_BiBi();   // 蜂鸣器鸣响
		}
	}
	else
	{
		Key_Num = 0;
	}
	return Key_Num;
}
