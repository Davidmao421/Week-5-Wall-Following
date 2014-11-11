#include "Drive2Secs.h"

Drive2Secs::Drive2Secs() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(tankDrive);
}

// Called just before this Command runs the first time
void Drive2Secs::Initialize() {
	SetTimeout(0.5);
}

// Called repeatedly when this Command is scheduled to run
void Drive2Secs::Execute() {
	tankDrive->tankDrive(-0.6,-0.6);
}

// Make this return true when this Command no longer needs to run execute()
bool Drive2Secs::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void Drive2Secs::End() {
	tankDrive->tankDrive(0,0);
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive2Secs::Interrupted() {
}
