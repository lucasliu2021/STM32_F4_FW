//
// Created by lucas on 2022/3/26.
//

#include "gallery.h"
#include "GUI.h"
#include "Picture.h"
#include "Lcd_Driver.h"
#include "delay.h"

void gallery()
{
    int i, j, k;
    unsigned char picH, picL;
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
        delay_ms(3000);
        k = 0;
        for (i = 0; i < 160; i++)
            for (j = 0; j < 128; j++)
            {
                picH = gImage_2[k++];
                picL = gImage_2[k++];
                Lcd_WriteData(picH);
                Lcd_WriteData(picL);
            }
        delay_ms(3000);
        k = 0;
        for (i = 0; i < 160; i++)
            for (j = 0; j < 128; j++)
            {
                picH = gImage_3[k++];
                picL = gImage_3[k++];
                Lcd_WriteData(picH);
                Lcd_WriteData(picL);
            }
        delay_ms(3000);
        k = 0;
        for (i = 0; i < 160; i++)
            for (j = 0; j < 128; j++)
            {
                picH = gImage_4[k++];
                picL = gImage_4[k++];
                Lcd_WriteData(picH);
                Lcd_WriteData(picL);
            }
        delay_ms(3000);
        k = 0;
        for (i = 0; i < 160; i++)
            for (j = 0; j < 128; j++)
            {
                picH = gImage_5[k++];
                picL = gImage_5[k++];
                Lcd_WriteData(picH);
                Lcd_WriteData(picL);
            }
        delay_ms(6000);
    }
}