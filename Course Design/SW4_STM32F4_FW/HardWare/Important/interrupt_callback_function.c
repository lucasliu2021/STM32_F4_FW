//
// Created by lucas on 2022/4/8.
//

#include "interrupt_callback_function.h"

__IO uint8_t task = 0;
__IO uint8_t clear = 0;
__IO uint8_t back = 0;
__IO uint8_t enter = 0;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
/*    ��ʼ�����ư���
     * ������ʾ��
     * ��������
    �ڼ�⵽�����ͷź�����ʱ10ms���������ض�����Ȼ���ٶԼ�ֵ���д���
    ������Ϊ����ȷ���������������־λ֮ǰ�ӳٵȴ�������ʧ��
     ��ֹ�򶶶��ڴ˽��жϱ�־λ��Ϊ��Ч��
     ����Ҫ�޸�HAL�⣨Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.c���еġ�HAL_GPIO_EXTI_IRQHandler��������
     �ڡ�__HAL_GPIO_EXTI_CLEAR_IT(GPIO_Pin);��֮ǰ����ӳ�*/

    //ÿ�ΰ�������ʼ������״̬
    back = 0;
    enter = 0;
    buzzer();
    switch (GPIO_Pin)
    {
        //���ð������ڵ�һ���ӿ촦���ٶ�
        case GPIO_PIN_2://�л�
            if (screen != 1)
            {
                task++;
            }
            if (screen == 1)
            {
                if (light_mode < 3)
                {
                    light_mode++;
                } else
                {
                    light_mode = 0;
                }
            }
            clear = 1;
            break;
        case GPIO_PIN_0://�Ƴ�
            back = 1;
            clear = 1;
            break;
        case GPIO_PIN_3://����
            enter = 1;
            clear = 1;
            break;
        default:
            break;
    }
}

__IO uint16_t pulse = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM3)
    {
        if (pulse < 1000)
        {
            pulse++;

        } else
        {
            pulse = 0;
            HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);//������ʾ
            //���
            if (watch == 1)//�����ж�
            {
                if (seconds < 60)
                {
                    seconds++;
                } else
                {
                    seconds = 0;
                    minutes++;
                }
            }
        }
        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, pulse);
    }
}
