///stm32f401内部温度传感器
#include <main.h>


#define V25 0.76
#define Avg_Slope 0.0025
// #define Avg_Slope 0.025
extern uint16_t ADC_Value[100];
extern uint16_t ADC_IN9_Value;//AD转换结果
extern int16_t ADC_TEMP_Value;//AD转换结果
extern float MCU_TEMP;//芯片温度

void ADC_FUNCTION(void);
