#include "MonitorMenu.h" 

 	/* 屏幕坐标/尺寸示意图
	 * O------→X=168
	 * |
	 * |
	 * |
	 * ↓Y=130
	 */

u8 Temp,Humi;
float Lux,CO2,Smoke;
int AutoMode_SideLight,AutoMode_Window,AutoMode_Air;

u8 ShowLux[20],ShowCO2[20],ShowSmoke[20],ShowTemp[20],ShowHumi[20];

void DataMonitoring(void)
{
	LCD_Fill(0,0,130,16,SKY_BLUE);
	LCD_Fill(0,16,130,130,BLUE);
	LCD_Fill(0,114,130,130,SKY_BLUE);
	LCD_DrawLine(0,120,130,120,WHITE);
	LCD_ShowChinese(40,2,(u8*)"环境监测",WHITE,SKY_BLUE,12,0);	
	LCD_ShowChinese(34,114,(u8*)"长按",WHITE,SKY_BLUE,12,0);
	LCD_ShowChinese(58,114,(u8*)"键返回",WHITE,SKY_BLUE,12,0);
	LCD_ShowString(46, 114,(u8*)"0K", WHITE, SKY_BLUE, 12, 0);

	while(1)	
	{
		int KeyNum = Key_Scan ();
		
		Lux = LightSensor_GetLux();
		CO2 = MQ135_GetData_PPM ();
		Smoke = MQ2_GetData_PPM ();
		DHT11_Read_Data(&Temp, &Humi);
		
		sprintf((char*)ShowTemp  ,":%d", Temp); 
		sprintf((char*)ShowHumi  ,":%d %%RH ", Humi); 
		sprintf((char*)ShowLux   ,":%.1f %% ", Lux); 
		sprintf((char*)ShowCO2   ,":%.1fppM", CO2); 
		sprintf((char*)ShowSmoke ,":%.1fppM", Smoke); 
		
		LCD_ShowChinese(5,20,(u8*)"温度",WHITE,BLUE,16,0);
		LCD_ShowChinese(5,39,(u8*)"湿度",WHITE,BLUE,16,0);
		LCD_ShowChinese(5,58,(u8*)"光照值",WHITE,BLUE,16,0);
		LCD_ShowChinese(5,77,(u8*)"二氧化碳",WHITE,BLUE,16,0);
		LCD_ShowChinese(5,96,(u8*)"烟雾浓度",WHITE,BLUE,16,0);
		
		LCD_ShowString(39, 20, ShowTemp, WHITE, BLUE, 16, 0);
		LCD_ShowString(39, 39, ShowHumi, WHITE, BLUE, 16, 0);
		LCD_ShowString(55, 58, ShowLux , WHITE, BLUE, 16, 0);
		LCD_ShowString(70, 77, ShowCO2 , WHITE, BLUE, 16, 0);
		LCD_ShowString(70, 96, ShowSmoke , WHITE, BLUE, 16, 0);
		
		SendDataToIoT ();
		SyetemWorking ();
		
		if(KeyNum == 1)
		{
			HomeUI_Protract ();
			return;
		}
		
		if((Temp > Thresholds.HighTemp)||(Temp < Thresholds.LowTemp)||(Humi > Thresholds.HighHumi))
		{
			AutoMode_Air = AirAutoModeOn;
		}
		else
		{
			AutoMode_Air = AirAutoModeOff;
		}
		
		if((CO2 > Thresholds.HighCO2)||(Smoke > Thresholds.HighSmoke))
		{
			AutoMode_Window = WindowAutoModeOn;
		}
		else
		{
			AutoMode_Window = WindowAutoModeOff;
		}
		
		if(Lux < Thresholds.HighLux )
		{
			AutoMode_SideLight = SideLightAutoModeOn ;
		}
		else
		{
			
		}
	}
}



