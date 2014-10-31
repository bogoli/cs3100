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

void makeProducerThread(int threadId, std::mutex& mutex, SynchronizedPriorityQueue<int> &queue){
	while(true){
		int randomNumber = makeRandom(threadId, std::ref(mutex));
		queue.enqueue(randomNumber);
		sleep(1);
	}
}

void makeConsumerThread(int threadId, std::mutex& coutMutex, SynchronizedPriorityQueue<int> &queue){
	while(true){
		int randomNumber = queue.dequeue();
		{
           std::lock_guard<std::mutex> lock(coutMutex);
           std::cout << "Thread " << threadId << " consumes " << randomNumber << std::endl;
       	}

		sleep(3);
	}
}
