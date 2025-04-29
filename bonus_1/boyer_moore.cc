// Copyright 2025 mbotteon
// Contains the source code for Boyer-Moore's algorithm

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>

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
  int m = pattern.length();
  
  // Add the alphabet and space as keys with pattern length as default value
  for (char c = 'A'; c <= 'Z'; ++c) {
    table[c] = m;
  }
  table[' '] = m;
  
  // Replace the default value with rightmost occurence of each pattern char
  for (int i = 0; i < m - 1 ; ++i)
    table[pattern[i]] = m - 1 - i;
  
  return table;
}

// Preprocess the pattern to build a new shift table for when a match is made
std::vector<int> GoodSuffixTable(const std::string& pattern) {
  int m = pattern.length();
  std::vector<int> table(m);
  std::vector<int> borderPos(m + 1);
  
  // Use borders - a preifx and suffix are equal  
  int i = m;
  int j = m + 1;
  borderPos[i] = j;
    
  // Preprocessing to compute border positions
  while (i > 0) {
    while (j <= m && pattern[i - 1] != pattern[j - 1]) {
      if (table[j] == 0)
        table[j] = j - i;
      j = borderPos[j];
    }
    --i;
    --j;
    borderPos[i] = j;
  }

  // Set the shift amounts
  for (int i = 0; i <= m; ++i) {
    if (table[i] == 0)
      table[i] = j;
    if (i == j)
      j = borderPos[j];
  }

  // Now adjust to size m and shift positions - ChatGPT helped here
  std::vector<int> final_table(m);
  for (int i = 0; i < m; ++i)
    final_table[i] = table[i + 1];

  return final_table;
}
  
int BoyerMooreSearch(const std::string& pattern, const std::string& text) {
  size_t m = pattern.length();
  
  // Pattern will not be in text if it is longer
  if (m > text.length())
    return -1;

  // Generate shift tables
  std::unordered_map<char, int> shift_table = ShiftTable(pattern);
  std::vector<int> good_suffix = GoodSuffixTable(pattern);
  
  // Begin at right end of pattern
  size_t i = 0;
  // Begin at leftmost index of text
  int j;
    while (i <= text.length() - m) {
        j = m - 1;
        // Compare characters from right to left
        while (j >= 0 && pattern[j] == text[i + j])
          --j;
        // If all characters match, return index
        if (j < 0)
          return i;
        // Else shift the index by max of bad character and good suffix values
        else {
          int bad_char_shift = shift_table[text[i + j]] - (m - 1 - j);
          int good_suffix_shift = good_suffix[j];
          i += std::max(1, std::max(bad_char_shift, good_suffix_shift));
        }
    }
    // If no match is ever found, return -1
    return -1;
}

int main(int argc, char *argv[]) {
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
  outputFile << "Print the pattern: " << std::endl;
  for (size_t i = 0; i < strings[0].length(); ++i) {
    outputFile << strings[0][i];
  }
  outputFile << "\n" << std::endl;
  
  // Print the text
  outputFile << "Print the text: " << std::endl;
  for (size_t i = 0; i < strings[1].length(); ++i) {
    outputFile << strings[1][i];
  }
  outputFile << "\n" << std::endl;
  
  outputFile << "Match found at: " << BoyerMooreSearch(strings[0], strings[1])
            << std::endl;
  return 0;
} 

