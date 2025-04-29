// Copyright 2025 mbotteon
// Contains the declaration of functions for Horspool's algorithm

#ifndef HORSPOOL_H_
#define HORSPOOL_H_

#include <vector>
#include <string>
#include <unordered_map>

// Read in a list of integer keys from a text file
std::vector<std::string> ReadFile(std::string);

// Preprocess the pattern to build a shift table
std::unordered_map<char, int> ShiftTable(const std::string&);
  
int HorspoolSearch(const std::string&, const std::string&);

#endif // HORSPOOL_H_

