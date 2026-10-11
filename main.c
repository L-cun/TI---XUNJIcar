#include "ti_msp_dl_config.h"
#include "main.h"
#include "stdio.h"
#include "Mor.h"
#include "xunji.h"
#include "Delay.h"
#include "oled_hardware_spi.h"
#include "circle.h"
#include "key.h"


uint8_t str_test[100];
uint8_t TASK = 0;//1!!!!!!!!!!!!!!!!!!!!1111
uint8_t workstep = 0;
uint8_t First_flag,startFlag = 0;
uint8_t pid_mode = 0;
float angle_record = 0;
float angle_record_1 = 0, angle_record_2 = 0;
uint8_t task4_jishu = 0;
float angle_record_3 = 0;
uint8_t key4_clicks = 0;  // 按键4点击次数
int KEYNum,modeFlag, circle=0;
uint8_t task_running = 1;
int a=1;
int main(void)
{
    
    SYSCFG_DL_init();
    SYSCFG_DL_motorAB_init();
    WIT_Init();
    motor_on();
     DL_TimerG_startCounter(motorAB_INST);
    circle_count = 0;
    uint8_t mode_changed = 0;
   
    while (1)  
    {                             

        
      uint8_t key_num = KEY_Getnum(); 
    if (key_num == 1) 
  {
    mode_changed++;
    if(mode_changed>6)
  {
   mode_changed=0;
  }

   }
  if(mode_changed==1&&key_num==2)
{
    while(a)
        { Trace();
        
        // 2. 执行圈计数（检测全白区域并累计圈数）
        count1_circle();
        
        // 3. 判断是否完成1圈，完成则停止
        if(circle_count >= 1)
        {
            motor_set_4(0, 0); // 停止电机
            a=0;
        }
        
        Delay_ms(10); // 控制循环频率
       }
    }

 if(mode_changed==2&&key_num==2)
{
    while(a)
        { Trace();
        
        // 2. 执行圈计数（检测全白区域并累计圈数）
        count2_circle();
        
        // 3. 判断是否完成1圈，完成则停止
        if(circle_count >= 2)
        {
            motor_set_4(0, 0); // 停止电机
            a=0;
        }
        
        Delay_ms(10); // 控制循环频率
       }
    }
 if(mode_changed==3&&key_num==2)             ///////////////////////////  ////3     2
{
    while(a)
        { Trace();
        
        // 2. 执行圈计数（检测全白区域并累计圈数）
        count3_circle();
        
        // 3. 判断是否完成1圈，完成则停止
        if(circle_count >= 2)
        {
            motor_set_4(0, 0); // 停止电机
            a=0;
        }
        
        Delay_ms(10); // 控制循环频率
       }
    }
 if(mode_changed==4&&key_num==2)             /////////////4                 5
{
    while(a)
        { Trace();
        
        // 2. 执行圈计数（检测全白区域并累计圈数）
        count2_circle();
        
        // 3. 判断是否完成1圈，完成则停止
        if(circle_count >= 4)
        {
            motor_set_4(0, 0); // 停止电机
            a=0;
        }
        
        Delay_ms(10); // 控制循环频率
       }
    }
  if(mode_changed==5&&key_num==2)
{
    while(a)
        { Trace();
        
        // 2. 执行圈计数（检测全白区域并累计圈数）
        count2_circle();
        
        // 3. 判断是否完成1圈，完成则停止
        if(circle_count >= 5)
        {
            motor_set_4(0, 0); // 停止电机
            a=0;
        }
        
        Delay_ms(10); // 控制循环频率
       }
    }
    
   }

  


    }