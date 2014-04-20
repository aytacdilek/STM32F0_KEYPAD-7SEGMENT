#include "stm32f0xx_keypad.h"

void Keypad_Init(void)
{
	//Enable Port clock
	RCC_AHBPeriphClockCmd(KEYPAD_RCC, ENABLE);
	//Set Coloumn control pins as output
	GPIO_InitStructure.GPIO_Pin = COLOUMN1 | COLOUMN2 | COLOUMN3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_1;
	GPIO_Init(KEYPAD_PORT, &GPIO_InitStructure);
	//Set Row control pins as input
	GPIO_InitStructure.GPIO_Pin = ROW1 | ROW2 | ROW3 | ROW4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_1;
	GPIO_Init(KEYPAD_PORT, &GPIO_InitStructure);
}

unsigned char Keypad_Scan(void)
{
	//Scan 1st coloumn
	GPIO_SetBits(KEYPAD_PORT, COLOUMN1);
	if(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW1))
	{
		Keypad_Delay(20);
		while(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW1));
		keyStroke = 0x01;
	}
	else if(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW2))
	{
		Keypad_Delay(20);
		while(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW2));
		keyStroke = 0x04;
	}
	else if(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW3))
	{
		Keypad_Delay(20);
		while(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW3));
		keyStroke = 0x07;
	}
	else if(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW4))
	{
		Keypad_Delay(20);
		while(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW4));
		keyStroke = 0x0A;
	}
	GPIO_ResetBits(KEYPAD_PORT, COLOUMN1);

	//Scan 2nd coloumn
	GPIO_SetBits(KEYPAD_PORT, COLOUMN2);
	if(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW1))
	{
		Keypad_Delay(20);
		while(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW1));
		keyStroke = 0x02;
	}
	else if(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW2))
	{
		Keypad_Delay(20);
		while(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW2));
		keyStroke = 0x05;
	}
	else if(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW3))
	{
		Keypad_Delay(20);
		while(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW3));
		keyStroke = 0x08;
	}
	else if(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW4))
	{
		Keypad_Delay(20);
		while(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW4));
		keyStroke = 0x00;
	}
	GPIO_ResetBits(KEYPAD_PORT, COLOUMN2);

	//Scan 3rd coloumn
	GPIO_SetBits(KEYPAD_PORT, COLOUMN3);
	if(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW1))
	{
		Keypad_Delay(20);
		while(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW1));
		keyStroke = 0x03;
	}
	else if(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW2))
	{
		Keypad_Delay(20);
		while(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW2));
		keyStroke = 0x06;
	}
	else if(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW3))
	{
		Keypad_Delay(20);
		while(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW3));
		keyStroke = 0x09;
	}
	else if(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW4))
	{
		Keypad_Delay(20);
		while(GPIO_ReadInputDataBit(KEYPAD_PORT, ROW4));
		keyStroke = 0x0B;
	}
	GPIO_ResetBits(KEYPAD_PORT, COLOUMN3);

	return keyStroke;
}

void Keypad_Delay(uint32_t msecond)
{
	uint32_t i;
	for(i=0; i<msecond; i++)
	{
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
	}
}
