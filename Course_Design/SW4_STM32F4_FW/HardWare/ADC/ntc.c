#include <math.h>
#include <ntc.h>

int NTC_TEMP;
float Rt = 0;
//Rp上拉电阻值
float Rp = 10000;
//T2为25摄氏度，折算为开尔文温度
float T2 = 273.15 + 25;
float Bx = 3500;
float Ka = 273.15;
float vol = 0;

//电压换算成温度
void TEMP_DATA(void)
{
    vol = (float) (ADC_IN9_Value * 3.3 / 4095);
    Rt = vol * 10000 / (3.3f - vol);
    NTC_TEMP = (int) (1 / (1 / T2 + log(Rt / Rp) / Bx) - Ka);
}
