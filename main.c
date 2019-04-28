/*インクルード***********************************************************/
#include "lpc13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#include <stdio.h>

#include "basicFunctions.h"

/*マクロ***********************************************************/


/*グローバル変数***********************************************************/

/*メイン関数***********************************************************/


int process(int before, int after){
	printf("process");
	return 0;
}

int output(int processKind){
	printf("output");
	return 0;
}



int  main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);		//CPUの初期設定

	LED(3);
	sound(45, 128, 3000);
	while(getSW() != 1);
	while(getSW() == 1);

	static int processKind;



	while(1){
		/*input*/
		static int beforeOutputSensor = 0;
		static int afterInputSensor = 0;

		beforeOutputSensor = sensor(bothSide);



		/*process*/

		processKind = process(beforeOutputSensor, afterInputSensor);


		/*output*/

		output(processKind);

		afterInputSensor = sensor(bothSide);

	}



	return 0;
}

















