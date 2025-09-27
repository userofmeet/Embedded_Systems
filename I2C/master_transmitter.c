#include<stm32f10x.h>
char res;
void I2C_Init()
{
	RCC->APB1ENR |= (1<<21);		//EC080
	I2C1->CR2=0x0008;
	I2C1->CCR=0x0028;
	I2C1->CR1=0x0001;
}

void I2C_Start()
{
	I2C1->CR1|=1<<8;
	I2C1->CR1|=1<<10;
	while(!(I2C1->SR1&0x0001));
}

void I2C_Addr(unsigned char adr)
{
	I2C1->DR=adr|0;
	while(!(I2C1->SR1&0x0002));
	res=(I2C1->SR2);
}

void I2C_Write()
{
	I2C1->DR=0xAA;
	while(!(I2C1->SR1&(1<<7)));
}

void I2C_Stop()
{
	I2C1->CR1|=0x0200;
	while(I2C1->SR2&0x0002);
}

int main()
{
	I2C_Init();
	I2C_Start();
	I2C_Addr(0x70);
	I2C_Write();
	I2C_Stop();
}
