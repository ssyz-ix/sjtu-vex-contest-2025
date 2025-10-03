#ifndef USERCONTROL_H_
#define USERCONTROL_H_
#include "vex.h"
#include "basic_function.h"
#include "controller.h"
/*
void motorTestControl();

// 新增
void testTurnTo();
void testPIDDistanceForward();
void testAuton();

void allDeviceControl();
void userControl();
*/
void joystickControl(controller::axis &axis,directionType dir) {
    //在这里指定电机
    int value = axis.position(percentUnits::pct);
    m.spin(forward, value, percentUnits::pct);
}

void joystickControlTurn(controller::axis &axis,directionType dir) {
    //在这里指定电机
    int value = axis.position(percentUnits::pct);
    m.spin(forward, value, percentUnits::pct);
}

#endif
