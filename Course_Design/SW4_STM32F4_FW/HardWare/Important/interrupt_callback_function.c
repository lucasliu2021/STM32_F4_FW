//
// Created by lucas on 2022/4/8.
//

#include "interrupt_callback_function.h"
#include "delay.h"
__IO uint8_t task = 0;
__IO uint8_t clear = 0;
__IO uint8_t back = 0;
__IO uint8_t enter = 0;

void HAL_GPIO_EXTI_IRQHandler(uint16_t GPIO_Pin)
{
    /* EXTI line interrupt detected */
    if(__HAL_GPIO_EXTI_GET_IT(GPIO_Pin) != RESET)
    {
        delay_ms(20);
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_Pin);
        HAL_GPIO_EXTI_Callback(GPIO_Pin);
    }
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
/*    初始化控制按键
     * 按键提示音
     * 按键消抖
    在检测到按键释放后，再延时10ms，消除后沿抖动，然后再对键值进行处理。
    个人认为更正确的做法是在清除标志位之前延迟等待抖动消失，
     防止因抖动在此将中断标志位置为有效。
     即需要修改HAL库（Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.c）中的“HAL_GPIO_EXTI_IRQHandler”函数。
     在“__HAL_GPIO_EXTI_CLEAR_IT(GPIO_Pin);”之前和之后添加延迟，有效防止前后抖*/

    //每次按键后会初始化按键状态
    back = 0;
    enter = 0;
    buzzer();
    switch (GPIO_Pin)
    {
        //常用按键放在第一，加快处理速度
        case GPIO_PIN_2://切换
            if (select_within_screen != 1 && select_within_signal != 1 && select_within_setting != 1)
            {
                task++;
            }
            if (select_within_screen == 1)//应用内选择
            {
                enter = 1;//保持进入
                if (light_mode < 3)//屏幕亮度
                {
                    light_mode++;
                } else
                {
                    light_mode = 0;
                }
            } else if (select_within_signal == 1)//应用内选择
            {
                enter = 1;//保持进入
                if (signal_mode < 3)//信号发生器选择
                {
                    signal_mode++;
                    Signal_mode_selection = 1;
                } else
                {
                    signal_mode = 0;
                }
            } else if (select_within_setting == 1)//应用内选择
            {
                enter = 1;//保持进入
                if (setting_mode < 1)//信号发生器选择
                {
                    setting_mode++;
                } else
                {
                    setting_mode = 0;
                }
            }
            clear = 1;
            break;
        case GPIO_PIN_0://推出
            back = 1;
            clear = 1;
            break;
        case GPIO_PIN_3://进入
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
            //秒表
            if (watch == 1)//开启判断
            {
                if (seconds < 60)
                {
                    seconds++;
                    HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);//清零提示
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

