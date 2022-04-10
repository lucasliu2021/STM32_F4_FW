#include "adc_function.h"

uint16_t i = 0, j = 0;
float temp;
uint16_t ADC_Value[768];
uint32_t ADC_IN9_Value;//AD转换结果
uint16_t ADC_IN10_Value[256];//AD转换结果
int32_t ADC_TEMP_Value;//AD转换结果
float MCU_TEMP;//芯片温度
uint16_t ADC_IN10_Value[256];//AD转换结果
float32_t ADC_IN10_voltage[256];
float32_t cycle;//计算信号的周期
void ADC_FUNCTION()
{
    for (i = 0, j = 0, ADC_IN9_Value = 0, ADC_TEMP_Value = 0; i < 768; j++)
    {
        ADC_IN9_Value += ADC_Value[i++];//通道1的ad值
        ADC_IN10_voltage[j] = ADC_Value[i] * 3.3f / 4096.0f;
        ADC_IN10_Value[j] = ADC_Value[i++];//通道10的ad值
        ADC_TEMP_Value += ADC_Value[i++];//内部温度传感器的ad值
    }
    ADC_TEMP_Value = ADC_TEMP_Value / 256;//均值滤波
    ADC_IN9_Value = ADC_IN9_Value / 256;
    temp = V25 - ADC_TEMP_Value * 3.3 / 4095;
    MCU_TEMP = temp / Avg_Slope + 25;


}

void cyc()//信号周期的计算
{
    //不写了

}