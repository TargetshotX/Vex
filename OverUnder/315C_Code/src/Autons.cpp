#include "vex.h"
#include "robot-config.h"
vex::timer myTimer;

void Far_Side_6Score(){
//Far Side Win Point
//Part One: Three Balls
//Calibrate Velocities and Sensors
  Intake.setVelocity(100,percentUnits::pct);
  Intake.spin(reverse);
  wait(.2,sec);
  Drivetrain.setDriveVelocity(50, percentUnits::pct);
  Intake.setVelocity(100, percentUnits::pct);
  printf("Far_Side_WinPoint");
//Intake First Triball
  Intake.spin(forward);
  Drivetrain.driveFor(7,inches);
  wait(.5, timeUnits::sec);
//Drive Back To Match Load Zone
  Drivetrain.driveFor(-40,inches);
//Turn To Goal With Inertial and Descore From Match Zone
  Drivetrain.turnFor(20, degrees);
  while(Inertial14.heading()<(245)) {
    LeftDriveSmart.spin(reverse, 30, percent);
    RightDriveSmart.spin(forward,45, percent);
  }
  Intake.spin(forward);
  Drivetrain.stop(); 
  BWingsLeft.set(true);
  BWingsRight.set(true);
  Drivetrain.driveFor(-25,inches);
  Drivetrain.turnFor(15, degrees);
  BWingsLeft.set(false);
  BWingsRight.set(false);
  Drivetrain.driveFor(-10,inches);
//Score All 3
//Go Forward and Turn
  Inertial14.resetRotation();
  Drivetrain.turnFor(-10, degrees);
  while(Inertial14.heading() > (140)) {
    LeftDriveSmart.spin(forward, 40, percent);
    RightDriveSmart.spin(reverse,50, percent);
  }
  Drivetrain.stop();
  Intake.setVelocity(100,percentUnits::pct); 
  Intake.spin(reverse);
//Push It All In
  Drivetrain.setDriveVelocity(30, percentUnits::pct);
  wait(.3, sec);
  Intake.spin(reverse);
  Drivetrain.driveFor(8,inches);
  Drivetrain.driveFor(-10,inches);
  wait(.2, sec);
  Drivetrain.driveFor(8,inches);
  Drivetrain.driveFor(-5,inches);

//Part Two: Three Balls
//Reset Velocities
  Drivetrain.setDriveVelocity(40, percentUnits::pct);
  Intake.setVelocity(100, percentUnits::pct);
  Drivetrain.setTurnVelocity(20, percentUnits::pct);
//Second Triball
//Turn and Intake
  Inertial14.resetRotation();
  Drivetrain.turnFor(10, degrees);
  while(Inertial14.heading() > (61)) {
    LeftDriveSmart.spin(reverse, 25, percent);
    RightDriveSmart.spin(forward,35, percent);
  }
  Drivetrain.stop(); 
  Intake.spin(forward,100, percentUnits::pct);
  Drivetrain.setDriveVelocity(50, percentUnits::pct);
  Drivetrain.driveFor(67, distanceUnits::in);
  wait(.3, sec);
//Spin and Outake 
  Intake.spin(forward);
  Intake.setVelocity(10,percent); 
  Inertial14.resetRotation();
  Drivetrain.turnFor(-80, degrees);
  Drivetrain.driveFor(15, distanceUnits::in);
  wait(.2,sec);
  Drivetrain.stop(); 
  Intake.spin(reverse,60, percentUnits::pct);
  wait(.4, sec);
//Third Triball
//Intake Next
  Drivetrain.turnFor(60, degrees);
  Intake.spin(forward,100, percentUnits::pct);
  Drivetrain.driveFor(25, distanceUnits::in);
  wait(.2, timeUnits::sec);
  Drivetrain.setTurnVelocity(30, percentUnits::pct);
//Score With Wings
  Intake.setVelocity(100,percentUnits::pct);
  Drivetrain.driveFor(-10, distanceUnits::in);
  Drivetrain.turnFor(-72.5,degrees);
  FWingsLeft.set(true);
  FWingsRight.set(true);
  Intake.spin(reverse);
  wait(.2,sec);
  Drivetrain.setDriveVelocity(60, percentUnits::pct);
  Drivetrain.driveFor(38.5, distanceUnits::in);
}


