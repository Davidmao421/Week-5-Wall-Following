#include "TankDrive.h"
#include "../Robotmap.h"
#include "../Commands/Drive.h"

TankDrive::TankDrive() : Subsystem("TankDrive") {
	drive = new RobotDrive(new Victor(LEFT_VICTOR), new Victor(RIGHT_VICTOR));
	ir = new AnalogChannel(1,IR_CHANNEL);
}
    
void TankDrive::InitDefaultCommand() {
	SetDefaultCommand(new Drive());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void TankDrive::tankDrive(float l, float r){
	drive->TankDrive(l,r);
}

float TankDrive::getIRVoltage(){
	return ir->GetVoltage();
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
