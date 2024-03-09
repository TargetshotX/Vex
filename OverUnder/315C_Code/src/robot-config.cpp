#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

//Motors
motor leftDrive1 = motor(PORT18, ratio6_1, false);
motor leftDrive2 = motor(PORT19, ratio6_1, false);
motor leftDrive3 = motor(PORT20, ratio6_1, false);
motor_group LeftDriveSmart = motor_group(leftDrive1,leftDrive2,leftDrive3);
motor rightDrive1= motor(PORT8, ratio6_1, true);
motor rightDrive2 = motor(PORT9, ratio6_1, true);
motor rightDrive3 = motor(PORT10, ratio6_1, true);
motor_group RightDriveSmart = motor_group(rightDrive1,rightDrive2,rightDrive3);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 355.59999999999997, 355.59999999999997, mm, 0.6666666666666666);
motor Slapper1 = motor(PORT16, ratio18_1, true);
motor Slapper2  = motor(PORT7, ratio18_1, false);
motor_group Slapper = motor_group(Slapper1, Slapper2);
motor Intake = motor(PORT17, ratio6_1, true);

//Pistons
digital_out BWingsLeft = digital_out(Brain.ThreeWirePort.A);
digital_out BWingsRight = digital_out(Brain.ThreeWirePort.B);
digital_out FWingsLeft = digital_out(Brain.ThreeWirePort.F);
digital_out FWingsRight = digital_out(Brain.ThreeWirePort.H);
digital_out Elevation = digital_out(Brain.ThreeWirePort.D);

#include "vex.h"

//Sensors + Controller
inertial Inertial14 = inertial(PORT5);
controller Controller1 = controller(primary);

bool RemoteControlCodeEnabled = true;

// VEXcode device constructors
void calibrateIntertialSensor(void) {
  Inertial14.calibrate();

  while(Inertial14.isCalibrating()){
   Controller1.Screen.clearLine(3);
   Controller1.Screen.print("Calibrating");
  }

  Controller1.Screen.clearLine(3);
  Controller1.Screen.print("Calibration Complete");

}

void errorLoop(void){
  

};

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  void Motor_Functions(void);
  void Piston_Functions(void);
  void Drivetrain_Function(void);  
}