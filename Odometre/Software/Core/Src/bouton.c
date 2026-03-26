#include "bouton.h"
#include <stm32c0xx_hal.h>
#include <stdint.h>


uint8_t autoriser_clignotement = 1;

void set_bouton(){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	HAL_Delay(250);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}

void action_bouton(){
	if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == GPIO_PIN_RESET) {
		autoriser_clignotement = !autoriser_clignotement; // On inverse l'autorisation
		HAL_Delay(200); // Anti-rebond (Debounce) rapide pour éviter les faux clics
	}
}
