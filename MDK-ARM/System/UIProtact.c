#include "UIProtact.h" 

	/* 屏幕坐标/尺寸示意图
	 * O------→X=128
	 * |
	 * |
	 * |
	 * ↓Y=130
	 */
		
void WiFiOnLine(void)
{
	LCD_Fill(63,8,66,13,BLUE);
	LCD_Fill(68,6,71,13,BLUE);
	LCD_Fill(73,4,76,13,BLUE);
	LCD_Fill(78,2,81,13,BLUE);
}

void WiFiConecting(void)
{
	u8 i;
	for(i=1;i<6;i++)
	{
		switch(i)
		{
			case 1:
				LCD_Fill(20,90,35,100,WHITE);
				LCD_Fill(45,80,60,100,WHITE);
				LCD_Fill(70,70,85,100,WHITE);
				LCD_Fill(95,60,110,100,WHITE);
				break;
			case 2:
				LCD_Fill(20,90,35,100,BLUE);
				LCD_Fill(45,80,60,100,WHITE);
				LCD_Fill(70,70,85,100,WHITE);
				LCD_Fill(95,60,110,100,WHITE);
				break;
			case 3:
				LCD_Fill(20,90,35,100,BLUE);
				LCD_Fill(45,80,60,100,BLUE);
				LCD_Fill(70,70,85,100,WHITE);
				LCD_Fill(95,60,110,100,WHITE);
				break;
			case 4:
				LCD_Fill(20,90,35,100,BLUE);
				LCD_Fill(45,80,60,100,BLUE);
				LCD_Fill(70,70,85,100,BLUE);
				LCD_Fill(95,60,110,100,WHITE);
				break;
			case 5:
				LCD_Fill(20,90,35,100,BLUE);
				LCD_Fill(45,80,60,100,BLUE);
				LCD_Fill(70,70,85,100,BLUE);
				LCD_Fill(95,60,110,100,BLUE);
				break;
		}
		HAL_Delay (1000);
	}
}

void WiFiOffLine(void)
{
	LCD_Fill(63,8,66,13,GRAY);
	LCD_Fill(68,6,71,13,GRAY);
	LCD_Fill(73,4,76,13,GRAY);
	LCD_Fill(78,2,81,13,GRAY);
}

void HouseArt(void)
{
	// 框
	LCD_Fill(15,40,55,80,BLACK);
	LCD_Fill(17,42,53,78,WHITE);
	//门
	LCD_Fill(28,63,43,78,BLACK);
	LCD_Fill(30,65,41,78,BLUE);
	//窗
	LCD_Fill(28,45,43,54,BLACK);
	LCD_Fill(30,47,41,52,BLUE);
	//封顶
	LCD_DrawLine(35,34,37,34,WHITE);
	LCD_DrawLine(32,35,40,35,WHITE);
	LCD_DrawLine(29,36,43,36,WHITE);
	LCD_DrawLine(26,37,46,37,WHITE);
	LCD_DrawLine(23,38,49,38,WHITE);
	LCD_DrawLine(20,39,52,39,WHITE);
	//左顶
	LCD_DrawLine(10,42,35,32,BLACK);
	LCD_DrawLine(10,43,35,33,BLACK);
	//右顶
	LCD_DrawLine(35,32,60,42,BLACK);
	LCD_DrawLine(35,33,60,43,BLACK);
	// 右小房框
	LCD_Fill(53,55,73,80,BLACK);
	LCD_Fill(55,57,71,78,WHITE);
	//右小门
	LCD_Fill(57,65,70,78,BLACK);
	LCD_Fill(59,67,68,78,BLUE);
	//右上墙角
	LCD_DrawLine(61,58,70,58,BLUE);
	LCD_DrawLine(61,59,70,59,BLUE);
	LCD_DrawLine(68,58,68,62,BLUE);
	LCD_DrawLine(69,58,69,62,BLUE);
}

void EquipManageUnSelect(void)
{
	LCD_Fill(86,86,126,126,BLUE);
	LCD_Fill(92,91,120,107,WHITE);
	LCD_Fill(94,93,110,105,BLUE);
	Draw_Circle(115,97,3,BLUE);
	LCD_DrawLine(112,103,118,103,BLUE);
	LCD_ShowChinese(93,110,(u8*)"设备",WHITE,BLUE,12,0);
}

void EquipManageSelected(void)
{
	LCD_Fill(86,86,126,126,BLUE);
	LCD_Fill(87,87,125,125,WHITE);
	LCD_Fill(92,91,120,107,BLUE);
	LCD_Fill(94,93,110,105,WHITE);
	Draw_Circle(115,97,3,WHITE);
	LCD_DrawLine(112,103,118,103,WHITE);
	LCD_ShowChinese(93,110,(u8*)"设备",BLUE,WHITE,12,0);
}

