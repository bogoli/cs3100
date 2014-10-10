// Lia Bogoev
// execute.hpp
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <iostream>
#include <stdio.h>
#include <string>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>

std::vector<std::string> split(std::string originalString, char c);

bool shell(std::vector<std::string> &, std::vector<std::string> &, std::chrono::microseconds &);

bool pipeCheck(std::vector<std::string> &, std::vector<std::string>::iterator &, int &);

bool shellPipe(std::vector<std::string> &, std::vector<std::string> &, std::vector<std::string> &, std::chrono::microseconds &);

bool execute(std::string &, std::vector<std::string> &, std::chrono::microseconds &);

