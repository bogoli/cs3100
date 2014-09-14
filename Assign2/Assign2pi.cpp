// Lia Bogoev
// CS3100 - Assign2
// Assign2pi.cpp

#include "Assign2pi.hpp"

double pi = 0;
double count;
float calcpi(){
	
	for(int i = 1; i < 10000000; i++){
		count = i;

		if(i%2 == 1){
			pi = pi + 4/(2*count - 1);
		}

		else{
			pi = pi - 4/(2*count -1);
		}
		
	} // end for
	return pi;
}
