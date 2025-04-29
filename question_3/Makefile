# Makefile to run HeapBottomUp algorithm
CXX = g++
CXXFLAGS = -Wall -std=c++17

SRC = heap_bottom_up.cc
HEADER = heap_bottom_up.h
TARGET = heap_bottom_up
OUTPUT = output.txt

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -c $(SRC) -o $(SRC:.cc=.o)
	$(CXX) $(CXXFLAGS) $(SRC:.cc=.o) -o $(TARGET)

clean:
	rm -f $(TARGET) $(SRC:.cc=.o) $(OUTPUT)
