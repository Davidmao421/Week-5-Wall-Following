#include "LowerArm.h"

LowerArm::LowerArm() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void LowerArm::Initialize() {
	arm->set(0);
}

// Called repeatedly when this Command is scheduled to run
void LowerArm::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool LowerArm::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void LowerArm::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerArm::Interrupted() {
}
