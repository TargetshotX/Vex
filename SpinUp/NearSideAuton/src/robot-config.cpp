/*
This is the Near Side Auton. It will 
1. roll the roller
2. shoot the pre load
3. Drive and intake disc
4. Shoot disc
*/

#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);
motor leftMotorA = motor(PORT1, ratio18_1, false);
motor leftMotorB = motor(PORT2, ratio18_1, false);
motor leftMotorC = motor(PORT3, ratio18_1, false);
motor_group LeftDriveSmart = motor_group(leftMotorA,leftMotorB,leftMotorC);
motor rightMotorA = motor(PORT4, ratio18_1, true);
motor rightMotorB = motor(PORT5, ratio18_1, true);
motor rightMotorC = motor(PORT6, ratio18_1,true);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB,rightMotorC);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);
motor Flywheel = motor(PORT7, ratio6_1, false);
motor Intake = motor(PORT8, ratio18_1, false);
digital_out Expansion1 = digital_out(Brain.ThreeWirePort.A);
digital_out Expansion2 = digital_out(Brain.ThreeWirePort.B);
digital_out Indexer = digital_out(Brain.ThreeWirePort.H);
inertial Inertial20 = inertial(PORT20);

void calibrateIntertialSensor(void) {
  Inertial20.calibrate();

  while(Inertial20.isCalibrating()){
   Controller1.Screen.clearLine(3);
   Controller1.Screen.print("Calibrating");
  }

  Controller1.Screen.clearLine(3);
  Controller1.Screen.print("Calibration Complete");

}


// pre-auton initialization

void pre_auton() {
  Brain.Screen.clearScreen();
  while(true) 
  {
    Brain.Screen.setCursor(2,1);
    Brain.Screen.print("Drivetrain Temp:");
    Brain.Screen.setCursor(3,1);
    Brain.Screen.print(Drivetrain.temperature(percentUnits::pct));
    Brain.Screen.setCursor(3,7);
    Brain.Screen.print("percent");
    
    Brain.Screen.setCursor(5,1);
    Brain.Screen.print("Intake Temp:");
    Brain.Screen.setCursor(6,1);
    Brain.Screen.print(Intake.temperature(percentUnits::pct));
    Brain.Screen.setCursor(6,7);
    Brain.Screen.print("percent");
    
    Brain.Screen.setCursor(8,1);
    Brain.Screen.print("Flywheel Temp:");
    Brain.Screen.setCursor(9,1);
    Brain.Screen.print(Flywheel.temperature(percentUnits::pct));
    Brain.Screen.setCursor(9,7);
    Brain.Screen.print("percent");
    
  }

}

