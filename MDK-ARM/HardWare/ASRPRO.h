#ifndef __ASRPRO_H
#define __ASRPRO_H

#include "stm32f4xx.h"                  // Device header
#include "main.h"

/* 对应 ASR_Num
 * ASR_Num 1 --> 主灯光
 * ASR_Num 2 --> 电视机
 * ASR_Num 3 --> 空调
 * ASR_Num 4 --> 热水器
 * ASR_Num 5 --> 窗户
 */

void ASR_Scan(void);

extern int ASRNum_LED ;
extern int ASRNum_TV  ;
extern int ASRNum_Air ;
extern int ASRNum_Hot ;
extern int ASRNum_Window ;
 
#endif
