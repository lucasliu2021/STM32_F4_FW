//
// Created by lucas on 2022/4/8.
//

#include "first_init.h"

void first_init()
{
    //初始化液晶屏以及延时函数
    delay_init(168);
    Lcd_Init();
    Lcd_Clear(BLACK);
    //函数数组生成
    DSP_multSine();
    //启动定时器
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
    HAL_TIM_Base_Start_IT(&htim3);
    HAL_TIM_Base_Start(&htim6);
    HAL_TIM_PWM_Start(&htim9, TIM_CHANNEL_1);
    //三角波
    HAL_DAC_Start(&hdac, DAC_CHANNEL_1);
    //正弦波
    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_2, (uint32_t *) DAC_Outputbuf, FFT_Len, DAC_ALIGN_12B_R);
    //启动ADC&&DAC
    HAL_ADC_Start_DMA(&hadc1, (uint32_t *) &ADC_Value, 768);
    //绘制静态数据
    Gui_DrawFont_GBK16(0, 0, WHITE, BLACK, "FW-FFT-SIG");
    Gui_DrawFont_GBK16(0, 20, YELLOW, BLACK, "MCU_TEMP:");
    Gui_DrawFont_GBK16(0, 36, YELLOW, BLACK, "NTC_TEMP:");
    Gui_DrawFont_GBK16(100, 36, YELLOW, BLACK, "℃");
    Gui_DrawFont_GBK16(100, 20, YELLOW, BLACK, "℃");
    //启动串口
    RetargetInit(&huart1);//针对clion的printf重定向
    HAL_UART_Receive_IT(&huart1, (uint8_t *) uart1_rx_buf, 5);
    printf("LCD_BLK_SET:0--10!\r\n");//魔法棒里的Target选项卡里一定要勾选Use MicroLIB

}
