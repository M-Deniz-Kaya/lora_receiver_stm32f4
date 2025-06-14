/*
 * troket_main.c
 *
 *  Created on: Jun 13, 2025
 *      Author: Deniz
 */
#include "troket_main.h"

#include <main.h>

extern UART_HandleTypeDef huart2;

void boot() {}

uint8_t rxBuffer[3];
uint8_t value1, value2, value3, state1, state2, state3;

void loop() {
	if (HAL_UART_Receive(&huart2, rxBuffer, 3, HAL_MAX_DELAY) == HAL_OK)
	{
		// for first led
		value1 = rxBuffer[0];
		state1 = value1 == 1 ? 1 : 0;
		HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, state1);

		// second led
	    value2 = rxBuffer[1];
		state2 = value2 == 1 ? 1 : 0;
		HAL_GPIO_WritePin(LD4_GPIO_Port, LD4_Pin, state2);
		
		// third led
	    value3 = rxBuffer[2];
		state3 = value3 == 1 ? 1 : 0;
		HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_Pin, state3);
	}
}


