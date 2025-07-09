#include "IoT.h"

/******************************引脚宏定义******************************/
#define RCC_APBnPeriph_USARTn 	RCC_APB1Periph_USART2	//USART时钟选择
#define RCC_APBnPeriph_GPIOn 	RCC_APB2Periph_GPIOA	//GPIO时钟选择
#define USARTn_IRQn				USART2_IRQn				//IRQN
#define GPIO_Pin_TX 			GPIO_Pin_2				//TX引脚选择
#define GPIO_Pin_RX 			GPIO_Pin_3				//RX引脚选择
#define USARTn 					USART2					//USART通道选择
#define GPIOn 					GPIOA					//GPIO引脚选择
#define BaudRate 				115200					//波特率
#define BUFFER_SIZE 		2048  					// 接收缓冲区大小
#define Received_OK 			"OK"
#define Received_Error 			"ERROR"

int TVIotMode  = 0;
int HotIotMode = 0;
int AirIotMode = 0;
int LightIotMode     = 0;
int WindowIotMode    = 0;
int SideLightIotMode = 0;

/*************************接收缓冲区声明*************************/
char rx_buffer[BUFFER_SIZE];
int  rx_index = 0 ;
int  rx_done  = 0 ;
int  Return_Num = 0 ;
int  Motor_Word;

/*****************************解析JSON中主灯光（客厅灯）的函数*****************************/
int JSON_Parse_Light_State(const char* json_str)
{
    const char* Light_key = "\"Light\":";
    const char* Light_pos = strstr(json_str, Light_key);

    if (Light_pos != NULL)
	{
        Light_pos += strlen(Light_key);
        while (*Light_pos == ' ' || *Light_pos == '\t' || *Light_pos == '\n' || *Light_pos == '\r')
		{
            Light_pos++;
        }
        if (*Light_pos >= '0' && *Light_pos <= '9')
		{
            return *Light_pos - '0';
        }
    }
    return -1;
}

/*****************************解析JSON中室外灯的函数*****************************/
int JSON_Parse_SideLight_State(const char* json_str)
{
    const char* SideLight_key = "\"SideLight\":";
    const char* SideLight_pos = strstr(json_str, SideLight_key);

    if (SideLight_pos != NULL)
	{
        SideLight_pos += strlen(SideLight_key);
        while (*SideLight_pos == ' ' || *SideLight_pos == '\t' || *SideLight_pos == '\n' || *SideLight_pos == '\r')
		{
            SideLight_pos++;
        }
        if (*SideLight_pos >= '0' && *SideLight_pos <= '9')
		{
            return *SideLight_pos - '0';
        }
    }
    return -1;
}

/*****************************解析JSON中电视机的函数*****************************/
int JSON_Parse_TV_State(const char* json_str)
{
    const char* TV_key = "\"TV\":";
    const char* TV_pos = strstr(json_str, TV_key);

    if (TV_pos != NULL)
	{
        TV_pos += strlen(TV_key);
        while (*TV_pos == ' ' || *TV_pos == '\t' || *TV_pos == '\n' || *TV_pos == '\r')
		{
            TV_pos++;
        }
        if (*TV_pos >= '0' && *TV_pos <= '9')
		{
            return *TV_pos - '0';
        }
    }
    return -1;
}

/*****************************解析JSON中空调的函数*****************************/
int JSON_Parse_Air_State(const char* json_str)
{
    const char* Air_key = "\"Air\":";
    const char* Air_pos = strstr(json_str, Air_key);

    if (Air_pos != NULL)
	{
        Air_pos += strlen(Air_key);
        while (*Air_pos == ' ' || *Air_pos == '\t' || *Air_pos == '\n' || *Air_pos == '\r')
		{
            Air_pos++;
        }
        if (*Air_pos >= '0' && *Air_pos <= '9')
		{
            return *Air_pos - '0';
        }
    }
    return -1;
}

/*****************************解析JSON中热水器的函数*****************************/
int JSON_Parse_Hot_State(const char* json_str)
{
    const char* Hot_key = "\"Hot\":";
    const char* Hot_pos = strstr(json_str, Hot_key);

    if (Hot_pos != NULL)
	{
        Hot_pos += strlen(Hot_key);
        while (*Hot_pos == ' ' || *Hot_pos == '\t' || *Hot_pos == '\n' || *Hot_pos == '\r')
		{
            Hot_pos++;
        }
        if (*Hot_pos >= '0' && *Hot_pos <= '9')
		{
            return *Hot_pos - '0';
        }
    }
    return -1;
}

