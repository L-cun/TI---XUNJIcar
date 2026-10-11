#include "ti_msp_dl_config.h"
#include "delay.h"

int KEY_Getnum(void)
{
   int KEY_Num=0;
    uint32_t temp=0;
  if(!DL_GPIO_readPins(KEYS_KEY1_PORT,KEYS_KEY1_PIN))
	{
		delay_cycles(320000*2);
		while(!DL_GPIO_readPins(KEYS_KEY1_PORT,KEYS_KEY1_PIN));
		delay_cycles(320000*2);
		KEY_Num=1;
	}

  if(!DL_GPIO_readPins(KEYS_KEY2_PORT,KEYS_KEY2_PIN))
	{
		delay_cycles(320000*2);
		while(!DL_GPIO_readPins(KEYS_KEY2_PORT,KEYS_KEY2_PIN));
		delay_cycles(320000*2);
		KEY_Num=2;
	}
    return KEY_Num;
}