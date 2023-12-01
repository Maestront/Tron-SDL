CXX = g++
CXXFLAGS = -IC:\msys64\mingw64\include\SDL2 -LC:\msys64\mingw64\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2

all: game

bin/ejemplo : src/ejemplo.cpp 
	$(CXX) $< $(CXXFLAGS) -o $@

bin/Game : src/game.cpp
	$(CXX) $< $(CXXFLAGS) -o $@

run : bin/Game
	./$<