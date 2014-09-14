Assign2: Assign2.o Assign2fib.o Assign2e.o Assign2pi.o
	g++ -std=c++11 -o Assign2 Assign2.o Assign2fib.o Assign2e.o Assign2pi.o

Assign2.o: Assign2.cpp Assign2fib.cpp Assign2e.cpp Assign2pi.cpp
	g++ -std=c++11 -c Assign2.cpp

Assign2fib.o: Assign2fib.cpp Assign2fib.hpp
	g++ -c Assign2fib.cpp

Assign2e.o:	Assign2e.cpp Assign2e.hpp
	g++ -c Assign2e.cpp

Assign2pi.o: Assign2pi.cpp Assign2pi.hpp
	g++ -c Assign2pi.cpp

clean: 
	rm *.o
	rm Assign2
