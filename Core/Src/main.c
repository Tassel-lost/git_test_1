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
#include "iwdg.h"
#include "tim.h"
#include "gpio.h"

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

/* USER CODE BEGIN PV */
uint32_t tick=0;
// 单位Hz
// enum PitchFrequency : uint32_t {
//     A0 = 27, // A0
//     A0S = 29, // A#0
//     B0 = 31, // B0
//     C1 = 33, // C1
//     C1S = 35, // C#1
//     D1F = 35, // Db1
//     D1 = 37, // D1
//     D1S = 39, // D#1
//     E1F = 39, // Eb1
//     E1 = 41, // E1
//     F1 = 44, // F1
//     F1S = 46, // F#1
//     G1F = 46, // Gb1
//     G1 = 49, // G1
//     G1S = 52, // G#1
//     A1F = 52, // Ab1
//     A1 = 55, // A1
//     A1S = 58, // A#1
//     B1F = 58, // Bb1
//     B1 = 62, // B1
//     C2 = 65, // C2
//     C2S = 69, // C#2
//     D2F = 69, // Db2
//     D2 = 73, // D2
//     D2S = 78, // D#2
//     E2F = 78, // Eb2
//     E2 = 82, // E2
//     F2 = 87, // F2
//     F2S = 92, // F#2
//     G2F = 92, // Gb2
//     G2 = 98, // G2
//     G2S = 103, // G#2
//     A2F = 103, // Ab2
//     A2 = 110, // A2
//     A2S = 117, // A#2
//     B2F = 117, // Bb2
//     B2 = 123, // B2
//     C3 = 130, // C3
//     C3S = 138, // C#3
//     D3F = 138, // Db3
//     D3 = 146, // D3
//     D3S = 155, // D#3
//     E3F = 155, // Eb3
//     E3 = 164, // E3
//     F3 = 174, // F3
//     F3S = 185, // F#3
//     G3F = 185, // Gb3
//     G3 = 196, // G3
//     G3S = 208, // G#3
//     A3F = 208, // Ab3
//     A3 = 220, // A3
//     A3S = 233, // A#3
//     B3F = 233, // Bb3
//     B3 = 247, // B3
//     C4 = 261, // Middle C (C4)
//     C4S = 277, // C#4
//     D4F = 277, // Db4
//     D4 = 293, // D4
//     D4S = 311, // D#4
//     E4F = 311, // Eb4
//     E4 = 329, // E4
//     F4 = 349, // F4
//     F4S = 370, // F#4
//     G4F = 370, // Gb4
//     G4 = 392, // G4
//     G4S = 415, // G#4
//     A4F = 415, // Ab4
//     A4 = 440, // A4 (Tuning pitch)
//     A4S = 466, // A#4
//     B4F = 466, // Bb4
//     B4 = 493, // B4
//     C5 = 523, // C5
//     C5S = 554, // C#5
//     D5F = 554, // Db5
//     D5 = 587, // D5
//     D5S = 622, // D#5
//     E5F = 622, // Eb5
//     E5 = 659, // E5
//     F5 = 698, // F5
//     F5S = 740, // F#5
//     G5F = 740, // Gb5
//     G5 = 784, // G5
//     G5S = 831, // G#5
//     A5F = 831, // Ab5
//     A5 = 880, // A5
//     A5S = 932, // A#5
//     B5F = 932, // Bb5
//     B5 = 987, // B5
//     C6 = 1046, // C6
//     C6S = 1109, // C#6
//     D6F = 1109, // Db6
//     D6 = 1175, // D6
//     D6S = 1245, // D#6
//     E6F = 1245, // Eb6
//     E6 = 1319, // E6
//     F6 = 1397, // F6
//     F6S = 1480, // F#6
//     G6F = 1480, // Gb6
//     G6 = 1568, // G6
//     G6S = 1661, // G#6
//     A6F = 1661, // Ab6
//     A6 = 1760, // A6
//     A6S = 1865, // A#6
//     B6F = 1865, // Bb6
//     B6 = 1976, // B6
//     C7 = 2093, // C7
//     C7S = 2217, // C#7
//     D7F = 2217, // Db7
//     D7 = 2349, // D7
//     D7S = 2489, // D#7
//     E7F = 2489, // Eb7
//     E7 = 2637, // E7
//     F7 = 2794, // F7
//     F7S = 2960, // F#7
//     G7F = 2960, // Gb7
//     G7 = 3136, // G7
//     G7S = 3322, // G#7
//     A7F = 3322, // Ab7
//     A7 = 3520, // A7
//     A7S = 3729, // A#7
//     B7F = 3729, // Bb7
//     B7 = 3951, // B7
//     C8 = 4186, // C8
//     C8S = 4435, // C#8
//     D8F = 4435, // Db8
//     D8 = 4699, // D8
//     D8S = 4978, // D#8
//     E8F = 4978, // Eb8
//     E8 = 5274, // E8
//     F8 = 5588, // F8
//     F8S = 5919, // F#8
//     G8F = 5919, // Gb8
//     G8 = 6272, // G8
//     G8S = 6645, // G#8
//     A8F = 6645, // Ab8
//     A8 = 7040, // A8
//     A8S = 7459, // A#8
//     B8F = 7459, // Bb8
//     B8 = 7902, // B8
//     C9 = 8372, // C9
//     C9S = 8870, // C#9
//     D9F = 8870, // Db9
//     D9 = 9397, // D9
//     D9S = 9956, // D#9
//     E9F = 9956, // Eb9
//     E9 = 10548, // E9
//     F9 = 11175, // F9
//     F9S = 11840, // F#9
//     G9F = 11840, // Gb9
//     G9 = 12544, // G9
//     G9S = 13289, // G#9
//     A9F = 13289, // Ab9
//     A9 = 14080, // A9
//     A9S = 14917, // A#9
//     B9F = 14917, // Bb9
//     B9 = 15804, // B9
//     C10 = 16744 // C10
// };
// struct MusicNote {
//   uint16_t tune; // unit: Hz
//   float beat;
// };
// inline MusicNote music_haruhikage_notes[] = {
//   { E6, 1 }, { D6, 0.5 }, { C6, 1 }, { D6, 0.5 }, { E6, 0.75 }, { F6, 0.25 }, { E6, 0.5 }, { D6, 1.5 },
// };
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
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
  MX_TIM1_Init();
  MX_TIM12_Init();
  //MX_IWDG_Init();
  /* USER CODE BEGIN 2 */
  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET);
  HAL_TIM_Base_Start(&htim1);
  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
  __HAL_TIM_ENABLE_IT(&htim1,TIM_IT_UPDATE);
  //HAL_TIM_PWM_Start(&htim12,TIM_CHANNEL_1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

    tick=HAL_GetTick();
    // for (int i=0;i<10000;i+=200) {
    //   __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,i);
    //   if (HAL_GPIO_ReadPin(S1_GPIO_Port,S1_Pin)) {HAL_IWDG_Refresh(&hiwdg);}
    //   HAL_Delay(200);
    // }
    // for (int i=0;i<10000;i+=200) {
    //   __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,10000-i);
    //   if (HAL_GPIO_ReadPin(S1_GPIO_Port,S1_Pin)) {HAL_IWDG_Refresh(&hiwdg);}
    //   HAL_Delay(200);
    // }


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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 6;
  RCC_OscInitStruct.PLL.PLLN = 180;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
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

  /** Initializes the CPU, AHB and APB buses clocks
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
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
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
