//
// Created by lucas on 2022/3/25.
//

#include "signal_generation.h"
#include "first_init.h"

__IO uint8_t signal_mode;//信号发生器模式
uint8_t Signal_mode_selection = 0;//生成一次监视
uint8_t select_within_signal;//内联选择
void signal_generation()
{
    //绘制静态数据
    Gui_DrawFont_GBK16(0, 0, YELLOW, BLACK, "signal gener");
    Gui_DrawFont_GBK16(20, 20, WHITE, BLACK, "sine wave");
    Gui_DrawFont_GBK16(20, 40, WHITE, BLACK, "triangle wave");
    Gui_DrawFont_GBK16(20, 60, WHITE, BLACK, "square wave");
    Gui_DrawFont_GBK16(20, 80, WHITE, BLACK, "pulse wave");
    switch (signal_mode)
    {
        case 0:
            Gui_DrawFont_GBK16(0, 20, YELLOW, BLACK, "E");
            //正弦波
            //仅生成一次数组,每次选择时重新生成
            if (Signal_mode_selection == 1)
            {
                DSP_Sine();
                Signal_mode_selection = 0;
            }
            break;
        case 1:
            Gui_DrawFont_GBK16(0, 40, YELLOW, BLACK, "E");
            //矩形波
            //仅生成一次数组
            if (Signal_mode_selection == 1)
            {
                DSP_multSine();
                Signal_mode_selection = 0;
            }
            break;
        case 2:
            Gui_DrawFont_GBK16(0, 60, YELLOW, BLACK, "E");
            //square wave
            break;
        case 3:
            Gui_DrawFont_GBK16(0, 80, YELLOW, BLACK, "E");
            //pulse wave
            break;
        default:
            break;

    }


}