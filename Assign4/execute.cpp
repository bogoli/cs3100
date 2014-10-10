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

//////////////////////////////////////////////////////////////////////////////////////////////////////////

bool shell(std::vector<std::string> &inputVector, std::vector<std::string> &history, std::chrono::microseconds &totalTime){
try{
		// check for exit =============================================   EXIT 
		if(inputVector.at(0) == "exit"){
			return false;
		} // end check for exit 

		// the command is not exit: 
		else{
			// display history ==========================================  HISTORY DISPLAY
			if(inputVector.at(0) == "history"){
				std::cout << "--- History --- \n";
				// iterate through the history vector and display options
				int i = 1;
				for(std::string s : history){
	 				std::cout << i << " " << s << std::endl;
	 				++i;
	 			} // end history vector iteration
			} // end history loop 

			// select something from history ============================  HISTORY SELECT
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
			} // end history select  

			// display runtime ==========================================  PTIME 
			else if(inputVector.at(0) == "ptime"){
				// need to be typcast to durations for calulations
				auto sec = std::chrono::duration_cast<std::chrono::seconds>(totalTime);
				auto milli = std::chrono::duration_cast<std::chrono::milliseconds>(totalTime - sec);
				auto micro = std::chrono::duration_cast<std::chrono::microseconds>(totalTime - sec - milli);
				
				std::cout << "Time spent running child processes: " << sec.count() << " seconds ";
				std::cout << milli.count() << " milliseconds and " << micro.count() << " microseconds. " << std::endl;
			} // end ptime
			
			else{  // ===================================================  OTHER COMMANDS
				// add input to history 
				// (first combine vector back to string, then add to history vector)
				std::string addToHistory;
				for(std::string s : inputVector){
					addToHistory.append(s);
					addToHistory.append(" "); // to preserve the intial input
				}
				history.insert(history.begin(),addToHistory);

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
			} // end other commands
				
			return true;
		} // end exit else

	} catch(std::exception& e){
		return true;
	}

} // end shell

//////////////////////////////////////////////////////////////////////////////////////////////////////////

bool pipeCheck(std::vector<std::string> &inputVector){
	// returns false if no pipe, true if there's a pipe
	for(std::string s : inputVector){
		if(s.compare("|") == 0){
			return true;
		}
		else{
			return false;
		}
	}
	return false;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////

bool shellPipe(std::vector<std::string> &inputVector, std::vector<std::string> &inputVector2, std::vector<std::string> &history, std::chrono::microseconds &totalTime){
	// add input to history 
	// first combine vector back to string, then add to history vector
	std::string addToHistory;
	for(std::string s : inputVector){
		addToHistory.append(s);
		addToHistory.append(" "); // to preserve the intial input
	}
	// add the pipe (to history)
	addToHistory.append("|");

	// add the second string to history
	for(std::string s : inputVector){
		addToHistory.append(s);
		addToHistory.append(" ");
	}

	history.insert(history.begin(),addToHistory);

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
	return true;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

bool execute(std::string &input, std::vector<std::string> &history, std::chrono::microseconds &totalTime){
	std::vector<std::string> inputVector = split(input, ' ');
	// check for pipe
	if(pipeCheck(inputVector)){
		// find where the pipe is
	}
	else{
		return shell(inputVector, history, totalTime);
	}
	return true;
} // end execute


