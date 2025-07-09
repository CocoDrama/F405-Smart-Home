#include "SetMenu.h" 

	/* 屏幕坐标/尺寸示意图
	 * O------→X=128
	 * |
	 * |
	 * |
	 * ↓Y=130
	 */

//int KeyNum ;
Thresholds_TypeDef Thresholds;  // 全局变量定义

void FirstSetMenu(void)
{
	AT24C02_Init(&hi2c1);
	AT24C02_LoadThresholds(&Thresholds);
	
	u8 Showi[20];

	if((Thresholds.HighTemp == 0)&&(Thresholds.LowTemp == 0)&&(Thresholds.HighHumi == 0)
			&&(Thresholds.LowHumi == 0)&&(Thresholds.HighLux == 0)&&(Thresholds.HighCO2 == 0)
			&&(Thresholds.HighSmoke == 0))
	{
		LCD_Fill(0,0,130,20,BLUE);
		LCD_Fill(0,20,130,130,WHITE);
		LCD_ShowChinese(16,2,(u8*)"首次阈值设置",WHITE,BLUE,16,0);
		
		LCD_ShowChinese(28,23,(u8*)"检测到你尚未设置",BLUE,WHITE,12,0);
		LCD_ShowChinese(4,38,(u8*)"过阈值，系统需要设置",BLUE,WHITE,12,0);
		LCD_ShowChinese(4,53,(u8*)"阈值保障正常工作，请",BLUE,WHITE,12,0);
		LCD_ShowChinese(4,68,(u8*)"在  秒后对系统阈值进",BLUE,WHITE,12,0);
		LCD_ShowChinese(4,83,(u8*)"行设置。",BLUE,WHITE,12,0);
		
		// 从10倒数到0
		for(u8 i = 9; i > 0; i--)
		{
				sprintf((char*)Showi, "%d", i);
				LCD_ShowString(20,68,(u8*)Showi,BLUE,WHITE,12,0);
				HAL_Delay(1000);  // 等待1秒
		}
		// 倒数结束后进入设置菜单
		SetMenu();
	}
}


// 定义菜单参数显示
u8 ShowHighTemp [30];
u8 ShowLowTemp  [30];
u8 ShowHighHumi [30];
u8 ShowLowHumi  [30];
u8 ShowHighLux  [30];
u8 ShowHighCO2  [30];
u8 ShowHighSmoke[30];

static int Key_Num ;

