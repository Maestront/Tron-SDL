CXX = g++
CXXFLAGS = -I/path/to/SFML/include -L/path/to/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system

all: main

bin/main : src/main.cpp include/*.hpp
	$(CXX) $< $(CXXFLAGS) -I include -o $@
	
run : bin/main
	./$<
