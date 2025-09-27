#include "STM32F4xx.h"
extern int32_t LED_Initialize (void);
extern int32_t LED_Uninitialize (void);
extern int32_t LED_On (uint32_t num);
extern int32_t LED_Off (uint32_t num);
extern int32_t LED_SetOut (uint32_t val);
int main(void)
{
    LED_Initialize();   // initialize LEDs
        while(1)
    {
        LED_SetOut(0xAA);   // send binary 10101010 to LEDs
        for (int i=0;i<100000;i++);

        LED_SetOut(0x55);   // send binary 01010101 to LEDs
        for (int i=0;i<100000;i++);
    }
}
