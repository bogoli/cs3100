// Lia Bogoev
// CS3100 — Assign7.cpp

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <deque>


const int NUM_SEQ = 100; // Number of sequences to test
const int SEQ_LEN = 1000; // Length of page sequences
const int MAX_PAGE = 250; // Range of pages 
const int MAX_FRAMES = 100; // Range of frames to test

bool contains(std::deque<int>& memory, int i){
	for(auto it=memory.begin(); it!=memory.end();++it){
		if(*it == i){
			return true;
		}
	}
	return false;
}


int main(){
	srand(time(NULL)); // seed the random number generator


	for(int rep = 0; rep < NUM_SEQ; ++rep){
		// Generate a single test sequence
		int sequence[SEQ_LEN];
		for (int i = 0; i < SEQ_LEN; ++i){
			sequence[i] = rand()%MAX_PAGE;
		}
		// std::cout << "sequence[0]: " << sequence[0] << std::endl;

		int page_faults = 0;
		int prev_page_faults = 1001;
		std::deque<int> memory;


		for(int frames = 1; frames < MAX_FRAMES; ++frames){
			memory.clear();

			for (int i = 0; i < SEQ_LEN; ++i){ // iterate through one page sequence
				if(memory.size() < frames){
					if(contains(memory, sequence[i]) == false){
						memory.push_back(sequence[i]);
						++page_faults;
					}
		 		}

		 		if(memory.size() >= frames){
		 			if(contains(memory, sequence[i]) == false){
						memory.pop_front();
						memory.push_back(sequence[i]);
						++page_faults;
					}
				}

			}// end for loop that circles through sequence

			if (page_faults > prev_page_faults){	
				std::cout << "Anomaly Detected: " << std::endl;
				std::cout << "Sequence: " << rep << std::endl;
				std::cout << "Page Faults: " << page_faults << " at " << frames << " frames." << std::endl;
				std::cout << "Page Faults: " << prev_page_faults << " at " << (frames - 1) << " frames.\n\n";
			}
			prev_page_faults = page_faults;
			page_faults = 0;
		}

	}
	return 0;

}