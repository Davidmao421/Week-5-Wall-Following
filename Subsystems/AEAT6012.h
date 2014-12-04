#ifndef AEAT6012_H
#define AEAT6012_H

#include <WPILIB.h>
#include <SPI.h>
#include "SensorBase.h"

class DigitalInput;
class DigitalOutput;


class AEAT_Sample {
public:
	uint16_t	position;
	unsigned long		timestamp; // milliseconds from currentTimeMillis()
	
	AEAT_Sample(void);
	void clear(void);
	
	// allow default copy constructor & assignment operator
	AEAT_Sample( AEAT_Sample & x )
	{
		if (&x != this)
		{
			position = x.position;
			timestamp = x.timestamp;
		}
	}
	
	AEAT_Sample & operator = ( AEAT_Sample & x )
	{
		if (&x != this)
		{
			position = x.position;
			timestamp = x.timestamp;
		}
		return *this;
	}
};


/**
 * AEAT6012 Encoder.
 * 
 * This class assumes the sensor is wired in 4-wire SPI mode.
 */
class AEAT6012 : public SensorBase
{
public:
	enum data_resolution {RES_12_BIT = 12,
							RES_10_BIT = 10};


	AEAT6012(DigitalOutput &clk, DigitalInput &miso,
		DigitalOutput &cs, data_resolution resolution = RES_12_BIT);

	virtual ~AEAT6012();

	uint16_t getEncoderPosition(void);  // raw 12 bit number
	float    getPosition(void) { return getEncoderPosition() * getConversion(); };  // degrees
	float    getConversion(void); // degrees per bit
	unsigned long     getTimestamp(void); // time in ms
	
	uint16_t getEncoderDelta(void);  // relative to previous reading (12 bit number)
	long     getDeltaTime(void); // time in ms

	void	resetHistory(void) { clearSamples(); m_count = 0; };

private:
	AEAT6012(AEAT6012 &copy); // disallow copy constructor
	AEAT6012 &operator=(AEAT6012&);  // disallow assignment operator

	void init(DigitalOutput *pclk,  DigitalInput *pmiso,
		DigitalOutput *pcs, data_resolution resolution);
	
	void clearSamples(void){ m_count = 0; };
	unsigned long timestamp(void);

	DigitalOutput		*m_pck;  // clock
	DigitalInput		*m_pmiso; // MISO:  data in
	DigitalOutput		*m_pcs;   // chip select
	SPI					*m_pspi;	  // SPI subsystem
	data_resolution		m_resolution; // number of bits per word

	long				m_count; // number of samples since last call to resetHistory()	
	AEAT_Sample			m_samples[3]; // 0: current; 1: previous; 2: first after reset
};



#endif // AEAT6012_H
