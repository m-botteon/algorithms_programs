// Copyright 2025 mbotteon
// Contains function declarations for Floyd's Algorithm

#ifndef FLOYD_H_
#define FLOYD_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

// Read in a distance matrix from a text file
std::vector<std::vector<float>> ReadFile(std::string);

std::vector<std::vector<float>> Floyd(const std::vector<std::vector<float>>);

#endif // FLOYD_H_
 
