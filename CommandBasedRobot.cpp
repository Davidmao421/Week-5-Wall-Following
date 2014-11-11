#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/Drive.h"
#include "CommandBase.h"

class CommandBasedRobot : public IterativeRobot {
private:
	Command *driveCommand;
	LiveWindow *lw;
	
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
	}
	
	virtual void TestPeriodic() {
		lw->Run();
	}
};

START_ROBOT_CLASS(CommandBasedRobot);

