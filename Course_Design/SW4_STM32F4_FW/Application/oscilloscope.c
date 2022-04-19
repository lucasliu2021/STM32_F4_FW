//
// Created by lucas on 2022/3/25.
//

#include "oscilloscope.h"
#include "first_init.h"

void oscilloscope()
{
    Gui_DrawFont_GBK16(0, 0, YELLOW, BLACK, "oscilloscope");
    Gui_DrawFont_GBK16(0, 30, WHITE, BLACK, "FEQ:");
    Gui_DrawFont_GBK16(60, 30, WHITE, BLACK, "VPP:");
    delay_ms(2);
    HAL_ADC_Stop_DMA(&hadc1);
    //采样&&发生
    ADC_FUNCTION();
    signal_info();//信号信息
    //绘制波形&&局部清屏
    LCD_DrawWave(ADC_IN10_Value, FFT_Len, 1, 159, 70, YELLOW);
    //快速傅里叶变换
    FFT_Function(ADC_IN10_voltage);
    LCD_DrawFFTWave(FFT_MAG_Outputdata, 1, 159, 100, Half_FFT_Len, BLUE);
    //DMA校正
    HAL_ADC_Start_DMA(&hadc1, (uint32_t *) &ADC_Value, 768);
}