void Near_Side_Elim(){
//Intake Middle Triball
  Drivetrain.setDriveVelocity(60,percentUnits::pct);
  Intake.setVelocity(100,pct);
  wait(.5,sec);
  Intake.spin(forward);
  Drivetrain.driveFor(64, inches);
//Turn to Descore
  Intake.setVelocity(100,pct);
  Intake.spin(forward);
  wait(.3,sec);
  Drivetrain.turnFor(-40,degrees);
  while(Inertial14.heading()<(70)) {
    LeftDriveSmart.spin(reverse, 30, percent);
    RightDriveSmart.spin(forward,45, percent);
  }
  Drivetrain.stop();
  wait(.5,sec);
  FWingsRight.set(true);
  FWingsLeft.set(true);
  Drivetrain.driveFor(20, inches);
//Score Triball and Sit So They Can't Push From Front
  Drivetrain.driveFor(-10, inches);
  Intake.setVelocity(100,percentUnits::pct);
  Drivetrain.driveFor(-10, distanceUnits::in);
  Drivetrain.turnFor(-100,degrees);
  FWingsLeft.set(true);
  FWingsRight.set(true);
  Drivetrain.driveFor(5.5, distanceUnits::in);
  Intake.spin(reverse);
  wait(.5,sec);
  Drivetrain.setDriveVelocity(60, percentUnits::pct);
  Drivetrain.turnFor(-100,degrees);
  BWingsLeft.set(true);
  BWingsRight.set(true);
  Drivetrain.driveFor(-20.5, distanceUnits::in);
  Drivetrain.driveFor(4, distanceUnits::in);
}

