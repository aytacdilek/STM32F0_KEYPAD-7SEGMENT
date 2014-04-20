#ifndef __STM32F0XX_7SEGMENT_H__
#define __STM32F0XX_7SEGMENT_H__

#include "stm32f0xx.h"
#include "stm32f0xx_gpio.h"
#include "stm32f0xx_rcc.h"

#define SEGMENT_PORT	GPIOA
#define SEGMENT_RCC		RCC_AHBENR_GPIOAEN
#define SEGMENT_PIN_0	GPIO_Pin_0
#define SEGMENT_PIN_1	GPIO_Pin_1
#define SEGMENT_PIN_2	GPIO_Pin_2
#define SEGMENT_PIN_3	GPIO_Pin_3
#define SEGMENT_PIN_4	GPIO_Pin_4
#define SEGMENT_PIN_5	GPIO_Pin_5
#define SEGMENT_PIN_6	GPIO_Pin_6

GPIO_InitTypeDef GPIO_InitStructure;

void SevenSegment_Init(void);
void SevenSegment_WriteData(unsigned char data);

#endif 	//__STM32F0XX_7SEGMENT_H__
