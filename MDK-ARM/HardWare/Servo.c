#include "SERVO.h" 

/* USER CODE BEGIN 0 */
// 舵机初始化函数
void Servo_Init(void)
{
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);  // 启动PWM输出
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 1500); // 初始位置1.5ms(90度)
}

// 舵机角度控制函数
void Servo_Turn(uint16_t angle)
{
    uint16_t pulse_width;
    
    // 角度限幅
    if(angle < SERVO_MIN_ANGLE) angle = SERVO_MIN_ANGLE;
    if(angle > SERVO_MAX_ANGLE) angle = SERVO_MAX_ANGLE;
    
    // 角度转脉冲宽度(线性映射)
    pulse_width = SERVO_MIN_PULSE + (angle * (SERVO_MAX_PULSE - SERVO_MIN_PULSE)) / SERVO_MAX_ANGLE;
    
    // 设置PWM脉宽
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, pulse_width);
}
/* USER CODE END 0 */

void Servo_TurnOn(void)
{
	Servo_Turn(60);
}

void Servo_TurnOFF(void)
{
	Servo_Turn(0);
}
