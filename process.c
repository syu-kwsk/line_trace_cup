/*
 * process.c
 *
 *  Created on: 2019/04/30
 *      Author: wataru65
 */

#include "lpc13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#include <stdio.h>

#include "basicFunctions.h"
#include "process.h"

int process(int *inputSensor){
	int beforeSensor[3];
	int afterSensor[3];



	for(int i = 0; i < 3; i++){
		beforeSensor[i] = inputSensor[i];
		afterSensor[i]  = inputSensor[i+3];
	}
	if(beforeSensor[0] == afterSensor[0]){
		processKind

	}

}
