//
// Created by lucas on 2022/4/8.
//

#include "first_init.h"

__IO uint16_t LCD_BLK;

void first_init()
{
    //����Һ����
    delay_init(168);
    Lcd_Init();
    Lcd_Clear(BLACK);
    //������������
    windows(1);//�Ӵ������ɴ�����
    //DSP_multSine();
    DSP_Sine();//���Ҳ�����
    //������ʱ��
    HAL_TIM_Base_Start(&htim6);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
    HAL_TIM_Base_Start_IT(&htim3);
    HAL_TIM_PWM_Start(&htim9, TIM_CHANNEL_1);
    HAL_TIM_Base_Start_IT(&htim9);
    //����ADC&&DAC
    //���Ҳ�
    HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_2, (uint32_t *) DAC_Outputbuf, FFT_Len, DAC_ALIGN_12B_R);
    //���ǲ�
    HAL_DAC_Start(&hdac, DAC_CHANNEL_1);//Ĭ�϶�ʱ������
    HAL_ADC_Start_DMA(&hadc1, (uint32_t *) &ADC_Value, 768);
    //��ʼ����Ļ����
    LCD_BLK = 99;
    light_mode = 0;
    select_within_screen = 0;
    select_within_signal = 0;
    buzzer_swtich = 1;//Ĭ�Ͽ���������
    //��������
    RetargetInit(&huart1);//���clion��printf�ض���
    printf("already powered on\r\n");//ħ�������Targetѡ���һ��Ҫ��ѡUse MicroLIB
    HAL_UART_Receive_IT(&huart1, (uint8_t *) uart1_rx_buf, 1);//�������ڽ����ж����� ��������ֻ�ܽ���һ��
}
