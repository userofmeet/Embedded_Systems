#include "STM32F10x.h"
extern int32_t LED_Initialize (void);
extern int32_t LED_Uninitialize (void);
extern int32_t LED_On (uint32_t num);
extern int32_t LED_Off (uint32_t num);
extern int32_t LED_SetOut (uint32_t val);
int main(void)
{
	LED_Initialize(); 
	while(1)
	{
    LED_On(2);			//EC080
		for (int i=0;i<10000;i++);
		LED_Off(2);
		for (int i=0;i<10000;i++);
	}
}
