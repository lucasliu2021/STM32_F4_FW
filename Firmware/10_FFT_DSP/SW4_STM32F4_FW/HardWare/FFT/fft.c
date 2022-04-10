//https://blog.csdn.net/hduxiejun/article/details/46287341?spm=1001.2101.3001.6650.2&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7EHighlightScore-2.queryctrv2&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7EHighlightScore-2.queryctrv2&utm_relevant_index=5
#include "fft.h"
#include "arm_math.h"
#include "adc_function.h"

float32_t FFT_Outputdata[FFT_Len];  //FFT结果输出
float32_t FFT_Inputbuf[FFT_Len];//FFT数据输入
float32_t FFT_MAG_Outputdata[Half_FFT_Len];//计算复数的模
void FFT_Function(void)
{
    uint16_t i;

    arm_rfft_fast_instance_f32 S;
    arm_rfft_fast_init_f32(&S, FFT_Len);

    for (i = 0; i < FFT_Len; i++)
    {
        FFT_Inputbuf[i] = 1 + cos(2 * 3.1415926f * 50 * i / FFT_Len);
//        FFT_Inputbuf[i] = 0.1 + 0.5 * arm_cos_f32(2 * 3.1415926f * 50 / FFT_Len + 3.1415926f / 3) + 0.2 * cos(2 * 3.1415926f * 20 * i / FFT_Len + 3.1415926f / 6) + 0.1 * cos(2 * 3.1415926f * 5 * i / FFT_Len + 3.1415926f / 6);
//        FFT_Inputbuf[i] = (float) (ADC_IN10_Value[i] / 4095.0);
    }
    arm_rfft_fast_f32(&S, FFT_Inputbuf, FFT_Outputdata, 0);
    arm_cmplx_mag_f32(FFT_Outputdata, FFT_MAG_Outputdata, FFT_Len);
}