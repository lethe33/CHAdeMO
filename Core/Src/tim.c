/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    tim.c
 * @brief   This file provides code for the configuration
 *          of the TIM instances.
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
/* Includes ------------------------------------------------------------------*/
#include "tim.h"

/* USER CODE BEGIN 0 */
// custom timer for 1/1000 SEC
volatile uint16_t timeMS[TIME_MS_LIST_END] = {
    0,
};
// custom timer for 1 SEC
volatile uint16_t timeSEC[TIME_SEC_LIST_END] = {
    0,
};
// check 1000ms for timeSEC
volatile uint16_t secCNT[TIME_SEC_LIST_END] = {
    0,
};
// timer for mainProcess
volatile uint16_t timeDelay[TIME_DELAY_LIST_END] = {
    0,
};
/* USER CODE END 0 */

TIM_HandleTypeDef htim7;

/* TIM7 init function */
void MX_TIM7_Init(void)
{

  /* USER CODE BEGIN TIM7_Init 0 */

  /* USER CODE END TIM7_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM7_Init 1 */

  /* USER CODE END TIM7_Init 1 */
  htim7.Instance = TIM7;
  htim7.Init.Prescaler = 84-1;
  htim7.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim7.Init.Period = 1000-1;
  htim7.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim7) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim7, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM7_Init 2 */

  /* USER CODE END TIM7_Init 2 */

}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* tim_baseHandle)
{

  if(tim_baseHandle->Instance==TIM7)
  {
  /* USER CODE BEGIN TIM7_MspInit 0 */

  /* USER CODE END TIM7_MspInit 0 */
    /* TIM7 clock enable */
    __HAL_RCC_TIM7_CLK_ENABLE();

    /* TIM7 interrupt Init */
    HAL_NVIC_SetPriority(TIM7_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIM7_IRQn);
  /* USER CODE BEGIN TIM7_MspInit 1 */

  /* USER CODE END TIM7_MspInit 1 */
  }
}

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* tim_baseHandle)
{

  if(tim_baseHandle->Instance==TIM7)
  {
  /* USER CODE BEGIN TIM7_MspDeInit 0 */

  /* USER CODE END TIM7_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM7_CLK_DISABLE();

    /* TIM7 interrupt Deinit */
    HAL_NVIC_DisableIRQ(TIM7_IRQn);
  /* USER CODE BEGIN TIM7_MspDeInit 1 */

  /* USER CODE END TIM7_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

void setTimerMS(uint16_t no, uint16_t t) {  // made function for ext access, timeMS[array] work in tim.c only
    timeMS[no] = t;
}
uint16_t getTimerMS(uint16_t no) {  // made function for ext access, timeMS[array] work in tim.c only
    return timeMS[no];
}
void setTimerSEC(uint16_t no, uint16_t t) {  // made function for ext access, timeSEC[array] work in tim.c only
    timeSEC[no] = t;
}
uint16_t getTimerSEC(uint16_t no) {  // made function for ext access, timeSEC[array] work in tim.c only
    return timeSEC[no];
}
void setDelayMS(uint16_t no, uint16_t t) {  // made function for ext access, timeDelay[array] work in tim.c only
    timeDelay[no] = t;
}
uint16_t getDelayMS(uint16_t no) {  // made function for ext access, timeDelay[array] work in tim.c only
    return timeDelay[no];
}

void onCounterMS(void) {  // minus counter for HAL_TIM_PeriodElapsedCallback (1ms)
    for (uint8_t no = 0; no < TIME_MS_LIST_END; no++) {
        timeMS[no] = (timeMS[no] > 0) ? timeMS[no] - 1 : 0;
        timeDelay[no] = (timeDelay[no] > 0) ? timeDelay[no] - 1 : 0;
    }
}

void onCounterSEC(void) {  // minus counter for HAL_TIM_PeriodElapsedCallback (1000ms)
    for (uint8_t no = 1; no < TIME_SEC_LIST_END; no++) {
        if (timeSEC[no] != 0) {
            if (++secCNT[no] > 999) {
                secCNT[no] = 0;
                timeSEC[no] = (timeSEC[no] > 0) ? timeSEC[no] - 1 : 0;
            }
        }
    }
}
/* USER CODE END 1 */
