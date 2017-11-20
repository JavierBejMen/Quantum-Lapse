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
PNGFLAGS = -lpng
 

MAINDEPENDENCIES = $(OBJ)/Sprite.o $(OBJ)/SpriteShader.o $(OBJ)/utils.o $(OBJ)/FileWrapper.o $(OBJ)/FrameTimer.o $(OBJ)/ShipShader.o $(OBJ)/Shader.o $(OBJ)/Pixel.o $(OBJ)/Ship.o $(OBJ)/PixelArray.o $(OBJ)/ImageBuffer.o $(OBJ)/main.o   

TARGETS = clean $(BIN)/main

all: $(TARGETS)

$(BIN)/main: $(MAINDEPENDENCIES)
	$(CC) $^ $(GLGLEWFLAGS) $(CCFLAGS) -o $@  $(PNGFLAGS)

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
	
$(OBJ)/ImageBuffer.o: $(SRC)/ImageBuffer.cpp
	$(CC) $(CCFLAGS) -c -o $@ $^ -I$(INCLUDE)
	
$(OBJ)/FileWrapper.o: $(SRC)/FileWrapper.cpp
	$(CC) $(CCFLAGS) -c -o $@ $^ -I$(INCLUDE)
	
$(OBJ)/utils.o: $(SRC)/utils.cpp
	$(CC) $(CCFLAGS) -c -o $@ $^ -I$(INCLUDE)
	
$(OBJ)/SpriteShader.o: $(SRC)/SpriteShader.cpp
	$(CC) $(CCFLAGS) -c -o $@ $^ -I$(INCLUDE)

$(OBJ)/Sprite.o: $(SRC)/Sprite.cpp
	$(CC) $(CCFLAGS) -c -o $@ $^ -I$(INCLUDE)
	
# Clean
.PHONY: clean

clean:
	-rm $(BIN)/* $(OBJ)/*
