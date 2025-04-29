// Copyright 2025 mbotteon
// Contains the HeapSort algorithm
// 1-indexed array representation of a heap - index 0 contains # of elements

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>

#include "heapsort.h"

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

// Heapifies the remaining elements after root removal
void Heapify(std::vector<int>& array, int n, int i) {
  // Set max to the root
  int max = i;
  
  // Left index
  int left = 2 * i;
  
  // Right index
  int right = 2 * i + 1;
  
  // If left is within array and larger than max, set max to left
  if (left < n && array[left] > array[max])
    max = left;
    
  // If right is within array and larger than max, set max to left
  if (right < n && array[right] > array[max])
    max = right;
    
  // If max is no longer root, swap must be made
  if (max != i) {
    int temp = array[i];
    array[i] = array[max];
    array[max] = temp;
    
    // Heapify the subtree to ensure the entire heap makes necessary swaps
    Heapify(array, n, max);
  }
}

void HeapSort(std::vector<int>& array) {
  // Build the heap
  for (int i = array.size()/2 - 1; i > 0; --i)
    Heapify(array, array.size(), i);
    
  // Iterate over the array and remove the root
  for (int i = array.size() - 1; i > 1; i--) {
    // Swap the root to the end to "remove" it
    int temp = array[1];
    array[1] = array[i];
    array[i] = temp;
    
    // Heapify the remaining subarray to move the max element to root
    Heapify(array, i, 1);
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
  
  // Open an output.txt file for writing
  std::ofstream outputFile;
  outputFile.open("output.txt");
  if (!outputFile.is_open()) {
    std::cerr << "Error: Cannot open file 'output.txt'" << std::endl;
    return 1;
  }
  
  // Display the unsorted list
  outputFile << "Print the unsorted list:" << std::endl;
  for (size_t i = 1; i < array.size(); ++i)
    outputFile << array[i] << ' ';
  outputFile << "\n" << std::endl;
  
  // Display the heap - this step is written into the function
  outputFile << "Print the heap:" << std::endl;
  // Build the heap
  for (int i = array.size()/2 - 1; i > 0; --i)
    Heapify(array, array.size(), i);
  for (size_t i = 1; i < array.size(); ++i)
    outputFile << array[i] << ' ';
  outputFile << "\n" << std::endl;

  // Call the Heap Sort function 
  HeapSort(array);
  
  // Display the sorted list
  outputFile << "Print the sorted list, starting by removing the largest num:"
             << std::endl;
  for (size_t i = 1; i < array.size(); ++i)
    outputFile << array[i] << ' ';
  outputFile << "\n" << std::endl;
}

