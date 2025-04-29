# Makefile to run Horspool's String Matching algorithm
CXX = g++
CXXFLAGS = -Wall -std=c++17

SRC = horspool.cc
HEADER = horspool.h
TARGET = horspool
OUTPUT = output.txt

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -c $(SRC) -o $(SRC:.cc=.o)
	$(CXX) $(CXXFLAGS) $(SRC:.cc=.o) -o $(TARGET)

clean:
	rm -f $(TARGET) $(SRC:.cc=.o) $(OUTPUT)
