#include "mbed.h"
BusOut myleds(LED1, LED2, LED3, LED4, p5, p6, p7, p8);

int main() 
{
    uint8_t binary = 0b00000101;
    myleds = binary;
    
    while(1) 
    {
        wait(0.25);
        if(binary == 0b10000000) 
        {
            binary = 0b10100000;
            myleds = binary;
            while(binary != 0b00000001) 
            {
                wait(0.25);
                binary >>= 1;
                myleds = binary;
            }
            if(binary == 0b00000001)
                wait(0.25);
                binary = 0b00000101;
                myleds = binary;
        }
        else 
        {
            binary <<= 1;
            myleds = binary;
        }
    }
}
