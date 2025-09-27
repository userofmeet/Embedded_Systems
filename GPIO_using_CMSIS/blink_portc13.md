## Code
```c
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
		LED_On(5);			//EC080
		for (int i=0;i<10000;i++);
		LED_Off(5);
		for (int i=0;i<10000;i++);
	}
}
```
## Modification in LED_MCBSTM32C.c for blinking LED at PORTC
<img width="864" height="468" alt="image" src="https://github.com/user-attachments/assets/a89886c3-e64e-4326-ba33-c5d4980e53a8" />
