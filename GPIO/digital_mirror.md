## Code
```c
#include "stm32f10x.h"
int main()
{
	int i,j;
	RCC -> APB2ENR |= (1<<2);
	RCC -> APB2ENR |= (1<<3);//01100
	GPIOA -> CRL &= ~(0xF << 0);
	GPIOA -> CRL |= (0x04 << 0);
	GPIOB -> CRL &= ~(0x0F << 0);
	GPIOB -> CRL |= (0x02 << 0);
	while(1){
		if (GPIOA -> IDR & (1<<0))
		{
			GPIOB -> BSRR = (1<<0);
		}
		else{
			GPIOB -> BRR = (1<<0);
		}
	}
}
```

## Results
### ON 
<img width="507" height="525" alt="image" src="https://github.com/user-attachments/assets/6e5f7b68-2099-4a69-84de-de660d5622c0" />
<img width="507" height="525" alt="image" src="https://github.com/user-attachments/assets/c6fc8328-cff1-43ed-bb0a-a9452048bc2d" />


### OFF
<img width="507" height="525" alt="image" src="https://github.com/user-attachments/assets/849949d3-8f4f-4412-888d-1f06a987bf39" />
<img width="507" height="525" alt="image" src="https://github.com/user-attachments/assets/587cfb53-d956-4157-abc7-7dd4fc301d90" />


