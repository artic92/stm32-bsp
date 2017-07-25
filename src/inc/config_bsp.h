/*
* @file config_bsp.h
* @brief Definizioni dipendenti dalla board
* @author: Antonio Riccio, Andrea Scognamiglio, Stefano Sorrentino
* @copyright
* Copyright 2017 Antonio Riccio <antonio.riccio.27@gmail.com>, <antonio.riccio9@studenti.unina.it>.
* This program is free software; you can redistribute it and/or modify it under the terms of the
* GNU General Public License as published by the
* Free Software Foundation; either version 3 of the License, or any later version.
* This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
* without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
* You should have received a copy of the GNU General Public License along with this program;
* if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*
*/
#ifndef SRC_CONFIG_H_
#define SRC_CONFIG_H_

#define BUTTON_PIN                      GPIO_PIN_0
#define BUTTON_GPIO_PORT                GPIOA
#define BUTTON_GPIO_CLK_ENABLE()        __HAL_RCC_GPIOA_CLK_ENABLE()
#define BUTTON_GPIO_CLK_DISABLE()       __HAL_RCC_GPIOA_CLK_DISABLE()
#define BUTTON_EXTI_IRQn                EXTI0_IRQn

#define LED3_PIN                        GPIO_PIN_13
#define LED4_PIN                        GPIO_PIN_12
#define LED5_PIN                        GPIO_PIN_14
#define LED6_PIN                        GPIO_PIN_15


#endif /* SRC_CONFIG_BSP_H_ */
