# Makefile
# Quantum-Lapse
# Javier Bejar Mendez

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

CC = c++
CCFLAGS = -std=c++11 -Wall -O3

MAINDEPENDENCIES = $(OBJ)/main.o $(OBJ)/Pixel.o

TARGETS = clean $(BIN)/main

all: $(TARGETS)

$(BIN)/main: $(MAINDEPENDENCIES)
	$(CC) $(CCFLAGS) -o $@ $^ 

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CCFLAGS) -c -o $@ $^ -I$(INCLUDE)

$(OBJ)/Pixel.o: $(SRC)/Pixel.cpp
	$(CC) $(CCFLAGS) -c -o $@ $^ -I$(INCLUDE)
	
# Clean
.PHONY: clean

clean:
	-rm $(BIN)/* $(OBJ)/*.o
