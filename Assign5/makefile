threads.app: Assign5.o threads.o
	g++ -std=c++11 -o threads.app Assign5.o threads.o -lpthread

Assign5.o: Assign5.cpp threads.cpp
	g++ -std=c++11 -c Assign5.cpp

threads.o: threads.cpp threads.hpp
	g++ -std=c++11 -c threads.cpp

clean:
	rm *.app
	rm *.o

