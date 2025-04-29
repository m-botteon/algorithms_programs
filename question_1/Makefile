# Makefile to run Topology Search algorithms
CXX = g++
CXXFLAGS = -Wall -std=c++17

SRC = topology.cc
HEADER = topology.h
TARGET = topology
OUTPUT = output.txt

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -c $(SRC) -o $(SRC:.cc=.o)
	$(CXX) $(CXXFLAGS) $(SRC:.cc=.o) -o $(TARGET)

clean:
	rm -f $(TARGET) $(SRC:.cc=.o) $(OUTPUT)
