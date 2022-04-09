//
// Created by lucas on 2022/4/8.
//

//####1
#include "main.h"
#include "adc.h"
#include "dac.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
//####2
#include "delay.h"
#include "GUI.h"
#include "Lcd_Driver.h"
#include "adc_function.h"
#include "ntc.h"
#include "temperature.h"
#include "key.h"
#include "main_task.h"
#include "../BUZZER/buzzer.h"
#include "bar_timer.h"
#include "screen_light.h"
#include "bth_game.h"
#include "dac_function.h"
//####3
#include "about.h"
#include "signal_generation.h"
#include "oscilloscope.h"
#include "stopwatch.h"
#include "gallery.h"
#include "uart.h"
#include "retarget.h"//针对clion的printf重定向

//####全局变量
extern __IO uint16_t LCD_BLK;
extern __IO uint16_t pulse;
extern __IO uint8_t task;
extern __IO uint8_t clear;
extern __IO uint8_t back;
extern __IO uint8_t enter;
//####函数声明
void first_init();
