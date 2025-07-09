#include "LED.h"

/****************LED��������****************/
void LED_ON(void)
{
	HAL_GPIO_WritePin(GPIOB, LED_Pin, GPIO_PIN_SET);
}

/****************LED�رպ���****************/
void LED_OFF(void)
{
	HAL_GPIO_WritePin(GPIOB, LED_Pin, GPIO_PIN_RESET);
}

/****************LED��˸����****************/
void LED_Flashing(void)
{
	HAL_GPIO_WritePin(GPIOB, LED_Pin, GPIO_PIN_SET);
	HAL_Delay (200);
	HAL_GPIO_WritePin(GPIOB, LED_Pin, GPIO_PIN_RESET);
	HAL_Delay (200);
}

void LED_FastFlashing(void)
{
	HAL_GPIO_WritePin(GPIOB, LED_Pin, GPIO_PIN_SET);
	HAL_Delay (200);
	HAL_GPIO_WritePin(GPIOB, LED_Pin, GPIO_PIN_RESET);
	HAL_Delay (50);
}

void LED_LowFlashing(void)
{
	HAL_GPIO_WritePin(GPIOB, LED_Pin, GPIO_PIN_SET);
	HAL_Delay (500);
	HAL_GPIO_WritePin(GPIOB, LED_Pin, GPIO_PIN_RESET);
	HAL_Delay (200);
}

