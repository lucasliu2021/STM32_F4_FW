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
#include "buzzer.h"
#include "bar_timer.h"
#include "screen_light.h"
#include "Bluetooth_communication.h"
#include "dac_function.h"
//####3
#include "about.h"
#include "signal_generation.h"
#include "oscilloscope.h"
#include "stopwatch.h"
#include "gallery.h"
#include "uart.h"
#include "retarget.h"//针对clion的printf重定向
#include "setting.h"
#include "w25qxx.h"
#include "wareroom.h"
#include "W25Q16.h"

//####全局变量
__IO extern uint16_t LCD_BLK;
__IO extern uint16_t pulse;
__IO extern uint8_t task;
__IO extern uint8_t clear;
__IO extern uint8_t back;
__IO extern uint8_t enter;
__IO extern uint8_t signal_mode;//信号发生器模式

//####函数声明
void first_init();
