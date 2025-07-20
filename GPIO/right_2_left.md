## CODE
``` c
#include <stm32f10x.h>
int main()

{
	int i,j; 
	RCC -> APB2ENR |= (1<<4);
	GPIOC -> CRH |= ((1<<20) | (1<<21));
	GPIOC -> CRH &= ~((1<<22) | (1<<23));
	while(1)
	{
		for(j=0;j<8;j++){
			GPIOC -> BSRR = (1<<j);
			for(i=0;i<2000000;i++);
			GPIOC -> BSRR = (1<<j+16);
			for(i=0;i<2000000;i++);
		}
	}
}
```

## GPIOC Peripheral
<img width="507" height="525" alt="image" src="https://github.com/user-attachments/assets/cdbc0284-0d56-4f8e-863d-96088fb703b8" />
<img width="507" height="525" alt="image" src="https://github.com/user-attachments/assets/5717fcd6-992e-4c33-9d66-b828ae7a2c9a" />
<img width="507" height="525" alt="image" src="https://github.com/user-attachments/assets/f63a413a-50c4-4efd-a3dc-8641fba2b695" />
