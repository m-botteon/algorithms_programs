// Copyright 2025 mbotteon
// Contains the prototypes for functions involved with Merge and Quick Sort

#ifndef _SORT_H_
#define _SORT_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>

// Read in a list of numbers from a text file
std::vector<float> ReadFile(std::string);

// Combine the arrays back together
void Merge(std::vector<float>&, std::vector<float>&, std::vector<float>&);

// Sort a list of numbers by MergeSort
void MergeSort(std::vector<float>&);

// Partition the array into two subarrays: less than and greater than pivot
int Partition(std::vector<float>& array, int low, int high);

// Sort a list of numbers by QuickSort
void QuickSort(std::vector<float>& array, int low, int high);

#endif  // _SORT_H_

