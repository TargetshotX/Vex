#include "vex.h"//define 
#include "robot-config.h"
void Piston_Functions(void){
    //Wings:
    if (Controller1.ButtonY.pressing()) {
      BWingsLeft.set(true);
      BWingsRight.set(true);

    }
    if (Controller1.ButtonA.pressing()) {
      BWingsLeft.set(false);
      BWingsRight.set(false);
    }

    //Wings
    if (Controller1.ButtonX.pressing()) {
      FWingsLeft.set(true);
      FWingsRight.set(true);
    }
    if (Controller1.ButtonB.pressing()) {
      FWingsLeft.set(false);
      FWingsRight.set(false);
    }
    //Elevation:
    if (Controller1.ButtonUp.pressing()) {
      Elevation.set(true);
    }
    if (Controller1.ButtonDown.pressing()) {
      Elevation.set(false);
    }

}