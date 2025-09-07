#include <LPC17xx.h>
void delay(int count) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < 1000; j++);  // crude delay
    }
}

int main(void) {
    LPC_GPIO2->FIODIR |= (1 << 0);   
    while (1) {
        LPC_GPIO2->FIOSET = (1 << 0);
        delay(1000);
        LPC_GPIO2->FIOCLR = (1 << 0);
        delay(1000);
    }
}
