CC = gcc
CXX = g++
CXXFLAGS = -Wall -I./include #-std=c++11

SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin

SOURCES := $(wildcard $(SRC_DIR)/*.c*)
C_OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))
CXX_OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))
#EXECUTABLE := $(patsubst $(SRC_DIR)/%.c*,$(BIN_DIR)/%,$(SOURCES))

EXECUTABLE = lab3

all: $(EXECUTABLE)

$(EXECUTABLE): $(CXX_OBJECTS)
	@mkdir -p $(BIN_DIR) # create bin/ if it doesn't exist
	$(CXX) $(CXXFLAGS) $^ -o $(BIN_DIR)/$@

ex1: $(OBJ_DIR)/ex1.o
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $(BIN_DIR)/$@

factorial: $(OBJ_DIR)/factorial.o
	@mkdir -p $(BIN_DIR)
	$(CC) $^ -o $(BIN_DIR)/$@

ex4: $(OBJ_DIR)/Currency.o $(OBJ_DIR)/ex4.o
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $(BIN_DIR)/$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	rm -f $(BIN_DIR)/* $(OBJ_DIR)/*
