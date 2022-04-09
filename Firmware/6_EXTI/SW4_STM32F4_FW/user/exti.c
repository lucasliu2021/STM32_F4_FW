//
// Created by lucas on 2022/3/15.
//
#include "delay.h"
#include "exti.h"

/*
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == WK_UP_Pin)
    {
        DelayMs(10);
        if (GPIO_Pin == WK_UP_Pin)
            HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
            HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
    }
    if (GPIO_Pin == KEY0_Pin)
    {
        DelayMs(10);
        if (GPIO_Pin == KEY0_Pin)
            HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
    }
    if (GPIO_Pin == KEY1_Pin)
    {
        DelayMs(10);
        if (GPIO_Pin == KEY1_Pin)
            HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
    }
}
*/
/*

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    switch (GPIO_Pin)
    {
        case GPIO_PIN_0:
            HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
            break;
        case GPIO_PIN_2:
            speed++;
            if (speed == 3)
            {
                speed = 0;
            }
            break;
        case GPIO_PIN_3:
            HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
            break;
        default:
            break;
    }
}
*/
