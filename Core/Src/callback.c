#include "stm32f4xx.h"
extern TIM_HandleTypeDef htim1;
uint16_t cnt=0;
uint16_t rpt=0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
if (htim == &htim1)
    {
        cnt++;
			rpt++;
        if (cnt>1000)cnt=0;
        __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,cnt);
    }
}