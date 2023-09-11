/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    tim.h
 * @brief   This file contains all the function prototypes for
 *          the tim.c file
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TIM_H__
#define __TIM_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern TIM_HandleTypeDef htim7;

/* USER CODE BEGIN Private defines */
enum { // for timer
    TIME_MS_TEST_01 = 1,
    TIME_MS_TEST_02,
    TIME_MS_TEST_03,
    TIME_MS_TEST_04,
    TIME_MS_TEST_05,
    TIME_MS_TEST_06,
    TIME_MS_TEST_07,
    TIME_MS_LIST_END,

    TIME_SEC_TEST_01 = 1,
    TIME_SEC_TEST_02,
    TIME_SEC_TEST_03,
    TIME_SEC_TEST_04,
    TIME_SEC_TEST_05,
    TIME_SEC_TEST_06,
    TIME_SEC_TEST_07,
    TIME_SEC_FAULT_RESET,
    TIME_SEC_FAULT_RESET_LEFT = TIME_SEC_FAULT_RESET,
    TIME_SEC_FAULT_RESET_RIGHT,
    TIME_SEC_LIST_END,

    TIME_DELAY_1MS = 1,
    TIME_DELAY_5MS,
    TIME_DELAY_10MS,
    TIME_DELAY_50MS,
    TIME_DELAY_100MS,
    TIME_DELAY_500MS,
    TIME_DELAY_1SEC,
    TIME_DELAY_LIST_END
};
/* USER CODE END Private defines */

void MX_TIM7_Init(void);

/* USER CODE BEGIN Prototypes */
void setTimerMS(uint16_t no, uint16_t t);
void setTimerSEC(uint16_t no, uint16_t t);
void setDelayMS(uint16_t no, uint16_t t);
uint16_t getTimerMS(uint16_t no);
uint16_t getTimerSEC(uint16_t no);
uint16_t getDelayMS(uint16_t no);
void onCounterMS(void);
void onCounterSEC(void);
// void onCounterSEC(unsigned char no);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __TIM_H__ */

