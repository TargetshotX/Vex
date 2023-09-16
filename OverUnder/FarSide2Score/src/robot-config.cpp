#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftMotorA = motor(PORT2, ratio6_1, false);
motor leftMotorB = motor(PORT4, ratio6_1, false);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
motor rightMotorA = motor(PORT1, ratio6_1, true);
motor rightMotorB = motor(PORT3, ratio6_1, true);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 355.59999999999997, 355.59999999999997, mm, 0.6666666666666666);
motor Catapult = motor(PORT5, ratio18_1, false);
motor Intake = motor(PORT6, ratio6_1, false);
motor Extension1 = motor(PORT10, ratio6_1, false);
motor Extension2 = motor(PORT9, ratio6_1, false);
controller Controller1 = controller(primary);
digital_out Wings1 = digital_out(Brain.ThreeWirePort.A);
digital_out Wings2 = digital_out(Brain.ThreeWirePort.B);
inertial Inertial8 = inertial(PORT8);

//Intertial Sensor

void calibrateIntertialSensor(void) {
  Inertial8.calibrate();

  while(Inertial8.isCalibrating()){
   Controller1.Screen.clearLine(3);
   Controller1.Screen.print("Calibrating");
  }

  Controller1.Screen.clearLine(3);
  Controller1.Screen.print("Calibration Complete");

}


// pre-auton initialization
void pre_auton() {
  Brain.Screen.clearScreen();
  Wings1.set(false);
  Wings2.set(true);
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
    Brain.Screen.print("Catapult Temp:");
    Brain.Screen.setCursor(9,1);
    Brain.Screen.print(Catapult.temperature(percentUnits::pct));
    Brain.Screen.setCursor(9,7);
    Brain.Screen.print("percent");
    
  }

}



//define rightSideAuton
void Autons() {
Drivetrain.setDriveVelocity(30, percentUnits::pct);

//Intake and Turn
Intake.spin(reverse,100, percentUnits::pct);
Drivetrain.driveFor(2, distanceUnits::in);
Intake.stop();

//Drive forward and Turn
Drivetrain.driveFor(70, distanceUnits::in);
Drivetrain.turnFor(-60, degrees);
Intake.spin(forward,100, percentUnits::pct);
wait(.5,sec);
Drivetrain.stop();
Drivetrain.driveFor(5, distanceUnits::in);
Intake.spin(forward,100, percentUnits::pct);

//Turn and intake
Drivetrain.driveFor(-1, distanceUnits::in);
Drivetrain.turnFor(120, degrees);
Drivetrain.driveFor(15, distanceUnits::in);
Intake.spin(reverse,100, percentUnits::pct);
Drivetrain.driveFor(15, distanceUnits::in);
Drivetrain.turnFor(120, degrees);
Drivetrain.driveFor(30, distanceUnits::in);
Intake.spin(forward,100, percentUnits::pct);
wait(.5, timeUnits ::sec);
Drivetrain.driveFor(1, distanceUnits::in);
Intake.stop();



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
bool Controller1UpDownControlMotorsStopped = true;


//Drivetrain:
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
      // only tell the left drive motor to spin if the values are not in the deadband range
      if (DrivetrainLNeedsToBeStopped_Controller1) {
        LeftDriveSmart.setVelocity(drivetrainLeftSideSpeed, percent);
        LeftDriveSmart.spin(forward);
      }
      // only tell the right drive motor to spin if the values are not in the deadband range
      if (DrivetrainRNeedsToBeStopped_Controller1) {
        RightDriveSmart.setVelocity(drivetrainRightSideSpeed, percent);
        RightDriveSmart.spin(forward);
      }


      //Intake:
      // check the ButtonL1/ButtonL2 status to control Intake
      if (Controller1.ButtonR2.pressing()) {
        Intake.setVelocity(100, percentUnits::pct);
        Intake.spin(forward);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonR1.pressing()) {
        Intake.setVelocity(100, percentUnits::pct);
        Intake.spin(reverse);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (!Controller1LeftShoulderControlMotorsStopped) {
        Intake.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1LeftShoulderControlMotorsStopped = true;
      }


      //Catapult:
      // check the ButtonR1/ButtonR2 status to control Catapult
      if (Controller1.ButtonL2.pressing()) {
        Catapult.setVelocity(100, percentUnits::pct);
        Catapult.spin(reverse);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonL1.pressing()) {
        Catapult.setVelocity(100, percentUnits::pct);
        Catapult.spinFor(reverse, 450 ,degrees); 
      }else if (Controller1.ButtonX.pressing()) {
        Catapult.stop();
        
        
      } 

      //Extension
      //Intake:
      // check the ButtonL1/ButtonL2 status to control Intake
      if (Controller1.ButtonUp.pressing()) {
        Extension1.stop();
        Extension1.setVelocity(100, percent);
        Extension2.setVelocity(100, percent);
        Extension1.spin(forward);
        Extension2.spin(reverse);
        Controller1UpDownControlMotorsStopped = false;
      } else if (Controller1.ButtonDown.pressing()) {
        Extension1.setVelocity(100, percent);
        Extension2.setVelocity(100, percent);
        Extension2.spin(forward);
        Extension1.spin(reverse);
        Controller1UpDownControlMotorsStopped = false;
      } else if (!Controller1UpDownControlMotorsStopped) {
        Extension1.stop(hold);
        Extension2.stop(hold);
        
      }

      //Wings
      if (Controller1.ButtonA.pressing()) {
       
       Wings1.set(true);
       Wings2.set(true);
      }

       if (Controller1.ButtonY.pressing()) {
       
       Wings1.set(false);
       Wings2.set(false);
       }

    }


    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}