/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stdio.h"
#define 	__RF24L01_TX_TEST__							//**@@ 如果测试发�?�功能则�?要定义该宏，如果测试接收则需要屏蔽该�? **@@//
//#define 	__USE_SOFT_SPI_INTERFACE__					//**@@ 如果使用软件SPI则需要定义该宏，反之如果使用硬件SPI则需要屏蔽该�? **@@//


/** 发�?�模式定�? */
enum
{
	TX_MODE_1 = 0,		//发�?�模�?1，发送固定的字符�?
	TX_MODE_2			//发�?�模�?2，发送串口接收到的数�?
};

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
#define LCD_SCLK_Pin GPIO_PIN_0
#define LCD_SCLK_GPIO_Port GPIOA
#define LCD_MOSI_Pin GPIO_PIN_1
#define LCD_MOSI_GPIO_Port GPIOA
#define LCD_RES_Pin GPIO_PIN_2
#define LCD_RES_GPIO_Port GPIOA
#define LCD_DC_Pin GPIO_PIN_3
#define LCD_DC_GPIO_Port GPIOA
#define LCD_BLK_Pin GPIO_PIN_4
#define LCD_BLK_GPIO_Port GPIOA
#define ZK_MOSI_Pin GPIO_PIN_5
#define ZK_MOSI_GPIO_Port GPIOA
#define LCD_CS_Pin GPIO_PIN_6
#define LCD_CS_GPIO_Port GPIOA
#define ZK_CS_Pin GPIO_PIN_7
#define ZK_CS_GPIO_Port GPIOA
#define select_Pin GPIO_PIN_13
#define select_GPIO_Port GPIOB
#define backward_Pin GPIO_PIN_14
#define backward_GPIO_Port GPIOB
#define forward_Pin GPIO_PIN_15
#define forward_GPIO_Port GPIOB
#define SPI1_NSS_Pin GPIO_PIN_15
#define SPI1_NSS_GPIO_Port GPIOA
#define SPI1_CE_Pin GPIO_PIN_6
#define SPI1_CE_GPIO_Port GPIOB
#define SPI1_IRT_Pin GPIO_PIN_7
#define SPI1_IRT_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
