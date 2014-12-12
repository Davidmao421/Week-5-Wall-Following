#include "Shoot.h"

Shoot::Shoot() {
	Requires(catapult);
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void Shoot::Initialize() {
	Preferences* pref = Preferences::GetInstance(); 
	printf("shooting %f %f", pref->GetDouble("catapult"), pref->GetDouble("cataspeed"));
	SetTimeout(pref->GetDouble("catapult", .1));
	catapult->Shoot(pref->GetDouble("cataspeed", -1));
}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void Shoot::End() {
	catapult->Shoot(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted() {
}
