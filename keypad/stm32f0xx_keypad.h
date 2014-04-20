#ifndef __STM32F0XX_KEYPAD_H__
#define __STM32F0XX_KEYPAD_H__

#include "stm32f0xx.h"
#include "stm32f0xx_gpio.h"
#include "stm32f0xx_rcc.h"

#define KEYPAD_PORT		GPIOB
#define KEYPAD_RCC		RCC_AHBENR_GPIOBEN
#define COLOUMN1		GPIO_Pin_0
#define COLOUMN2		GPIO_Pin_1
#define COLOUMN3		GPIO_Pin_2
#define ROW1			GPIO_Pin_3
#define ROW2			GPIO_Pin_4
#define ROW3			GPIO_Pin_5
#define ROW4			GPIO_Pin_6

GPIO_InitTypeDef GPIO_InitStructure;
unsigned char keyStroke;

void Keypad_Init(void);
unsigned char Keypad_Scan(void);
void Keypad_Delay(uint32_t msecond);

#endif	//__STM32F0XX_KEYPAD_H__
