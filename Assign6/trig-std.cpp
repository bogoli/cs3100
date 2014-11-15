// Lia Bogoev
// CS3100 - Assignment 6
// trig-std.cpp

// Notes: extern "C"  removes mangled name so that you can call the funciton somewhere else 

#include <math.h>

const double CONVERSION_FACTOR = 0.0174532925;

extern "C" double mysin(double deg){
	return sin(deg*CONVERSION_FACTOR);
}

extern "C" double mycos(double deg){
	return cos(deg*CONVERSION_FACTOR);
}

extern "C" double mytan(double deg){
	return tan(deg*CONVERSION_FACTOR);
}	