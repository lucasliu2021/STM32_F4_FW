///stm32f401�ڲ��¶ȴ�����
#include <main.h>


#define V25 0.76
#define Avg_Slope 0.0025
// #define Avg_Slope 0.025
extern uint16_t ADC_Value[100];
extern uint16_t ADC_IN9_Value;//ADת�����
extern int16_t ADC_TEMP_Value;//ADת�����
extern float MCU_TEMP;//оƬ�¶�

void ADC_FUNCTION(void);
