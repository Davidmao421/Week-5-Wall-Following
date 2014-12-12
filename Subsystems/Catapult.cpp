#include "Catapult.h"
#include "../Robotmap.h"

Catapult::Catapult() : Subsystem("Catapult") {
	motor = new Jaguar (CATAPULT_MOTOR);
}
    
void Catapult::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Catapult::Shoot(float val){
	motor->Set(val);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
