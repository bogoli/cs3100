// Lia Bogoev
// CS3100 — Assign7.cpp

#include <iostream>
#include <random>
#include <array>
#include <deque>

const int SEQ_SIZE = 1000;	// size of page sequence
const int PAGE_SIZE = 250;	// max value of page
const int MEM_SIZE = 100;	// number of frames to test
const int NUM_SEQ = 100; 	// number of sequences to run

typedef std::array<int, SEQ_SIZE> page_sequence;

std::array<page_sequence, NUM_SEQ> make_sequences(){
	// make an array of arrays of 1000
	std::array<page_sequence, NUM_SEQ> test_sequences;

	for(int i = 0; i < NUM_SEQ; ++i){
		test_sequences[i] = page_sequence();
		for (int j = 0; j < SEQ_SIZE; ++j){
			test_sequences[i][j] = rand()%PAGE_SIZE;
		}
	}
	return test_sequences;
}


int do_test(int frames, std::deque<int>& memory, page_sequence& sequence){
	int page_faults = 0;
	for(int page = 0; page < sequence.size(); ++page){
		// if the queue is smaller than the number of frames that we have
		// add the page to the back of the queue
		if(memory.size() < frames){
			memory.push_back(page);
		}

		// if not, increase page faults, pop off the front, push on the back
		else {
			page_faults++;
			memory.pop_front();
			memory.push_back(page);

		}
	}
	return page_faults;
}


void setup_test(int size, std::array<page_sequence, NUM_SEQ>& test_sequences){
	// allocate our "memory"
	auto memory = std::deque<int>(); 
	int page_faults = NUM_SEQ + 1;

	// iterate through the different page sequences
	for(int i = 0; i < test_sequences.size(); ++i){	
		if(do_test(size, memory, test_sequences[i]) > page_faults){
		
			std::cout << "Anomaly Detected: " << std::endl;
			std::cout << "Sequence: " << i << std::endl;
			std::cout << "Number of Frames: " << size << std::endl;
			std::cout << "Page_faults " << page_faults << std::endl;
			std::cout << "- - - - - - - - - - - - - \n";
		
			page_faults = do_test(size, memory, test_sequences[i]);
		}

		else{
			page_faults = do_test(size, memory, test_sequences[i]);
		}
	}
}


int main(){

	std::cout << "Number of sequences tested: " << NUM_SEQ << std::endl;
	std::cout << "Length of page usage sequence: " << SEQ_SIZE << std::endl;
	std::cout << "Frames of physical memory: " << MEM_SIZE << std::endl;
	std::cout << std::endl << std::endl << std::endl;

 	std::array<page_sequence, NUM_SEQ> test_sequences = make_sequences();

/*
 	for(int i = 0; i < NUM_SEQ; ++i){
		for (int j = 0; j < SEQ_SIZE; ++j){
			std::cout << test_sequences[i][j] << " ";
		}
		std::cout << std::endl;
	}
*/

	// for each of the frame sizes we need to test
	for(int frames = 1; frames <= MEM_SIZE; frames++){
		setup_test(frames, test_sequences);
	}

	//print_results(results)
	//}

	return 0;
}