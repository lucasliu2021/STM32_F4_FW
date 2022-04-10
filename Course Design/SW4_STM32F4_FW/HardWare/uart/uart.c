//
// Created by lucas on 2022/4/8.
//

//scanf ����ӿո�   printfҪ��ħ�������湴ѡ use microlib
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

//�����Ǵ����жϻص�����
__IO uint8_t uart1_rx_buf[1]; //__IO  volatile  ����1���ջ�����������һ���ֽ�
__IO uint8_t Uart1_Rx_Flag = 0;//����1������ɱ�־

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)//���ڽ�������жϻص�����
{
    if (huart->Instance == USART1)//�ж��ǲ��Ǵ���1����Ĵ��ڽ����жϣ����д��ڵĽ����ж϶�������ص����������Ҫ�ж�һ�����ĸ����������ģ��жϻص������е�����һ��Ҫ��࣬�Ա���������
    {
        Uart1_Rx_Flag = 1;
    }
}
