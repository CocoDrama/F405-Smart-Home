#include "Relays.h"

/****************继电器1关闭函数****************/
void Relay1_OFF(void)
{
	HAL_GPIO_WritePin(GPIOB, JDQ1_Pin, GPIO_PIN_RESET);
}

/****************继电器1开启函数****************/
void Relay1_ON(void)
{
	HAL_GPIO_WritePin(GPIOB, JDQ1_Pin, GPIO_PIN_SET);
}

/****************继电器2关闭函数****************/
void Relay2_OFF(void)
{
	HAL_GPIO_WritePin(GPIOB, JDQ2_Pin, GPIO_PIN_RESET);
}

/****************继电器2开启函数****************/
void Relay2_ON(void)
{
	HAL_GPIO_WritePin(GPIOB, JDQ2_Pin, GPIO_PIN_SET);
}

/****************继电器3关闭函数****************/
void Relay3_OFF(void)
{
	HAL_GPIO_WritePin(GPIOB, JDQ3_Pin, GPIO_PIN_RESET);
}

/****************继电器3开启函数****************/
void Relay3_ON(void)
{
	HAL_GPIO_WritePin(GPIOB, JDQ3_Pin, GPIO_PIN_SET);
}

/****************继电器4关闭函数****************/
void Relay4_OFF(void)
{
	HAL_GPIO_WritePin(GPIOB, JDQ4_Pin, GPIO_PIN_RESET);
}

/****************继电器4开启函数****************/
void Relay4_ON(void)
{
	HAL_GPIO_WritePin(GPIOB, JDQ4_Pin, GPIO_PIN_SET);
}

/****************继电器5关闭函数****************/
void Relay5_OFF(void)
{
	HAL_GPIO_WritePin(GPIOB, JDQ5_Pin, GPIO_PIN_RESET);
}

/****************继电器5开启函数****************/
void Relay5_ON(void)
{
	HAL_GPIO_WritePin(GPIOB, JDQ5_Pin, GPIO_PIN_SET);
}

/****************继电器全关闭函数****************/
void Relays_OFF(void)
{
	Relay1_OFF ();
	Relay2_OFF ();
	Relay3_OFF ();
	Relay4_OFF ();
	Relay5_OFF ();
}

/****************继电器全开启函数****************/
void Relays_ON(void)
{
	Relay1_ON ();
	Relay2_ON ();
	Relay3_ON ();
	Relay4_ON ();
	Relay5_ON ();
}
