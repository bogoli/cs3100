// Lia Bogoev
// CS3100 - Assign3

#include "execute.hpp"

int main(){

	std::string input;
	std::vector<std::string> history{};

	do {
		std::cout << "> ";
		std::getline(std::cin, input);
		
	} while(execute(input, history));	

	return 0;
}

//    std::chrono::microseconds exectime(0);
