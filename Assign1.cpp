// Lia Bogoev 
// CS3100 - Assign 1

#include <iostream>

int main(int argc, char* argv[]){

	//std::cout << "argc: " << argc << "\n";

	if(argc == 1){
		// No argument input
		std::cout << " --- Assign1 Help ---\n";
		std::cout << " -fib [n] Compute the fibonacci of [n]\n";
		std::cout << " -e [n]   Compute the value of 'e' using [n] iterations\n";
		std::cout << " -pi [n]   Computer pi to [n] digits\n";
	} // end if(argc == 0)



/*
	for (int arg = 0; arg < argc; arg++) {
		//std::cout << arg  << std::endl;
	
		if(std::string(argv[1]) == "-f"){
 			std::cout << "fib\n";
		}
		else if(std::string(argv[1]) == "-e"){
			std::cout << "the number e\n";
		}
		else{
			std::cout << "....else\n";
		}
	}
*/

	return 0;
}
