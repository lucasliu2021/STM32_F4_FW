#include <main.h>


#define V25 0.76
#define Avg_Slope 0.0025
// #define Avg_Slope 0.025
extern uint16_t ADC_Value[384];
extern uint32_t ADC_IN9_Value;//ADת�����
extern uint16_t ADC_IN10_Value[128];//ADת�����
extern int32_t ADC_TEMP_Value;//ADת�����
extern float MCU_TEMP;//оƬ�¶�

void ADC_FUNCTION(void);
