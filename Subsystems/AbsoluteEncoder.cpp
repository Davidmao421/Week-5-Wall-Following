#include "../Robotmap.h"
#include "AbsoluteEncoder.h"

//// singleton. This is the absolute encoder for the catapult.
//DigitalOutput g_Catapult_AbsEnc_DO_Clock( ABSOLUTEENCODER_CLOCK );
//DigitalOutput g_Catapult_AbsEnc_DO_ChipSelect( ABSOLUTEENCODER_CHIPSELECT );
//DigitalInput  g_Catapult_AbsEnc_DI_Data( ABSOLUTEENCODER_MISO );
//AEAT6012 g_Catapult_AbsEnc( g_Catapult_AbsEnc_DO_Clock,
//							g_Catapult_AbsEnc_DI_Data,
//							g_Catapult_AbsEnc_DO_ChipSelect );
							
AbsoluteEncoder::AbsoluteEncoder( DigitalOutput * clock, DigitalInput * data, DigitalOutput * chipselect ) 
: Subsystem("AbsoluteEncoder") // , AbsEncoderInstance( clock, data, chipselect )
{
	AbsEncoderInstance = new AEAT6012( *clock, *data, *chipselect );
}
    
void AbsoluteEncoder::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.



bool AbsoluteEncoder::GetDegreesAndTime( float * degrees, unsigned long * clockMilliseconds )
{
//	if ( ! degrees || ! clockMilliseconds )
//		return false;
//	
//	*degrees = AbsEncoderInstance.getPosition();
//	*clockMilliseconds = AbsEncoderInstance.getTimestamp();
	
	return true;
}
