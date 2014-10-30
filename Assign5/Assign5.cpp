// Lia Bogoev
// CS3100 - Assignment 5

#include <iostream>
#include <exception>
#include <iomanip>

int main(int argc, char* argv[]){
	int producers = 0;
	int consumers = 0;

	if(argc == 3){
		// correct number of arguments
		try{
			producers = std::stoi(argv[1]);
			consumers = std::stoi(argv[2]);
		} catch(...){
			std::cout << "Invalid Parameter\n";	
		} // end try catch block 

		/*
		std::cout << "Producers: " << producers << std::endl;
		std::cout << "Consumers: " << consumers << std::endl;
		*/ 








	}// end if there are the correct number of inputs

	else{
		// No argument input or incorrect input 
		std::cout << " No input specified.\n";
		std::cout << " The first command line argument specifies the number of";
		std::cout << "\n producers, the second specifies the number of consumers.\n";
	} // end else (incorrect number of inputs)

	return 0;
}
