#include "vex.h"
#include "autons.h"
#include "robot-config.h"
using namespace vex;
competition Competition;
int current_auton_selection = 0;
bool auto_started = false; 

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  calibrateIntertialSensor();
  vexcodeInit();

  while(auto_started == false){            //Changing the names below will only change their names on the
    Brain.Screen.clearScreen();            //brain screen for auton selection.
    switch(current_auton_selection){       //Tap the brain screen to cycle through autons.
      case 0:
        Brain.Screen.printAt(50, 50, "Far Side");
        break;
      case 1:
        Brain.Screen.printAt(50, 50, "NearSide Without Score");
        break;
      case 2:
        Brain.Screen.printAt(50, 50, "Skills Auton");
        break;
      case 3:
        Brain.Screen.printAt(50, 50, "Near Side Elims");
        break;
      case 4:
        Brain.Screen.printAt(50, 50, "Far Side Safe");
        break;
      case 5:
        Brain.Screen.printAt(50, 50, "error loop test");
        break;
      case 6:
        Brain.Screen.printAt(50, 50, "Tank Odom Test");
        break;
      case 7:
        Brain.Screen.printAt(50, 50, "Holonomic Odom Test");
        break;
    }
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 8){
      current_auton_selection = 0;
    }
    task::sleep(10);
  }
}

void autonomous(void) {
  auto_started = true;
  switch(current_auton_selection){  
    case 0:
      Far_Side_6Score();
       //This is the default auton, if you don't select from the brain.
      break;        //Change these to be your own auton functions in order to use the auton selector.
    case 1:         //Tap the screen to cycle through autons.
      Near_Side_Safe();
      break;
    case 2:
      Skills_Auton();
      break;
    case 3:
      Near_Side_Elim();
      break;
    case 4:
      Far_Side_Safe();
      break;
    case 5:
      break;
    case 6:
      test_errorloop();
      break;
    case 7:
      holonomic_odom_test();
      break;
 }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    Motor_Functions();
    Piston_Functions();
    Drivetrain_Function(); 
    //chassis.control_arcade();

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
