#include "stm32f4xx.h"
#include "usart.h"
#include "main.h"
extern TIM_HandleTypeDef htim1;
uint16_t cnt=0;
uint16_t rpt=0;
extern UART_HandleTypeDef huart1;
extern uint8_t rx_buffer[20];
uint8_t tx_buffer[20]={0};
uint8_t index=0;
uint8_t begin=0;
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

        for (uint8_t i=0; i<20; i++) {
            tx_buffer[i]=rx_buffer[i];
        }
        // for (uint8_t i=0; i<4; i++) {
        //     HAL_UART_Transmit_DMA(&huart7,tx_buffer+begin,1);
        //     begin++;
        //     if (begin>=20) {begin=0;}
        //
        // }
        HAL_UART_Transmit_DMA(&huart7,tx_buffer,4);
        HAL_UART_Receive_IT(&huart7,rx_buffer,4);
    }
}