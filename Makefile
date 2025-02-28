# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g

# Executable name
EXEC = main

# Source files (add your files here)
SRC = main.cpp ivedimo_funkcijos.cpp apdorojimo_funkcijos.cpp spausdinimo_funkcijos.cpp
OBJ = $(SRC:.cpp=.o)

# Default rule to build the executable
all: $(EXEC)

# Linking step
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

# Compiling each .cpp file into an .o file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove compiled files
clean:
	rm -f $(EXEC) $(OBJ)
