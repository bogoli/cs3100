// Lia Bogoev
// CS3100 - Assignment 5

#include <chrono>
#include <exception>
#include <iomanip>
#include <iostream>
#include <random>


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

		for (int i=0; i<50; ++i) {
			unsigned seed = i;
			std::default_random_engine generator (seed);

			std::normal_distribution<double> distribution(50,10);
			double chosenNumber = std::round(distribution(generator)); 
			if(chosenNumber < 1){chosenNumber = 1;}
			else if(chosenNumber > 100){chosenNumber = 100;}
			else{std::cout << chosenNumber << "\n";}
		}



	}// end if there are the correct number of inputs

	else{
		// No argument input or incorrect input 
		std::cout << " No input specified.\n";
		std::cout << " The first command line argument specifies the number of";
		std::cout << "\n producers, the second specifies the number of consumers.\n";
	} // end else (incorrect number of inputs)

	return 0;
}
