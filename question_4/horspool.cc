// Copyright 2025 mbotteon
// Contains the source code for Horspool's algorithm

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>
#include <chrono>

#include "horspool.h"

// Read in a list of integer keys from a text file
std::vector<std::string> ReadFile(std::string file_name) {
    std::ifstream file(file_name);
    std::vector<std::string> strings;
    std::string line;

  // If file cannot be opened, print error message
  if (!file)
    std::cerr << "Error: Cannot open file 'input.txt'" << std::endl;
    
  // For each line, parse through
  // First line is pattern, second line is text string
  while (std::getline(file, line)) {
    strings.push_back(line);
  }

  // Close the file and return the vector
  file.close();  
  return strings;
}

// Preprocess the pattern to build a shift table
std::unordered_map<char, int> ShiftTable(const std::string& pattern) {
  std::unordered_map<char, int> table;
  size_t m = pattern.length();
  
  // Add the alphabet and space as keys with pattern length as default value
  for (char c = 'A'; c <= 'Z'; ++c) {
    table[c] = m;
  }
  table[' '] = m;
  
  // Replace the default value with rightmost occurence of each pattern char
  for (size_t i = 0; i < m - 1; ++i)
    table[pattern[i]] = m - 1 - i;
  
  return table;
}
  
int HorspoolSearch(const std::string& pattern, const std::string& text) {
  size_t m = pattern.length();
  
  // Pattern will not be in text if it is longer
  if (m > text.length())
    return -1;

  // Generate shift table
  std::unordered_map<char, int> shift_table = ShiftTable(pattern);

  // Begin at right end of pattern
  size_t i = m - 1;
  size_t k = 0;
  while (i <= text.length() - 1) {
    // Counter for number of matches
    k = 0;
    // Increment counter if a match is found
    while (k <= m - 1 && pattern[m - 1 - k] == text[i - k]) {
      ++k;
    }
    // If all characters match, return index
    if (k == m)
      return i - m + 1;
    // Else shift the index by the value corresponding to the current text char
    else
      i += shift_table[text[i]];
  }
  // If no match is ever found, return -1
  return -1;
}

int main(int argc, char *argv[]) {
  // Check the number of inputs
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
    return 1;
  }

  // Call the ReadFile function to read the pattern and text
  std::vector<std::string> strings = ReadFile(argv[1]);
  
  // Open an output.txt file for writing
  std::ofstream outputFile;
  outputFile.open("output.txt");
  if (!outputFile.is_open()) {
    std::cerr << "Error: Cannot open file 'output.txt'" << std::endl;
    return 1;
  }
  
  // Print the pattern
  outputFile << "Pattern:" << std::endl;
  for (size_t i = 0; i < strings[0].length(); ++i) {
    outputFile << strings[0][i];
  }
  outputFile << "\n" << std::endl;
  
  // Print the text
  outputFile << "Text:" << std::endl;
  for (size_t i = 0; i < strings[1].length(); ++i) {
    outputFile << strings[1][i];
  }
  outputFile << "\n" << std::endl;
  
  // Run the algorithm
  auto start = std::chrono::high_resolution_clock::now();
  int index = HorspoolSearch(strings[0], strings[1]);
  auto end = std::chrono::high_resolution_clock::now();
  auto time = std::chrono::duration<double, std::milli>(end - start);
  
  outputFile << "Horspool's Algorithm took " << time.count()
             << " ms to run." << std::endl;
  if (index != -1)
    outputFile << "Match found at: " << index << std::endl;
  else
    outputFile << index << " No match found." << std::endl;
    
  return 0;
} 

