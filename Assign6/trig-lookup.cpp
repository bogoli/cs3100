// extern "C"  removes mangled name so that you can call the funciton somewhere else 

#include <math.h>

double lerp(double deg, double* trigArray){
	int x0 = floor(deg);
	double y0 = trigArray[x0];
	int x1 = ceil(deg);
	double y1 = trigArray[x1];

	// find the slope
	double m = (y1 - y0) / (x1 - x0);
	// find the y intercept
	double b = -m*x0 + y0;
	// plug in the degree value into the equation
	double y = m * deg + b;  // deg is the x that we want to plug into the equation
	return y;
}

extern "C" double mysin(double deg){
	static double sinArray[360];
	for (int i = 0; i < 359; i++){
		sinArray[i] = sin(0.0174532925*i);
	}

	// use remainder to ensure value is in lookup table
	deg = fmod(deg, 360);
	return lerp(deg, sinArray);
}

extern "C" double mycos(double deg){
	static double cosArray[360];
	for (int i = 0; i < 359; i++){
		cosArray[i] = cos(0.0174532925*i);
	}

	// use remainder to ensure value is in lookup table
	deg = fmod(deg, 360);
	return lerp(deg, cosArray);
}

extern "C" double mytan(double deg){
	static double tanArray[360];
	for (int i = 0; i < 359; i++){
		tanArray[i] = tan(0.0174532925*i);
	}

	// use remainder to ensure value is in lookup table
	deg = fmod(deg, 360);
	return lerp(deg, tanArray);
}