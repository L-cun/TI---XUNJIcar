#include "ti_msp_dl_config.h"
#include "Mor.h"
#include "xunji.h"
#include "Delay.h"

uint8_t L4=0, L3=0, L2=0, L1=0;
uint8_t R1=0, R2=0, R3=0, R4=0;
uint8_t Line_flag = 1;       // 1=在轨迹上，0=离线
uint8_t turn_state = 0;      // 转弯状态：0=直走，1=右转中，2=左转中
uint16_t turn_cnt = 0;       // 转弯计时（用于控制转弯角度）
float basespeed = 0.2f;     // 直走基础速度
float turn_speed = 0.4f;     // 转弯时基础速度（略低，提高稳定性）
// 读取传感器状态
void Get_Sensors(void)
{
    L4 = DL_GPIO_readPins(xunji_L4_PORT, xunji_L4_PIN) ? 1 : 0;
    L3 = DL_GPIO_readPins(xunji_L3_PORT, xunji_L3_PIN) ? 1 : 0;
    L2 = DL_GPIO_readPins(xunji_L2_PORT, xunji_L2_PIN) ? 1 : 0;
    L1 = DL_GPIO_readPins(xunji_L1_PORT, xunji_L1_PIN) ? 1 : 0;
    R1 = DL_GPIO_readPins(xunji_R1_PORT, xunji_R1_PIN) ? 1 : 0;
    R2 = DL_GPIO_readPins(xunji_R2_PORT, xunji_R2_PIN) ? 1 : 0;
    R3 = DL_GPIO_readPins(xunji_R3_PORT, xunji_R3_PIN) ? 1 : 0;
    R4 = DL_GPIO_readPins(xunji_R4_PORT, xunji_R4_PIN) ? 1 : 0;

    // 检测到任何轨迹，标记在线
    if(L4==0 || L3==0 || L2==0 || L1==0 || R1==0 || R2==0 || R3==0 || R4==0)
    {
        Line_flag = 1;
    }
}


void Trace(void)
{
    Get_Sensors();
      if(L4==0&&L3==0&&L2==0&&L1==0&&R1==0&&R2==0&&R3==0&&R4==0)
    {
       motor_set_4(0, 0.4);
      
        Delay_ms(60);
       
    
    }
       else  if(L1==1&&R1==1)
        {
            motor_set_4(basespeed, basespeed);
        }
        else if(L4==1)// 0011 1111
        {
            motor_set_4(0, 0.2);
        }
        else if(R4==1)// 0011 1111
        {
            motor_set_4(0.2, 0);
        }
         
         else if(L4==1&&L3==0)// 0011 1111
        {
            motor_set_4(0, 0.2);
        }
        else if(L2==1&&L3==1)// 0011 1111
        {
            motor_set_4(0, 0.2);
        }
        
        else if(L4==1&&L3==1)// 0011 1111
        {
            motor_set_4(0, 0.2);
        }
        else if(R3==1&&R4==1)// 1111 1100
        {
            motor_set_4(basespeed + 0.2, 0);
        }
       else if(L4==1)// 1111 1100
        {
            motor_set_4(0, 0.2);
        }
        else if(R4==1)// 1111 1100
        {
            motor_set_4( 0.2, 0);
        }
        else if(R4==1&&R3==0)//1111 1110
        {
            motor_set_4(basespeed + 0.2, basespeed - 0.1);
        }

        else if(L1==1&&R1==0)// 1110 1111
        {
            motor_set_4(basespeed - 0.17, basespeed + 0.08);
        }
        else if(L1==0&&R1==1)// 1111 0111
        {
            motor_set_4(basespeed + 0.08, basespeed - 0.17);
        }

        else if(L2==1&&L1==1)// 1100 1111
        {
            motor_set_4(basespeed - 0.17, basespeed + 0.18);
        }
        else if(R1==1&&R2==1)// 1111 0011
        {
            motor_set_4(basespeed + 0.18, basespeed - 0.17);
        }

        else if(L3==1&&L2==1)// 1001 1111
        {
            motor_set_4(basespeed - 0.17, basespeed + 0.23);
        }
        else if(R2==1&&R3==1)// 1111 1001
        {
            motor_set_4(basespeed + 0.23, basespeed - 0.17);
        }
       
     
        
    }

