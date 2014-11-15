// Lia Bogoev
// CS3100 - Assignment 6
// trig-lookup.cpp

// Notes: extern "C"  removes mangled name so that you can call the funciton somewhere else 

#include <math.h>

const double CONVERSION_FACTOR = 0.0174532925;

double sinArray[360];
double cosArray[360];
double tanArray[360];

extern "C" void initialize(){
	for (int i = 0; i < 360; i++){
		sinArray[i] = sin(CONVERSION_FACTOR*i);
		cosArray[i] = cos(CONVERSION_FACTOR*i);
		tanArray[i] = tan(CONVERSION_FACTOR*i);
	}
}

double lerp(double deg, double* trigArray){
	int x0 = floor(deg);
	int x1 = (x0 + 1)%360;

	double xFraction = deg - x0;
	double yDiff = trigArray[x1] - trigArray[x0];
	double y = trigArray[x0] + xFraction*yDiff;

	return y;

}

extern "C" double mysin(double deg){
	return lerp(deg, sinArray);
}

extern "C" double mycos(double deg){
	return lerp(deg, cosArray);
}

extern "C" double mytan(double deg){
	return lerp(deg, tanArray);
}