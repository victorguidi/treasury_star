# This is the Makefile for the project that uses OpenGL
# The main entry point for this project is main.cpp

# First we define the compiler and the flags to use
CXX = g++
CXXFLAGS = -Wall -g
LDLIBS = -lGL -lGLU -lglut

# The all target is the default target, which depends on the main target
all: main

main: main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDLIBS)

# The clean target removes all the object files and the executablea, and PHONY tells make that this is not a file
.PHONY: clean
clean:
	rm -f main

# The run target runs the executable
run: main
	./main

