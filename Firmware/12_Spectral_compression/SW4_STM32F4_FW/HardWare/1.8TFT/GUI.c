#include "main.h"
#include "Lcd_Driver.h"
#include "GUI.h"
#include "delay.h"
#include "Font.h"
#include "Picture.h"

//Ƕ��ʽ������
//�Ա���վ��http://chinanuedc.taobao.com

//��һ����Ϊ���Ļ�Բ����

void Gui_Circle(uint16_t X, uint16_t Y, uint16_t R, uint16_t fc)
{//Bresenham�㷨 
    unsigned short a, b;
    int c;
    a = 0;
    b = R;
    c = 3 - 2 * R;
    while (a < b)
    {
        Gui_DrawPoint(X + a, Y + b, fc);     //        7
        Gui_DrawPoint(X - a, Y + b, fc);     //        6
        Gui_DrawPoint(X + a, Y - b, fc);     //        2
        Gui_DrawPoint(X - a, Y - b, fc);     //        3
        Gui_DrawPoint(X + b, Y + a, fc);     //        8
        Gui_DrawPoint(X - b, Y + a, fc);     //        5
        Gui_DrawPoint(X + b, Y - a, fc);     //        1
        Gui_DrawPoint(X - b, Y - a, fc);     //        4

        if (c < 0) c = c + 4 * a + 6;
        else
        {
            c = c + 4 * (a - b) + 10;
            b -= 1;
        }
        a += 1;
    }
    if (a == b)
    {
        Gui_DrawPoint(X + a, Y + b, fc);
        Gui_DrawPoint(X + a, Y + b, fc);
        Gui_DrawPoint(X + a, Y - b, fc);
        Gui_DrawPoint(X - a, Y - b, fc);
        Gui_DrawPoint(X + b, Y + a, fc);
        Gui_DrawPoint(X - b, Y + a, fc);
        Gui_DrawPoint(X + b, Y - a, fc);
        Gui_DrawPoint(X - b, Y - a, fc);
    }

}

//���ߺ���
void Gui_DrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t Color)
{
    int dx,             // difference in x's
    dy,             // difference in y's
    dx2,            // dx,dy * 2
    dy2,
            x_inc,          // amount in pixel space to move during drawing
    y_inc,          // amount in pixel space to move during drawing
    error,          // the discriminant i.e. error i.e. decision variable
    index;          // used for looping	


    Lcd_SetXY(x0, y0);
    dx = x1 - x0;//����x����
    dy = y1 - y0;//����y����

    if (dx >= 0)
    {
        x_inc = 1;
    } else
    {
        x_inc = -1;
        dx = -dx;
    }

    if (dy >= 0)
    {
        y_inc = 1;
    } else
    {
        y_inc = -1;
        dy = -dy;
    }

    dx2 = dx << 1;
    dy2 = dy << 1;

    if (dx > dy)//x�������y���룬��ôÿ��x����ֻ��һ���㣬ÿ��y���������ɸ���
    {//���ߵĵ�������x���룬��x���������
        // initialize error term
        error = dy2 - dx;

        // draw the line
        for (index = 0; index <= dx; index++)//Ҫ���ĵ������ᳬ��x����
        {
            //����
            Gui_DrawPoint(x0, y0, Color);

            // test if error has overflowed
            if (error >= 0) //�Ƿ���Ҫ����y����ֵ
            {
                error -= dx2;

                // move to next line
                y0 += y_inc;//����y����ֵ
            } // end if error overflowed

            // adjust the error term
            error += dy2;

            // move to the next pixel
            x0 += x_inc;//x����ֵÿ�λ���󶼵���1
        } // end for
    } // end if |slope| <= 1
    else//y�����x�ᣬ��ÿ��y����ֻ��һ���㣬x�����ɸ���
    {//��y��Ϊ��������
        // initialize error term
        error = dx2 - dy;

        // draw the line
        for (index = 0; index <= dy; index++)
        {
            // set the pixel
            Gui_DrawPoint(x0, y0, Color);

            // test if error overflowed
            if (error >= 0)
            {
                error -= dy2;

                // move to next line
                x0 += x_inc;
            } // end if error overflowed

            // adjust the error term
            error += dx2;

            // move to the next pixel
            y0 += y_inc;
        } // end for
    } // end else |slope| > 1
}


