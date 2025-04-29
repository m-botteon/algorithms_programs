// Copyright 2025 mbotteon
// Contains the function declarations for HeamBottomUp 

#ifndef HEAP_BOTTOM_UP_H
#define HEAP_BOTTOM_UP_H

#include <vector>
#include <string>

// Read in a list of integer keys from a text file
std::vector<int> ReadFile(std::string);

// Create a heap rooted at the max element
void MaxHeapBottomUp(std::vector<int>&);

// Create a heap rooted at the min element
void MinHeapBottomUp(std::vector<int>&);

#endif // HEAP_BOTTOM_UP_H_

