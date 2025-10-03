#include "robot_config.h"
#include "vex.h"

using namespace vex;
MyBrain *my_brain = MyBrain::getInstance();
controller Controller = controller(primary);
inertial Inertial = inertial(PORT1);

motor motor1 = motor(PORT1, ratio6_1, true);
motor motor2 = motor(PORT2, ratio6_1, true);
motor motor3 = motor(PORT3, ratio6_1, true);
motor motor4 = motor(PORT4, ratio6_1, true);
//定义四个依次连接左前轮、右前轮、左后轮、右后轮的电机

motor motor5 = motor(PORT5, ratio6_1, true);
motor motor6 = motor(PORT6, ratio6_1, true);
motor motor7 = motor(PORT7, ratio6_1, true);
//定义三个依次连接1、2、3号传送带的电机