void Skills_Auton(){
//Skills Auton
  Slapper.setVelocity(100,pct);
  //Slapper.spinFor(reverse, 30, sec, 100, velocityUnits::pct);
  Slapper.spin(reverse);
  Drivetrain.setDriveVelocity(50, percentUnits::pct);
  Drivetrain.setTurnVelocity(7, percentUnits::pct);
  Inertial14.resetHeading();
  Drivetrain.turnFor(5, degrees);
  while(Inertial14.heading()>(337.5)) {
    RightDriveSmart.spin(reverse,5, percent);
    LeftDriveSmart.spin(forward,10, percent);
  }
  Drivetrain.stop();
  wait(.5,sec);
  Drivetrain.driveFor(115, inches);
  wait(.2,sec);
  Slapper1.stop();
  Slapper2.stop();
  Drivetrain.stop();
//Calibrate Velocities
  Drivetrain.setDriveVelocity(20, percentUnits::pct);
  Drivetrain.setTurnVelocity(5, percentUnits::pct);
  Intake.setVelocity(100, percentUnits::pct);
//Drive Back To Match Load Zone
//Turn To Scoop Triballs
  FWingsLeft.set(true);
  Inertial14.resetHeading();
  Drivetrain.turnFor(-5, degrees);
  while(Inertial14.heading()<(20)) {
    RightDriveSmart.spin(forward, 15, percent);
    LeftDriveSmart.spin(reverse,5, percent);
  }
  Drivetrain.driveFor(31, inches);
  Drivetrain.stop();
  FWingsLeft.set(false);
  Drivetrain.turnFor(-5, degrees);
  while(Inertial14.heading()<(80)) {
    RightDriveSmart.spin(forward, 15, percent);
    LeftDriveSmart.spin(reverse,5, percent);
  }
//Score triballs from the side
  Drivetrain.setDriveVelocity(40,pct);
  Drivetrain.driveFor(17.5, inches);
  wait(.2,sec);
  Drivetrain.driveFor(-8, inches);
  wait(.4,sec);
  Drivetrain.driveFor(8, inches);
  wait(.2,sec);
  Drivetrain.driveFor(-20, inches);
  FWingsLeft.set(false);
//Part Two: Score from the middle
//Reset Velocities
  Drivetrain.setDriveVelocity(30, percentUnits::pct);
  Intake.setVelocity(100, percentUnits::pct);
  Drivetrain.setTurnVelocity(10, percentUnits::pct);
//Go to push spot
  Drivetrain.turnFor(-5, degrees);
  while(Inertial14.heading()<(145.5)) {
    RightDriveSmart.spin(forward, 15, percent);
    LeftDriveSmart.spin(reverse,5, percent);
  }
  Drivetrain.stop();
  Drivetrain.setDriveVelocity(50, percentUnits::pct);
  Drivetrain.driveFor(62.5 , distanceUnits::in);
  wait(.3, sec);
//Scoring Time:
//Go To Center
  Drivetrain.setTurnVelocity(5, percentUnits::pct);
  Inertial14.resetHeading();
  Drivetrain.turnFor(10, degrees);
  while(Inertial14.heading()>(295)) {
    RightDriveSmart.spin(reverse,2.5, percent);
    LeftDriveSmart.spin(forward,7.5, percent);
  }
  Drivetrain.stop();
  Drivetrain.driveFor(48.5, distanceUnits::in);
  wait(.2, timeUnits::sec);
  Drivetrain.setTurnVelocity(5, percentUnits::pct);
//Score
  Drivetrain.turnFor(-55,degrees);
  Drivetrain.setTurnVelocity(20,percentUnits::pct);
  Drivetrain.setDriveVelocity(35, percentUnits::pct);
  wait(.7,sec);
  BWingsLeft.set(true);
  BWingsRight.set(true);
  myTimer.reset();
    if (myTimer.time()< 3) {
      // If less than 3 seconds, continue doing something
      Drivetrain.driveFor(-28.5, distanceUnits::in);
    } else {
      // Exit the loop
      return;
    }
  wait(500, msec); // Use msec for milliseconds if using VEXcode V5
  Drivetrain.driveFor(15, distanceUnits::in);
  wait(.5,sec);
  Drivetrain.driveFor(-15, distanceUnits::in);
//Come back to Bar and Turn and Push Triballs
  Drivetrain.setDriveVelocity(40, percentUnits::pct);
  Drivetrain.driveFor(30, distanceUnits::in);
  BWingsLeft.set(false);
  BWingsRight.set(false);
//Inertial Turn to turn 90 degress
  Inertial14.resetHeading();
  Drivetrain.turnFor(10, degrees);
  while(Inertial14.heading()>(270)) {
    RightDriveSmart.spin(reverse,5, percent);
    LeftDriveSmart.spin(forward,15, percent);
  }
//Drive Back To Bar and Turn To Push
  Drivetrain.driveFor(-25, inches);;
  Drivetrain.turnFor(10, degrees);
  while(Inertial14.heading()>(180)) {
    RightDriveSmart.spin(reverse,5, percent);
    LeftDriveSmart.spin(forward,15, percent);
  }
  Drivetrain.driveFor(34, distanceUnits::in);
  FWingsLeft.set(true);
  FWingsRight.set(true);
  wait(.3,sec);
  Drivetrain.driveFor(-34, distanceUnits::in);
  FWingsLeft.set(false);
  FWingsRight.set(false);
//Push From the Center
  Drivetrain.setTurnVelocity(10,percent);
  Drivetrain.turnFor(-55,degrees);
  Drivetrain.driveFor(-35, distanceUnits::in);
  Drivetrain.turnFor(-55,degrees);
  BWingsLeft.set(true);
  BWingsRight.set(true);
  Drivetrain.driveFor(-30, distanceUnits::in);
  BWingsLeft.set(false);
  BWingsRight.set(false);
}



void Near_Side_Safe(){
//Set Velocities
  Intake.setVelocity(100,percentUnits::pct);
  Intake.spin(reverse);
  wait(.2,sec);
  Intake.stop();
  calibrateIntertialSensor();
  Drivetrain.setDriveVelocity(30, percentUnits::pct);
  Intake.setVelocity(100, percentUnits::pct);
//Remove Ball in Match Load Zone
  Drivetrain.driveFor(15,inches);
  BWingsLeft.set(true);
  BWingsRight.set(true);
  wait(1,sec);
  Drivetrain.driveFor(-13.5,inches);
  BWingsLeft.set(false);
  BWingsRight.set(false);
  Inertial14.resetRotation();
  Drivetrain.setTurnVelocity(5, percentUnits::pct);
  Drivetrain.turnFor(27.5, degrees);
  Drivetrain.stop(); 
  Drivetrain.driveFor(-40,inches);
  Drivetrain.stop();
  BWingsRight.set(true);
  Drivetrain.setDriveVelocity(15,percentUnits::pct);
  wait(.5,sec);
  Drivetrain.driveFor(-13,inches);
  

}

