//
// Created by lucas on 2022/3/25.
//

#include "buzzer.h"
#include "main.h"
#include "delay.h"

uint8_t buzzer_swtich;

void buzzer()
{
    if (buzzer_swtich == 1)
    {
        for (uint8_t i = 0; i < 100; ++i)
        {
            HAL_GPIO_TogglePin(BUZZER_GPIO_Port, BUZZER_Pin);
            delay_us(50);//
        }
    }
}