#include <stm32f4xx.h>                       /* STM32F103 definitions         */
__asm void abc (void) {
	MOV R0,#0XFFFFFFFF
	BX R0
}

int main (void) {
 abc();
  while (1) ;
}
