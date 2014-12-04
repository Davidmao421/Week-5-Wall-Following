#ifndef ARM_H
#define ARM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author David Mao
 */
class Arm: public Subsystem {
private:
	Servo* servo;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Arm();
	void InitDefaultCommand();
	void set(float val);
	float get();
};

#endif
