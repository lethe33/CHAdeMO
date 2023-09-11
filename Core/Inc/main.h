/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_R_B_Pin GPIO_PIN_0
#define LED_R_B_GPIO_Port GPIOB
#define LED_L_R_Pin GPIO_PIN_12
#define LED_L_R_GPIO_Port GPIOD
#define LED_L_G_Pin GPIO_PIN_13
#define LED_L_G_GPIO_Port GPIOD
#define LED_L_B_Pin GPIO_PIN_14
#define LED_L_B_GPIO_Port GPIOD
#define LED_R_R_Pin GPIO_PIN_6
#define LED_R_R_GPIO_Port GPIOC
#define LED_R_G_Pin GPIO_PIN_5
#define LED_R_G_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
enum{
    ID_LIST_START = 0,
    ID_LEFT,
    ID_RIGHT,
    ID_LIST_END
};
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
