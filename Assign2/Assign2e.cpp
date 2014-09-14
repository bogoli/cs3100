// Lia Bogoev
// CS3100 - Assign2
// Assign2e.cpp

#include "Assign2e.hpp"

double tracker = 1;
float e = 0;

float calce(int n){
	for(int i = 1; i <= n; i++){
		e = e + (1/tracker);
		tracker = tracker * i;
	}				
	return e;
}
