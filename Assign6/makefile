# Lia Bogoev
# makefile for Assign6

# Compile and link shared libraries:
# gcc -c -fpic library.cpp
# gcc -shared -o library.so library.o

trig: Assign6.o trig-lookup.so trig-std.so
	g++ -std=c++11 -o trig Assign6.cpp -ldl  #-ldl for shared libraries

trig-lookup.so: trig-lookup.cpp
	gcc -c -fpic trig-lookup.cpp
	gcc -shared -o trig-lookup.so trig-lookup.o

trig-std.so: trig-std.cpp
	gcc -c -fpic trig-std.cpp
	gcc -shared -o trig-std.so trig-std.o

clean:
	rm trig
	rm *.so
	rm *.o

