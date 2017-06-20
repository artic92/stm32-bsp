/*
 * bsp_pb.h
 *
 *  Created on: 17 mag 2017
 *      Author: antonio
 */

#ifndef BSP_PB_H_
#define BSP_PB_H_

#include "stm32f4xx.h"

#define BUTTON_MODE_POLLING 0
#define BUTTON_MODE_INT 1

void myBSP_PB_Init(int mode);
GPIO_PinState myBSP_PB_GetState();

#endif /* BSP_PB_H_ */
