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
enum sensorKind{
	bb, ww, wb, bw
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

int sensor(){
	const int borderJudgeNum = 500;
	static int resultSensorNum = 0;

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


void backModify(int checkNum){

	int beforeRunSensor, afterRunSensor;
	int changeNum = 0;

	while(changeNum < checkNum){

		beforeRunSensor = sensor();
		switch(sensor()){
		case bb: run(back);break;
		case ww: run(straight); break;
		case bw: run(turnLeft); break;
		case wb: run(turnRight); break;
		}
		afterRunSensor = sensor();

		if(beforeRunSensor != afterRunSensor){
			changeNum++;
		}
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
		static int stage;
		if(stage == 0){
			switch(sensor()){
			case bb: run(straight); stage++; break;
			case ww: run(straight); break;
			case bw: run(turnLeft); break;
			case wb: run(turnRight); break;
			}
		}
		if(stage == 1){
			backModify(10);
			stage++;
		}
		if(stage == 2){
			switch(sensor()){
			case bb: run(straight); stage++; break;
			case ww: run(straight); break;
			case bw: run(turnLeft); break;
			case wb: run(turnRight); break;
			}
		}
		if(stage == 3){
			backModify(10);
			stage++;
		}
		if(stage == 4){
			run(stop);
		}




	}
	return 0;
}

















