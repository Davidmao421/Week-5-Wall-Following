#ifndef TANKDRIVE_H
#define TANKDRIVE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author prath_000
 */
class TankDrive: public Subsystem {
private:
	RobotDrive* drive;
	AnalogChannel* ir;
	
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	TankDrive();
	void InitDefaultCommand();
	void tankDrive(float left, float right);
	float getIRVoltage();
};

#endif
