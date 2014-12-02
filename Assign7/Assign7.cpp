// Lia Bogoev
// CS3100 — Assign7.cpp

#include <iostream>
#include <random>
#include <unordered_map>

std::default_random_engine generator(time(NULL));

const int SEQ_SIZE = 1000;	// size of page sequence
const int PAGE_SIZE = 250;	// max value of page
const int MEM_SIZE = 100;	// number of frames to test
const int NUM_SEQ = 100; 	// number of sequences to run

typedef std::unordered_map<int,int> intmap;
intmap memory;

int main(){
/*
	std::cout << "Number of sequences tested: " << NUM_SEQ << std::endl;
	std::cout << "Length of page usage sequence: " << SEQ_SIZE << std::endl;
	std::cout << "Frames of physical memory: " << MEM_SIZE << std::endl;
*/

	// value of my memory array is the key of my page array, and vice versa
	// value of page array is key of memory array

	int sequence[SEQ_SIZE];

	for (int i = 0; i < SEQ_SIZE; ++i){
		// fill an array (page sequence)
		sequence[i] = rand()%PAGE_SIZE;
	}


//	for(int i = 0; i < MEM_SIZE; ++i){
	
	int memory[100];
	int next = 0;
	int page_faults = 0;
		for(int j = 0; j < 1000; ++ j){
			// if in memory, do nothing
			
			// if not in memory:
				memory[next] = sequence[j];
				++page_faults;
		
		}
//	}


	return 0;
}