void SetMenu(void)
{
	AT24C02_Init(&hi2c1);
	AT24C02_LoadThresholds(&Thresholds);
	
	LCD_Fill(0,0,130,20,WHITE);
	LCD_ShowChinese(32,2,(u8*)"系统设置", BLUE, WHITE,16,0);
	LCD_Fill(0,20,130,130,BLUE);
	
	int Select_Num = 2;
	int Menu_Num = 0;
	int Show_Select_Num[20];
	
	while(1)
	{
		Key_Num = Key_Scan ();
		if(Key_Num == 3)
		{
			Select_Num++;
			if(Select_Num >7)
			{
				Select_Num = 1;
			}
		}
		else if(Key_Num == 4)
		{
			Select_Num--;
			if(Select_Num <1)
			{
				Select_Num = 7;
			}
		}
		
		sprintf((char*)Show_Select_Num,  "%d/7", Select_Num);
		
		LCD_ShowString(100,6,(u8*)Show_Select_Num,BLUE,WHITE,12,0);
		
		switch (Select_Num)
		{
			case 1:
				LCD_ShowChinese(10,25, (u8*) "返回主页", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,39, (u8*) "温度设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,53, (u8*) "湿度设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,67, (u8*) "光照设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,81, (u8*) "烟雾设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,95, (u8*) "二氧化碳设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,109,(u8*) "恢复出厂设置", WHITE, BLUE,12,0);
		
				LCD_ShowString(85,25, (u8*)"<--", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,39, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,53, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,67, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,81, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,95, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,109,(u8*)"   ", WHITE, BLUE, 12, 0);
		
				if(Key_Num == 1)	{	Menu_Num = 1;   }
				break ;
				
			case 2:
				LCD_ShowChinese(10,25, (u8*) "返回主页", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,39, (u8*) "温度设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,53, (u8*) "湿度设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,67, (u8*) "光照设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,81, (u8*) "烟雾设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,95, (u8*) "二氧化碳设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,109,(u8*) "恢复出厂设置", WHITE, BLUE,12,0);
		
				LCD_ShowString(85,25, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,39, (u8*)"<--", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,53, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,67, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,81, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,95, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,109,(u8*)"   ", WHITE, BLUE, 12, 0);
			
				if(Key_Num == 1)	{	Menu_Num = 2;	}
				break ;
			case 3:
				LCD_ShowChinese(10,25, (u8*) "返回主页", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,39, (u8*) "温度设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,53, (u8*) "湿度设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,67, (u8*) "光照设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,81, (u8*) "烟雾设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,95, (u8*) "二氧化碳设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,109,(u8*) "恢复出厂设置", WHITE, BLUE,12,0);
		
				LCD_ShowString(85,25, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,39, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,53, (u8*)"<--", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,67, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,81, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,95, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,109,(u8*)"   ", WHITE, BLUE, 12, 0);
			
				if(Key_Num == 1)	{	Menu_Num = 3;	}
				break ;
			case 4:
				LCD_ShowChinese(10,25, (u8*) "返回主页", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,39, (u8*) "温度设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,53, (u8*) "湿度设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,67, (u8*) "光照设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,81, (u8*) "烟雾设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,95, (u8*) "二氧化碳设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,109,(u8*) "恢复出厂设置", WHITE, BLUE,12,0);
		
				LCD_ShowString(85,25, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,39, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,53, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,67, (u8*)"<--", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,81, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,95, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,109,(u8*)"   ", WHITE, BLUE, 12, 0);
			
				if(Key_Num == 1)	{	Menu_Num = 4;	}
				break ;
			case 5:
				LCD_ShowChinese(10,25, (u8*) "返回主页", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,39, (u8*) "温度设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,53, (u8*) "湿度设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,67, (u8*) "光照设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,81, (u8*) "烟雾设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,95, (u8*) "二氧化碳设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,109,(u8*) "恢复出厂设置", WHITE, BLUE,12,0);
		
				LCD_ShowString(85,25, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,39, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,53, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,67, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,81, (u8*)"<--", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,95, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,109,(u8*)"   ", WHITE, BLUE, 12, 0);
			
				if(Key_Num == 1)	{	Menu_Num = 5;	}
				break ;
			case 6:
				LCD_ShowChinese(10,25, (u8*) "返回主页", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,39, (u8*) "温度设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,53, (u8*) "湿度设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,67, (u8*) "光照设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,81, (u8*) "烟雾设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,95, (u8*) "二氧化碳设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,109,(u8*) "恢复出厂设置", WHITE, BLUE,12,0);
		
				LCD_ShowString(85,25, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,39, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,53, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,67, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,81, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,95, (u8*)"<--", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,109,(u8*)"   ", WHITE, BLUE, 12, 0);
			
				if(Key_Num == 1)	{	Menu_Num = 6;	}
				break ;
			case 7:
				LCD_ShowChinese(10,25, (u8*) "返回主页", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,39, (u8*) "温度设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,53, (u8*) "湿度设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,67, (u8*) "光照设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,81, (u8*) "烟雾设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,95, (u8*) "二氧化碳设置", WHITE, BLUE,12,0);
				LCD_ShowChinese(10,109,(u8*) "恢复出厂设置", WHITE, BLUE,12,0);
		
				LCD_ShowString(85,25, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,39, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,53, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,67, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,81, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,95, (u8*)"   ", WHITE, BLUE, 12, 0);
				LCD_ShowString(85,109,(u8*)"<--", WHITE, BLUE, 12, 0);
			
				if(Key_Num == 1)
				{	
					Thresholds.HighTemp  = 0 ;	// 默认温度高阈值
					Thresholds.LowTemp   = 0 ;	// 默认温度低阈值
					Thresholds.HighHumi  = 0 ;	// 默认湿度高阈值
					Thresholds.LowHumi   = 0 ;	// 默认湿度低阈值
					Thresholds.HighLux   = 0 ;   // 默认开灯阈值
					Thresholds.HighCO2   = 0 ;   // 默认 MQ2 阈值
					Thresholds.HighSmoke = 0 ;   // 默认 MQ135 阈值
					AT24C02_SaveThresholds(&Thresholds);
					LCD_Fill(10,50,120,80,WHITE);
					LCD_ShowChinese(29,57,(u8*)"重置成功！",BLACK,WHITE,16,0);
					HAL_Delay (1000);
					LCD_Fill(10,50,120,80,BLUE);
				}
				break ;
		}
		switch(Menu_Num)
		{
			case 1:
					HomeUI_Protract ();
					return;
			case 2:
					Menu_Temp ();
					Menu_Num = 0;
					break;
			case 3:
					Menu_Humi ();
					Menu_Num = 0;
					break;
			case 4:
					Menu_Lux ();
					Menu_Num = 0;
					break;
			case 5:
					Menu_Smoke ();
					Menu_Num = 0;
					break;
			case 6:
					Menu_CO2 ();
					Menu_Num = 0;
					break;
		}
	}
}

void Menu_Temp(void)
{
	int Select_Temp_Num = 2;
	LCD_Fill(0,0,130,24,WHITE);
	LCD_ShowChinese(32,4,(u8*)"温度设置", BLUE, WHITE,16,0);
	LCD_Fill(0,24,130,130,BLUE);
	while(1)
	{
		Key_Num = Key_Scan ();

		if(Key_Num == 3)
		{
			Select_Temp_Num++;
			if(Select_Temp_Num >4)
			{
				Select_Temp_Num = 1;
			}
		}
		else if(Key_Num == 4)
		{
			Select_Temp_Num--;
			if(Select_Temp_Num <1)
			{
				Select_Temp_Num = 4;
			}
		}
		sprintf((char*)ShowHighTemp, "%d",Thresholds.HighTemp);
		sprintf((char*)ShowLowTemp,  "%d",Thresholds.LowTemp);
		
		LCD_ShowChinese(5,25,(u8*)"返回主菜单", WHITE, BLUE,16,0);
		LCD_ShowChinese(5,45,(u8*)"高温设置", WHITE, BLUE,16,0);
		LCD_ShowChinese(5,65,(u8*)"低温设置", WHITE, BLUE,16,0);
		LCD_ShowChinese(5,85,(u8*)"重置阈值", WHITE, BLUE,16,0);
		
		LCD_ShowString(70, 45 ,(u8*)ShowHighTemp , WHITE, BLUE, 16, 0);
		LCD_ShowString(70, 65 ,(u8*)"  ", WHITE, BLUE, 16, 0);
		LCD_ShowString(70, 65 ,(u8*)ShowLowTemp , WHITE, BLUE, 16, 0);
		
		LCD_ShowChinese(90,45,(u8*) "℃",WHITE,BLUE,16,0);
		LCD_ShowChinese(90,65,(u8*) "℃",WHITE,BLUE,16,0);
		
		switch (Select_Temp_Num)
		{
			case 1:
					LCD_ShowString(105,25,  (u8*)"<--", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,45,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,65,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,85,  (u8*)"   ", WHITE, BLUE, 16, 0);
					if(Key_Num == 1)
					{
						AT24C02_SaveThresholds(&Thresholds);
						LCD_Fill(20,40,108,90,WHITE);
						LCD_ShowChinese(28,50,(u8*)"重置成功！", BLUE, WHITE,16,0);
						HAL_Delay (1000);
						LCD_Fill(0,0,130,24,WHITE);
						LCD_Fill(0,24,130,130,BLUE);
						LCD_ShowChinese(33,5,(u8*)"系统设置", BLUE, WHITE,16,0);
						return;
					}
					break;
			case 2:
					LCD_ShowString(105,25,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,45,  (u8*)"<--", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,65,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,85,  (u8*)"   ", WHITE, BLUE, 16, 0);
					if(Key_Num == 6)
					{
						Thresholds.HighTemp++;
						if(Thresholds.HighTemp>50)
						{
							Thresholds.HighTemp = 25;
						}
					}
					else if(Key_Num == 5)
					{
						Thresholds.HighTemp--;
						if(Thresholds.HighTemp<25)
						{
							Thresholds.HighTemp = 50;
						}
					}
					break;
			case 3:
					LCD_ShowString(105,25,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,45,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,65,  (u8*)"<--", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,85,  (u8*)"   ", WHITE, BLUE, 16, 0);
					if(Key_Num == 6)
					{
						Thresholds.LowTemp++;
						if(Thresholds.LowTemp>25)
						{
							Thresholds.LowTemp = 1;
						}
					}
					else if(Key_Num == 5)
					{
						Thresholds.LowTemp--;
						if(Thresholds.LowTemp<1)
						{
							Thresholds.LowTemp = 25;
						}
					}
					break;
			case 4:
					LCD_ShowString(105,25,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,45,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,65,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,85,  (u8*)"<--", WHITE, BLUE, 16, 0);
					if(Key_Num == 1)
					{
						Thresholds.HighTemp = 40;
						Thresholds.LowTemp  = 10;
						AT24C02_SaveThresholds(&Thresholds);
					}
					break ;
		}
	}
}

void Menu_Humi(void)
{
	int Select_Humi_Num = 1;
	LCD_Fill(0,0,130,24,WHITE);
	LCD_ShowChinese(33,5,(u8*)"湿度设置", BLUE, WHITE,16,0);
	LCD_Fill(0,24,130,130,BLUE);
	
	while(1)
	{
		Key_Num = Key_Scan ();
		
		if(Key_Num == 3)
		{
			Select_Humi_Num++;
			if(Select_Humi_Num >4)
			{
				Select_Humi_Num = 1;
			}
		}
		else if(Key_Num == 4)
		{
			Select_Humi_Num--;
			if(Select_Humi_Num <1)
			{
				Select_Humi_Num = 4;
			}
		}
		
		sprintf((char*)ShowHighHumi, "%d %%RH", Thresholds.HighHumi);
		sprintf((char*)ShowLowHumi,  "%d %%RH", Thresholds.LowHumi );
		
		LCD_ShowChinese(5,25,(u8*)"返回主菜单", WHITE, BLUE,16,0);
		LCD_ShowChinese(5,45,(u8*)"高湿值", WHITE, BLUE,16,0);
		LCD_ShowChinese(5,65,(u8*)"低湿值", WHITE, BLUE,16,0);
		LCD_ShowChinese(5,85,(u8*)"重置阈值", WHITE, BLUE,16,0);
		
		LCD_ShowString(55, 45 ,(u8*)ShowHighHumi , WHITE, BLUE, 16, 0);
		LCD_ShowString(55, 65 ,(u8*)ShowLowHumi , WHITE, BLUE, 16, 0);
		
		switch (Select_Humi_Num)
		{
			case 1:
					LCD_ShowString(105,25,  (u8*)"<--", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,45,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,65,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,85,  (u8*)"   ", WHITE, BLUE, 16, 0);
					if(Key_Num == 1)
					{
						AT24C02_SaveThresholds(&Thresholds);
						LCD_Fill(20,40,108,90,WHITE);
						LCD_ShowChinese(28,50,(u8*)"重置成功！", BLUE, WHITE,16,0);
						HAL_Delay (1000);
						LCD_Fill(0,0,130,24,WHITE);
						LCD_Fill(0,24,130,130,BLUE);
						LCD_ShowChinese(33,5,(u8*)"系统设置", BLUE, WHITE,16,0);
						return;
					}
					break;
			case 2:
					LCD_ShowString(105,25,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,45,  (u8*)"<--", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,65,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,85,  (u8*)"   ", WHITE, BLUE, 16, 0);
					if(Key_Num == 6)
					{
						Thresholds.HighHumi++;
						if(Thresholds.HighHumi>75)
						{
							Thresholds.HighHumi = 45;
						}
					}
					else if(Key_Num == 5)
					{
						Thresholds.HighHumi--;
						if(Thresholds.HighHumi<45)
						{
							Thresholds.HighHumi = 75;
						}
					}
					break;
			case 3:
					LCD_ShowString(105,25,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,45,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,65,  (u8*)"<--", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,85,  (u8*)"   ", WHITE, BLUE, 16, 0);
					if(Key_Num == 6)
					{
						Thresholds.LowHumi++;
						if(Thresholds.LowHumi>45)
						{
							Thresholds.LowHumi = 15;
						}
					}
					else if(Key_Num == 5)
					{
						Thresholds.LowHumi--;
						if(Thresholds.LowHumi<15)
						{
							Thresholds.LowHumi = 45;
						}
					}
					break;
			case 4:
					LCD_ShowString(105,25,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,45,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,65,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,85,  (u8*)"<--", WHITE, BLUE, 16, 0);
					if(Key_Num == 1)
					{
						Thresholds.HighHumi = 70;
						Thresholds.LowHumi  = 45;
					}
					break ;
		}
	}
}

void Menu_Lux(void)
{
	int Select_Lux_Num = 1;
	LCD_Fill(0,0,130,24,WHITE);
	LCD_ShowChinese(33,5,(u8*)"光照设置", BLUE, WHITE,16,0);
	LCD_Fill(0,24,130,130,BLUE);
	
	while(1)
	{
		Key_Num = Key_Scan ();
		
		if(Key_Num == 3)
		{
			Select_Lux_Num++;
			if(Select_Lux_Num >3)
			{
				Select_Lux_Num = 1;
			}
		}
		else if(Key_Num == 4)
		{
			Select_Lux_Num--;
			if(Select_Lux_Num <1)
			{
				Select_Lux_Num = 3;
			}
		}
		sprintf((char*)ShowHighLux,"%.f %%",Thresholds .HighLux);
		
		LCD_ShowChinese(5,25,(u8*)"返回主菜单", WHITE, BLUE,16,0);
		LCD_ShowChinese(5,45,(u8*)"光照阈值", WHITE, BLUE,16,0);
		LCD_ShowChinese(5,65,(u8*)"重置阈值", WHITE, BLUE,16,0);
		
		LCD_ShowString(70, 45 ,(u8*)ShowHighLux , WHITE, BLUE, 16, 0);
		
		switch (Select_Lux_Num)
		{
			case 1:
					LCD_ShowString(105,25,  (u8*)"<--", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,45,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,65,  (u8*)"   ", WHITE, BLUE, 16, 0);
					if(Key_Num == 1)
					{
						AT24C02_SaveThresholds(&Thresholds);
						LCD_Fill(20,40,108,90,WHITE);
						LCD_ShowChinese(28,50,(u8*)"重置成功！", BLUE, WHITE,16,0);
						HAL_Delay (1000);
						LCD_Fill(0,0,130,24,WHITE);
						LCD_Fill(0,24,130,130,BLUE);
						LCD_ShowChinese(33,5,(u8*)"系统设置", BLUE, WHITE,16,0);
						return;
					}
					break;
			case 2:
					LCD_ShowString(105,25,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,45,  (u8*)"<--", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,65,  (u8*)"   ", WHITE, BLUE, 16, 0);
					if(Key_Num == 6)
					{
						Thresholds.HighLux +=5;
						if(Thresholds.HighLux>90)
						{
							Thresholds.HighLux = 10;
						}
					}
					else if(Key_Num == 5)
					{
						Thresholds.HighLux -=5;
						if(Thresholds.HighLux<10)
						{
							Thresholds.HighLux = 90;
						}
					}
					break;
			case 3:
					LCD_ShowString(105,25,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,45,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,65,  (u8*)"<--", WHITE, BLUE, 16, 0);
					if(Key_Num == 1)
					{
						Thresholds.HighLux = 45;
					}
					break;
		}
	}
}

void Menu_CO2(void)
{
	int Select_YanWu_Num = 1;
	LCD_Fill(0,0,130,24,WHITE);
	LCD_ShowChinese(16,4,(u8*)"二氧化碳设置", BLUE, WHITE,16,0);
	LCD_Fill(0,24,130,130,BLUE);
	
	while(1)
	{
		Key_Num = Key_Scan ();
		
		if(Key_Num == 3)
		{
			Select_YanWu_Num++;
			if(Select_YanWu_Num >3)
			{
				Select_YanWu_Num = 1;
			}
		}
		else if(Key_Num == 4)
		{
			Select_YanWu_Num--;
			if(Select_YanWu_Num <1)
			{
				Select_YanWu_Num = 3;
			}
		}
		sprintf((char*)ShowHighCO2,":%.1f ppM ",Thresholds.HighCO2);
		 
		LCD_ShowChinese(5,25,(u8*)"返回主菜单", WHITE, BLUE,16,0);
		LCD_ShowChinese(5,45,(u8*)"数值", WHITE, BLUE,16,0);
		LCD_ShowChinese(5,65,(u8*)"重置阈值", WHITE, BLUE,16,0);
		
		LCD_ShowString(40, 45 ,(u8*)ShowHighCO2 , WHITE, BLUE, 16, 0);
		
		switch (Select_YanWu_Num)
		{
			case 1:
					LCD_ShowString(105,25,  (u8*)"<--", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,45,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,65,  (u8*)"   ", WHITE, BLUE, 16, 0);
					if(Key_Num == 1)
					{
						AT24C02_SaveThresholds(&Thresholds);
						LCD_Fill(20,40,108,90,WHITE);
						LCD_ShowChinese(28,50,(u8*)"重置成功！", BLUE, WHITE,16,0);
						HAL_Delay (1000);
						LCD_Fill(0,0,130,24,WHITE);
						LCD_Fill(0,24,130,130,BLUE);
						LCD_ShowChinese(33,5,(u8*)"系统设置", BLUE, WHITE,16,0);
						return;
					}
					break;
			case 2:
					LCD_ShowString(105,25,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,45,  (u8*)"<--", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,65,  (u8*)"   ", WHITE, BLUE, 16, 0);
					if(Key_Num == 6)
					{
						Thresholds.HighCO2 +=0.2;
						if(Thresholds.HighCO2>15)
						{
							Thresholds.HighCO2 = 0.2;
						}
					}
					else if(Key_Num == 5)
					{
						Thresholds.HighCO2 -=0.2;
						if(Thresholds.HighCO2<0.2)
						{
							Thresholds.HighCO2 = 15;
						}
					}
					break;
			case 3:
					LCD_ShowString(105,25,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,45,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,65,  (u8*)"<--", WHITE, BLUE, 16, 0);
					if(Key_Num == 1)
					{
						Thresholds.HighCO2 = 5;
					}
					break;
		}
	}
}

void Menu_Smoke(void)
{
	int Select_JiaBen_Num = 1;
	LCD_Fill(0,0,130,24,WHITE);
	LCD_ShowChinese(16,5,(u8*)"烟雾设置", BLUE, WHITE,16,0);
	LCD_Fill(0,24,130,130,BLUE);
	
	while(1)
	{
		Key_Num = Key_Scan ();
		
		if(Key_Num == 3)
		{
			Select_JiaBen_Num++;
			if(Select_JiaBen_Num >3)
			{
				Select_JiaBen_Num = 1;
			}
		}
		else if(Key_Num == 4)
		{
			Select_JiaBen_Num--;
			if(Select_JiaBen_Num <1)
			{
				Select_JiaBen_Num = 3;
			}
		}
		sprintf((char*)ShowHighSmoke,":%.1f ppM ",Thresholds.HighSmoke);
		
		LCD_ShowChinese(5,25,(u8*)"返回主菜单", WHITE, BLUE,16,0);
		LCD_ShowChinese(5,45,(u8*)"数值", WHITE, BLUE,16,0);
		LCD_ShowChinese(5,65,(u8*)"重置阈值", WHITE, BLUE,16,0);
		
		LCD_ShowString(40, 45 ,(u8*)ShowHighSmoke , WHITE, BLUE, 16, 0);
		
		switch (Select_JiaBen_Num)
		{
			case 1:
					LCD_ShowString(105,25,  (u8*)"<--", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,45,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,65,  (u8*)"   ", WHITE, BLUE, 16, 0);
					if(Key_Num == 1)
					{
						AT24C02_SaveThresholds(&Thresholds);
						LCD_Fill(20,40,108,90,WHITE);
						LCD_ShowChinese(28,50,(u8*)"重置成功！", BLUE, WHITE,16,0);
						HAL_Delay (1000);
						LCD_Fill(0,0,130,24,WHITE);
						LCD_Fill(0,24,130,130,BLUE);
						LCD_ShowChinese(33,5,(u8*)"系统设置", BLUE, WHITE,16,0);
						return;
					}
					break;
			case 2:
					LCD_ShowString(105,25,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,45,  (u8*)"<--", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,65,  (u8*)"   ", WHITE, BLUE, 16, 0);
					if(Key_Num == 6)
					{
						Thresholds .HighSmoke +=0.2;
						if(Thresholds .HighSmoke>15)
						{
							Thresholds .HighSmoke = 0.2;
						}
					}
					else if(Key_Num == 5)
					{
						Thresholds .HighSmoke -=0.2;
						if(Thresholds .HighSmoke<0.2)
						{
							Thresholds .HighSmoke = 15;
						}
					}
					break;
			case 3:
					LCD_ShowString(105,25,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,45,  (u8*)"   ", WHITE, BLUE, 16, 0);
					LCD_ShowString(105,65,  (u8*)"<--", WHITE, BLUE, 16, 0);
					if(Key_Num == 1)
					{
						Thresholds .HighSmoke = 5;
					}
					break;
		}
	}
}

