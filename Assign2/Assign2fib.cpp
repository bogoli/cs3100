// Lia Bogoev
// CS3100 - Assign 2 
// Assign2fib.cpp

#include "Assign2fib.hpp"

int fibonacci1(int n){
	if (n == 0){return 0;}
	else if (n == 1){return 1;}
	else{return fibonacci1(n-1) + fibonacci1(n-2);}
}
