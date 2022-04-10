//
// Created by lucas on 2022/4/8.
//
#include "stdio.h"
#include "usart.h"
#define uart1_rx_buf_length 1
extern __IO uint8_t uart1_rx_buf[uart1_rx_buf_length]; //__IO  volatile  串口1接收缓冲区，长度一个字节
extern __IO uint8_t Uart1_Rx_Flag;

