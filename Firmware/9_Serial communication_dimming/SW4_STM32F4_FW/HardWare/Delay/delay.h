#ifndef __DELAY_H
#define __DELAY_H 			   
#include <main.h>	  
//////////////////////////////////////////////////////////////////////////////////  
//
//********************************************************************************
//修改说明
//无
////////////////////////////////////////////////////////////////////////////////// 	 
void delay_init(uint8_t SYSCLK);
void delay_ms(uint16_t nms);
void delay_us(uint32_t nus);
void DelayUs(uint32_t count);
void DelayMs(uint32_t  Timer);
#endif





























