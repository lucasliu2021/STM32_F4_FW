//
// Created by lucas on 2022/3/25.
//


/*
 * 采用定时器后台计时
 * 小时分钟秒钟
 * */

#include "bar_timer.h"
#include "GUI.h"
#include "Lcd_Driver.h"

uint8_t minutes = 0;
uint8_t seconds = 0;

void bar_timer()
{
    LCD_ShowNum(32, 2, minutes, 2);
    Gui_DrawFont_GBK16(48, 0, WHITE, BLACK, ":");
    LCD_ShowNum(50, 2, seconds, 2);
}