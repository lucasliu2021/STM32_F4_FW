#include "adc_function.h"
uint8_t i=0;float temp;
uint16_t ADC_Value[100];
uint16_t ADC_IN9_Value;//ADת�����
int16_t ADC_TEMP_Value;//ADת�����
float MCU_TEMP;//оƬ�¶�
void ADC_FUNCTION()
{
		
	for(i=0,ADC_IN9_Value=0,ADC_TEMP_Value=0;i<20;)
		{
            ADC_IN9_Value+=ADC_Value[i++];//ͨ��1��adֵ
			ADC_TEMP_Value+=ADC_Value[i++];//�ڲ��¶ȴ�������adֵ
		}
		ADC_TEMP_Value=ADC_TEMP_Value/10;//��ֵ�˲�
		ADC_IN9_Value=ADC_IN9_Value/10;
		temp=V25-ADC_TEMP_Value*3.3/4095;
		MCU_TEMP=temp/Avg_Slope+25;
}
