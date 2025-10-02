#include "stm32f10x.h"                  // Device header
void Initialize_spi(void);							//EC080
void Initialize_IOA(void);
void send_data(void);

int main(){
	Initialize_IOA();
	Initialize_spi();
	send_data();
}

void Initialize_spi(void){	
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN; 	// enable the peripheral bus and gpio A also
	SPI1->CR1 = SPI_CR1_SSM | SPI_CR1_MSTR; 	// configuring with S/W slave select as master
	SPI1->CR1 |= SPI_CR1_SPE; 		              // enabling the spi peripheral
}

void Initialize_IOA(void){			// initialize the input and output pins for MOSI, CLOCL and MISO
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;	  // enable the GPIO A
	GPIOA->CRL = 0xB8B00000;		// configure pin 7,6,5 of A as specified in data sheet
//	AFIO->EVCR = 0x87 | 0x85;	// enable the alternate function of pins. fucntion which are to be configured as alternate fucntion
}


void send_data(void){
	char ch;
	SPI1->CR1 |= SPI_CR1_SSI;	// enable the slave first
	SPI1->DR = 0xab; 			// send first the ab 
	while(!(SPI1->SR & SPI_SR_RXNE));	// check to receive bit from MISO pin to see if something is received from MISO pin and also clear RXNE flag by reading it
	
ch = SPI1->DR;          // reading received value in ch variable
	while(!(SPI1->SR & SPI_SR_TXE));	// wait for it to transmit and also clearing txe flag by reading it

	SPI1->DR = 0xcd;			// load with another word
	while(!(SPI1->SR & SPI_SR_RXNE));	 // check to receive from MISO pin
	ch = SPI1->DR;
	while(!(SPI1->SR & SPI_SR_TXE));
	SPI1->DR =0xef;
	while(!(SPI1->SR & SPI_SR_RXNE));
	ch = SPI1->DR;
	
	//initiating the stop condition
	while(!(SPI1->SR & SPI_SR_TXE));
	ch = SPI1->DR;
	while(!(SPI1->SR & SPI_SR_RXNE));
	while(!(SPI1->SR & SPI_SR_BSY)); // wait for line to be un_busy
	
	// here we are supposed to disable the spi peripheral
}

