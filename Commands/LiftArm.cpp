#include "LiftArm.h"

LiftArm::LiftArm() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void LiftArm::Initialize() {
	arm->set(0.6);
}

// Called repeatedly when this Command is scheduled to run
void LiftArm::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool LiftArm::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void LiftArm::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftArm::Interrupted() {
}
