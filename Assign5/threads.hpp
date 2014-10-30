// Lia Bogoev
// threads.hpp

#include <chrono>
#include <cstdlib>
#include <exception>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <unistd.h>


int makeRandom(int);
void makeThread(int, std::mutex&);
