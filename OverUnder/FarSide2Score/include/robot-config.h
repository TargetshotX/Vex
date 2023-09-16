using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern drivetrain Drivetrain;
extern motor Cata;
extern motor Intake;
extern motor Elevtation1;
extern motor Elevtation2;
extern motor_group Elevation;
extern digital_out Wings1;
extern digital_out Wings2;




/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
void pre_auton(void);
void Autons(void);

void  calibrateIntertialSensor( void );