void Far_Side_Safe(){
//Far Side Win Point
//Part One: Three Balls
//Calibrate Velocities and Sensors
  Drivetrain.setDriveVelocity(50, percentUnits::pct);
  Intake.setVelocity(100, percentUnits::pct);
  printf("Far_Side_WinPoint");
//Intake First Triball
  Intake.spin(forward);
  wait(.5, timeUnits::sec);
//Drive Back To Match Load Zone
  Drivetrain.driveFor(-33,inches);
//Turn To Goal With Inertial and Descore From Match Zone
  Drivetrain.turnFor(20, degrees);
  while(Inertial14.heading()<(245)) {
    LeftDriveSmart.spin(reverse, 30, percent);
    RightDriveSmart.spin(forward,45, percent);
  }
  Drivetrain.stop(); 
  BWingsLeft.set(true);
  BWingsRight.set(true);
  Drivetrain.driveFor(-25,inches);
  Drivetrain.turnFor(15, degrees);
  BWingsLeft.set(false);
  BWingsRight.set(false);
  Drivetrain.driveFor(-10,inches);
//Score All 3
//Go Forward and Turn
  Inertial14.resetRotation();
  Drivetrain.turnFor(-10, degrees);
  while(Inertial14.heading() > (130)) {
    LeftDriveSmart.spin(forward, 40, percent);
    RightDriveSmart.spin(reverse,50, percent);
  }
  Drivetrain.stop(); 
//Push It All In
  Intake.spin(forward);
  Drivetrain.setDriveVelocity(30, percentUnits::pct);
  wait(.2, sec);
  Drivetrain.driveFor(11,inches);
  Drivetrain.driveFor(-10,inches);
  wait(.2, sec);
  Drivetrain.driveFor(11,inches);
  Drivetrain.driveFor(-12,inches);

//Part Two: Three Balls
//Reset Velocities
  Drivetrain.setDriveVelocity(40, percentUnits::pct);
  Intake.setVelocity(100, percentUnits::pct);
  Drivetrain.setTurnVelocity(20, percentUnits::pct);
//Second Triball
//Turn and Intake
  Inertial14.resetRotation();
  Drivetrain.turnFor(10, degrees);
  while(Inertial14.heading() > (61)) {
    LeftDriveSmart.spin(reverse, 25, percent);
    RightDriveSmart.spin(forward,35, percent);
  }
  Drivetrain.stop(); 
  Intake.spin(forward,100, percentUnits::pct);
  Drivetrain.setDriveVelocity(50, percentUnits::pct);
  Drivetrain.driveFor(67, distanceUnits::in);
  wait(.3, sec);
//Spin and Outake 
  Intake.setVelocity(10,percent); 
  Inertial14.resetRotation();
  Drivetrain.turnFor(-80, degrees);
  Drivetrain.driveFor(15, distanceUnits::in);
  wait(.2,sec);
  Drivetrain.stop(); 
  Intake.spin(reverse,60, percentUnits::pct);
  wait(.4, sec);
//Third Triball
//Intake Next
  Drivetrain.turnFor(60, degrees);
  Intake.spin(forward,100, percentUnits::pct);
  Drivetrain.driveFor(32.5, distanceUnits::in);
  wait(.2, timeUnits::sec);
  Drivetrain.setTurnVelocity(30, percentUnits::pct);
//Score With Wings
  Intake.setVelocity(100,percentUnits::pct);
  Drivetrain.driveFor(-12, distanceUnits::in);
  Drivetrain.turnFor(-72.5,degrees);
  FWingsLeft.set(true);
  FWingsRight.set(true);
  Intake.spin(reverse);
  wait(.2,sec);
  Drivetrain.setDriveVelocity(60, percentUnits::pct);
  Drivetrain.driveFor(38.5, distanceUnits::in);
}

void test_errorloop(){
  
}

void holonomic_odom_test(){
}