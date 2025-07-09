#include "BodySW.h"
 
int Body_Num(void)
{
	uint8_t BodyNum ;
	if(HAL_GPIO_ReadPin (BodySW_GPIO_Port,BodySW_Pin)==0)
	{
		BodyNum = 1;
	}
	else
	{
		BodyNum = 0;
	}
	return BodyNum;
}
