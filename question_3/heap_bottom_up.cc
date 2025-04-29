// Copyright 2025 mbotteon
// Contains the HeamBottomUp algorithms for max and min heaps

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>
#include <chrono>

#include "heap_bottom_up.h"

// Read in a list of integer keys from a text file
std::vector<int> ReadFile(std::string file_name) {
    std::ifstream file(file_name);
    std::vector<int> integers;
    std::string line;

  // If file cannot be opened, print error message
  if (!file)
    std::cerr << "Error: Cannot open file 'input.txt'" << std::endl;
    
  // For each line, parse through
  // The first line will be the size, which will take index 0
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    int num;
    // For each number, add it to the vector
    while (iss >> num) {
      integers.push_back(num);
    }
  }

  // Close the file and return the vector
  file.close();  
  return integers;
}

void MaxHeapBottomUp(std::vector<int>& array) {
  int k, v, j;
  int n = array.size();
  bool heap;
  for (int i = floor(n/2); i > 0; --i) {
    k = i;
    v = array[k];
    heap = false;
    // Check the heap is not yet complete and k is still within the parents
    while (!heap && (2 * k) <= n) {
      j = 2 * k;
      // Check if there are two children
      if (j < n) {
        // Check if the second child is smaller
        if (array[j] < array[j + 1])
          ++j;
      }
      // Check if the array has been arranged into a heap
      if (v >= array[j])
        heap = true;
      // Otherwise move the element in j to parent position
      else {
        array[k] = array[j];
        k = j;
      }
    } 
    array[k] = v;
  }
}

void MinHeapBottomUp(std::vector<int>& array) {
  int k, v, j;
  int n = array.size();
  bool heap;
  for (int i = floor(n/2); i > 0; --i) {
    k = i;
    v = array[k];
    heap = false;
    // Check the heap is not yet complete and k is still within the parents
    while (!heap && (2 * k) <= n - 1) {
      j = 2 * k;
      // Check if there are two children
      if (j < n - 1) {
        // Check if the second child is larger
        if (array[j] > array[j + 1])
          ++j;
      }
      // Check if the array has been arranged into a heap
      if (v <= array[j])
        heap = true;
      // Otherwise move the element in j to parent position
      else {
        array[k] = array[j];
        k = j;
      }
    } 
    array[k] = v;
  }
}

int main(int argc, char *argv[]) {
  // Check the number of inputs
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
    return 1;
  }

  // Call the ReadFile function to generate the list of unsorted keys
  std::vector<int> array = ReadFile(argv[1]);
  
  // Make a copy of the array to use for the Min function
  std::vector<int> array_copy = array;
  
  // Open an output.txt file for writing
  std::ofstream outputFile;
  outputFile.open("output.txt");
  if (!outputFile.is_open()) {
    std::cerr << "Error: Cannot open file 'output.txt'" << std::endl;
    return 1;
  }
  
  // Display the unheapified list
  outputFile << "Print the unheapified list:" << std::endl;
  for (size_t i = 1; i < array.size(); ++i)
    outputFile << array[i] << ' ';
  outputFile << "\n" << std::endl;

  // Call the HeapBottomUp function
  auto start = std::chrono::high_resolution_clock::now();
  MaxHeapBottomUp(array);
  auto end = std::chrono::high_resolution_clock::now();
  auto max_time = std::chrono::duration<double, std::milli>(end - start);
  outputFile << "Max HeapBottomUp took " << max_time.count()
             << " ms to run." << std::endl;
  
  // Display the heapified list
  outputFile << "Print the heapified list for a max heap:" << std::endl;
  for (size_t i = 1; i < array.size(); ++i)
    outputFile << array[i] << ' ';
  outputFile << "\n" << std::endl;
  
  // Display the unheapified list
  outputFile << "Print the unheapified list:" << std::endl;
  for (size_t i = 1; i < array_copy.size(); ++i)
    outputFile << array_copy[i] << ' ';
  outputFile << "\n" << std::endl;

  // Call the HeapBottomUp function 
  start = std::chrono::high_resolution_clock::now();
  MinHeapBottomUp(array_copy);
  end = std::chrono::high_resolution_clock::now();
  auto min_time = std::chrono::duration<double, std::milli>(end - start);
  outputFile << "Min HeapBottomUp took " << min_time.count()
             << " ms to run." << std::endl;
  
  // Display the heapified list
  outputFile << "Print the heapified list for a min heap:" << std::endl;
  for (size_t i = 1; i < array_copy.size(); ++i)
    outputFile << array_copy[i] << ' ';
 outputFile << "\n" << std::endl;
}

