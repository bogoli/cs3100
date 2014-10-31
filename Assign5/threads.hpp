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
#include <vector>

int makeRandom(int, std::mutex&);
void makeThread(int, std::mutex&);
