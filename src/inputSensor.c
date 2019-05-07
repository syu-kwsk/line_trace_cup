/*
 * inputSensor.c
 *
 *  Created on: 2019/04/30
 *      Author: wataru65
 */
#include "lpc13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#include "basicFunctions.h"
#include "inputSensor.h"


int inputSensor(){

	static int input[6];
	input[0] = sensor(bothSide);
	input[1] = sensor(rightSide);
	input[2] = sensor(leftSide);


	return *input;
}
