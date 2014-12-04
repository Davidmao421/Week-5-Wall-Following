#include "Arm.h"
#include "../Robotmap.h"

Arm::Arm() : Subsystem("Arm") {
	servo = new Servo(ARM_SERVO);
}
    
void Arm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Arm::set(float val){
	servo->Set(val);
}

float Arm::get(){
	return servo->Get();
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
