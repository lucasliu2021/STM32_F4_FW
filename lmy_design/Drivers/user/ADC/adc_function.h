#include "main.h"
#include "arm_math.h"

#define V25 0.76
#define Avg_Slope 0.0025
// #define Avg_Slope 0.025
extern uint16_t ADC_Value[768];
extern uint32_t ADC_IN9_Value;//ADת�����
extern uint16_t ADC_IN10_Value[256];//ADת�����
extern int32_t ADC_TEMP_Value;//ADת�����
extern float MCU_TEMP;//оƬ�¶�
extern float32_t ADC_IN10_voltage[256];//ADת�����
extern float32_t cycle;
void ADC_FUNCTION(void);
void cyc();//����д�����ڼ���
void windows(uint8_t enable);
