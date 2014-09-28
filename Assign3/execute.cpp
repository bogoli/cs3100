// Lia Bogoev
// execute.cpp

#include "execute.hpp"

bool execute(std::string &input, std::vector<std::string> &history){


	// check for exit
	if(input == "exit" || input == "bye" || input == "quit"){
		return false;
	}

	// not exit: 
	else{
		// add input to history
		history.insert(history.begin(),input);

		if(input == "history"){
			std::cout << "--- History --- \n";

			int i = 1;
			for(std::string s : history){
 				std::cout << i << " " << s << std::endl;
 				++i;
 			}
		}



		return true;
	}
}