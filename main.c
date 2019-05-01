/*インクルード***********************************************************/
#include "lpc13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"
#include <stdio.h>

#include "basicFunctions.h"
#include "inputSensor.h"
#include "process.h"


/*マクロ***********************************************************/


/*グローバル変数***********************************************************/

/*メイン関数***********************************************************/


int  main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);		//CPUの初期設定

	LED(3);
	sound(45, 128, 3000);
	while(getSW() != 1);
	while(getSW() == 1);




	while(1){
		/*input*/
		static int input[6];
		input[0] = sensor(bothSide);
		input[1] = sensor(rightSide);
		input[2] = sensor(leftSide);



		/*process*/




		/*output*/

		input[3] = sensor(bothSide);
		input[4] = sensor(rightSide);
		input[5] = sensor(leftSide);





	}



	return 0;
}

















