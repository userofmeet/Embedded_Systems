## CODE
```C
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
			GPIOC -> BSRR = (1<<(15-j));
			for(i=0;i<2000000;i++);
			GPIOC -> BSRR = (1<<(j+16));
			GPIOC -> BSRR = (1<<(15-j+16));
			for(i=0;i<2000000;i++);
		}
	}
}
```

## GPIOC Peripheral 
<img width="507" height="525" alt="image" src="https://github.com/user-attachments/assets/d84bbf10-a088-4c14-9033-2c4b79176a1d" />
<img width="507" height="525" alt="image" src="https://github.com/user-attachments/assets/7f15085f-b3b7-463c-bb3a-355eb226b734" />
<img width="507" height="525" alt="image" src="https://github.com/user-attachments/assets/cc99801e-2110-4b32-ac90-b353d4dcfac9" />
