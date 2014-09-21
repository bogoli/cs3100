// Lia Bogoev
// CS3100 - Assign3

#include <iostream>
#include <unistd.h>
#include <cstring>
#include <chrono>

int main(){
	if (fork()){
		auto start = std::chrono::system_clock::now();

		wait(NULL);
		
		auto end = std::chrono::system_clock::now();
		auto timeDiff = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		
	}
	else{
		
	}


	return 0;
}