#include "Relays.h"

/****************�̵���1�رպ���****************/
void Relay1_OFF(void)
{
	HAL_GPIO_WritePin(GPIOB, JDQ1_Pin, GPIO_PIN_RESET);
}

/****************�̵���1��������****************/
void Relay1_ON(void)
{
	HAL_GPIO_WritePin(GPIOB, JDQ1_Pin, GPIO_PIN_SET);
}

/****************�̵���2�رպ���****************/
void Relay2_OFF(void)
{
	HAL_GPIO_WritePin(GPIOB, JDQ2_Pin, GPIO_PIN_RESET);
}

/****************�̵���2��������****************/
void Relay2_ON(void)
{
	HAL_GPIO_WritePin(GPIOB, JDQ2_Pin, GPIO_PIN_SET);
}

/****************�̵���3�رպ���****************/
void Relay3_OFF(void)
{
	HAL_GPIO_WritePin(GPIOB, JDQ3_Pin, GPIO_PIN_RESET);
}

/****************�̵���3��������****************/
void Relay3_ON(void)
{
	HAL_GPIO_WritePin(GPIOB, JDQ3_Pin, GPIO_PIN_SET);
}

/****************�̵���4�رպ���****************/
void Relay4_OFF(void)
{
	HAL_GPIO_WritePin(GPIOB, JDQ4_Pin, GPIO_PIN_RESET);
}

/****************�̵���4��������****************/
void Relay4_ON(void)
{
	HAL_GPIO_WritePin(GPIOB, JDQ4_Pin, GPIO_PIN_SET);
}

/****************�̵���5�رպ���****************/
void Relay5_OFF(void)
{
	HAL_GPIO_WritePin(GPIOB, JDQ5_Pin, GPIO_PIN_RESET);
}

/****************�̵���5��������****************/
void Relay5_ON(void)
{
	HAL_GPIO_WritePin(GPIOB, JDQ5_Pin, GPIO_PIN_SET);
}

/****************�̵���ȫ�رպ���****************/
void Relays_OFF(void)
{
	Relay1_OFF ();
	Relay2_OFF ();
	Relay3_OFF ();
	Relay4_OFF ();
	Relay5_OFF ();
}

/****************�̵���ȫ��������****************/
void Relays_ON(void)
{
	Relay1_ON ();
	Relay2_ON ();
	Relay3_ON ();
	Relay4_ON ();
	Relay5_ON ();
}
