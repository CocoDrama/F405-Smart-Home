#ifndef __LCD_H
#define __LCD_H 

/* ------> ����������� ���������� @�����ϡ� <------ */
#include "stm32f4xx_hal.h"
#include "stdlib.h"
#include "stdint.h"
#include "main.h"

/***************�����Լ��������****************/
/* Ӳ����Ӧ���Ӷ˿ڣ�
 * SCL --> SCL --> PA5
 * SDA --> SDA --> PA7
 * RST --> RES --> PA6
 * DC  --> DC  --> PA2
 * BLK --> BLK --> PA3
 * CS  --> CS  --> PA4
 *
 *********************END**********************/
#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t

#define LCD_SCLK_Clr() HAL_GPIO_WritePin(LCD_SCL_GPIO_Port, LCD_SCL_Pin, GPIO_PIN_RESET)//SCL=SCLK
#define LCD_SCLK_Set() HAL_GPIO_WritePin(LCD_SCL_GPIO_Port, LCD_SCL_Pin, GPIO_PIN_SET)

#define LCD_MOSI_Clr() HAL_GPIO_WritePin(LCD_SDA_GPIO_Port, LCD_SDA_Pin, GPIO_PIN_RESET)//SDA=MOSI
#define LCD_MOSI_Set() HAL_GPIO_WritePin(LCD_SDA_GPIO_Port, LCD_SDA_Pin, GPIO_PIN_SET)

#define LCD_RES_Clr()  HAL_GPIO_WritePin(LCD_RES_GPIO_Port, LCD_RES_Pin, GPIO_PIN_RESET)//RES
#define LCD_RES_Set()  HAL_GPIO_WritePin(LCD_RES_GPIO_Port, LCD_RES_Pin, GPIO_PIN_SET)

#define LCD_DC_Clr()   HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_RESET)//DC
#define LCD_DC_Set()   HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_SET)

#define LCD_CS_Clr()   HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET)//CS
#define LCD_CS_Set()   HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET)

#define LCD_BLK_Clr()  HAL_GPIO_WritePin(LCD_BL_GPIO_Port, LCD_BL_Pin, GPIO_PIN_RESET)//BLK
#define LCD_BLK_Set()  HAL_GPIO_WritePin(LCD_BL_GPIO_Port, LCD_BL_Pin, GPIO_PIN_SET)

#define USE_HORIZONTAL 0  //���ú�������������ʾ 0��1Ϊ���� 2��3Ϊ����

#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
#define LCD_W 128
#define LCD_H 160//160

#else
#define LCD_W 160//160
#define LCD_H 128
#endif

/* ������ɫ */
#define WHITE      0xFFFF    // ��ɫ (R=31, G=63, B=31)
#define BLACK      0x0000    // ��ɫ (R=0,  G=0,  B=0)
#define RED        0xF800    // ��ɫ (R=31, G=0,  B=0)
#define GREEN      0x07E0    // ��ɫ (R=0,  G=63, B=0)
#define BLUE       0x001F    // ��ɫ (R=0,  G=0,  B=31)

/* ������ɫ */
#define YELLOW     0xFFE0    // ��ɫ (R=31, G=63, B=0)
#define CYAN       0x07FF    // ��ɫ (R=0,  G=63, B=31)
#define MAGENTA    0xF81F    // Ʒ�� (R=31, G=0,  B=31)
#define ORANGE     0xFC00    // ��ɫ (R=31, G=32, B=0)
#define PINK       0xFC9F    // ��ɫ (R=31, G=20, B=31)
#define GOLD       0xFEA0    // ��ɫ (R=31, G=42, B=0)

/* ��ɫϵ */
#define GRAY       0x8410    // ��ɫ (R=16, G=32, B=16)
#define LIGHT_GRAY 0xC618    // ǳ�� (R=24, G=48, B=24)
#define DARK_GRAY  0x4208    // ��� (R=8,  G=16, B=8)

/* ��ɫϵ */
#define NAVY       0x0010    // ���� (R=0,  G=0,  B=16)
#define SKY_BLUE   0x867F    // ���� (R=16, G=50, B=31)
#define STEEL_BLUE 0x4416    // ���� (R=8,  G=16, B=22)

