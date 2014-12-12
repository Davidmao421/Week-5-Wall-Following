#ifndef CATAPULT_H
#define CATAPULT_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author David Mao
 */
class Catapult: public Subsystem {
private:
	Jaguar* motor;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Catapult();
	void InitDefaultCommand();
	void Shoot(float);
};

#endif
