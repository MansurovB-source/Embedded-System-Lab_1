#include "hal.h"

int delay = 500;
unsigned int leds_num[] = {GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5,
                      GPIO_PIN_6, GPIO_PIN_8, GPIO_PIN_9,
                      GPIO_PIN_11, GPIO_PIN_12};
					  
GPIO_PinState state = GPIO_PIN_SET;
					  
void status(GPIO_PinState state) {
	//HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_15);
	state = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15);
	while(state == GPIO_PIN_RESET) {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
		HAL_Delay(50);
		state = (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15)); // read nBTN
		if(state == GPIO_PIN_RESET) {
			state = GPIO_PIN_SET;
		} else {
			state = GPIO_PIN_RESET;
		}
	}
		
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
	//HAL_Delay(delay);
}

void led(GPIO_PinState led_1, GPIO_PinState led_2, GPIO_PinState led_3, GPIO_PinState led_4, GPIO_PinState led_5, GPIO_PinState led_6, GPIO_PinState led_7, GPIO_PinState led_8) {
	state = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15);	
	HAL_GPIO_WritePin(GPIOD, leds_num[0], led_1);
	status(state);
	HAL_GPIO_WritePin(GPIOD, leds_num[1], led_2);
	status(state);
	HAL_GPIO_WritePin(GPIOD, leds_num[2], led_3);
	status(state);
	HAL_GPIO_WritePin(GPIOD, leds_num[3], led_4);
	status(state);
	HAL_GPIO_WritePin(GPIOD, leds_num[4], led_5);
	status(state);
	HAL_GPIO_WritePin(GPIOD, leds_num[5], led_6);
	status(state);
	HAL_GPIO_WritePin(GPIOD, leds_num[6], led_7);
	status(state);
	HAL_GPIO_WritePin(GPIOD, leds_num[7], led_8);
	status(state);
	HAL_Delay(delay);
}

int umain() {
    unsigned int sw_num[] = {GPIO_PIN_4, GPIO_PIN_8, GPIO_PIN_10, GPIO_PIN_12};
	
	while(true) {

	GPIO_PinState state_1 = HAL_GPIO_ReadPin(GPIOE, sw_num[0]);
    GPIO_PinState state_2 = HAL_GPIO_ReadPin(GPIOE, sw_num[1]);
    GPIO_PinState state_3 = HAL_GPIO_ReadPin(GPIOE, sw_num[2]);
    GPIO_PinState state_4 = HAL_GPIO_ReadPin(GPIOE, sw_num[3]);
	
	if(state_1 == GPIO_PIN_RESET && state_2 == GPIO_PIN_SET  && state_3 == GPIO_PIN_RESET && state_4 == GPIO_PIN_RESET) {
		
		led(GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_SET);
		led(GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_RESET);
		led(GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET);
		led(GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET);
		led(GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_RESET);
		led(GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_SET);
		led(GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_RESET);
		led(GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET);
		led(GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET);
		led(GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET);
		led(GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET);
		led(GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_RESET);
		
	} else {
		{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
		}
		
		{
		HAL_GPIO_WritePin(GPIOD, leds_num[0], state_1);
		HAL_GPIO_WritePin(GPIOD, leds_num[1], state_2);
		HAL_GPIO_WritePin(GPIOD, leds_num[2], state_3);
		HAL_GPIO_WritePin(GPIOD, leds_num[3], state_4);
		HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
		}
	}
	
	}
}