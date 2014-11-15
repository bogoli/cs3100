// Lia Bogoev 
// CS3100 — Assignment 6

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <dlfcn.h>
#include <iomanip>

double evaluateTrig(double (*function)(double)){
	// The comparison is to compute the accumulated sum of each trigonometric
	// type over the range of 0 to 359 degrees, with an increment of 0.1 degrees.
	double trigSum = 0;
	for(double i = 0; i < 360; i = i+0.1){
		if((function(i) >= -1 && function(i) <= 1) ||(i < 89 || (i > 91 && i < 269) || i > 271)){
			trigSum += function(i);
		}
	}
	return trigSum;
}

int main(){
	// open the trig-lookup library
	void* trigLookupLib = dlopen("./trig-lookup.so", RTLD_LAZY);
	if (!trigLookupLib){
		std::cout << "Couldn't open the shared library, error: " << dlerror() << std::endl;
		exit(1);
	}

	// load mysin function:
	double (*mysin)(double) = (double(*)(double))dlsym(trigLookupLib, "mysin");
	if (dlerror() != NULL){
		std::cout << "Couldn't find 'mysin', error: " << dlerror() << std::endl;
		exit(1);
	}
	// load mycos function: 
	double (*mycos)(double) = (double(*)(double))dlsym(trigLookupLib, "mycos");
	if (dlerror() != NULL){
		std::cout << "Couldn't find 'mycos', error: " << dlerror() << std::endl;
		exit(1);
	}
	// load mytan function: 
	double (*mytan)(double) = (double(*)(double))dlsym(trigLookupLib, "mytan");
	if (dlerror() != NULL){
		std::cout << "Couldn't find 'mytan', error: " << dlerror() << std::endl;
		exit(1);
	}

	// load initialized: 
	void (*initialize)() = (void(*)())dlsym(trigLookupLib, "initialize");
	if (dlerror() != NULL){
		std::cout << "Couldn't find 'initialize', error: " << dlerror() << std::endl;
		exit(1);
	}

	initialize();

	double mySinTotal = evaluateTrig(mysin);
	double myCosTotal = evaluateTrig(mycos);
	double myTanTotal = evaluateTrig(mytan);

	// close the trig-lookup library
	dlclose(trigLookupLib);

/////////////////////////////////////////////////////////////////////////////////////

	// open the trig-std library
	void* trigStdLib = dlopen("./trig-std.so", RTLD_LAZY);
	if (!trigStdLib){
		std::cout << "Couldn't open the shared library, error: " << dlerror() << std::endl;
		exit(1);
	}

	// load mysin function:
	double (*stdsin)(double) = (double(*)(double))dlsym(trigStdLib, "mysin");
	if (dlerror() != NULL){
		std::cout << "Couldn't find 'mysin', error: " << dlerror() << std::endl;
		exit(1);
	}
	// load mycos function: 
	double (*stdcos)(double) = (double(*)(double))dlsym(trigStdLib, "mycos");
	if (dlerror() != NULL){
		std::cout << "Couldn't find 'mycos', error: " << dlerror() << std::endl;
		exit(1);
	}
	// load mytan function: 
	double (*stdtan)(double) = (double(*)(double))dlsym(trigStdLib, "mytan");
	if (dlerror() != NULL){
		std::cout << "Couldn't find 'mytan', error: " << dlerror() << std::endl;
		exit(1);
	}
	
	double stdSinTotal = evaluateTrig(stdsin);
	double stdCosTotal = evaluateTrig(stdcos);
	double stdTanTotal = evaluateTrig(stdtan);

	// close the trig-std library
	dlclose(trigStdLib);

	double sinDifference = mySinTotal - stdSinTotal;
	double cosDifference = myCosTotal - stdCosTotal;
	double tanDifference = myTanTotal - stdTanTotal;

/////////////////////////////////////////////////////////////////////////////////////	
	std::cout << std::setw(24) << "trig-lookup.so" << std::setw(20) << "trig-std.so" << std::setw(20) << "difference" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "sin:" << std::setw(20) << mySinTotal << std::setw(20) << stdSinTotal << std::setw(20) <<  sinDifference << std::endl;
	std::cout << "cos:" << std::setw(20) << myCosTotal << std::setw(20) << stdCosTotal << std::setw(20) <<  cosDifference << std::endl;
	std::cout << "tan:" << std::setw(20) << myTanTotal << std::setw(20) << stdTanTotal << std::setw(20) <<  tanDifference << std::endl;

	return 0;
}









