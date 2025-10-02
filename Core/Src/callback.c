#include "stm32f4xx.h"
#include "usart.h"
#include "main.h"
extern TIM_HandleTypeDef htim1;
uint16_t cnt=0;
uint16_t rpt=0;
extern UART_HandleTypeDef huart1;
extern uint8_t rx_buffer[4];
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
if (htim == &htim1)
    {
        cnt++;
			rpt++;
        if (cnt>1000)cnt=0;
        __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,cnt);
    }
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart==&huart7) {
        if (rx_buffer[0]=='R')
        {HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);}
        else if (rx_buffer[0]=='M')
        {HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET);}
        HAL_UART_Receive_IT(&huart7,rx_buffer,1);
    }
}