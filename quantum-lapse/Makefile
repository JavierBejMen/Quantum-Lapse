# Makefile
# Quantum-Lapse
# Javier Bejar Mendez

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

CC = g++
CCFLAGS = -std=c++11 -Wall -O3 
GLGLEWFLAGS = -lGL -lGLEW -lSDL2

MAINDEPENDENCIES = $(OBJ)/main.o $(OBJ)/FrameTimer.o $(OBJ)/ShipShader.o $(OBJ)/Shader.o $(OBJ)/Pixel.o $(OBJ)/Ship.o $(OBJ)/PixelArray.o

TARGETS = clean $(BIN)/main

all: $(TARGETS)

$(BIN)/main: $(MAINDEPENDENCIES)
	$(CC) $^ $(GLGLEWFLAGS) $(CCFLAGS) -o $@  

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CCFLAGS) -c -o $@ $^ -I$(INCLUDE)
	
$(OBJ)/FrameTimer.o: $(SRC)/FrameTimer.cpp
	$(CC) $(CCFLAGS) -c -o $@ $^ -I$(INCLUDE)
	
$(OBJ)/Shader.o: $(SRC)/Shader.cpp 
	$(CC) $(CCFLAGS) -c -o $@ $^ -I$(INCLUDE)
	
$(OBJ)/ShipShader.o: $(SRC)/ShipShader.cpp 
	$(CC) $(CCFLAGS) -c -o $@ $^ -I$(INCLUDE)
	
$(OBJ)/Pixel.o: $(SRC)/Pixel.cpp
	$(CC) $(CCFLAGS) -c -o $@ $^ -I$(INCLUDE)
	
$(OBJ)/PixelArray.o: $(SRC)/PixelArray.cpp
	$(CC) $(CCFLAGS) -c -o $@ $^ -I$(INCLUDE)
	
$(OBJ)/Ship.o: $(SRC)/Ship.cpp
	$(CC) $(CCFLAGS) -c -o $@ $^ -I$(INCLUDE)
	
# Clean
.PHONY: clean

clean:
	-rm $(BIN)/* $(OBJ)/*
