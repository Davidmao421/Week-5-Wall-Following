#ifndef ABSOLUTEENCODER_H
#define ABSOLUTEENCODER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "AEAT6012.h"

class AbsoluteEncoder: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	AEAT6012 * AbsEncoderInstance;
public:
	//AbsoluteEncoder();
	AbsoluteEncoder( DigitalOutput * clock, DigitalInput * data, DigitalOutput * chipselect );
	void InitDefaultCommand();
	
	// true=ok. false means error reading data.
	bool GetDegreesAndTime( float * degrees, unsigned long * clockMilliseconds );
};

#endif
