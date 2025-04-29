// Copyright 2025 mbotteon
// Contains the MergeSort and QuickSort algorithms

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>
#include <chrono>

#include "sort.h"

// Read in a list of numbers from a text file
std::vector<float> ReadFile(std::string file_name) {
    std::ifstream file(file_name);
    std::vector<float> numbers;
    std::string line;

  // If file cannot be opened, print error message
  if (!file)
    std::cerr << "Error: Cannot open file 'input.txt'" << std::endl;
    
  // Check if the line exists
  if (std::getline(file, line)) {
    std::istringstream iss(line);
    float num;
    // For each number, add it to the vector
    while (iss >> num) {
      numbers.push_back(num);
    }
  }

  // Close the file and return the vector
  file.close();  
  return numbers;
}

// Combine the arrays back together
void Merge(std::vector<float>& left, std::vector<float>& right,
           std::vector<float>& array) {
  size_t i = 0;
  size_t j = 0;
  int k = 0;
  
  // Merge the subarrays together via comparison of their first elements
  while (i < left.size() && j < right.size()) {
    // If the element in the left subarray is smaller, place it in main array
    if (left[i] <= right[j]) {
      array[k] = left[i];
      ++i;
    }
    // Else, place the first element of the right subarray in the main array
    else {
      array[k] = right[j];
      ++j;
    }
    ++k;
  }
  
  // If there are any leftover elements in the left array, move them in
  while (i < left.size()) {
    array[k] = left[i];
    ++i;
    ++k;
  }
  // If there are any leftover elements in the right array, move them in
  while (j < right.size()) {
    array[k] = right[j];
    ++j;
    ++k;
  }
}

// Sort a list of numbers by MergeSort
void MergeSort(std::vector<float>& array) {
  if (array.size() > 1) {

    // Create two temporary subarrays to split the current array
    std::vector<float> temp_left;
    std::vector<float> temp_right;
    
    for (size_t i = 0; i < array.size(); ++i) {
      if (i < array.size() / 2)
        temp_left.push_back(array[i]);
      else
        temp_right.push_back(array[i]);
    }
    
    MergeSort(temp_left);
    MergeSort(temp_right);
    Merge(temp_left, temp_right, array);
  }
}

// Partition the array into two subarrays: less than and greater than pivot
int Partition(std::vector<float>& array, int low, int high) {
  // Pivot is set to the first element
  float p = array[low];
  int i = low;
  int j = high;
  
  // Iterate through the array to find elements to swap
  while (i < j) {
    // Stop iterating i when an element larger than pivot is found
    while (i < high && array[i] <= p)
      ++i;
    // Stop iterating j when an element smaller than pivot is found
    while (j > low && array[j] > p)
      --j;
    if (i < j) {
      // Swap elements at positions i and j
      float temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }

  // Swap elements at j and pivot
  array[low] = array[j];
  array[j] = p;
  return j;
}

// Sort a list of numbers by QuickSort
void QuickSort(std::vector<float>& array, int low, int high) {
  if (low < high) {
    int s = Partition(array, low, high);
    QuickSort(array, low, s - 1);
    QuickSort(array, s + 1, high);
  }
}

int main(int argc, char *argv[]) {
  // Check the number of inputs
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
    return 1;
  }

  // Call the ReadFile function to generate the list of unsorted numbers
  std::vector<float> array = ReadFile(argv[1]);
  // Make a copy of this to demonstrate QuickSort later
  std::vector<float> array_copy = array;
  
  // Open an output.txt file for writing
  std::ofstream outputFile;
  outputFile.open("output.txt");
  if (!outputFile.is_open()) {
    std::cerr << "Error: Cannot open file 'output.txt'" << std::endl;
    return 1;
  }
    
  // Display the unsorted list
  outputFile << "Print the unsorted list:" << std::endl;
  for (float val : array)
    outputFile << val << ' ';
  outputFile << "\n" << std::endl;

  // Call the Merge Sort function 
  auto start = std::chrono::high_resolution_clock::now();
  MergeSort(array);
  auto end = std::chrono::high_resolution_clock::now();
  auto time = std::chrono::duration<double, std::milli>(end - start);
  outputFile << "MergeSort took " << time.count()
             << " ms to run.\n" << std::endl;
  
  // Display the sorted list
  outputFile << "Print the sorted list via Merge Sort:" << std::endl;
  for (float val : array)
    outputFile << val << ' ';
  outputFile << "\n" << std::endl;
  
  // Display the unsorted list
  outputFile << "Print the unsorted list:" << std::endl;
  for (float val : array_copy)
    outputFile << val << ' ';
  outputFile << "\n" << std::endl;
  
  // Call the Quick Sort function on the unsorted copy
  start = std::chrono::high_resolution_clock::now();
  QuickSort(array_copy, 0, array_copy.size() - 1);
  end = std::chrono::high_resolution_clock::now();
  time = std::chrono::duration<double, std::milli>(end - start);
  outputFile << "QuickSort took " << time.count()
             << " ms to run.\n" << std::endl;
  
  // Display the sorted list
  outputFile << "Print the sorted list via Quick Sort:" << std::endl;
  for (float val : array_copy)
    outputFile << val << ' ';
  outputFile << "\n" << std::endl;

  return 0;
}

