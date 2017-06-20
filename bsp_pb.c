/*
 * bsp_pb.c
 *
 *  Created on: 17 mag 2017
 *      Author: antonio
 */

#include "bsp_pb.h"

void myBSP_PB_Init(int mode)
{
	GPIO_InitTypeDef gpioa_init;

	if(mode == BUTTON_MODE_POLLING){
		gpioa_init.Pin = GPIO_PIN_0;
		gpioa_init.Mode = GPIO_MODE_INPUT;
		gpioa_init.Pull = GPIO_NOPULL;
		gpioa_init.Speed = GPIO_SPEED_HIGH;
	}else{
		gpioa_init.Pin = GPIO_PIN_0;
		gpioa_init.Mode = GPIO_MODE_IT_RISING;
		gpioa_init.Pull = GPIO_NOPULL;
		gpioa_init.Speed = GPIO_SPEED_HIGH;

		HAL_NVIC_SetPriority(EXTI0_IRQn, 0xF, 0xF);
		HAL_NVIC_ClearPendingIRQ(EXTI0_IRQn);
		HAL_NVIC_EnableIRQ(EXTI0_IRQn);
	}

	HAL_GPIO_Init(GPIOA, &gpioa_init);
}

void myBSP_PB_deInit(){
	HAL_GPIO_DeInit(GPIOA, GPIO_PIN_0);
}

GPIO_PinState myBSP_PB_GetState()
{
	return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
}
