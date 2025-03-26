/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "i2c.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "u8g2.h"
#include "u8g2_stm32.h"
#include "mui.h"

#include "ui_controls.h"

#include "UserActionPanel.h"
#include "MainViewController.h"

//#include "../../SSD1306/ssd1306.h"
//#include "../../SSD1306/ssd1306_fonts.h"

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
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
u8g2_t u8g2;
mui_t mui;

UserActionPanel userActionPanel;

uint8_t myMenuCallback(mui_t *ui, uint8_t msg) {
    if (msg == MUIF_MSG_DRAW) {
        u8g2_DrawStr(&u8g2, 10, 20, "Hello, MUI!");
    }
    return 0;
}

//mui_menu_entry_t menu[] = {
//    {1, "Start",  myMenuCallback},  // Пункт меню "Start"
//    {2, "Settings", myMenuCallback}, // "Settings"
//    {3, "About", myMenuCallback},   // "About"
//    {0, NULL, NULL} // Кінець меню (важливо!)
//};

//const mui_menu_entry_t main_menu[] = {
//  {MUI_MENU_HEADER, "Main Menu"},
//  {MUI_MENU_BUTTON, "Start", MUI_ACTION_GOTO, 1},
//  {MUI_MENU_BUTTON, "Settings", MUI_ACTION_GOTO, 2},
//  {MUI_MENU_BUTTON, "Exit", MUI_ACTION_EXIT, 0}
//};

uint8_t menu_list[] = { 1, 2, 3, 0 };

//uint8_t drawMenu(mui_t *ui, uint8_t msg) {
//    if (msg == MUIF_MSG_DRAW) {
//        switch (mui_GetCurrentFormId(ui)) {
//            case 1: mui_Draw(&mui, 10, 20, "Start"); break;
//            case 2: mui_DrawStr(&mui, 10, 40, "Settings"); break;
//            case 3: mui_DrawStr(&mui, 10, 60, "About"); break;
//        }
//    }
//    return 0;
//}

fds_t fds[] = {
    1,
    2,
	3
};

muif_t muif[] = {
    1,
    2,
	3
};

void u8g2_Init(void) {
	u8g2_Setup_ssd1306_i2c_128x32_univision_f(&u8g2, U8G2_R0, u8x8_byte_hw_i2c, u8x8_gpio_and_delay_stm32);
    u8g2_InitDisplay(&u8g2);
    u8g2_SetPowerSave(&u8g2, 0);
    u8g2_SetFont(&u8g2, u8g2_font_5x8_t_cyrillic);

    u8g2_ClearBuffer(&u8g2);
    u8g2_SendBuffer(&u8g2);


//    mui_Init(&mui, &u8g2, fds, muif, sizeof(muif) / sizeof(muif_t));
//    mui_Register(&mui, 0, myMenuCallback);
//    mui_ListInit(&mui, menu_list);
//    mui_GotoForm(&mui, 1, 0);

////    ssd1306_Init();
//
//
//    u8g2_DrawVLine(&u8g2, 0, 10, 20);
//    u8g2_DrawHLine(&u8g2, 0, 0, 20);
//    u8g2_SendBuffer(&u8g2);

//    ssd1306_SetCursor(5, 5);
//    ssd1306_WriteString("qwerty", Font_16x26, White);
//    ssd1306_UpdateScreen();
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
  MX_USART2_UART_Init();
  MX_I2C3_Init();
  /* USER CODE BEGIN 2 */
//  ssd1306_Init();
  u8g2_Init();
//  ssd1306_Line(10, 5, 108, 5, White);
//  ssd1306_UpdateScreen();


//  u8g2_ClearBuffer(&u8g2);
//  u8g2_SetFont(&u8g2, u8g2_font_ncenB08_tr);
//  u8g2_DrawStr(&u8g2, 10, 10, "Hello STM32!");
//  u8g2_SendBuffer(&u8g2);
//
//  u8g2_DrawHLine(&u8g2, 0, 0, 100);
//  u8g2_SendBuffer(&u8g2);

//  ssd1306_Line(10, 5, 108, 5, White);
//  ssd1306_UpdateScreen();

  MainViewController mainViewController = MainViewController(u8g2);
  userActionPanel.eventReciever = &mainViewController;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  mainViewController.update();

//	  u8g2_ClearBuffer(&u8g2);
//	  mui_Draw(&mui);
//	  u8g2_SendBuffer(&u8g2);

//	  u8g2_ClearBuffer(&u8g2);
////	  u8g2_SetDrawColor(&u8g2, 1);
//	  u8g2_DrawLine(&u8g2, 5, 5, 100, 5);
//	  u8g2_SetFont(&u8g2, u8g2_font_ncenB08_tr);
//	  u8g2_DrawStr(&u8g2, 0, 0, "Hello STM32!");
//	  u8g2_SendBuffer(&u8g2);

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
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
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
}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	userActionPanel.handleInterrupt(GPIO_Pin);
}

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
