/*
 * koolCharge.c
 *
 *  Created on: Sep 6, 2023
 *      Author: User
 */
#include <stdio.h>

#include "chademo.h"
#include "fault.h"
#include "gpio.h"
#include "iwdg.h"
#include "main.h"
#include "tim.h"
#include "usart.h"
void delay1ms(void) {
    __HAL_IWDG_RELOAD_COUNTER(&hiwdg);  // IWED reload counter (500ms)
    faultProcess();
}
void delay5ms(void) {
    CHAdeMO_Process();
}
void delay10ms(void) {
}
void delay50ms(void) {
}
void delay100ms(void) {
}
void delay500ms(void) {
}
void delay1sec(void) {
    HAL_GPIO_TogglePin(LED_L_R_GPIO_Port, LED_L_R_Pin);  // heartbeat
    HAL_GPIO_TogglePin(LED_R_G_GPIO_Port, LED_R_G_Pin);  // heartbeat
}
void mainProcess(void) {
    if (getDelayMS(TIME_DELAY_1MS) == 0) {
        setDelayMS(TIME_DELAY_1MS, 1);
        delay1ms();
        if (getDelayMS(TIME_DELAY_5MS) == 0) {
            setDelayMS(TIME_DELAY_5MS, 5);
            delay5ms();
            if (getDelayMS(TIME_DELAY_10MS) == 0) {
                setDelayMS(TIME_DELAY_10MS, 10);
                delay10ms();
                if (getDelayMS(TIME_DELAY_50MS) == 0) {
                    setDelayMS(TIME_DELAY_50MS, 50);
                    delay50ms();
                    if (getDelayMS(TIME_DELAY_100MS) == 0) {
                        setDelayMS(TIME_DELAY_100MS, 100);
                        delay100ms();
                        if (getDelayMS(TIME_DELAY_500MS) == 0) {
                            setDelayMS(TIME_DELAY_500MS, 500);
                            delay500ms();
                            if (getDelayMS(TIME_DELAY_1SEC) == 0) {
                                setDelayMS(TIME_DELAY_1SEC, 1000);
                                delay1sec();
                            }
                        }
                    }
                }
            }
        }
    }
}
