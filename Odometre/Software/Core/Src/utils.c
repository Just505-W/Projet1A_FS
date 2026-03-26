#include "utils.h"
#include "main.h"
#include <stm32c0xx_hal.h>

uint32_t last_led_tick = 0;
uint8_t led_state = 0;
uint8_t autoriser_clignotement = 1;

void setup(){
	set_leds();
	set_bouton();
}

void loop(){
	clignoter_led_bleue();
	action_bouton();
	if (autoriser_clignotement==1) {
		clignoter_led_verte();
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_11);
		HAL_Delay(250);
	} else {

		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
	}
}

/* Tout ce qui concerne les LEDs*/
void set_leds(){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
	HAL_Delay(250);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
	HAL_Delay(250);
}

void clignoter_led_bleue(){

	if (HAL_GetTick() - last_led_tick > 250) {
		led_state = !led_state;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, led_state);

		last_led_tick = HAL_GetTick();
	}
}
void clignoter_led_verte(){

	if (HAL_GetTick() - last_led_tick > 250) {
		led_state = !led_state;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, led_state);

		last_led_tick = HAL_GetTick();
	}
}



/* Tout ce qui concerne le bouton*/


void set_bouton(){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	HAL_Delay(250);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}

void action_bouton(){
	if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == GPIO_PIN_RESET) {
		autoriser_clignotement = !autoriser_clignotement; // On inverse l'autorisation
		HAL_Delay(200);
	}
}
