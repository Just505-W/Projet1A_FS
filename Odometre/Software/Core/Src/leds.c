#include "leds.h"
#include <stdint.h>
#include <stm32c0xx_hal.h>


uint32_t last_led_tick = 0;
uint8_t led_state = 0;


void set_leds(){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
	HAL_Delay(250);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
	HAL_Delay(250);
}

void clignoter_leds(){

	if (HAL_GetTick() - last_led_tick > 250) {
		led_state = !led_state;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, led_state);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, !led_state);

		last_led_tick = HAL_GetTick();
	}
}
