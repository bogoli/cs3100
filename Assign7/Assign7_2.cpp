// Lia Bogoev
// CS3100 — Assign7.cpp

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <deque>


const int NUM_SEQ = 100; // Number of sequences to test
const int SEQ_LEN = 1000; // Length of page sequences
const int MAX_PAGE = 20; // Range of pages 
const int MAX_FRAMES = 100; // Range of frames to test

int main(){
	srand(std::time(NULL)); // seed the random number generator


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
					// FIRST check to see if it's in memory before pushing and popping
					for(auto it=memory.begin(); it!=memory.end();++it){
						if(*it == sequence[i]){
							// std::cout << "already in memory " << i <<  std::endl;
							// std::cout << "*it " << *it << " sequence[i] " << sequence[i] <<  "     " << page_faults << std::endl;
							break;
						}
					}
					memory.push_back(sequence[i]);
					// std::cout << "pushed back " << sequence[i] << std::endl;
		 		}

		 		if(memory.size() >= frames){
		 			for(auto it=memory.begin(); it!=memory.end();++it){
						if(*it == sequence[i]){
							// std::cout << "already in memory " << sequence[i] <<  std::endl;
							break;
						}
					}
					// std::cout << "not in memory, popped, pushed.\n";
					memory.pop_front();
					memory.push_back(sequence[i]);
					++page_faults;
				}

			}// end for loop that circles through sequence

			std::cout << "frames:  " << frames << std::endl;
			std::cout << "page_faults:  " << page_faults << std::endl;
			std::cout << "\n\n\n";

			if (page_faults > prev_page_faults){	
				std::cout << "Anomaly Detected: " << std::endl;
				std::cout << "frames: " << frames << std::endl;
				std::cout << "page_faults: " << page_faults << "  prev_page_faults: " << prev_page_faults << std::endl;
			}
			prev_page_faults = page_faults;
			page_faults = 0;
		}

	}
	return 0;

}