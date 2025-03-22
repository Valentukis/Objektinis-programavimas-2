CXX = g++
CXXFLAGS = -O3 -Wall -std=c++17

.DEFAULT_GOAL := main

vector: vector/*.cpp
	$(CXX) $(CXXFLAGS) -o vector_program vector/*.cpp

main: class/*.cpp
	$(CXX) $(CXXFLAGS) -o main class/*.cpp

clean:
	rm -f vector_program class_program
