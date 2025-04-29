# Makefile to run MergeSort and QuickSort algorithms
CXX = g++
CXXFLAGS = -Wall -std=c++17

SRC = sort.cc
HEADER = sort.h
TARGET = sort
OUTPUT = output.txt

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -c $(SRC) -o $(SRC:.cc=.o)
	$(CXX) $(CXXFLAGS) $(SRC:.cc=.o) -o $(TARGET)

clean:
	rm -f $(TARGET) $(SRC:.cc=.o) $(OUTPUT)
