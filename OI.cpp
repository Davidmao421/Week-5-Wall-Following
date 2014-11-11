#include "OI.h"
#include "Commands/RotateCW90.h"
#include "Commands/RotateCCW90.h"
#include "Commands/Drive2Secs.h"
#include "Commands/TurnAndDrive.h"
#include "Commands/TurnCWSlightly.h"
#include "Commands/TurnCCWSlightly.h"
#include "Commands/FollowWall.h"
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
	button1->WhenPressed(new RotateCW90());
	button2->WhenPressed(new RotateCCW90());
	button3->WhenPressed(new Drive2Secs());
	button4->WhenPressed(new TurnAndDrive());
	button5->WhenPressed(new TurnCWSlightly());
	button6->WhenPressed(new TurnCCWSlightly());
	button7->WhileHeld(new FollowWall());
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

