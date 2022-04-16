////
//// Created by lucas on 2022/4/1.
////
//
#include "dac_function.h"

uint16_t DAC_Outputbuf[FFT_Len];
void DSP_Sine(void)
{
    uint16_t i;

    for (i = 0; i < FFT_Len; i++)
    {
        DAC_Outputbuf[i] = 2047 * (1 + cosf(2 * PI * i / FFT_Len));
    }
}

void DSP_multSine(void)
{
    uint16_t i;

    for (i = 0; i < FFT_Len; i++)
    {
        DAC_Outputbuf[i] =
                2047 * (0.5 + 0.2*cosf(2 * PI*0.1 * i / FFT_Len) + 0.4*cosf(2 * PI *0.3* i / FFT_Len) + 0.6*cosf(2 * PI*0.5 * i / FFT_Len)+0.3*cosf(2 * PI*0.7 * i / FFT_Len));

    }
}

