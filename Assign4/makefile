shell: Assign3.o execute.o
	g++ -std=c++11 -o shell.app Assign3.o execute.o

Assign3.o: Assign3.cpp execute.cpp
	g++ -std=c++11 -c Assign3.cpp

execute.o: execute.cpp execute.hpp
	g++ -std=c++11 -c execute.cpp

clean:
	rm *.app
	rm *.o
