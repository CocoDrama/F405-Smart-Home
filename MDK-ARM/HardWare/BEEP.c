#include "BEEP.h"

/****************��������������****************/
void BEEP_ON(void)
{
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB, Beep_Pin, GPIO_PIN_SET);
}

/****************�������رպ���****************/
void BEEP_OFF(void)
{
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB, Beep_Pin, GPIO_PIN_RESET);
}

/****************���������к���****************/
void BEEP_Alarm(void)
{
	HAL_GPIO_WritePin(GPIOB, Beep_Pin, GPIO_PIN_SET);
	HAL_Delay (50);
	HAL_GPIO_WritePin(GPIOB, Beep_Pin, GPIO_PIN_RESET);
	HAL_Delay (50);
}

void BEEP_BiBi(void)
{
	HAL_GPIO_WritePin(GPIOB, Beep_Pin, GPIO_PIN_SET);
	HAL_Delay (50);
	HAL_GPIO_WritePin(GPIOB, Beep_Pin, GPIO_PIN_RESET);
}

