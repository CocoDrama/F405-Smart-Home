#include "USART3.h"

#define ESP_Test "AT\r\n,"



void ESP_TEST(void)
{
	printf("%s", ESP_Test);
	HAL_Delay(1000);
}
