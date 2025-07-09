#include "AdcSensor.h"

/*************************** 光敏采集 ***************************/
// 读取光敏ADC值
uint16_t LightSensor_GetADCValue(void)
{
    uint32_t Lux_Data = 0;
    ADC_ChannelConfTypeDef sConfig = {0};

    // 配置ADC通道（PC0对应ADC1_IN10）
    sConfig.Channel = LightSensor_ADC_CHANNEL;
    sConfig.Rank = 1;  // 直接赋值为1，替代 ADC_REGULAR_RANK_1
    sConfig.SamplingTime = ADC_SAMPLETIME_56CYCLES;
    HAL_ADC_ConfigChannel(&hadc1, &sConfig);

    for (uint8_t i = 0; i < READ_TIMES; i++)
    {
        HAL_ADC_Start(&hadc1);
        if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK)
        {
            Lux_Data += HAL_ADC_GetValue(&hadc1);
        }
        HAL_Delay(5);
    }
    return Lux_Data / READ_TIMES;
}

// 转化光敏百分比
float LightSensor_GetLux(void)
{
    uint16_t Lux = LightSensor_GetADCValue();
    return 100.0f - ((float)Lux / 4095.0f) * 100.0f;
}

/*************************** 二氧化碳采集 ***************************/
// 读取MQ135ADC值
uint16_t MQ135_GetData(void)
{
    uint32_t MQ135_Data = 0;
    ADC_ChannelConfTypeDef sConfig = {0};

    // 配置ADC通道（PC0对应ADC1_IN10）
    sConfig.Channel = MQ135Sensor_ADC_CHANNEL;
    sConfig.Rank = 1;  // 直接赋值为1，替代 ADC_REGULAR_RANK_1
    sConfig.SamplingTime = ADC_SAMPLETIME_56CYCLES;
    HAL_ADC_ConfigChannel(&hadc1, &sConfig);

    for (uint8_t i = 0; i < READ_TIMES; i++)
    {
        HAL_ADC_Start(&hadc1);
        if (HAL_ADC_PollForConversion(&hadc1, 11) == HAL_OK)
        {
            MQ135_Data += HAL_ADC_GetValue(&hadc1);
        }
        HAL_Delay(5);
    }
    return MQ135_Data / READ_TIMES;
}

// 读取二氧化碳ppM值
float MQ135_GetData_PPM(void)
{
	float  tempData = 0;

	for (uint8_t i = 0; i < READ_TIMES; i++)
	{
		tempData += MQ135_GetData();
		 HAL_Delay(5); // 稳定读数
	}
	tempData /= READ_TIMES;
	
	float Vol = (tempData*5/4096);
	float RS = (5-Vol)/(Vol*0.5);
	float R0=6.64;
	
	float ppm = pow(11.5428*R0/RS, 0.6549f);
	
	return ppm;
}

/*************************** 烟雾浓度采集 ***************************/
// 读取MQ2ADC值
uint16_t MQ2_GetData(void)
{
    uint32_t MQ2_Data = 0;
    ADC_ChannelConfTypeDef sConfig = {0};

    // 配置ADC通道（PC0对应ADC1_IN10）
    sConfig.Channel = MQ2Sensor_ADC_CHANNEL;
    sConfig.Rank = 1;  // 直接赋值为1，替代 ADC_REGULAR_RANK_1
    sConfig.SamplingTime = ADC_SAMPLETIME_56CYCLES;
    HAL_ADC_ConfigChannel(&hadc1, &sConfig);

    for (uint8_t i = 0; i < READ_TIMES; i++)
    {
        HAL_ADC_Start(&hadc1);
        if (HAL_ADC_PollForConversion(&hadc1, 12) == HAL_OK)
        {
            MQ2_Data += HAL_ADC_GetValue(&hadc1);
        }
        HAL_Delay(5);
    }
    return MQ2_Data / READ_TIMES;
}

// 读取二氧化碳ppM值
float MQ2_GetData_PPM(void)
{
	float  tempData = 0;

	for (uint8_t i = 0; i < READ_TIMES; i++)
	{
		tempData += MQ2_GetData();
		 HAL_Delay(5); // 稳定读数
	}
	tempData /= READ_TIMES;
	
	float Vol = (tempData*5/4096);
	float RS = (5-Vol)/(Vol*0.5);
	float R0=6.64;
	
	float ppm = pow(11.5428*R0/RS, 0.6549f);
	
	return ppm;
}
