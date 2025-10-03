#ifndef ROBOT_CONFIG_H_
#define ROBOT_CONFIG_H_

#include "my-brain.h"
#include "vex.h"

using namespace vex;

extern MyBrain *my_brain;
extern controller Controller;

//定义四个依次连接左前轮、右前轮、左后轮、右后轮的电机
extern motor motor1,motor2,motor3,motor4;

//定义三个依次连接1、2、3号传送带的电机
extern motor motor5,motor6,motor7;


#endif