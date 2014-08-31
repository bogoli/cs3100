// Lia Bogoev 
// CS3100 - Assign 1

#include <iostream>

int main(int argc, char* argv[]){

	if(argc == 3){
		// correct number of arguments

		if(std::string(argv[1]) == "-fib"){
			std::cout << "fib\n";
		} // end == "-fib"

		else if(std::string(argv[1]) == "-e"){
			std::cout << "eeeee\n";
		} // end == "-e"

	 	else if(std::string(argv[1]) == "-pi"){
			std::cout << "pie\n";
		} // end == "-pi"
	}

	else{
		// No argument input or incorrect input 
		std::cout << "  --- Assign1 Help ---\n";
		std::cout << "  -fib [n] Compute the fibonacci of [n]\n";
		std::cout << "  -e [n]   Compute the value of 'e' using [n] iterations\n";
		std::cout << "  -pi [n]  Compute pi to [n] digits\n";
	} // end else 


	return 0;
}
