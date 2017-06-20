/**
* @file bsp_pb.c
* @brief Implementazione delle funzioni di gestione dei pulsanti.
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
* @addtogroup BUTTONS
* @{
*/
/***************************** Include Files *********************************/
#include "bsp_pb.h"

/**
 * @brief Inizializza l'hardware di supporto.
 *
 * @param int_config è una costante che configura il supporto alle interruzioni.
 *    Se impostata come INT_ENABLED abilita le interruzioni, se impostata a
 *    INT_DISABLED il supporto alle interruzioni è disabilitato.
 *
 * @note
 *    L'implementazione della funzione di gestione dell'interruzione è demandata
 *    all'utilizzatore. Il nome dell'ISR è HAL_GPIO_EXTI_Callback(uint16_t).
 *
 * @return none.
 */
void myBSP_PB_Init(mode_enum mode)
{
	GPIO_InitTypeDef gpioa_init;

		__GPIOA_CLK_ENABLE();

	if(mode == INT_DISABLED){
		gpioa_init.Pin = GPIO_PIN_0;
		gpioa_init.Mode = GPIO_MODE_INPUT;
		gpioa_init.Pull = GPIO_NOPULL;
		gpioa_init.Speed = GPIO_SPEED_HIGH;
	}else{
		gpioa_init.Pin = GPIO_PIN_0;
		gpioa_init.Mode = GPIO_MODE_IT_RISING;
		gpioa_init.Pull = GPIO_NOPULL;
		gpioa_init.Speed = GPIO_SPEED_HIGH;

		HAL_NVIC_SetPriority(EXTI0_IRQn, 15, 15);
		HAL_NVIC_ClearPendingIRQ(EXTI0_IRQn);
		HAL_NVIC_EnableIRQ(EXTI0_IRQn);
	}

	HAL_GPIO_Init(GPIOA, &gpioa_init);
}

/**
 * @brief Deinizializza l'hardware di supporto.
 *
 * @return none.
 */
void myBSP_PB_deInit(){
	HAL_GPIO_DeInit(GPIOA, GPIO_PIN_0);
}

/**
 * @brief Lettura dello stato del pulsante.
 *
 * @return Costante che indica lo stato del pulsante.
 */
GPIO_PinState myBSP_PB_GetState()
{
	return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
}
