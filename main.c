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



		/*process*/




		/*output*/




	}



	return 0;
}

















