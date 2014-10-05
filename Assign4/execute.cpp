// Lia Bogoev
// execute.cpp

#include "execute.hpp"

std::vector<std::string> split(std::string originalString, char c){
	std::vector<std::string> stringVector;
	std::string subString;

	// find position of the char you want to split string by
	int i = originalString.find(c); 

	while(i != std::string::npos){
		// split the string (make the original the remainder)
		subString = originalString.substr(0,i);
		originalString = originalString.substr(i + 1, std::string::npos);

		// add the string to the vector if it's non 0
		if(i !=0 && subString.size() !=0){
			stringVector.push_back(subString);
		}
		// find the next instance of the char to split by
		i = originalString.find(c);
	}
	if(originalString.size() != 0){
		stringVector.push_back(originalString);
	}

	return stringVector;
}


bool execute(std::string &input, std::vector<std::string> &history, std::chrono::microseconds &totalTime){
	std::vector<std::string> inputVector = split(input, ' ');

	try{
	// check for exit
		if(inputVector.at(0) == "exit"){
			return false;
		}

		// not exit: 
		else{
			// display history
			if(inputVector.at(0) == "history"){
				std::cout << "--- History --- \n";

				int i = 1;
				for(std::string s : history){
	 				std::cout << i << " " << s << std::endl;
	 				++i;
	 			}
			}

			// select something from history
			else if(inputVector.at(0) == "^"){
				if (fork()){
					// start the clock
					auto startTime = std::chrono::system_clock::now();
					// wait for child process to finish
					wait(NULL);
					// stop the clock
					auto endTime = std::chrono::system_clock::now();

					// add difference to total time
					totalTime += std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
				}
				else{
					int histPosition = stoi(inputVector.at(1));
					// make a vector of the commands needed to execute from history
					std::vector<std::string> historyParsed = split(history[histPosition - 1], ' ');

					int argc = (int)historyParsed.size();
				/*
					std::cout << "histPosition: " << histPosition << std::endl; 
					std::cout << "history[histPosition]: " << history[histPosition - 1] << std::endl;
				*/
					char** args = new char*[argc + 1];

					for(int i = 0; i < argc; ++i){
						int length = historyParsed[i].length() + 1;
						args[i] = new char[length];
						strncpy(args[i], historyParsed[i].c_str(), length);
						
					}
					// add the terminating character for execvp					
					args[argc] = NULL;

	 				execvp(args[0], args);
	 				// terminate this child process
	 				return false;	 				
				}
			}

			// display runtime
			else if(inputVector.at(0) == "ptime"){
				// need to be typcast to durations for calulations
				auto sec = std::chrono::duration_cast<std::chrono::seconds>(totalTime);
				auto milli = std::chrono::duration_cast<std::chrono::milliseconds>(totalTime - sec);
				auto micro = std::chrono::duration_cast<std::chrono::microseconds>(totalTime - sec - milli);
				
				std::cout << "Time spent running child processes: " << sec.count() << " seconds ";
				std::cout << milli.count() << " milliseconds and " << micro.count() << " microseconds. " << std::endl;
			}
			
			else{
				// add input to history
				history.insert(history.begin(),input);

				if (fork()){
					// start the clock
					auto startTime = std::chrono::system_clock::now();
					// wait for child process to finish
					wait(NULL);
					// stop the clock
					auto endTime = std::chrono::system_clock::now();

					// add difference to total time
					totalTime += std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
				}
				else{
					int argc = (int)inputVector.size();

					char** args = new char*[argc + 1];

					for(int i = 0; i < argc; ++i){
						int length = inputVector[i].length() + 1;
						args[i] = new char[length];
						strncpy(args[i], inputVector[i].c_str(), length);
					}
					// add the terminating character for execvp					
					args[argc] = NULL;

	 				execvp(args[0], args);
	 				// terminate this child process
	 				return false;	 				
				}

			}

			return true;
		}
	} catch(std::exception& e){
		return true;
	}
}
