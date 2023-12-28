#include "vex.h"//define 
void Piston_Functions(void){
    bool Controller1UpDownControlMotorsStopped = true;
    //Elevation
      // check the Up/Down status to control Elevation
    if (Controller1.ButtonUp.pressing()) {
        Elevation.set(true);
    } else if (Controller1.ButtonDown.pressing()) {
        Elevation.set(false); 
    }

    //Wings:
    if (Controller1.ButtonY.pressing()) {
       Wings.set(true);
    
    }
    if (Controller1.ButtonA.pressing()) {
       Wings.set(false);
    }
}
