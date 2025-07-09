#include "EquipMenu.h" 

u8 ShowSelectNum[20];

int Light_ActMode ;
int Air_ActMode ;
int Window_ActMode ;
int Eat_ActMode ;
int TV_ActMode ;
int HotWater_ActMode ;

void EquipSetMenu(void)
{
	LCD_Fill(0,0,130,16,SKY_BLUE);
	LCD_Fill(0,16,130,130,BLUE);
	LCD_ShowChinese(40,2,(u8*)"设备管理",BLUE,SKY_BLUE,12,0);
	
	int SelectNum = 2;
	LCD_ShowChinese(80,33, (u8*)"←",WHITE,BLUE,12,0);
	
	while(1)
	{
		int KeyWord = Key_Scan();
		
		sprintf((char*)ShowSelectNum, "%d/7", SelectNum);
		
		LCD_ShowChinese(5,18,(u8*)  "返回主页"    , WHITE, BLUE,12,0);
		LCD_ShowChinese(5,33,(u8*)  "灯光设置"    , WHITE, BLUE,12,0);
		LCD_ShowChinese(5,48,(u8*)  "空调设置"    , WHITE, BLUE,12,0);
		LCD_ShowChinese(5,63,(u8*)  "窗户设置"    , WHITE, BLUE,12,0);
		LCD_ShowChinese(5,78,(u8*)  "室外灯设置"  , WHITE, BLUE,12,0);
		LCD_ShowChinese(5,93,(u8*)  "油烟机设置"  , WHITE, BLUE,12,0);
		LCD_ShowChinese(5,108,(u8*) "热水器设备"  , WHITE, BLUE,12,0);
		
		LCD_ShowString(105, 2, (u8*)ShowSelectNum , BLUE,SKY_BLUE, 12, 0);
		
		if (KeyWord == 3)
		{
			SelectNum++;
			if (SelectNum > 7)
			{
				SelectNum = 1;
			}
		} 
		else if (KeyWord == 4)
		{
			SelectNum--;
			if (SelectNum < 1)
			{
				SelectNum = 7;
			}
		}
		else if((KeyWord == 2)||(KeyWord == 5)||(KeyWord == 6))
		{
		
		}
		
		if((KeyWord == 3) ||(KeyWord == 4))
		{
			switch (SelectNum)
			{
				case 1:
					LCD_ShowChinese(80,18 ,(u8*)"←",WHITE,BLUE,12,0);
					LCD_ShowString (80,33, (u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,48, (u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,63, (u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,78, (u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,93, (u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,108,(u8*)"  ",WHITE,BLUE,12,0);
					break;                           
				case 2:                            
					LCD_ShowString (80,18 ,(u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowChinese(80,33, (u8*)"←",WHITE,BLUE,12,0);
					LCD_ShowString (80,48, (u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,63, (u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,78, (u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,93, (u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,108,(u8*)"  ",WHITE,BLUE,12,0);
					break;
				case 3:
					LCD_ShowString (80,18 ,(u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,33 ,(u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowChinese(80,48 ,(u8*)"←",WHITE,BLUE,12,0);
					LCD_ShowString (80,63, (u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,78, (u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,93, (u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,108,(u8*)"  ",WHITE,BLUE,12,0);
					break;                         
				case 4:                        
					LCD_ShowString (80,18 ,(u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,33 ,(u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,48 ,(u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowChinese(80,63 ,(u8*)"←",WHITE,BLUE,12,0);
					LCD_ShowString (80,78, (u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,93, (u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,108,(u8*)"  ",WHITE,BLUE,12,0);
					break;                          
				case 5:                           
					LCD_ShowString (80,18 ,(u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,33 ,(u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,48 ,(u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,63 ,(u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowChinese(80,78 ,(u8*)"←",WHITE,BLUE,12,0);
					LCD_ShowString (80,93, (u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,108,(u8*)"  ",WHITE,BLUE,12,0);
					break;
				case 6:
					LCD_ShowString (80,18 ,(u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,33 ,(u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,48 ,(u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,63 ,(u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,78 ,(u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowChinese(80,93 ,(u8*)"←",WHITE,BLUE,12,0);
					LCD_ShowString (80,108,(u8*)"  ",WHITE,BLUE,12,0);
					break;                         
				case 7:                          
					LCD_ShowString (80,18 ,(u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,33 ,(u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,48 ,(u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,63 ,(u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,78 ,(u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowString (80,93, (u8*)"  ",WHITE,BLUE,12,0);
					LCD_ShowChinese(80,108,(u8*)"←",WHITE,BLUE,12,0);
					break;
				}
			}
			else if(KeyWord == 1)
			{
				switch(SelectNum)
				{
					case 1:
						HomeUI_Protract ();
						return;
					case 2:
						Light_Ctrl();
						LCD_Fill(0,16,130,130,BLUE);
						LCD_ShowChinese(80,33, (u8*)"←",WHITE,BLUE,12,0);
						break;
					case 3:
						Air_Ctrl();
						LCD_Fill(0,16,130,130,BLUE);
						LCD_ShowChinese(80,48, (u8*)"←",WHITE,BLUE,12,0);
						break;
					case 4:
						Window_Ctrl();
						LCD_Fill(0,16,130,130,BLUE);
						LCD_ShowChinese(80,63, (u8*)"←",WHITE,BLUE,12,0);
						break;
					case 5:
						Eat_Ctrl();
						LCD_Fill(0,16,130,130,BLUE);
						LCD_ShowChinese(80,78, (u8*)"←",WHITE,BLUE,12,0);
						break;
					case 6:
						TV_Ctrl();
						LCD_Fill(0,16,130,130,BLUE);
						LCD_ShowChinese(80,93, (u8*)"←",WHITE,BLUE,12,0);
						break;
					case 7:
						HotWater_Ctrl();
						LCD_Fill(0,16,130,130,BLUE);
						LCD_ShowChinese(80,108, (u8*)"←",WHITE,BLUE,12,0);
						break;
				}
			}
		}
	}


void Light_Ctrl(void)
{

    int KeyWord_Light = 0;
    int LightState = 1; 
    
    LCD_Fill(5,30,123,80,WHITE);     
    LCD_ShowChinese(10, 35, (u8*)"是否开启灯光？", BLUE, WHITE, 16, 0);
    LCD_ShowChinese(25, 60, (u8*)"开启", WHITE, BLUE, 12, 0);
    LCD_ShowChinese(80, 60, (u8*)"关闭", BLUE, WHITE, 12, 0);
    
    while(1)
		{
        KeyWord_Light = Key_Scan();
        
        if((KeyWord_Light == 5 )||( KeyWord_Light == 6))
				{
					LightState = !LightState;
					
					if(LightState == 1)
					{
						LCD_ShowChinese(25, 60, (u8*)"开启", WHITE, BLUE, 12, 0);
						LCD_ShowChinese(80, 60, (u8*)"关闭", BLUE, WHITE, 12, 0);
					} 
					else 
					{
						LCD_ShowChinese(25, 60, (u8*)"开启", BLUE, WHITE, 12, 0);
						LCD_ShowChinese(80, 60, (u8*)"关闭", WHITE, BLUE, 12, 0);
					}
        }
        else if(KeyWord_Light == 1)
				{
					Light_ActMode = LightState; 
					if(Light_ActMode == 1)
					{
						Relay1_ON ();
						LCD_Fill(5,30,123,55,WHITE); 
						LCD_ShowChinese(10, 35, (u8*)"灯光已打开！", BLUE, WHITE, 16, 0);
						HAL_Delay (500);
					}
					else
					{
						Relay1_OFF ();
						LCD_Fill(5,30,123,55,WHITE);
						LCD_ShowChinese(10, 35, (u8*)"灯光已关闭！", BLUE, WHITE, 16, 0);
						HAL_Delay (500);
					}
					return;
        }
    }
}


void Air_Ctrl(void)
{

    int KeyWord_Air = 0;
    int AirState = 1; 
    
    LCD_Fill(5,30,123,80,WHITE);     
    LCD_ShowChinese(10, 35, (u8*)"是否开启空调？", BLUE, WHITE, 16, 0);
    LCD_ShowChinese(25, 60, (u8*)"开启", WHITE, BLUE, 12, 0);
    LCD_ShowChinese(80, 60, (u8*)"关闭", BLUE, WHITE, 12, 0);
    
    while(1)
		{
        KeyWord_Air = Key_Scan();
        
        if((KeyWord_Air == 5 )||( KeyWord_Air == 6))
				{
					AirState = !AirState;
					
					if(AirState == 1)
					{
						LCD_ShowChinese(25, 60, (u8*)"开启", WHITE, BLUE, 12, 0);
						LCD_ShowChinese(80, 60, (u8*)"关闭", BLUE, WHITE, 12, 0);
					} 
					else 
					{
						LCD_ShowChinese(25, 60, (u8*)"开启", BLUE, WHITE, 12, 0);
						LCD_ShowChinese(80, 60, (u8*)"关闭", WHITE, BLUE, 12, 0);
					}
        }
        else if(KeyWord_Air == 1)
				{
					Air_ActMode = AirState; 
					if(Air_ActMode == 1)
					{
						Relay4_ON ();
						LCD_Fill(5,30,123,55,WHITE);
						LCD_ShowChinese(10, 35, (u8*)"空调已打开！", BLUE, WHITE, 16, 0);
						HAL_Delay (500);
					}
					else
					{
						Relay4_OFF ();
						LCD_Fill(5,30,123,55,WHITE);
						LCD_ShowChinese(10, 35, (u8*)"空调已关闭！", BLUE, WHITE, 16, 0);
						HAL_Delay (500);
					}
					return;
        }
    }
}

void Window_Ctrl(void)
{

    int KeyWord_Window = 0;
    int WindowState = 1; 
    
    LCD_Fill(5,30,123,80,WHITE);     
    LCD_ShowChinese(10, 35, (u8*)"是否开启窗户？", BLUE, WHITE, 16, 0);
    LCD_ShowChinese(25, 60, (u8*)"开启", WHITE, BLUE, 12, 0);
    LCD_ShowChinese(80, 60, (u8*)"关闭", BLUE, WHITE, 12, 0);
    
    while(1)
		{
        KeyWord_Window = Key_Scan();
        
        if((KeyWord_Window == 5 )||( KeyWord_Window == 6))
				{
					WindowState = !WindowState;
					
					if(WindowState == 1)
					{
						LCD_ShowChinese(25, 60, (u8*)"开启", WHITE, BLUE, 12, 0);
						LCD_ShowChinese(80, 60, (u8*)"关闭", BLUE, WHITE, 12, 0);
					} 
					else 
					{
						LCD_ShowChinese(25, 60, (u8*)"开启", BLUE, WHITE, 12, 0);
						LCD_ShowChinese(80, 60, (u8*)"关闭", WHITE, BLUE, 12, 0);
					}
        }
        else if(KeyWord_Window == 1)
				{
					Window_ActMode = WindowState; 
					if(Window_ActMode == 1)
					{
						Servo_TurnOn ();
						LCD_Fill(5,30,123,55,WHITE);
						LCD_ShowChinese(10, 35, (u8*)"窗户已打开！", BLUE, WHITE, 16, 0);
						HAL_Delay (500);
					}
					else
					{
						Servo_TurnOFF ();
						LCD_Fill(5,30,123,55,WHITE);
						LCD_ShowChinese(10, 35, (u8*)"窗户已关闭！", BLUE, WHITE, 16, 0);
						HAL_Delay (500);
					}
					return;
        }
    }
}

void Eat_Ctrl(void)
{

    int KeyWord_Eat = 0;
    int EatState = 1; 
    
    LCD_Fill(5,30,123,80,WHITE);     
    LCD_ShowChinese(10, 35, (u8*)"是否开启室外灯？", BLUE, WHITE, 16, 0);
    LCD_ShowChinese(25, 60, (u8*)"开启", WHITE, BLUE, 12, 0);
    LCD_ShowChinese(80, 60, (u8*)"关闭", BLUE, WHITE, 12, 0);
    
    while(1)
		{
        KeyWord_Eat = Key_Scan();
        
        if((KeyWord_Eat == 5 )||( KeyWord_Eat == 6))
				{
					EatState = !EatState;
					
					if(EatState == 1)
					{
						LCD_ShowChinese(25, 60, (u8*)"开启", WHITE, BLUE, 12, 0);
						LCD_ShowChinese(80, 60, (u8*)"关闭", BLUE, WHITE, 12, 0);
					} 
					else 
					{
						LCD_ShowChinese(25, 60, (u8*)"开启", BLUE, WHITE, 12, 0);
						LCD_ShowChinese(80, 60, (u8*)"关闭", WHITE, BLUE, 12, 0);
					}
        }
        else if(KeyWord_Eat == 1)
				{
					Eat_ActMode = EatState; 
					if(Eat_ActMode == 1)
					{
						Relay2_ON ();
						LCD_Fill(5,30,123,55,WHITE);
						LCD_ShowChinese(10, 35, (u8*)"室外灯已打开！", BLUE, WHITE, 16, 0);
						HAL_Delay (500);
					}
					else
					{
						Relay2_OFF ();
						LCD_Fill(5,30,123,55,WHITE);
						LCD_ShowChinese(10, 35, (u8*)"室外灯已关闭！", BLUE, WHITE, 16, 0);
						HAL_Delay (500);
					}
					return;
        }
    }
}
	
void TV_Ctrl(void)
{

    int KeyWord_TV = 0;
    int TVState = 1; 
    
    LCD_Fill(5,30,123,80,WHITE);     
    LCD_ShowChinese(10, 35, (u8*)"是否开启油烟机？", BLUE, WHITE, 16, 0);
    LCD_ShowChinese(25, 60, (u8*)"开启", WHITE, BLUE, 12, 0);
    LCD_ShowChinese(80, 60, (u8*)"关闭", BLUE, WHITE, 12, 0);
    
    while(1)
		{
        KeyWord_TV = Key_Scan();
        
        if((KeyWord_TV == 5 )||( KeyWord_TV == 6))
				{
					TVState = !TVState;
					
					if(TVState == 1)
					{
						LCD_ShowChinese(25, 60, (u8*)"开启", WHITE, BLUE, 12, 0);
						LCD_ShowChinese(80, 60, (u8*)"关闭", BLUE, WHITE, 12, 0);
					} 
					else 
					{
						LCD_ShowChinese(25, 60, (u8*)"开启", BLUE, WHITE, 12, 0);
						LCD_ShowChinese(80, 60, (u8*)"关闭", WHITE, BLUE, 12, 0);
					}
        }
        else if(KeyWord_TV == 1)
				{
					TV_ActMode = TVState; 
					if(TV_ActMode == 1)
					{
						Relay3_ON ();
						LCD_Fill(5,30,123,55,WHITE);
						LCD_ShowChinese(10, 35, (u8*)"油烟机已打开！", BLUE, WHITE, 16, 0);
						HAL_Delay (500);
					}
					else
					{
						Relay3_OFF ();
						LCD_Fill(5,30,123,55,WHITE);
						LCD_ShowChinese(10, 35, (u8*)"油烟机已关闭！", BLUE, WHITE, 16, 0);
						HAL_Delay (500);
					}
					return;
        }
    }
}

void HotWater_Ctrl(void)
{

    int KeyWord_HotWater = 0;
    int HotWaterState = 1; 
    
    LCD_Fill(5,30,123,80,WHITE);     
    LCD_ShowChinese(10, 35, (u8*)"是否开启热水器", BLUE, WHITE, 16, 0);
    LCD_ShowChinese(25, 60, (u8*)"开启", WHITE, BLUE, 12, 0);
    LCD_ShowChinese(80, 60, (u8*)"关闭", BLUE, WHITE, 12, 0);
    
    while(1)
		{
        KeyWord_HotWater = Key_Scan();
        
        if((KeyWord_HotWater == 5 )||( KeyWord_HotWater == 6))
				{
					HotWaterState = !HotWaterState;
					
					if(HotWaterState == 1)
					{
						LCD_ShowChinese(25, 60, (u8*)"开启", WHITE, BLUE, 12, 0);
						LCD_ShowChinese(80, 60, (u8*)"关闭", BLUE, WHITE, 12, 0);
					} 
					else 
					{
						LCD_ShowChinese(25, 60, (u8*)"开启", BLUE, WHITE, 12, 0);
						LCD_ShowChinese(80, 60, (u8*)"关闭", WHITE, BLUE, 12, 0);
					}
        }
        else if(KeyWord_HotWater == 1)
				{
					HotWater_ActMode = HotWaterState; 
					if(HotWater_ActMode == 1)
					{
						Relay5_ON ();
						LCD_Fill(5,30,123,55,WHITE);
						LCD_ShowChinese(10, 35, (u8*)"热水器已打开！", BLUE, WHITE, 16, 0);
						HAL_Delay (500);
					}
					else
					{
						Relay5_OFF ();
						LCD_Fill(5,30,123,55,WHITE);
						LCD_ShowChinese(10, 35, (u8*)"热水器已关闭！", BLUE, WHITE, 16, 0);
						HAL_Delay (500);
					}
					return;
        }
    }
}
					


	/* 屏幕坐标/尺寸示意图
	 * O------→X=128
	 * |
	 * |
	 * |
	 * ↓Y=130
	 */

