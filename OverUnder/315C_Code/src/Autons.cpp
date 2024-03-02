#include "vex.h"
#include "robot-config.h"

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
  Intake.spin(reverse);
  Drivetrain.setDriveVelocity(30, percentUnits::pct);
  wait(.2, sec);
  Intake.spin(forward);
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
  Slapper.spinFor(reverse, 30, sec, 100, velocityUnits::pct);
  Slapper.spin(reverse);
  Drivetrain.setDriveVelocity(50, percentUnits::pct);
  Drivetrain.setTurnVelocity(5, percentUnits::pct);
  Drivetrain.turnFor(18.5, degrees);
  while(Inertial14.heading()<(18.5)) {
    LeftDriveSmart.spin(reverse, 15, percent);
    RightDriveSmart.spin(forward,30, percent);
  }
  Drivetrain.stop();
  wait(.5,sec);
  Drivetrain.driveFor(115, inches);
  wait(.5,sec);
  Slapper1.stop();
  Slapper2.stop();
  Drivetrain.stop();
//Calibrate Velocities
  Drivetrain.setDriveVelocity(35, percentUnits::pct);
  Drivetrain.setTurnVelocity(5, percentUnits::pct);
  Intake.setVelocity(100, percentUnits::pct);
//Drive Back To Match Load Zone
//Turn To Middle
  Inertial14.resetRotation();
  Drivetrain.turnFor(-35, degrees);
  while(Inertial14.heading()>(305)) {
    LeftDriveSmart.spin(forward, 35, percent);
    RightDriveSmart.spin(reverse,25, percent);
  }
  Drivetrain.driveFor(20, inches);  
//Part Two: Score from the middle
//Reset Velocities
  Drivetrain.setDriveVelocity(30, percentUnits::pct);
  Intake.setVelocity(100, percentUnits::pct);
  Drivetrain.setTurnVelocity(10, percentUnits::pct);
//Go to push spot
  FWingsRight.set(true);
  Intake.spin(reverse,100, percentUnits::pct);
  Inertial14.resetRotation();
  Drivetrain.turnFor(-45, degrees);
  while(Inertial14.heading()<(105)) {
    RightDriveSmart.spin(forward, 35, percent);
    LeftDriveSmart.spin(reverse,25, percent);
  }
  Drivetrain.stop(); 
  Drivetrain.setDriveVelocity(50, percentUnits::pct);
  Drivetrain.driveFor(46, distanceUnits::in);
  wait(.3, sec);
//Scoring Time:
//Go To Center
  Drivetrain.setTurnVelocity(5, percentUnits::pct);
  Drivetrain.turnFor(24, degrees);
  Intake.spin(reverse,100, percentUnits::pct);
  Drivetrain.driveFor(50, distanceUnits::in);
  wait(.2, timeUnits::sec);
  Drivetrain.setTurnVelocity(20, percentUnits::pct);
//Score With Wings
  Drivetrain.turnFor(-50,degrees);
  BWingsLeft.set(true);
  BWingsRight.set(true);
  Drivetrain.setDriveVelocity(30, percentUnits::pct);
  wait(.7,sec);
  Drivetrain.driveFor(-36.5, distanceUnits::in);
  Drivetrain.driveFor(15, distanceUnits::in);
  wait(.5,sec);
  Drivetrain.driveFor(-15, distanceUnits::in);
//Come back to Bar and Turn and Push Triballs
  Drivetrain.setDriveVelocity(60, percentUnits::pct);
  Drivetrain.driveFor(15, distanceUnits::in);
  BWingsLeft.set(false);
  BWingsRight.set(false);
  Inertial14.resetRotation();
  Drivetrain.turnFor(30, degrees);
  while(Inertial14.heading()<(90)) {
    LeftDriveSmart.spin(reverse, 30, percent);
    RightDriveSmart.spin(forward,45, percent);
  }
  Drivetrain.driveFor(21, distanceUnits::in);
  Drivetrain.turnFor(39.5, degrees);
  BWingsRight.set(true);
  Drivetrain.driveFor(-25, distanceUnits::in);
//Scoop and Push Again
  Drivetrain.setDriveVelocity(20, percentUnits::pct);
  Inertial14.resetRotation();
  Drivetrain.turnFor(-57.5, degrees);
  while(Inertial14.heading()>(215)) {
    LeftDriveSmart.spin(forward, 45, percent);
    RightDriveSmart.spin(reverse,30, percent);
  }
  BWingsRight.set(true);
  BWingsLeft.set(true);
  Drivetrain.setDriveVelocity(90, percentUnits::pct);
  wait(.5,sec);
  Drivetrain.driveFor(-30, distanceUnits::in);
  Drivetrain.driveFor(15, distanceUnits::in);
  wait(.2,sec);
  Drivetrain.driveFor(-18, distanceUnits::in);
  Drivetrain.driveFor(4, distanceUnits::in);
  BWingsLeft.set(false);
  BWingsRight.set(false);
  wait(.5,sec);
//Go to Side and Push
  Drivetrain.driveFor(21, distanceUnits::in);
  Drivetrain.turnFor(39.5, degrees);
  BWingsRight.set(true);
  Drivetrain.driveFor(-25, distanceUnits::in);
  Drivetrain.setDriveVelocity(40, percentUnits::pct);
  Inertial14.resetRotation();
  Drivetrain.turnFor(-57.5, degrees);
  while(Inertial14.heading()>(215)) {
    LeftDriveSmart.spin(forward, 45, percent);
    RightDriveSmart.spin(reverse,30, percent);
  }
  BWingsRight.set(true);
  BWingsLeft.set(true);
  Drivetrain.setDriveVelocity(90, percentUnits::pct);
  wait(.5,sec);
  Drivetrain.driveFor(-30, distanceUnits::in);
  Drivetrain.driveFor(15, distanceUnits::in);
  wait(.2,sec);
  Drivetrain.driveFor(-18, distanceUnits::in);
  Drivetrain.driveFor(4, distanceUnits::in);
  BWingsLeft.set(false);
  BWingsRight.set(false);
  wait(.5,sec);

  

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

void tank_odom_test(){
  
}

void holonomic_odom_test(){
}