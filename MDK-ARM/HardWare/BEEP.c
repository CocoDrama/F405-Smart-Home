#include "BEEP.h"

/****************·äÃùÆ÷¿ªÆôº¯Êý****************/
void BEEP_ON(void)
{
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB, Beep_Pin, GPIO_PIN_SET);
}

/****************·äÃùÆ÷¹Ø±Õº¯Êý****************/
void BEEP_OFF(void)
{
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB, Beep_Pin, GPIO_PIN_RESET);
}

/****************·äÃùÆ÷Ãù½Ðº¯Êý****************/
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

