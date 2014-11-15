// Lia Bogoev 
// CS3100 — Assignment 6

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <dlfcn.h>

const double CONVERSION_FACTOR = 0.0174532925;

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





	dlclose(handle);
	return 0;
}









