// Copyright 2025 mbotteon
// Contains the HeapSort algorithm function declaration
// 1-indexed array representation of a heap - index 0 contains # of elements

#ifndef HEAPSORT_H_
#define HEAPSORT_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>

// Read in a list of integer keys from a text file
std::vector<int> ReadFile(std::string file_name);

// Heapifies the remaining elements after root removal
void Heapify(std::vector<int>& array, int n, int i);

void HeapSort(std::vector<int>& array);

#endif // HEAPSORT_H_

