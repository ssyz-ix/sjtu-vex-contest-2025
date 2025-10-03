#ifndef BASIC_FUNCTIONS_H_
#define BASIC_FUNCTIONS_H_
#include "robot_config.h"
using namespace vex;

void moveMotor(motor m, double percent); //让电机m以percent百分比速度旋转

void turnAngle(double target); 
//用于自动阶段，旋转target角度，以度为单位，逆时针为正顺时针为负
void moveDistance(double target);  
//用于自动阶段，前进或后退target距离，以厘米为单位,前进为正后退为负
void movePercent(double fbPercent, double lrPercent); 
//用于手动阶段，以百分比速度移动和转动，fbPercent为前后百分比速度，lrPercent为左右百分比速度。
//前、右为正，后、左为负。

//上述三个函数都需要用PID控制

void displayTime(int t); //从t秒开始倒计时到0秒, 并在屏幕上显示当前时间

void detectBall(); //不断检测是否有对手的球吸入，如果有就反转电机。
void automonous(); //自动阶段机器人的行为

void userControl(); //手动阶段机器人的行为
#endif