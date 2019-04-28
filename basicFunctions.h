/*
 * basicFunctions.h
 *
 *  Created on: 2019/04/28
 *      Author: wataru65
 */

#ifndef BASICFUNCTIONS_H_
#define BASICFUNCTIONS_H_

/*マクロ***********************************************************/
#define mtrHigh 10000
#define mtrLow 5000
#define mtrBackHigh -10000
#define mtrBackLow -5000
#define mtrStop 0

/*グローバル変数***********************************************************/
enum SENSORTYPE{
	rightSide, leftSide, bothSide
};
enum SENSORKIND{
	bb, ww, wb, bw, rb, rw, lb, lw
};
enum RUNKIND{
	straight, turnRight, turnLeft, back, backRight, backLeft, rotate, stop
};


/*基本関数***********************************************************/
void sound(int sound_pitch, int sound_volume,int sound_time);
void light(int light_kind, int light_time);
void motor(int left_motor, int right_motor);
void run(int runKind);
int sensor(int sensorType);
void backModify(int checkNum);



#endif /* BASICFUNCTIONS_H_ */




