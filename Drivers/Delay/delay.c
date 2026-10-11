#include "delay.h"


void Delay_ms(uint32_t times)
{
    while(times--)
        delay_cycles(CPUCLK_FREQ/1000);
}

void Delay_us(uint32_t us)
{
    while(us--)
    {
        delay_cycles(CPUCLK_FREQ/1000000);
    }
}