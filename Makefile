CC = g++
CFLAGS = -Wall -I./include

SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin

SOURCES := $(wildcard $(SRCDIR)/*.c*)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

EXECUTABLE = $(BINDIR)/factorial $(BINDIR)/ex3 

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BINDIR)/* $(OBJDIR)/*
