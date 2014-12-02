// Lia Bogoev
// CS3100 — Assign7.cpp

#include <iostream>
#include <random>
#include <array>

std::default_random_engine generator(time(NULL));

const int SEQ_SIZE = 1000;	// size of page sequence
const int PAGE_SIZE = 250;	// max value of page
const int MEM_SIZE = 100;	// number of frames to test
const int NUM_SEQ = 100; 	// number of sequences to run

typedef array<int, 1000> page_sequence;

array<page_sequence, NUM_SEQ> make_sequences(){
	// make an array of arrays of 1000
	array<page_sequence, NUM_SEQ> test_sequences;

	for(int i = 0; i < NUM_SEQ; ++i){
		for (int j = 0; j < SEQ_SIZE; ++j){
			test_sequences<i,j>  = rand()%PAGE_SIZE;
		}
	}
		
	return test_sequences;
}

int main(){
/*
	std::cout << "Number of sequences tested: " << NUM_SEQ << std::endl;
	std::cout << "Length of page usage sequence: " << SEQ_SIZE << std::endl;
	std::cout << "Frames of physical memory: " << MEM_SIZE << std::endl;
*/

	/* Create a list of 100 random page sequences 
      and save it so we can use the exact same 
      sequences for each page size
 	*/
 	// array<page_sequence, 100> test_sequences = make_sequences();

	// We'll eventually need to save the test results somewhere results is that somewhere
	// 	auto results = //Something something

	// for each of the frame sizes we need to test
	for(int frames = 1; frames <= 100; frames++){
		// Do some tests and insert them into the results
		// results.Add(do_test(page_size, tests))
	}

	//print_results(results)
	//}

	return 0;
}