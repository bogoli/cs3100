// Lia Bogoev 
// CS3100 — Assignment 6

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <dlfcn.h>

const double CONVERSION_FACTOR = 0.0174532925;

double lerp(double deg, double* trigArray){
	int x0 = floor(deg);
	double y0 = trigArray[x0];
	int x1 = ceil(deg);
	double y1 = trigArray[x1];
	// double x ---> deg

	// find the slope
	double m = (y1 - y0) / (x1 - x0);
	// find the y intercept
	double b = -m*x0 + y0;
	// plug in the degree value into the equation
	double y = m * deg + b;  // deg is the x that we want to plug into the equation
	return y;
}

int main(){
	// open the library
	void* handle = dlopen("./trig-lookup.so", RTLD_LAZY);
	if (!handle){
		std::cout << "Couldn't open the shared library, error: " << dlerror() << std::endl;
		exit(1);
	}

	// load mysin function:
	double (*mysin)(double) = (double(*)(double))dlsym(handle, "mysin");
	if (dlerror() != NULL){
		std::cout << "Couldn't find 'mysin', error: " << dlerror() << std::endl;
		exit(1);
	}

	// load mycos function: 
	double (*mycos)(double) = (double(*)(double))dlsym(handle, "mycos");
	if (dlerror() != NULL){
		std::cout << "Couldn't find 'mycos', error: " << dlerror() << std::endl;
		exit(1);
	}

	// load mytan function: 
	double (*mytan)(double) = (double(*)(double))dlsym(handle, "mytan");
	if (dlerror() != NULL){
		std::cout << "Couldn't find 'mytan', error: " << dlerror() << std::endl;
		exit(1);
	}

	std::cout << "mysin(45.2): " << mysin(45.2) << std::endl;
	std::cout << "mycos(45.2): " << mycos(45.2) << std::endl;
	std::cout << "mytan(42.5): " << mytan(42.5) << std::endl;




	dlclose(handle);
	return 0;
}









