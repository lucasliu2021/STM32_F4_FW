
#include "main.h"
//嵌入式开发网
//淘宝网站：http://chinanuedc.taobao.com



//uint16_t LCD_BGR2RGB(uint16_t c);
void Gui_Circle(uint16_t X,uint16_t Y,uint16_t R,uint16_t fc);
void Gui_DrawLine(uint16_t x0, uint16_t y0,uint16_t x1, uint16_t y1,uint16_t Color);
void Gui_box(uint16_t x, uint16_t y, uint16_t w, uint16_t h,uint16_t bc);
void Gui_box2(uint16_t x,uint16_t y,uint16_t w,uint16_t h, uint8_t mode);
void DisplayButtonDown(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);
void DisplayButtonUp(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);
void Gui_DrawFont_GBK16(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s);
void Gui_DrawFont_GBK24(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s);
void Gui_DrawFont_Num32(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint16_t num) ;


void Test_Demo(void);	//液晶屏测试例程
void show_pic(void);
uint32_t LCD_Pow(uint8_t m,uint8_t n);
void LCD_ShowNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len);
void LCD_DrawWave(uint16_t wave[], uint8_t drawline, uint16_t colm, uint16_t heigh, uint16_t color);
void LCD_DrawFFTWave(float wave[],uint8_t drawline,uint16_t colm,uint8_t high,uint16_t size,uint16_t color);//drawline:是否连线，position：上下位置




