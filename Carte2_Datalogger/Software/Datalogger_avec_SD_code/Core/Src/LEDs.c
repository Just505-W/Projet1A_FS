/*
 * LEDs.c
 *
 *  Created on: Feb 12, 2026
 *      Author: Amélie
 */



led = 0;

while (1){
	HAL_Delay(250);
	led =1-led; //allume la led
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, led);

}


extern UART_HandleTypeDef huart2;

void loop(void){
	int led=0;
}
