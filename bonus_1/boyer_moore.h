// Copyright 2025 mbotteon
// Contains the function declarations for Boyer-Moore's algorithm

#ifndef BOYER_MOORE_H_
#define BOYER_MOORE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>

// Read in a list of integer keys from a text file
std::vector<std::string> ReadFile(std::string);

// Preprocess the pattern to build a shift table
std::unordered_map<char, int> ShiftTable(const std::string&);

// Preprocess the pattern to build a new shift table for when a match is made
std::vector<int> GoodSuffixTable(const std::string&)
  
int BoyerMooreSearch(const std::string&, const std::string&);

#endif // BOYER_MOORE_H_

