// Lia Bogoev
// CS3100 - Assignment 5

#include "threads.hpp"

int main(int argc, char* argv[]){
	std::mutex mutex; 

	int producerSize = 0;
	int consumerSize = 0;

	// check for correct number of arguments
	if(argc == 3){
	
		// check for correct number of arguments
		try{
			producerSize = std::stoi(argv[1]);
			consumerSize = std::stoi(argv[2]);

		} catch(...){
			std::cout << "Invalid Parameter\n";	
		} // end try catch block 

		std::vector<std::thread> producers(producerSize);
		std::vector<std::thread> consumers(consumerSize);

		// start a thread for each producer
		for(int i = 0; i < producerSize; ++i){			
			producers[i] = std::thread(makeThread, (i + 1), std::ref(mutex));
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}

		// join all the threads
		for (int i = 0; i < producerSize; ++i) {
			producers[i].join();
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
