#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors

//Motors
motor leftDrive1 = motor(PORT1, ratio6_1, false);
motor leftDrive2 = motor(PORT2, ratio6_1, false);
motor leftDrive3 = motor(PORT3, ratio6_1, false);
motor_group LeftDriveSmart = motor_group(leftDrive1,leftDrive2,leftDrive3);
motor rightDrive1= motor(PORT4, ratio6_1, true);
motor rightDrive2 = motor(PORT5, ratio6_1, true);
motor rightDrive3 = motor(PORT6, ratio6_1, true);
motor_group RightDriveSmart = motor_group(rightDrive1,rightDrive2,rightDrive3);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 355.59999999999997, 355.59999999999997, mm, 0.6666666666666666);
motor Slapper = motor(PORT16, ratio18_1, false);
motor Intake = motor(PORT8, ratio6_1, false);

//Pistons
digital_out Wings = digital_out(Brain.ThreeWirePort.H);
digital_out Elevation = digital_out(Brain.ThreeWirePort.B);

//Sensors + Controller
inertial Inertial15 = inertial(PORT14);
controller Controller1 = controller(primary);

bool RemoteControlCodeEnabled = true;

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