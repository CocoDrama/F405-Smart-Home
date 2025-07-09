#include "SERVO.h" 

/* USER CODE BEGIN 0 */
// �����ʼ������
void Servo_Init(void)
{
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);  // ����PWM���
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 1500); // ��ʼλ��1.5ms(90��)
}

// ����Ƕȿ��ƺ���
void Servo_Turn(uint16_t angle)
{
    uint16_t pulse_width;
    
    // �Ƕ��޷�
    if(angle < SERVO_MIN_ANGLE) angle = SERVO_MIN_ANGLE;
    if(angle > SERVO_MAX_ANGLE) angle = SERVO_MAX_ANGLE;
    
    // �Ƕ�ת������(����ӳ��)
    pulse_width = SERVO_MIN_PULSE + (angle * (SERVO_MAX_PULSE - SERVO_MIN_PULSE)) / SERVO_MAX_ANGLE;
    
    // ����PWM����
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
