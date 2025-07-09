#include "ASRPRO.h"

/* ��Ӧ ASR_Num
 * ASRNum_LED --> ���ƹ�
 * ASRNum_TV  --> ���̻�
 * ASRNum_Air --> �յ�
 * ASRNum_Hot --> �����
 * ASR_Num 5 --> ����
 */
 
 int ASRNum_LED = 0;
 int ASRNum_TV = 0;
 int ASRNum_Air = 0;
 int ASRNum_Hot = 0;
 int ASRNum_Window = 0;
 
void ASR_Scan(void)
{
	if(HAL_GPIO_ReadPin (JDQSW1_GPIO_Port,JDQSW1_Pin)==0)
	{
		ASRNum_LED = 1;  
	}
	else
	{
		ASRNum_LED = 0;
	}
	
	if(HAL_GPIO_ReadPin (JDQSW2_GPIO_Port,JDQSW2_Pin)==0)
	{
		ASRNum_TV = 1;
	}
	else
	{
		ASRNum_TV = 0;
	}
	
	if(HAL_GPIO_ReadPin (JDQSW3_GPIO_Port,JDQSW3_Pin)==0)
	{
		ASRNum_Air = 1; 
	}
	else
	{
		ASRNum_Air = 0; 
	}
	
	if(HAL_GPIO_ReadPin (JDQSW4_GPIO_Port,JDQSW4_Pin)==0)
	{
		ASRNum_Hot = 1;
	}
	else
	{
		ASRNum_Hot = 0;
	}
	
	if(HAL_GPIO_ReadPin (JDQSW5_GPIO_Port,JDQSW5_Pin)==0)
	{
		ASRNum_Window = 1;
	}
	else
	{
		ASRNum_Window = 0;
	}
}
