#include "stm32f0xx_keypad.h"
#include "stm32f0xx_7segment.h"

int main(void)
{
	unsigned char  input;

	SevenSegment_Init();
	Keypad_Init();

    while(1)
    {
    	input = Keypad_Scan();
    	SevenSegment_WriteData(input);
    }
}
