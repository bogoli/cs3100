// Lia Bogoev
// execute.hpp

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#include <iostream>
#include <cstring>
#include <chrono>
#include <vector>


bool execute(std::string &, std::vector<std::string> &);