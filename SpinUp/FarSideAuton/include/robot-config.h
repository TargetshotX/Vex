using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern controller Controller2;
extern drivetrain Drivetrain;
extern motor Flywheel;
extern motor Intake;
extern digital_out Expansion1;
extern digital_out Expansion2;
extern digital_out Expansion3;
extern digital_out Expansion4;
extern digital_out Indexer;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
void  leftSideAuton( void );
void  pre_auton( void );