void Gui_box(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t bc)
{
    Gui_DrawLine(x, y, x + w, y, 0xEF7D);
    Gui_DrawLine(x + w - 1, y + 1, x + w - 1, y + 1 + h, 0x2965);
    Gui_DrawLine(x, y + h, x + w, y + h, 0x2965);
    Gui_DrawLine(x, y, x, y + h, 0xEF7D);
    Gui_DrawLine(x + 1, y + 1, x + 1 + w - 2, y + 1 + h - 2, bc);
}


void Gui_box2(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t mode)
{
    if (mode == 0)
    {
        Gui_DrawLine(x, y, x + w, y, 0xEF7D);
        Gui_DrawLine(x + w - 1, y + 1, x + w - 1, y + 1 + h, 0x2965);
        Gui_DrawLine(x, y + h, x + w, y + h, 0x2965);
        Gui_DrawLine(x, y, x, y + h, 0xEF7D);
    }
    if (mode == 1)
    {
        Gui_DrawLine(x, y, x + w, y, 0x2965);
        Gui_DrawLine(x + w - 1, y + 1, x + w - 1, y + 1 + h, 0xEF7D);
        Gui_DrawLine(x, y + h, x + w, y + h, 0xEF7D);
        Gui_DrawLine(x, y, x, y + h, 0x2965);
    }
    if (mode == 2)
    {
        Gui_DrawLine(x, y, x + w, y, 0xffff);
        Gui_DrawLine(x + w - 1, y + 1, x + w - 1, y + 1 + h, 0xffff);
        Gui_DrawLine(x, y + h, x + w, y + h, 0xffff);
        Gui_DrawLine(x, y, x, y + h, 0xffff);
    }
}


/**************************************************************************************
��������: ����Ļ��ʾһ͹��İ�ť��
��    ��: uint16_t x1,y1,x2,y2 ��ť�����ϽǺ����½�����
��    ��: ��
**************************************************************************************/
void DisplayButtonDown(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
    Gui_DrawLine(x1, y1, x2, y1, GRAY2);  //H
    Gui_DrawLine(x1 + 1, y1 + 1, x2, y1 + 1, GRAY1);  //H
    Gui_DrawLine(x1, y1, x1, y2, GRAY2);  //V
    Gui_DrawLine(x1 + 1, y1 + 1, x1 + 1, y2, GRAY1);  //V
    Gui_DrawLine(x1, y2, x2, y2, WHITE);  //H
    Gui_DrawLine(x2, y1, x2, y2, WHITE);  //V
}

/**************************************************************************************
��������: ����Ļ��ʾһ���µİ�ť��
��    ��: uint16_t x1,y1,x2,y2 ��ť�����ϽǺ����½�����
��    ��: ��
**************************************************************************************/
void DisplayButtonUp(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
    Gui_DrawLine(x1, y1, x2, y1, WHITE); //H
    Gui_DrawLine(x1, y1, x1, y2, WHITE); //V

    Gui_DrawLine(x1 + 1, y2 - 1, x2, y2 - 1, GRAY1);  //H
    Gui_DrawLine(x1, y2, x2, y2, GRAY2);  //H
    Gui_DrawLine(x2 - 1, y1 + 1, x2 - 1, y2, GRAY1);  //V
    Gui_DrawLine(x2, y1, x2, y2, GRAY2); //V
}


//��ʾ16x16���ַ�

