## CODE
```c
#include <stm32f10x.h>
int main()

{
	int i,j; 
	RCC -> APB2ENR |= (1<<4);
	GPIOC -> CRH |= ((1<<20) | (1<<21));
	GPIOC -> CRH &= ~((1<<22) | (1<<23));
	while(1)
	{
		for(j=7;j>=0;j--){
			GPIOC -> BSRR = (1<<j);
			for(i=0;i<2000000;i++);
			GPIOC -> BSRR = (1<<j+16);
			for(i=0;i<2000000;i++);
		}
	}
}
```

## RESULTS
<img width="507" height="525" alt="image" src="https://github.com/user-attachments/assets/aab73131-180b-4a97-b164-d5d4cc7bb22c" />
<img width="507" height="525" alt="image" src="https://github.com/user-attachments/assets/c631ad80-cc7c-48e8-90f9-c19a62e2b20d" />
<img width="507" height="525" alt="image" src="https://github.com/user-attachments/assets/22c7452b-357a-4a3e-aa25-b104d82ee6fb" />
