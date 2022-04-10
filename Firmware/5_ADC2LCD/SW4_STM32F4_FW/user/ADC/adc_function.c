#include "adc_function.h"
uint8_t i=0;float temp;
uint16_t ADC_Value[100];
uint16_t ADC_IN9_Value;//AD转换结果
int16_t ADC_TEMP_Value;//AD转换结果
float MCU_TEMP;//芯片温度
void ADC_FUNCTION()
{
		
	for(i=0,ADC_IN9_Value=0,ADC_TEMP_Value=0;i<20;)
		{
            ADC_IN9_Value+=ADC_Value[i++];//通道1的ad值
			ADC_TEMP_Value+=ADC_Value[i++];//内部温度传感器的ad值
		}
		ADC_TEMP_Value=ADC_TEMP_Value/10;//均值滤波
		ADC_IN9_Value=ADC_IN9_Value/10;
		temp=V25-ADC_TEMP_Value*3.3/4095;
		MCU_TEMP=temp/Avg_Slope+25;
}
