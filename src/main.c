/**
* @file main.c
* @brief Applicazione dimostrativa delle funzionalità del BSP.
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
/***************************** Include Files ********************************/
#include "bsp_led.h"
#include "bsp_pb.h"

int on_led = 0;

void setup();
void loop();

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

/**
* @details Esegue un test di funzionamento accendendo e spegnendo i LED in base
* allo stato degli switch o dei pulsanti.
*/
int main(void)
{
	setup();
	for(;;) loop();
	return 1;
}

/**
* @brief Configura l'hardware.
*
* @details Questa funzione Inizializza tutti i LED e configura lo switch in modalità
*		interrompente.
*/
void setup()
{
	HAL_Init();

	myBSP_LED_Init(LED0);
	myBSP_LED_Init(LED1);
	myBSP_LED_Init(LED2);
	myBSP_LED_Init(LED3);

	myBSP_PB_Init(INT_ENABLED);
}

/**
* @brief Commuta il led in base al valore del contatore on_led
*/
void loop()
{
	switch(on_led % 4){
		case 0:
			myBSP_LED_Toggle(LED0);
			HAL_Delay(500);
			break;
		case 1:
			myBSP_LED_Toggle(LED1);
			HAL_Delay(500);
			break;
		case 2:
			myBSP_LED_Toggle(LED2);
			HAL_Delay(500);
			break;
		case 3:
			myBSP_LED_Toggle(LED3);
			HAL_Delay(500);
			break;
	}
	on_led++;
}

/**
* @brief ISR del pulsante.
*
* @details Riavvia il contatore.
*/
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	myBSP_LED_Toggle(LED0);
}
