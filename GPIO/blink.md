## CODE
``` c
#include <stm32f10x.h>
int main()
{
	int i; 
	RCC -> APB2ENR |= (1<<4);
	GPIOC -> CRH |= ((1<<20) | (1<<21));
	GPIOC -> CRH &= ~((1<<22) | (1<<23));
	while(1)
	{
		GPIOC -> BSRR = (1<<13);
		for(i=0;i<20000000;i++);
		GPIOC -> BSRR = (1<<29);
		for(i=0;i<20000000;i++);
	}
}
```

## GPIOC Peripheral
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/9a9f2502-348a-46d8-a337-0e1168f7b952" />
<img width="507" height="525" alt="image" src="https://github.com/user-attachments/assets/34bc1467-473d-450b-b591-cc3bb934bead" />
<img width="507" height="525" alt="image" src="https://github.com/user-attachments/assets/02e2140c-9915-45f7-9536-09b9f4e0aac8" />
