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
 * This software component is licensed by ST under Ultimate Liberty license
 * SLA0044, the "License"; You may not use this file except in compliance with
 * the License. You may obtain a copy of the License at:
 *                             www.st.com/SLA0044
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
DAC_HandleTypeDef hdac;

ETH_HandleTypeDef heth;

UART_HandleTypeDef huart7;
UART_HandleTypeDef huart3;

PCD_HandleTypeDef hpcd_USB_OTG_FS;

/* Definitions for GreenLED */
osThreadId_t GreenLEDHandle;
const osThreadAttr_t GreenLED_attributes = {
  .name = "GreenLED",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
/* Definitions for BlueLED */
osThreadId_t BlueLEDHandle;
const osThreadAttr_t BlueLED_attributes = {
  .name = "BlueLED",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
/* Definitions for RedLED */
osThreadId_t RedLEDHandle;
const osThreadAttr_t RedLED_attributes = {
  .name = "RedLED",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
/* Definitions for Future */
osThreadId_t FutureHandle;
const osThreadAttr_t Future_attributes = {
  .name = "Future",
  .priority = (osPriority_t) osPriorityHigh,
  .stack_size = 128 * 4
};
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ETH_Init(void);
static void MX_USART3_UART_Init(void);
static void MX_USB_OTG_FS_PCD_Init(void);
static void MX_DAC_Init(void);
static void MX_UART7_Init(void);
void GreenLEDTask(void *argument);
void BlueLEDTask(void *argument);
void RedLEDTask(void *argument);
void FutureTask(void *argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_ETH_Init();
  MX_USART3_UART_Init();
  MX_USB_OTG_FS_PCD_Init();
  MX_DAC_Init();
  MX_UART7_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
	/* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
	/* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
	/* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of GreenLED */
  GreenLEDHandle = osThreadNew(GreenLEDTask, NULL, &GreenLED_attributes);

  /* creation of BlueLED */
  BlueLEDHandle = osThreadNew(BlueLEDTask, NULL, &BlueLED_attributes);

  /* creation of RedLED */
  RedLEDHandle = osThreadNew(RedLEDTask, NULL, &RedLED_attributes);

  /* creation of Future */
  FutureHandle = osThreadNew(FutureTask, NULL, &Future_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
	/* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Start scheduler */
  osKernelStart();
 
  /* We should never get here as control is now taken by the scheduler */
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

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief DAC Initialization Function
  * @param None
  * @retval None
  */
static void MX_DAC_Init(void)
{

  /* USER CODE BEGIN DAC_Init 0 */

  /* USER CODE END DAC_Init 0 */

  DAC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN DAC_Init 1 */

  /* USER CODE END DAC_Init 1 */
  /** DAC Initialization 
  */
  hdac.Instance = DAC;
  if (HAL_DAC_Init(&hdac) != HAL_OK)
  {
    Error_Handler();
  }
  /** DAC channel OUT1 config 
  */
  sConfig.DAC_Trigger = DAC_TRIGGER_NONE;
  sConfig.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
  if (HAL_DAC_ConfigChannel(&hdac, &sConfig, DAC_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN DAC_Init 2 */

  /* USER CODE END DAC_Init 2 */

}

/**
  * @brief ETH Initialization Function
  * @param None
  * @retval None
  */
static void MX_ETH_Init(void)
{

  /* USER CODE BEGIN ETH_Init 0 */

  /* USER CODE END ETH_Init 0 */

  /* USER CODE BEGIN ETH_Init 1 */

  /* USER CODE END ETH_Init 1 */
  heth.Instance = ETH;
  heth.Init.AutoNegotiation = ETH_AUTONEGOTIATION_ENABLE;
  heth.Init.PhyAddress = LAN8742A_PHY_ADDRESS;
  heth.Init.MACAddr[0] =   0x00;
  heth.Init.MACAddr[1] =   0x80;
  heth.Init.MACAddr[2] =   0xE1;
  heth.Init.MACAddr[3] =   0x00;
  heth.Init.MACAddr[4] =   0x00;
  heth.Init.MACAddr[5] =   0x00;
  heth.Init.RxMode = ETH_RXPOLLING_MODE;
  heth.Init.ChecksumMode = ETH_CHECKSUM_BY_HARDWARE;
  heth.Init.MediaInterface = ETH_MEDIA_INTERFACE_RMII;

  /* USER CODE BEGIN MACADDRESS */

  /* USER CODE END MACADDRESS */

  if (HAL_ETH_Init(&heth) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ETH_Init 2 */

  /* USER CODE END ETH_Init 2 */

}

/**
  * @brief UART7 Initialization Function
  * @param None
  * @retval None
  */
static void MX_UART7_Init(void)
{

  /* USER CODE BEGIN UART7_Init 0 */

  /* USER CODE END UART7_Init 0 */

  /* USER CODE BEGIN UART7_Init 1 */

  /* USER CODE END UART7_Init 1 */
  huart7.Instance = UART7;
  huart7.Init.BaudRate = 115200;
  huart7.Init.WordLength = UART_WORDLENGTH_8B;
  huart7.Init.StopBits = UART_STOPBITS_1;
  huart7.Init.Parity = UART_PARITY_NONE;
  huart7.Init.Mode = UART_MODE_TX_RX;
  huart7.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart7.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart7) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART7_Init 2 */

  /* USER CODE END UART7_Init 2 */

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief USB_OTG_FS Initialization Function
  * @param None
  * @retval None
  */
static void MX_USB_OTG_FS_PCD_Init(void)
{

  /* USER CODE BEGIN USB_OTG_FS_Init 0 */

  /* USER CODE END USB_OTG_FS_Init 0 */

  /* USER CODE BEGIN USB_OTG_FS_Init 1 */

  /* USER CODE END USB_OTG_FS_Init 1 */
  hpcd_USB_OTG_FS.Instance = USB_OTG_FS;
  hpcd_USB_OTG_FS.Init.dev_endpoints = 4;
  hpcd_USB_OTG_FS.Init.speed = PCD_SPEED_FULL;
  hpcd_USB_OTG_FS.Init.dma_enable = DISABLE;
  hpcd_USB_OTG_FS.Init.phy_itface = PCD_PHY_EMBEDDED;
  hpcd_USB_OTG_FS.Init.Sof_enable = ENABLE;
  hpcd_USB_OTG_FS.Init.low_power_enable = DISABLE;
  hpcd_USB_OTG_FS.Init.lpm_enable = DISABLE;
  hpcd_USB_OTG_FS.Init.vbus_sensing_enable = ENABLE;
  hpcd_USB_OTG_FS.Init.use_dedicated_ep1 = DISABLE;
  if (HAL_PCD_Init(&hpcd_USB_OTG_FS) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USB_OTG_FS_Init 2 */

  /* USER CODE END USB_OTG_FS_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(OUT_CMD_GPIO_Port, OUT_CMD_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LD1_Pin|LD3_Pin|LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(USB_PowerSwitchOn_GPIO_Port, USB_PowerSwitchOn_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : USER_Btn_Pin */
  GPIO_InitStruct.Pin = USER_Btn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USER_Btn_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : OUT_CMD_Pin */
  GPIO_InitStruct.Pin = OUT_CMD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(OUT_CMD_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LD1_Pin LD3_Pin LD2_Pin */
  GPIO_InitStruct.Pin = LD1_Pin|LD3_Pin|LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : USB_PowerSwitchOn_Pin */
  GPIO_InitStruct.Pin = USB_PowerSwitchOn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(USB_PowerSwitchOn_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : USB_OverCurrent_Pin */
  GPIO_InitStruct.Pin = USB_OverCurrent_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USB_OverCurrent_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : EXT_BTN1_Pin EXT_BTN2_Pin EXT_BTN3_Pin EXT_BTN4_Pin */
  GPIO_InitStruct.Pin = EXT_BTN1_Pin|EXT_BTN2_Pin|EXT_BTN3_Pin|EXT_BTN4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI4_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

}

/* USER CODE BEGIN 4 */
void send_Frame(int value_to_send){
	int LowTime = LOW_TIME;
	int HighTime = HIGH_TIME;
	if(value_to_send == 0){
		//		HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,0);
		for(int i =0 ; i <8 ;i++){
			HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T1);
			while(LowTime){
				LowTime--;
			}
			HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T0);
			while(HighTime){
				HighTime --;
			}
			HighTime =HIGH_TIME;
			LowTime =LOW_TIME;
		}

	}
	if(value_to_send == 1){
		//		HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,0);
		for(int i =0 ; i < 8;i++){
			HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T1);
			while(HighTime){
				HighTime--;
			}
			HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T0);
			while(LowTime){
				LowTime --;
			}
			HighTime =HIGH_TIME;
			LowTime =LOW_TIME;
		}
		//		HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,1);
	}
	//	HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T1);
	//	HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T0);

}

/* USER CODE END 4 */

/* USER CODE BEGIN Header_GreenLEDTask */
/**
 * @brief  Function implementing the GreenLED thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_GreenLEDTask */
void GreenLEDTask(void *argument)
{
  /* USER CODE BEGIN 5 */
	/* Infinite loop */
	for(;;)
	{
		//		send_One();

		send_Frame(0);
		send_Frame(1);
		send_Frame(0);
		//		HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T1);
		//		HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T0);
		//		osDelay(250);
		send_Frame(0);
		send_Frame(1);
		send_Frame(0);

		send_Frame(0);
		send_Frame(1);
		send_Frame(0);
		HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T1);
		HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T0);
		osDelay(250);
		send_Frame(0);
		send_Frame(0);
		send_Frame(0);
		//		osDelay(250);
		send_Frame(0);
		send_Frame(1);
		send_Frame(0);

		send_Frame(0);
		send_Frame(1);
		send_Frame(0);

		HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T1);
		HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T0);
		osDelay(250);

		send_Frame(0);
		send_Frame(1);
		send_Frame(0);
		//		HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T1);
		//		HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T0);
		//		osDelay(250);
		send_Frame(0);
		send_Frame(0);
		send_Frame(0);

		send_Frame(0);
		send_Frame(1);
		send_Frame(0);
		HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T1);
		HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T0);
		osDelay(250);

		send_Frame(0);
		send_Frame(1);
		send_Frame(0);
		//		HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T1);
		//		HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T0);
		//		osDelay(250);
		send_Frame(0);
		send_Frame(1);
		send_Frame(0);

		send_Frame(0);
		send_Frame(0);
		send_Frame(0);
		HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T1);
		HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T0);
		osDelay(250);

		send_Frame(0);
		send_Frame(1);
		send_Frame(0);
		//		HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T1);
		//		HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T0);
		//		osDelay(250);
		send_Frame(0);
		send_Frame(0);
		send_Frame(0);

		send_Frame(0);
		send_Frame(1);
		send_Frame(0);
		HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T1);
		HAL_GPIO_WritePin(OUT_CMD_GPIO_Port,OUT_CMD_Pin,T0);


		osDelay(250);
		//		osDelay(50);
		//		send_Frame(0);
		//		osDelay(50);

		//		if(HAL_GPIO_ReadPin(USER_Btn_GPIO_Port,USER_Btn_Pin)){
		//			HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
		//			osDelay(4000);

	}
	//		osDelay(1);
	//}
  /* USER CODE END 5 */ 
}

