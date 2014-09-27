// Lia Bogoev
// CS3100 - Assign3

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#include <iostream>
#include <cstring>
#include <chrono>

int main(){
	bool running = true;

	std::string input;
	while(running){ 
		printf("[cmd]: ");
		fflush(stdout);
		std::getline(std::cin, input);
			
/* Start time:
	auto start = std::chrono::system_clock::now();

	wait(NULL);
	
	// End time:
	auto end = std::chrono::system_clock::now();

	// Calculate time difference in microseconds
	auto timeDiff = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	// std::cout << "Time executing child process " << timeDiff.count() << std::endl;	
*/


	}	// end while(running) loop 

	return 0;
}