/*****************************解析JSON中窗户的函数*****************************/
int JSON_Parse_Window_State(const char* json_str)
{
    const char* Window_key = "\"Window\":";
    const char* Window_pos = strstr(json_str, Window_key);

    if (Window_pos != NULL)
	{
        Window_pos += strlen(Window_key);
        while (*Window_pos == ' ' || *Window_pos == '\t' || *Window_pos == '\n' || *Window_pos == '\r')
		{
            Window_pos++;
        }
        if (*Window_pos >= '0' && *Window_pos <= '9')
		{
            return *Window_pos - '0';
        }
    }
    return -1;
}

void ParseAndProcessJSON(const char* json_str)
{
	int TVIotState        = JSON_Parse_TV_State(rx_buffer);
	int HotIotState       = JSON_Parse_Hot_State(rx_buffer);
	int AirIotState       = JSON_Parse_Air_State(rx_buffer);
	int LightIotState   	= JSON_Parse_Light_State(rx_buffer); 
	int WindowIotState   	= JSON_Parse_Window_State(rx_buffer);
	int SideLightIotState	= JSON_Parse_SideLight_State(rx_buffer);

	if (TVIotState == 1)      { TVIotMode = 1;      } else if(TVIotState == 0)      { TVIotMode        = 0;}
	if (HotIotState == 1)     { HotIotMode = 1;     } else if(HotIotState == 0)     { HotIotMode       = 0;}
	if (AirIotState == 1)     { AirIotMode = 1;     } else if(AirIotState == 0)     { AirIotMode       = 0;}
	if (LightIotState ==1)    { LightIotMode =1;    } else if(LightIotState ==0)    { LightIotMode     = 0;}
	if (WindowIotState ==1)   { WindowIotMode =1;   } else if(WindowIotState ==0)   { WindowIotMode    = 0;}
	if (SideLightIotState ==1){ SideLightIotMode =1;} else if(SideLightIotState ==0){ SideLightIotMode = 0;}
}


/*************************** 接收中断函数 (HAL库版本) ***************************/
// 修正函数名和逻辑
void USART3_IRQHandler(void) {
  if (__HAL_UART_GET_FLAG(&huart3, UART_FLAG_RXNE)) {
    char ch = (uint8_t)(huart3.Instance->DR);
    
    if (rx_index < BUFFER_SIZE - 1) {
      rx_buffer[rx_index++] = ch;
      
      if (ch == '\n') { // 检测结束符
        rx_buffer[rx_index] = '\0';
        if (strstr(rx_buffer, "OK") != NULL) Return_Num = 1;
        else Return_Num = 2;
        
        ParseAndProcessJSON(rx_buffer);
        rx_index = 0; // 重置索引
      }
    } else {
      rx_index = 0; // 溢出处理
      memset(rx_buffer, 0, BUFFER_SIZE);
    }
  }
}


void IoT_Conect(void)
{
	LCD_Fill(0,0,130,130,WHITE);
	LCD_ShowChinese(24,30,(u8*)"云端连接中",BLUE,WHITE,16,0);
	
	WiFiConecting ();
	
	printf("%s", ESP_Test);
	HAL_Delay (500);

	printf("%s", ESP_Rst);			//重启ESP
	HAL_Delay (3000);
	
	printf ("%s", ESP_Mode);		//设置模式
	HAL_Delay (2000);
	
	printf ("%s", CIP_Mode);		//设置模式
	HAL_Delay (2000);
	
	printf ("%s",WiFiSSID_Passwd);	//连接WiFi
	HAL_Delay (6000);//等待连接WiFi
	
	//设置MQTT用户属性·要素①
	printf ("%s",MQTTUser_Passwd);
	HAL_Delay (2000);
	
	//设置Client ID·要素②
	printf("%s",MQTT_ClientID);
	HAL_Delay (2000);
	
	//连接MQTT·要素③
	printf("%s",MQTT_Url);
	HAL_Delay (2000);
	
	//订阅主题
	printf("%s",MQTTSub);
	HAL_Delay (2000);

	if(Return_Num == 1)
	{
		LCD_Fill(0,105,130,121,SKY_BLUE);
		LCD_ShowChinese(25,105,(u8*)"连接成功！",BLUE,SKY_BLUE,16,0);
		BEEP_ON ();
		LED_ON ();
		HAL_Delay (1000);
		BEEP_OFF ();
		LED_OFF ();
	}
	else
	{
		LCD_Fill(0,105,130,121,RED);
		LCD_ShowChinese(2,105,(u8*)"连接失败请重启！",WHITE,RED,16,0);
		BEEP_Alarm();
		LED_Flashing ();
	}
}


u8 Temp2,Humi2;
float Lux2,CO22,Smoke2;

