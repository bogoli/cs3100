# Lia Bogoev
# makefile for Assign6

# Compile and link shared libraries:
# gcc -c -fpic library.cpp
# gcc -shared -o library.so library.o
# 
# Compile and link a program that uses shared libraries:
# g++ -o program program.cpp -ldl

trig.app: Assign6.o
	g++ -std=c++11 -o trig.app Assign6.o 

Assign6.o: Assign6.cpp 
	g++ -std=c++11 -c Assign6.cpp

clean:
	rm *.app
	rm *.o

