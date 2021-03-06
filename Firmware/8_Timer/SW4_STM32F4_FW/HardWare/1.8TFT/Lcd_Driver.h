#include "main.h"
#include "typedefine.h"

//嵌入式开发网
//淘宝网站：http://chinanuedc.taobao.com



//LCD重要参数集
typedef struct
{
    u16 width;            //LCD 宽度
    u16 height;            //LCD 高度
    u16 id;                //LCD ID
    u8 dir;            //横屏还是竖屏控制：0，竖屏；1，横屏。
    u16 wramcmd;        //开始写gram指令
    u16 setxcmd;        //设置x坐标指令
    u16 setycmd;        //设置y坐标指令
} _lcd_dev;

//LCD参数
extern _lcd_dev lcddev;    //管理LCD重要参数


#define RED      0xf800
#define GREEN      0x07e0
#define BLUE      0x001f
#define WHITE      0xffff
#define BLACK      0x0000
#define YELLOW  0xFFE0
#define GRAY0   0xEF7D    //灰色0 3165 00110 001011 00101
#define GRAY1   0x8410        //灰色1      00000 000000 00000
#define GRAY2   0x4208        //灰色2  1111111111011111

/////////////////////////////////////用户配置区///////////////////////////////////	 
//支持横竖屏快速定义切换，支持8/16位模式切换
#define USE_HORIZONTAL    0        //定义是否使用横屏 		0,不使用.  1,使用.
//使用模拟SPI作为测试



//液晶控制口置1操作语句宏定义
#define    LCD_SDA_SET    HAL_GPIO_WritePin(LCD_SDA_GPIO_Port, LCD_SDA_Pin, GPIO_PIN_SET)
#define    LCD_SCL_SET    HAL_GPIO_WritePin(LCD_SCL_GPIO_Port, LCD_SCL_Pin, GPIO_PIN_SET)

#define    LCD_CS_SET    HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET)
#define LCD_RST_SET   HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_SET) //RST PIN HIGH

#define    LCD_RS_SET    HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, GPIO_PIN_SET)
#define    LCD_BLK_SET    HAL_GPIO_WritePin(LCD_BLK_GPIO_Port, LCD_BLK_Pin, GPIO_PIN_SET)

//液晶控制口置0操作语句宏定义

#define    LCD_SDA_CLR    HAL_GPIO_WritePin(LCD_SDA_GPIO_Port, LCD_SDA_Pin, GPIO_PIN_RESET)
#define    LCD_SCL_CLR    HAL_GPIO_WritePin(LCD_SCL_GPIO_Port, LCD_SCL_Pin, GPIO_PIN_RESET)

#define    LCD_CS_CLR    HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET)
#define LCD_RST_CLR   HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_RESET)//RST PIN LOW

#define    LCD_RS_CLR    HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, GPIO_PIN_RESET)
#define    LCD_BLK_CLR    HAL_GPIO_WritePin(LCD_BLK_GPIO_Port, LCD_BLK_Pin, GPIO_PIN_RESET)


void LCD_GPIO_Init(void);//初始化IO口
void SPI_WriteData(u8 Data);//STM32_模拟SPI写一个字节数据底层函数
void LCD_WriteData_16Bit(uint16_t Data);//向液晶屏写一个16位数据

void Lcd_WriteIndex(u8 Index);//写控制器寄存器地址
void Lcd_WriteData(u8 Data);//  写寄存器数据
void Lcd_WriteReg(u8 Index, u8 Data);////写寄存器函数

u16 Lcd_ReadReg(u8 LCD_Reg);

void Lcd_Reset(void);

void Lcd_Init(void);

void Lcd_Clear(u16 Color);

void Lcd_SetXY(u16 x, u16 y);

void Gui_DrawPoint(u16 x, u16 y, u16 Data);

//unsigned int Lcd_ReadPoint(u16 x,u16 y);
void Lcd_custer_Clear(u16 X_MAX, u16 Y_MAX, u16 X_START, u16 Y_START, u16 Color);


