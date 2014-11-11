#include "RotateCCW90.h"

RotateCCW90::RotateCCW90() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(tankDrive);
}

// Called just before this Command runs the first time
void RotateCCW90::Initialize() {
	SetTimeout(0.25);
}

// Called repeatedly when this Command is scheduled to run
void RotateCCW90::Execute() {
	tankDrive->tankDrive(-0.6,0.6);
}

// Make this return true when this Command no longer needs to run execute()
bool RotateCCW90::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void RotateCCW90::End() {
	tankDrive->tankDrive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateCCW90::Interrupted() {
}
