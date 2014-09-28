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
			// add input to history
			history.insert(history.begin(),input);

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

			}

			// display runtime
			else if(inputVector.at(0) == "ptime"){

				/*
				int sec = (int) (totalTime/1000000);
				int milli = (int) ((totalTime - seconds*1000000)/1000);
				int micro = (int) totalTime - seconds*1000000 - milliseconds*1000;
				*/


				auto sec = std::chrono::duration_cast<std::chrono::seconds>(totalTime);
				auto milli = std::chrono::duration_cast<std::chrono::milliseconds>(totalTime - sec);
				auto micro = std::chrono::duration_cast<std::chrono::microseconds>(totalTime - sec - milli);
				std::cout << "Time spent running child processes: " << sec.count() << " seconds ";
				std::cout << milli.count() << " milliseconds and " << micro.count() << " microseconds. " << std::endl;
			}
			
			else{
				if (fork()){
					auto startTime = std::chrono::system_clock::now();
					wait(NULL);
					auto endTime = std::chrono::system_clock::now();
					totalTime += std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
					
					// totalTime = timeDiff.count() + totalTime;
				}
				else{
					int argc = (int)inputVector.size();

					char** args = new char*[argc + 1];

					for(int i = 0; i < argc; ++i){
						int length = inputVector[i].length() + 1;
						args[i] = new char[length];
						strncpy(args[i], inputVector[i].c_str(), length);
					}
					
					args[argc] = NULL;
				/*
					int i = 0;
					for(std::string s : inputVector){
	 					char* args[i] = s;
	 					++i;
	 				} 
	 				args[i+1] = NULL;
	 			*/


	 				execvp(args[0], args);
	 				return false;	 				
	 				/*
	 				sleep(1);  // for testings purposes
	 				std::cout << "child process \n" << std::endl;
	 				*/
				}

			}

			return true;
		}
	} catch(std::out_of_range e){
		return true;
	}
}