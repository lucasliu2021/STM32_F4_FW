//
// Created by lucas on 2022/3/26.
//
#include "Bluetooth_communication.h"
#include "first_init.h"

void Bluetooth_communication()
{

    //����ͨ��
    if (Uart1_Rx_Flag == 1)
    {
        Uart1_Rx_Flag = 0;
        if (uart1_rx_buf[0] >= 0 && uart1_rx_buf[0] <= 10)//�����飬��0λ  ʮ���Ƶ���(0-255):0һ���ֽ�/10�����ֽ�
        {
            LCD_BLK = uart1_rx_buf[0] * 10;
            __HAL_TIM_SET_COMPARE(&htim9, TIM_CHANNEL_1, LCD_BLK);
            printf("LCD_BLK_SET!\r\n");//����scanf������ȡ��������ʱ����Ҫ�Կո���Ϊ����Ľ���
        } else
            printf("LCD_BLK_SET_ERROR!\r\n");
        HAL_UART_Receive_IT(&huart1, (uint8_t *) uart1_rx_buf, 1);//�������ڽ����ж����� ��������ֻ�ܽ���һ��
    }

    if (HAL_GPIO_ReadPin(STA_GPIO_Port, STA_Pin) == 1)
    {
        Gui_DrawFont_GBK16(0, 60, RED, BLACK, "Please connect");
        Gui_DrawFont_GBK16(0, 80, RED, BLACK, "bluetooth module");
    } else
    {
        //�������ݲ���
        if (Uart1_Rx_Flag == 1)
        {
            //��ʾ
            Gui_DrawFont_GBK16(0, 80, RED, BLACK, "Please connect");
            Uart1_Rx_Flag = 0;
            HAL_UART_Receive_IT(&huart1, (uint8_t *) uart1_rx_buf, 5);
        }

    }

}

