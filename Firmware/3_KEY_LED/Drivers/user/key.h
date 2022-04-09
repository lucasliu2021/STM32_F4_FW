#include "main.h"
/*下面的方式是通过直接操作库函数方式读取IO*/
//#define KEY2 		GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4) //PE4
#define KEY1 HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin)	//PE3 
#define KEY0 HAL_GPIO_ReadPin(KEY0_GPIO_Port,KEY0_Pin) //PE2
#define WK_UP HAL_GPIO_ReadPin(WK_UP_GPIO_Port,WK_UP_Pin)	//PA0
#define KEY0_PRES 1
#define KEY1_PRES	2
//#define KEY2_PRES	3
#define WKUP_PRES 4
uint8_t KEY_Scan(uint8_t mode);  		//按键扫描函数	