void MonitorUnSelect(void)
{
	LCD_Fill(86,2,126,42,BLUE);
	Draw_Circle(102,14,7,WHITE);
	Draw_Circle(102,14,8,WHITE);
	Draw_Circle(99,11,2,WHITE);
	LCD_DrawLine(108,18,117,22,WHITE);
	LCD_DrawLine(108,19,117,23,WHITE);
	LCD_DrawLine(108,20,117,24,WHITE);
	LCD_ShowChinese(93,27,(u8*)"监测",WHITE,BLUE,12,0);
}

void MonitorSelected(void)
{
	LCD_Fill(86,2,126,42,BLUE);
	LCD_Fill(87,3,125,41,WHITE);
	Draw_Circle(102,14,7,BLUE);
	Draw_Circle(102,14,8,BLUE);
	Draw_Circle(99,11,2,BLUE);
	LCD_DrawLine(108,18,117,22,BLUE);
	LCD_DrawLine(108,19,117,23,BLUE);
	LCD_DrawLine(108,20,117,24,BLUE);
	LCD_ShowChinese(93,27,(u8*)"监测",BLUE,WHITE,12,0);
}

void SetUnSelect(void)
{
	LCD_Fill(86,44,126,84,BLUE);
	LCD_Fill(95,49,117,52,WHITE);
	LCD_Fill(95,55,117,58,WHITE);
	LCD_Fill(95,61,117,64,WHITE);
	Draw_Circle(114,50,1,WHITE);
	Draw_Circle(114,50,2,WHITE);
	Draw_Circle(114,50,3,WHITE);
	Draw_Circle(98,56,1,WHITE);
	Draw_Circle(98,56,2,WHITE);
	Draw_Circle(98,56,3,WHITE);
	Draw_Circle(114,62,1,WHITE);
	Draw_Circle(114,62,2,WHITE);
	Draw_Circle(114,62,3,WHITE);
	LCD_ShowChinese(93,68,(u8*)"设置",WHITE,BLUE,12,0);
}

void SetSelected(void)
{
	LCD_Fill(86,44,126,84,BLUE);
	LCD_Fill(87,45,125,83,WHITE);
	LCD_Fill(95,49,117,52,BLUE);
	LCD_Fill(95,55,117,58,BLUE);
	LCD_Fill(95,61,117,64,BLUE);
	Draw_Circle(114,50,1,BLUE);
	Draw_Circle(114,50,2,BLUE);
	Draw_Circle(114,50,3,BLUE);
	Draw_Circle(98,56,1,BLUE);
	Draw_Circle(98,56,2,BLUE);
	Draw_Circle(98,56,3,BLUE);
	Draw_Circle(114,62,1,BLUE);
	Draw_Circle(114,62,2,BLUE);
	Draw_Circle(114,62,3,BLUE);
	LCD_ShowChinese(93,68,(u8*)"设置",BLUE,WHITE,12,0);
}

#include "tim.h"  // 假设使用HAL库的定时器

// 定义全局/静态变量
static int MenuNum = 2;
static int ShowState = 0;

void MenuChecking(void)
{
    int KeyNum = Key_Scan();
	
    // 3. 原有菜单逻辑
    if (KeyNum == 3) {
        MenuNum++;
        if (MenuNum > 3) MenuNum = 1;
        ShowState = 0;
    } 
    else if (KeyNum == 4) {
        MenuNum--;
        if (MenuNum < 1) MenuNum = 3;
        ShowState = 0;
    }

    // 刷新界面
    if (ShowState == 0) {
        switch (MenuNum) {
            case 1: MonitorSelected(); SetUnSelect(); EquipManageUnSelect(); break;
            case 2: MonitorUnSelect(); SetSelected(); EquipManageUnSelect(); break;
            case 3: MonitorUnSelect(); SetUnSelect(); EquipManageSelected(); break;
        }
        ShowState = 1;
    }

    // 处理菜单确认
    if (KeyNum == 1) {
        switch (MenuNum) {
					case 1: DataMonitoring();MenuNum = 2;break;
					case 2: SetMenu();MenuNum = 2;break;
					case 3: EquipSetMenu(); MenuNum = 2;break;
        }
    }
}

void HomeUI_Protract(void)
{
	LCD_Fill(0,0,130,130,SKY_BLUE);
	
	LCD_ShowChinese(7,85,(u8*)"慧享家",BLACK,SKY_BLUE,24,0);
	LCD_ShowString (3,110,(u8*)"SMART HOME",BLUE, SKY_BLUE,16,0);
	LCD_ShowString (12,15,(u8*)"IoT",BLUE, SKY_BLUE,16,0);
	HouseArt ();
	MonitorUnSelect();
	SetSelected();
	EquipManageUnSelect();
}

