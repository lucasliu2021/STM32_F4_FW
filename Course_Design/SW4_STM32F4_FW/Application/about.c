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
    Gui_DrawFont_GBK16(0, 123, YELLOW, BLACK, "DON 2022.4.20");
    Gui_DrawFont_GBK16(0, 58, YELLOW, BLACK, "FW  V7.0");
    Gui_DrawFont_GBK16(0, 90, WHITE, BLACK, "ÁõÁ¼ºÆ  Â«ÃÎÔÂ");
    Gui_DrawFont_GBK16(0, 144, BLACK, YELLOW, "WWW.LHAO.TOP");
}
