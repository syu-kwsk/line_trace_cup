/*インクルード***********************************************************/
#include "lpc13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

/*マクロ***********************************************************/
#define mtrHigh 10000
#define mtrLow 5000
#define mtrBackHigh -10000
#define mtrBackLow -5000
#define mtrStop 0

/*グローバル変数***********************************************************/
enum sensorType{
	rightSide, leftSide, bothSide
};
enum sensorKind{
	bb, ww, wb, bw, rb, rw, lb, lw
};
enum runKind{
	straight, turnRight, turnLeft, back, backRight, backLeft, rotate, stop
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

void motor(int left_motor, int right_motor){
	Mtr_Run_lv(right_motor, -left_motor, 0, 0, 0, 0);
}
void run(int runKind){

	if(runKind == straight){
		motor(mtrHigh, mtrHigh);
	}
	else if(runKind == turnRight){
		motor(mtrHigh, mtrStop);
	}
	else if(runKind == turnLeft){
		motor(mtrStop, mtrHigh);
	}
	else if(runKind == back){
		motor(mtrBackHigh,mtrBackHigh);
	}
	else if(runKind == backRight){
		motor(mtrBackHigh,mtrStop);
	}
	else if(runKind == backLeft){
		motor(mtrStop,mtrBackHigh);
	}
	else if(runKind == rotate){
		motor(mtrHigh,mtrBackHigh);
	}
	else if(runKind == stop){
		motor(mtrStop,mtrStop);
	}

}

int sensor(int sensorType){
	const int borderJudgeNum = 500;
	static int resultSensor = 8;


	if(sensorType == rightSide){
		if(ADRead(1) > borderJudgeNum){
			resultSensor = rb;
		}
		else if(ADRead(1) < borderJudgeNum){
			resultSensor = rw;
		}
	}
	else if(sensorType == leftSide){
		if(ADRead(0) > borderJudgeNum){
			resultSensor = lb;
		}
		else if(ADRead(0) < borderJudgeNum){
			resultSensor = lw;
		}
	}
	else if(sensorType == bothSide){
		if(ADRead(0) > borderJudgeNum && ADRead(1) > borderJudgeNum){
			resultSensor = bb;
		}
		else if(ADRead(0) < borderJudgeNum && ADRead(1) < borderJudgeNum){
			resultSensor = ww;
		}
		else if(ADRead(0) < borderJudgeNum && ADRead(1) > borderJudgeNum){
			resultSensor = wb;
		}
		else if(ADRead(0) > borderJudgeNum && ADRead(1) < borderJudgeNum){
			resultSensor = bw;
		}
	}



	return resultSensor;
}


void backModify(int checkNum){

	int beforeRunSensor, afterRunSensor;
	int changeNum = 0;

	while(changeNum < checkNum){

		beforeRunSensor = sensor(bothSide);
		switch(sensor(bothSide)){
		case bb: run(back);break;
		case ww: run(straight); break;
		case bw: run(turnLeft); break;
		case wb: run(turnRight); break;
		}
		afterRunSensor = sensor(bothSide);

		if(beforeRunSensor != afterRunSensor){
			changeNum++;
		}
	}
	while(sensor(bothSide) == bb){
		run(straight);
	}

}

int  main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);		//CPUの初期設定

	LED(3);
	sound(45, 128, 3000);
	while(getSW() != 1);
	while(getSW() == 1);


	while(1){














	}
	return 0;
}

















