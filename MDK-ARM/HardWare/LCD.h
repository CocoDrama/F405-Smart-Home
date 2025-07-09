#ifndef __LCD_H
#define __LCD_H 

/* ------> 本处程序出自 “哔哩哔哩 @向孟孟” <------ */
#include "stm32f4xx_hal.h"
#include "stdlib.h"
#include "stdint.h"
#include "main.h"

/***************根据自己需求更改****************/
/* 硬件对应连接端口：
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

#define USE_HORIZONTAL 0  //设置横屏或者竖屏显示 0或1为竖屏 2或3为横屏

#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
#define LCD_W 128
#define LCD_H 160//160

#else
#define LCD_W 160//160
#define LCD_H 128
#endif

/* 基础颜色 */
#define WHITE      0xFFFF    // 白色 (R=31, G=63, B=31)
#define BLACK      0x0000    // 黑色 (R=0,  G=0,  B=0)
#define RED        0xF800    // 红色 (R=31, G=0,  B=0)
#define GREEN      0x07E0    // 绿色 (R=0,  G=63, B=0)
#define BLUE       0x001F    // 蓝色 (R=0,  G=0,  B=31)

/* 复合颜色 */
#define YELLOW     0xFFE0    // 黄色 (R=31, G=63, B=0)
#define CYAN       0x07FF    // 青色 (R=0,  G=63, B=31)
#define MAGENTA    0xF81F    // 品红 (R=31, G=0,  B=31)
#define ORANGE     0xFC00    // 橙色 (R=31, G=32, B=0)
#define PINK       0xFC9F    // 粉色 (R=31, G=20, B=31)
#define GOLD       0xFEA0    // 金色 (R=31, G=42, B=0)

/* 灰色系 */
#define GRAY       0x8410    // 灰色 (R=16, G=32, B=16)
#define LIGHT_GRAY 0xC618    // 浅灰 (R=24, G=48, B=24)
#define DARK_GRAY  0x4208    // 深灰 (R=8,  G=16, B=8)

/* 蓝色系 */
#define NAVY       0x0010    // 深蓝 (R=0,  G=0,  B=16)
#define SKY_BLUE   0x867F    // 天蓝 (R=16, G=50, B=31)
#define STEEL_BLUE 0x4416    // 钢蓝 (R=8,  G=16, B=22)

/* 绿色系 */
#define LIME       0x87E0    // 亮绿 (R=16, G=63, B=0)
#define OLIVE      0x8400    // 橄榄绿 (R=16, G=32, B=0)
#define FOREST     0x2444    // 森林绿 (R=4,  G=16, B=4)

/* 红色系 */
#define CRIMSON    0xD010    // 深红 (R=26, G=0,  B=16)
#define SALMON     0xFC0E    // 鲑鱼红 (R=31, G=24, B=14)
#define MAROON     0x8000    // 褐红 (R=16, G=0,  B=0)

/* 紫色系 */
#define PURPLE     0x801F    // 紫色 (R=16, G=0,  B=31)
#define LAVENDER   0xE71F    // 薰衣草紫 (R=28, G=14, B=31)
#define INDIGO     0x4810    // 靛蓝 (R=9,  G=8,  B=16)

/* 棕色系 */
#define BROWN      0xA145    // 棕色 (R=20, G=8,  B=5)
#define CHOCOLATE  0xD343    // 巧克力色 (R=26, G=12, B=3)
#define TAN        0xD5B0    // 棕褐色 (R=26, G=45, B=16)

/* 特殊颜色 */
#define TEAL       0x0410    // 水鸭色 (R=0,  G=16, B=16)
#define TURQUOISE  0x471F    // 绿松石色 (R=8,  G=28, B=31)
#define CORAL      0xFBEA    // 珊瑚色 (R=31, G=46, B=10)



//进度条设置参数
#define PROGRESS_BAR_XSTART 15		//X起始值
#define PROGRESS_BAR_YSTART 70		//Y起始值
#define PROGRESS_BAR_XEND   105		//X结束值
#define PROGRESS_BAR_YEND   75		//Y结束值
#define PROGRESS_BAR_COLOR  BLACK	//进度条颜色

void LCD_GPIO_Init(void);//初始化GPIO
void LCD_Writ_Bus(u8 dat);//模拟SPI时序
void LCD_WR_DATA8(u8 dat);//写入一个字节
void LCD_WR_DATA(u16 dat);//写入两个字节
void LCD_WR_REG(u8 dat);//写入一个指令
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2);//设置坐标函数
uint8_t LCD_Init(void);//LCD初始化


void LCD_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color);//指定区域填充颜色
void LCD_DrawPoint(u16 x,u16 y,u16 color);//在指定位置画一个点
void LCD_DrawLine(u16 x1,u16 y1,u16 x2,u16 y2,u16 color);//在指定位置画一条线(X1,Y1,X2,Y2,颜色)
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2,u16 color);//在指定位置画一个矩形
void Draw_Circle(u16 x0,u16 y0,u8 r,u16 color);//在指定位置画一个圆(x,y,半径，颜色)
void drawProgressBarAnimation(void);//绘制进度条
	
void LCD_ShowChinese(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//显示汉字串(X,Y,"汉字串",字色,底色,尺寸,模式)
void LCD_ShowChinese12x12(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//显示单个12x12汉字
void LCD_ShowChinese16x16(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//显示单个16x16汉字
void LCD_ShowChinese24x24(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//显示单个24x24汉字
void LCD_ShowChinese32x32(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//显示单个32x32汉字

void LCD_ShowChar(u16 x,u16 y,u8 num,u16 fc,u16 bc,u8 sizey,u8 mode);//显示一个字符
void LCD_ShowString(u16 x,u16 y,const u8 *p,u16 fc,u16 bc,u8 sizey,u8 mode);//显示字符串(X,Y,"字符串",字色,底色,尺寸,模式)
u32 mypow(u8 m,u8 n);//求幂
void LCD_ShowIntNum(u16 x,u16 y,u16 num,u8 len,u16 fc,u16 bc,u8 sizey);//显示整数变量
void LCD_ShowFloatNum1(u16 x,u16 y,float num,u8 len,u16 fc,u16 bc,u8 sizey);//显示两位小数变量

void LCD_ShowPicture(u16 x,u16 y,u16 length,u16 width,const u8 pic[]);//显示图片


#endif

