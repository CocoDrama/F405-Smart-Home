#include "Work.h" 

/* Relay1 --> 主灯光
 * Relay2 --> 室外光
 * Relay3 --> 电视机
 * Relay4 --> 空调
 * Relay5 --> 热水器
 */

int IoTSwitchMode_Light = 0;
int IoTSwitchMode_SideLight = 0;
int IoTSwitchMode_TV = 0;
int IoTSwitchMode_Hot = 0;
int IoTSwitchMode_Window = 0;
int IoTSwitchMode_Air = 0;

void WiFiYorN(void)
{
	if(Return_Num==1)
	{
		WiFiOnLine ();
	}
	else if(Return_Num == 0)
	{
		WiFiOffLine ();
	}
}
// 主灯光
// 室外灯
// 空调
// 油烟机
// 窗户
void SyetemWorking(void)
{
	ASR_Scan ();
	
	// 主灯控制**
	if((Light_ActMode==1)||(ASRNum_LED == 1)||(LightIotMode==1))
	{
		Relay1_ON ();
		IoTSwitchMode_Light = 1;
		
	}
	else
	{
		Relay1_OFF ();
		IoTSwitchMode_Light = 0;
	}
	
	// 室外光控制**
	if(((Lux <Thresholds.HighLux)&&(AutoMode_SideLight == 1))||(SideLightIotMode==1)||(Eat_ActMode == 1)||(ASRNum_Hot == 1))
	{
		Relay2_ON ();
		IoTSwitchMode_SideLight = 1;
	}
	else
	{
		Relay2_OFF ();
		IoTSwitchMode_SideLight = 0;
	}
	
	// 油烟机控制**
	if((TV_ActMode==1)||(ASRNum_TV == 1)||(TVIotMode == 1))
	{
		Relay3_ON ();
		IoTSwitchMode_TV = 1;
	}
	else
	{
		Relay3_OFF ();
		IoTSwitchMode_TV = 0;
	}
	
	// 空调控制**
	if((Air_ActMode==1)||(ASRNum_Air == 1) || (AutoMode_Air == 1) || (AirIotMode == 1))
	{
		Relay4_ON ();
		IoTSwitchMode_Air = 1;
	}
	else
	{
		Relay4_OFF ();
		IoTSwitchMode_Air = 0;
	}
	
	// 热水器控制
	if((HotWater_ActMode==1)||(HotIotMode == 1 ))
	{
		Relay5_ON ();
		IoTSwitchMode_Hot = 1;
	}
	else
	{
		Relay5_OFF ();
		IoTSwitchMode_Hot = 0;
	}
	
	// 窗帘控制
	if((Window_ActMode == 1)||(ASRNum_Window == 1)||(AutoMode_Window == 1)||(WindowIotMode == 1))
	{
		Servo_TurnOn ();
		IoTSwitchMode_Window = 1;
	}
	else
	{
		Servo_TurnOFF ();
		IoTSwitchMode_Window = 0;
	}
}

	/* 屏幕坐标/尺寸示意图
	 * O------→X=128
	 * |
	 * |
	 * |
	 * ↓Y=130
	 */

