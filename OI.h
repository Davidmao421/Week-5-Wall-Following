#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Robotmap.h"


class OI {
private:
	Joystick* left;
	Joystick* right;

public:
	OI();
	float getLeftY();
	float getRightY();
};

#endif