/* USER CODE BEGIN Header_BlueLEDTask */
/**
 * @brief Function implementing the BlueLED thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_BlueLEDTask */
void BlueLEDTask(void *argument)
{
  /* USER CODE BEGIN BlueLEDTask */
	/* Infinite loop */
		 char* message = "GnuDeLamotte\n\r";
	for(;;)
	{
		//		if(state_BTN_BLINK == 1){
		HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
		HAL_UART_Transmit(&huart7,(uint8_t*)message,15,100);
		//		HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
		//		HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
		//		}
		////		HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
		//		HAL_Delay(250);

		osDelay(1);
	}

  /* USER CODE END BlueLEDTask */
}

/* USER CODE BEGIN Header_RedLEDTask */
/**
 * @brief Function implementing the RedLED thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_RedLEDTask */
void RedLEDTask(void *argument)
{
  /* USER CODE BEGIN RedLEDTask */
	/* Infinite loop */
	for(;;)
	{
		//		HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
		//		HAL_Delay(166);

		osDelay(1);
	}
  /* USER CODE END RedLEDTask */
}

/* USER CODE BEGIN Header_FutureTask */
/**
 * @brief Function implementing the Future thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_FutureTask */
void FutureTask(void *argument)
{
  /* USER CODE BEGIN FutureTask */
	/* Infinite loop */
	for(;;)
	{
		osDelay(1);
		//		HAL_Delay(1);
	}
  /* USER CODE END FutureTask */
}

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