//define rightSideAuton
void rightSideAuton() {

 //Spin roller shoot 2
 Flywheel.setVelocity(90, percentUnits::pct);
 Flywheel.spin(reverse);
 calibrateIntertialSensor();
 Drivetrain.setDriveVelocity(100, percentUnits::pct);
 Intake.setVelocity(100, percentUnits::pct);
 Intake.spin(reverse);
 Drivetrain.driveFor(reverse,2,inches);
 Drivetrain.driveFor(forward,3,inches);
 Drivetrain.turnFor(20, degrees);
 wait(1,seconds);
 Indexer.set(true);
 wait(.3,seconds);
 Indexer.set(false);
 Intake.spin(forward);
 wait(1,seconds);
 Indexer.set(true);
 wait(.3,seconds);
 Indexer.set(false);
 wait(.1,sec);


 //turn
 Drivetrain.turnFor(30, degrees);
 while(Inertial20.heading() > (230)) {
  LeftDriveSmart.spin(forward, 25, percent);
  RightDriveSmart.spin(reverse,15, percent);

}
Drivetrain.stop();

//Drive Forward
Intake.spin(forward);
Drivetrain.setDriveVelocity(90, percentUnits::pct);
Drivetrain.driveFor(reverse,30,inches);
Drivetrain.setDriveVelocity(20, percentUnits::pct);
Drivetrain.driveFor(reverse,10,inches);
Drivetrain.turnFor(-86, degrees);

// Shoot the Discs
 Flywheel.setVelocity(80, percentUnits::pct);
 Flywheel.spin(reverse);
 wait(2, sec);
 Indexer.set(true);
 wait(.3,seconds);
 Indexer.set(false);
 Intake.stop();
 wait(.5,seconds);
 Indexer.set(true);
 wait(.3,seconds);
 Indexer.set(false);
 wait(.1,sec);
 wait(.2,seconds);
 Indexer.set(true);
 wait(.3,seconds);
 Indexer.set(false);
 wait(.1,sec);





 return;
}

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool Controller1LeftShoulderControlMotorsStopped = true;
bool Controller1RightShoulderControlMotorsStopped = true;
bool DrivetrainLNeedsToBeStopped_Controller1 = true;
bool DrivetrainRNeedsToBeStopped_Controller1 = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      // calculate the drivetrain motor velocities from the controller joystick axies
      // left = Axis3 + Axis1
      // right = Axis3 - Axis1
      int drivetrainLeftSideSpeed = Controller1.Axis3.position() - Controller1.Axis1.position();
      int drivetrainRightSideSpeed = Controller1.Axis3.position() + Controller1.Axis1.position();
      
      // check if the value is inside of the deadband range
      if (drivetrainLeftSideSpeed < 5 && drivetrainLeftSideSpeed > -5) {
        // check if the left motor has already been stopped
        if (DrivetrainLNeedsToBeStopped_Controller1) {
          // stop the left drive motor
          LeftDriveSmart.stop();
          // tell the code that the left motor has been stopped
          DrivetrainLNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the left motor nexttime the input is in the deadband range
        DrivetrainLNeedsToBeStopped_Controller1 = true;
      }
      // check if the value is inside of the deadband range
      if (drivetrainRightSideSpeed < 5 && drivetrainRightSideSpeed > -5) {
        // check if the right motor has already been stopped
        if (DrivetrainRNeedsToBeStopped_Controller1) {
          // stop the right drive motor
          RightDriveSmart.stop();
          // tell the code that the right motor has been stopped
          DrivetrainRNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the right motor next time the input is in the deadband range
        DrivetrainRNeedsToBeStopped_Controller1 = true;
      }
      
      // only tell the left drive motor to spin if the values are not in the deadband range
      if (DrivetrainLNeedsToBeStopped_Controller1) {
        LeftDriveSmart.setVelocity(drivetrainLeftSideSpeed, percent);
        LeftDriveSmart.spin(reverse);
      }
      // only tell the right drive motor to spin if the values are not in the deadband range
      if (DrivetrainRNeedsToBeStopped_Controller1) {
        RightDriveSmart.setVelocity(drivetrainRightSideSpeed, percent);
        RightDriveSmart.spin(reverse);
      }
    
      // check the ButtonR1/ButtonR2 status to control Intake
      if (Controller1.ButtonR1.pressing()) {
        Intake.setVelocity(100, percentUnits::pct);
        Intake.spin(forward);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonR2.pressing()) {
        Intake.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are release
        Controller1RightShoulderControlMotorsStopped = true;
      // check the Button R1
      }

       if (Controller1.ButtonL1.pressing()) {
       Flywheel.setVelocity(63, percentUnits::pct); 
       Flywheel.spin(reverse);
       Controller1LeftShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonL2.pressing()) {
       Flywheel.stop();
       Controller1LeftShoulderControlMotorsStopped = true;}

      
      if (Controller1.ButtonX.pressing()) {
       
       Indexer.set(true);
       wait(.135,seconds);
       Indexer.set(false);

      } else if(Controller1.ButtonB.pressing()) {
       
       Indexer.set(true);
       wait(.4,seconds);
       Indexer.set(false);
       wait(.4,seconds);
       Indexer.set(true);
       wait(.4,seconds);
       Indexer.set(false);
       wait(.4,seconds);
       Indexer.set(true);
       wait(.4,seconds);
       Indexer.set(false);
      } 
      if(Controller1.ButtonUp.pressing() && Controller1.ButtonDown.pressing()) {
      // Code to fire the expansion goes here
      Expansion1.set(true);
      }
      if(Controller1.ButtonLeft.pressing() && Controller1.ButtonRight.pressing()) {
      // Code to fire the expansion goes here
      Expansion2.set(true);
      }
  
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;}



void vexcodeInit( void ) {
task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}  