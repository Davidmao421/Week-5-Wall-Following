#include <WPILIb.h>
#include "networktables2/util/System.h"
#include "AEAT6012.h"


AEAT_Sample::AEAT_Sample(void) : position(0), timestamp(0) {
	; // empty
}

void AEAT_Sample::clear(void) {
	position = 0;
	timestamp = 0;
}


const float AEAT6012_DEG_PER_BIT = 360.0 / 4096.0;
const float AEAT6010_DEG_PER_BIT = 360.0 / 1024.0;

AEAT6012::AEAT6012(DigitalOutput &ck,
		DigitalInput &miso,
		DigitalOutput &cs, 
		data_resolution resolution) 
	: m_pck(&ck),
	m_pmiso(&miso),
	m_pcs(&cs),
	m_pspi(NULL),
	m_resolution(resolution),
	m_count(0)
{
	init(&ck, &miso, &cs, resolution);
}


void AEAT6012::init(DigitalOutput *pck,
		DigitalInput *pmiso,
		DigitalOutput *pcs, 
		data_resolution resolution) {
	
	// assert(pclk);
	// assert(pmiso);
	// assert(pcs);
	// asssert(resolution == RES_12_BIT || resolution == RES_10_BIT);
	
	if (pck && pmiso && pcs) {
		m_pck = pck;
		m_pmiso = pmiso;
		m_pcs = pcs;
		m_resolution = resolution;
		
		m_pspi = new SPI(pck, pmiso);
		
		if (m_pspi) {
			m_pspi->SetMSBFirst();  // ?
			m_pspi->SetSampleDataOnRising(); // ?
			m_pspi->SetClockActiveLow(); // ?
			
			m_pspi->SetSlaveSelect(pcs, SPI::kChipSelect, false);
			
			m_pspi->SetBitsPerWord(m_resolution);
			m_pspi->ApplyConfig();
			m_pspi->ClearReceivedData();
		}
	}
	
	resetHistory();
}

AEAT6012::~AEAT6012() {
	if (m_pspi) {
		delete m_pspi;
		m_pspi = NULL;
	}
	
	if (m_pck) {
		delete m_pck;
		m_pck = NULL;
	}
	
	if (m_pcs) {
		delete m_pcs;
		m_pcs = NULL;
	}
	
	if (m_pmiso) { 
		delete m_pmiso;
		m_pmiso = NULL;
	}
}


uint16_t AEAT6012::getEncoderPosition(void) {
	uint16_t position = 0;
	
	// assert(m_pspi);
	
	if(m_pspi)
	{
		position = (uint16_t)m_pspi->Read();

		// swap bytes
		position = ((position >> 8) & 0xFF) | (position << 8);
		
		// m_samples[0] is the current reading;
		// m_samples[1] is the previous;
		// m_samples[2] is the first reading;
		
		// if there is a previous sample, copy the last one
		if (m_count >= 1) {
			m_samples[1] = m_samples[0];
		}
		
		m_samples[0].position = position;
		m_samples[0].timestamp = currentTimeMillis();

		// if the first sample, save it until reset history
		if (m_count == 0) {
			m_samples[2] = m_samples[0];
		}
		
		m_count++;
	}
	
	return position;
}


float    AEAT6012::getConversion(void) { // degrees per bit
	float res = AEAT6012_DEG_PER_BIT;
	
	if (m_resolution == RES_10_BIT) {
		res = AEAT6010_DEG_PER_BIT;
	}
	
	return res;
}


unsigned long     AEAT6012::getTimestamp(void) { // time in ms
	unsigned long timestamp = 0;
	
	if (m_count > 0)
	{
		timestamp = m_samples[0].timestamp;
	}
	
	return timestamp;
}


uint16_t AEAT6012::getEncoderDelta(void) {
	uint16_t delta = 0;
	
	if (m_count >= 2)
	{
		delta = m_samples[0].position = m_samples[1].position;
	}
	
	return delta;
}


long     AEAT6012::getDeltaTime(void) { // time in ms
	long delta = 0;
	
	if (m_count > 1)
	{
		delta = m_samples[0].timestamp = m_samples[1].timestamp;
	}
	
	return delta;
}


unsigned long AEAT6012::timestamp(void) {
	return 0; // <incomplete>
}

