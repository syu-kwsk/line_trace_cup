/*インクルード***********************************************************/
#include "lpc13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

/*マクロ***********************************************************/
#define mtrHigh 10000
#define mtrLow 5000
#define mtrBackHigh -10000
#define mtrBackLow 5000
#define mtrStop 0

/*グローバル変数***********************************************************/
enum{
	bb, ww, wb, bw
};

/*メイン関数***********************************************************/

void sound(int sound_pitch, int sound_volume,int sound_time){
	BuzzerSet(sound_pitch, sound_volume);
	BuzzerStart();
	Wait(sound_time);
	BuzzerStop();
}

void light(int light_kind, int light_time){
	LED(light_kind);
	Wait(light_time);
	LED(0);
}

void run(int left_motor, int right_motor){
	Mtr_Run_lv(right_motor, -left_motor, 0, 0, 0, 0);
}

int sensor(){
	const int borderJudgeNum = 500;
	int resultSensorNum = 0;

	if(ADRead(0) > borderJudgeNum && ADRead(1) > borderJudgeNum){
		resultSensorNum = bb;
	}
	else if(ADRead(0) < borderJudgeNum && ADRead(1) < borderJudgeNum){
		resultSensorNum = ww;
	}
	else if(ADRead(0) < borderJudgeNum && ADRead(1) > borderJudgeNum){
		resultSensorNum = wb;
	}
	else if(ADRead(0) > borderJudgeNum && ADRead(1) < borderJudgeNum){
		resultSensorNum = bw;
	}

	return resultSensorNum;
}


int  main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);		//CPUの初期設定

	LED(3);
	sound(45, 128, 3000);
	while(getSW() != 1);
	while(getSW() == 1);



	return 0;
}



/*
void Mtr_Run_lv(right, left(negative), 0, 0, 0, 0);
void getSW(); == 1(on)
              == 0(off)


void LED(kind); ==0(off)
				==1(green on)
				==2(orenge on)
			    ==3(both on)

void AdRead(chanel); ==0(left)
                     ==1(right)
					 > 500 black
					 < 500 white

void BuzzerSet(pitch, vol); pitch: 0~255
                            vol:   0~128
void BuzzerStart();
void BuzzerStop();

 */















