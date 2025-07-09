#ifndef __IoT_H
#define __IoT_H

/* ------> ����������� ���������� @�����ϡ� <------ */
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"
#include "main.h"
#include "usart.h"
#include "string.h"
#include "cJSON.h"
#include "UIProtact.h" 
#include "LED.h"
#include "BEEP.h"
#include "Work.h"

/************************ATָ��궨��************************/
#define ESP_Test "AT\r\n"
#define ESP_Rst  "AT+RESTORE\r\n"
#define ESP_Mode "AT+CWMODE=1\r\n"
#define CIP_Mode "AT+CIPMUX=0\r\n"
#define WiFiSSID_Passwd "AT+CWJAP=\"Tenda_0474E0\",\"12345678\"\r\n"
#define MQTT_Disconected "AT+MQTTCLEAN=0\r\n"

/**************************MQTT��Ҫ�غ궨��**************************/
#define MQTTUser_Passwd "AT+MQTTUSERCFG=0,1,\"NULL\",\"Device1&a1Fe3LOgKlx\",\"cefb926965db5400b99a35edeb091aed2a8b068706ac574219d9c3d3b21284f4\",0,0,\"\"\r\n"
#define MQTT_ClientID "AT+MQTTCLIENTID=0,\"a1Fe3LOgKlx.Device1|securemode=2\\,signmethod=hmacsha256\\,timestamp=1751682851159|\"\r\n"
#define MQTT_Url "AT+MQTTCONN=0,\"a1Fe3LOgKlx.iot-as-mqtt.cn-shanghai.aliyuncs.com\",1883,1\r\n"

/**************************MQTT��������궨��**************************/
#define MQTTSub "AT+MQTTSUB=0,\"a1Fe3LOgKlx/Device1/user/update\",1\r\n"

/*****************************USART3����*****************************/
void USART3_IROHandler(void);					//USART3�жϺ���
int JSON_Parse_Light_State(const char* json_str);//������
int JSON_Parse_SideLight_State(const char* json_str);//�����
int JSON_Parse_TV_State(const char* json_str);//���ӻ�
int JSON_Parse_Air_State(const char* json_str);//�յ�
int JSON_Parse_Hot_State(const char* json_str);//��ˮ��
int JSON_Parse_Window_State(const char* json_str);//����
void ParseAndProcessJSON(const char* json_str);//��������
void IoT_Conect(void);		//����IoT

void SendDataToIoT (void);

extern int TVIotMode  ;
extern int HotIotMode ;
extern int AirIotMode ;
extern int LightIotMode     ;
extern int WindowIotMode    ;
extern int SideLightIotMode ;

extern int  Return_Num ;

#endif

