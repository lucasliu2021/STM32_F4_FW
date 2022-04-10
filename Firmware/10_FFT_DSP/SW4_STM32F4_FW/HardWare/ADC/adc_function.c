#include "adc_function.h"

uint16_t i = 0, j = 0;
float temp;
uint16_t ADC_Value[384];
uint32_t ADC_IN9_Value;//ADת�����
uint16_t ADC_IN10_Value[128];//ADת�����
int32_t ADC_TEMP_Value;//ADת�����
float MCU_TEMP;//оƬ�¶�
void ADC_FUNCTION()
{

    for (i = 0, j = 0, ADC_IN9_Value = 0, ADC_TEMP_Value = 0; i < 384; j++)
    {
        ADC_IN9_Value += ADC_Value[i++];//ͨ��1��adֵ
        ADC_IN10_Value[j] = ADC_Value[i++];//ͨ��10��adֵ
        ADC_TEMP_Value += ADC_Value[i++];//�ڲ��¶ȴ�������adֵ
    }
    ADC_TEMP_Value = ADC_TEMP_Value / 128;//��ֵ�˲�
    ADC_IN9_Value = ADC_IN9_Value / 128;
    temp = V25 - ADC_TEMP_Value * 3.3 / 4095;
    MCU_TEMP = temp / Avg_Slope + 25;
}
