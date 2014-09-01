// Lia Bogoev 
// CS3100 - Assign 1

#include <iostream>
#include <exception>
#include <new>

int main(int argc, char* argv[]){
	int par;

	if(argc == 3){
		// correct number of arguments

		if(std::string(argv[1]) == "-fib"){
			try{
				par = std::stoi(argv[2]);
			} catch(...){
				std::cout << "Invalid Parameter\n";	
			} // end try catch block 

		// calculate fibonacci here (0-14 inclusive)

		} // end == "-fib"

		else if(std::string(argv[1]) == "-e"){
			try{
				par = std::stoi(argv[2]);
			} catch(...){
				std::cout << "Invalid Parameter\n";	
			} // end try catch block 
		
		// calculate e here (1-100 iterations)

		} // end == "-e"
	 	

		else if(std::string(argv[1]) == "-pi"){
			try{
				par = std::stoi(argv[2]);
			} catch(...){
				std::cout << "Invalid Parameter\n";	
			} // end try catch block 
			
			// calulate pi here (1-10 inclusive)

		} // end == "-pi"
	}// end if there are the correct number of inputs

	else{
		// No argument input or incorrect input 
		std::cout << "--- Assign1 Help ---\n";
		std::cout << "-fib [n] Compute the fibonacci of [n]\n";
		std::cout << "-e [n]   Compute the value of 'e' using [n] iterations\n";
		std::cout << "-pi [n]  Compute pi to [n] digits\n";
	} // end else (incorrect number of inputs)


	return 0;
}
