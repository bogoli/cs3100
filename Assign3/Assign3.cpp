// Lia Bogoev
// CS3100 - Assign3

#include "execute.hpp"

int main(){

	std::string input;
	std::vector<std::string> history{};
	std::chrono::microseconds totalTime(0);
	
	do {
		std::cout << "> ";
		std::getline(std::cin, input);
		
	} while(execute(input, history, totalTime));	

	return 0;
}
