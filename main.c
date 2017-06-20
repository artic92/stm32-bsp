/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_pb.h"

void setup();
void loop();

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	myBSP_LED_Toggle(LED0);
}

int main(void)
{
	setup();
	for(;;) loop();
	return 1;
}

void setup()
{
	HAL_Init();
	myBSP_LED_Init(LED0);
	myBSP_LED_Init(LED1);
	myBSP_LED_Init(LED2);
	myBSP_LED_Init(LED3);
//	myBSP_PB_Init(BUTTON_MODE_POLLING);
	myBSP_PB_Init(BUTTON_MODE_INT);
}

void loop()
{
	// Decommentare se si usa il pulsante in modalità polling
//	if(myBSP_PB_GetState() == GPIO_PIN_SET)
		myBSP_LED_Toggle(LED3);
	HAL_Delay(500);
}
