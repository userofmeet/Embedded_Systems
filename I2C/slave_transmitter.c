#include <stm32f10x.h> 					// ec080
#include <stdio.h> 
void Initialize(void) 
{ 
	I2C1 -> CR2 = 0x08; // Set freq to 8MHz 
	I2C1 -> CCR = 0x28; // set clock freq 
	I2C1 -> CR1 = 0x0401; 
	// enable pheripheral and acknowledgement bit[0] and bit[10] resp. 
}

void Start(void) 
{ 
	I2C1 -> CR1 |= 0x0100; // start generation bit[8] 
	while(!(I2C1 -> SR1 & 0x0001)); // confirming start bit generation (checking bit[0]) 
} 

void Address(char x) 
{ 
	I2C1 -> DR = x | 0; // address kept in DATA REGISTER 
	while(!(I2C1 -> SR1 & 0x0002)); // confirming address sent (check bit[1]) 
	I2C1 -> SR1 = ((I2C1 -> SR1) & 0xFFFD); // clearing ADDR bit for master receiver mode (clear 	bit[1]) 
} 

void Data() 
{ 
	char d ; //I2C1 -> DR = 0x00; 
	while(!(I2C1 -> SR1 & 0x40)); 
	// Wait for data transfer to complete (checking bit[1]) 
} 

void Stop(void) 
{ 
	I2C1 -> CR1 |= 0x0200; // Set stop bit, bit[9] 
	while(I2C1 -> SR2 & 0x0002); 
	// confirming stop bit generation (checking bit[1]) 
} 

int main(void) 
{ 
	Initialize(); 
	Start(); 
	Address(0x71); 
	Data(); 
	Stop(); 
	return 0; 
} 

