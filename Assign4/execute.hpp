// Lia Bogoev
// execute.hpp

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <exception>
#include <iostream>
#include <cstring>
#include <string>
#include <chrono>
#include <vector>

std::vector<std::string> split(std::string originalString, char c);

bool shell(std::vector<std::string> &, std::vector<std::string> &, std::chrono::microseconds &);

bool execute(std::string &, std::vector<std::string> &, std::chrono::microseconds &);

