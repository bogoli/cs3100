// syncClass.hpp
#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class SynchronizedPriorityQueue{
public:
	void enqueue(T value){
		std::unique_lock<std::mutex> lock(mutex);
		queue.push(value);
		event.notify_one();
	};
	
	T dequeue(){
		std::unique_lock<std::mutex> lock(mutex);

		event.wait(lock, [&] { return queue.size() > 0; });
		
		// store the value off the front of the queue, pop, return
		T value = queue.top();
		queue.pop();
		return value;
	}; 
	
	std::size_t size(){return queue.size();};

private:
	std::priority_queue<T> queue;
	std::condition_variable event;
	std::mutex mutex;

};