#ifndef __ASRPRO_H
#define __ASRPRO_H

#include "stm32f4xx.h"                  // Device header
#include "main.h"

/* ��Ӧ ASR_Num
 * ASR_Num 1 --> ���ƹ�
 * ASR_Num 2 --> ���ӻ�
 * ASR_Num 3 --> �յ�
 * ASR_Num 4 --> ��ˮ��
 * ASR_Num 5 --> ����
 */

void ASR_Scan(void);

extern int ASRNum_LED ;
extern int ASRNum_TV  ;
extern int ASRNum_Air ;
extern int ASRNum_Hot ;
extern int ASRNum_Window ;
 
#endif
