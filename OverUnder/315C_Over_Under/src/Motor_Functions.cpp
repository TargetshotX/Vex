#include "vex.h"//define 

void Motor_Functions(void){

  bool Controller1LeftShoulderControlMotorsStopped = true;
  bool Controller1RightShoulderControlMotorsStopped = true;

  //Slapper:
  // check the ButtonL1/ButtonL2 status to control Slapper
  if (Controller1.ButtonL2.pressing()) {
    Slapper.setVelocity(100, percentUnits::pct);
    Slapper.spin(reverse);
    Controller1LeftShoulderControlMotorsStopped = false;
  }else if (Controller1.ButtonL1.pressing()) {
    Slapper.stop();
  }

  //Intake:
  // check the ButtonL1/ButtonL2 status to control Intake
  if (Controller1.ButtonR2.pressing()) {
    Intake.setVelocity(100, percentUnits::pct);
    Intake.spin(reverse);
    Controller1RightShoulderControlMotorsStopped = false;
  } else if (Controller1.ButtonR1.pressing()) {
    Intake.setVelocity(100, percentUnits::pct);
    Intake.spin(forward);
    Controller1RightShoulderControlMotorsStopped = false;
  } else if (Controller1RightShoulderControlMotorsStopped) {
    Intake.stop();
    // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
    Controller1RightShoulderControlMotorsStopped = true;
  }

}