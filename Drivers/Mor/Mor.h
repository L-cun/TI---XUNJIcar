#ifndef __MOR_H
#define __MOR_H

void gpio_set(GPIO_Regs* gpio, uint32_t pins, uint8_t t);
void uart_send(UART_Regs* uart, unsigned char *Tx_buf, int len);//向某个串口传送数据
void motorA_dir_speed(uint8_t dir, float speed);
void motorB_dir_speed(uint8_t dir, float speed);
void motorA_dir_duty(uint8_t dir, float duty);
void motorB_dir_duty(uint8_t dir, float duty);
void motor_set(float duty_A, float duty_B);
void motor_on(void);
void motor_off(void);
void motor_set_4(float speed_A, float speed_B);
#endif
