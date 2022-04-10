/* USER CODE BEGIN Header */

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
#include "first_init.h"
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
volatile uint16_t pulse = 0;
__IO uint16_t LCD_BLK = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */


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
    MX_TIM9_Init();
    /* USER CODE BEGIN 2 */
    first_init();//独立出来了
    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    while (1)
    {
        /* USER CODE END WHILE */

        /* USER CODE BEGIN 3 */
        delay_ms(2);
        HAL_ADC_Stop_DMA(&hadc1);
        //采样&&发生
        ADC_FUNCTION();
        TEMP_DATA();
        //温度显示
        LCD_ShowNum(70, 20, MCU_TEMP, 3);//芯片温度
        LCD_ShowNum(70, 36, NTC_TEMP, 3);//NTC温度
        //绘制波形&&局部清屏
        LCD_DrawWave(ADC_IN10_Value, FFT_Len, 1, 159, 55, YELLOW);

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

        //快速傅里叶变换
        FFT_Function(ADC_IN10_voltage);
        LCD_DrawFFTWave(FFT_MAG_Outputdata, 1, 159, 100, Half_FFT_Len, BLUE);

        //DMA校正
        HAL_ADC_Start_DMA(&hadc1, (uint32_t *) &ADC_Value, 768);
    }
    /* USER CODE END 3 */
}


void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};


    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

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
        if (pulse < 1000)
        {
            pulse++;
        } else
        {
            pulse = 0;
        }

        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, pulse);

    }

}

/* USER CODE END 4 */


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

