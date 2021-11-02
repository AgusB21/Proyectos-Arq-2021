//Punto 2 Agustin Baigorria MUN:01513

#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_def.h"

#pragma GCC diagnostic push

void main() {
        HAL_Init();

        Init_GPIO_LEDS();

      while (1) {
	              HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, SET);
	              HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
	              HAL_Delay(100);
        }
}

void SysTick_Handler(void) {
    HAL_IncTick();
}

void Init_GPIO_LEDS() {
                        GPIO_InitTypeDef GPIO_InitStruct = {0};
                          __HAL_RCC_GPIOD_CLK_ENABLE();
                          __HAL_RCC_GPIOA_CLK_ENABLE();

                           GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
                           GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
                           GPIO_InitStruct.Pull = GPIO_PULLDOWN;
                           GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

                        HAL_GPIO_Init(GPIOD,&GPIO_InitStruct);

                           GPIO_InitStruct.Pin = GPIO_PIN_0;
                           GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
                           GPIO_InitStruct.Pull = GPIO_NOPULL;

                        HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);
}

#pragma GCC diagnostic pop
