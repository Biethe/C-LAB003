CXX = g++
CXXFLAGS  = -Wall -I./include

SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin

SOURCES := $(wildcard $(SRC_DIR)/*.c*)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))
EXECUTABLE = ex3 

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $(BIN_DIR)/$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $(OBJ_DIR)/$@

clean:
	rm -f $(BIN_DIR)/* $(OBJ_DIR)/*
