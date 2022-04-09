//
// Created by lucas on 2022/4/1.
//

#include "main.h"
#include "arm_math.h"
#include "fft.h"

extern __IO uint16_t DAC_Outputbuf[FFT_Len];

void DSP_Sine(void);

void DSP_multSine(void);
