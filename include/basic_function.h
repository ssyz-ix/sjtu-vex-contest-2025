#ifndef BASIC_FUNCTIONS_H_
#define BASIC_FUNCTIONS_H_
#include "robot_config.h"

extern double SelfAngle;
/*
void moveTestMotor(double percent);

// 新增
void turnTo(double tar_angle);
void PIDDistanceForwardRel(double target);
*/
//下列为基础函数
void moveMotor(motor &TargetMotor,double percent,directionType direction);//电机编号&希望的运行速度&方向
//下列为机器人移动函数
void PIDDistanceForwardRel(double target,string direction);//PID控制距离
void PIDTurnTo(double SelfAngle,double target,string direction);//PID控制转向
//下列为球相关的函数
void TakeInBalls();//控制传球履带的
void TakeOutBalls();//控制传球履带的
void FangXiaXiQiuYongDeNaGeBanZi();
//应该还有好多，不太清楚具体机械结构先不写了

#endif
