#include "utils.h"
#include <stm32c0xx_hal.h>


uint8_t autoriser_clignotement = 1;

void setup(){
	set_leds();
	set_bouton();
}

void loop(){
	clignoter_led_bleue();
	action_bouton();
	if (autoriser_clignotement) {
		clignoter_led_verte();
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_11);
		HAL_Delay(250);
	} else {

		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
	}
}
