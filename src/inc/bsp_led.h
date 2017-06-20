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
*   Questa libreria fa uso dei driver HAL dell'ST Microelectronics.
*
*/
#ifndef BSP_LED_H_
#define BSP_LED_H_

/***************************** Include Files *********************************/
#include "config.h"
#include "stm32f4xx.h"

/************************** Constant Definitions *****************************/
/**
 * @brief Enumerazione che specifica i pin sui quali i led sono posizionati.
 */
 typedef enum
 {
   LED0 = LED3_PIN,
   LED1 = LED4_PIN,
   LED2 = LED5_PIN,
   LED3 = LED6_PIN
 } led_pin;

/**
 * @name Funzioni di inizializzazione
 * @{
 */
void myBSP_LED_Init(led_pin led_to_init);
void myBSP_LED_deInit(led_pin led_to_disable);
/** @} */

/**
 * @name Funzioni per le operazioni di I/O
 * @{
 */
void myBSP_LED_On(led_pin on_led);
void myBSP_LED_Off(led_pin off_led);
void myBSP_LED_Toggle(led_pin toggle_led);
/** @} */

#endif /* BSP_LED_H_ */
/** @} */
