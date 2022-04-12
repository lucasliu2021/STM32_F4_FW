//
// Created by lucas on 2022/3/25.
//
#include "about.h"
#include "GUI.h"
#include "Lcd_Driver.h"

void about()
{
    Gui_DrawFont_GBK16(0, 0, WHITE, BLACK, "ABOUT");
    Gui_DrawFont_GBK16(0, 26, YELLOW, BLACK, "DEV  2022.3.25");
    Gui_DrawFont_GBK16(0, 58, YELLOW, BLACK, "FW  V5.0");
    Gui_DrawFont_GBK16(0, 100, WHITE, BLACK, "ÁõÁ¼ºÆ  Â«ÃÎÔÂ");
    Gui_DrawFont_GBK16(0, 128, WHITE, BLACK, "WWW.LHAO.TOP");
}