void Gui_DrawFont_GBK16(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s)
{
    unsigned char i, j;
    unsigned short k, x0;
    x0 = x;

    while (*s)
    {
        if ((*s) < 128)
        {
            k = *s;
            if (k == 13)
            {
                x = x0;
                y += 16;
            } else
            {
                if (k > 32) k -= 32; else k = 0;

                for (i = 0; i < 16; i++)
                    for (j = 0; j < 8; j++)
                    {
                        if (asc16[k * 16 + i] & (0x80 >> j)) Gui_DrawPoint(x + j, y + i, fc);
                        else
                        {
                            if (fc != bc) Gui_DrawPoint(x + j, y + i, bc);
                        }
                    }
                x += 8;
            }
            s++;
        } else
        {


            for (k = 0; k < hz16_num; k++) //�������ֿ�����Ҷ�Ӧ�ַ��Ĵ���
            {
                if ((hz16[k].Index[0] == *(s)) && (hz16[k].Index[1] == *(s + 1)))
                {
                    for (i = 0; i < 16; i++)
                    {
                        for (j = 0; j < 8; j++)
                        {
                            if (hz16[k].Msk[i * 2] & (0x80 >> j)) Gui_DrawPoint(x + j, y + i, fc);
                            else
                            {
                                if (fc != bc) Gui_DrawPoint(x + j, y + i, bc);
                            }
                        }
                        for (j = 0; j < 8; j++)
                        {
                            if (hz16[k].Msk[i * 2 + 1] & (0x80 >> j)) Gui_DrawPoint(x + j + 8, y + i, fc);
                            else
                            {
                                if (fc != bc) Gui_DrawPoint(x + j + 8, y + i, bc);
                            }
                        }
                    }
                }
            }
            s += 2;
            x += 16;
        }

    }
}



//��ʾ24x24���ַ�

void Gui_DrawFont_GBK24(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s)
{
    unsigned char i, j;
    unsigned short k;

    while (*s)
    {
        if (*s < 0x80)
        {
            k = *s;
            if (k > 32) k -= 32; else k = 0;

            for (i = 0; i < 16; i++)
                for (j = 0; j < 8; j++)
                {
                    if (asc16[k * 16 + i] & (0x80 >> j))
                        Gui_DrawPoint(x + j, y + i, fc);
                    else
                    {
                        if (fc != bc) Gui_DrawPoint(x + j, y + i, bc);
                    }
                }
            s++;
            x += 8;
        } else
        {

            for (k = 0; k < hz24_num; k++)
            {
                if ((hz24[k].Index[0] == *(s)) && (hz24[k].Index[1] == *(s + 1)))
                {
                    for (i = 0; i < 24; i++)
                    {
                        for (j = 0; j < 8; j++)
                        {
                            if (hz24[k].Msk[i * 3] & (0x80 >> j))
                                Gui_DrawPoint(x + j, y + i, fc);
                            else
                            {
                                if (fc != bc) Gui_DrawPoint(x + j, y + i, bc);
                            }
                        }
                        for (j = 0; j < 8; j++)
                        {
                            if (hz24[k].Msk[i * 3 + 1] & (0x80 >> j)) Gui_DrawPoint(x + j + 8, y + i, fc);
                            else
                            {
                                if (fc != bc) Gui_DrawPoint(x + j + 8, y + i, bc);
                            }
                        }
                        for (j = 0; j < 8; j++)
                        {
                            if (hz24[k].Msk[i * 3 + 2] & (0x80 >> j))
                                Gui_DrawPoint(x + j + 16, y + i, fc);
                            else
                            {
                                if (fc != bc) Gui_DrawPoint(x + j + 16, y + i, bc);
                            }
                        }
                    }
                }
            }
            s += 2;
            x += 24;
        }
    }
}

//��ʾ16x32�ĵ��������ַ�--���������

void Gui_DrawFont_Num32(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint16_t num)
{
    unsigned char i, j, k, c;

    for (i = 0; i < 32; i++)
    {
        for (j = 0; j < 4; j++)
        {
            c = *(sz32 + num * 32 * 4 + i * 4 + j);
            for (k = 0; k < 8; k++)
            {

                if (c & (0x80 >> k)) Gui_DrawPoint(x + j * 8 + k, y + i, fc);
                else
                {
                    if (fc != bc) Gui_DrawPoint(x + j * 8 + k, y + i, bc);
                }
            }
        }
    }
}


unsigned char Num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


