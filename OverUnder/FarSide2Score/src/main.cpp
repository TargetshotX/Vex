/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]              [Type]        [Port(s)]
// Controller1          controller                    
// Controller2          controller                    
// Drivetrain           drivetrain    1, 2, 3, 4, 5, 6      
// Flywheel             motor         7               
// Intake               motor         8               
// Expansion1           digital_out   A               
// Expansion2           digital_out   B               
// Expansion3           digital_out   C               
// Expansion4           digital_out   D               
// Indexer              digital_out   H             
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
competition Competition;


int main() {


//Set the callbacks for Autonomous and Driver Control periods.
 Competition.autonomous(Autons);
 Competition.drivercontrol(vexcodeInit);
 pre_auton();
 calibrateIntertialSensor();

  
}