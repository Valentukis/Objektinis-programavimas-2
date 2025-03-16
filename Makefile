CXX = g++
CXXFLAGS = -O3 -Wall -std=c++17

vector: vector/*.cpp
	$(CXX) $(CXXFLAGS) -o vector_program vector/*.cpp

deque: deque/*.cpp
	$(CXX) $(CXXFLAGS) -o deque_program deque/*.cpp

list: list/*.cpp
	$(CXX) $(CXXFLAGS) -o list_program list/*.cpp

clean:
	rm -f vector_program deque_program list_program
