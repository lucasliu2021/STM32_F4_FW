//
// Created by lucas on 2022/3/26.
//

#include "stopwatch.h"
#include "first_init.h"

uint8_t se1 = 0, se2 = 0;
uint8_t min1 = 0, min2 = 0;
uint8_t watch = 0;

void stopwatch()
{
    watch = 1;
    Gui_DrawFont_GBK24(0, 0, WHITE, BLACK, "STOPWATCH");
    se1 = seconds / 10;
    se2 = seconds % 10;
    min1 = minutes / 10;
    min2 = minutes % 10;
    Gui_DrawFont_Num32(0, 60, YELLOW, BLUE, min1);
    Gui_DrawFont_Num32(32, 60, YELLOW, BLUE, min2);
    Gui_DrawFont_Num32(64, 60, YELLOW, BLUE, se1);
    Gui_DrawFont_Num32(96, 60, YELLOW, BLUE, se2);

}

void watch_init()
{
    watch = 0;
    minutes = 0;
    seconds = 0;

}