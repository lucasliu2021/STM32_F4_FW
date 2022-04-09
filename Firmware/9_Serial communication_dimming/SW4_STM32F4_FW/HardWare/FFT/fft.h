#include <main.h>
#include <adc_function.h>
#include "arm_math.h"
#include "arm_const_structs.h"

#define FFT_Len 256//16/64/256/1024/4096¿ÉÑ¡
#define Half_FFT_Len FFT_Len/2

extern float32_t FFT_Outputdata[FFT_Len];
extern float32_t FFT_MAG_Outputdata[Half_FFT_Len];

void FFT_Function(float32_t FFT_Inputbuf[]);

