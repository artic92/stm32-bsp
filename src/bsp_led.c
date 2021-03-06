/**
* @file bsp_led.c
* @brief Implementazione delle funzioni di gestione dei LED.
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
* @addtogroup LED
* @{
*/
/***************************** Include Files *********************************/
#include "bsp_led.h"

/**
 * @brief Inizializza l'hardware di supporto.
 *
 * @param led_to_init è la maschera di bit indicante i LED da abilitare.
 *		Questo parametro può essere uno tra:
 *			@ref LEDa
 *			@ref LEDb
 *			@ref LEDc
 *			@ref LEDd
 *
 * @return none.
 */
void myBSP_LED_Init(led_pin led_to_init)
{
	GPIO_InitTypeDef gpio_init;

	__GPIOD_CLK_ENABLE();

	gpio_init.Pin = led_to_init;
	gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_init.Pull = GPIO_PULLUP;
	gpio_init.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOD, &gpio_init);
	HAL_GPIO_WritePin(GPIOD, led_to_init, GPIO_PIN_RESET);
}

/**
 * @brief Deinizializza l'hardware di supporto.
 *
 * @param led_to_disable è la maschera di bit indicante i LED da disabilitare.
 *		Questo parametro può essere uno tra:
 *			@ref LEDa
 *			@ref LEDb
 *			@ref LEDc
 *			@ref LEDd
 *
 * @return none.
 */
void myBSP_LED_deInit(led_pin led_to_disable)
{
	HAL_GPIO_DeInit(GPIOD, led_to_disable);
}

/**
 * @brief Accende i LED selezionati.
 *
 * @param on_led è la maschera di bit indicante i LED da accendere.
 *		Questo parametro deve essere uno o più tra:
 *			@ref LEDa
 *			@ref LEDb
 *			@ref LEDc
 *			@ref LEDd
 *
 * @return none.
 *
 * @note
 *    Questa funzione deve essere chiamata dopo aver abilitato i LED.
 */
void myBSP_LED_On(led_pin on_led)
{
	HAL_GPIO_WritePin(GPIOD, on_led, GPIO_PIN_SET);
}

/**
 * @brief Spegne i LED selezionati.
 *
 * @param off_led è la maschera di bit indicante i LED da spegnere.
 *		Questo parametro deve essere uno o più tra:
 *			@ref LEDa
 *			@ref LEDb
 *			@ref LEDc
 *			@ref LEDd
 *
 * @return none.
 *
 * @note
 *    Questa funzione deve essere chiamata dopo aver abilitato i LED.
 */
void myBSP_LED_Off(led_pin off_led)
{
	HAL_GPIO_WritePin(GPIOD, off_led, GPIO_PIN_RESET);
}

/**
 * @brief Commuta lo stato dei LED selezionati.
 *
 * @param toggle_led è la maschera di bit indicante i LED da commutare.
 *		Questo parametro deve essere uno o più tra:
 *			@ref LEDa
 *			@ref LEDb
 *			@ref LEDc
 *			@ref LEDd
 *
 * @note
 *    Questa funzione deve essere chiamata dopo aver abilitato i LED.
 */
void myBSP_LED_Toggle(led_pin toggle_led)
{
	HAL_GPIO_TogglePin(GPIOD, toggle_led);
}
/** @} */
