#include <math.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();\
//Creating 4 motors
Adafruit_DCMotor *motor1 = AFMS.getMotor(1);
Adafruit_DCMotor *motor2 = AFMS.getMotor(2);
Adafruit_DCMotor *motor3 = AFMS.getMotor(3);
Adafruit_DCMotor *motor4 = AFMS.getMotor(4);

void setup_drivebase(){
  AFMS.begin();
  //Set default speed as 0
  motor1 -> setSpeed(0);
  motor2 -> setSpeed(0);
  motor3 -> setSpeed(0);
  motor4 -> setSpeed(0);
  
}
int invert_value(int motor_speed, int stationary_value){
  int inverted_value = 0;
  if (motor_speed > stationary_value){
    inverted_value = stationary_value - (motor_speed % stationary_value);
  }
  else if (motor_speed < stationary_value){ 
    inverted_value = stationary_value + (motor_speed % stationary_value);
  }
  return inverted_value;
}

int scale_joystick(int joystick_value){
  double scale = joystick_value/255;
  scale = pow(scale,2);
  return int(joystick_value * scale);
}

void tank_drive(int left_speed, int right_speed){
  //Set default speeds of motor 
  motor1 -> setSpeed(left_speed);
  motor2 -> setSpeed(left_speed);
  motor3 -> setSpeed(right_speed);
  motor4 -> setSpeed(right_speed);
}
