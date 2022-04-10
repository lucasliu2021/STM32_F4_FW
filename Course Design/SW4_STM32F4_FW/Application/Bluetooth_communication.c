//
// Created by lucas on 2022/3/26.
//
#include "Bluetooth_communication.h"
#include "first_init.h"

void Bluetooth_communication()
{

    //串口通信
    if (Uart1_Rx_Flag == 1)
    {
        Uart1_Rx_Flag = 0;
        if (uart1_rx_buf[0] >= 0 && uart1_rx_buf[0] <= 10)//是数组，第0位  十进制的数(0-255):0一个字节/10两个字节
        {
            LCD_BLK = uart1_rx_buf[0] * 10;
            __HAL_TIM_SET_COMPARE(&htim9, TIM_CHANNEL_1, LCD_BLK);
            printf("LCD_BLK_SET!\r\n");//调用scanf函数读取串口数据时，需要以空格作为输入的结束
        } else
            printf("LCD_BLK_SET_ERROR!\r\n");
        HAL_UART_Receive_IT(&huart1, (uint8_t *) uart1_rx_buf, 1);//开启串口接收中断允许 不开启就只能接收一次
    }

    if (HAL_GPIO_ReadPin(STA_GPIO_Port, STA_Pin) == 1)
    {
        Gui_DrawFont_GBK16(0, 60, RED, BLACK, "Please connect");
        Gui_DrawFont_GBK16(0, 80, RED, BLACK, "bluetooth module");
    } else
    {
        //串口数据测试
        if (Uart1_Rx_Flag == 1)
        {
            //显示
            Gui_DrawFont_GBK16(0, 80, RED, BLACK, "Please connect");
            Uart1_Rx_Flag = 0;
            HAL_UART_Receive_IT(&huart1, (uint8_t *) uart1_rx_buf, 5);
        }

    }

}