void Redraw_Mainmenu(void)
{

    Lcd_Clear(GRAY0);

    Gui_DrawFont_GBK16(32, 2, BLUE, GRAY0, "��ֻ����");
    Gui_DrawFont_GBK16(32, 20, BLUE, GRAY0, "Һ������");

    DisplayButtonUp(15, 38, 113, 58); //x1,y1,x2,y2
    Gui_DrawFont_GBK16(16, 40, GREEN, GRAY0, "��ɫ������");

    DisplayButtonUp(15, 68, 113, 88); //x1,y1,x2,y2
    Gui_DrawFont_GBK16(16, 70, BLUE, GRAY0, "������ʾ����");

    DisplayButtonUp(15, 98, 113, 118); //x1,y1,x2,y2
    Gui_DrawFont_GBK16(16, 100, RED, GRAY0, "ͼƬ��ʾ����");

#if USE_HORIZONTAL == 1    //ʹ�ú���

    Gui_DrawFont_Num32(125,90,RED,GRAY0,Num[5]);
    delay_ms(1000);
    Gui_DrawFont_Num32(125,90,RED,GRAY0,Num[4]);
    delay_ms(1000);
    Gui_DrawFont_Num32(125,90,RED,GRAY0,Num[3]);
    delay_ms(1000);
    Gui_DrawFont_Num32(125,90,RED,GRAY0,Num[2]);
    delay_ms(1000);
    Gui_DrawFont_Num32(125,90,RED,GRAY0,Num[1]);
    delay_ms(1000);
    Gui_DrawFont_Num32(125,90,RED,GRAY0,Num[0]);

#else

    Gui_DrawFont_Num32(100, 125, RED, GRAY0, Num[5]);
    delay_ms(1000);
    Gui_DrawFont_Num32(100, 125, RED, GRAY0, Num[4]);
    delay_ms(1000);
    Gui_DrawFont_Num32(100, 125, RED, GRAY0, Num[3]);
    delay_ms(1000);
    Gui_DrawFont_Num32(100, 125, RED, GRAY0, Num[2]);
    delay_ms(1000);
    Gui_DrawFont_Num32(100, 125, RED, GRAY0, Num[1]);
    delay_ms(1000);
    Gui_DrawFont_Num32(100, 125, RED, GRAY0, Num[0]);

#endif

}

void Num_Test(void)
{
    uint8_t i = 0;
    Lcd_Clear(GRAY0);
    Gui_DrawFont_GBK16(16, 20, RED, GRAY0, "Num Test");
    delay_ms(1000);
    Lcd_Clear(GRAY0);

    for (i = 0; i < 10; i++)
    {
        Gui_DrawFont_Num32((i % 3) * 40, 32 * (i / 3), RED, GRAY0, Num[i]);
        delay_ms(100);
    }
    delay_ms(2000);

}

void Font_Test(void)
{
    Lcd_Clear(GRAY0);
    Gui_DrawFont_GBK16(16, 10, BLUE, GRAY0, "������ʾ����");

    delay_ms(1000);
    Lcd_Clear(GRAY0);
    Gui_DrawFont_GBK16(32, 16, BLACK, GRAY0, "��ֻ����");
    Gui_DrawFont_GBK16(32, 36, BLACK, GRAY0, "���Ĳ���");
    Gui_DrawFont_GBK16(16, 56, BLUE, GRAY0, "רעҺ������");
    Gui_DrawFont_GBK16(16, 76, RED, GRAY0, "ȫ�̼���֧��");
    Gui_DrawFont_GBK16(16, 116, GREEN, GRAY0, "chinanuedc");
    delay_ms(1800);
}

void Color_Test(void)
{
    uint8_t i = 1;
    Lcd_Clear(GRAY0);

    Gui_DrawFont_GBK16(20, 10, BLUE, GRAY0, "Color Test");
    delay_ms(200);

    while (i--)
    {
        Lcd_Clear(WHITE);
        Lcd_Clear(BLACK);
        Lcd_Clear(RED);
        Lcd_Clear(GREEN);
        Lcd_Clear(BLUE);
    }
}

