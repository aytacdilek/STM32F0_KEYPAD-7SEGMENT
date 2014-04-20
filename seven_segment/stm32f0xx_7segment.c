#include "stm32f0xx_7segment.h"

const unsigned char digit[16]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7C, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

void SevenSegment_Init(void)
{
	//Enable Port clock
	RCC_AHBPeriphClockCmd(SEGMENT_RCC, ENABLE);
	//Initiliaze seven segmnet data pins
	GPIO_InitStructure.GPIO_Pin = SEGMENT_PIN_0 | SEGMENT_PIN_1 | SEGMENT_PIN_2 | SEGMENT_PIN_3 | SEGMENT_PIN_4 | SEGMENT_PIN_5 | SEGMENT_PIN_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_1;
	GPIO_Init(SEGMENT_PORT, &GPIO_InitStructure);

	GPIO_Write(SEGMENT_PORT, GPIO_ReadOutputData(SEGMENT_PORT) & 0xFF80);
}

void SevenSegment_WriteData(unsigned char data)
{
	GPIO_Write(SEGMENT_PORT, (uint16_t) digit[data]);
}
