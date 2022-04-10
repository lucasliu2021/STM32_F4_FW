//
// Created by lucas on 2022/4/8.
//

//scanf 后面加空格   printf要在魔法棒里面勾选 use microlib
#include "uart.h"
#include "first_init.h"

int fputc(int ch, FILE *f)//printf
{
    HAL_UART_Transmit(&huart1, (uint8_t *) &ch, 1, HAL_MAX_DELAY);
    return ch;
}

int fgetc(FILE *f)//scanf
{
    int ch;
    HAL_UART_Receive(&huart1, (uint8_t *) &ch, 1, HAL_MAX_DELAY);
    return ch;
}

//以下是串口中断回调函数
__IO uint8_t uart1_rx_buf[1]; //__IO  volatile  串口1接收缓冲区，长度一个字节
__IO uint8_t Uart1_Rx_Flag = 0;//串口1接收完成标志

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)//串口接收完成中断回调函数
{
    if (huart->Instance == USART1)//判断是不是串口1引起的串口接收中断（所有串口的接收中断都进这个回调函数。因此要判断一下是哪个串口引发的，中断回调函数中的内容一定要简洁，以避免阻塞）
    {
        Uart1_Rx_Flag = 1;
    }
}
