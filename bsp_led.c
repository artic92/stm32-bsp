/*
 * bsp_led.c
 *
 *  Created on: 17 mag 2017
 *      Author: antonio
 */

#include "bsp_led.h"

void myBSP_LED_Init(uint16_t led_to_init)
{
	GPIO_InitTypeDef gpiod_init;

	gpiod_init.Pin = led_to_init;
	gpiod_init.Mode = GPIO_MODE_OUTPUT_PP;
	gpiod_init.Pull = GPIO_PULLUP;
	gpiod_init.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOD, &gpiod_init);
}

void myBSP_LED_deInit(uint16_t led_to_disable)
{
	HAL_GPIO_DeInit(GPIOD, led_to_disable);
}

void myBSP_LED_On(uint16_t on_led)
{
	HAL_GPIO_WritePin(GPIOD, on_led, GPIO_PIN_SET);
}

void myBSP_LED_Off(uint16_t off_led)
{
	HAL_GPIO_WritePin(GPIOD, off_led, GPIO_PIN_RESET);
}

void myBSP_LED_Toggle(uint16_t toggle_led)
{
	HAL_GPIO_TogglePin(GPIOD, toggle_led);
}
