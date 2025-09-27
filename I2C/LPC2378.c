#include <LPC23xx.h>
char res;
void I2C_Init(void)
{
    // Enable power/clock for I2C0 (PCONP bit 7)
    PCONP |= (1 << 7);

    // P0.27 = SDA0, P0.28 = SCL0 (select function 1)
    PINSEL1 |= (1 << 22) | (1 << 24);

    // I2C Clock = PCLK / (I2SCLH + I2SCLL)
    // Suppose PCLK = 12 MHz, we want 100kHz → 12MHz/(60+60)=100kHz
    I2C0SCLH = 60;
    I2C0SCLL = 60;
    // Enable I2C
    I2C0CONSET = (1 << 6);   // I2EN = 1
}

void I2C_Start(void)
{
    I2C0CONSET = (1 << 5);   // STA = 1
    I2C0CONCLR = (1 << 3);   // Clear SI
    while (!(I2C0CONSET & (1 << 3))); // Wait for SI = 1
}

void I2C_Addr(unsigned char adr)
{
    I2C0DAT = adr;           // Load slave address + Write bit
    I2C0CONCLR = (1 << 5);   // Clear START bit
    I2C0CONCLR = (1 << 3);   // Clear SI
    while (!(I2C0CONSET & (1 << 3))); // Wait for SI
    res = I2C0STAT;          // Read status
}

void I2C_Write(unsigned char data)
{
    I2C0DAT = data;          // Send data
    I2C0CONCLR = (1 << 3);   // Clear SI
    while (!(I2C0CONSET & (1 << 3))); // Wait for SI
}

void I2C_Stop(void)
{
    I2C0CONSET = (1 << 4);   // STO = 1
    I2C0CONCLR = (1 << 3);   // Clear SI
}
 


int main(void)
{
    I2C_Init();
    I2C_Start();
    I2C_Addr(0x70);      // Slave address (write mode)
    I2C_Write(0xAA);     // Send data byte
    I2C_Stop();
}

