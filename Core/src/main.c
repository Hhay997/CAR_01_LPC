/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "rtc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd_init.h"
#include "lcd.h"
#include "lcd_front.h"
#include "delay.h"
#include "alternating.h"
#include "spi01.h"
#include "stdint.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

unsigned char date_r[8]={0};
unsigned char date_w[8]={0};
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
int LCD_FLAG=0;
int POTECT_FLAG=0;
unsigned char BUF[150]={0};



/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */




HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	LCD_FLAG++;
	POTECT_FLAG++;
	if(htim==(&htim1))
	{
		if(LCD_FLAG==2)//周期200ms
		{

		//	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port,SPI1_NSS_Pin,1);
			HAL_SPI_Receive_DMA(&hspi1,date_r,8);
			//HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port,SPI1_NSS_Pin,0);
			//date_r[0]=L01_ReadSingleReg(0x50);
			uint8_t date[1]={0x02};
			  uint8_t input=0x03;
				  //HAL_SPI_Transmit(&hspi1,&input,1,1000);
				  L01_ReadSingleReg(input);
			LCD_ShowString(0,0,"                     ",WHITE,BLACK,24,0);//清行代码
			LCD_ShowIntNum(40,0,date_r[0],3,WHITE,BLACK,24);
			delay_ms(10);

			LCD_ShowString(0,30,"                     ",WHITE,BLACK,24,0);//清行代码
			LCD_ShowIntNum(40,30,date_r[1],3,WHITE,BLACK,24);
			delay_ms(10);

			LCD_ShowString(0,60,"                     ",WHITE,BLACK,24,0);//清行代码
			LCD_ShowIntNum(40,60,date_r[2],3,WHITE,BLACK,24);
			delay_ms(10);

			/*LCD_ShowString(0,90,"                     ",WHITE,BLACK,24,0);//清行代码
			LCD_ShowIntNum(40,90,date_r[3],3,WHITE,BLACK,24);
			delay_ms(100);

			LCD_ShowString(0,120,"                     ",WHITE,BLACK,24,0);//清行代码
			LCD_ShowIntNum(40,120,date_r[4],3,WHITE,BLACK,24);
			delay_ms(100);

			LCD_ShowString(0,150,"                     ",WHITE,BLACK,24,0);//清行代码
			LCD_ShowIntNum(40,150,date_r[5],3,WHITE,BLACK,24);
			delay_ms(100);

			LCD_ShowString(0,180,"                     ",WHITE,BLACK,24,0);//清行代码
			LCD_ShowIntNum(40,180,date_r[6],3,WHITE,BLACK,24);
			delay_ms(100);

			LCD_ShowString(0,210,"                     ",WHITE,BLACK,24,0);//清行代码
			LCD_ShowIntNum(40,210,date_r[7],3,WHITE,BLACK,24);


			delay_ms(100);

	//	SYS_DEFEND(BUF);

			LCD_FLAG=0;
		}
		//delay_ms(10000);
		if(POTECT_FLAG==10)//周期10ms
		{
			Ptotect();
			POTECT_FLAG=0;
		}
	}
}




/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_RTC_Init();
  MX_USART3_UART_Init();
  MX_TIM1_Init();
  MX_USART1_UART_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */
  LCD_Init();
  LCD_Fill(0,0,LCD_W,LCD_H,BLACK );
  L01_CE_HIGH();
  L01_CSN_LOW();
	HAL_GPIO_WritePin(SPI1_CE_GPIO_Port,SPI1_CE_Pin,1);
  HAL_TIM_Base_Start_IT(&htim1);





  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