void SendDataToIoT (void)
{
	
	DHT11_Read_Data(&Temp2,&Humi2);
	Lux2 = LightSensor_GetLux();
	CO22 = MQ135_GetData_PPM ();
	Smoke2 = MQ2_GetData_PPM ();
	
	//发送温度信息
	printf("AT+MQTTPUB=0,\"/sys/a1Fe3LOgKlx/Device1/thing/event/property/post\",\"{\\\"params\\\":{\\\"Temp\\\":%d}}\",1,0\r\n",Temp2);
	HAL_Delay (600);
	
	printf("AT+MQTTPUB=0,\"/sys/a1Fe3LOgKlx/Device1/thing/event/property/post\",\"{\\\"params\\\":{\\\"Humi\\\":%d}}\",1,0\r\n",Humi2);
	HAL_Delay (600);
	
	printf("AT+MQTTPUB=0,\"/sys/a1Fe3LOgKlx/Device1/thing/event/property/post\",\"{\\\"params\\\":{\\\"Lux\\\":%.1f}}\",1,0\r\n",Lux2);
	HAL_Delay (600);
	
	printf("AT+MQTTPUB=0,\"/sys/a1Fe3LOgKlx/Device1/thing/event/property/post\",\"{\\\"params\\\":{\\\"CO2\\\":%.1f}}\",1,0\r\n",CO22);
	HAL_Delay (600);
	
	printf("AT+MQTTPUB=0,\"/sys/a1Fe3LOgKlx/Device1/thing/event/property/post\",\"{\\\"params\\\":{\\\"Smoke\\\":%.1f}}\",1,0\r\n",Smoke2);
	HAL_Delay (600);
	

	if(IoTSwitchMode_Light == 1)
	{
		printf("AT+MQTTPUB=0,\"/sys/a1Fe3LOgKlx/Device1/thing/event/property/post\",\"{\\\"params\\\":{\\\"Light\\\":1}}\",1,0\r\n");
		HAL_Delay (600);
	}
	else
	{
		printf("AT+MQTTPUB=0,\"/sys/a1Fe3LOgKlx/Device1/thing/event/property/post\",\"{\\\"params\\\":{\\\"Light\\\":0}}\",1,0\r\n");
		HAL_Delay (600);
	}
	
	if(IoTSwitchMode_SideLight == 1)
	{
		printf("AT+MQTTPUB=0,\"/sys/a1Fe3LOgKlx/Device1/thing/event/property/post\",\"{\\\"params\\\":{\\\"SideLight\\\":1}}\",1,0\r\n");
		HAL_Delay (600);
	}
	else
	{
		printf("AT+MQTTPUB=0,\"/sys/a1Fe3LOgKlx/Device1/thing/event/property/post\",\"{\\\"params\\\":{\\\"SideLight\\\":0}}\",1,0\r\n");
		HAL_Delay (600);
	}
	
	if(IoTSwitchMode_TV == 1)
	{
		printf("AT+MQTTPUB=0,\"/sys/a1Fe3LOgKlx/Device1/thing/event/property/post\",\"{\\\"params\\\":{\\\"TV\\\":1}}\",1,0\r\n");
		HAL_Delay (600);
	}
	else
	{
		printf("AT+MQTTPUB=0,\"/sys/a1Fe3LOgKlx/Device1/thing/event/property/post\",\"{\\\"params\\\":{\\\"TV\\\":0}}\",1,0\r\n");
		HAL_Delay (600);
	}
	
	if(IoTSwitchMode_Hot == 1)
	{
		printf("AT+MQTTPUB=0,\"/sys/a1Fe3LOgKlx/Device1/thing/event/property/post\",\"{\\\"params\\\":{\\\"Hot\\\":1}}\",1,0\r\n");
		HAL_Delay (600);
	}
	else
	{
		printf("AT+MQTTPUB=0,\"/sys/a1Fe3LOgKlx/Device1/thing/event/property/post\",\"{\\\"params\\\":{\\\"Hot\\\":0}}\",1,0\r\n");
		HAL_Delay (600);
	}
	
	if(IoTSwitchMode_Window == 1)
	{
		printf("AT+MQTTPUB=0,\"/sys/a1Fe3LOgKlx/Device1/thing/event/property/post\",\"{\\\"params\\\":{\\\"Window\\\":1}}\",1,0\r\n");
		HAL_Delay (600);
	}
	else
	{
		printf("AT+MQTTPUB=0,\"/sys/a1Fe3LOgKlx/Device1/thing/event/property/post\",\"{\\\"params\\\":{\\\"Window\\\":0}}\",1,0\r\n");
		HAL_Delay (600);
	}
	
	if(IoTSwitchMode_Air == 1)
	{
		printf("AT+MQTTPUB=0,\"/sys/a1Fe3LOgKlx/Device1/thing/event/property/post\",\"{\\\"params\\\":{\\\"Air\\\":1}}\",1,0\r\n");
		HAL_Delay (600);
	}
	else
	{
		printf("AT+MQTTPUB=0,\"/sys/a1Fe3LOgKlx/Device1/thing/event/property/post\",\"{\\\"params\\\":{\\\"Air\\\":0}}\",1,0\r\n");
		HAL_Delay (600);
	}
}
