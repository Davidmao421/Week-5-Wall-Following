#include "OI.h"
#include "Commands/RotateCW90.h"
#include "Commands/RotateCCW90.h"
#include "Commands/Drive2Secs.h"
#include "Commands/TurnAndDrive.h"
#include "Commands/TurnCWSlightly.h"
#include "Commands/TurnCCWSlightly.h"
#include "Commands/FollowWall.h"
#include "Commands/LowerArm.h"
#include "Commands/LiftArm.h"
#include "Commands/Shoot.h"

OI::OI() {
	left = new Joystick(JOYSTICK_1);
	right = new Joystick(JOYSTICK_2);
	Button* button1 = new JoystickButton(left, 5);
	Button* button2 = new JoystickButton(left, 6);
	Button*	button3 = new JoystickButton(left, 7);
	Button* button4 = new JoystickButton(left, 8);
	Button* button5 = new JoystickButton(left, 9);
	Button* button6 = new JoystickButton(left, 10);
	Button* button7 = new JoystickButton(left, 4);
	Button* button8 = new JoystickButton (left, 1);
	Button* button9 = new JoystickButton (left, 2);
	button1->WhenPressed(new Shoot());
	button2->WhenPressed(new RotateCCW90());
	button3->WhenPressed(new Drive2Secs());
	button4->WhenPressed(new TurnAndDrive());
	button5->WhenPressed(new TurnCWSlightly());
	button6->WhenPressed(new TurnCCWSlightly());
	button7->WhileHeld(new FollowWall());
	button8->WhenPressed(new Shoot());
	button9->WhenPressed(new LiftArm());
}
/*while (1){
	printf("%f\n", ir -> GetVoltage());
}*/

float OI::getLeftY(){
	return left->GetY();
}

float OI::getRightY(){
	return right->GetY();
}

