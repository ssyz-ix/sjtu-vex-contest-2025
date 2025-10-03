#include "basic_function.h"

using namespace vex;

void moveMotor(motor m,double percent) {
    //xiugai
    m.spin(forward, percent, pct);
}

double Kp = 0.5;
double Ki = 0.1;
double Kd = 0.05;
double radius=1234;//待定

void moveDistance(double target){

    double curDistance=0;
    double error=target;
    double preError=0;
    double integral=0;
    double derivative = 0;
    double output = 0;
    double limit=100;//待定
    double deltaT;
    double preVelo=0;
    double curVelo=0;
    double mixedVelo=0;//一阶滤波
    double alpha=0.2;//待定
    double limitOfIntegral=123456;//待定
    double preTime=0;
    double curTime=0;

    MyTimer t; 
    t.reset();

    while(true){

        integral+=error;
        if(fabs(integral)>limitOfIntegral)
            integral=(integral>0?limitOfIntegral:-limitOfIntegral);
        derivative=error-preError;//如果频率够快的话差不多可以等价于微分吧（
        output=Kp*error+Ki*integral+Kd*derivative;

        if(fabs(output)>limit)
            output=(output>0?limit:-limit);

        moveMotor(motor1,output/limit*100);
        moveMotor(motor2,output/limit*100);
        moveMotor(motor3,output/limit*100);
        moveMotor(motor4,output/limit*100);

        curTime=t.getTimeDouble();
        deltaT=curTime-preTime;
        preTime=curTime;

        double curVelo = (motor1.velocity(dps)+motor2.velocity(dps)+motor3.velocity(dps)+motor4.velocity(dps))/4;
        mixedVelo=alpha*preVelo+(1-alpha)*curVelo;

        curDistance+=mixedVelo*deltaT*radius;
        preError=error;
        error=target-curDistance;
        preVelo=mixedVelo;  

        if(fabs(error)<1)
            break;

        this_thread::sleep_for(2);
}
    motor1.stop(brake);
    motor2.stop(brake);
    motor3.stop(brake);
    motor4.stop(brake);
}

void turnAngle(double target){

    double curAngle=0;
    double error=target;
    double preError=0;
    double integral=0;
    double derivative = 0;
    double output = 0;
    double limit=100;//待定
    double limitOfIntegral;

    while(true){

        integral+=error;
        if(fabs(integral)>limitOfIntegral)
            integral=(integral>0?limitOfIntegral:-limitOfIntegral);
        derivative=error-preError;
        output=Kp*error+Ki*integral+Kd*derivative;

        if(fabs(output)>limit)
            output=(output>0?limit:-limit);

        moveMotor(motor1,-output/limit*100);
        moveMotor(motor2,output/limit*100);
        moveMotor(motor3,-output/limit*100);
        moveMotor(motor4,output/limit*100);

        curAngle=InertialSensor.rotation();
        preError=error;
        error=target-curAngle;

        if(fabs(error)<1)
            break;

        this_thread::sleep_for(2);
}
    motor1.stop(brake);
    motor2.stop(brake);
    motor3.stop(brake);
    motor4.stop(brake);
}

void movePercent(double fbPercent, double lrPercent) {

}
//上述三个函数都需要用PID控制

void displayTime(int t) {
    
}

void detectBall() {

}
void automonous() {

}

void userControl() {

}