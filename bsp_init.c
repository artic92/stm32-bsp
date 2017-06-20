/*
 * bsp_init.c
 *
 *  Created on: 18 mag 2017
 *      Author: antonio
 */

#include "stm32f4xx.h"

void HAL_MspInit(void)
{
	__GPIOA_CLK_ENABLE();
	__GPIOD_CLK_ENABLE();
}

void HAL_MspDeInit(void)
{
	__GPIOA_CLK_DISABLE();
	__GPIOD_CLK_DISABLE();
}
