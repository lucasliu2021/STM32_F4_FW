//
// Created by lucas on 2022/4/9.
//

#include "setting.h"
#include "first_init.h"

__IO uint8_t setting_mode;
uint8_t select_within_setting;

void setting()
{
    //»æÖÆ¾²Ì¬Êý¾Ý
    Gui_DrawFont_GBK16(0, 0, YELLOW, BLACK, "setting");
    Gui_DrawFont_GBK16(40, 20, WHITE, BLACK, "BUZZER");
    switch (setting_mode)
    {
        case 0:
            Gui_DrawFont_GBK16(0, 20, YELLOW, BLACK, "EN");
            buzzer_swtich = 1;
            break;
        case 1:
            Gui_DrawFont_GBK16(0, 20, YELLOW, BLACK, "DS");
            buzzer_swtich = 0;
            break;
        default:
            break;

    }
}