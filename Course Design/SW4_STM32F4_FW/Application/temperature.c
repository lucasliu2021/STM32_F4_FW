//
// Created by lucas on 2022/3/22.
//
#include "first_init.h"


void temperature()
{
    //���ƾ�̬����
    Gui_DrawFont_GBK16(0, 0, YELLOW, BLACK, "temperature");
    Gui_DrawFont_GBK16(0, 20, YELLOW, BLACK, "LLHAO-FW1");
    Gui_DrawFont_GBK16(0, 40, YELLOW, BLACK, "MCU_TEMP:");
    Gui_DrawFont_GBK16(100, 40, YELLOW, BLACK, "��");
    Gui_DrawFont_GBK16(0, 56, YELLOW, BLACK, "NTC_TEMP:");
    Gui_DrawFont_GBK16(100, 56, YELLOW, BLACK, "��");
    /*Gui_DrawFont_GBK16(0, 66, YELLOW, BLACK, "WAVE");*/
    delay_ms(8);
    //Lcd_custer_Clear(128, 160, 0, 50, BLACK);
    /*HAL_ADC_Stop_DMA(&hadc1);*/
    //����&&����
    ADC_FUNCTION();
    TEMP_DATA();
    //�¶���ʾ
    LCD_ShowNum(77, 40, MCU_TEMP, 2);//оƬ�¶�
    LCD_ShowNum(77, 56, NTC_TEMP, 2);//NTC�¶�

    //DMAУ��
    HAL_ADC_Start_DMA(&hadc1, (uint32_t *) &ADC_Value, 768);
}
