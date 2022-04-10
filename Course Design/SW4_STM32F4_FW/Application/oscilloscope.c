//
// Created by lucas on 2022/3/25.
//

#include "oscilloscope.h"
#include "first_init.h"

void oscilloscope()
{
    Gui_DrawFont_GBK16(0, 16, YELLOW, BLACK, "oscilloscope");
    delay_ms(2);
    HAL_ADC_Stop_DMA(&hadc1);
    //����&&����
    ADC_FUNCTION();
    //���Ʋ���&&�ֲ�����
    LCD_DrawWave(ADC_IN10_Value, FFT_Len, 1, 159, 70, YELLOW);
    //���ٸ���Ҷ�任
    FFT_Function(ADC_IN10_voltage);
    LCD_DrawFFTWave(FFT_MAG_Outputdata, 1, 159, 100, Half_FFT_Len, BLUE);
    //DMAУ��
    HAL_ADC_Start_DMA(&hadc1, (uint32_t *) &ADC_Value, 768);
}
