#include "TurnCCWSlightly.h"

TurnCCWSlightly::TurnCCWSlightly() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires (tankDrive);
}

// Called just before this Command runs the first time
void TurnCCWSlightly::Initialize() {
	SetTimeout(0.1);
}

// Called repeatedly when this Command is scheduled to run
void TurnCCWSlightly::Execute() {
	tankDrive-> tankDrive(-0.5,0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool TurnCCWSlightly::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void TurnCCWSlightly::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnCCWSlightly::Interrupted() {
}
