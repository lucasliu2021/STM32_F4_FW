/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dac.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "delay.h"
#include "GUI.h"
#include "Lcd_Driver.h"
#include "adc_function.h"
#include "ntc.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
volatile uint16_t pluse = 0;
__IO uint8_t uart1_rx_buf[5];
__IO uint8_t Rx_Flag;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private HardWare code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
    /* USER CODE BEGIN 1 */

    /* USER CODE END 1 */

    /* MCU Configuration--------------------------------------------------------*/

    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();

    /* USER CODE BEGIN Init */

    /* USER CODE END Init */

    /* Configure the system clock */
    SystemClock_Config();

    /* USER CODE BEGIN SysInit */

    /* USER CODE END SysInit */

    /* Initialize all configured peripherals */
    MX_GPIO_Init();
    MX_DMA_Init();
    MX_ADC1_Init();
    MX_DAC_Init();
    MX_TIM6_Init();
    MX_TIM3_Init();
    MX_USART1_UART_Init();
    /* USER CODE BEGIN 2 */
    //初始化液晶屏以及延时函数
    delay_init(168);
    Lcd_Init();
    LCD_BLK_SET;//开启背光
    Lcd_Clear(BLACK);
    //启动定时器
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
    HAL_TIM_Base_Start_IT(&htim3);
    HAL_TIM_Base_Start(&htim6);
    //启动ADC&&DAC
    HAL_DAC_Start(&hdac, DAC_CHANNEL_1);
    HAL_ADC_Start_DMA(&hadc1, (uint32_t *) &ADC_Value, 384);
    //绘制静态数据
    Gui_DrawFont_GBK16(0, 0, YELLOW, BLACK, "LLHAO-FW1");
    Gui_DrawFont_GBK16(0, 20, YELLOW, BLACK, "MCU_TEMP:");
    Gui_DrawFont_GBK16(100, 20, YELLOW, BLACK, "℃");
    Gui_DrawFont_GBK16(0, 36, YELLOW, BLACK, "NTC_TEMP:");
    Gui_DrawFont_GBK16(100, 36, YELLOW, BLACK, "℃");
    Gui_DrawFont_GBK16(0, 66, YELLOW, BLACK, "WAVE");
    //启动串口
    HAL_UART_Receive_IT(&huart1, (uint8_t *) uart1_rx_buf, 5);
    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    while (1)
    {
        /* USER CODE END WHILE */

        /* USER CODE BEGIN 3 */
        delay_ms(8);
        //Lcd_custer_Clear(128, 160, 0, 50, BLACK);
        HAL_ADC_Stop_DMA(&hadc1);
        //采样&&发生
        ADC_FUNCTION();
        TEMP_DATA();
        //温度显示
        LCD_ShowNum(77, 20, MCU_TEMP, 2);//芯片温度
        LCD_ShowNum(77, 36, NTC_TEMP, 2);//NTC温度
        //绘制波形&&局部清屏
        LCD_DrawWave(ADC_IN10_Value, 1, 159, 55, YELLOW);
        //DMA校正
        HAL_ADC_Start_DMA(&hadc1, (uint32_t *) &ADC_Value, 384);

        //串口数据测试
        if (Rx_Flag == 1)
        {
            HAL_UART_Transmit_IT(&huart1, (uint8_t *) uart1_rx_buf, 5);
            Rx_Flag = 0;
            HAL_UART_Receive_IT(&huart1, (uint8_t *) uart1_rx_buf, 5);
        }
    }
    /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /** Configure the main internal regulator output voltage
    */
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
    /** Initializes the RCC Oscillators according to the specified parameters
    * in the RCC_OscInitTypeDef structure.
    */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 8;
    RCC_OscInitStruct.PLL.PLLN = 336;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = 4;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }
    /** Initializes the CPU, AHB and APB buses clocks
    */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                  | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
    {
        Error_Handler();
    }
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM3)
    {
        if (pluse < 1000)
        {
            pluse++;
        } else
        {
            pluse = 0;
            HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);//清零提示
        }

        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, pluse);

    }

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    Rx_Flag = 1;
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1)
    {
    }
    /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
