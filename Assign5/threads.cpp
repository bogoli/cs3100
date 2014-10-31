// Lia Bogoev
// threads.cpp

#include "threads.hpp"

int makeRandom(int i, std::mutex& mutex){
	std::lock_guard<std::mutex> lock(mutex);
	unsigned seed = time(NULL) - i;
	std::default_random_engine generator (seed);

	std::normal_distribution<double> distribution(50,10);
	double chosenNumber = std::round(distribution(generator)); 
	if(chosenNumber < 1){return 1;}
	else if(chosenNumber > 100){return 100;}
	else{
		return chosenNumber; 
	}
}

void makeThread(int threadId, std::mutex& mutex){
	while(true){
		std::cout << "Thread: " << threadId;
		std::cout << "   Value: " << makeRandom(threadId, std::ref(mutex)) << std::endl;
		sleep(1);
	}
}
