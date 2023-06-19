/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define yukariYavaslamaLimitIn_Pin GPIO_PIN_13
#define yukariYavaslamaLimitIn_GPIO_Port GPIOC
#define yavaslamaLimitIn_Pin GPIO_PIN_14
#define yavaslamaLimitIn_GPIO_Port GPIOC
#define basincSalteriIn_Pin GPIO_PIN_15
#define basincSalteriIn_GPIO_Port GPIOC
#define ecercevesiIn_Pin GPIO_PIN_0
#define ecercevesiIn_GPIO_Port GPIOC
#define ustlimitIn_Pin GPIO_PIN_1
#define ustlimitIn_GPIO_Port GPIOC
#define altlimitIn_Pin GPIO_PIN_2
#define altlimitIn_GPIO_Port GPIOC
#define geributonIn_Pin GPIO_PIN_3
#define geributonIn_GPIO_Port GPIOC
#define ileributonIn_Pin GPIO_PIN_0
#define ileributonIn_GPIO_Port GPIOA
#define yukaributonIn_Pin GPIO_PIN_1
#define yukaributonIn_GPIO_Port GPIOA
#define asagibutonIn_Pin GPIO_PIN_2
#define asagibutonIn_GPIO_Port GPIOA
#define enterbutonIn_Pin GPIO_PIN_3
#define enterbutonIn_GPIO_Port GPIOA
#define buzzerOut_Pin GPIO_PIN_4
#define buzzerOut_GPIO_Port GPIOA
#define tablaKapiOut_Pin GPIO_PIN_5
#define tablaKapiOut_GPIO_Port GPIOA
#define kapi2Out_Pin GPIO_PIN_6
#define kapi2Out_GPIO_Port GPIOA
#define kapi1Out_Pin GPIO_PIN_7
#define kapi1Out_GPIO_Port GPIOA
#define devirmeAsagiGeriOut_Pin GPIO_PIN_4
#define devirmeAsagiGeriOut_GPIO_Port GPIOC
#define devirmeYukariIleriOut_Pin GPIO_PIN_5
#define devirmeYukariIleriOut_GPIO_Port GPIOC
#define yavaslamaValfOut_Pin GPIO_PIN_0
#define yavaslamaValfOut_GPIO_Port GPIOB
#define asagiValfOut_Pin GPIO_PIN_1
#define asagiValfOut_GPIO_Port GPIOB
#define yukariValfOut_Pin GPIO_PIN_2
#define yukariValfOut_GPIO_Port GPIOB
#define motorIkinciHizOut_Pin GPIO_PIN_10
#define motorIkinciHizOut_GPIO_Port GPIOB
#define motorOut_Pin GPIO_PIN_11
#define motorOut_GPIO_Port GPIOB
#define acilstopIn_Pin GPIO_PIN_12
#define acilstopIn_GPIO_Port GPIOB
#define yukaristartIn_Pin GPIO_PIN_13
#define yukaristartIn_GPIO_Port GPIOB
#define asagiStartIn_Pin GPIO_PIN_14
#define asagiStartIn_GPIO_Port GPIOB
#define devirmeyukariileriIn_Pin GPIO_PIN_15
#define devirmeyukariileriIn_GPIO_Port GPIOB
#define devirmeasagigeriIn_Pin GPIO_PIN_6
#define devirmeasagigeriIn_GPIO_Port GPIOC
#define kapiacIn_Pin GPIO_PIN_7
#define kapiacIn_GPIO_Port GPIOC
#define ustkapiacIn_Pin GPIO_PIN_8
#define ustkapiacIn_GPIO_Port GPIOC
#define tablakapiacIn_Pin GPIO_PIN_9
#define tablakapiacIn_GPIO_Port GPIOC
#define tablakapisiviciIn_Pin GPIO_PIN_8
#define tablakapisiviciIn_GPIO_Port GPIOA
#define kapiSiviciIn_Pin GPIO_PIN_15
#define kapiSiviciIn_GPIO_Port GPIOA
#define devirmeYukariLimitIn_Pin GPIO_PIN_10
#define devirmeYukariLimitIn_GPIO_Port GPIOC
#define devirmeAsagiLimitIn_Pin GPIO_PIN_11
#define devirmeAsagiLimitIn_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
