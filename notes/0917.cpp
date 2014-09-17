// 09.17.2014 
// an example of how execvp works
/*
#include <iostream>
#include <unistd.h>
#include <cstring>

int main(){
	char** argv;

	argv = new char*[4];
	argv[0] = new char[3];
	argv[1] = new char[3];
	argv[2] = new char[3];
	argv[3] = NULL;

	std::strcpy(argv[0], "ls");
	std::strcpy(argv[1], "-l");
	std::strcpy(argv[2], "-a");

	// call execvp. everything after is skipped.
	execvp(argv[0],argv);

	std::cout << "This shouldn't show up because we replaced the process. \n";

	return 0;

}
*/

#include <iostream>
#include <chrono>

int main(){
	// auto tells the operating system to deduce the variable type
	// NOT  dynamic type
	auto start = std::chrono::system_clock::now();  // this is a time point
	std::cout << "This is a time test... \n";
	auto end = std::chrono::system_clock::now();

 	// when you subtract two time points you get a duration
	// want to cast this duration to the unit we want
	auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start); 
	std::cout << "The time diff is: " << diff.count() << "\n";






	return 0;
}