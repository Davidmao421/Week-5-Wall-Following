#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/Drive.h"
#include "CommandBase.h"

// testing the Magnetic Absolute Encoder
#include "RobotMap.h"
#include "Subsystems/AbsoluteEncoder.h"

class CommandBasedRobot : public IterativeRobot {
private:
	Command *driveCommand;
	LiveWindow *lw;
	/*
	DigitalInput  data( ABSOLUTEENCODER_MISO );
	DigitalOutput clock( ABSOLUTEENCODER_CLOCK );
	DigitalOutput chipselect( ABSOLUTEENCODER_CHIPSELECT ); 
	AbsoluteEncoder CatapultTestEncoder( clock, data, chipselect );
	*/
	virtual void RobotInit() {
		CommandBase::init();
		lw = LiveWindow::GetInstance();
		driveCommand = new Drive();
	}
	
	virtual void AutonomousInit() {
	}
	
	virtual void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		driveCommand->Start();
	}
	
	virtual void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
		SmartDashboard::PutNumber("IR Voltage", CommandBase::tankDrive->getIRVoltage());
		SmartDashboard::PutNumber("Servo", CommandBase::arm->get());
	}
	
	virtual void TestPeriodic() {
		lw->Run();
	}
};

START_ROBOT_CLASS(CommandBasedRobot);

