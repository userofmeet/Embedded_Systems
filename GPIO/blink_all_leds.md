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
		for(j=0;j<8;j++){
			GPIOC -> BSRR = 0xFFFF;
			for(i=0;i<2000000;i++);
			GPIOC -> BSRR = 0xFFFF0000;
			for(i=0;i<2000000;i++);
		}
	}
}
```

## Results
<img width="507" height="525" alt="image" src="https://github.com/user-attachments/assets/8ca1c547-c97e-40b1-b26c-842ca73d6291" />
<img width="507" height="525" alt="image" src="https://github.com/user-attachments/assets/ebc5791e-4a71-4dfc-9f70-7f74506a8ab8" />
