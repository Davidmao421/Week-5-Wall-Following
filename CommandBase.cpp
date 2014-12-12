#include "CommandBase.h"
#include "Subsystems/TankDrive.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
TankDrive* CommandBase::tankDrive = NULL;
OI* CommandBase::oi = NULL;
Arm* CommandBase::arm = NULL;
Catapult* CommandBase::catapult = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	tankDrive = new TankDrive();
	oi = new OI();
	arm = new Arm();
	catapult = new Catapult();
}
