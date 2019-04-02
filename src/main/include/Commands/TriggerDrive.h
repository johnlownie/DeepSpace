//! An interface command for driving the robot with an xbox controller
#ifndef _TRIGGERDRIVE_HG_
#define _TRIGGERDRIVE_HG_

#include <frc/commands/Command.h>
#include <Subsystems/DriveTrain.h>
#include "RobotMap.h"
#include <frc/GenericHID.h>
#include "Commands/ClimbManager.h"
#include <AHRS.h>

class TriggerDrive : public frc::Command {
public:
    TriggerDrive();               //!< Class constructor
    void Initialize() override;   //!< Runs once on initalization
    void Execute() override;      //!< Called in a loop during Teleop
    bool IsFinished() override;   //!< Runs after execute, return true to end the command
    void End() override;          //!< Runs once when IsFinished() returns true
    void Interrupted() override;  //!< Runs once if the command is forced to stop
  
private:
    double xSpeed;                  //!< Store the frequently accessed xSpeed for faster runtime
    double zRotation;               //!< Store the frequently accessed zRotation for faster runtime
    double xSpeedPrev;              //!< Store the last used x speed for difference calculations
    double zRotationPrev;           //!< Store the last used z rotation for difference calculations
    bool isReversed;                //!< Boolean for reversing x direction
	frc::XboxController* pJoyDrive; //!< Pointer to the driver controller
    AHRS* pGyro;                    //!< Pointer to the gyro

};

#endif // _TRIGGERDRIVE_HG_