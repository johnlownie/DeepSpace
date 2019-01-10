#include "Robot.h"

#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>

// Subsystems
DriveTrain *Robot::m_DriveTrain;
OI *Robot::m_oi;

void Robot::RobotInit() {
  // Print out a banner to the shell
  // Some backslashes are doubled in order for them to print properly
  std::cout << "   Welcome 5024!" << std::endl;
  std::cout << "-------------------" << std::endl;
  std::cout << "Robot Starting.."<< std::endl;

  // Subsystems
  this->m_DriveTrain = new DriveTrain();
  this->m_oi = new OI();

  // Init camera
  std::cout << "Starting CameraServer.." << std::endl;
  this->frontCam = frc::CameraServer::GetInstance()->StartAutomaticCapture("Front Cam", 1);
  this->backCam  = frc::CameraServer::GetInstance()->StartAutomaticCapture("Back Cam", 0);

  // this->frontServer = frc::CameraServer::GetInstance()->GetServer();
  // this->backServer  = frc::CameraServer::GetInstance()->GetServer();

  // // Sinks to keep camera connections open
  // this->frontCvsink = new cs::CvSink("frontCam");
  // this->frontCvsink->SetSource(this->frontCam);
  // this->frontCvsink->SetEnabled(true);
  
  // this->backCvsink = new cs::CvSink("backCam");
  // this->backCvsink->SetSource(this->backCam);
  // this->backCvsink->SetEnabled(true);

  // // Set server sources
  // this->frontServer.SetSource(this->frontCam);
  // this->backServer.SetSource(this->backCam);
	
	// Init commands
  std::cout << "Creating Commands.." << std::endl;
  this->pTriggerDrive = new TriggerDrive();

  // Set robot loop speed (in seconds)
  std::cout << "Setting Period Time.." << std::endl;
  // this->SetPeriod(0.01);
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() { frc::Scheduler::GetInstance()->Run(); }

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString code to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional commands to the
 * chooser code above (like the commented example) or additional comparisons to
 * the if-else structure below with additional strings & commands.
 */
void Robot::AutonomousInit() {
  // std::string autoSelected = frc::SmartDashboard::GetString(
  //     "Auto Selector", "Default");
  // if (autoSelected == "My Auto") {
  //   m_autonomousCommand = &m_myAuto;
  // } else {
  //   m_autonomousCommand = &m_defaultAuto;
  // }

  // m_autonomousCommand = m_chooser.GetSelected();

  // if (m_autonomousCommand != nullptr) {
  //   m_autonomousCommand->Start();
  // }
}

void Robot::AutonomousPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  // if (m_autonomousCommand != nullptr) {
  //   m_autonomousCommand->Cancel();
  //   m_autonomousCommand = nullptr;
  // }

  if (this->pTriggerDrive != nullptr) {
		this->pTriggerDrive->Start();
	}
}

void Robot::TeleopPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main(){
  // Start the robot
  WinGame(Robot);
  return 1;
}
#endif