// Lia Bogoev
// CS3100 - Assignment 5

#include "threads.hpp"

int main(int argc, char* argv[]){
	std::mutex mutex; 

	int producers = 0;
	int consumers = 0;

	if(argc == 3){
		while(true){
			// check for correct number of arguments
			try{
				producers = std::stoi(argv[1]);
				consumers = std::stoi(argv[2]);
			} catch(...){
				std::cout << "Invalid Parameter\n";	
			} // end try catch block 

			std::thread first (makeThread, 1, std::ref(mutex));
			std::thread second (makeThread, 2, std::ref(mutex));

			first.join();
			second.join();
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
