using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor rightDrive1;
extern motor rightDrive2;
extern motor rightDrive3;
extern motor leftDrive1;
extern motor leftDrive2;
extern motor leftDrive3;
extern motor_group LeftDriveSmart;
extern motor_group RightDriveSmart;
extern drivetrain Drivetrain;
extern motor Slapper;
extern motor Intake;
extern digital_out Elevation;
extern digital_out Wings;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
void pre_auton(void);
void Autons(void);
void Motor_Functions(void);
void Piston_Functions(void);
void Drivetrain_Function(void);
void calibrateIntertialSensor(void);

