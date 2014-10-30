// Lia Bogoev
// threads.cpp

#include "threads.hpp"

int makeRandom(int i){
	unsigned seed = i;
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
	std::lock_guard<std::mutex> lock(mutex);
	std::cout << "Thread: " << threadId;
	std::cout << " Value: " << makeRandom(threadId) << std::endl;
	sleep(1);

}

template <typename T>
class SynchronizedPriorityQueue{
public:
    SynchronizedPriorityQueue();
    void enqueue(T value);  // Add a new item to the queue
    T dequeue();            // Removes an item from the queue
    std::size_t size();     // Returns the number of available items
};