/*
 * LEDs.c
 *
 *  Created on: Feb 12, 2026
 *      Author: Amélie
 */


#include "LEDs.h"

extern UART_HandleTypeDef huart2;

led = 0;

void Led_blink(){
	HAL_Delay(250);
	led =1-led;
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, led);

}

void loop(void){
	Led_blink();
}
