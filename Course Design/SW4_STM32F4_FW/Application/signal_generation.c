//
// Created by lucas on 2022/3/25.
//

#include "signal_generation.h"
#include "first_init.h"

__IO uint8_t signal_mode;//�źŷ�����ģʽ
uint8_t Signal_mode_selection = 0;//����һ�μ���
uint8_t select_within_signal;//����ѡ��
void signal_generation()
{
    //���ƾ�̬����
    Gui_DrawFont_GBK16(0, 0, YELLOW, BLACK, "signal gener");
    Gui_DrawFont_GBK16(20, 20, WHITE, BLACK, "sine wave");
    Gui_DrawFont_GBK16(20, 40, WHITE, BLACK, "triangle wave");
    Gui_DrawFont_GBK16(20, 60, WHITE, BLACK, "square wave");
    Gui_DrawFont_GBK16(20, 80, WHITE, BLACK, "pulse wave");
    switch (signal_mode)
    {
        case 0:
            Gui_DrawFont_GBK16(0, 20, YELLOW, BLACK, "E");
            //���Ҳ�
            //������һ������,ÿ��ѡ��ʱ��������
            if (Signal_mode_selection == 1)
            {
                DSP_Sine();
                Signal_mode_selection = 0;
            }
            break;
        case 1:
            Gui_DrawFont_GBK16(0, 40, YELLOW, BLACK, "E");
            //���β�
            //������һ������
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