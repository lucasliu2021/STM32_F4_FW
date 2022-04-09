//
// Created by lucas on 2022/3/25.
//

#include "screen_light.h"
#include "first_init.h"

__IO uint8_t light_mode;
uint8_t screen;

void screen_light()
{

    //»æÖÆ¾²Ì¬Êý¾Ý
    Gui_DrawFont_GBK16(0, 0, YELLOW, BLACK, "screen_light");
    Gui_DrawFont_GBK16(20, 20, WHITE, BLACK, "MAX");
    Gui_DrawFont_GBK16(20, 40, WHITE, BLACK, "NOR");
    Gui_DrawFont_GBK16(20, 60, WHITE, BLACK, "MIN");
    switch (light_mode)
    {
        case 0:
            Gui_DrawFont_GBK16(0, 20, YELLOW, BLACK, "E");
            LCD_BLK = 99;
            break;
        case 1:
            Gui_DrawFont_GBK16(0, 40, YELLOW, BLACK, "E");
            LCD_BLK = 50;
            break;
        case 2:
            Gui_DrawFont_GBK16(0, 60, YELLOW, BLACK, "E");
            LCD_BLK = 10;
            break;
        default:
            break;

    }


}