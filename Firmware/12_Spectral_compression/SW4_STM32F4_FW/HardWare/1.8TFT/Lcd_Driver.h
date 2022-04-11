#include "main.h"

//Ƕ��ʽ������
//�Ա���վ��http://chinanuedc.taobao.com



//LCD��Ҫ������
typedef struct
{
    uint16_t width;            //LCD ���
    uint16_t height;            //LCD �߶�
    uint16_t id;                //LCD ID
    uint8_t dir;            //���������������ƣ�0��������1��������
    uint16_t wramcmd;        //��ʼдgramָ��
    uint16_t setxcmd;        //����x����ָ��
    uint16_t setycmd;        //����y����ָ��
} _lcd_dev;

//LCD����
extern _lcd_dev lcddev;    //����LCD��Ҫ����


#define RED      0xf800
#define GREEN      0x07e0
#define BLUE      0x001f
#define WHITE      0xffff
#define BLACK      0x0000
#define YELLOW  0xFFE0
#define GRAY0   0xEF7D    //��ɫ0 3165 00110 001011 00101
#define GRAY1   0x8410        //��ɫ1      00000 000000 00000
#define GRAY2   0x4208        //��ɫ2  1111111111011111

/////////////////////////////////////�û�������///////////////////////////////////	 
//֧�ֺ��������ٶ����л���֧��8/16λģʽ�л�
#define USE_HORIZONTAL    0        //�����Ƿ�ʹ�ú��� 		0,��ʹ��.  1,ʹ��.
//ʹ��ģ��SPI��Ϊ����



//Һ�����ƿ���1�������궨��
#define    LCD_SDA_SET    HAL_GPIO_WritePin(LCD_SDA_GPIO_Port, LCD_SDA_Pin, GPIO_PIN_SET)
#define    LCD_SCL_SET    HAL_GPIO_WritePin(LCD_SCL_GPIO_Port, LCD_SCL_Pin, GPIO_PIN_SET)

#define    LCD_CS_SET    HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET)
#define LCD_RST_SET   HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_SET) //RST PIN HIGH

#define    LCD_RS_SET    HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, GPIO_PIN_SET)
#define    LCD_BLK_SET    HAL_GPIO_WritePin(LCD_BLK_GPIO_Port, LCD_BLK_Pin, GPIO_PIN_SET)

//Һ�����ƿ���0�������궨��

#define    LCD_SDA_CLR    HAL_GPIO_WritePin(LCD_SDA_GPIO_Port, LCD_SDA_Pin, GPIO_PIN_RESET)
#define    LCD_SCL_CLR    HAL_GPIO_WritePin(LCD_SCL_GPIO_Port, LCD_SCL_Pin, GPIO_PIN_RESET)

#define    LCD_CS_CLR    HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET)
#define LCD_RST_CLR   HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_RESET)//RST PIN LOW

#define    LCD_RS_CLR    HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, GPIO_PIN_RESET)
#define    LCD_BLK_CLR    HAL_GPIO_WritePin(LCD_BLK_GPIO_Port, LCD_BLK_Pin, GPIO_PIN_RESET)


void LCD_GPIO_Init(void);//��ʼ��IO��
void SPI_WriteData(uint8_t Data);//STM32_ģ��SPIдһ���ֽ����ݵײ㺯��
void LCD_WriteData_16Bit(uint16_t Data);//��Һ����дһ��16λ����

void Lcd_WriteIndex(uint8_t Index);//д�������Ĵ�����ַ
void Lcd_WriteData(uint8_t Data);//  д�Ĵ�������
void Lcd_WriteReg(uint8_t Index, uint8_t Data);////д�Ĵ�������

uint16_t Lcd_ReadReg(uint8_t LCD_Reg);

void Lcd_Reset(void);

void Lcd_Init(void);

void Lcd_Clear(uint16_t Color);

void Lcd_SetXY(uint16_t x, uint16_t y);

void Gui_DrawPoint(uint16_t x, uint16_t y, uint16_t Data);

//unsigned int Lcd_ReadPoint(uint16_t x,uint16_t y);
void Lcd_custer_Clear(uint16_t X_MAX, uint16_t Y_MAX, uint16_t X_START, uint16_t Y_START, uint16_t Color);


