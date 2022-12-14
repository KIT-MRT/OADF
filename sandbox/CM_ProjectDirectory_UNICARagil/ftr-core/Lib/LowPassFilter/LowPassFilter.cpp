
#include "LowPassFilter.hpp"

#define ERROR_CHECK (true)

#if ERROR_CHECK
#include <iostream>
#endif
#include <math.h>
LowPassFilter::LowPassFilter():
	output(0),
	ePow(0){}

LowPassFilter::LowPassFilter(float iCutOffFrequency, float iDeltaTime):
	output(0),
	ePow(float(1-exp(-iDeltaTime * 2 * 3.1415926535897932384626433832795 * iCutOffFrequency)))
{
	#if ERROR_CHECK
	if (iDeltaTime <= 0){
		std::cout << "Warning: A LowPassFilter instance has been configured with 0 s as delta time.";
		ePow = 0;
	}
	if(iCutOffFrequency <= 0){
		std::cout << "Warning: A LowPassFilter instance has been configured with 0 Hz as cut-off frequency.";
		ePow = 0;
	}
	#endif
}

float LowPassFilter::update(float input){
	return output += (input - output) * ePow;
}

float LowPassFilter::update(float input, float deltaTime, float cutoffFrequency){
	reconfigureFilter(deltaTime, cutoffFrequency); //Changes ePow accordingly.
	return output += (input - output) * ePow;
}

void LowPassFilter::reconfigureFilter(float deltaTime, float cutoffFrequency){
	#if ERROR_CHECK
	if (deltaTime <= 0){
		std::cout << "Warning: A LowPassFilter instance has been configured with 0 s as delta time.";
		ePow = 0;
	}
	if(cutoffFrequency <= 0){
		std::cout << "Warning: A LowPassFilter instance has been configured with 0 Hz as cut-off frequency.";
		ePow = 0;
	}
	#endif
	ePow = float(1-exp(-deltaTime * 2 * 3.1415926535897932384626433832795 * cutoffFrequency));
}
