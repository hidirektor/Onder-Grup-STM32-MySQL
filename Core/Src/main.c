/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "main.h"
#include "stdio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include <stdlib.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
char esp_data[100]; // ESP8266 ile iletişim için veri tamponu

// Veritabanı bilgileri
char* db_ip = "89.252.138.99";
uint16_t db_port = 3306;
char* db_name = "hidirekt_ondergrup";
char* db_user = "hidirekt_onder";
char* db_password = "!2(l;cR4TBQG";

// LED pinleri
GPIO_TypeDef* led_gpio_port = GPIOB;
uint16_t green_led_pin = GPIO_PIN_6;
uint16_t red_led_pin = GPIO_PIN_5;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */
void ESP8266_Init(void);
void ESP8266_SendData(char* data);
void CheckDatabase(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void ESP8266_Init(void)
{
  HAL_UART_Transmit(&huart1, (uint8_t*)"AT+RST\r\n", 8, HAL_MAX_DELAY); // ESP8266'nın sıfırlanması
  HAL_Delay(2000); // 2 saniye bekleme

  HAL_UART_Transmit(&huart1, (uint8_t*)"AT+CWMODE=1\r\n", 13, HAL_MAX_DELAY); // WiFi modunun istemci moduna ayarlanması
  HAL_Delay(1000); // 1 saniye bekleme

  char connect_cmd[100];
  sprintf(connect_cmd, "AT+CWJAP=\"%s\",\"%s\"\r\n", "Wifi Name", "Password"); // WiFi ağına bağlantı
  HAL_UART_Transmit(&huart1, (uint8_t*)connect_cmd, strlen(connect_cmd), HAL_MAX_DELAY);
   HAL_Delay(7000); // 7 saniye bekleme

   HAL_UART_Transmit(&huart1, (uint8_t*)"AT+CIPMUX=0\r\n", 13, HAL_MAX_DELAY); // Bağlantı noktası çoklu modunun devre dışı bırakılması
   HAL_Delay(1000); // 1 saniye bekleme

   HAL_UART_Transmit(&huart1, (uint8_t*)"AT+CIPSTART=\"TCP\",\"", 20, HAL_MAX_DELAY);
   HAL_UART_Transmit(&huart1, (uint8_t*)db_ip, strlen(db_ip), HAL_MAX_DELAY); // Veritabanına TCP bağlantısı
   HAL_UART_Transmit(&huart1, (uint8_t*)"\",", 2, HAL_MAX_DELAY);
   char db_port_str[6];
   sprintf(db_port_str, "%d", db_port);
   HAL_UART_Transmit(&huart1, (uint8_t*)db_port_str, strlen(db_port_str), HAL_MAX_DELAY); // Bağlantı noktası
   HAL_UART_Transmit(&huart1, (uint8_t*)"\r\n", 2, HAL_MAX_DELAY);
   HAL_Delay(3000); // 3 saniye bekleme
 }

 void ESP8266_SendData(char* data)
 {
   HAL_UART_Transmit(&huart1, (uint8_t*)"AT+CIPSEND=", 11, HAL_MAX_DELAY);
   char data_length_str[6];
   sprintf(data_length_str, "%d", strlen(data));
   HAL_UART_Transmit(&huart1, (uint8_t*)data_length_str, strlen(data_length_str), HAL_MAX_DELAY); // Veri uzunluğu
   HAL_UART_Transmit(&huart1, (uint8_t*)"\r\n", 2, HAL_MAX_DELAY);
   HAL_Delay(2000); // 2 saniye bekleme
   HAL_UART_Transmit(&huart1, (uint8_t*)data, strlen(data), HAL_MAX_DELAY); // Veri gönderme
   HAL_Delay(3000); // 3 saniye bekleme
 }

 void CheckDatabase(void)
 {
   HAL_UART_Transmit(&huart1, (uint8_t*)"AT+CIPSEND=4\r\n", 14, HAL_MAX_DELAY);
   HAL_Delay(2000); // 2 saniye bekleme
   HAL_UART_Transmit(&huart1, (uint8_t*)"PING\r\n", 6, HAL_MAX_DELAY); // Veritabanı bağlantısını kontrol etmek için PING gönderme
   HAL_Delay(3000); // 3 saniye bekleme

   HAL_UART_Receive_IT(&huart1, (uint8_t*)esp_data, 100); // ESP8266'dan gelen yanıtı almak için UART kesmesini başlatma
 }

 int main(void)
 {
   HAL_Init();

   SystemClock_Config();

   MX_GPIO_Init();
   MX_USART1_UART_Init();
   MX_USART2_UART_Init();

   ESP8266_Init(); // ESP8266'nın başlatılması

   while (1)
   {
     CheckDatabase(); // Veritabanını kontrol etme

     // LED'leri kontrol etme
     if (strstr(esp_data, "LED_ON")) // ESP8266'dan gelen yanıtta "LED_ON" ifadesini arama
     {
       HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); // LED'i açma
       ESP8266_SendData("LED is ON\r\n"); // Yanıt olarak "LED is ON" gönderme
     }
     else if (strstr(esp_data, "LED_OFF")) // ESP8266'dan gelen yanıtta "LED_OFF" ifadesini arama
     {
       HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); // LED'i kapatma
       ESP8266_SendData("LED is OFF\r\n"); // Yanıt olarak "LED is OFF" gönderme
     }

     memset(esp_data, 0, sizeof(esp_data)); // esp_data dizisini sıfırlama

     HAL_Delay(100); // 100 ms bekleme
   }
 }

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, redLed_Pin|greenLed_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : redLed_Pin greenLed_Pin */
  GPIO_InitStruct.Pin = redLed_Pin|greenLed_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
