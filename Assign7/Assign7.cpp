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

bool contains(int page, std::deque<int>& memory){
	// if memory contains the page, return true
	for(auto it = memory.begin(); it != memory.end(); ++it){
		// dereference iterator (get the integer out of the iterator)
		int myit = *it;
		if(page == myit){
			return true;
		}
	}
	// else, memory doesn't contain page, return false
	return false;
}

int do_test(int frames, page_sequence& sequence){
	auto memory = std::deque<int>();
	int page_faults = 0;
	for(int i = 0; i < sequence.size(); ++i){
		int page = sequence[i];
		if(contains(page, memory)){
			// page is already in memory
			break;
		}
		// if the queue is smaller than the number of frames that we have
		// add the page to the back of the queue
		if(memory.size() < frames){
			memory.push_back(page);
		}

		// if not, increase page faults, pop off the front, push on the back
		else {
			assert(memory.size() == frames);
			page_faults++;
			memory.pop_front();
			memory.push_back(page);
		}
	}
	return page_faults;
}
void reportAnomalies(int sequence, int faults1, int size1, int faults2, int size2){
	std::cout << "found anomaly for sequence: " << sequence << std::endl;

}

void findAnomalies(std::array<page_sequence, NUM_SEQ>& test_sequences){
	// for each of the frame sizes we need to test
	for(int i = 0; i < NUM_SEQ; ++i){
		int prev_page_faults = -1;
		for(int frames = 1; frames <= MEM_SIZE; frames++){
			int current_faults = do_test(frames, test_sequences[i]);
			if(prev_page_faults != -1 && prev_page_faults < current_faults){
				reportAnomalies(i, prev_page_faults, frames-1, current_faults, frames);
			}
			prev_page_faults = current_faults;
		}
	}
}

int main(){

	std::cout << "Number of sequences tested: " << NUM_SEQ << std::endl;
	std::cout << "Length of page usage sequence: " << SEQ_SIZE << std::endl;
	std::cout << "Frames of physical memory: " << MEM_SIZE << std::endl;
	std::cout << std::endl << std::endl << std::endl;

 	std::array<page_sequence, NUM_SEQ> test_sequences = make_sequences();

 	findAnomalies(test_sequences);

/*
 	for(int i = 0; i < NUM_SEQ; ++i){
		for (int j = 0; j < SEQ_SIZE; ++j){
			std::cout << test_sequences[i][j] << " ";
		}
		std::cout << std::endl;
	}
*/
	



	return 0;
}