//16λ ��ֱɨ��  �ҵ���  ��λ��ǰ
void show_pic(void)
{
    int i, j, k;
    unsigned char picH, picL;

//	Lcd_Clear(GRAY0);
//	
//	Gui_DrawFont_GBK16(16,10,BLUE,GRAY0,"ͼƬ��ʾ����");
//	
//	delay_ms(1000);
//	
//	Lcd_Clear(GRAY0);

#if USE_HORIZONTAL == 1    //ʹ�ú���

    {
            k=0;
            for(i=0;i<128;i++)
            for(j=0;j<160;j++)
            {
                picH=gImage_1234[k++];
                picL=gImage_1234[k++];
                Lcd_WriteData(picH);
                Lcd_WriteData(picL);


            }
    }


#else
    {
        k = 0;
        for (i = 0; i < 160; i++)
            for (j = 0; j < 128; j++)
            {
                picH = gImage_1[k++];
                picL = gImage_1[k++];
                Lcd_WriteData(picH);
                Lcd_WriteData(picL);
            }
        delay_ms(300);
        k = 0;
        for (i = 0; i < 160; i++)
            for (j = 0; j < 128; j++)
            {
                picH = gImage_2[k++];
                picL = gImage_2[k++];
                Lcd_WriteData(picH);
                Lcd_WriteData(picL);
            }
        delay_ms(300);
        k = 0;
        for (i = 0; i < 160; i++)
            for (j = 0; j < 128; j++)
            {
                picH = gImage_3[k++];
                picL = gImage_3[k++];
                Lcd_WriteData(picH);
                Lcd_WriteData(picL);
            }
        delay_ms(300);
        k = 0;
        for (i = 0; i < 160; i++)
            for (j = 0; j < 128; j++)
            {
                picH = gImage_4[k++];
                picL = gImage_4[k++];
                Lcd_WriteData(picH);
                Lcd_WriteData(picL);
            }
        delay_ms(300);
        k = 0;
        for (i = 0; i < 160; i++)
            for (j = 0; j < 128; j++)
            {
                picH = gImage_5[k++];
                picL = gImage_5[k++];
                Lcd_WriteData(picH);
                Lcd_WriteData(picL);
            }
        delay_ms(300);


    }
#endif
}

//��Բ ����  �㷨��ʾ
void show_Circle(void)
{

    Lcd_Clear(GRAY0);

    Gui_DrawFont_GBK16(8, 10, BLUE, GRAY0, "Circle��ʾ����");

    delay_ms(1000);

    Lcd_Clear(GRAY0);

#if USE_HORIZONTAL == 1    //ʹ�ú���

    Gui_DrawLine(0, 0,159,0,RED);//��һ��ֱ����
    Gui_DrawLine(0, 1,159,1,RED);//��һ��ֱ����

    Gui_DrawLine(159, 0,159,127,RED);//��һ��ֱ����
    Gui_DrawLine(158, 0,158,127,RED);//��һ��ֱ����

    Gui_DrawLine(0, 127,159,127,RED);//��һ��ֱ����
    Gui_DrawLine(0, 126,159,126,RED);//��һ��ֱ����

    Gui_DrawLine(0, 0,0, 127,RED);//��һ��ֱ����
    Gui_DrawLine(1, 0,1, 127,RED);//��һ��ֱ����

#else		//������ʾ

    Gui_DrawLine(0, 0, 127, 0, RED);//��һ��ֱ����
    Gui_DrawLine(0, 1, 127, 1, RED);//��һ��ֱ����

    Gui_DrawLine(127, 0, 127, 159, RED);//��һ��ֱ����
    Gui_DrawLine(126, 0, 126, 159, RED);//��һ��ֱ����

    Gui_DrawLine(0, 159, 127, 159, RED);//��һ��ֱ����
    Gui_DrawLine(0, 158, 127, 158, RED);//��һ��ֱ����

    Gui_DrawLine(0, 0, 0, 159, RED);//��һ��ֱ����
    Gui_DrawLine(1, 0, 1, 159, RED);//��һ��ֱ����

#endif

    Gui_Circle(64, 64, 50, RED);//��һ��Բ��
    Gui_Circle(64, 64, 40, GREEN);
    Gui_Circle(64, 64, 30, BLUE);


    Gui_DrawLine(10, 79, 110, 79, BLACK);//��һ����ɫ��ֱ����
    Gui_DrawLine(10, 80, 110, 80, BLACK);//��һ����ɫ��ֱ����
    Gui_DrawLine(10, 81, 110, 81, BLACK);//��һ����ɫ��ֱ����
}


