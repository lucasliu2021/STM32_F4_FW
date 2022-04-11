#include "adc_function.h"
#include "fft.h"

uint16_t i = 0, j = 0;
float temp;
uint16_t ADC_Value[768];
uint32_t ADC_IN9_Value;//ADת�����
uint16_t ADC_IN10_Value[256];//ADת�����
int32_t ADC_TEMP_Value;//ADת�����
float MCU_TEMP;//оƬ�¶�
uint16_t ADC_IN10_Value[256];//ADת�����
float32_t ADC_IN10_voltage[256];
float32_t cycle;//�����źŵ�����
//������
float32_t windows_Outputbuf[FFT_Len];

void windows(uint8_t enable)
{
    for (uint16_t i = 0; i < FFT_Len; ++i)
    {
        if (enable)
        {
            windows_Outputbuf[i] = 0.539 + 0.46 * arm_sin_f32(2 * PI * i / FFT_Len + 1.5 * PI);
        } else
        {
            windows_Outputbuf[i] = 1;//���δ�
        }
    }
}

void ADC_FUNCTION()
{
    for (i = 0, j = 0, ADC_IN9_Value = 0, ADC_TEMP_Value = 0; i < 768; j++)
    {
        ADC_IN9_Value += ADC_Value[i++];//ͨ��1��adֵ
        ADC_IN10_Value[j] = ADC_Value[i] *windows_Outputbuf[j];//ͨ��10��adֵ
        ADC_IN10_voltage[j] = ADC_Value[i] * 3.3f / 4096.0f;
        i++;
        ADC_TEMP_Value += ADC_Value[i++];//�ڲ��¶ȴ�������adֵ
    }
    ADC_TEMP_Value = ADC_TEMP_Value / 256;//��ֵ�˲�
    ADC_IN9_Value = ADC_IN9_Value / 256;
    temp = V25 - ADC_TEMP_Value * 3.3 / 4095;
    MCU_TEMP = temp / Avg_Slope + 25;


}


void cyc()//�ź����ڵļ���
{
    //��д��

}