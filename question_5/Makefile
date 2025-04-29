# Makefile to run Floyd's algorithm
CXX = g++
CXXFLAGS = -Wall -std=c++17

SRC = floyd.cc
HEADER = floyd.h
TARGET = floyd
OUTPUT = output.txt

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -c $(SRC) -o $(SRC:.cc=.o)
	$(CXX) $(CXXFLAGS) $(SRC:.cc=.o) -o $(TARGET)

clean:
	rm -f $(TARGET) $(SRC:.cc=.o) $(OUTPUT)
