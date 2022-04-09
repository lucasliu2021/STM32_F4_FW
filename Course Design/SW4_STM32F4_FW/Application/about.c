//
// Created by lucas on 2022/3/25.
//
#include "about.h"
#include "GUI.h"
#include "Lcd_Driver.h"
void about()
{
    Gui_DrawFont_GBK16(0, 0, YELLOW, BLACK, "ABOUT");
    Gui_DrawFont_GBK16(0, 26, YELLOW, BLACK, "DEVP-TIME");
    Gui_DrawFont_GBK16(0, 42, YELLOW, BLACK, "2022.3.25");
    Gui_DrawFont_GBK16(0, 58, YELLOW, BLACK, "FW_VERSION");
    Gui_DrawFont_GBK16(0, 74, YELLOW, BLACK, "V2.0");
    Gui_DrawFont_GBK16(0, 100, WHITE, BLACK, "ÁõÁ¼ºÆ  Â«ÃÎÔÂ");
    Gui_DrawFont_GBK16(0, 144, WHITE, BLACK, "WWW.LHAO.TOP");
}
