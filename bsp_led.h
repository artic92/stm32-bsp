/**
* @file bsp_led.h
* @brief Definisce un board support package per la gestione dei LED.
* @author: Antonio Riccio, Andrea Scognamiglio, Stefano Sorrentino
* @copyright
* Copyright 2017 Antonio Riccio <antonio.riccio.27@gmail.com>, <antonio.riccio9@studenti.unina.it>
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
* @addtogroup LED
* @{
*
* @details
*   API che definiscono un basic support package per l'utilizzo dei LED su stm32.
*   Questa libreria fa uso degli HAL drivers offerti dell'ST.
*
*/
#ifndef BSP_LED_H_
#define BSP_LED_H_

/***************************** Include Files *********************************/
#include "stm32f4xx.h"

/************************** Constant Definitions *****************************/
/**
 * @name Definizioni dei pin
 * @{
 */
#define LED0 GPIO_PIN_12
#define LED1 GPIO_PIN_13
#define LED2 GPIO_PIN_14
#define LED3 GPIO_PIN_15
/** @} */

/**
 * @name Funzioni di inizializazzione
 * @{
 */
void myBSP_LED_Init(uint16_t led_to_init);
void myBSP_LED_deInit(uint16_t led_to_disable);
/** @} */

/**
 * @name Funzioni per le operazioni di I/O
 * @{
 */
void myBSP_LED_On(uint16_t on_led);
void myBSP_LED_Off(uint16_t off_led);
void myBSP_LED_Toggle(uint16_t toggle_led);
/** @} */

#endif /* BSP_LED_H_ */
/** @} */
