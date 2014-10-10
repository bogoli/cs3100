// Lia Bogoev
// execute.cpp
#include "execute.hpp"

const int PIPE_COUNT = 2;
const int PIPE_READ_END = 0;
const int PIPE_WRITE_END = 1;

const int STDIN = 0;
const int STDOUT = 1;

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

} // end shell function

//////////////////////////////////////////////////////////////////////////////////////////////////////////

bool pipeCheck(std::vector<std::string> &inputVector, std::vector<std::string>::iterator &inputPipeLoc, int &inputPipeLocInt){
	// returns false if no pipe, true if there's a pipe
	int i = 0;
	for(std::string s : inputVector){
		if(s.compare("|") == 0){
			std::vector<std::string>::iterator inputPipeLoc = std::find(inputVector.begin(), inputVector.end(), "|");
			inputPipeLocInt = i;
			return true;
		}
		++i;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

bool shellPipe(std::vector<std::string> &inputVector1, std::vector<std::string> &inputVector2, std::vector<std::string> &history, std::chrono::microseconds &totalTime){
	// add input to history 
	// first combine vector back to string, then add to history vector
	std::string addToHistory;
	for(std::string s : inputVector1){
		addToHistory.append(s);
		addToHistory.append(" "); // to preserve the intial input
	}
	// add the pipe (to history)
	addToHistory.append("| ");

	// add the second string to history
	for(std::string s : inputVector2){
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

	//==============================================  pipes shit 
	else{
		int pids[PIPE_COUNT];
		pipe(pids);

		int savedStdout = dup(STDOUT);
		int savedStdin = dup(STDIN);

		// first child --> into pipe
		pid_t pid = fork();
		if (pid == 0){
			// moving write end of the pipe to be my stdout
			dup2(pids[PIPE_WRITE_END], STDOUT);

			int argc = (int)inputVector1.size();
			char** argv = new char*[argc + 1];

			for(int i = 0; i < argc; ++i){
				int length = inputVector1[i].length() + 1;
				argv[i] = new char[length];
				strncpy(argv[i], inputVector1[i].c_str(), length);
				// std::cout << "first pipe child: inputVector1["  << i << "]: " << inputVector1[i] << std::endl;
			}
			// add the terminating character for execvp					
			argv[argc] = NULL;

			execvp(argv[0], argv);
		} // end of first pipe child

		// second child will perform the second command on whatever comes down the pipe
		pid_t pid2 = fork();
		if (pid2 == 0){
			// this copies the read end of the pipe onto stdin
			dup2(pids[PIPE_READ_END], STDIN);
			// This is key, in order to terminate the input from the pipe
			// have to close off the write end, otherwise the 'more' command
			// will continue to wait for additional data.
			close(pids[PIPE_WRITE_END]);

			int argc = (int)inputVector2.size();
			char** argv = new char*[argc + 1];

			for(int i = 0; i < argc; ++i){
				int length = inputVector2[i].length() + 1;
				argv[i] = new char[length];
				strncpy(argv[i], inputVector2[i].c_str(), length);
				// std::cout << "second pipe child: inputVector2["  << i << "]: " << inputVector2[i] << std::endl;
			}
			// add the terminating character for execvp					
			argv[argc] = NULL;

			execvp(argv[0], argv);
		} // end of the second pipe child

		// Wait for the first child to finish
		int status;
		waitpid(pid, &status, 0);

		// Fully close down the pipe
		close(pids[PIPE_WRITE_END]);
		close(pids[PIPE_READ_END]);

		waitpid(pid2, &status, 0);

		// restore standard in and out 
		dup2(savedStdin, STDIN);
		dup2(savedStdout, STDOUT);

		// terminate this child process
		return false;	 				
	}
	return true;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

bool execute(std::string &input, std::vector<std::string> &history, std::chrono::microseconds &totalTime){
	int inputPipeLocInt = 0;
	std::vector<std::string> inputVector = split(input, ' ');
	// check for pipe
	std::vector<std::string>::iterator inputPipeLoc = inputVector.begin();
	if(pipeCheck(inputVector, inputPipeLoc, inputPipeLocInt)){
		// std::cout << "inputPipeLoc = " << inputPipeLoc << std::endl;
		
		try{
			// now that have pipe location, need to split into two vectors and implement pipe. 

			std::vector<std::string> inputVector1;
			std::vector<std::string> inputVector2;

			for(int i = 0; i < inputPipeLocInt; i++){
				inputVector1.insert(inputVector1.end(), inputVector[i]);
			}

			for(int i = inputPipeLocInt + 1; i < inputVector.size(); i++){
				inputVector2.insert(inputVector2.end(), inputVector[i]);
			}

			return shellPipe(inputVector1, inputVector2, history, totalTime);
		} 
		catch(std::exception& e){
			std::cout << "Pipe needs previous command.\n";
			return true;
		}// end catch block

	}
	else{
		return shell(inputVector, history, totalTime);
	}
	return true;
} // end execute
