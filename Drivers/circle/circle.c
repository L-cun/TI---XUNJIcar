#include "ti_msp_dl_config.h"
#include "Mor.h"
#include "xunji.h"
  

uint8_t circle_count = 0;  // 总圈数
uint8_t white_pass = 0;    // 全白区域通过计数
uint8_t in_white_area = 0; // 全白区域标记（0=不在，1=在）

void count1_circle(void)
{
    Get_Sensors();
    
    // 检测全白区域
    if(L4==0&&L3==0&&L2==0&&L1==0&&R1==0&&R2==0&&R3==0&&R4==0)
    {
        // 核心控制：仅在"首次进入全白区域"时计数
        if(in_white_area == 0) 
        {
            in_white_area = 1;  // 标记为"已进入"，防止重复计数
            white_pass++;       // 累加通过次数
            
            if(white_pass >= 4)
            {
                circle_count++;  // 圈数+1
                white_pass = 0;  // 重置计数
            }
        }
    }
    else
    {
        // 离开全白区域时，重置标记
        in_white_area = 0;
    }
}

void count4_circle(void)
{
    Get_Sensors();
    
    // 检测全白区域
    if(L4==0&&L3==0&&L2==0&&L1==0&&R1==0&&R2==0&&R3==0&&R4==0)
    {
        // 核心控制：仅在"首次进入全白区域"时计数
        if(in_white_area == 0) 
        {
            in_white_area = 1;  // 标记为"已进入"，防止重复计数
            white_pass++;       // 累加通过次数
            
            if(white_pass >= 8)
            {
                circle_count++;  // 圈数+1
                white_pass = 0;  // 重置计数
            }
        }
    }
    else
    {
        // 离开全白区域时，重置标记
        in_white_area = 0;
    }
}

void count3_circle(void)
{
    Get_Sensors();
    
    // 检测全白区域
    if(L4==0&&L3==0&&L2==0&&L1==0&&R1==0&&R2==0&&R3==0&&R4==0)
    {
        // 核心控制：仅在"首次进入全白区域"时计数
        if(in_white_area == 0) 
        {
            in_white_area = 1;  // 标记为"已进入"，防止重复计数
            white_pass++;       // 累加通过次数
            
            if(white_pass >= 6)
            {
                circle_count++;  // 圈数+1
                white_pass = 0;  // 重置计数
            }
        }
    }
    else
    {
        // 离开全白区域时，重置标记
        in_white_area = 0;
    }
}

void count2_circle(void)
{
    Get_Sensors();
    
    // 检测全白区域
    if(L4==0&&L3==0&&L2==0&&L1==0&&R1==0&&R2==0&&R3==0&&R4==0)
    {
        // 核心控制：仅在"首次进入全白区域"时计数
        if(in_white_area == 0) 
        {
            in_white_area = 1;  // 标记为"已进入"，防止重复计数
            white_pass++;       // 累加通过次数
            
            if(white_pass >= 4)
            {
                circle_count++;  // 圈数+1
                white_pass = 0;  // 重置计数
            }
        }
    }
    else
    {
        // 离开全白区域时，重置标记
        in_white_area = 0;
    }
}

void count5_circle(void)
{
    Get_Sensors();
    
    // 检测全白区域
    if(L4==0&&L3==0&&L2==0&&L1==0&&R1==0&&R2==0&&R3==0&&R4==0)
    {
        // 核心控制：仅在"首次进入全白区域"时计数
        if(in_white_area == 0) 
        {
            in_white_area = 1;  // 标记为"已进入"，防止重复计数
            white_pass++;       // 累加通过次数
            
            if(white_pass >= 8)
            {
                circle_count++;  // 圈数+1
                white_pass = 0;  // 重置计数
            }
        }
    }
    else
    {
        // 离开全白区域时，重置标记
        in_white_area = 0;
    }
}