void Test_Demo(void)    //Һ������������
{
    Redraw_Mainmenu();
    Color_Test();//�򵥴�ɫ������
    Num_Test();  //������ʾ����
    Font_Test();//��Ӣ����ʾ����
    show_pic();//ͼƬ��ʾʾ��
    delay_ms(1200);
    show_Circle();//��ͼ�㷨��ʾ---��Բ
    delay_ms(2000);

}

// ADC2TFT
//m^n����
//����ֵ:m^n�η�.
uint32_t LCD_Pow(uint8_t m, uint8_t n)
{
    uint32_t result = 1;
    while (n--)result *= m;
    return result;
}

//��ʾ����,��λΪ0,����ʾ
//x,y :�������	 
//len :���ֵ�λ��
//color:��ɫ 
//num:��ֵ(0~4294967295);	 
void LCD_ShowNum(uint16_t x, uint16_t y, uint32_t num, uint8_t len)
{
    uint8_t t, temp, shuzi[len];
    uint8_t enshow = 0;
    for (t = 0; t < len; t++)
    {
        temp = (num / LCD_Pow(10, len - t - 1)) % 10;
        if (enshow == 0 && t < (len - 1))
        {
            if (temp == 0)
            {
                shuzi[t] = 32;
                continue;
            } else enshow = 1;

        }
        shuzi[t] = temp + 0x30;
    }
    Gui_DrawFont_GBK16(x, y, WHITE, BLACK, shuzi);
}

//���Ʋ���
void LCD_DrawWave(uint16_t wave[], uint16_t num, uint8_t drawline, uint16_t colm, uint16_t heigh, uint16_t color)
{
    uint8_t lie_size = 127;//LCD����
    uint8_t i = 0, j = 0;
    for (; lie_size > 0; lie_size--)
    {
        for (j = colm - heigh; j <= colm; j++)//���ĳ��
        {
            Gui_DrawPoint(lie_size, j, BLACK);
        }
        Gui_DrawPoint(lie_size, colm - (unsigned char) (wave[i*num/128] * heigh / 4095), color);

        if ((i > 1) && (i < 128) && drawline)
        {
            if ((wave[i*num/128] - wave[(i - 1)*num/128] > 74 || (wave[i*num/128] - wave[(i - 1)*num/128] < -74)))//4096/HIGH=74

                Gui_DrawLine(lie_size, colm - (unsigned char) (wave[i*num/128] * heigh / 4095), lie_size + 1,
                             colm - (unsigned char) (wave[(i - 1)*num/128] * heigh / 4095), color);
        }

        i++;

    }
}

uint16_t point[128];
float div = 1;
uint16_t max = 0;

void LCD_DrawFFTWave(float wave[], uint8_t drawline, uint16_t colm, uint8_t high, uint16_t size,
                     uint16_t color)//drawline:�Ƿ����ߣ�position������λ��
{
    uint8_t i = 0;//LCD
    if (size > 127)//������Ļ�ֱ��ʵ����������ϵ���ʾ��Χ
        size = 127;

    for (i = 0; i < size; i++)
    {
        if (wave[i] > max)
            max = wave[i];
    }
    if (max > high)
    {
        div = (float) max / high;
    } else
    {
        div = 1;
    }
    for (i = 0; i < size; i++)
    {
        point[i] = wave[i] / div;//���ȷ�������
        Gui_DrawPoint(i, colm - point[i], color); //������Ļ�ֱ�160*128��ADֵ���л���
        if (drawline)
            Gui_DrawLine(i, colm - point[i], i, colm, color);//�����ߵĳ���
    }
}
