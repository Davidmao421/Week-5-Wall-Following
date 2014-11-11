#include "FollowWall.h"

FollowWall::FollowWall() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(tankDrive);
}

// Called just before this Command runs the first time
void FollowWall::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void FollowWall::Execute() {
	if(tankDrive->getIRVoltage() < 0.7)
		tankDrive->tankDrive(-0.6,-0.4);
	else
		tankDrive->tankDrive(-0.4,-0.6);
}

// Make this return true when this Command no longer needs to run execute()
bool FollowWall::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void FollowWall::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FollowWall::Interrupted() {
}
