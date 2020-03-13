/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
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
#include "i2c.h"
#include "usart.h"
#include "gpio.h"
#include "lcd.h"
#include "ringbuffer_dma.h"
#include "BMP280.h"
#include <string.h>
/* Private includes ----------------------------------------------------------*/
RingBuffer_DMA ring;
/* USER CODE BEGIN Includes */
#define BUF_SIZE  4096
//A**RRAY FOR RING
uint8_t rx[BUF_SIZE];
uint32_t rx_count;
//A**RRAY FOR COMMAND
uint8_t command[BUF_SIZE];
uint8_t icmd = 0;
//*** BMP280
double temp, press, alt;
int8_t com_rslt;
#define QNH 1005

/* ESP8266 variables */
#define SERVER_PORT     "8888"
#define SERVER_ADD		"192.168.31.55"
#define SERVER_TOK		"restoration1"				// At least 10 symbols
#define WIFI_SSID		    "TechMaker"//"kofein"
#define WIFI_PASS			"#techmaker#"//"speciality"
//**UART_COMMAND
char uart_co[256];

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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void UART_R(){
	rx_count = RingBuffer_DMA_Count(&ring);
    while(rx_count --){
    	uint8_t byte = RingBuffer_DMA_GetByte(&ring);
    	if(byte == '\n'){
    		command[icmd] = 0;
    		icmd = 0 ;
    		LCD_Printf("%s \n", command);
    		continue;
    	}
    	else if (byte == '\r') {
    		//LCD_Printf("trying to get information \n");
            continue;
    	}
    	else{
    		command[icmd++ % BUF_SIZE] = byte;
    	}
    }
}
//void UART_R();
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
  MX_DMA_Init();
  MX_UART4_Init();
  MX_I2C1_Init();
  LCD_Init();

  /* USER CODE BEGIN 2 */
  //R***ING buffer in.
  RingBuffer_DMA_Init(&ring , huart4.hdmarx , rx , BUF_SIZE);
  //U***ART recieving DMA
  HAL_UART_Receive_DMA(&huart4, rx, BUF_SIZE);
  //B***MP280
  LCD_Printf("Connecting to BMP280...\n");
  	bmp280_t bmp280 = {.i2c_handle = &hi2c1};
  	com_rslt = BMP280_init(&bmp280);
  	com_rslt += BMP280_set_power_mode(BMP280_NORMAL_MODE);
  	com_rslt += BMP280_set_work_mode(BMP280_STANDARD_RESOLUTION_MODE);
  	com_rslt += BMP280_set_standby_durn(BMP280_STANDBY_TIME_1_MS);
  	if (com_rslt != SUCCESS) {
  		LCD_Printf("Check BMP280 connection!\nProgram terminated");
  		return 0;
  	}
  	LCD_Printf("Connection successful!\n");
  ///*** CONNECTING TO THE ROUTER
    //##ping
  sprintf(uart_co, "AT+RST\r\n");
  HAL_UART_Transmit(&huart4, (uint8_t * )uart_co, strlen(uart_co), HAL_MAX_DELAY);
  HAL_Delay(300);
  UART_R();
    //##Turn on message echo
  sprintf(uart_co, "ATE1\r\n");
  HAL_UART_Transmit(&huart4, (uint8_t *)uart_co, strlen(uart_co), HAL_MAX_DELAY);
  HAL_Delay(100);
  UART_R();
    //##Display version info
  sprintf(uart_co, "AT+GMR\r\n");
  HAL_UART_Transmit(&huart4, (uint8_t *)uart_co, strlen(uart_co), HAL_MAX_DELAY);
  HAL_Delay(500);
  UART_R();
    //##Set to client mode
  sprintf(uart_co, "AT+CWMODE_CUR=1\r\n");
  HAL_UART_Transmit(&huart4, (uint8_t *)uart_co, strlen(uart_co), HAL_MAX_DELAY);
  HAL_Delay(100);
  UART_R();
  HAL_Delay(2000);
    //##Connect to network
  sprintf(uart_co, "AT+CWJAP_CUR=\"%s\",\"%s\"\r\n", WIFI_SSID, WIFI_PASS);
  HAL_UART_Transmit(&huart4, (uint8_t *)uart_co, strlen(uart_co), HAL_MAX_DELAY);
  HAL_Delay(10000);
  UART_R();
    //##Check for IP
  sprintf(uart_co, "AT+CIFSR\r\n");
  HAL_UART_Transmit(&huart4, (uint8_t *)uart_co, strlen(uart_co), HAL_MAX_DELAY);
  HAL_Delay(5000);
  UART_R();
  /* USER CODE END 2 */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1){
	  /* Get BMP280 data */
     BMP280_read_temperature_double(&temp);
	 BMP280_read_pressure_double(&press);
	 alt = BMP280_calculate_altitude(QNH*100);
	 //***REQUEST for sending
	 char rq[256];
	 sprintf(rq,"&temp=%.1f&press=%.0f %.1f HTTP/1.1\r\nHost: %s\r\n\r\n", temp, press, alt, SERVER_ADD);
	 //***CONNECTING to the server
		sprintf(uart_co, "AT+CIPSTART=\"TCP\",\"%s\",%s\r\n", SERVER_ADD , SERVER_PORT);
		HAL_UART_Transmit(&huart4, (uint8_t *)uart_co, strlen(uart_co), 1000);
		HAL_Delay(10000);
		UART_R();
	//*** send length to
		sprintf(uart_co, "AT+CIPSEND=%d\r\n", strlen(rq));
				HAL_UART_Transmit(&huart4, (uint8_t *)uart_co, strlen(uart_co), HAL_MAX_DELAY);
				HAL_Delay(200); // wait for ">"
				UART_R();
	///***Send data
	   HAL_UART_Transmit(&huart4, (uint8_t *)rq, strlen(rq), 1000);
	   HAL_Delay(1800);
	   UART_R();
	///***Disconnect from server */
	    sprintf(uart_co, "AT+CIPCLOSE\r\n");
		HAL_UART_Transmit(&huart4, (uint8_t *)uart_co, strlen(uart_co), 1000);
		HAL_Delay(1000);
		UART_R();

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}
// UART_+++++++++___/__/

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
  RCC_OscInitStruct.PLL.PLLN = 180;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Activate the Over-Drive mode 
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
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
