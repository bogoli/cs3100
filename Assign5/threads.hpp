// Lia Bogoev
// threads.hpp
#pragma once

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

#include "syncClass.hpp"

int makeRandom(int, std::mutex&);
void makeProducerThread(int, std::mutex&, SynchronizedPriorityQueue<int>&);
void makeConsumerThread(int, std::mutex&, SynchronizedPriorityQueue<int>&);
