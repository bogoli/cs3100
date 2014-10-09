shell: Assign4.o execute.o
	g++ -std=c++11 -o shell.app Assign4.o execute.o

Assign4.o: Assign4.cpp execute.cpp
	g++ -std=c++11 -c Assign4.cpp

execute.o: execute.cpp execute.hpp
	g++ -std=c++11 -c execute.cpp

clean:
	rm *.app
	rm *.o
