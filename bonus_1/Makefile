# Makefile to run Boyer-Moore String Matching algorithm
CXX = g++
CXXFLAGS = -Wall -std=c++17

SRC = boyer_moore.cc
HEADER = boyer_moore.h
TARGET = boyer_moore
OUTPUT = output.txt

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -c $(SRC) -o $(SRC:.cc=.o)
	$(CXX) $(CXXFLAGS) $(SRC:.cc=.o) -o $(TARGET)

clean:
	rm -f $(TARGET) $(SRC:.cc=.o) $(OUTPUT)
