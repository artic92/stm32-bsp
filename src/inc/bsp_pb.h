/**
* @file bsp_pb.h
* @brief Definisce un board support package per la gestione dei pulsanti.
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
* @addtogroup BUTTONS
* @{
*
* @details
*   API che definiscono un basic support package per l'utilizzo dei pulsanti
*   su stm32. Questa libreria fa uso dei driver HAL dell'ST Microelectronics.
*
*/
#ifndef BSP_PB_H_
#define BSP_PB_H_

/***************************** Include Files *********************************/
#include "stm32f4xx.h"
#include "config_bsp.h"

/************************** Constant Definitions *****************************/
/**
 * @brief Enumerazione che indica la modalità di funzionamento del pulsante.
 *
 * @details Questa enumerazione deve essere utilizzata nella fase di configurazione
 *    per controllare il pulsante in polling o mediante interruzione.
 */
 typedef enum
 {
   INT_ENABLED,          ///< Modalità di funzionamento mediante polling
   INT_DISABLED          ///< Modalità di funzionamento mediante interruzioni
 } mode_enum;

 /**
  * @brief Enumerazione che indica lo stato di funzionamento del pulsante.
  *
  * @details Questa enumerazione vien utilizzata dal metodo myBSP_PB_GetState().
  * @see myBSP_PB_GetState():
  */
  typedef enum
  {
    PUSHED,             ///< Il pulsante è stato premuto
    NOT_PUSHED          ///< Il pulsante è in uno stato di riposo
  } state_enum;

/**
 * @name Funzioni di inizializzazione
 * @{
 */
void myBSP_PB_Init(mode_enum mode);
/** @} */

/**
 * @name Funzioni per le operazioni di I/O
 * @{
 */
state_enum myBSP_PB_GetState();
/** @} */

#endif /* BSP_PB_H_ */
