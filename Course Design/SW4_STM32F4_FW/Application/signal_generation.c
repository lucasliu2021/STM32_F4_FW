//
// Created by lucas on 2022/3/25.
//

#include "signal_generation.h"
#include "first_init.h"
void signal_generation()
{
    //»æÖÆ¾²Ì¬Êý¾Ý
    Gui_DrawFont_GBK16(0, 0, YELLOW, BLACK, "signal gener");
    Gui_DrawFont_GBK16(20, 20, WHITE, BLACK, "sine wave");
    Gui_DrawFont_GBK16(20, 40, WHITE, BLACK, "triangle wave");
    Gui_DrawFont_GBK16(20, 60, WHITE, BLACK, "square wave");
    switch (light_mode)
    {
        case 0:
            Gui_DrawFont_GBK16(0, 20, YELLOW, BLACK, "E");

            break;
        case 1:
            Gui_DrawFont_GBK16(0, 40, YELLOW, BLACK, "E");

            break;
        case 2:
            Gui_DrawFont_GBK16(0, 60, YELLOW, BLACK, "E");

            break;
        default:
            break;

    }


}