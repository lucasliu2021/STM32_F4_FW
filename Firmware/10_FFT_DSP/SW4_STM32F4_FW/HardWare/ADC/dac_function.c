////
//// Created by lucas on 2022/4/1.
////
//
//#include "adc_function.h"
//#include "arm_math.h"
//float siny[256];
//uint16_t sinx[256];
//void DSP_multSine(void)
//{
//
//    uint16_t i;
//
//    for(i=0;i<256;i++)
//    {
//        siny[i]=arm_sin_f32(i*PI/128);
//
//        sinx[i]=(uint16_t)(2048+2048*(arm_sin_f32(i*PI/128)/2+arm_sin_f32));//¿´²»¼û
//    }
//}
//void DSP_Sine(void)
//{
//    uint16_t i;
//    for(i=0;i<256;i++)
//    {
//        siny[i]=arm_sin_f32	(i*PI/128);
//        siny[i]=(uint16_t)(2048+2048*i*arm_sin_f32(i*PI/128));
//    }
//}