/* ��ɫϵ */
#define LIME       0x87E0    // ���� (R=16, G=63, B=0)
#define OLIVE      0x8400    // ����� (R=16, G=32, B=0)
#define FOREST     0x2444    // ɭ���� (R=4,  G=16, B=4)

/* ��ɫϵ */
#define CRIMSON    0xD010    // ��� (R=26, G=0,  B=16)
#define SALMON     0xFC0E    // ����� (R=31, G=24, B=14)
#define MAROON     0x8000    // �ֺ� (R=16, G=0,  B=0)

/* ��ɫϵ */
#define PURPLE     0x801F    // ��ɫ (R=16, G=0,  B=31)
#define LAVENDER   0xE71F    // ޹�²��� (R=28, G=14, B=31)
#define INDIGO     0x4810    // ���� (R=9,  G=8,  B=16)

/* ��ɫϵ */
#define BROWN      0xA145    // ��ɫ (R=20, G=8,  B=5)
#define CHOCOLATE  0xD343    // �ɿ���ɫ (R=26, G=12, B=3)
#define TAN        0xD5B0    // �غ�ɫ (R=26, G=45, B=16)

/* ������ɫ */
#define TEAL       0x0410    // ˮѼɫ (R=0,  G=16, B=16)
#define TURQUOISE  0x471F    // ����ʯɫ (R=8,  G=28, B=31)
#define CORAL      0xFBEA    // ɺ��ɫ (R=31, G=46, B=10)



//���������ò���
#define PROGRESS_BAR_XSTART 15		//X��ʼֵ
#define PROGRESS_BAR_YSTART 70		//Y��ʼֵ
#define PROGRESS_BAR_XEND   105		//X����ֵ
#define PROGRESS_BAR_YEND   75		//Y����ֵ
#define PROGRESS_BAR_COLOR  BLACK	//��������ɫ

void LCD_GPIO_Init(void);//��ʼ��GPIO
void LCD_Writ_Bus(u8 dat);//ģ��SPIʱ��
void LCD_WR_DATA8(u8 dat);//д��һ���ֽ�
void LCD_WR_DATA(u16 dat);//д�������ֽ�
void LCD_WR_REG(u8 dat);//д��һ��ָ��
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2);//�������꺯��
uint8_t LCD_Init(void);//LCD��ʼ��


void LCD_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color);//ָ�����������ɫ
void LCD_DrawPoint(u16 x,u16 y,u16 color);//��ָ��λ�û�һ����
void LCD_DrawLine(u16 x1,u16 y1,u16 x2,u16 y2,u16 color);//��ָ��λ�û�һ����(X1,Y1,X2,Y2,��ɫ)
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2,u16 color);//��ָ��λ�û�һ������
void Draw_Circle(u16 x0,u16 y0,u8 r,u16 color);//��ָ��λ�û�һ��Բ(x,y,�뾶����ɫ)
void drawProgressBarAnimation(void);//���ƽ�����
	
void LCD_ShowChinese(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//��ʾ���ִ�(X,Y,"���ִ�",��ɫ,��ɫ,�ߴ�,ģʽ)
void LCD_ShowChinese12x12(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//��ʾ����12x12����
void LCD_ShowChinese16x16(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//��ʾ����16x16����
void LCD_ShowChinese24x24(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//��ʾ����24x24����
void LCD_ShowChinese32x32(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//��ʾ����32x32����

void LCD_ShowChar(u16 x,u16 y,u8 num,u16 fc,u16 bc,u8 sizey,u8 mode);//��ʾһ���ַ�
void LCD_ShowString(u16 x,u16 y,const u8 *p,u16 fc,u16 bc,u8 sizey,u8 mode);//��ʾ�ַ���(X,Y,"�ַ���",��ɫ,��ɫ,�ߴ�,ģʽ)
u32 mypow(u8 m,u8 n);//����
void LCD_ShowIntNum(u16 x,u16 y,u16 num,u8 len,u16 fc,u16 bc,u8 sizey);//��ʾ��������
void LCD_ShowFloatNum1(u16 x,u16 y,float num,u8 len,u16 fc,u16 bc,u8 sizey);//��ʾ��λС������

void LCD_ShowPicture(u16 x,u16 y,u16 length,u16 width,const u8 pic[]);//��ʾͼƬ


#endif

