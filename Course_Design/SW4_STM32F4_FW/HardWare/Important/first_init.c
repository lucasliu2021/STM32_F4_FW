//
// Created by lucas on 2022/4/8.
//

#include "first_init.h"

__IO uint16_t LCD_BLK;

void first_init()
{
    //启动液晶屏
    delay_init(168);
    Lcd_Init();
    Lcd_Clear(BLACK);
    //函数数组生成
    windows(1);//加窗并生成窗函数
    //DSP_multSine();
    DSP_Sine();//正弦波数组
    //启动定时器
    HAL_TIM_Base_Start(&htim6);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
    HAL_TIM_Base_Start_IT(&htim3);
    HAL_TIM_PWM_Start(&htim9, TIM_CHANNEL_1);
    HAL_TIM_Base_Start_IT(&htim9);
    //启动ADC&&DAC
    //正弦波
    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_2, (uint32_t *) DAC_Outputbuf, FFT_Len, DAC_ALIGN_12B_R);
    //三角波
    HAL_DAC_Start(&hdac, DAC_CHANNEL_1);//默认定时器启动
    HAL_ADC_Start_DMA(&hadc1, (uint32_t *) &ADC_Value, 768);
    //初始化屏幕亮度
    LCD_BLK = 99;
    light_mode = 0;
    select_within_screen = 0;
    select_within_signal = 0;
    buzzer_swtich = 1;//默认开启蜂鸣器
    //启动串口
    RetargetInit(&huart1);//针对clion的printf重定向
    printf("already powered on\r\n");//魔法棒里的Target选项卡里一定要勾选Use MicroLIB
    HAL_UART_Receive_IT(&huart1, (uint8_t *) uart1_rx_buf, 1);//开启串口接收中断允许 不开启就只能接收一次
}
